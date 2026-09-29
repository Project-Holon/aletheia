/*
 * function: func_021C376C
 * address:  0x021C376C
 * packet:   pkt_ov093_021C376C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C37E0  0x021C37E0  thumb  ov093
 *   func_021C37F0  0x021C37F0  thumb  ov093
 *   func_021C3800  0x021C3800  thumb  ov093
 *   func_021C3810  0x021C3810  thumb  ov093
 *   func_021C5718  0x021C5718  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct { u8 pad[5]; u8 f : 1; } Q;

extern void func_021C37E0(int it);
extern int func_021C37F0(int it);
extern int func_021C3800(int it);
extern int func_021C3810(u8 *p, int b, int r, int z, int *out, int z1, int z2, int z3);
extern void func_021C5718(u8 *p, int b, int c);

void func_021C376C(u8 *p, u16 a1, int b, int it)
{
    int v = 0;
    int r;
    func_021C37E0(it);
    r = func_021C37F0(it);
    while (r) {
        if (func_021C3810(p, b, r, 0, &v, 0, 0, 0)) {
            Q *q = *(Q **)(p + 0x4a8);
            if (!q->f)
                q->f = 1;
        } else if (v == 0) {
            func_021C5718(p, b, a1);
        }
        r = func_021C3800(it);
    }
}
