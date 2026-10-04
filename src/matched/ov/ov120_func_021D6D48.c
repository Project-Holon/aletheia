/*
 * function: func_021D6D48
 * address: 0x021D6D48
 * packet: pkt_ov120_021D6D48
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_02049238 0x02049238 arm
 *   func_021D698C 0x021D698C thumb ov120
 *   func_021D692C 0x021D692C thumb ov120
 *   func_021D6ED8 0x021D6ED8 thumb ov120
 */
#include "../include/Obj00199.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, u16 heap);
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_02049238(void *);
extern void func_021D698C(u8 *);
extern void func_021D692C(u8 *, int);
extern void func_021D6ED8(u8 *);
void func_021D6D48(u8 *p)
{
    void *t = func_020490F4(144, ((struct Obj00199 *)p)->fF4);
    int i;
    for (i = 0; i < 6; i++) {
        if (*(void **)(p + i * 4 + 0x14c)) {
            func_0204B3B4(*(void **)(p + i * 4 + 0x14c));
            *(void **)(p + i * 4 + 0x14c) = 0;
        }
    }
    func_021D698C(p);
    func_021D692C(p, 0);
    func_021D6ED8(p);
    func_02049238(t);
}
