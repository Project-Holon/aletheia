/*
 * file:     btl_server_p106.c
 * unit:     yes
 * function: func_021CA158, func_021CA1D0
 * address:  0x021CA158
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021BC2B0  0x021BC2B0  thumb  ov093
 *   func_021C8374  0x021C8374  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   func_021BDD00  0x021BDD00  thumb  ov093
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021BB930  0x021BB930  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021C2CA8  0x021C2CA8  thumb  ov093
 *   func_021D65C8  0x021D65C8  thumb  ov093
 *   func_021D6D7C  0x021D6D7C  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021CA238  0x021CA238  thumb  ov093
 */
#include "../../matched/include/Obj00003.h"

struct Msg;
struct Unk021D62A8;
struct Work;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Cmd_021CA158 {
    u8 pad[0x4C];
    u8 b4c;
    u8 b4d;
};

struct Cmd_021CA1D0 {
    u32 pad;
    u8 b4;
    u8 b5;
};

extern u8 *func_021B9934(char *p, int i);
extern int func_021BC2B0(u8 *p);
extern int func_021C8374(u8 *p, int i);
extern int func_021C99A0(void *w, const struct Msg *m);
extern int func_021BDD00(u8 *p, u8 *a, int c);
extern int func_021B8D8C(void *p, void *a, u32 b);
extern void func_021BB930(u8 *p, u32 value);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern void func_021C2CA8(u8 *p, u8 *a);
extern void func_021D65C8(struct Work *p, struct Work *q);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern u32 func_021D6D7C(u8 *p);
extern int func_021CA238(void *p, u8 i);
int func_021CA158(u8 *w, struct Cmd_021CA158 *c);
int func_021CA1D0(u8 *w, const struct Cmd_021CA1D0 *c);


int func_021CA158(u8 *w, struct Cmd_021CA158 *c)
{
    u8 *r = func_021B9934(*(char * *)&((struct Obj00003 *)w)->f8, c->b4c);
    if (func_021BC2B0(w) == 0 && func_021C8374(w, c->b4c) == 0 && ((struct Obj00003 *)w)->f14 == 0) {
        func_021C99A0(w, (const struct Msg *)((u8 *)c + 4));
        if (func_021BDD00(w, r, c->b4d) != 0) {
            func_021BB930(((struct Obj00003 *)w)->f0, func_021B8D8C(((struct Obj00003 *)w)->f4, ((struct Obj00003 *)w)->f8, c->b4c));
            func_021C99A0(w, (const struct Msg *)((u8 *)c + 0x28));
            ((struct Obj00003 *)w)->f14 = 1;
            return 1;
        }
    }
    return 0;
}


int func_021CA1D0(u8 *w, const struct Cmd_021CA1D0 *c)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)w)->f8, c->b4);
    u8 *b = func_021B9934(*(char * *)&((struct Obj00003 *)w)->f8, c->b5);
    if (func_021D62C4((struct Unk021D62A8 *)a, 0x10) != 0) func_021C2CA8(w, b);
    func_021D65C8((struct Work *)b, (struct Work *)a);
    func_021CD4B0(((struct Obj00003 *)w)->fC, 0x26, c->b4, c->b5);
    if (func_021D6D7C(b) != 0) {
        int r = func_021CA238(w + 0x1AB8, c->b5);
        func_021CD4B0(((struct Obj00003 *)w)->fC, 0x51, r);
    }
    return 1;
}
