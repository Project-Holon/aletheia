/*
 * function: func_02187098
 * address: 0x02187098
 * packet: pkt_ov020_02187098
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0215A5F4 0x0215A5F4 thumb ov010
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_0201210C 0x0201210C thumb
 *   func_021870C4 0x021870C4 thumb ov020
 *   func_0215897C 0x0215897C thumb ov010
 */
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *p);
extern void *func_0201210C(void *p);
extern void *func_021870C4(void *a, void *b);
extern void func_0215897C(void *vm, void *task);
int func_02187098(void *unused, void *p)
{
    void *vm;
    void *obj;
    vm = func_0215A5F4(p);
    obj = func_0215A5DC(p);
    func_0215897C(vm, func_021870C4(obj, func_0201210C(obj)));
    return 1;
}
