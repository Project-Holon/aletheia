/*
 * function: func_021F3890
 * address:  0x021F3890
 * packet:   pkt_ov056_021F3890
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218C7D8  0x0218C7D8  thumb  ov021
 *   func_0218C654  0x0218C654  thumb  ov021
 *   d_021F4290  0x021F4290  data  ov056  a4
 *   d_021F42D8  0x021F42D8  data  ov056  a4
 */

typedef unsigned int u32;

typedef struct { u32 a, b, c; } Ent;

extern int func_0218C7D8(void *p, int b, int c);
extern int func_0218C654(int a, int b, int c);
extern u32 d_021F4290[];
extern Ent d_021F42D8[];

void func_021F3890(u32 *out, int a, int idx)
{
    if (d_021F4290[idx] != 0) {
        out[0] = func_0218C7D8((void *)a, 0, (int)(&d_021F42D8[idx]));
        out[1] = func_0218C654(a, 0, (int)(&d_021F42D8[idx]));
        out[2] = a;
    } else {
        out[0] = 0;
        out[1] = 0;
    }
}
