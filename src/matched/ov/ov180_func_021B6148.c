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
 *   func_020306F0  0x020306F0  arm
 */

struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int);

int HALL_OF_FAME_ProcExit(void *p)
{
    func_020315D4(p);
    func_020306F0(0x8d);
    return 1;
}
