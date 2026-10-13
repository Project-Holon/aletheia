/*
 * function: func_021BED2C
 * address:  0x021BED2C
 * packet:   pkt_ov210_021BED2C
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BEE94 0x021BEE94 thumb ov210
 *   func_021BEEC4 0x021BEEC4 thumb ov210
 *   func_021BF0DC 0x021BF0DC thumb ov210
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 * Addresses are Black-image addresses.
 */

extern void func_021BEE94(void);
struct Obj021BF0DC;
struct Res021BEEC4;
extern void func_021BEEC4(struct Res021BEEC4 *p);
extern void func_021BF0DC(struct Obj021BF0DC *p);
typedef unsigned int   u32;
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

void func_021BED2C(int p)
{
    func_021BEE94();
    func_021BEEC4((struct Res021BEEC4 *)p);
    func_021BF0DC((struct Obj021BF0DC *)p);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}
