#include "Errors.h"

extern const char *ERROR_MAP[] = {
	"Building not available", 
	"Building already built", 
	"Not enough resources", 
	"Building not found",
	"Town is not owned by a player",
	"Unknown error"};

const char *getErrorString(int error)
{
	if(error > 0)
		return "Success";
	return ERROR_MAP[-error];
}