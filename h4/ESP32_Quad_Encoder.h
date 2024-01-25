// ESP32_Quad_Encoder.h

#ifndef _ESP32_QUAD_ENCODER_h
#define _ESP32_QUAD_ENCODER_h

//#if defined(ARDUINO) && ARDUINO >= 100
//	#include "arduino.h"
//#else
//	#include "WProgram.h"
//#endif
#pragma once
#include <Arduino.h>
#include <driver/gpio.h>
#include <driver/pcnt.h>
#define MAX_ENCODERS 3

enum encType { enc_single, enc_half, enc_full, enc_na };
enum axisType { axis_x, axis_y, axis_z, axis_w, axis_s };
enum pullupType { pa_none, pa_up, pa_down };

class ESP32Encoder {
private:
	int aPin;
	int bPin;
	enum pullupType puType;
	int filter = 0;
	bool fullQuad = false;
	gpio_num_t aPinNumber;
	gpio_num_t bPinNumber;
	pcnt_unit_t unit;
	pcnt_config_t enc_config;
	static int numEncoders;
	static bool attachedInterrupt;

public:
	ESP32Encoder(axisType axi, int aP, int bP, encType ty, pullupType uip, int fil);
	ESP32Encoder();
	void attachEncoder(int index);
	int32_t getCount();
	int32_t clearCount();
	enum axisType axis;
	enum encType type;
	volatile int32_t count = 0;
	static ESP32Encoder* encoders[MAX_ENCODERS];
};



#endif

