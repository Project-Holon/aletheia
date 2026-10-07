/*
 * file:     btl_server_p120.c
 * unit:     yes
 * function: func_021CC508, func_021CC558
 * address:  0x021CC508
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
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021C84D0  0x021C84D0  thumb  ov093
 *   func_021C8910  0x021C8910  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021E869C  0x021E869C  thumb  ov093
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 */
#include "../../matched/include/Obj13347.h"

struct QI;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D59B4(u8 *p, int k);
extern u32 func_021CC8D8(void *lock, int line);
extern void func_021C84D0(u8 *p, u8 *a);
extern int func_021C8910(u8 *p);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern u8 func_021D5440(u8 *p);
extern int func_021E869C(void *p, int id);
extern u16 func_021D5B40(struct QI *p);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
int func_021CC508(char *p, void *m);
int func_021CC558(char *p, void *m);


int func_021CC508(char *p, void *m)
{
    u32 s;
    int r;

    if (func_021D59B4(m, 16) != 150) {
        s = func_021CC8D8(p + 0x1d74, 1921);
        func_021C84D0((u8 *)p, m);
        r = func_021C8910((u8 *)p);
        func_021CC95C((u32 *)(p + 0x1d74), s, 1926);
        if (r == 2)
            return 1;
    }
    return 0;
}


int func_021CC558(char *p, void *m)
{
    u32 s;
    int id;
    u32 t;
    char *q;

    if (func_021E869C(p, func_021D5440(m)) == 0) {
        t = (u16)(u32)func_021D5B40(m);
        if (t != 0) {
            s = func_021CC8D8(p + 0x1d74, 1944);
            id = func_021D5440(m);
            q = (char *)func_021C88A4(p, 32, id);
            q[6] = id;
            ((struct Obj13347 *)q)->f4 = 0;
            func_021C8838(q + 12, 2, 225);
            func_021C8860((struct S *)(q + 12), id);
            func_021C8860((struct S *)(q + 12), t);
            func_021C88C8(p, q);
            func_021CC95C((u32 *)(p + 0x1d74), s, 1957);
            return 1;
        }
    }
    return 0;
}
