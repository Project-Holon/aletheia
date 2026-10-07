/*
 * file:     beacon_view_p08.c
 * unit:     yes
 * function: func_021F1004, func_021F1070
 * address:  0x021F1004
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F0FE8  0x021F0FE8  thumb  ov032
 *   func_02165CC0  0x02165CC0  thumb  ov010
 *   func_02021F64  0x02021F64  thumb
 *   func_020215BC  0x020215BC  thumb
 *   func_021F2144 0x021F2144 thumb ov032
 */
#include "../../matched/include/Obj00007.h"

struct PalAnmSlot;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021F0FE8(int a);
extern void func_02165CC0(int a0, int a1);
extern void func_02021F64(u16 *, u16 *, int, u8, u16);
extern void func_020215BC(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
extern void func_021F2144(char *p, char *q, void *text, u16 col, u32 a4);
void func_021F1004(char *p, u8 *q, int r);
void func_021F1070(char *p, char *q, void *text, int a4);


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
    func_02165CC0((int)(&a[3]), r);
    func_02021F64(&a[3], &a[4], 1, 3, 0);
    func_020215BC((struct PalAnmSlot *)(*(int *)&((struct Obj00007 *)p)->fAC), a, 3, (u16)((q[0] + 4) * 16 + 1), 10);
}

void func_021F1070(char *p, char *q, void *text, int a4)
{
    func_021F2144(p, q, text, 0x3c60, a4);
}
