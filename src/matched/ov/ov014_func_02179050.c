/*
 * function: func_02179050
 * address:  0x02179050
 * packet:   pkt_ov014_02179050
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_021797A8     0x021797A8  data  a4
 */

#include "../include/G_S.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed short s16;

extern struct S *g_021797A8;

int func_02179050(u16 mask)
{
    s16 last = 0;
    s16 i;
    u16 cnt = 0;
    u32 k;

    for (i = 0; i < 16; i++) {
        if (mask & (1 << i)) {
            last = i + 1;
            cnt++;
        }
    }
    if (cnt > 1) {
        s16 j;

        *(u32 *)(((u8 *)g_021797A8) + 0x1E9C) = *(u32 *)(((u8 *)g_021797A8) + 0x1E9C) * 0x10DCD + 0x3039;
        k = (u32)(cnt * (u8) * (u32 *)(((u8 *)g_021797A8) + 0x1E9C)) << 8 >> 16;
        for (j = 0; j < 16; j++) {
            if (mask & 1) {
                if (k == 0)
                    return (s16)(j + 1);
                k = (u16)(k - 1);
            }
            mask = mask >> 1;
        }
        return 0;
    }
    return last;
}
