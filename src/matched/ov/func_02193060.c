/*
 * function: FIELD_MSGBG_SetBlendThunk
 * address:  0x02193060
 * packet:   pkt_02193060
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to FIELD_MSGBG_SetBlend with no argument change.
 *
 * symbols:
 *   FIELD_MSGBG_SetBlend  0x02193044  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_MSGBG_SetBlend(u32 v);

void FIELD_MSGBG_SetBlendThunk(u32 a)
{
    FIELD_MSGBG_SetBlend(a);
}
