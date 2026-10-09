/*
 * file:     btl_server_p26.c
 * unit:     yes
 * function: func_021BF6E8, func_021BF78C, func_021BF83C
 * address:  0x021BF6E8
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
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 *   func_021C8828  0x021C8828  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   func_021C8810  0x021C8810  thumb  ov093
 *   func_021C88E4  0x021C88E4  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021CD64C  0x021CD64C  thumb  ov093
 *   func_021CC8C0  0x021CC8C0  thumb  ov093
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021BF894  0x021BF894  thumb  ov093
 *   func_021BF8A4  0x021BF8A4  thumb  ov093
 *   func_021BF8B4  0x021BF8B4  thumb  ov093
 *   func_021BF8C4  0x021BF8C4  thumb  ov093
 *   func_021BF324  0x021BF324  thumb  ov093
 *   func_021C6948  0x021C6948  thumb  ov093
 *   func_021C572C  0x021C572C  thumb  ov093
 */
#include "../../matched/include/Obj13316.h"
#include "../../matched/include/Obj13317.h"

struct Msg;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Bf { u8 pad[0x10]; u32 f : 1; };

extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern u32 func_021C8828(u8 *p);
extern int func_021C99A0(void *w, const struct Msg *m);
extern void func_021C8810(u8 *p);
extern int func_021C88E4(u8 *p);
extern u8 func_021D5440(u8 *p);
extern void func_021CD64C(void *w, u8 id, ...);
extern u32 func_021CC8C0(u32 *p, u32 i);
extern void func_021D74F8(int line);
extern void func_021D75EC(int key, u32 val);
extern void func_021D7630(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern void func_021BF894(int d);
extern u8 *func_021BF8A4(int d);
extern void func_021BF8B4(int d, u8 *x);
extern u8 *func_021BF8C4(int d);
extern int func_021BF324(u8 *p, u8 *a, u8 *b);
extern int func_021C6948(u8 *p, u8 *a, u8 *b, u32 v);
extern void func_021C572C(u8 *p, u8 *x, u32 v);
int func_021BF6E8(u8 *p, u8 *b, u8 *c2, u8 *d, void *s0, int s1);
int func_021BF78C(u8 *p, u8 *b, int c, u8 *d, u8 *e, void *f, void *g, int *h);
void func_021BF83C(u8 *p, u16 *b, u8 *c, int d);


int func_021BF6E8(u8 *p, u8 *b, u8 *c2, u8 *d, void *s0, int s1)
{
    u32 s;
    int flag;
    int r;
    s = func_021CC8D8(p + 0x1d74, 4784);
    flag = 0;
    r = func_021BF78C(p, b, s1, c2, d, s0, p + 0x1ae4, &flag);
    if (r != 0) {
        if (func_021C8828(p + 0x1ae4) != 0) {
            func_021C99A0(p, (const struct Msg *)(p + 0x1ae4));
            func_021C8810(p + 0x1ae4);
        } else if (func_021C88E4(p) == 0 && flag == 0) {
            func_021CD64C(((struct Obj13316 *)p)->fC, 0x5b, 0xd2, func_021D5440(d), 0xffff0000);
        }
    }
    func_021CC95C((u32 *)(p + 0x1d74), s, 4810);
    return r;
}



int func_021BF78C(u8 *p, u8 *b, int c, u8 *d, u8 *e, void *f, void *g, int *h)
{
    u32 t;
    int r;
    t = func_021CC8C0(f, func_021D5440(e));
    func_021C8810(g);
    func_021D74F8(4834);
    func_021D75EC(3, func_021D5440(d));
    func_021D75EC(4, func_021D5440(e));
    func_021D75EC(0x12, ((struct Obj13317 *)b)->f0);
    func_021D75EC(0x16, b[6]);
    func_021D75EC(0x4e, ((struct Bf *)b)->f);
    func_021D75EC(0x3f, (u32)g);
    func_021D75EC(0x38, t);
    func_021D7630(0x40, 0);
    func_021D7630(0x51, 0);
    func_021D70F0(p, c);
    r = func_021D775C(0x40);
    *h = func_021D775C(0x51);
    func_021D7540(4847);
    return r;
}



void func_021BF83C(u8 *p, u16 *b, u8 *c, int d)
{
    u8 *x;
    func_021BF894(d);
    x = func_021BF8A4(d);
    while (x != 0) {
        if (func_021BF324(p, c, x) == 0) {
            if (func_021C6948(p, c, x, *b) != 0) {
                func_021BF8B4(d, x);
                func_021C572C(p, x, *b);
            }
        }
        x = func_021BF8C4(d);
    }
}
