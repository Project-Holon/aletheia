/*
 * function: func_021B8448
 * address: 0x021B8448
 * packet: pkt_ov172_021B8448
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH
 * note 2026-10-02: byte-correct. Only open relocation: the tail-call target 0x02179650 (pool word 0x02179651)
 *   is an unlabelled thumb leaf in ov014 ("ldr r1, =g_021797A8; ldr r2, [r1]; ldr r1, =0x1EC2; strh r0, [r2, r1]; bx lr").
 *   ov014 is outside this lane (pengy range); seeding 0x02179650 there closes this one.
 * symbols:
 *   func_02179650 0x02179650 thumb ov014
 */
typedef unsigned short u16;
extern void func_02179650(u16 v);
void func_021B8448(void *p, char *q)
{
    func_02179650(5);
}
