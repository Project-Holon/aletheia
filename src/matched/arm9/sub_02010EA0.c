/*
 * function: sub_02010EA0
 * address:  0x02010EA0
 * packet:   pkt_02010DB4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_0214621C  0x0214621C  data
 *
 * The second unlabelled leaf after sub_02010E14 (it saves no lr, so
 * disasm.py never labels it; see docs/idioms/unlabelled-leaf-functions-hide-
 * in-word-runs.md).  It reads the state byte for the record `rec[slot]`
 * names, using the same 0xc-byte record stride and +0xa slot field that
 * sub_02010E14 writes with.
 *
 * The pointer must be ADVANCED into its own value first: writing the whole
 * thing as one subscript, `g_0214621C[rec[slot * 0xc + 0xa]]`, folds the
 * +0xa into the scaled index and gives `adds r2, #0xa; ldrb r1, [r1, r2]`
 * where the original has `adds r0, r1, r2; ldrb r1, [r0, #0xa]` - four bytes
 * in the same place, same size, and the only difference in the function.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02010EA0.c \
 *       --func sub_02010EA0 --addr 0x02010EA0 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;

extern u8 g_0214621C[];

u8 sub_02010EA0(int slot, u8 *rec)
{
    rec = rec + slot * 0xc;
    return g_0214621C[rec[0xa]];
}
