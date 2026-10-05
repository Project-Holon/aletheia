/*
 * function: func_021F0218
 * address: 0x021F0218
 * packet: pkt_ov035_021F0218
 * region: ov035
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0201F614 THM_CALL at +0x36 has no outside witness.
 * interface: 0201F614 forwards r0 and splits packed r1 into two halfwords;
 *            02028604 uses only r0; legacy trailing inputs are unread.
 * symbols:
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_02028604 0x02028604 thumb
 *   func_02031140 0x02031140 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201F614 0x0201F614 thumb
 *
 * 2026-10-05 (D8 lane 15): 0201F614 now filed EXACT as src/matched/arm9/func_0201F614.c (u16 lo, u16 hi split of r1).
 * Re-run after the integrator regenerates the layout; expected EXACT.
 */
extern void func_0201CE48(void *);
extern void func_02045808(void *);
extern void func_02028604(void *);
extern void func_02031140(void *);
extern void func_020452E8(void *);
extern void func_0201F614(int, unsigned int);
void func_021F0218(char *p)
{
    if (*(void **)(p + 0x24)) {
        func_0201CE48(*(void **)(p + 0x24));
        *(void **)(p + 0x24) = 0;
        func_02045808(*(void **)(p + 0x28));
        *(void **)(p + 0x28) = 0;
    }
    func_02028604(*(void **)(p + 0x30));
    func_02031140(*(void **)(p + 0x20));
    func_020452E8(*(void **)(p + 0x1c));
    func_020452E8(*(void **)(p + 0x18));
    func_0201F614(5, *(unsigned int *)(p + 0x14));
}
