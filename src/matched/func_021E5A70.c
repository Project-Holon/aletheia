/*
 * function: func_021E5A70
 * address:  0x021E5A70
 * packet:   pkt_021E5A70
 * region:   ov178
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   func_0217E00C  0x0217E00C  thumb  ov176
 *   ov176_id       0x000000B0  data
 */
typedef unsigned char u8;
typedef unsigned int u32;

extern void func_02034AC4(u32 v);
extern u32 func_0217E00C(u32 v, u32 n);
extern u8 ov176_id[];

void func_021E5A70(u32 *out, u32 **pp, u32 v)
{
    func_02034AC4((u32)ov176_id);
    *out = func_0217E00C(*(u32 *)*pp, v);
}
