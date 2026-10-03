/*
 * function: func_021BA60C
 * address: 0x021BA60C
 * packet: pkt_ov099_021BA60C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02049F34 0x02049F34 arm
 *   d_021C2878 0x021C2878 data ov099 a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02082BCC(void *, u32, u32);
extern void *func_02049F34(u32, u32, void *, u16);
extern const u16 d_021C2878[];
void func_021BA60C(char *a, char *p, u32 unused, u32 arc)
{
    func_02082BCC(p, 0, 20);
    *(void **)p = func_02049F34(arc, 9, p + 4, *(u32 *)(a + 4));
    p[9] = 0;
    p[8] = 15;
    *(u16 *)(p + 10) = d_021C2878[(u8)p[9]];
}
