/*
 * function: func_021BC7F0
 * address:  0x021BC7F0
 * packet:   pkt_021BC52C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_021BC7F0   0x021BC7F0  thumb
 *   func_021DD13C   0x021DD13C  data  ov016
 *
 * Fill 0xe8 bytes of the 0x021DD13C buffer, then report success.
 *
 * NOT EXACT.  MATCH: the pool word names 0x021DD13C, a bss address of ov016 that nine overlays
 * share and that another overlay starts an object at, so the `ov016` hint is
 * contested and no class attests it.  It turns EXACT when an attestation
 * extension resolves a contested bss object, or when a second reference to
 * 0x021DD13C exists outside this function.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_021BC7F0.c \
 *       --func func_021BC7F0 --addr 0x021BC7F0 --region ov016 --cc dsi/1.1p1 --thumb
 */

extern void func_02092344(int, char *, int);
extern char func_021DD13C[];

int func_021BC7F0(int a)
{
    func_02092344(a, func_021DD13C, 0xe8);
    return 1;
}
