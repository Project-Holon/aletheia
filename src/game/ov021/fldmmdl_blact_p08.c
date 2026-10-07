/*
 * file:     fldmmdl_blact_p08.c
 * unit:     yes
 * function: func_0219CDAC, func_0219CE60, func_0219CEAC, func_0219CF00, func_0219CF54, func_0219CFB0, func_0219D064, func_0219D0F4, func_0219D144, func_0219D184, func_0219D1F8, func_0219D208, func_0219D2CC
 * address:  0x0219CDAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216D518  0x0216D518  thumb  ov010
 *   func_02046E24  0x02046E24  arm
 *   func_0219CB24  0x0219CB24  thumb  ov021
 *   func_02046EFC  0x02046EFC  arm
 *   func_0216D4F0  0x0216D4F0  thumb  ov010
 *   func_0216E3C8  0x0216E3C8  thumb  ov010
 *   func_0219CBD4  0x0219CBD4  thumb  ov021
 *   func_0219CD68  0x0219CD68  thumb  ov021
 *   func_0219D3F0  0x0219D3F0  thumb  ov021
 *   func_0219C7B4  0x0219C7B4  thumb  ov021
 *   func_0219C780  0x0219C780  thumb  ov021
 *   func_0216D758  0x0216D758  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216E204  0x0216E204  thumb  ov010
 *   func_0219C880  0x0219C880  thumb  ov021
 *   func_02050468  0x02050468  arm
 *   func_0216D4F8  0x0216D4F8  thumb  ov010
 *   d_021DDD70     0x021DDD70  data ov021 a4
 */
#include "../../matched/include/Obj03579.h"
#include "../../matched/include/Obj04224.h"
#include "../../matched/include/Obj05011.h"
#include "../../matched/include/Obj19665.h"
#include "../../matched/include/Obj03580.h"
#include "../../matched/include/Obj12673.h"
#include "../../matched/include/Obj03117.h"
#include "../../matched/include/Obj07477.h"
#include "../../matched/include/Obj00429.h"
#include "../../matched/include/Obj09512.h"
#include "../../matched/include/Obj12675.h"
#include "../../matched/include/Obj06001.h"
#include "../../matched/include/Obj12676.h"
#include "../../matched/include/Obj01353.h"
#include "../../matched/include/Obj03118.h"
#include "../../matched/include/Obj00808.h"
#include "../../matched/include/Obj07478.h"
#include "../../matched/include/Obj02699.h"
#include "../../matched/include/Obj03119.h"
#include "../../matched/include/Obj03116.h"

struct Tagged;
struct BbActSys;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct { u32 a, b, c; } E12;

typedef struct { int a; int b; int c; } S3;

extern u32 func_0216D518(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern void func_0219CB24(u8 *o, u32 a, u32 b, u32 c, u8 s0, u32 s1);
extern void func_02046EFC(struct Tagged *p);
extern u16 func_0216D4F0(void *p);
extern void *func_0216E3C8(void *p);
extern int func_0219CBD4(u32 a, u32 b, u32 c, u32 d);
extern void func_0219CD68(u8 *o, u16 a, u8 b, u8 c, u16 d, u32 e);
extern unsigned short func_0219D3F0(int *o, int a1, int a2, int a3, int a4, int a5);
extern unsigned short func_0219C7B4(int, unsigned int, unsigned int);
extern unsigned short func_0219C780(int, int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void func_0216D758(void *a0);
extern void func_02082BCC(u8 *p, u32 a, u32 b);
extern void *func_0216D67C(void *a0);
extern u32 func_0216D520(void *p);
extern int func_0216D7A8(void *p, unsigned int v);
extern u16 func_0216D598(void *p);
extern void func_0216E204(char *a, u32 v);
extern void func_0219C880(u8 *o, u32 a, u32 b, u32 c);
extern void func_02050468(struct BbActSys *o, u16 first, u32 count);
extern u32 func_0216D4F8(u8 *p);
extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
void func_0219CDAC(u8 *o);
int func_0219CE60(u8 *o, u32 a, u32 b, u32 c, u16 e, u32 w);
void func_0219CEAC(int *obj);
int func_0219CF00(int *t, unsigned int id, unsigned short *out);
int func_0219CF54(int *t, unsigned int id);
void func_0219CFB0(int *obj, int a1, unsigned char *src, int a3, int a5, int a6, S3 *a7);
void func_0219D064(int *obj, int *rec);
void func_0219D0F4(int *obj);
int func_0219D144(int *obj, unsigned int a, int b);
void func_0219D184(int *obj, int key);
void func_0219D1F8(u8 *p);
void func_0219D208(int a, unsigned int id);
void func_0219D2CC(int *obj);
extern unsigned char d_021DDD70[];


/*
 * Commits pending 0xC-byte entries through func_0219CE60, then compacts the
 * table so the free (0xFFFF) entries sit at the end.
 *
 * Addresses are Black-image addresses.
 */
void func_0219CDAC(u8 *o)
{
    u8 *ctx = *(u8 * *)&((struct Obj03579 *)o)->f1C;
    u32 j = 0;
    u32 k = 0;
    u8 *e = *(u8 * *)&((struct Obj05011 *)ctx)->fC;
    u8 *base;
    for (; j < ((struct Obj05011 *)ctx)->f4; j++, e += 0xc) {
        if (((struct Obj04224 *)e)->f0 != 0xFFFF) {
            if (func_0219CE60(o, ((struct Obj04224 *)e)->f0, e[4], e[5], ((struct Obj04224 *)e)->f2, ((struct Obj04224 *)e)->f8) == 0)
                break;
            ((struct Obj04224 *)e)->f0 = 0xFFFF;
            k++;
            if (k >= ((struct Obj05011 *)ctx)->f6)
                break;
        }
    }
    if (k != 0) {
        j = 0;
        base = *(u8 * *)&((struct Obj05011 *)ctx)->fC;
        for (; j < (u32)((struct Obj05011 *)ctx)->f4 - 1; j++) {
            E12 *ent = (E12 *)(base + 12 * j);
            if (((struct Obj19665 *)ent)->f0 == 0xFFFF) {
                for (k = j + 1; k < ((struct Obj05011 *)ctx)->f4; k++) {
                    if (*(u16 *)(base + 12 * k) != 0xFFFF) {
                        *ent = *(E12 *)(base + 12 * k);
                        *(u16 *)(base + 12 * k) = 0xFFFF;
                        break;
                    }
                }
            }
        }
    }
}


/*
 * Claims the first free 0x14-byte slot of the table at *(*(+0x1c)+0x10).
 *
 * Addresses are Black-image addresses.
 */
int func_0219CE60(u8 *o, u32 a, u32 b, u32 c, u16 e, u32 w)
{
    u8 *ctx = *(u8 * *)&((struct Obj03579 *)o)->f1C;
    u8 *p = *(u8 * *)&((struct Obj12673 *)ctx)->f10;
    u32 i;
    for (i = 0; i < ((struct Obj12673 *)ctx)->f6; i++, p += 0x14) {
        if (((struct Obj03580 *)p)->f10 == 0) {
            ((struct Obj03580 *)p)->f0 = 0;
            ((struct Obj03580 *)p)->f8 = a;
            ((struct Obj03580 *)p)->fA = b;
            ((struct Obj03580 *)p)->fB = c;
            ((struct Obj03580 *)p)->f4 = w;
            ((struct Obj03580 *)p)->f10 = (u32)func_02046E24(func_0216D518((u8 *)(((struct Obj03579 *)o)->f10)), e);
            ((struct Obj03580 *)p)->f0 = 1;
            return 1;
        }
    }
    return 0;
}


void func_0219CEAC(int *obj)
{
    unsigned int i;
    int *p;
    int *t;

    t = (int *)obj[7];
    if (t != 0 && t[0] == 1) {
        i = 0;
        p = (int *)t[4];
        if (!(i < ((struct Obj07477 *)t)->f6)) {
            return;
        }
        for (; i < ((struct Obj07477 *)t)->f6; i++, p += 5) {
            if (p[4] != 0 && ((struct Obj03117 *)p)->f0 == 1) {
                ((struct Obj03117 *)p)->f0 = 0;
                func_0219CB24((u8 *)obj, p[4], ((struct Obj03117 *)p)->f8, *((unsigned char *)p + 0xa),
                              *((unsigned char *)p + 0xb), p[1]);
                p[4] = 0;
            }
        }
    }
}


int func_0219CF00(int *t, unsigned int id, unsigned short *out)
{
    unsigned int i;
    unsigned char *p;
    unsigned int n;
    unsigned int j;
    unsigned char *q;
    unsigned int m;

    t = (int *)t[7];
    i = 0;
    n = *(unsigned short *)&((struct Obj00429 *)t)->f4;
    p = (unsigned char *)t[3];
    for (; i < n; i++, p += 12) {
        if (((struct Obj12675 *)p)->f0 == id) {
            *out = ((struct Obj12675 *)p)->f8;
            return 1;
        }
    }
    m = *(unsigned short *)((char *)t + 6);
    j = 0;
    q = (unsigned char *)t[4];
    for (; j < m; j++, q += 20) {
        if (((struct Obj09512 *)q)->f8 == id && ((struct Obj09512 *)q)->f10 != 0) {
            *out = ((struct Obj09512 *)q)->f4;
            return 1;
        }
    }
    return 0;
}


int func_0219CF54(int *t, unsigned int id)
{
    unsigned int i;
    unsigned char *p;
    unsigned int n;
    unsigned int j;
    unsigned char *q;
    unsigned int m;

    t = (int *)t[7];
    i = 0;
    n = *(unsigned short *)&((struct Obj00429 *)t)->f4;
    p = (unsigned char *)t[3];
    for (; i < n; i++, p += 12) {
        if (((struct Obj12676 *)p)->f0 == id) {
            ((struct Obj12676 *)p)->f0 = 0xFFFF;
            return 1;
        }
    }
    m = *(unsigned short *)((char *)t + 6);
    j = 0;
    q = (unsigned char *)t[4];
    for (; j < m; j++, q += 20) {
        if (*(int *)&((struct Obj06001 *)q)->f10 != 0 && ((struct Obj06001 *)q)->f8 == id) {
            *q = 0;
            func_02046EFC(((struct Obj06001 *)q)->f10);
            *(int *)&((struct Obj06001 *)q)->f10 = 0;
            return 1;
        }
    }
    return 0;
}


void func_0219CFB0(int *obj, int a1, unsigned char *src, int a3, int a5, int a6, S3 *a7)
{
    unsigned int i;
    unsigned int n;
    int *p;
    unsigned short v[2];
    unsigned short *t;

    i = 0;
    n = func_0216D4F0((void *)obj[4]);
    p = *(int **)(obj[7] + 0x14);
    for (; i < n; i++, p += 10) {
        if (p[0] == 0) {
            *((unsigned char *)p + 0xd) = 0;
            p[1] = a1;
            p[0] = a3;
            ((struct Obj01353 *)p)->f8 = ((struct Obj03118 *)src)->f0;
            *((unsigned char *)p + 0xa) = src[7];
            *((unsigned char *)p + 0xb) = src[8];
            *((unsigned char *)p + 0xc) = src[9];
            func_0219CBD4((u32)obj, ((struct Obj01353 *)p)->f8, (u32)(&v[1]), (u32)(&v[0]));
            if (v[1] == 0xFFFF && func_0219CF00(obj, ((struct Obj01353 *)p)->f8, &v[0]) == 0) {
                t = func_0216E3C8(src);
                v[0] = 1;
                func_0219CD68((u8 *)obj, ((struct Obj01353 *)p)->f8, *((unsigned char *)p + 0xa),
                              *((unsigned char *)p + 0xb), *t, 1);
            }
            p[5] = a5;
            p[6] = a6;
            if (a7 != 0) {
                *(S3 *)(p + 7) = *a7;
            }
            *((unsigned char *)p + 0xd) = 1;
            return;
        }
    }
}


void func_0219D064(int *obj, int *rec)
{
    unsigned short x[3];
    unsigned short r;

    x[0] = 0xFFFF;
    *((unsigned char *)rec + 0xd) = 0;
    if (rec[4] != 0) {
        x[2] = func_0219D3F0(obj, ((struct Obj00808 *)rec)->f8, *((unsigned char *)rec + 0xa),
                             *((unsigned char *)rec + 0xb), rec[4], 1);
        rec[4] = 0;
        func_0219CBD4((u32)obj, ((struct Obj00808 *)rec)->f8, (u32)(&x[0]), (u32)(&x[1]));
    } else {
        func_0219CBD4((u32)obj, ((struct Obj00808 *)rec)->f8, (u32)(&x[2]), (u32)(&x[1]));
    }
    if (rec[1] != 0) {
        r = func_0219C7B4(rec[1], x[2], x[0]);
    } else {
        r = func_0219C780(obj[4], (int)(rec + 7), *((unsigned char *)rec + 0xa),
                          *((unsigned char *)rec + 0xc), x[2], x[0]);
    }
    *(unsigned short *)rec[0] = r;
    if (rec[5] != 0) {
        ((void (*)(unsigned int, int))rec[5])(*(unsigned short *)rec[0], rec[6]);
    }
    if (rec[1] != 0) {
        func_0216D758((void *)rec[1]);
    }
}


void func_0219D0F4(int *obj)
{
    unsigned int i;
    unsigned int n;
    int *p;
    unsigned short sp[2];

    i = 0;
    n = func_0216D4F0((void *)obj[4]);
    p = *(int **)(obj[7] + 0x14);
    if (n == 0) {
        return;
    }
    for (; i < n; i++, p += 10) {
        if (p[0] != 0 && *((unsigned char *)p + 0xd) == 1) {
            if (func_0219CBD4((u32)obj, ((struct Obj00808 *)p)->f8, (u32)(&sp[0]), (u32)(&sp[1])) == 1) {
                func_0219D064(obj, p);
                func_0219D1F8((u8 *)p);
            }
        }
    }
}


int func_0219D144(int *obj, unsigned int a, int b)
{
    unsigned int i;
    unsigned int n;
    int *p;

    i = 0;
    n = func_0216D4F0((void *)obj[4]);
    p = *(int **)(obj[7] + 0x14);
    for (; i < n; i++, p += 10) {
        if (p[0] != 0 && p[1] != 0 && p[1] != b && ((struct Obj07478 *)p)->f8 == a) {
            return 1;
        }
    }
    return 0;
}


void func_0219D184(int *obj, int key)
{
    unsigned int i;
    unsigned int n;
    int *p;
    unsigned short s;

    i = 0;
    n = func_0216D4F0((void *)obj[4]);
    p = *(int **)(obj[7] + 0x14);
    for (; i < n; i++, p += 10) {
        if (p[0] != 0 && p[1] == key) {
            *((unsigned char *)p + 0xd) = 0;
            if (func_0219CF00(obj, ((struct Obj02699 *)p)->f8, &s) == 1 && (s & 1)) {
                if (func_0219D144(obj, ((struct Obj02699 *)p)->f8, p[1]) == 0) {
                    func_0219CF54(obj, ((struct Obj02699 *)p)->f8);
                }
            }
            if (p[4] != 0) {
                func_02046EFC((void *)p[4]);
                p[4] = 0;
            }
            func_0219D1F8((u8 *)p);
            return;
        }
    }
}


/*
 * Clears the byte at +0xd, then tail calls with 0 and 0x28.
 *
 * Addresses are Black-image addresses.
 */
void func_0219D1F8(u8 *p)
{
    *((u8 *)p + 0xd) = 0;
    func_02082BCC(p, 0, 0x28);
}


void func_0219D208(int a, unsigned int id)
{
    int *ctx;
    int i;
    unsigned char *r;
    unsigned short h;
    unsigned short v[2];

    ctx = (int *)func_0216D520(func_0216D67C((void *)a));
    r = (unsigned char *)ctx[8];
    func_0219CBD4((u32)ctx, id, (u32)(&v[1]), (u32)(&v[0]));
    if (v[1] != 0xFFFF && !(v[0] & 2)) {
        func_0216E204((char *)a, id);
        return;
    }
    i = 0;
    h = func_0216D7A8((void *)a, 0);
    if (h == 0xFFFF) {
        func_0216E204((char *)a, id);
        return;
    }
    for (; i < 4; i++) {
        if (((struct Obj03119 *)r)->f0 == 0) {
            break;
        }
    }
    if (i >= 4) {
        func_0216E204((char *)a, id);
        return;
    }
    ((struct Obj03119 *)r)->f0 = a;
    ((struct Obj03119 *)r)->f4 = h;
    ((struct Obj03119 *)r)->f6 = func_0216D598((void *)a);
    ((struct Obj03119 *)r)->f8 = id;
    func_0216E204((char *)a, id);
    i = 0;
    if (func_0216D7A8((void *)a, 0) != 0xFFFF) {
        func_0219C880((u8 *)ctx, a, ((struct Obj03119 *)r)->f4, ((struct Obj03119 *)r)->f6);
        func_02050468((struct BbActSys *)ctx[1], ((struct Obj03119 *)r)->f4, 1);
        ((struct Obj03119 *)r)->f0 = i;
    }
}

/*
 * Promoted 2026-09-27 (lane ov010 blocker tree).  The call at +0x08 is a
 * Thumb `bl` (d0 f7 10 f9), not an interworking `blx`: the target must be
 * Thumb.  The old header called 0x0216D4F8 `arm ov009`, but ov009's byte
 * there is an ARM fragment with no start, while ov010 holds an EXACT Thumb
 * getter (src/matched/func_0216D4F8.c, shard layout/matched/ov010/
 * pkt_0216D4F8.json).  With the region/ISA hint fixed to `thumb ov010` the
 * site resolves as `matched` and the entry is EXACT.
 */
void func_0219D2CC(int *obj)
{
    ((struct Obj03116 *)obj)->f20 =
        (int)func_02030734(func_0216D4F8((u8 *)obj[4]), 0x30, 1, (const char *)d_021DDD70, 0x979);
}
