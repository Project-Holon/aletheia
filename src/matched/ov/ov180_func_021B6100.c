/*
 * function: func_021B6100
 * address: 0x021B6100
 * packet: pkt_ov180_021B6100
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: 0203159C own source says void; caller consumes live allocation r0,
 * and full callee stores that pointer then leaves r0 unchanged through return.
 */
typedef unsigned int u32;
struct Obj0203159C;
extern void func_0203064C(void *, u32, u32);
extern u32 *func_0203159C(struct Obj0203159C *, u32, u32);
extern void func_02082BCC(void *, u32, u32);
int func_021B6100(struct Obj0203159C *obj, void *unused, u32 value)
{
    u32 *p;
    func_0203064C((void *)1, 141, 0x60000);
    p = func_0203159C(obj, 0x919C, 141);
    func_02082BCC(p, 0, 0x919C);
    *p = value;
    return 1;
}
