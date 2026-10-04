/*
 * function: func_021BA9C0
 * address:  0x021BA9C0
 * packet:   pkt_ov070_021BA9C0
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02027778  0x02027778  thumb
 *   func_02045808  0x02045808  arm
 *   func_021BB3F4  0x021BB3F4  thumb  ov070
 *
 * Levers: the object pointer must be a byte pointer (as an int the
 * loop-invariant p+0x544 is not hoisted into its own stack slot), and the
 * 12-byte record pointer e is formed before the allocation call.
 */
#include "../include/Obj00002.h"
#include "../include/Obj09881.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int a;
    u8 b;
    u8 pad[3];
    int c;
    int d;
    u8 e;
    u8 f;
    u8 g;
    u8 h;
} Desc;

typedef unsigned int   u32;
struct MsgBank;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern int func_02027778(Desc *, int);
extern void func_02045808(struct U16Vec *vec);
extern void func_021BB3F4(int p, int mode);

void func_021BA9C0(u8 *p, int *tbl, int n)
{
    Desc s;
    int i;
    int r;
    u8 *e;

    s.a = ((struct Obj00002 *)p)->f544;
    s.b = n;
    s.c = (int)(p + 0x780);
    s.d = 1;
    s.e = 0x20;
    s.f = 0x18;
    s.g = 0xD;
    s.h = 3;
    for (i = 0; i < n; i++) {
        e = p + i * 0xC;
        r = (int)func_020457B0(0x64, ((struct Obj00002 *)p)->f544);
        ((struct Obj09881 *)e)->f780 = r;
        func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00002 *)p)->f51C), tbl[i], (void *)r);
        ((struct Obj09881 *)e)->f784 = 0x39E0;
        ((struct Obj09881 *)e)->f788 = 0;
    }
    *(int *)(p + (i - 1) * 0xC + 0x788) = 1;
    *(int *)&((struct Obj00002 *)p)->f77C = func_02027778(&s, ((struct Obj00002 *)p)->f7E0);
    for (i = 0; i < n; i++) {
        func_02045808((struct U16Vec *)(*(int *)(p + i * 0xC + 0x780)));
    }
    func_021BB3F4((int)p, 0);
}
