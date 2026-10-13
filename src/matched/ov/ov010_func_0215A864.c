/*
 * function: SCRCMD_WORK_StartMenu
 * address:  0x0215A864
 * packet:   pkt_ov010_0215A864
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The ov021 leaves 0x02190AC4 and 0x02190AEC (unlabelled, formerly the
 * blockers) are matched in their own shards and attest as matched.
 *
 * symbols:
 *   SCRCMD_WORK_GetMenuHeap  0x0215A5FC  thumb  ov010
 *   FIELD_MSGBG_GetMenuItemsWidthChars  0x02190ACC  thumb  ov021
 *   FIELD_MSGBG_GetMenuItemCount  0x02190AC4  thumb  ov021
 *   FIELD_MSGBG_GetMenuHeightChars  0x02190AEC  thumb  ov021
 *   FIELD_MSGBG_SetMenuHeaderRect  0x02190B08  thumb  ov021
 *   FIELD_MSGBG_CreateMenuFuncWork  0x02190988  thumb  ov021
 *   SCRCMD_WORK_MenuCursorCallback  0x0215A9C0  thumb  ov010
 *   gScrcmdMenuHeader     0x02171140  data  ov010  a4
 */
#include "../include/Obj18800.h"

typedef struct {
    int a0;
    int a1;
    unsigned short a2;
    unsigned short f1 : 3;
    unsigned short f2 : 4;
    int c3;
    unsigned short h8;
    unsigned short h9;
    int d5;
    int d6;
    int d7;
} L32;

typedef struct {
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned char d;
    unsigned char e;
    int pad8;
    int padc;
    int pad10;
    int pad14;
    int j;
    int k;
} Q;

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Handle;
extern int SCRCMD_WORK_GetMenuHeap(int a0);
extern u32 FIELD_MSGBG_GetMenuItemsWidthChars(u32 *obj, u32 *tab, u32 unused, u32 key);
extern unsigned FIELD_MSGBG_GetMenuItemCount(void *p);
extern unsigned FIELD_MSGBG_GetMenuHeightChars(unsigned a, unsigned b, unsigned c, int d);
extern int FIELD_MSGBG_SetMenuHeaderRect(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 f);
extern struct Handle *FIELD_MSGBG_CreateMenuFuncWork(u16 *a, const u8 *b, u32 c, u32 d, u32 x, u16 y, u16 z, u32 w);
extern void SCRCMD_WORK_MenuCursorCallback(int a);
extern L32 gScrcmdMenuHeader;

void SCRCMD_WORK_StartMenu(int *p)
{
    int x;
    int y;
    Q *q = (Q *)(*(char * *)&((struct Obj18800 *)p)->f20 + 0x34);
    L32 l = gScrcmdMenuHeader;
    int t = SCRCMD_WORK_GetMenuHeap((int)p);
    unsigned m;
    unsigned n;

    x = FIELD_MSGBG_GetMenuItemsWidthChars((u32 *)t, (u32 *)q->j, l.h8, l.f1);
    if (q->e == 1) {
        q->a = q->a - (unsigned short)x;
    }
    n = FIELD_MSGBG_GetMenuItemCount((void *)q->j);
    m = 6;
    if (n <= 6) {
        m = n;
    }
    y = FIELD_MSGBG_GetMenuHeightChars(m, l.h9, l.f2, n > 6);
    FIELD_MSGBG_SetMenuHeaderRect((u32)(&l), (unsigned short)FIELD_MSGBG_GetMenuItemCount((void *)q->j), (unsigned short)q->a, (unsigned short)q->b, (unsigned short)x, (unsigned short)y);
    q->k = (int)FIELD_MSGBG_CreateMenuFuncWork((u16 *)t, (const u8 *)(&l), q->j, (u32)((void *)SCRCMD_WORK_MenuCursorCallback), (u32)p, 0, q->c, q->d);
}
