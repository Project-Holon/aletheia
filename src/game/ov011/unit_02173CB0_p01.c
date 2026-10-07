/*
 * file:     unit_02173CB0_p01.c
 * unit:     yes
 * function: func_02173CB0, func_02173D00, func_02173D2C, func_02173D5C, func_02173DA0, func_02173DE0
 * address:  0x02173CB0
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_02175648  0x02175648  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D4D0  0x0203D4D0  arm
 *   func_0203D378 0x0203D378 arm
 *   func_02175F34 0x02175F34 thumb ov011
 *   func_02175914 0x02175914 thumb ov011
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_02175938  0x02175938  thumb ov011
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_020127AC  0x020127AC  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_02176048  0x02176048  thumb ov011
 *   func_0203D1E8  0x0203D1E8  arm
 *   func_021780FC  0x021780FC  thumb ov014
 */
#include "../../matched/include/Obj19172.h"

struct Big;
struct Out;
struct Entry;
struct Link;
struct SaveBlock;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef struct Ent {
    u16 h[8];
    u8 f10, f11, f12, pad13;
    u8 f14[0x14];
} Ent;

typedef struct { int w0; unsigned f : 4; } S;

u32 func_02026478(void *obj);
void *func_02012EBC(struct Big *p);
u16 *func_0200BE48(void *sys);
int func_021736D8(void);
void func_02175648(void *sv, struct Out *o);
extern struct Entry *func_020399A8(void);
u32 func_0203D4D0(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
u32 func_0203D378(void);
void func_02175F34(void *w, Ent *tbl, u32 arg, int idx);
void func_02175914(int a, int b);
int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
void func_02175938(u8 *p, const u16 *src, int index);
u32 func_0203D1A4(struct Link *p);
void *func_020127AC(struct SaveBlock *p, u32 idx);
void func_02082D44(void *d, int s, int n);
u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
int func_02176048(char *a, char *b, void *c, int d);
void func_0203D1E8(u32 unused, void *arg);
void func_021780FC(u8 value);
int func_02173CB0(int *a, int b);
void func_02173D00(u32 a, int b, int *c, u8 *d);
int func_02173D2C(int a0, int a1);
void func_02173D5C(int a, int b, char *c, char *d);
int func_02173DA0(int a, int b, int c);
void func_02173DE0(int a, int b, S *c, char *d);


int func_02173CB0(int *a, int b)
{
    int v;
    int buf[4];

    v = func_02026478((void *)a[1]);
    func_0200BE48(func_02012EBC((struct Big *)v));
    if (func_021736D8() == 0) {
        return 1;
    }
    func_02175648((void *)v, (struct Out *)buf);
    return func_0203D4D0((int)func_020399A8(), (unsigned char)b, 0x20D, 0x10, (u32)buf, 0, 0, 0);
}


/*
 * note: Two alignment bytes follow; existing pkt_ov011_02173D2C covers
 *       the next function's push at 02173D2C. No unit is created.
 */
void func_02173D00(u32 a, int b, int *c, u8 *d)
{
    if (func_0203D378()) {
        func_02175F34(d, (Ent *)(d + 0x1ac), a, *c);
        func_02175914((int)(d + 0x1ac), *c);
    }
}


int func_02173D2C(int a0, int a1)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    return func_0203D3A8(func_020399A8(), 0x20E, 4, (u32)(&a1));
}


void func_02173D5C(int a, int b, char *c, char *d)
{
    int v;
    int t;

    v = func_02026478((void *)(((struct Obj19172 *)d)->f4));
    t = (unsigned char)c[0x24];
    func_02175938((u8 *)(d + 0x1AC), (const u16 *)c, t);
    if (t != func_0203D1A4((struct Link *)((int)func_020399A8()))) {
        func_02082D44(c, (int)func_020127AC((struct SaveBlock *)v, t), 0x10);
    }
}


int func_02173DA0(int a, int b, int c)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    return func_0203D3F8((u32)func_020399A8(), 0xFF, 0x20F, 0x28, b + c * 0x28, 0, 0, 1);
}


void func_02173DE0(int a, int b, S *c, char *d)
{
    unsigned t;

    if (func_0203D378()) {
        if (func_02176048(d, d + 0x1AC, c, a) == 1) {
            t = c->f;
            if (t == 0 || t == 3) {
                func_0203D1E8((u32)func_020399A8(), 0);
                func_021780FC(1);
                d[0x93C] = 1;
            }
        }
    }
}
