/*
 * function: func_021FC4E4
 * address: 0x021FC4E4
 * packet: pkt_ov135_021FC4E4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021FC526..021FC528 is two zero alignment bytes.
 * symbols:
 *   func_02202940 0x02202940 thumb ov135
 *   func_020452E8 0x020452E8 arm
 */
#include "../include/Obj00287.h"
extern void func_02202940(void *);
struct Descriptor;
extern void func_020452E8(struct Descriptor *d);
void func_021FC4E4(char *p)
{
    int i;
    func_02202940(p + 0xfa0);
    func_020452E8(((struct Obj00287 *)p)->fDE0);
    func_020452E8(((struct Obj00287 *)p)->fD40);
    func_020452E8(((struct Obj00287 *)p)->fD50);
    for (i = 0; i < 14; i++) {
        func_020452E8(*(void **)(p + i * 4 + 0xd90));
    }
}
