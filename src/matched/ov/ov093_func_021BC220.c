/*
 * function: func_021BC220
 * address:  0x021BC220
 * packet:   pkt_ov093_021BC220
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB85C  0x021BB85C  thumb  ov093
 *   func_021BB8A8  0x021BB8A8  thumb  ov093
 *   func_021BB8B0  0x021BB8B0  thumb  ov093
 *   func_021BD9D4  0x021BD9D4  thumb  ov093
 *   func_021BDA00  0x021BDA00  thumb  ov093
 *   func_021C5200  0x021C5200  thumb  ov093
 *
 * func_021BB8B0 returns a 4-byte bitfield struct: declaring it that way
 * (a u32 return with shifts and masks gives a different frame) is what
 * matches.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 a : 4;
    u32 b : 3;
    u32 c : 3;
    u32 d : 1;
} Bf;

extern int func_021BB85C(int p, u8 i);
extern u8 func_021BB8A8(u8 *p, u8 i);
extern Bf func_021BB8B0(u8 *p, u8 i, u8 j);
extern void func_021BD9D4(u8 *p, u8 i, u8 a, u8 b, u8 c);
extern void func_021BDA00(u8 *p);
extern void func_021C5200(u8 *p);

void func_021BC220(u8 *p, u8 *o)
{
    u32 i;
    u32 j;
    u32 n;
    Bf v;

    for (i = 0; i < 4; i++) {
        if (func_021BB85C(*(int *)p, i) != 0) {
            n = func_021BB8A8(o, i);
            for (j = 0; j < n; j++) {
                v = func_021BB8B0(o, i, j);
                if (v.a == 3 && v.d == 0)
                    func_021BD9D4(p, i, v.b, v.c, 1);
            }
        }
    }
    func_021BDA00(p);
    func_021C5200(p);
}
