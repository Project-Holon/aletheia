/*
 * function: func_021BAE28
 * address:  0x021BAE28
 * packet:   pkt_ov068_021BAE28
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA31C  0x021BA31C  thumb  ov068
 *   func_02027778  0x02027778  thumb
 *   func_02027974  0x02027974  thumb
 *   func_020279E8  0x020279E8  thumb
 *   func_02027A04  0x02027A04  thumb
 *   func_02027858  0x02027858  thumb
 */
#include "../include/Obj02417.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct TaskMenu;
extern int func_021BA31C(u8 *p);
struct TaskMenuTmpl;
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void  func_02027974(void *p);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8    func_02027A04(const u8 *p);
extern void func_02027858(struct TaskMenu *m);

void func_021BAE28(u8 *p)
{
    switch (((struct Obj02417 *)p)->f56) {
    case 0:
        if (func_021BA31C(p) != 0) {
            ((struct Obj02417 *)p)->f56 = 1;
        }
        break;
    case 1:
        ((struct Obj02417 *)p)->f38 = func_02027778((struct TaskMenuTmpl *)(p + 0x58), ((struct Obj02417 *)p)->f6C);
        ((struct Obj02417 *)p)->f56 = 2;
        break;
    case 2:
        func_02027974(((struct Obj02417 *)p)->f38);
        if (func_020279E8(((struct Obj02417 *)p)->f38) != 0) {
            ((struct Obj02417 *)p)->f54 = func_02027A04(*(u8 * *)&((struct Obj02417 *)p)->f38) + 1;
            ((struct Obj02417 *)p)->f56 = 3;
            func_02027858(((struct Obj02417 *)p)->f38);
        }
        break;
    }
}
