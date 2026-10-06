/*
 * function: func_021B7CB4
 * address: 0x021B7CB4
 * packet: pkt_ov093_021B7CB4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6818 0x021B6818 thumb ov093
 *   func_021D4270 0x021D4270 thumb ov093
 *   func_021BA9C8 0x021BA9C8 thumb ov093
 *   func_021CD6F0 0x021CD6F0 thumb ov093
 *   func_021CD978 0x021CD978 thumb ov093
 *   func_021BAA94 0x021BAA94 thumb ov093
 *   func_021BAACC 0x021BAACC thumb ov093
 *   func_021B8B9C 0x021B8B9C thumb ov093
 *   func_021BAB10 0x021BAB10 thumb ov093
 *   func_021CD960 0x021CD960 thumb ov093
 */
#include "../include/Obj01232.h"
#include "../include/Obj05182.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 pad[0x473]; u8 a:1; u8 b:1; } B;
struct Copy24;
extern unsigned int func_021B6818(unsigned int *p);
extern int func_021D4270(void);
struct Copy24;
struct QB;
extern u8 *func_021BA9C8(void *a, struct Copy24 *b, void *c, int d, u16 heap);
extern u8 *func_021CD6F0(u8 *a, u8 *b, int c, int d, u16 idx, u16 kind, u8 e, int f, int g, struct Copy24 *h, u16 heap);
extern u32 func_021CD978(struct QB *p);
extern void func_021BAA94(char *p, int b, u8 c, u8 d);
extern void func_021BAACC(char *p, int a, int b, int c, u8 d);
extern int func_021B8B9C(u8 *, u8);
extern void func_021BAB10(char *p, u8 c, u8 d);
extern void func_021CD960(u8 *p, u32 v);
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
