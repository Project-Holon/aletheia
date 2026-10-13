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
 *   func_02082BCC 0x02082BCC arm
 */
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void func_02082BCC(void *p, unsigned int v, unsigned int n);
void TOUCHBAR_FreeButton(void **p)
{
    CLACT_DeleteActor(*p);
    func_02082BCC(p, 0, 0x38);
}
