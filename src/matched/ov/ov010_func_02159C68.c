/*
 * function: MAP_MATRIX_ApplyReplaceRecord
 * address:  0x02159C68
 * packet:   pkt_ov010_02159C68
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MAP_REPLACE_CheckRecord  0x02159E00  thumb  ov010
 *   MAP_MATRIX_Load  0x02159B94  thumb  ov010
 */
#include "../include/Obj12278.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Obj {
    u16 f00;
    u16 f02;
    u32 pad04[3];
    u32 f10;
} Obj;

extern int MAP_REPLACE_CheckRecord(u8 *a, u32 *b, u32 *c);
extern int MAP_MATRIX_Load(int a0, int a1, int a2, int a3);

void MAP_MATRIX_ApplyReplaceRecord(Obj *a, int b, int c)
{
    u32 v[2];
    int r = MAP_REPLACE_CheckRecord((u8 *)b, &v[1], &v[0]);
    switch (r) {
    case 0:
        break;
    case 2:
        MAP_MATRIX_Load((int)a, (u16)v[0], a->f02, c);
        return;
    case 1: {
        u32 i;
        for (i = 0; i < a->f10; i++) {
            u32 *p = (u32 *)((u8 *)a + i * 4);
            if (v[1] == ((struct Obj12278 *)p)->f71C)
                ((struct Obj12278 *)p)->f71C = v[0];
        }
        break;
    }
    }
}
