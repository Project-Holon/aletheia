/*
 * function: SAVE_SCREEN_Exit
 * address:  0x021B9864
 * packet:   pkt_021B9864
 * region:   ov205
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
extern void GFL_HEAP_DeleteChecked(unsigned int);

int SAVE_SCREEN_Exit(void *p)
{
    func_020315D4(p);
    GFL_HEAP_DeleteChecked(0x54);
    return 1;
}
