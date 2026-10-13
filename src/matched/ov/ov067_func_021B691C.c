/*
 * function: TOUCHBAR_FreeButton
 * address: 0x021B691C
 * packet: pkt_ov067_021B691C
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte alignment padding at 0x021B6932.
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   MI_CpuFill8 0x02082BCC arm
 */
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void MI_CpuFill8(void *p, unsigned int v, unsigned int n);
void TOUCHBAR_FreeButton(void **p)
{
    CLACT_DeleteActor(*p);
    MI_CpuFill8(p, 0, 0x38);
}
