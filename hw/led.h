#ifndef _LED_H_
#define _LED_H_
#include "stm32f4xx.h"

typedef uint8_t led_bit;
typedef uint32_t led_bits;

typedef enum LED_ELE_LEVEL{
    LED_LOW_LEVEL = 0,
    LED_HIGH_LEVEL
} LED_ELE_LEVEL;

typedef struct LED_Class LED_Class;
typedef struct LED_Class *pLED_Class;


typedef struct LED_Class{

    led_bits led_curent_level;
    int led_amount;
/********
     һλд
		 ��λд
		 һλ��
	   ��λ��
  	*********/
    void (*set_level)(pLED_Class, const int led_n, const led_bit led_level);/*******����ָ�룬ע��������Ҫ����ʲô�ط�**********/
    void (*set_level_arr)(pLED_Class, const led_bits led_sta);
    void (*read_level)(pLED_Class, const int led_n, led_bit *led_level);
    void (*read_level_arr)(pLED_Class, led_bits* led_sta);

} LED_Class;


extern void led_out_gpio(uint8_t arg_int, int led_n);/********�ӿ�ȫ��������ֻ�ö���*********/
extern uint8_t led_in_gpio(int led_n);

pLED_Class createLedClass(void);
pLED_Class createLedClassWtihArgs(int led_amount);


#endif