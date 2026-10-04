/*
 * function: func_021DDBF0
 * address:  0x021DDBF0
 * packet:   pkt_ov119_021DDBF0
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_021E12AC  0x021E12AC  thumb  ov119
 *   func_021DD140  0x021DD140  thumb  ov119
 *   func_021D8A24  0x021D8A24  thumb  ov119
 *   func_02039CB4  0x02039CB4  arm
 *   func_021DD24C  0x021DD24C  thumb  ov119
 *   func_021DD294  0x021DD294  thumb  ov119
 *   func_021DD080  0x021DD080  thumb  ov119
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021DA76C  0x021DA76C  thumb  ov119
 *   func_02045CAC  0x02045CAC  arm
 *   func_021E1024  0x021E1024  thumb  ov119
 *   func_021DDB90  0x021DDB90  thumb  ov119
 */
#include "../include/Obj00001.h"

typedef unsigned int u32;

struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern u32 func_0203D1A4(struct Link *p);
struct MsgBank;
extern int func_021E12AC(char *p);
extern int func_021DD140(char *p);
extern int func_021D8A24(void *p);
struct Link;
extern unsigned int func_02039CB4(struct Link *p, unsigned int lo, unsigned int hi);
extern int func_021DD24C(char *p);
extern void func_021DD294(char *p, int a, int b);
extern void func_021DD080(void *a, void *b, void *c);
extern void func_021D8E84(void *p, int next);
extern void func_021DA76C(void *p);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021E1024(void *p);
extern void func_021DDB90(unsigned char *p);

void func_021DDBF0(char *p)
{
    int a, b, c, d, m;
    a = func_0203D1A4((struct Link *)((u32)func_020399A8()));
    b = 1 - a;
    if (func_021E12AC(p) == 0) return;
    if (func_021DD140(p) == 0) return;
    if (func_021D8A24(p) != 0 && func_02039CB4((struct Link *)func_020399A8(), 0x1D, 8) == 0) {
        func_021DD24C(p);
        return;
    }
    func_021DD294(p, 0, 0);
    c = (unsigned char)(p + a)[0x11E0];
    if (c == 13 && (unsigned char)(p + b)[0x11E0] == 13) {
        func_021DD080((void *)((u32)func_020399A8()), (void *)13, p);
        func_021D8E84(p, (int)func_021DA76C);
        return;
    }
    d = (unsigned char)(p + b)[0x11E0];
    if (d == 5) m = 0x61;
    else if (c == 5) m = 0x62;
    else if (d == 7) m = 0x63;
    else if (c == 7) m = 0x64;
    else if (d == 8) m = 0x64;
    else if (c == 8) m = 0x63;
    else if (d == 6) m = 0x61;
    else if (c == 6) m = 0x6F;
    else if (d == 14) m = 0x97;
    else if (c == 14) m = 0x96;
    func_02045CAC(((struct Obj00001 *)p)->f720, m, ((struct Obj00001 *)p)->f738);
    func_021E1024(p);
    p[0x11E0] = 0;
    p[0x11E1] = 0;
    func_021D8E84(p, (int)func_021DDB90);
}
