/*
 * function: func_021B8A88
 * address: 0x021B8A88
 * packet: pkt_ov067_021B8A88
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: explicit sentinel break keeps the loop uninverted; retain the
 * sentinel byte in a local for the subsequent output store.
 */
#include "../include/Obj20623.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Entry { u8 f0, f1; u8 pad2[2]; u32 f4; } Entry;
void func_021B8A88(u8 *p, u8 *a, u8 *b)
{
    u8 i;
    Entry *entries;
    u8 value;
    entries = *(Entry * *)&((struct Obj20623 *)p)->f1C;
    for (i = 0; ; i++) {
        value = entries[i].f0;
        if (value == 0xff) break;
        if (entries[i].f4 == 1) {
            *a = value;
            *b = (*(Entry **)(p + 0x1c))[i].f1;
            return;
        }
    }
}
