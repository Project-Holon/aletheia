/*
 * function: BTL_MSG_FormatArgs
 * address:  0x021EEE24
 * packet:   pkt_ov093_021EEE24
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Variadic: copies n words into an eight-word table at gBtlMsgState + 0x30
 * (zero-filling the rest), then hands the table (named separately at its
 * own address d_021F63C8) to BTL_MSG_FormatWithSide.
 *
 * symbols:
 *   BTL_MSG_FormatWithSide  0x021EEE80  thumb  ov093
 *   gBtlMsgState     0x021F6398  data  ov093  a4
 *   d_021F63C8  0x021F63C8  data
 *   d_021F63C8  0x021F63C8  data
 *   d_021F63C8     0x021F63C8  data  a4
 */

#include "../include/G_ov093_021F6398.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed int s32;
typedef char *va_list;
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define va_arg(ap, t) (*(t *)((ap += 4) - 4))

extern struct G_ov093_021F6398 gBtlMsgState;
extern s32 d_021F63C8[];
extern void BTL_MSG_FormatWithSide(u32 a, u16 k, u32 *p);

void BTL_MSG_FormatArgs(u32 a, u16 k, u32 n, ...)
{
    va_list ap;
    u32 i;

    va_start(ap, n);
    for (i = 0; i < n; i++) {
        gBtlMsgState.a[i] = va_arg(ap, s32);
    }
    for (; i < 8; i++) {
        gBtlMsgState.a[i] = 0;
    }
    BTL_MSG_FormatWithSide(a, k, (u32 *)d_021F63C8);
}
