/*
 * function: func_021B6DD0
 * address: 0x021B6DD0
 * packet: pkt_ov093_021B6DD0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the boolean passed narrow is an int local; t declared after desc puts t at sp+0x1c.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`desc = p;` before `desc = p + 0xc8;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 *
 * symbols:
 *   func_021B8B9C 0x021B8B9C thumb ov093
 *   func_021B8B78 0x021B8B78 thumb ov093
 *   func_021B9E38 0x021B9E38 thumb ov093
 *   func_021B9E7C 0x021B9E7C thumb ov093
 *   func_021B6954 0x021B6954 thumb ov093
 *   func_021EE644 0x021EE644 thumb ov093
 *   func_021CD938 0x021CD938 thumb ov093
 *   func_021B6818 0x021B6818 thumb ov093
 *   func_021B6848 0x021B6848 thumb ov093
 *   func_021B93E0 0x021B93E0 thumb ov093
 *   func_021B9460 0x021B9460 thumb ov093
 *   func_021BA9C8 0x021BA9C8 thumb ov093
 *   func_021B69FC 0x021B69FC thumb ov093
 *   func_021CD6F0 0x021CD6F0 thumb ov093
 *   func_021B6A3C 0x021B6A3C thumb ov093
 *   func_021B6A70 0x021B6A70 thumb ov093
 *   func_021CD978 0x021CD978 thumb ov093
 *   func_021BAA94 0x021BAA94 thumb ov093
 *   func_021BAB40 0x021BAB40 thumb ov093
 *   func_021B83F4 0x021B83F4 thumb ov093
 */
#include "../include/Obj00886.h"
#include "../include/Obj02772.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Copy24;
extern unsigned int func_021B6818(unsigned int *p);
struct T;
extern void func_021B6848(u8 *, struct T *);
extern void func_021B93E0(char *, u32, u32);
extern void func_021B9460(char *a, char *b, u8 c);
struct A;
struct B;
struct Copy24;
struct QB;
extern u8 *func_021BA9C8(void *a, struct Copy24 *b, void *c, int d, u16 heap);
extern void func_021B69FC(int, char *);
extern u8 *func_021CD6F0(u8 *a, u8 *b, int c, int d, u16 idx, u16 kind, u8 e, int f, int g, struct Copy24 *h, u16 heap);
extern void func_021B6A3C(unsigned char *p, unsigned char *q);
extern void func_021B6A70(unsigned char *p, unsigned char *q, int r);
extern u32 func_021CD978(struct QB *p);
extern void func_021BAA94(char *p, int b, u8 c, u8 d);
extern void func_021BAB40(char *p);
extern int func_021B83F4(int a);
extern int func_021B8B9C(unsigned char *p, unsigned char k);
extern unsigned int func_021B8B78(unsigned char *p, int k);
extern void func_021B9E38(char *p, int a, int b);
extern void func_021B9E7C(struct A *p, struct B *src);
extern void func_021B6954(int a, int b);
extern void func_021EE644(void *, int, int);
extern void func_021CD938(u8 *p, void *a);
int func_021B6DD0(int unused, u8 *p)
{
    u8 *q;
    int i;
    u8 k;
    int b;
    u8 *desc;
    u8 *table;
    int t;
    q = *(u8 * *)&((struct Obj00886 *)p)->f0;
    t = (int)func_021B6818((unsigned int *)q);
    p[0x46c] = 0;
    p[0x46b] = 2;
    p[0x428] = 0;
    p[0x42a] = 0;
    p[0x429] = 1;
    p[0x42b] = 1;
    switch (q[0x22]) {
    case 0: break;
    case 1: case 2: case 3:
        p[0x42a] = 2;
        p[0x42b] = 3;
        p[0x46b] = 4;
        break;
    case 4:
        p[0x42b] = 3;
        p[0x46b] = 3;
        break;
    }
    func_021B6848(p, (struct T *)q);
    func_021B93E0((char *)p + 0xc8, (u32)p, 0);
    func_021B93E0((char *)p + 0x1b0, (u32)p, 1);
    for (i = 0; i < 4; i++) {
        if (func_021B8B9C(p, i)) {
            func_021B9460((char *)(p + 0xc8), (char *)p, i);
            func_021B9460((char *)(p + 0x1b0), (char *)p, i);
        }
    }
    if (!q[0x23]) {
        func_021B9E38((char *)((int)(p + 0x20)), ((struct Obj00886 *)p)->f468, ((struct Obj00886 *)p)->fC0);
        func_021B9E7C((struct A *)((int)(p + 0x48)), (struct B *)(((struct Obj02772 *)q)->f4C));
        if (func_021B8B9C(p, 2)) func_021B9E7C((struct A *)((int)(p + 0x70)), (struct B *)(((struct Obj02772 *)q)->f50));
        if (func_021B8B9C(p, 3)) func_021B9E7C((struct A *)((int)(p + 0x98)), (struct B *)(((struct Obj02772 *)q)->f54));
    } else {
        for (i = 0; i < 4; i++) {
            if (func_021B8B9C(p, i)) func_021B6954((int)p, (u8)i);
        }
    }
    ((struct Obj00886 *)p)->f8 = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, ((struct Obj00886 *)p)->f468);
    p[0x46e] = 1;
    table = p + 0x3f0;
    desc = p + 0xc8;
    for (i = 0; i < 4; i++) {
        if (func_021B8B9C(p, i)) {
            k = func_021B8B78(p, (unsigned char)i);
            b = 0;
            if (i != 0) b = 1;
            *(int *)(p + i * 4 + 0x10) = (int)func_021CD6F0(p, desc, 0, ((struct Obj02772 *)q)->f1C, i, (u8)k, b, t, (u8)q[0x23], (struct Copy24 *)table, ((struct Obj00886 *)p)->f468);
        }
    }
    if (q[0x23]) {
        func_021EE644(p + 0x2c8, ((struct Obj02772 *)q)->f94, ((struct Obj02772 *)q)->f98);
        for (i = 0; i < 4; i++) {
            if (func_021B8B9C(p, i)) func_021CD938((u8 *)(*(int *)(p + i * 4 + 0x10)), p + 0x2c8);
        }
    }
    func_021B6A70(p, q, t);
    for (i = 0; i < 4; i++) {
        if (func_021B8B9C(p, i)) {
            k = func_021B8B78(p, (unsigned char)i);
            func_021BAA94((char *)(((struct Obj00886 *)p)->f8), func_021CD978((struct QB *)(*(int *)(p + i * 4 + 0x10))), i, k);
        }
    }
    func_021BAB40((char *)(((struct Obj00886 *)p)->f8));
    ((struct Obj00886 *)p)->f464 = (u32)func_021B83F4;
    return 1;
}
