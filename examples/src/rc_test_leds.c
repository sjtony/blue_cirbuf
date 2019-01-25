/**
 * @file rc_test_leds.c
 * @example    rc_test_leds
 *
 * tests all LEDs on Robotics Cape & BeagleBone Blue
 *
 * @author     James Strawson
 * @date       1/29/2018
 */

#include <stdio.h>
#include <rc/led.h>
#include <rc/test.h>
#include <rc/time.h>

#define WAIT_US 500000 // time to light each LED in microseconds

int main() {
	CIRC_BBUF_DEF(my_circ_buf, 32);

	uint8_t out_data = 0, in_data = 0x55;

	rc_led_set(RC_LED_GREEN, 1);
	rc_usleep(WAIT_US);
	rc_led_set(RC_LED_GREEN, 0);

	rc_led_set(RC_LED_RED, 1);
	rc_usleep(WAIT_US);
	rc_led_set(RC_LED_RED, 0);

	rc_led_set(RC_LED_USR0, 1);
	rc_usleep(WAIT_US);
	rc_led_set(RC_LED_USR0, 0);

	rc_led_set(RC_LED_USR1, 1);
	rc_usleep(WAIT_US);
	rc_led_set(RC_LED_USR1, 0);

	rc_led_set(RC_LED_USR2, 1);
	rc_usleep(WAIT_US);
	rc_led_set(RC_LED_USR2, 0);

	rc_led_set(RC_LED_USR3, 1);
	rc_usleep(WAIT_US);
	rc_led_set(RC_LED_USR3, 0);

	rc_led_set(RC_LED_BAT25, 1);
	rc_usleep(WAIT_US);
	rc_led_set(RC_LED_BAT25, 0);

	rc_led_set(RC_LED_BAT50, 1);
	rc_usleep(WAIT_US);
	rc_led_set(RC_LED_BAT50, 0);

	rc_led_set(RC_LED_BAT75, 1);
	rc_usleep(WAIT_US);
	rc_led_set(RC_LED_BAT75, 0);

	rc_led_set(RC_LED_BAT100, 1);
	rc_usleep(WAIT_US);
	rc_led_set(RC_LED_BAT100, 0);

	rc_led_cleanup();

//sj
	if (circ_bbuf_push(&my_circ_buf, in_data)) {
		printf("Out of space in CB\n");
		return -1;
	}

	if (circ_bbuf_pop(&my_circ_buf, &out_data)) {
		printf("CB is empty\n");
		return -1;
	}

	printf("Push: 0x%x\n", in_data);
	printf("Pop:  0x%x\n", out_data);

	return 0;
}
