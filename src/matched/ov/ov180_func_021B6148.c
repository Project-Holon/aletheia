/*
 * function: HALL_OF_FAME_ProcExit
 * address:  0x021B6148
 * packet:   pkt_021B6148
 * region:   ov180
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
extern void GFL_HEAP_DeleteChecked(unsigned int);

int HALL_OF_FAME_ProcExit(void *p)
{
    func_020315D4(p);
    GFL_HEAP_DeleteChecked(0x8d);
    return 1;
}
