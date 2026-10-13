/*
 * function: FIELD_TASK_Start
 * address:  0x021C6CC4
 * packet:   pkt_021C6CC4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to FIELD_TASK_SetRunning with no argument change.
 *
 * symbols:
 *   FIELD_TASK_SetRunning  0x021C6CE4  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_TASK_SetRunning(u32 *p);

void FIELD_TASK_Start(u32 *a0)
{
    FIELD_TASK_SetRunning(a0);
}
