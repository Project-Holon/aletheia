/*
 * function: func_021C2488
 * address: 0x021C2488
 * packet: pkt_ov093_021C2488
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   sub_0201BD28 0x0201BD28 thumb
 *   sub_0201BF58 0x0201BF58 thumb
 *   func_021D7C70 0x021D7C70 thumb ov093
 *   func_021C2564 0x021C2564 thumb ov093
 *   func_021C2574 0x021C2574 thumb ov093
 *   func_021C2584 0x021C2584 thumb ov093
 *   func_021C2594 0x021C2594 thumb ov093
 *   func_021C25A4 0x021C25A4 thumb ov093
 *   func_021C5718 0x021C5718 thumb ov093
 */
#include "../include/Obj21083.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 v; } W;
typedef struct { u32 v; } Word;
typedef struct { u8 pad[5]; u8 f:1; } BF;
typedef struct { u8 pad[0x78a]; u8 low:4; u8 f:1; } State;
extern u32 sub_0201BD28(u16, u32);
extern W sub_0201BF58(u16);
extern void func_021D7C70(W, u32, Word *);
extern u32 func_021C2564(u32);
extern void func_021C2574(u32);
extern u32 func_021C2584(u32);
extern u32 func_021C2594(u32);
extern int func_021C25A4(u8 *, u32, u32, u32, u32, Word, u32);
extern void func_021C5718(u8 *, u8 *, u32);
void func_021C2488(u8 *p, u16 id, u8 *a, u32 c)
{
    u32 s;
    W w;
    Word out;
    u32 t;
    int got;
    s = sub_0201BD28(id, 11);
    w = sub_0201BF58(id);
    got = 0;
    if (func_021C2564(c)) {
        func_021C2574(c);
        for (t = func_021C2584(c); t; t = func_021C2594(c)) {
            func_021D7C70(w, (u32)a, &out);
            if (func_021C25A4(p, (u32)a, t, id, s, out, 1)) {
                BF *flag = *(BF * *)&((struct Obj21083 *)p)->f4A8;
                if (!flag->f) flag->f = 1;
                got = 1;
            }
        }
        if (!got && !((State *)p)->f) func_021C5718(p, a, id);
    } else {
        func_021C5718(p, a, id);
    }
}
