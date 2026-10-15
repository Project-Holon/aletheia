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
 *   func_020306F0  0x020306F0  arm
 */

struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);

int STAFF_ROLL_Exit(void *p)
{
    func_020315D4(p);
    func_020306F0(0x8e);
    return 1;
}
