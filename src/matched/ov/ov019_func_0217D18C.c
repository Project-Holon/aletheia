/*
 * function: func_0217D18C
 * address:  0x0217D18C
 * packet:   pkt_ov019_0217D18C
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0217BB04  0x0217BB04  thumb  ov019
 *   func_0217F210  0x0217F210  thumb  ov019
 *   func_0217F1EC  0x0217F1EC  thumb  ov019
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200ED48  0x0200ED48  thumb
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_02012950  0x02012950  thumb
 *   func_02008530  0x02008530  thumb
 *   func_0200ED54  0x0200ED54  thumb
 *   func_02030734  0x02030734  arm
 *   func_0201A920  0x0201A920  thumb
 *   func_0217422C  0x0217422C  thumb  ov012
 *   func_02174268  0x02174268  thumb  ov012
 *   func_020307B0  0x020307B0  arm
 *   func_0203D378  0x0203D378  arm
 *   func_0217B8E4  0x0217B8E4  thumb  ov019
 *   d_021807E8     0x021807E8  data  a4
 */
#include "../include/Obj07385.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int f00;
    int f04;
    u16 f08;
    u8 f0a;
    u8 f0b;
    int f0c;
    int f10;
} Rec14;

typedef struct {
    u8 pad00[8];
    int f08;
    u8 pad0c[0x14 - 0x0c];
    int f14;
    int pad18;
    int f1c;
    Rec14 *f20;
} Rec30;

extern int func_0217BB04(char *p);
typedef unsigned int   u32;
extern void func_0217F210(u8 *p, int a, u32 b);
extern u32 func_0217F1EC(u8 *p);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern void func_02039C68(struct Link *p, unsigned int lo, unsigned int hi);
extern unsigned int func_02039CB4(struct Link *p, unsigned int lo, unsigned int hi);
struct Big;
struct Ctx;
struct L0200ED54;
struct Party;
struct Rec44;
struct Sub0200852CObj;
struct Sub24;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200ED48(void *p);
extern u32 func_0203D1A4(struct Link *p);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void func_0200ED54(struct L0200ED54 *l, u32 val);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *file, u16 line);
extern struct Party *func_0201A920(u32 heap);
extern void func_0217422C(u8 *p, int a, int b);
extern int func_02174268(u8 *a);
extern u32 func_020307B0(void *p);
extern u32 func_0203D378(void);
extern int func_0217B8E4(char *p, char v);
extern u8 d_021807E8[];

int func_0217D18C(u8 *a, int b, int c, u8 *d)
{
    int x, y;
    Rec30 *p;
    Rec14 *q;
    if (*d != 4 && func_0217BB04((char *)a) == 1)
        return 1;
    switch (*d) {
    case 0:
        func_0217F210(a, c, 0x26);
        (*d)++;
        break;
    case 1:
        if (func_0217F1EC(a) == 1) {
            func_02039C68((struct Link *)func_020399A8(), 6, 0x14);
            (*d)++;
        }
        break;
    case 2:
        if (func_02039CB4((struct Link *)func_020399A8(), 6, 0x14) == 1) {
            x = (int)func_020120F4((const struct Ctx *)((*(int **)a)[3]));
            y = (int)func_0200ED48(func_02012EBC((struct Big *)x));
            func_0200ED54((struct L0200ED54 *)y, func_02008530((const struct Sub0200852CObj *)func_02012950((struct Sub24 *)x, func_0203D1A4((struct Link *)((int)func_020399A8())) ^ 1)));
            (*d)++;
        }
        break;
    case 3:
        p = func_02030734(0x41, 0x30, 1, (const char *)d_021807E8, 0xA54);
        p->f14 = (int)func_020120F4((const struct Ctx *)((*(int **)a)[3]));
        p->f1c = (int)func_0201A920(0x41);
        q = func_02030734(4, 0x14, 0, (const char *)d_021807E8, 0xA5B);
        q->f00 = p->f14;
        q->f04 = p->f1c;
        q->f08 = 0;
        q->f0a = 0;
        q->f0b = 0;
        q->f0c = 1;
        q->f10 = 0;
        p->f20 = q;
        p->f08 = 0;
        *(Rec30 * *)&((struct Obj07385 *)a)->f3558 = p;
        func_0217422C(a, 2, (int)p);
        (*d)++;
        break;
    case 4:
        if (func_02174268(a) == 0) {
            p = *(Rec30 * *)&((struct Obj07385 *)a)->f3558;
            func_020307B0(p->f20);
            func_020307B0((void *)p->f1c);
            func_020307B0(*(Rec30 * *)&((struct Obj07385 *)a)->f3558);
            *(Rec30 * *)&((struct Obj07385 *)a)->f3558 = 0;
            (*d)++;
        }
        break;
    case 5:
        func_0217F210(a, c, 0x10);
        func_02039C68((struct Link *)func_020399A8(), 7, 0x14);
        (*d)++;
        break;
    case 6:
        if (func_0217F1EC(a) != 0 && func_02039CB4((struct Link *)func_020399A8(), 7, 0x14) == 1) {
            if (func_0203D378() == 1)
                func_0217B8E4((char *)a, 7);
            else
                func_0217B8E4((char *)a, 9);
            return 1;
        }
        break;
    }
    return 0;
}
