/*
 * function: ITEMMENU_FlushWindowAt
 * address: 0x021BB724
 * packet: pkt_ov070_021BB724
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two-byte alignment padding at 0x021BB73A.
 * symbols:
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Cfg;
struct Descriptor;
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern u8 func_02045730(struct Descriptor *);
extern void func_02041B6C(u32);
void ITEMMENU_FlushWindowAt(void **p)
{
    BMP_WIN_MakeScreen(*p);
    func_02041B6C(func_02045730(*p));
}
