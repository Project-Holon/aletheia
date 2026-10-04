/*
 * function: func_021BD504
 * address:  0x021BD504
 * packet:   pkt_ov091_021BD504
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BB7D8  0x021BB7D8  thumb  ov091
 *   func_021BB714  0x021BB714  thumb  ov091
 *   func_021BB97C  0x021BB97C  thumb  ov091
 *   func_021BBA0C  0x021BBA0C  thumb  ov091
 *   func_021BB7E8  0x021BB7E8  thumb  ov091
 *   func_021BB98C  0x021BB98C  thumb  ov091
 *   func_020457B0  0x020457B0  arm
 *   func_02045924  0x02045924  arm
 *   func_02045808  0x02045808  arm
 */
#include "../include/Obj00009.h"
#include "../include/Obj20922.h"
#include "../include/Obj20923.h"
#include "../include/Obj20924.h"
#include "../include/Obj20925.h"
#include "../include/Obj20926.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef unsigned int   u32;
extern int func_021BB7D8(void *unused, u32 p);
struct Strbuf;
struct U16Vec;
extern void func_021BB714(void *a, u32 *s, u32 k);
extern void func_021BB97C(char *a, int x);
extern void func_021BBA0C(int a, int b, int c, int d, int e);
extern void func_021BB7E8(char *a, int x, int y);
extern void func_021BB98C(void *p, u32 s);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_02045808(struct U16Vec *vec);

void func_021BD504(char *a)
{
    int t;
    if (((struct Obj20922 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f94 == 0)
        return;
    if (func_021BB7D8(a, *(int *)&((struct Obj00009 *)a)->f150) == 0)
        func_021BB714(a, (u32 *)(*(int *)&((struct Obj00009 *)a)->f150), 1);
    if (((struct Obj20923 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f64 == 1) {
        t = (int)func_020457B0(0x10, ((struct Obj00009 *)a)->f0);
        func_02045924((struct Strbuf *)t, (const u16 *)(((struct Obj20924 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f78));
        func_021BB97C(a, *(int *)&((struct Obj00009 *)a)->f150);
        func_021BBA0C((int)a, *(int *)&((struct Obj00009 *)a)->f150, 0, t, ((struct Obj20925 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f7C);
        func_021BB7E8(a, *(int *)&((struct Obj00009 *)a)->f150, 0xA9);
        func_021BB98C(a, *(int *)&((struct Obj00009 *)a)->f150);
        func_02045808((struct U16Vec *)t);
    } else {
        func_021BB7E8(a, *(int *)&((struct Obj00009 *)a)->f150, ((struct Obj20926 *)(*(char * *)&((struct Obj00009 *)a)->f280))->f94 + 0xA9);
    }
}
