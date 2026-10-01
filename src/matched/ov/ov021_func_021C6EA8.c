/*
 * function: func_021C6EA8
 * address:  0x021C6EA8
 * packet:   pkt_ov021_021C6EA8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C6CC4  0x021C6CC4  thumb  ov021
 *   func_021C6CE0  0x021C6CE0  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Q Q;
typedef struct { u8 n; u8 pad[3]; Q **f4; u32 *f8; } R;
extern int func_021C6CE0(Q *q);
extern void func_021C6CC4(Q *q);
void func_021C6EA8(R *r, int i)
{
    if (r->f4[i] != 0 && r->f8[i] != 0) {
        if (func_021C6CE0(r->f4[i]) == 0 && func_021C6CE0((Q *)r->f8[i]) == 2)
            func_021C6CC4(r->f4[i]);
    }
}
