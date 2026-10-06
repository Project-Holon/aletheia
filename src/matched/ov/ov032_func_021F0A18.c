/*
 * function: func_021F0A18
 * address:  0x021F0A18
 * packet:   pkt_ov032_021F0A18
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B898  0x0204B898  arm
 *   func_02035D40  0x02035D40  arm
 *   func_021F0DD8  0x021F0DD8  thumb  ov032
 *   d_021F3530     0x021F3530  data  a2
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Obj;
extern u16 func_0204B898(struct Obj *p);
struct Ctx;
extern u32 func_02035D40(struct Ctx *ctx, u32 a, u32 b);
extern void func_021F0DD8(u32 v);
extern u16 d_021F3530[];

int func_021F0A18(u8 *p, u32 *v)
{
    u8 b[5];
    int i;

    b[4] = 0xff;
    for (i = 0; i < 4; i++) {
        u32 a = func_0204B898((struct Obj *)(*(u32 *)(p + 0x2bc + i * 4)));
        if ((u8)(a - (i * 3 + 1)) % 3 < 2) {
            b[0] = 0xac;
            b[1] = b[0] + 0x18;
            b[2] = i * 32 + 0x84;
            b[3] = b[2] + 0x18;
            if (func_02035D40((struct Ctx *)b, v[0], v[1]) != -1) {
                func_021F0DD8(d_021F3530[i]);
                return i;
            }
        }
    }
    return -1;
}
