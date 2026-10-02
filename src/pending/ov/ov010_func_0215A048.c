/*
 * function: func_0215A048
 * address: 0x0215A048
 * packet: pkt_ov010_0215A048
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH
 * blocker: THM_CALL func_02014184 at +0x14 has no outside witness;
 * ARM9 unlabelled Thumb leaf, label/sole-ref-code refuses, owned by Ilias.
 * split: 14 image references (1 inside); none provides the missing traced
 * function-start witness. tu --suggest-split leaves caller OUT, no viable cut.
 * symbols:
 *   func_02014184 0x02014184 thumb
 */
typedef unsigned short u16;
extern void func_02014184(void *, int, short, int, int, int);
void func_0215A048(void *a, int b, int c, unsigned d, u16 e) {
 func_02014184(a, b, 1, d << 16, 0, (unsigned)e << 16);
}
