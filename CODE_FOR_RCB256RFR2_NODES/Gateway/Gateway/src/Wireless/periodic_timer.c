/**
 * \file periodic_timer.c
 *
 * Created: 12/11/2021 12:32:00
 * Author: pract
 *
 * \brief  API file of periodic operations using timer as generated by Project Wizard
 *
 * Copyright (c) 2014 Atmel Corporation. All rights reserved.
 *
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 * \page license License
 * Copyright(c) 2014, Atmel Corporation All rights reserved.
 *
 * Licensed under Atmel's Limited License Agreement --> EULA.txt
 */


#include <periodic_timer.h>
#include "usr_wireless.h"

/**
 * \brief This function initializes the App timers
 * (T_APP_TIMER1 is the only timer added by the project wizard,add extra timers based on the application requirement)
 */
//int variableGloval;
void app_timers_init(void)
{
	if (STATUS_OK != sw_timer_get_id(&T_APP_TIMER1)) {
		app_alert();
	}
	// Add initialization code for extra timers
}

/**
 \brief Callback called once the timer expires
*/
void app_timer_cb(void *parameter)
{
	usr_app_timer_cb(parameter);
	//LED_On(LED1);

	//Re-register the timer for the next time interval
	//start_timer1();
}

//TODO (Project Wizard) - Call this function atleast once to start the timer
/**
 \brief This function starts a timer T-APP_TIMER with timeout TIMER_DURATION  with callback id app_timer_cb
 * New timers can be added by defeining ex. start_timer2 by adding a new timer id T_APP_TIMER2 and a different call back name based on the requirement ,
 * max no of timers to be added is based on *the  count  TOTAL_NUMBER_OF_TIMERS in conf_common_sw_timer.h
 */
void start_timer1(void)
{
	sw_timer_start(T_APP_TIMER1,TIMER_DURATION,SW_TIMEOUT_RELATIVE,(FUNC_PTR)app_timer_cb,NULL)	;
}

//TODO (Project Wizard) - This function is used to stop the timer before expiry which is started using start_timer1
/**
 \brief This function stops a timer T-APP_TIMER 
 * To add stop timer functions for other timer, add defenitions stop_timer2 with sw_timer_stop(NEW ID) inside it
 */
void stop_timer1(void)
{

	sw_timer_stop(T_APP_TIMER1);
}