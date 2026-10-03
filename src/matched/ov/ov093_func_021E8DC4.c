/*
 * function: func_021E8DC4
 * address:  0x021E8DC4
 * packet:   pkt_ov093_021E8DC4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ov094_id       0x0000005E  data
 *   ov095_id       0x0000005F  data
 *   ov096_id       0x00000060  data
 *   func_021E8E38  0x021E8E38  thumb  ov093
 *   func_02034AC4  0x02034AC4  arm
 *   func_0208068C  0x0208068C  arm
 *   func_0203D29C  0x0203D29C  arm
 */
extern char ov094_id[], ov095_id[], ov096_id[];
extern void func_021E8E38(unsigned short heap);
extern int func_02034AC4(int id);
extern void func_0208068C(unsigned int v);
typedef unsigned int   u32;
extern u32 func_0203D29C(void);

void func_021E8DC4(unsigned short heap)
{
    func_021E8E38(heap);
    func_02034AC4((int)ov094_id);
    func_0208068C(0x80);
    func_02034AC4((int)ov095_id);
    if (func_0203D29C() == 0) {
        func_02034AC4((int)ov096_id);
    }
}
