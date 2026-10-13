/*
 * function: func_021C0AF0
 * address:  0x021C0AF0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: branch to CLACT_ExitSystem.
 *
 * Addresses are Black-image addresses.
 *
 * symbols:
 *   CLACT_ExitSystem  0x0204A5AC  arm  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void CLACT_ExitSystem(void);

void func_021C0AF0(void)
{
    CLACT_ExitSystem();
}
