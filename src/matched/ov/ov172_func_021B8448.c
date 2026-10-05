/*
 * function: func_021B8448
 * address: 0x021B8448
 * packet: pkt_ov172_021B8448
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note (2026-10-05, wD4 lane17): still MATCH, only the ov014 leaf 02179650 (pengy range, no label) is unresolved.
 * note 2026-10-04 wD2 lane01: still MATCH. Symbols line already has `thumb ov014`; match.py still says no witness (ov009/ov014 overlap, 021797A8-area leaf func_02179650 unlabelled in pengy's ov014). Needs a matched/labelled leaf at 0x02179650 in ov014 (pengy range, not touched).
 * note 2026-10-02: byte-correct. Only open relocation: the tail-call target 0x02179650 (pool word 0x02179651)
 *   is an unlabelled thumb leaf in ov014 ("ldr r1, =g_021797A8; ldr r2, [r1]; ldr r1, =0x1EC2; strh r0, [r2, r1]; bx lr").
 *   ov014 is outside this lane (pengy range); seeding 0x02179650 there closes this one.
 * symbols:
 *   func_02179650 0x02179650 thumb ov014
 * note 2026-10-05 (wD8 lane06): re-run, still MATCH. Only blocker: func_02179650, an unlabelled Thumb leaf in ov014
 *   (pengy's overlay, not same-overlay, so the witness exception does not apply). Seeding that label closes this.
 */
typedef unsigned short u16;
extern void func_02179650(u16 v);
void func_021B8448(void *p, char *q)
{
    func_02179650(5);
}
