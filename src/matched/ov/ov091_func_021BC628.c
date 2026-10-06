/*
 * unit:     yes
 * function: func_021BC628, func_021BC6A0, func_021BC6C0
 * address:  0x021BC628
 * packet:   pkt_ov091_021BC628
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021BC1D0  0x021BC1D0  thumb  ov091
 *   func_021BB7A4  0x021BB7A4  thumb  ov091
 *   func_021BB050  0x021BB050  thumb  ov091
 *   func_0201AB28  0x0201AB28  thumb
 *   func_021BC350  0x021BC350  thumb  ov091
 *   func_021BE2B4  0x021BE2B4  thumb  ov091
 *   func_021BB2C0  0x021BB2C0  thumb  ov091
 *   func_020061E4  0x020061E4  thumb
 *   func_021BBA70  0x021BBA70  thumb  ov091
 */
#include "../include/Obj00009.h"
#include "../include/Obj07736.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021BC1D0(int);
extern void func_021BB7A4(void *p, u32 *s);
extern void func_021BB050(int unused, u8 *s, int k);
extern void *func_0201AB28(void *p, u32 idx);
extern int func_021BC350(u8 *p, int v);
extern int func_021BE2B4(void *mon, u16 item, u16 moveSlot, u16 arg, int heap);
extern void func_021BB2C0(u8 *a, u8 *s);
extern void func_020061E4(u32 a);
extern void func_021BBA70(int, int);

void func_021BC628(int p)
{
    int n = func_021BC1D0(p);
    func_021BB7A4((void *)p, (u32 *)(*(int *)&((struct Obj00009 *)p)->f150));
    func_021BB050(p, (u8 *)(*(int *)(p + ((struct Obj00009 *)p)->f2C * 4 + 0x160)), 3);
    ((struct Obj00009 *)p)->f2C = n;
    *(int *)&((struct Obj00009 *)p)->f38 = (int)func_0201AB28(**(void ** *)&((struct Obj00009 *)p)->f280, n);
    func_021BC350((u8 *)p, 0);
    func_021BE2B4((void *)(*(int *)&((struct Obj00009 *)p)->f38),
                  *(u16 *)(*(int *)&((struct Obj00009 *)p)->f280 + 0x44), 0,
                  *(u16 *)(*(int *)&((struct Obj00009 *)p)->f280 + 0x30), ((struct Obj00009 *)p)->f0);
    func_021BB2C0((u8 *)p, (u8 *)(*(int *)(p + ((struct Obj00009 *)p)->f2C * 4 + 0x160)));
    func_020061E4(0x56f);
}

void func_021BC6A0(char *p)
{
    p[0xc] = 0xd;
    p[0xe] = 0;
    *(int *)(((struct Obj07736 *)p)->f280 + 0x50) = 0;
    func_021BBA70((int)p, ((struct Obj07736 *)p)->f150);
}

void func_021BC6C0(char *p)
{
    p[0xc] = 0xd;
    p[0xe] = 6;
}
