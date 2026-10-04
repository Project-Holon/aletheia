/*
 * function: func_021C3E0C
 * address: 0x021C3E0C
 * packet: pkt_ov093_021C3E0C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *  func_021C3FAC 0x021C3FAC thumb ov093
 *  func_021D59B4 0x021D59B4 thumb ov093
 *  func_021C3FBC 0x021C3FBC thumb ov093
 *  func_021C3FCC 0x021C3FCC thumb ov093
 *  func_021D5440 0x021D5440 thumb ov093
 *  func_021CD4B0 0x021CD4B0 thumb ov093
 *  func_021CD64C 0x021CD64C thumb ov093
 *  func_021CC8D8 0x021CC8D8 thumb ov093
 *  func_021CC95C 0x021CC95C thumb ov093
 *  func_021C7B3C 0x021C7B3C thumb ov093
 *  func_021C7B7C 0x021C7B7C thumb ov093
 *  func_021D66D0 0x021D66D0 thumb ov093
 *  func_021D8564 0x021D8564 thumb ov093
 *  func_021D62C4 0x021D62C4 thumb ov093
 *  func_021C195C 0x021C195C thumb ov093
 *  func_021C3FDC 0x021C3FDC thumb ov093
 */
#include "../include/Obj03191.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 pad[5]; u8 a:1,b:1,c:6; } Flag;
extern u8 *func_021C3FAC(u8 *, int);
extern int func_021D59B4(u8 *p, int k);
extern int func_021C3FBC(u16);
extern int func_021C3FCC(u16);
extern u8 func_021D5440(u8 *p);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021CD64C(void *w, u8 id, ...);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(void *, u32, int);
extern void func_021C7B3C(u8 *, int, u16, u16);
extern void func_021C7B7C(u8 *p, unsigned int i);
struct QJ;
extern void func_021D66D0(struct QJ *p, u32 v);
extern void func_021D8564(int a, int b);
extern int func_021D62C4(u8 *, int);
extern void func_021C195C(u8 *p, u8 *q, u32 n);
extern void func_021C3FDC(u8 *, u8 *);
void func_021C3E0C(u8 *p, u8 *a, u8 *c)
{
    u8 *b;
    u32 x, y, ai, bi;
    u32 s, t;
    int line;
    Flag *f;
    b = func_021C3FAC(c, 0);
    x = func_021D59B4(a, 16);
    y = func_021D59B4(b, 16);
    if (x != y && !func_021C3FBC(x) && !func_021C3FCC(y)) {
        ai = func_021D5440(a);
        bi = func_021D5440(b);
        f = *(Flag * *)&((struct Obj03191 *)p)->f4A8;
        if (f->a == 0) f->a = 1;
        func_021CD4B0(((struct Obj03191 *)p)->fC, 0x4a, ai, bi, (u16)y, (u16)x);
        func_021CD64C(((struct Obj03191 *)p)->fC, 0x5b, 0x1fc, ai, 0xffff0000);
        line = 9140;
        s = func_021CC8D8(p + 0x1d74, line);
        func_021C7B3C(p, ai, x, y);
        func_021C7B3C(p, bi, y, x);
        func_021CC95C(p + 0x1d74, s, line + 3);
        func_021D66D0((struct QJ *)a, y);
        func_021D66D0((struct QJ *)b, x);
        func_021D8564((int)a, (int)b);
        func_021CD4B0(((struct Obj03191 *)p)->fC, 0x58, ai);
        func_021CD4B0(((struct Obj03191 *)p)->fC, 0x58, bi);
        if (x != y) {
            t = func_021CC8D8(p + 0x1d74, line + 16);
            func_021C7B7C(p, ai);
            func_021C7B7C(p, bi);
            line += 19;
            func_021CC95C(p + 0x1d74, t, line);
        }
        if (func_021D62C4(a, 16) == 0) {
            if (x == 0x67) func_021C195C(p, a, 0);
            if (x == 0x7f) func_021C3FDC(p, a);
        }
        if (func_021D62C4(b, 16) == 0) {
            if (y == 0x67) func_021C195C(p, b, 0);
            if (y == 0x7f) func_021C3FDC(p, b);
        }
    } else {
        func_021CD64C(((struct Obj03191 *)p)->fC, 0x5a, 0x47, 0xffff0000);
    }
}
