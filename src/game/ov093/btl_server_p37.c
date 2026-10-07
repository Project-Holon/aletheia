/*
 * file:     btl_server_p37.c
 * unit:     yes
 * function: func_021BF78C, func_021BF83C
 * address:  0x021BF78C
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
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021CC8C0  0x021CC8C0  thumb  ov093
 *   func_021C8810  0x021C8810  thumb  ov093
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
#include "../../matched/include/Obj13317.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Bf { u8 pad[0x10]; u32 f : 1; };

extern u8 func_021D5440(u8 *p);
extern u32 func_021CC8C0(u32 *p, u32 i);
extern void func_021C8810(u8 *p);
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
int func_021BF78C(u8 *p, u8 *b, int c, u8 *d, u8 *e, void *f, void *g, int *h);
void func_021BF83C(u8 *p, u16 *b, u8 *c, int d);


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
