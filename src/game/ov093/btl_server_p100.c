/*
 * file:     btl_server_p100.c
 * unit:     yes
 * function: func_021C8D0C, func_021C8D2C
 * address:  0x021C8D0C
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
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021C5A34 0x021C5A34 thumb ov093
 *   func_021C3370  0x021C3370  thumb  ov093
 *   func_021C3394  0x021C3394  thumb  ov093
 *   func_021C33E8  0x021C33E8  thumb  ov093
 *   func_021C5A1C  0x021C5A1C  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   func_021CD64C  0x021CD64C  thumb  ov093
 */
#include "../../matched/include/Obj00003.h"

struct Msg;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { u32 pad : 8; u32 idx : 5; u32 rest : 19; } Ent_021C8D0C;

typedef unsigned short u16;

typedef struct {
    u32 pad : 8; u32 idx : 5; u32 mid : 10; u32 fl : 1; u32 top : 8;
    u16 h4; u8 b6; u8 b7; u16 h8; u16 ha;
} Ent_021C8D2C;

extern u8 *func_021B9934(char *p, int i);
extern void func_021C5A34(u8 *p, u8 *a);
extern int func_021C3370(u8 *p, void *q);
extern int func_021C3394(u8 *p, u8 *q, int r);
extern void func_021C33E8(int a, int b, int c);
extern void func_021C5A1C(u8 *p, u8 *a);
extern int func_021C99A0(void *w, const struct Msg *m);
extern void func_021CD64C(void *w, u8 id, ...);
int func_021C8D0C(u8 *p, Ent_021C8D0C *e);
u8 func_021C8D2C(int p, const Ent_021C8D2C *e, int c);

/*
 * note: caller narrows index to u8 before func_021B9934.
 */
int func_021C8D0C(u8 *p, Ent_021C8D0C *e)
{
    func_021C5A34(p, func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, (u8)e->idx));
    return 1;
}


u8 func_021C8D2C(int p, const Ent_021C8D2C *e, int c)
{
    u8 r = 0;
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, (u8)e->idx);
    int b = (int)func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, e->b6);

    if (func_021C3370((u8 *)p, (void *)b) == 0) {
        if (e->fl)
            func_021C5A1C((u8 *)p, a);
        if (e->b7 == 0) {
            r = !func_021C3394((u8 *)p, (u8 *)b, 1);
        } else {
            r = 1;
        }
        if (r) {
            func_021C33E8(p, b, e->h4);
            if ((u8)e->ha)
                func_021C99A0((void *)p, (void *)&e->h8);
            else if (c)
                func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x38c, e->b6, c, 0xffff0000);
        }
        if (e->fl)
            func_021C5A34((u8 *)p, a);
    }
    return r;
}
