/*
 * function: ZUKAN_LIST_ProcExit
 * address:  0x021BC288
 * packet:   pkt_021BC288
 * region:   ov209
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 */

struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);

int ZUKAN_LIST_ProcExit(void *p)
{
    func_020315D4(p);
    GFL_HEAP_DeleteChecked(0x6b);
    return 1;
}
