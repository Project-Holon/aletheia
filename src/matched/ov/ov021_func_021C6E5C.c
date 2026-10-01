/*
 * function: func_021C6E5C
 * address:  0x021C6E5C
 * packet:   pkt_ov021_021C6E5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*

 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Q Q;
typedef struct { u8 n; u8 pad[3]; Q **f4; u32 *f8; } R;
void func_021C6E5C(R *r, int i, Q *q, u32 v)
{
    if (r->f4[i] == 0) {
        r->f4[i] = q;
        r->f8[i] = v;
    }
}
