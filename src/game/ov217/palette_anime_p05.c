/*
 * file:     palette_anime_p05.c
 * unit:     yes
 * function: func_021C16C4, func_021C16DC, func_021C16E8, func_021C16FC, func_021C1704, func_021C1720, func_021C17C4, func_021C1850, func_021C18C4, func_021C18F8, func_021C1A58, func_021C1A5C, func_021C1A64, func_021C1A84, func_021C1AB4, func_021C1AC0, func_021C1AD4, func_021C1AFC, func_021C1B28
 * address:  0x021C16C4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C0E4C  0x021C0E4C  thumb  ov217
 *   func_021C0E54  0x021C0E54  thumb  ov217
 *   func_021C0E5C  0x021C0E5C  thumb  ov217
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021C1B60 0x021C1B60 thumb ov217
 *   func_021C1B4C 0x021C1B4C thumb ov217
 *   func_0207CA30 0x0207CA30 arm
 *   _ffltu  0x0209BE04  arm
 *   _ffixu  0x0209C494  arm
 */
#include "../../matched/include/Obj04640.h"
#include "../../matched/include/Obj04641.h"
#include "../../matched/include/Obj00554.h"
#include "../../matched/include/Obj03955.h"
#include "../../matched/include/Obj14759.h"
#include "../../matched/include/Obj03377.h"

struct Ring;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef signed char    s8;

typedef signed short   s16_021C16E8;

typedef signed short   s16_021C1704;

typedef signed short   s16_021C1720;

typedef struct {
    u32 f0;
    u32 f1;
    u32 f2;
    u32 f3;
    u32 f4;
} Rec_021C17C4;

struct Ent_021C18C4 {
    u8 pad0[8];
    u8 len;
    u8 start;
    u8 end;
    u8 pad1[9];
};

typedef signed short s16_021C18F8;

enum Counter { ZERO=0 };

struct Range {u8 max,min;u16 x,y,z;};

typedef struct {
    u32 w;
    u32 a;
} Rec_021C1A58;

typedef struct {
    u32 w[5];
    u32 flag;
    u32 value;
} Rec_021C1A5C;

typedef short s16_021C1A64;

struct Pos { s16_021C1A64 x; s16_021C1A64 y; s16_021C1A64 z; };

struct Ent_021C1A84 {
    u8 pad0[0x1C];
};

typedef signed short   s16_021C1AC0;

extern void func_021C0E4C(u32, u32);
extern u32 func_021C0E54(struct Ring *r);
extern u32 func_021C0E5C();
extern u16 func_021C1B60(void *);
extern u16 func_021C1B4C(void *);
extern void func_0207CA30(const s16_021C18F8 *,const s16_021C18F8 *,s16_021C18F8 *);
void func_021C16C4(void *p);
void func_021C16DC(u32 *p, u32 a1);
void func_021C16E8(u32 a0);
void *func_021C16FC(void *p, u32 v);
u32 func_021C1704(void *a0);
void func_021C1720(u8 *a0, u8 *a1);
void func_021C17C4(u8 *p);
void func_021C1850(u8 *p);
void func_021C18C4(u8 *p);
void func_021C18F8(u8 *p);
void func_021C1A58(Rec_021C1A58 *p, u32 v);
void func_021C1A5C(Rec_021C1A5C *p, u32 v);
void func_021C1A64(u8 *p, const struct Pos *v);
u8 func_021C1A84(u8 *p, u8 key);
void *func_021C1AB4(void *p, u32 n);
void *func_021C1AC0(u8 *p, u8 key);
int func_021C1AD4(u8 *p);
int func_021C1AFC(u8 *p);
void func_021C1B28(u8 *p, u8 *a, u8 *b);


/*
 * Count the u32 at +0x18 down to zero, clearing the u32 at +0x14 when it reaches it.
 *
 * Addresses are Black-image addresses.
 */
void func_021C16C4(void *p)
{
    u32 v;
    if (((struct Obj04640 *)p)->f14 == 0)
        return;
    if (((struct Obj04640 *)p)->f18 == 0)
        return;
    v = ((struct Obj04640 *)p)->f18 - 1;
    ((struct Obj04640 *)p)->f18 = v;
    if (v == 0)
        ((struct Obj04640 *)p)->f14 = 0;
}

/*
 * Word at +0xc forwarded to func_021C0E4C.
 *
 * Addresses are Black-image addresses.
 */
void func_021C16DC(u32 *p, u32 a1)
{
    func_021C0E4C(p[3], a1);
}

/*
 * Reconstructed from the listing.
 *
 * Addresses are Black-image addresses.
 */
void func_021C16E8(u32 a0)
{
    func_021C16FC((void *)(a0 + 0 + 0), func_021C0E54((struct Ring *)(((struct Obj04641 *)(((u8*)a0 + 0)))->fC)) + 0);
}


/*
 * Set +8 and clear +0x10.
 *
 * Addresses are Black-image addresses.
 */
void *func_021C16FC(void *p, u32 v)
{
    ((struct Obj04641 *)p)->f8 = v;
    ((struct Obj04641 *)p)->f10 = 0;
    return p;
}

u32 func_021C1704(void *a0)
{
    ((struct Obj00554 *)(((u8*)a0)))->f1AC = 0;
    func_021C0E5C(((struct Obj00554 *)(((u8*)a0)))->fC);
    return (u32)func_021C16FC(a0, 0);
}



/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
void func_021C1720(u8 *a0, u8 *a1)
{
    *(u8*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC) + 28) = ((struct Obj03955 *)((u8*)a1))->f0;
    *(u32*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC) + 32) = (u32)(((struct Obj03955 *)(((u8*)a1)))->f4);
    *(u8*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC + 36)) = 0;
    *(u8*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC + 37)) = 0;
    *(u8*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC + 38)) = 0;
    *(u8*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC + 39)) = ((struct Obj03955 *)(((u8*)a1)))->f8;
    *(u8*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC + 40)) = ((struct Obj03955 *)(((u8*)a1)))->f9;
    *(u8*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC + 41)) = ((struct Obj03955 *)(((u8*)a1)))->fA;
    *(u8*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC + 42)) = ((struct Obj03955 *)(((u8*)a1)))->fB;
    *(u8*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC + 43)) = ((struct Obj03955 *)(((u8*)a1)))->fC;
    *(u8*)(((u8*)a0 + ((struct Obj00554 *)(((u8*)a0)))->f1AC * 20 + 44)) = ((struct Obj03955 *)(((u8*)a1)))->fD;
    ((struct Obj00554 *)(((u8*)a0)))->f1AC = ((struct Obj00554 *)(((u8*)a0)))->f1AC + 1;
}


/*
 * note: bubble sort of 0x14-byte records by u32 key (descending). Counters and bound are int and are
 *   declared and assigned separately (int i; int n; int j; n = ...; i = 0;): that order puts n in lr and i
 *   in ip and keeps n - 1 unhoisted.
 */
void func_021C17C4(u8 *p)
{
    int i;
    int n;
    int j;
    n = *(u8 *)(p + 0x1AC);
    i = 0;

    while (i < n - 1) {
        j = 0;
        while (j < n - 1 - i) {
            u8 *e = p + j * 0x14;
            if (*(u32 *)(e + 0x20) < *(u32 *)(e + 0x34)) {
                Rec_021C17C4 t = *(Rec_021C17C4 *)(e + 0x1C);
                *(Rec_021C17C4 *)(e + 0x1C) = *(Rec_021C17C4 *)(e + 0x30);
                *(Rec_021C17C4 *)(e + 0x30) = t;
            }
            j++;
        }
        i++;
    }
}

/*
 * lever: declare base before total, preserve both base stores, guard do-loop.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`base=p;` before `base=p+0x1c;`). Game code has no line table, so these
 * were stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 */
void func_021C1850(u8 *p)
{
    u8 *base;
    u32 total=func_021C1AD4(p);
    int count=p[0x1ac];
    int i=0;
    int remaining;
    if (count>0) {
        base=p+0x1c;
        do {
            u8 *record=base+i*20;
            record[8]=(((struct Obj14759 *)record)->f4*100)/total;
            i++;
        } while (i<count);
    }
    remaining=100-func_021C1AFC(p);
    i=0;
    while (remaining>0) {
        p[i*20+0x24]+=1;
        remaining--;
        i=(i+1)%count;
    }
}


void func_021C18C4(u8 *p)
{
    int i;
    int n;
    int sum;
    n = p[0x1AC];
    sum = 0;
    for (i = 0; i < n; i++) {
        ((struct Ent_021C18C4 *)(p + 0x1C))[i].start = sum;
        ((struct Ent_021C18C4 *)(p + 0x1C))[i].end = sum + ((struct Ent_021C18C4 *)(p + 0x1C))[i].len - 1;
        sum += ((struct Ent_021C18C4 *)(p + 0x1C))[i].len;
    }
}

/*
 * Callee B60/B4C full matched bodies explicitly return (u16); caller uses their halfword payloads.
 */
void func_021C18F8(u8 *p)
{
    struct Range range;
    int count=p[0x1ac];
    int k=0;
    int i;
    for(i=0;i<count;i++) {
        u8 *rec;
        u16 color,color2;
        int j;
        rec=func_021C1AB4(p,i);
        color=func_021C1B60(rec);
        color2=func_021C1B4C(rec);
        func_021C1B28(rec,&range.min,&range.max);
        range.x=((struct Obj00554 *)p)->f1B4;
        range.y=((struct Obj00554 *)p)->f1B6;
        range.z=((struct Obj00554 *)p)->f1B8+i*205;
        for(j=range.min;j<=range.max;j++) {
            u8 *q=p+k*10;
            ((struct Obj03377 *)q)->f418=color;
            ((struct Obj03377 *)q)->f412=range.x;
            ((struct Obj03377 *)q)->f414=range.y;
            ((struct Obj03377 *)q)->f416=range.z;
            q[0x41a]=i;
            ((struct Obj03377 *)q)->f422=color2;
            func_0207CA30((s16_021C18F8 *)&range.x,(s16_021C18F8 *)(p+0x1ba+j*6),(s16_021C18F8 *)(p+0x412+((u32)k+1)*10));
            q[0x424]=i;
            ((struct Obj03377 *)q)->f42C=color2;
            func_0207CA30((s16_021C18F8 *)&range.x,(s16_021C18F8 *)(p+0x1ba+((j+1)%100)*6),(s16_021C18F8 *)(p+0x412+((u32)k+2)*10));
            q[0x42e]=i;
            k+=3;
        }
    }
}


void func_021C1A58(Rec_021C1A58 *p, u32 v)
{
    p->a = v;
}


/*
 * Stores a constant 1 at offset 0x14 and the argument at offset 0x18.
 * Reached only from the tail-call veneer func_021C118C.
 *
 * Addresses are Black-image addresses.
 */
void func_021C1A5C(Rec_021C1A5C *p, u32 v)
{
    p->flag = 1;
    p->value = v;
}


/*
 * A const source pointer fixes the load order (y, x, z).
 */
void func_021C1A64(u8 *p, const struct Pos *v)
{
    s16_021C1A64 z = v->z;
    s16_021C1A64 y = v->y;
    s16_021C1A64 x = v->x;
    *(s16_021C1A64 *)(p + 0x1B4) = x;
    *(s16_021C1A64 *)(p + 0x1B6) = y;
    *(s16_021C1A64 *)(p + 0x1B8) = z;
}


u8 func_021C1A84(u8 *p, u8 key)
{
    int i;
    int n;
    u8 v;
    n = p[0x1AC];
    for (i = 0; i < n; i++) {
        v = p[0x1C + i * 0x14];
        if (v == key) {
            return i;
        }
    }
    return 0;
}


void *func_021C1AB4(void *p, u32 n)
{
    return (char *)p + 0x1c + n * 0x14;
}


void *func_021C1AC0(u8 *p, u8 key)
{
    return func_021C1AB4(p, func_021C1A84(p, key));
}


int func_021C1AD4(u8 *p)
{
    int i;
    int n;
    int sum;
    n = p[0x1AC];
    sum = 0;
    for (i = 0; i < n; i++)
        sum += *(int *)(p + i * 0x14 + 0x20);
    return sum;
}


/*
 * Addresses are Black-image addresses.
 */
int func_021C1AFC(u8 *p)
{
    int i;
    int n;
    int sum;
    n = p[0x1AC];
    sum = 0;
    for (i = 0; i < n; i++)
        sum += p[i * 0x14 + 0x24];
    return sum;
}


void func_021C1B28(u8 *p, u8 *a, u8 *b)
{
    u8 x = (u8)(float)p[9];
    u8 y = (u8)(float)p[10];
    *a = x;
    *b = y;
}
