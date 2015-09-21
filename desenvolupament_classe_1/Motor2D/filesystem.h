#ifndef _FILESYSTEM_H_
#define _FILESYSTEM_H_

#include "SDL_image\include\SDL_image.h"
#include "j1Module.h"


class filesystem : public j1Module
{
public:

	// Constructor
	filesystem();

	// Destructor
	virtual ~filesystem();

	bool Start();

	bool CleanUp();

	SDL_RWops* LoadFile(const char* file);
	
};



#endif