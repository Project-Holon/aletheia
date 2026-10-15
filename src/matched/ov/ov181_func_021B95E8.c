/*
 * function: STAFF_ROLL_Exit
 * address:  0x021B95E8
 * packet:   pkt_ov181_021B95E8
 * region:   ov181
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

int STAFF_ROLL_Exit(void *p)
{
    func_020315D4(p);
    GFL_HEAP_DeleteChecked(0x8e);
    return 1;
}
