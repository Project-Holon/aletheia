/*
 * function: func_021EBB34
 * address:  0x021EBB34
 * packet:   pkt_ov170_021EBB34
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201EF40 0x0201EF40 thumb
 *   func_021EBA84 0x021EBA84 thumb
 *
 * Puts item v into word slot 0 and prints message 0xE into window i.
 *
 * Filed in src/pending although it compiles EXACT: the ov170 listing labels
 * 0x021EBB1C as one 64-byte ARM function and has no start at 0x021EBB28 or
 * 0x021EBB34.  The three are Thumb functions (two tail-call thunks to
 * func_021EBA84 and a sibling of func_021EBAF8).  Integrator: seed 0x021EBB1C
 * (Thumb, witness bl at 0x021E7B6E), 0x021EBB28 and 0x021EBB34 in
 * layout/function_starts.txt, then move all three to src/matched/ov.
 */

typedef unsigned int u32;

extern void func_0201EF40(void *ws, u32 i, u32 v);
extern void func_021EBA84(unsigned char *p, int msg, int i);

#define WORK(p) (*(char **)((p) + 0x2C))

void func_021EBB34(unsigned char *p, u32 v, int i)
{
    func_0201EF40(*(void **)(WORK(p) + 0x84), 0, v);
    func_021EBA84(p, 0xE, i);
}
