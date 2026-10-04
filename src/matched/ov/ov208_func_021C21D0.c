/*
 * function: func_021C21D0
 * address: 0x021C21D0
 * packet: pkt_ov208_021C21D0
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_0204B3DC 0x0204B3DC arm
 */
#include "../include/Obj00081.h"
typedef unsigned char u8;
struct Obj;
struct PrintSys;
struct Descriptor;
struct CharBuf;
extern unsigned func_0204B3F4(struct Obj *);
extern void func_0201C6EC(struct PrintSys *);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *, u8);
extern void func_02045334(struct Descriptor *);
extern void func_0204B3DC(struct Obj *, unsigned);
void func_021C21D0(void *unused, char *p, int key)
{
    u8 i;
    if (func_0204B3F4(*(struct Obj * *)&((struct Obj00081 *)p)->fC8)) {
        ((struct Obj00081 *)p)->f30 = 0;
        func_0201C6EC(*(struct PrintSys * *)&((struct Obj00081 *)p)->f40);
        func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj00081 *)p)->f20), 0);
        func_02045334(*(struct Descriptor * *)&((struct Obj00081 *)p)->f20);
        func_0204B3DC(*(struct Obj * *)&((struct Obj00081 *)p)->fC8, 0);
    } else {
        for (i = 0; i < 61; i++) func_0204B3DC(*(struct Obj **)(p + i * 4 + 0xdc), 0);
    }
}
