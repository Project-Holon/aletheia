/*
 * function: func_0217F914
 * address: 0x0217F914
 * packet: pkt_ov018_0217F914
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding follow at 0x0217F936.
 * symbols:
 *   func_0215A5F4 0x0215A5F4 thumb ov010
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_0215897C 0x0215897C thumb ov010
 *   func_0217F938 0x0217F938 thumb ov018
 */
extern void *func_0215A5F4(void *);
extern void *func_0215A5DC(void *);
extern void func_0215897C(void *, void *);
extern void *func_0217F938(void *);
int func_0217F914(void *unused, void *vm)
{
    void *owner;
    owner = func_0215A5F4(vm);
    func_0215897C(owner, func_0217F938(func_0215A5DC(vm)));
    return 1;
}
