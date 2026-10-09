/*
 * file:     btl_server_p96.c
 * unit:     yes
 * function: func_021C96D4, func_021C9728, func_021C9750, func_021C9778, func_021C97A4, func_021C97D0
 * address:  0x021C96D4
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
 *   func_021C5A1C  0x021C5A1C  thumb  ov093
 *   func_021C5A34  0x021C5A34  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021D5FC0 0x021D5FC0 thumb ov093
 *   func_021D6440 0x021D6440 thumb ov093
 *   func_021C60EC 0x021C60EC thumb ov093
 *   func_021C6110 0x021C6110 thumb ov093
 *   func_021C7BA8  0x021C7BA8  thumb  ov093
 *   func_021C9818  0x021C9818  thumb  ov093
 */
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj09973.h"

struct Msg;
struct UtilWork;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Cmd_021C96D4 {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 10;
    u32 flag : 1;
};

struct Cmd_021C97D0 {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 19;
    u32 w4;
    u32 w8;
    u8 b12;
};

extern u8 *func_021B9934(char *p, int i);
extern void func_021C5A1C(u8 *p, u8 *a);
extern void func_021C5A34(u8 *p, u8 *a);
extern int func_021C99A0(void *w, const struct Msg *m);
extern int func_021D5B68(void *);
extern void func_021D5FC0(struct UtilWork *, u32);
extern void func_021D6440(u8 *p, u32 n);
extern void func_021C60EC(u8 *, u8 *, u32);
extern void func_021C6110(u8 *, u8 *, u32);
extern void func_021C7BA8(u8 *p, u8 a, u32 b, u32 c, u32 *out);
extern int func_021C9818(u32 b, u32 a, u32 v);
int func_021C96D4(char *w, struct Cmd_021C96D4 *c);
int func_021C9728(u8 *p, u8 *q);
int func_021C9750(u8 *p, u8 *q);
int func_021C9778(u8 *p, u8 *q);
int func_021C97A4(u8 *p, u8 *q);
int func_021C97D0(void *w, const struct Cmd_021C97D0 *c);



int func_021C96D4(char *w, struct Cmd_021C96D4 *c)
{
    u8 *r = 0;
    int id = c->id;
    if (id != 0x1F) {
        r = func_021B9934(*(char * *)&((struct Obj00003 *)w)->f8, (u8)id);
    }
    if (c->flag && r) func_021C5A1C((u8 *)w, r);
    func_021C99A0(w, (const struct Msg *)((u8 *)c + 4));
    if (c->flag && r) func_021C5A34((u8 *)w, r);
    return 1;
}



/*
 * extent: two bytes of trailing alignment padding.
 */
int func_021C9728(u8 *p, u8 *q)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[8]);
    if (!func_021D5B68(a)) {
        func_021D5FC0((struct UtilWork *)a, *(u32 *)(q + 4));
        return 1;
    }
    return 0;
}



int func_021C9750(u8 *p, u8 *q)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[8]);
    if (!func_021D5B68(a)) {
        func_021D6440(a, *(u32 *)(q + 4));
        return 1;
    }
    return 0;
}



int func_021C9778(u8 *p, u8 *q)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[8]);
    if (!func_021D5B68(a)) {
        func_021C60EC(p, a, *(u32 *)(q + 4));
        return 1;
    }
    return 0;
}



int func_021C97A4(u8 *p, u8 *q)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[8]);
    if (!func_021D5B68(a)) {
        func_021C6110(p, a, *(u32 *)(q + 4));
        return 1;
    }
    return 0;
}


int func_021C97D0(void *w, const struct Cmd_021C97D0 *c)
{
    u32 v;
    void *pv;
    v = c->w8;
    pv = &v;
    func_021C7BA8(w, c->id, c->w4, c->b12, pv);
    if (func_021C9818(c->b12, c->w4, ((struct Obj09973 *)pv)->f0) != 0) {
        func_021C99A0(w, (const struct Msg *)((u8 *)c + 0x10));
        return 1;
    }
    return 0;
}
