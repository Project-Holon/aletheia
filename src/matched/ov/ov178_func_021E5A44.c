/*
 * function: func_021E5A44
 * address:  0x021E5A44
 * packet:   pkt_021E5A44
 * region:   ov178
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D9EA0  0x021D9EA0  thumb  ov175
 *   func_02034A5C  0x02034A5C  arm
 *   ov175_id       0x000000AF  data
 *   ov114_id       0x00000072  data
 *   ov067_id       0x00000043  data
 */
typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021D9EA0(u32);
extern void func_02034A5C(u32 v);
extern u8 ov175_id[];
extern u8 ov114_id[];
extern u8 ov067_id[];

void func_021E5A44(void **pp)
{
    if (*pp == 0)
        return;
    func_021D9EA0((u32)*pp);
    func_02034A5C((u32)ov175_id);
    func_02034A5C((u32)ov114_id);
    func_02034A5C((u32)ov067_id);
}
