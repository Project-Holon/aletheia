/*
 * function: FIELD_TASK_Update
 * address:  0x021C6CBC
 * packet:   pkt_021C6CBC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to FIELD_TASK_RunCheck with no argument change.
 *
 * symbols:
 *   FIELD_TASK_RunCheck  0x021C6CF4  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_TASK_RunCheck();

void FIELD_TASK_Update(void)
{
    FIELD_TASK_RunCheck();
}
