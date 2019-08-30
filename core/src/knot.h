/*
 * Copyright (c) 2018, CESAR. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*
 * Similar to Arduino:
 * setup() is called once and loop() is always called at idle state.
 * Sensors and actuactors should be registered at setup() function
 * definition and loop() must NOT be blooking.
 *
 * setup() and loop() must be defined at user app context.
 */
void setup(void);
void loop(void);

/* Proxy: Virtual representation of the remote device */
struct knot_proxy;

typedef void (*knot_callback_t) (struct knot_proxy *proxy);

/* Set knot to track and update data items */
int knot_data_register(u8_t id, const char *name,
		       u16_t type_id, u8_t value_type, u8_t unit,
		       void *target, size_t target_len,
		       knot_callback_t write_cb, knot_callback_t read_cb);

/*
 * This fuction configures which events should send proxy value to cloud
 *
 * @param id Sensor ID.
 * @param ... Optional list of event flags.
 *
 * This function must end with NULL
 */
bool knot_data_config(u8_t id, ...);

/* Proxy properties */
u8_t knot_proxy_get_id(struct knot_proxy *proxy);

/* Proxy helpers to get or set sensor data at the remote */
bool knot_proxy_value_set_basic(struct knot_proxy *proxy,
				const void *value);
bool knot_proxy_value_set_string(struct knot_proxy *proxy,
				 const char *value, int len);

bool knot_proxy_value_get_basic(struct knot_proxy *proxy,
				void *value);
bool knot_proxy_value_get_string(struct knot_proxy *proxy,
				 char *value, int len, int *olen);


