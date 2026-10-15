/*
 * function: PDC_ProcExit
 * address: 0x021B61C4
 * packet: pkt_ov098_021B61C4
 * region: ov098
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PDC_MAIN_Delete 0x021B632C thumb ov098
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov094_id 0x0000005E data
 */
extern void PDC_MAIN_Delete(unsigned p);
struct Proc;
extern void func_020315D4(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
extern void func_02034A5C(int);
extern char ov094_id[];
int PDC_ProcExit(void *a, int b, int c, void **p)
{
    PDC_MAIN_Delete((unsigned int)(*p));
    func_020315D4(a);
    GFL_HEAP_DeleteChecked(0x85);
    func_02034A5C((int)ov094_id);
    return 1;
}
