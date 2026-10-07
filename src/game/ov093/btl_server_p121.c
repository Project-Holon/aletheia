/*
 * file:     btl_server_p121.c
 * unit:     yes
 * function: func_021CC5F4, func_021CC668
 * address:  0x021CC5F4
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
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 *   func_021B8B9C 0x021B8B9C thumb ov093
 *   func_021B9AEC 0x021B9AEC thumb ov093
 *   func_021B9B94 0x021B9B94 thumb ov093
 *   func_021B9B98 0x021B9B98 thumb ov093
 *   func_021B8BC4 0x021B8BC4 thumb ov093
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021BA534 0x021BA534 thumb ov093
 *   func_021CC758 0x021CC758 thumb ov093
 *   func_021B9A40 0x021B9A40 thumb ov093
 *   func_021CC768 0x021CC768 thumb ov093
 */
#include "../../matched/include/Obj05196.h"

struct S;
struct Q1;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern u32 func_021CC8D8(void *lock, int line);
extern u8 func_021D5440(u8 *p);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern int func_021B8B9C(unsigned char *p, unsigned char k);
extern char *func_021B9AEC(char *,int);
extern u8 func_021B9B94(struct Q1 *p);
extern u8 func_021B9B98(u8 *p);
extern unsigned char func_021B8BC4(int unused, unsigned int b);
extern u8 func_021B8FF4(u8 *p);
extern int func_021BA534(void ***p);
extern int func_021CC758(void *);
extern unsigned char func_021B9A40(unsigned int x);
extern int func_021CC768(void *,u8 *,u8 *,int);
int func_021CC5F4(char *p, void *m);
int func_021CC668(u8 *p);


int func_021CC5F4(char *p, void *m)
{
    u32 s;
    int id;
    u8 *r;
    char *q;

    s = func_021CC8D8(p + 0x1d74, 1968);
    id = func_021D5440(m);
    r = (u8 *)func_021C88A4(p, 16, id);
    r[4] = 1;
    r[5] = id;
    func_021C88C8(p, r);
    q = (char *)func_021C88A4(p, 4, id);
    func_021C8838(q + 4, 2, 228);
    func_021C8860((struct S *)(q + 4), id);
    func_021C88C8(p, q);
    func_021CC95C((u32 *)(p + 0x1d74), s, 1984);
    return 1;
}

int func_021CC668(u8 *p)
{
    u8 live[2];
    u8 counts[2];
    u32 i;
    char *list;
    u8 side;
    u8 other;
    int k;
    live[0] = live[1] = 0;
    counts[0] = counts[1] = 0;
    for (i = 0; i < 4; i++) {
        if (func_021B8B9C(((struct Obj05196 *)p)->f4, i)) {
            list = func_021B9AEC(*(char * *)&((struct Obj05196 *)p)->f8,i);
            if (func_021B9B94((struct Q1 *)list)) {
                side = func_021B8BC4((int)(((struct Obj05196 *)p)->f4),(u8)i);
                live[side] += func_021B9B98((u8 *)list);
                counts[side] += func_021B9B94((struct Q1 *)list);
            }
        }
    }
    side = func_021B8BC4((int)(((struct Obj05196 *)p)->f4),(u8)func_021B8FF4(((struct Obj05196 *)p)->f4));
    other = side ^ 1;
    if (live[side] == 0 && live[other] != 0) return 0;
    if (live[other] == 0 && live[side] != 0) return 1;
    if (!func_021BA534(((struct Obj05196 *)p)->f4)) return 2;
    if (live[0] == 0) {
        k = func_021CC758(p+0x3e0);
        if (k != 31) {
            k = func_021B9A40(k);
            if (k == side) return 1;
            return 0;
        }
        return 2;
    }
    return func_021CC768(p, live, counts, side);
}
