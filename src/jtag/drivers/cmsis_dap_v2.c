/***************************************************************************
 *   Copyright (C) 2020 by Talpa Chen                                      *
 *   talpachen@gmail.com                                                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 ***************************************************************************/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <transport/transport.h>
#include <jtag/interface.h>
#include <jtag/commands.h>
#include <jtag/swd.h>
#include <jtag/tcl.h>
#include <libusb.h>

static int cmsis_dap_v2_init(void)
{
    // TODO
    return ERROR_OK;
}

static int cmsis_dap_v2_quit(void)
{
    // TODO
    return ERROR_OK;
}

static int cmsis_dap_v2_reset(int srst, int trst)
{
    // TODO
    return ERROR_OK;
}

static int cmsis_dap_v2_speed(int speed)
{
    // TODO
    return ERROR_OK;
}

static int cmsis_dap_v2_khz(int khz, int *jtag_speed)
{
    // TODO
    return ERROR_OK;
}

static int cmsis_dap_v2_speed_div(int speed, int *khz)
{
    // TODO
    return ERROR_OK;
}

static int cmsis_dap_execute_queue(void)
{
    // TODO
    return ERROR_OK;
}

static int cmsis_dap_v2_dap_op_connect(struct adiv5_dap *dap)
{
    // TODO
    return ERROR_OK;
}

static int stlink_dap_check_reconnect(struct adiv5_dap *dap)
{
    // TODO
    return ERROR_OK;
}

static int cmsis_dap_v2_dap_op_send_sequence(struct adiv5_dap *dap, enum swd_special_seq seq)
{
    // TODO
    return ERROR_OK;
}

static int cmsis_dap_v2_dap_op_queue_dp_read(struct adiv5_dap *dap, unsigned reg,
		uint32_t *data)
{
    // TODO
    return ERROR_OK;
}

static int cmsis_dap_v2_dap_op_queue_dp_write(struct adiv5_dap *dap, unsigned reg,
		uint32_t data)
{
    // TODO
    return ERROR_OK;
}

static int cmsis_dap_v2_dap_op_queue_ap_read(struct adiv5_ap *ap, unsigned reg,
		uint32_t *data)
{
    // TODO
    return ERROR_OK;
}

static int cmsis_dap_v2_dap_op_queue_ap_write(struct adiv5_ap *ap, unsigned reg,
		uint32_t data)
{
    // TODO
    return ERROR_OK;
}

static int cmsis_dap_v2_dap_op_queue_ap_abort(struct adiv5_dap *dap, uint8_t *ack)
{
    // TODO
    return ERROR_OK;
}

static int cmsis_dap_v2_dap_op_run(struct adiv5_dap *dap)
{
    // TODO
    return ERROR_OK;
}

int cmsis_dap_v2_dap_op_sync(struct adiv5_dap *dap)
{
    // TODO
    return ERROR_OK;
}

static void cmsis_dap_v2_dap_op_quit(struct adiv5_dap *dap)
{
    // TODO
}


static const char * const cmsis_dap_v2_transport[] = { "swd", "jtag", NULL };

static struct jtag_interface cmsis_dap_v2_jtag_interface = {
    .supported = DEBUG_CAP_TMS_SEQ,
    .execute_queue = cmsis_dap_v2_execute_queue,
};

static const struct swd_driver cmsis_dap_v2_swd_driver = {
    .init = cmsis_dap_v2_swd_init,
    .switch_seq = cmsis_dap_v2_swd_switch_seq,
    .read_reg = cmsis_dap_v2_swd_read_reg,
    .write_reg = cmsis_dap_v2_swd_write_reg,
    .run = cmsis_dap_v2_swd_run_queue,
    .trace = NULL,
};

static struct dap_ops cmsis_dap_v2_dap_ops = {
    .connect = cmsis_dap_v2_dap_op_connect,
    .send_sequence = cmsis_dap_v2_dap_op_send_sequence,
    .queue_dp_read = cmsis_dap_v2_dap_op_queue_dp_read,
    .queue_dp_write = cmsis_dap_v2_dap_op_queue_dp_write,
    .queue_ap_read = cmsis_dap_v2_dap_op_queue_ap_read,
    .queue_ap_write = cmsis_dap_v2_dap_op_queue_ap_write,
    .queue_ap_abort = cmsis_dap_v2_dap_op_queue_ap_abort,
    .run = cmsis_dap_v2_dap_op_run,
    .sync = cmsis_dap_v2_dap_op_sync, /* optional */
    .quit = cmsis_dap_v2_dap_op_quit, /* optional */
};

struct adapter_driver cmsis_dap_v2_adapter_driver = {
    .name = "cmsis-dap-v2",
    .transports = cmsis_dap_v2_transport,
    .commands = cmsis_dap_v2_command_handlers,

    .init = cmsis_dap_v2_init,
    .quit = cmsis_dap_v2_quit,
    .reset = cmsis_dap_v2_reset,
    .speed = cmsis_dap_v2_speed,
    .khz = cmsis_dap_v2_khz,
    .speed_div = cmsis_dap_v2_speed_div,

    .jtag_ops = &cmsis_dap_v2_jtag_interface,
    .swd_ops = &cmsis_dap_v2_swd_driver,
	.dap_jtag_ops = &cmsis_dap_v2_dap_ops,
	.dap_swd_ops = &cmsis_dap_v2_dap_ops,
};
