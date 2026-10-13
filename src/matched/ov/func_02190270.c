/*
 * function: FIELD_MSGBG_SetupBg
 * address:  0x02190270
 * packet:   pkt_02190270
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: pins the second argument to 1.
 *
 * symbols:
 *   FIELD_MSGBG_InitBgTwoLayerTalk  0x02192BD0  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_MSGBG_InitBgTwoLayerTalk(char *p, int flag);

void FIELD_MSGBG_SetupBg(u32 a)
{
    FIELD_MSGBG_InitBgTwoLayerTalk((char *)a, 1);
}
