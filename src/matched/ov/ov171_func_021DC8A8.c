/*
 * function: DENDOU_VIEW_ProcExit
 * address:  0x021DC8A8
 * packet:   pkt_021DC8A8
 * region:   ov171
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020315D4  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 */

struct Proc;
extern void func_020315D4(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);

int DENDOU_VIEW_ProcExit(void *p)
{
    func_020315D4(p);
    GFL_HEAP_DeleteChecked(0x8c);
    return 1;
}
