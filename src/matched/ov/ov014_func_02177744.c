/*
 * function: func_02177744
 * address:  0x02177744
 * packet:   pkt_ov014_02177744
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_pWhPipeWork  0x021797A4  data  a4
 */

#include "../include/G_W.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern struct W *g_pWhPipeWork;

void func_02177744(void)
{
    u8 *w = ((u8 *)g_pWhPipeWork);
    int i;

    for (i = 0; i < 16; i++) {
        u16 v = *(volatile u16 *)(w + i * 2 + 0xC40);
        if (v != 0 && v != 0) {
            *(volatile u16 *)(w + i * 2 + 0xC40) = *(volatile u16 *)(w + i * 2 + 0xC40) - 1;
            if (*(volatile u16 *)(w + i * 2 + 0xC40) == 0)
                w[0xCEF] = 1;
        }
    }
}
