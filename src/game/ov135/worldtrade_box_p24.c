/*
 * file:     worldtrade_box_p24.c
 * unit:     yes
 * function: func_021F86A8, func_021F875C
 * address:  0x021F86A8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   tbl_02203B84 0x02203B84 data a2
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   d_02202ED8 0x02202ED8 data a4
 */
#include "../../matched/include/Obj06512.h"

struct Blk37;
struct Slot;
struct CharBuf;
struct Descriptor;
struct Obj;
struct Src;
typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned char u8;

typedef struct { u8 pad[0xEF0]; u16 a[10]; u16 b[10]; } Work;

typedef struct { u32 w[4]; u16 count, rows; u32 rest[8]; } Menu;

extern u32 func_0200D064(struct Blk37 *p, u16 id);
extern void *func_0201F81C(u32 n, u32 heap);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201F73C(void *win, int a, int b, int c);
extern struct Obj *func_0201FF30(struct Src *src, u16 a, u16 b, u32 heap);
int func_021F86A8(void **menu, void *msg, void *endmsg, u16 *list, u32 unused4, u32 unused5, u32 kind, void *bag);
void *func_021F875C(Work *p, void **menu, void *win, void *endmsg, void *msg, u8 *cfg, void *bag);
extern const u16 tbl_02203B84[];
extern const Menu d_02202ED8;

int func_021F86A8(void **menu, void *msg, void *endmsg, u16 *list, u32 unused4, u32 unused5, u32 kind, void *bag)
{
    int i;
    int size;
    int count;
    int start;
    count = 0;
    start = tbl_02203B84[kind];
    size = tbl_02203B84[kind + 1] - start;
    for (i = 0; i < size; i++) {
        if (func_0200D064(bag, list[start + i]) != 0) count++;
    }
    *menu = func_0201F81C(count + 1, 0x48);
    for (i = 0; i < size; i++) {
        if (func_0200D064(bag, list[start + i]) != 0) {
            func_0201F878(*menu, (u32)msg, list[start + i], list[start + i], 0x48);
        }
    }
    func_0201F878(*menu, (u32)endmsg, 0x85, -2, 0x48);
    return count + 1;
}

/*
 * lever: u16 arrays at 0xEF0 and 0xF04 preserve base/index load scheduling; raw offset casts differ by 8 bytes.
 */
void *func_021F875C(Work *p, void **menu, void *win, void *endmsg, void *msg, u8 *cfg, void *bag)
{
    int kind;
    int count;
    Menu src;
    func_02043B5C(func_02045770(win), 15);
    kind = ((struct Obj06512 *)cfg)->f6 + ((struct Obj06512 *)cfg)->f4;
    count = func_021F86A8(menu, msg, endmsg, *(u16 * *)&((struct Obj06512 *)cfg)->f18, ((struct Obj06512 *)cfg)->f14, ((struct Obj06512 *)cfg)->f1C, kind, bag);
    src = d_02202ED8;
    src.count = count;
    src.w[0] = (u32)*menu;
    src.w[3] = (u32)win;
    func_0201F73C(win, 0, 31, 11);
    return func_0201FF30((struct Src *)(&src), p->a[kind], p->b[kind], 0x48);
}
