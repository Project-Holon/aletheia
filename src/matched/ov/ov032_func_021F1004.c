/*
 * function: func_021F1004
 * address:  0x021F1004
 * packet:   pkt_ov032_021F1004
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F1004  0x021F1004  thumb
 *   func_021F0FE8  0x021F0FE8  thumb  ov032
 *   GAME_BEACON_ACCESSOR_GetFavoriteColorRgb  0x02165CC0  thumb  ov010
 *   PALANM_BlendColors  0x02021F64  thumb
 *   PALANM_CopyToSlot  0x020215BC  thumb
 */
#include "../include/Obj00007.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021F0FE8(int a);
struct PalAnmSlot;
extern void GAME_BEACON_ACCESSOR_GetFavoriteColorRgb(int a0, int a1);
extern void PALANM_BlendColors(u16 *, u16 *, int, u8, u16);
extern void PALANM_CopyToSlot(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);

void func_021F1004(char *p, u8 *q, int r)
{
    u16 a[5];
    int x;
    int b;
    u16 *t;

    x = func_021F0FE8(r);
    b = x * 16;
    t = *(u16 * *)&((struct Obj00007 *)p)->f3C8;
    a[0] = t[b];
    a[1] = t[b + 1];
    a[2] = t[b + 2];
    GAME_BEACON_ACCESSOR_GetFavoriteColorRgb((int)(&a[3]), r);
    PALANM_BlendColors(&a[3], &a[4], 1, 3, 0);
    PALANM_CopyToSlot((struct PalAnmSlot *)(*(int *)&((struct Obj00007 *)p)->fAC), a, 3, (u16)((q[0] + 4) * 16 + 1), 10);
}
