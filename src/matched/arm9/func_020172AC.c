/*
 * function: MCSS_TOOL_SetSpindaSpotHook
 * address:  0x020172AC
 * packet:   pkt_020172AC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MCSS_SetLoadHook  0x02014CF0  thumb
 *   MCSS_TOOL_SpindaSpotHook  0x020172BC  thumb
 *
 * A four-instruction tail call: the second argument is replaced by a function
 * pointer (the pool word 0x020172BD, the Thumb bit set), the first and third
 * pass through, and the target is loaded from the pool and branched to with
 * `bx r3`.  The callee is the label-less Thumb leaf src/matched/MCSS_SetLoadHook.c.
 *
 * The `symbols:` line is load-bearing.  Without it the name `MCSS_SetLoadHook`
 * carries the address but the naming convention can only guess the ISA, and
 * an address no `func_` label was traced at is guessed ARM -- so the site
 * was reported as "02014CF0 (arm, from name) has no witness" and the file sat
 * at MATCH, because MCSS_SetLoadHook is a Thumb manifest entry and the `matched`
 * class refuses an ISA that does not agree with it.  Declaring the ISA
 * explicitly (origin "header") resolves the word to 0x02014CF1, which is what
 * the image holds.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MCSS_TOOL_SetSpindaSpotHook.c \
 *       --func MCSS_TOOL_SetSpindaSpotHook --addr 0x020172AC --cc 1.1p1 --thumb
 */

struct Obj02014CF0;
extern void MCSS_SetLoadHook(struct Obj02014CF0 *o, int v1, int v2);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 MCSS_TOOL_SpindaSpotHook(u8 *a0, u8 **a1, u32 a2);

void MCSS_TOOL_SetSpindaSpotHook(int a0, int a1)
{
    MCSS_SetLoadHook((struct Obj02014CF0 *)a0, (int)MCSS_TOOL_SpindaSpotHook, a1);
}
