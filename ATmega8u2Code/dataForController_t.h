/*  dataForController_t.h
 *
 *	  Alan Chatham - 2011
 *
 *  This is simply a typedef for a struct
 *   that holds information about controller
 *   button presses.  It is used by the controller
 *   libraries to pass information from an application
 *   to a library function that formats and sends
 *   appropriate controller data
 */

#ifndef DATA_FOR_CONTROLLER_T
#define DATA_FOR_CONTROLLER_T

	typedef struct dataForController_t
	{
		uint16_t leftStickX : 16; 
		uint16_t leftStickY : 16;
		uint16_t rightStickX : 16;
		uint8_t rightStickY : 8;
		uint8_t dial : 8;
		uint8_t slider : 8;
	} dataForController_t;


#endif
