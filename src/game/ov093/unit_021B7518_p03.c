/*
 * file:     unit_021B7518_p03.c
 * unit:     yes
 * function: func_021B8070, func_021B81DC
 * address:  0x021B8070
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
 *   func_021B6818 0x021B6818 thumb ov093
 *   func_021D4270 0x021D4270 thumb ov093
 *   func_021BA9C8 0x021BA9C8 thumb ov093
 *   func_021CD6F0 0x021CD6F0 thumb ov093
 *   func_021CD978 0x021CD978 thumb ov093
 *   func_021BAA94 0x021BAA94 thumb ov093
 *   func_021BAACC 0x021BAACC thumb ov093
 *   func_021B8B9C 0x021B8B9C thumb ov093
 *   func_021B6994 0x021B6994 thumb ov093
 *   func_021BAB10 0x021BAB10 thumb ov093
 *   func_021CD960 0x021CD960 thumb ov093
 */
#include "../../matched/include/Obj01233.h"
#include "../../matched/include/Obj05183.h"
#include "../../matched/include/Obj01134.h"
#include "../../matched/include/Obj05184.h"

struct Copy24;
struct S;
struct QB;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u8 pad[0x473]; u8 a:1; u8 b:1; } B;

extern unsigned int func_021B6818(unsigned int *p);
extern int func_021D4270(void);
extern u8 *func_021BA9C8(void *a, struct Copy24 *b, void *c, int d, u16 heap);
extern u8 *func_021CD6F0(u8 *a, u8 *b, int c, int d, u16 idx, u16 kind, u8 e, int f, int g, struct Copy24 *h, u16 heap);
extern u32 func_021CD978(struct QB *p);
extern void func_021BAA94(char *p, int b, u8 c, u8 d);
extern void func_021BAACC(char *p, int a, int b, int c, u8 d);
extern int func_021B8B9C(u8 *, u8);
extern int func_021B6994(struct S **pp, u32 b);
extern void func_021BAB10(int, u8, int);
extern void func_021CD960(u8 *p, u32 v);
int func_021B8070(u8 *p);
int func_021B81DC(u8 *p);

int func_021B8070(u8 *p)
{
    u8 *q;
    u8 idx;
    int t;
    u32 i, flag;
    q = *(u8 * *)&((struct Obj01233 *)p)->f0;
    idx = p[0x46c];
    t = (int)func_021B6818((unsigned int *)q);
    if (func_021D4270()) {
        ((B *)p)->a = 1;
        return 1;
    }
    if (p[0x46e]) {
        ((struct Obj01233 *)p)->f8 = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, ((struct Obj01233 *)p)->f468);
        ((int *)(p + 0x10))[idx] = (int)func_021CD6F0(p, p + 0xc8, q[0x20], ((struct Obj05183 *)q)->f1C, idx, (u8)3, 0, t, (u8)0, (struct Copy24 *)(p + 0x3f0), ((struct Obj01233 *)p)->f468);
        func_021BAA94((char *)(((struct Obj01233 *)p)->f8), func_021CD978((struct QB *)(((int *)(p + 0x10))[idx])), idx, 3);
        flag = 0;
        if (idx == 0) flag = 1;
        func_021BAACC((char *)(((struct Obj01233 *)p)->f8), q[0x20], ((struct Obj05183 *)q)->f1C, (u8)flag, 3);
    } else {
        ((int *)(p + 0x10))[idx] = (int)func_021CD6F0(p, p + 0xc8, q[0x20], ((struct Obj05183 *)q)->f1C, idx, (u8)3, 0, t, (u8)0, (struct Copy24 *)(p + 0x3f0), ((struct Obj01233 *)p)->f468);
        ((struct Obj01233 *)p)->fC = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, ((struct Obj01233 *)p)->f468);
        for (i = 0; i < 4; i++) {
            if (func_021B8B9C(p, i))
                func_021BAB10(((struct Obj01233 *)p)->fC, i, func_021B6994((struct S **)p, (u8)i));
        }
        func_021CD960((u8 *)(((int *)(p + 0x10))[idx]), (int)(((struct Obj01233 *)p)->fC));
    }
    return 1;
}

int func_021B81DC(u8 *p)
{
    u8 idx;
    u8 *q;
    int t;
    u32 i;
    idx = p[0x46c];
    q = *(u8 * *)&((struct Obj01134 *)p)->f0;
    t = (int)func_021B6818((unsigned int *)q);
    if (func_021D4270()) {
        ((B *)p)->a = 1;
        return 1;
    }
    if (p[0x46e]) {
        ((struct Obj01134 *)p)->f8 = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, ((struct Obj01134 *)p)->f468);
        ((int *)(p + 0x10))[idx] = (int)func_021CD6F0(p, p + 0xc8, q[0x20], ((struct Obj05184 *)q)->f1C, idx, (u8)1, 0, t, (u8)0, (struct Copy24 *)(p + 0x3f0), ((struct Obj01134 *)p)->f468);
        func_021BAA94((char *)(((struct Obj01134 *)p)->f8), func_021CD978((struct QB *)(((int *)(p + 0x10))[idx])), idx, 1);
        for (i = 0; i < p[0x46b]; i++) {
            if (i != idx)
                func_021BAACC((char *)(((struct Obj01134 *)p)->f8), q[0x20], ((struct Obj05184 *)q)->f1C, (u8)i, 1);
        }
    } else {
        ((int *)(p + 0x10))[idx] = (int)func_021CD6F0(p, p + 0xc8, q[0x20], ((struct Obj05184 *)q)->f1C, idx, (u8)1, 0, t, (u8)0, (struct Copy24 *)(p + 0x3f0), ((struct Obj01134 *)p)->f468);
        ((struct Obj01134 *)p)->fC = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, ((struct Obj01134 *)p)->f468);
        for (i = 0; i < 4; i++) {
            if (func_021B8B9C(p, i))
                func_021BAB10(((struct Obj01134 *)p)->fC, i, func_021B6994((struct S **)p, (u8)i));
        }
        func_021CD960((u8 *)(((int *)(p + 0x10))[idx]), (int)(((struct Obj01134 *)p)->fC));
    }
    return 1;
}
