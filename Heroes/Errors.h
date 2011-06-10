#pragma once

#define SUCCESS					 1;
#define BUILDING_NOT_AVAILABLE	 0;
#define BUILDING_ALREADY_BUILT	-1;
#define NOT_ENOUGH_RESOURCES	-2;
#define BUILDING_NOT_FOUND		-3;
#define TOWN_NOT_OWNED			-4;
#define UNKNOWN_ERROR			-5;

const char *ERROR_MAP[];

const char *getErrorString(int error);