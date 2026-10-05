/*
 * function: func_021BE3D4
 * address: 0x021BE3D4
 * packet: pkt_ov210_021BE3D4
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: each int offset is assigned 0x1DC, then its final literal;
 *        spilled locals retain both stores without a reload.
 * note 2026-10-05 (wave D9r lane 131): removed the 4 dead first assignments
 * (`release = 0x1dc;` before `release = 0x14c;`; `clear = 0x1dc;` before
 * `clear = 0x150;` and 2 more). Game code has no line table, so these were
 * stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 *
 * symbols:
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 */
#include "../include/Obj08413.h"
typedef unsigned char u8;
struct PrintSys;
struct Descriptor;
extern unsigned func_0201C4E4(struct PrintSys *);
extern void *func_02045770(struct Descriptor *);
extern unsigned func_0201C6C4(struct PrintSys *, void *);
extern void func_02045334(struct Descriptor *);
void func_021BE3D4(u8 *p)
{
    int release, clear, get, flag;
    unsigned i;
    func_0201C4E4(*(struct PrintSys * *)&((struct Obj08413 *)p)->f1DC);
    release = 0x14c;
    clear = 0x150;
    get = 0x14c;
    flag = 0x150;
    for (i = 0; i < 16; i++) {
        struct PrintSys *ps = *(struct PrintSys * *)&((struct Obj08413 *)p)->f1DC;
        u8 *record = p + i * 8;
        if (record[flag] != 0 && func_0201C6C4(ps, func_02045770(*(struct Descriptor **)(record + get))) == 0) {
            func_02045334(*(struct Descriptor **)(record + release));
            record[clear] = 0;
        }
    }
}
