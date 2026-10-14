/*
 * function: WORLDTRADE_GetWifiLinkLevel
 * address:  0x021F4EB4
 * packet:   pkt_021F4EB4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  the only callee, 0x0205CCD8, is a 12-byte ARM veneer (ldr ip,[pc]; bx ip;.word 0x021666C8) emitted as data words in asm/arm9/main.s, so it has no func_ label; the `veneer` class refuses it too because its own pointer target 0x021666C8 is not known code to names_known_code().  All 12 bytes are right, including the BLX pair.
 *
 * symbols:
 *   DWC_GetLinkLevel  0x0205CCD8  arm

 *
 * Return 3 minus the hardware counter read back through the arm9 veneer at 0x0205CCD8.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/WORLDTRADE_GetWifiLinkLevel.c --func WORLDTRADE_GetWifiLinkLevel  *       --addr 0x021F4EB4 --region ov135 --thumb --cc dsi/1.1p1 --diff
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int DWC_GetLinkLevel(void);

int WORLDTRADE_GetWifiLinkLevel(void)
{
    return 3 - DWC_GetLinkLevel();
}
