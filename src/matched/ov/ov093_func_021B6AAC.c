/*
 * function: func_021B6AAC
 * address: 0x021B6AAC
 * packet: pkt_ov093_021B6AAC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
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
#include "../include/Obj00661.h"
#include "../include/Obj01230.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Copy24;
extern unsigned int func_021B6818(unsigned int *p);
struct T;
extern void func_021B6848(u8 *, struct T *);
extern void func_021B93E0(char *, u32, u32);
extern void func_021B9460(char *a, char *b, u8 c);
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
int func_021B6AAC(int unused, u8 *p)
{
    u8 *q;
    int t;
    q = *(u8 * *)&((struct Obj01230 *)p)->f0;
    t = func_021B6818((unsigned int *)q);
    p[0x46b] = 2;
    p[0x428] = 0;
    p[0x429] = 1;
    func_021B6848(p, (struct T *)q);
    func_021B93E0((char *)p + 0xc8, (u32)p, 0);
    func_021B9460((char *)(p + 0xc8), (char *)p, 0);
    func_021B9460((char *)(p + 0xc8), (char *)p, 1);
    func_021B93E0((char *)p + 0x1b0, (u32)p, 1);
    func_021B9460((char *)(p + 0x1b0), (char *)p, 0);
    func_021B9460((char *)(p + 0x1b0), (char *)p, 1);
    ((struct Obj01230 *)p)->f8 = (int)func_021BA9C8(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, ((struct Obj01230 *)p)->f468);
    p[0x46e] = 1;
    func_021B69FC((int)p, (char *)q);
    ((struct Obj01230 *)p)->f10 = (int)func_021CD6F0(p, p + 0xc8, 0, ((struct Obj00661 *)q)->f1C, 0, 1, 0, t, q[0x23], (struct Copy24 *)(p + 0x3f0), ((struct Obj01230 *)p)->f468);
    ((struct Obj01230 *)p)->f14 = (int)func_021CD6F0(p, p + 0xc8, 0, ((struct Obj00661 *)q)->f1C, 1, 1, 1, t, q[0x23], (struct Copy24 *)(p + 0x3f0), ((struct Obj01230 *)p)->f468);
    func_021B6A3C(p, q);
    func_021B6A70(p, q, t);
    func_021BAA94((char *)(((struct Obj01230 *)p)->f8), func_021CD978((struct QB *)(((struct Obj01230 *)p)->f10)), 0, 1);
    func_021BAA94((char *)(((struct Obj01230 *)p)->f8), func_021CD978((struct QB *)(((struct Obj01230 *)p)->f14)), 1, 1);
    func_021BAB40((char *)(((struct Obj01230 *)p)->f8));
    ((struct Obj01230 *)p)->f464 = (u32)func_021B83F4;
    return 1;
}
