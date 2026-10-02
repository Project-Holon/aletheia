/*
 * function: func_02156400
 * address: 0x02156400
 * packet: pkt_ov009_02156400
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021A8264 0x021A8264 data ov009 a4
 *   func_021AF1A0 0x021AF1A0 thumb ov013
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *d_021A8264;
extern void func_021AF1A0(void);
void func_02156400(void)
{
    func_021AF1A0();
    if (d_021A8264) {
        *(int *)(d_021A8264 + 0x76C) = 0;
        *(int *)(d_021A8264 + 0x768) = 0;
        *(u16 *)(d_021A8264 + 0x794) = 0;
    }
}
