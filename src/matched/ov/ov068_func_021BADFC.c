/*
 * function: func_021BADFC
 * address: 0x021BADFC
 * packet: pkt_ov068_021BADFC
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045808 0x02045808 arm
 *   func_021BA254 0x021BA254 thumb ov068
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
extern void func_021BA254(u8 *);
extern void func_02082BCC(void *, u32, u32);
void func_021BADFC(u8 *p)
{
    int i;
    for (i = 0; i < 2; i++) func_02045808((struct U16Vec *)(*(u32 *)(p + i * 12 + 60)));
    func_021BA254(p);
    func_02082BCC(p, 0, 112);
}
