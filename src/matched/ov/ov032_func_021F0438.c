/*
 * function: func_021F0438
 * address:  0x021F0438
 * packet:   pkt_ov032_021F0438
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BEACON_VIEW_SetArrowAnim  0x021F05E8  thumb  ov032
 *   func_021F0B10  0x021F0B10  thumb  ov032
 *   BEACON_VIEW_IsArrowAnimActive  0x021F0668  thumb  ov032
 *   func_021F055C  0x021F055C  thumb  ov032
 *   GAME_BEACON_ACCESSOR_TableGetRingIndex  0x021659F0  thumb  ov010
 *   func_021F0F44  0x021F0F44  thumb  ov032
 *   func_0201EE0C  0x0201EE0C  thumb
 *   BEACON_VIEW_SetPrintQueueLimit  0x021F029C  thumb  ov032
 *   func_021F18C4  0x021F18C4  thumb  ov032
 *   GAME_BEACON_SEARCH_SetThanks  0x021657E8  thumb  ov010
 */
#include "../include/Obj00007.h"
#include "../include/Obj09795.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void BEACON_VIEW_SetArrowAnim(u8 *p, int a, u32 b);
extern void func_021F0B10(char *p, int a, int b);
extern int BEACON_VIEW_IsArrowAnimActive(char *p, int i);
extern int func_021F055C(u8 *p);
extern int GAME_BEACON_ACCESSOR_TableGetRingIndex(u8 *q, int delta);
extern u8 *func_021F0F44(u8 *p, int a);
struct WordSet;
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void BEACON_VIEW_SetPrintQueueLimit(char *p, int flag);
extern void func_021F18C4(char *p, int b);
extern void GAME_BEACON_SEARCH_SetThanks(void *a, u16 b);

int func_021F0438(u8 *p)
{
    u8 *e;
    u8 s;

    if (((struct Obj00007 *)p)->fA8 != 0)
        return 5;
    switch (((struct Obj00007 *)p)->f6C) {
    case 0:
        BEACON_VIEW_SetArrowAnim(p, 2, 1);
        func_021F0B10((char *)p, 2, (int)(p + 0xA8));
        (((struct Obj00007 *)p)->f6C)++;
        break;
    case 1:
        if (BEACON_VIEW_IsArrowAnimActive((char *)p, 2) != 0)
            break;
        BEACON_VIEW_SetArrowAnim(p, 0, 2);
        BEACON_VIEW_SetArrowAnim(p, 1, 2);
        BEACON_VIEW_SetArrowAnim(p, 3, 2);
        (((struct Obj00007 *)p)->f6C)++;
        break;
    case 2:
        ((struct Obj00007 *)p)->f6C = func_021F055C(p);
        if (((struct Obj00007 *)p)->f6C == 3)
            return 3;
        break;
    case 4:
        s = GAME_BEACON_ACCESSOR_TableGetRingIndex((u8 *)(((struct Obj00007 *)p)->f3C), p[0x7E] + p[0x7C]);
        e = func_021F0F44(p, s);
        func_0201EE0C(((struct Obj00007 *)p)->f110, 0, ((struct Obj09795 *)e)->f24, e[4], 1, 2);
        BEACON_VIEW_SetPrintQueueLimit((char *)p, 1);
        func_021F18C4((char *)p, 3);
        GAME_BEACON_SEARCH_SetThanks((void *)(*(int *)&((struct Obj00007 *)p)->f4), ((struct Obj09795 *)e)->f6);
        ((struct Obj00007 *)p)->f6C = 5;
        break;
    case 5:
        BEACON_VIEW_SetPrintQueueLimit((char *)p, 0);
        ((struct Obj00007 *)p)->f6C = 6;
        break;
    case 3:
        BEACON_VIEW_SetArrowAnim(p, 2, 0);
        ((struct Obj00007 *)p)->f6C = 2;
        break;
    case 6:
        BEACON_VIEW_SetArrowAnim(p, 4, 0);
        func_021F0B10((char *)p, 1, (int)(p + 0xA8));
        ((struct Obj00007 *)p)->f6C = 7;
        break;
    case 7:
        ((struct Obj00007 *)p)->f6C = 0;
        return 0;
    }
    return 5;
}
