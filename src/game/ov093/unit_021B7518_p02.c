/*
 * file:     unit_021B7518_p02.c
 * unit:     yes
 * function: func_021B7BB0, func_021B7CB4
 * address:  0x021B7BB0
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
 *   func_021D4270 0x021D4270 thumb ov093
 *   func_021D4500 0x021D4500 thumb ov093
 *   func_021D4AF4 0x021D4AF4 thumb ov093
 *   func_021D4B18 0x021D4B18 thumb ov093
 *   func_021D450C 0x021D450C thumb ov093
 *   func_021D45FC 0x021D45FC thumb ov093
 *   func_021D4648 0x021D4648 thumb ov093
 *   func_021D4674 0x021D4674 thumb ov093
 *   func_021B8B9C 0x021B8B9C thumb ov093
 *   func_021B9F70 0x021B9F70 thumb ov093
 *   func_021BA698 0x021BA698 thumb ov093
 *   func_02012EBC 0x02012EBC thumb
 *   func_02007B44 0x02007B44 thumb
 *   func_02007B20 0x02007B20 thumb
 *   func_02007B00 0x02007B00 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_021B6818 0x021B6818 thumb ov093
 *   func_021BA9C8 0x021BA9C8 thumb ov093
 *   func_021CD6F0 0x021CD6F0 thumb ov093
 *   func_021CD978 0x021CD978 thumb ov093
 *   func_021BAA94 0x021BAA94 thumb ov093
 *   func_021BAACC 0x021BAACC thumb ov093
 *   func_021BAB10 0x021BAB10 thumb ov093
 *   func_021CD960 0x021CD960 thumb ov093
 */
#include "../../matched/include/Obj07743.h"
#include "../../matched/include/Obj20949.h"
#include "../../matched/include/Obj01232.h"
#include "../../matched/include/Obj05182.h"

struct Sub02007AC8Entry;
struct Big;
struct Copy24;
struct QB;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u8 pad[0x473]; u8 a:1; u8 b:1; } B;

extern int func_021D4270(void);
extern void func_021D4500(void);
extern void func_021D4AF4(int);
extern int func_021D4B18(int);
extern u32 func_021D450C(u32 *);
extern int func_021D45FC(void);
extern u32 func_021D4648(u32 a);
extern void func_021D4674(void);
extern int func_021B8B9C(unsigned char *p, unsigned char k);
extern int func_021B9F70(u8 *p, int i);
extern void func_021BA698(u8 *p, int k);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02007AC8Entry *func_02007B44(void *sys);
extern void *func_02007B20(u32 heap);
extern u32 func_02007B00(void);
extern void func_02082D44(const void *,void *,u32);
extern unsigned int func_021B6818(unsigned int *p);
extern u8 *func_021BA9C8(void *a, struct Copy24 *b, void *c, int d, u16 heap);
extern u8 *func_021CD6F0(u8 *a, u8 *b, int c, int d, u16 idx, u16 kind, u8 e, int f, int g, struct Copy24 *h, u16 heap);
extern u32 func_021CD978(struct QB *p);
extern void func_021BAA94(char *p, int b, u8 c, u8 d);
extern void func_021BAACC(char *p, int a, int b, int c, u8 d);
extern void func_021BAB10(char *p, u8 c, u8 d);
extern void func_021CD960(u8 *p, u32 v);
int func_021B7BB0(u8 *p,u32 *state);
int func_021B7CB4(u8 *p);

int func_021B7BB0(u8 *p,u32 *state)
{
    u8 *q;
    u32 i;
    void *src;
    q = *(u8 * *)&((struct Obj07743 *)p)->f0;
    if (func_021D4270()) {
        ((B *)p)->a = 1;
        return 1;
    }
    switch (*state) {
    case 0:
        func_021D4500();
        func_021D4AF4(3);
        ++*state;
        break;
    case 1:
        if (func_021D4B18(3)) ++*state;
        break;
    case 2:
        if (func_021D450C((u32 *)func_02007B44(func_02012EBC(((struct Obj20949 *)q)->f58)))) ++*state;
        break;
    case 3:
        if (func_021D45FC()) {
            for (i = 0; i < 4; ++i) {
                if (func_021B8B9C(p,i) && !func_021B9F70(p,(u8)i)) {
                    src = (void *)func_021D4648((u8)i);
                    if (src) {
                        *(void **)(p + i * 4 + 0x3e0) = func_02007B20(((struct Obj07743 *)p)->f468);
                        func_02082D44(src, *(void **)(p + i * 4 + 0x3e0),func_02007B00());
                    }
                }
                func_021BA698(p,(u8)i);
            }
            func_021D4674();
            ++*state;
        }
        break;
    default:
        return 1;
    }
    return 0;
}

int func_021B7CB4(u8 *p)
{
    u8 *q;
    u8 idx;
    int t;
    u32 i, flag;
    q = *(u8 * *)&((struct Obj01232 *)p)->f0;
    idx = p[0x46c];
    t = (int)func_021B6818((unsigned int *)q);
    if (func_021D4270()) {
        ((B *)p)->a = 1;
        return 1;
    }
    if (p[0x46e]) {
        ((struct Obj01232 *)p)->f8 = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, ((struct Obj01232 *)p)->f468);
        ((int *)(p + 0x10))[idx] = (int)func_021CD6F0(p, p + 0xc8, q[0x20], ((struct Obj05182 *)q)->f1C, idx, (u8)1, 0, t, (u8)0, (struct Copy24 *)(p + 0x3f0), ((struct Obj01232 *)p)->f468);
        func_021BAA94((char *)(((struct Obj01232 *)p)->f8), func_021CD978((struct QB *)(((int *)(p + 0x10))[idx])), idx, 1);
        flag = 1;
        if (idx != 0) flag = 0;
        func_021BAACC((char *)(((struct Obj01232 *)p)->f8), q[0x20], ((struct Obj05182 *)q)->f1C, (u8)flag, 1);
    } else {
        ((int *)(p + 0x10))[idx] = (int)func_021CD6F0(p, p + 0xc8, q[0x20], ((struct Obj05182 *)q)->f1C, idx, (u8)1, 0, t, (u8)0, (struct Copy24 *)(p + 0x3f0), ((struct Obj01232 *)p)->f468);
        ((struct Obj01232 *)p)->fC = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, ((struct Obj01232 *)p)->f468);
        for (i = 0; i < 4; i++) {
            if (func_021B8B9C(p, i))
                func_021BAB10((char *)(((struct Obj01232 *)p)->fC), i, 1);
        }
        func_021CD960((u8 *)(((int *)(p + 0x10))[idx]), (int)(((struct Obj01232 *)p)->fC));
    }
    return 1;
}
