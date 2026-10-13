/*
 * function: func_021DD1A4
 * address:  0x021DD1A4
 * packet:   pkt_021DD1A4
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DD14C  0x021DD14C  thumb
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   func_020419E4  0x020419E4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021DD14C(void *unused, u8 *p);
extern void CLACT_VBlankSystem(void);
extern void func_020419E4(void);

void func_021DD1A4(void *a0, void *work)
{
    func_021DD14C(a0, work);
    CLACT_VBlankSystem();
    func_020419E4();
}
