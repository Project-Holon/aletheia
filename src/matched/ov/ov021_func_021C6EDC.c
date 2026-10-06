/*
 * function: func_021C6EDC
 * address:  0x021C6EDC
 * packet:   pkt_ov021_021C6EDC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C6CD0  0x021C6CD0  thumb  ov021
 *   func_021C6E74  0x021C6E74  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Q Q;
typedef struct { u8 n; u8 pad[3]; Q **f4; u32 *f8; } R;
extern int func_021C6CD0(u32 a);
extern void func_021C6E74(R *r, int i);
void func_021C6EDC(R *r, int i)
{
    if (r->f4[i] != 0 && func_021C6CD0((u32)r->f4[i]) == 1)
        func_021C6E74(r, i);
}
