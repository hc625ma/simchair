/*
 * typedefs.h
 *
 * Created: 12/13/2011 2:26:51 PM
 *  Author: Alan Chatham
 *
 *	This file contains all the typedef'ed structs we're using to store button data
 */ 


#ifndef PHYSICAL_BUTTON_LIST_T
#define PHYSICAL_BUTTON_LIST_T

// How many total inputs do we have?
#define NUMBER_OF_INPUTS 36
#define NUMBER_OF_DIGITAL_BUTTONS 27

// This one is an abstract representation of what physical buttons we have
//  on the controller itself
typedef struct physicalButtonList_t{

	
	uint16_t leftStickX;
	uint16_t leftStickY;
	uint16_t rightStickX;
	uint8_t rightStickY;
	uint8_t dial;
	uint8_t slider;
	
	
} physicalButtonList_t;
#endif // PHYSICAL_BUTTON_LIST_T
