#pragma comment (lib,"PhysFS/libx86/physfs.lib")
#include "PhysFS\include\physfs.h"
#include "p2Log.h"


#include "filesystem.h"

filesystem::filesystem() : j1Module()
{
	name.create("filesystem");
}

filesystem ::~filesystem()
{

}
bool filesystem::Start()
{
	LOG("start filesystem");
	//retornara 0 si hi ha algun error
	int init  = PHYSFS_init(NULL);
	//el if si hi ha problemas al inicialitzar
	if (init == 0)
	{
		//imprimeixo l'error
		LOG(PHYSFS_getLastError());
		return false;
	}
	return true;
}

bool filesystem::CleanUp()
{
	LOG("cleanup filesystem");
	PHYSFS_deinit();

	return true;
}

SDL_RWops* filesystem::LoadFile(const char* file)
{
	PHYSFS_File * myfile = PHYSFS_openRead(file);

	if (myfile == NULL)
	{
		LOG(PHYSFS_getLastError());
	}
	PHYSFS_sint64 file_size = PHYSFS_fileLength(myfile);

	char *myBuf;

	myBuf = new char[PHYSFS_fileLength(myfile)];
	int length_read = PHYSFS_read(myfile, myBuf, 1, PHYSFS_fileLength(myfile));

	PHYSFS_close(myfile);

	SDL_RWops *rw = SDL_RWFromConstMem(myfile, file_size);

	return rw;
}