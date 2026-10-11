/*
 * file:     btl_server_p02.c
 * unit:     yes
 * function: func_021BC0E8, func_021BC220, func_021BC2B0, func_021BC310, func_021BC360, func_021BC390, func_021BC3B0
 * address:  0x021BC0E8
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
 *   func_021BC948 0x021BC948 thumb ov093
 *   func_021D8454 0x021D8454 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021BC8EC 0x021BC8EC thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021C6350 0x021C6350 thumb ov093
 *   func_021BC874 0x021BC874 thumb ov093
 *   func_021BB85C  0x021BB85C  thumb  ov093
 *   func_021BB8A8  0x021BB8A8  thumb  ov093
 *   func_021BB8B0  0x021BB8B0  thumb  ov093
 *   func_021BD9D4  0x021BD9D4  thumb  ov093
 *   func_021BDA00  0x021BDA00  thumb  ov093
 *   func_021C5200  0x021C5200  thumb  ov093
 *   func_021B8B9C  0x021B8B9C  thumb  ov093
 *   func_021B8BC4  0x021B8BC4  thumb  ov093
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021B9B98  0x021B9B98  thumb  ov093
 *   func_021B990C 0x021B990C thumb ov093
 *   func_021BD584 0x021BD584 thumb ov093
 *   func_021BB890  0x021BB890  thumb  ov093
 *   func_021B8588  0x021B8588  thumb  ov093
 *   func_021BC408  0x021BC408  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 */
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj06224.h"
#include "../../matched/include/Obj05189.h"

#define ENTRY(i) (&e[i])
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 a:4; u32 b:3; u32 action:16; u32 rest:9; } B;

typedef struct { u8 *a; B b; u32 c; u8 d,f; u16 pad; } E;

typedef struct { u8 *a; B b; u32 c; u8 d,f; u16 pad; } E2;

typedef struct {
    u32 a : 4;
    u32 b : 3;
    u32 c : 3;
    u32 d : 1;
} Bf;

extern u16 func_021BC948(u8 *, u8 *, int);
extern u32 func_021D8454(u32 *);
extern u32 func_021CC8D8(void *, int);
extern int func_021BC8EC(u8 *, u32, u8 *);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern u8 func_021C6350(u8 *, u8 *);
typedef struct { u32 a, b, key, d; } E_021BC874;

extern void func_021BC874(E_021BC874 *p, u32 n);
extern u8 *func_021BB85C(u8 *p, unsigned int i);
extern u8 func_021BB8A8(u8 *p, u8 i);
extern Bf func_021BB8B0(u8 *p, u8 i, u8 j);
extern void func_021BD9D4(u8 *p, u8 i, u8 a, u8 b, int c);
extern int func_021BDA00(u8 *p);
extern int func_021C5200(u8 *p);
extern int func_021B8B9C(u8 *p, u8 k);
extern unsigned char func_021B8BC4(int unused, unsigned int b);
extern u8 func_021B8FF4(u8 *p);
extern char *func_021B9AEC(char *p, int i);
extern u8 func_021B9B98(u8 *p);
extern void *func_021B990C(char *, u32, u32);
extern int func_021BD584(u8 *, u8 *);
extern int func_021BB890(u8 *p, u8 i);
extern u32 func_021B8588(void **p);
extern int func_021BC408(u8 *p, u8 i, u32 *out);
extern void func_021CD4B0(int p, int k, u8 a, u8 b);
void func_021BC0E8(u8 *p, E *e, u32 n);
int func_021BC220(u8 *p, u8 *o);
int func_021BC2B0(u8 *p);
int func_021BC310(u8 *p);
int func_021BC360(u8 *p);
int func_021BC390(u8 *p);
void func_021BC3B0(int *p);



static inline void set_accuracy(E *e, u16 v)
{
    e->c = (v & 0x1fff) | (e->c & 0xffffe000);
}



static inline u32 pack(u16 low, u8 a, u8 b, u8 c)
{
    return (low & 0x1fff) | (((u16)(a << 13)) | ((((u32)(u16)(c << 13) << 9)) | (((u32)b & 63) << 16)));
}



static inline void update(E *e, int result)
{
    u16 low = (u16)(e->c & 0x1fff);
    u8 a = (e->c >> 13) & 7;
    u8 c = (e->c >> 22) & 7;
    e->c = pack(low, a, result, c);
}



void func_021BC0E8(u8 *p, E *e, u32 n)
{
    u32 i;
    u32 off;
    u32 type;
    u16 value;
    u32 lock;
    int result;
    E *q;
    for (i = 0; i < n; i++) {
        off = i * 16;
        q = &e[i];
        set_accuracy(q, func_021BC948(p, ENTRY(i)->a, 1));
        type = func_021D8454((u32 *)&q->b);
        if (type == 1) {
            if (((E2 *)e)[i].b.a == 1) value = ((E2 *)e)[i].b.action; else value = 0;
            lock = func_021CC8D8(p + 0x1d74, 1076);
            q = (E *)((u32)e + off);
            result = func_021BC8EC(p, value, q->a);
            update(q, result);
            func_021CC95C((u32 *)(p + 0x1d74), lock, 1079);
        }
        if (type == 1 || type == 5) {
            lock = func_021CC8D8(p + 0x1d74, 1087);
            q = (E *)((u32)e + off);
            q->c = ((func_021C6350(p, q->a) & 7) << 13) | (q->c & 0xffff1fff);
            func_021CC95C((u32 *)(p + 0x1d74), lock, 1090);
        }
    }
    func_021BC874((E_021BC874 *)e, n);
}





/*
 * func_021BB8B0 returns a 4-byte bitfield struct: declaring it that way
 * (a u32 return with shifts and masks gives a different frame) is what
 * matches.
 */
int func_021BC220(u8 *p, u8 *o)
{
    u32 i;
    u32 j;
    u32 n;
    Bf v;

    for (i = 0; i < 4; i++) {
        if (func_021BB85C((u8 *)(*(int *)&((struct Obj00003 *)p)->f0), (u8)i) != 0) {
            n = func_021BB8A8(o, i);
            for (j = 0; j < n; j++) {
                v = func_021BB8B0(o, i, j);
                if (v.a == 3 && v.d == 0)
                    func_021BD9D4(p, i, v.b, v.c, 1);
            }
        }
    }
    func_021BDA00(p);
    return func_021C5200(p);
}





int func_021BC2B0(u8 *p)
{
    u8 f[2];
    u32 i;

    f[1] = 0;
    f[0] = f[1];
    for (i = 0; i < 4; i++) {
        if (func_021B8B9C(*(u8 * *)&((struct Obj00003 *)p)->f4, i) != 0) {
            char *q = func_021B9AEC(*(char * *)&((struct Obj00003 *)p)->f8, i);
            u8 k = func_021B8BC4((int)(*(u8 * *)&((struct Obj00003 *)p)->f4), (u8)i);

            if (func_021B9B98((u8 *)q) != 0)
                f[k] = 1;
        }
    }
    if (f[0] == 0 || f[1] == 0)
        return 1;
    return 0;
}




int func_021BC310(u8 *p)
{
    u32 i;

    for (i = 0; i < 4; i++) {
        if (func_021B8B9C(*(u8 * *)&((struct Obj06224 *)p)->f4, i) != 0) {
            u8 a = func_021B8BC4((int)(*(u8 * *)&((struct Obj06224 *)p)->f4), (u8)i);
            u8 b = func_021B8BC4((int)(*(u8 * *)&((struct Obj06224 *)p)->f4), (u8)func_021B8FF4(*(u8 * *)&((struct Obj06224 *)p)->f4));

            if (a == b) {
                if (func_021B9B98((u8 *)func_021B9AEC(*(char * *)&((struct Obj06224 *)p)->f8, i)) != 0)
                    return 1;
            }
        }
    }
    return 0;
}



/*
 * extent: two zero alignment bytes at 0x021BC38E, then func_021BC390.
 * Lever: bind the first call result before initializing the boolean result.
 */
int func_021BC360(u8 *p)
{
    u8 *a;
    u32 side;
    int result;
    u32 *out;
    side = func_021B8FF4(*(u8 * *)&((struct Obj00003 *)p)->f4);
    result = 0;
    a = func_021B990C(*(char * *)&((struct Obj00003 *)p)->f8, side, 0);
    out = *(u32 * *)&((struct Obj00003 *)p)->fC;
    out[0] = 0;
    out[1] = 0;
    if (func_021BD584(p, a)) result = 1;
    return result;
}



/*
 * extent: two zero alignment bytes at 0x021BC3AE, then matched func_021BC3B0.
 */
int func_021BC390(u8 *p)
{
    int result = 0;
    u32 *out = *(u32 * *)&((struct Obj05189 *)p)->fC;
    out[0] = 0;
    out[1] = 0;
    func_021BC3B0((int *)p);
    if (**(u32 * *)&((struct Obj05189 *)p)->fC) result = 1;
    return result;
}


void func_021BC3B0(int *p)
{
    u32 i;
    u32 x;
    u32 v;

    if (p[6] == 1) {
        for (i = 0; i < 4; i++) {
            if (func_021BB890((u8 *)p[0], i) != 0) {
                if (func_021B8588((void **)p[1]) != 2)
                    v = 1;
                else
                    v = func_021BC408((u8 *)p + 0x1ab8, i, &x) + 1;
                func_021CD4B0(p[3], 0x29, i, v);
            }
        }
    }
}
