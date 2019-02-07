/* main.c - KNoT Setup main entry point */
/*
 * Copyright (c) 2019, CESAR. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <zephyr.h>
#include <logging/log.h>

#include "bt_srv.h"

LOG_MODULE_REGISTER(knot_setup, LOG_LEVEL_DBG);

void main(void)
{
	int err;

	/* Setup Application */
	LOG_DBG("Initializing Setup App");

	/* Bluetooth services */
	err = bt_srv_init();
	if (err) {
		LOG_ERR("Failed to initialize bluetooth");
		return;
	}
}