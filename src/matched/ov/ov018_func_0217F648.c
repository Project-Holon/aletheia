/*
 * function: func_0217F648
 * address: 0x0217F648
 * packet: pkt_ov018_0217F648
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of alignment padding at 0x0217F67A.
 * symbols:
 *   func_0215A5F4 0x0215A5F4 thumb ov010
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_02159AE8 0x02159AE8 thumb ov010
 *   func_0217F67C 0x0217F67C thumb ov018
 *   func_0215897C 0x0215897C thumb ov010
 */
typedef unsigned short u16;
extern void *func_0215A5F4(void *);
extern void *func_0215A5DC(void *);
extern u16 *func_02159AE8(void *, void *);
extern void *func_0217F67C(void *, u16 *);
extern void func_0215897C(void *, void *);
int func_0217F648(void *a, void *vm)
{
    void *owner = func_0215A5F4(vm);
    void *sys = func_0215A5DC(vm);
    func_0215897C(owner, func_0217F67C(sys, func_02159AE8(a, vm)));
    return 1;
}
