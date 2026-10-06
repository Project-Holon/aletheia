/*
 * function: func_021F55D4
 * address:  0x021F55D4
 * packet:   pkt_ov083_021F55D4
 * region:   ov083
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * `for (i = 0, n = 0; ...)` (not `n = 0;` before the loop) is what lets the
 * constant zero live in r4 across the calls and seeds `i` from it.
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_0200BF10  0x0200BF10  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_02190844  0x02190844  thumb  ov021
 *   func_021F556C  0x021F556C  thumb  ov083
 *   func_02010EB4  0x02010EB4  thumb
 *   func_02010EC0  0x02010EC0  thumb
 */
#include "../include/Obj00815.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Big;
extern void *func_02012EBC(struct Big *p);
extern u16 *func_0200BE48(void *sys);
struct Rec1B0;
extern u8 func_0200BF10(struct Rec1B0 *p);
struct MsgBank;
struct Slot;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_02190844(struct Slot **p, int x, int y, u32 z);
extern void  func_021F556C(char *p, u32 a1, u32 a2, int a3, u8 a4);
extern u8 func_02010EB4(int k);
extern u32 func_02010EC0(u32 i);

void func_021F55D4(char *p)
{
    u8 vals[13];
    u8 order[13];
    u16 keys[13];
    void *x;
    u8 c;
    u8 i;
    u8 j;
    u8 n;
    u8 t;

    x = func_0200BE48(func_02012EBC(((struct Obj00815 *)p)->fC));
    func_02045CAC((struct MsgBank *)(((struct Obj00815 *)p)->f28), 4, (void *)(((struct Obj00815 *)p)->f34));
    func_02190844((struct Slot **)(((struct Obj00815 *)p)->f18), 0, 0, ((struct Obj00815 *)p)->f34);
    func_02045CAC((struct MsgBank *)(((struct Obj00815 *)p)->f28), 6, (void *)(((struct Obj00815 *)p)->f34));
    c = (int)func_0200BF10(x);
    if (c != 0x30) {
        func_021F556C(p, ((struct Obj00815 *)p)->f34, c, 0, 1);
    }
    func_02045CAC((struct MsgBank *)(((struct Obj00815 *)p)->f28), 5, (void *)(((struct Obj00815 *)p)->f34));
    func_02190844((struct Slot **)(((struct Obj00815 *)p)->f18), 0, 0x30, ((struct Obj00815 *)p)->f34);
    func_02045CAC((struct MsgBank *)(((struct Obj00815 *)p)->f28), 7, (void *)(((struct Obj00815 *)p)->f34));

    for (i = 0, n = 0; i < 13; i++) {
        order[i] = i;
        c = (int)func_02010EB4((u8)i);
        if (c != 0x30) {
            keys[n] = func_02010EC0(i);
            vals[n] = c;
            n++;
        }
    }

    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--) {
            if (keys[order[j - 1]] > keys[order[j]]) {
                t = order[j];
                order[j] = order[j - 1];
                order[j - 1] = t;
            }
        }
    }

    for (i = 0; i < n; i++) {
        func_021F556C(p, ((struct Obj00815 *)p)->f34, vals[order[i]], keys[order[i]], i + 4);
    }
}
