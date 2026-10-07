/*
 * file:     pokemontrade_3d_p09.c
 * unit:     yes
 * function: func_021E3208, func_021E3230, func_021E324C, func_021E32C4, func_021E32EC, func_021E33FC, func_021E35A0, func_021E36A8, func_021E36C8, func_021E36D8, func_021E3700, func_021E3730, func_021E3744, func_021E3758
 * address:  0x021E3208
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   tbl_021E7AC4   0x021E7AC4  data   ov119  a4
 *   func_02047E88 0x02047E88 arm
 *   func_02048A18 0x02048A18 arm
 *   func_0204779C 0x0204779C arm
 *   func_020477A4 0x020477A4 arm
 *   d_021E7B3C 0x021E7B3C data a4
 *   func_020480E4  0x020480E4  arm
 *   func_02047910  0x02047910  arm
 *   func_02047964  0x02047964  arm
 *   func_02048AD0  0x02048AD0  arm
 *   func_020479D8  0x020479D8  arm
 *   func_02051534  0x02051534  arm
 *   func_02051574  0x02051574  arm
 *   func_02047A60  0x02047A60  arm
 *   func_02011590  0x02011590  thumb
 *   d_021E7AC8  0x021E7AC8  data a4
 *   d_021E8144  0x021E8144  data a4
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017F00 0x02017F00 thumb
 *   func_02015F04 0x02015F04 thumb
 *   func_02015F14 0x02015F14 thumb
 *   func_02015C78 0x02015C78 thumb
 *   _fgr 0x0209BBB0 arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   _fflt 0x0209BDBC arm
 *   d_021E7B9C 0x021E7B9C data a4
 *   func_0201ADE4 0x0201ADE4 thumb
 *   func_0201AE1C 0x0201AE1C thumb
 *   func_0201AE14 0x0201AE14 thumb
 *   func_0215642C 0x0215642C thumb ov009
 *   func_02017270 0x02017270 thumb
 *   func_020173B4 0x020173B4 thumb
 *   func_02015CAC 0x02015CAC thumb
 *   func_02015FF0 0x02015FF0 thumb
 *   data_021E7B00 0x021E7B00 data a4
 *   data_021E7B0C 0x021E7B0C data a4
 *   func_02015EA0  0x02015EA0  thumb
 *   func_02015BA4  0x02015BA4  thumb
 *   d_021E8190 0x021E8190 data a2
 *   d_021E8178 0x021E8178 data a4
 *   d_021E8168 0x021E8168 data a4
 */
#include "../../matched/include/Obj03779.h"
#include "../../matched/include/Obj00001.h"
#include "../../matched/include/Obj10375.h"
#include "../../matched/include/Obj00907.h"

#define F32_TO_FX32(f) ((int)(((f) > 0) ? ((f) * 4096.0f + 0.5f) : ((f) * 4096.0f - 0.5f)))
#define REG_VTX_16 (*(vu32 *)0x0400048C)
struct G3dSys;
struct Ctx;
struct Light;
struct Arg;
struct IcaAnime;
struct Personal;
typedef unsigned int u32;

typedef void (*Fn)(void *);

typedef unsigned short u16;

typedef struct {int a,b,c; u16 d,e;} Entry_021E324C;

typedef unsigned char  u8;

typedef struct {
    void (*fn)(char *p, void *out);
    int unused;
} Handler;

typedef struct {
    int x;
    int amount;
} Cfg;

typedef struct {
    char pad00[0x90];
    int *a90;           /* 0x090 */
    int *a94;           /* 0x094 */
    int *a98;           /* 0x098 */
    int *a9C;           /* 0x09C */
    int pada0[2];       /* 0x0A0 */
    int aA8;            /* 0x0A8 */
    int aAC;            /* 0x0AC */
} Sub;

typedef signed int     s32;

typedef struct {
    int a;
    int b;
    int c;
    int d;
    float x;
    float y;
    float z;
} Entry_021E33FC;

typedef struct {
    int x;
    int y;
    int z;
} Vec_021E33FC;

typedef signed short   s16_021E33FC;

typedef struct { int x, y, z; } Vec_021E35A0;

typedef struct { u32 v[4]; } Table;

typedef struct {
    char pad0[0x5f4];
    u16 heap;
    char pad5f6[0x840 - 0x5f6];
    void *res;
    void *obj[4];
    char pad854[0x118c - 0x854];
    int mode;
} Work;

typedef short s16_021E3700;

typedef s16_021E3700 fx16;

typedef volatile u32 vu32;

extern u16 func_02047E88(void *,const Entry_021E324C *);
extern u32 func_02048A18(u8 *a0, int i);
extern int func_0204779C(int *p);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern void func_020480E4(struct Ctx *c, u32 i);
extern int func_02047910(void *a, int idx, int amount);
extern void func_02047964(void);
extern void func_02048AD0(struct Light *l);
extern void func_020479D8(void);
extern int func_02051534(void);
extern int func_02051574(void);
extern void func_02047A60(void *a0, struct Arg *a1);
extern u32 func_02011590(struct IcaAnime *p, s32 v);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u8 func_02017F00(void *p);
extern u16 func_02015F04(void *p);
extern s16_021E33FC func_02015F14(void *p);
extern void func_02015C78(void *p, u32 *src);
extern void *func_0201ADE4(unsigned int species, int form, unsigned int heap);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *h);
extern void func_0215642C(int);
extern void *func_02017270(void *a0, void *a1, u32 a2, u32 a3, u32 a4, u32 a5);
extern int func_020173B4(int a0);
extern void func_02015CAC(void *p, u32 *src);
extern void func_02015FF0(char *p, int v);
extern void func_02015EA0(void *p);
extern void func_02015BA4(void *sys, void *obj);
void func_021E3208(void *p, int a);
void func_021E3230(void *p);
void func_021E324C(char *p,int n);
void func_021E32C4(char *p);
void func_021E32EC(char *p);
void func_021E33FC(void *p0, int *dir, int p2, void *mon);
void func_021E35A0(Work *p, int idx, int side, void *mon, int flag);
void func_021E36A8(void *a, int b, int c, void *d, int e, int f);
void func_021E36C8(void *a, int b, int c, void *d, int e);
void func_021E36D8(void *p, int idx);
void func_021E3700(int n);
void func_021E3730(int n);
void func_021E3744(int n);
void func_021E3758(unsigned short *p, int x, int y, int colour);
extern Fn tbl_021E7AC4[];
extern const Entry_021E324C d_021E7B3C[];
extern const Handler d_021E7AC8[];
extern Cfg d_021E8144;
extern Entry_021E33FC d_021E7B9C[4];
extern const Vec_021E35A0 data_021E7B00;
extern const Table data_021E7B0C;
extern u32 d_021E8178[];
extern u32 d_021E8168[];


/*
 * Addresses are Black-image addresses.
 */
void func_021E3208(void *p, int a)
{
    func_021E324C(p, a);
    if (((struct Obj03779 *)p)->f109C != 0xFFFFFFFF) {
        tbl_021E7AC4[*(u32 *)((char *)p + 0x109C) * 2](p);
    }
}


void func_021E3230(void *p)
{
    if (((struct Obj00001 *)p)->f109C != 0xFFFFFFFF) {
        func_021E32C4(p);
        ((struct Obj00001 *)p)->f109C = 0xFFFFFFFF;
    }
}

void func_021E324C(char *p,int n) {
    void *q;
    int i,count;
    if(d_021E7B3C[n].d) ((struct Obj03779 *)p)->f824=func_02047E88(((struct Obj03779 *)p)->f820,&d_021E7B3C[n]);
    else ((struct Obj03779 *)p)->f824=0xffff;
    if(((struct Obj03779 *)p)->f824!=0xffff) {
        q=(void *)func_02048A18(((struct Obj03779 *)p)->f820,((struct Obj03779 *)p)->f824);
        count=func_0204779C(q);
        for(i=0;i<count;i++) func_020477A4(q,(u16)i);
    }
    *(int *)&((struct Obj03779 *)p)->f109C=n;
}


void func_021E32C4(char *p)
{
    u16 v;

    v = ((struct Obj10375 *)p)->f824;
    if (v != 0xFFFF)
        func_020480E4(((struct Obj10375 *)p)->f820, v);
    ((struct Obj10375 *)p)->f824 = 0xFFFF;
}


void func_021E32EC(char *p)
{
    char buf[0x3C];
    void *q;
    int n;
    int i;
    int idx;

    idx = ((struct Obj00907 *)p)->f109C;
    if (idx == -1)
        return;
    if (d_021E7AC8[idx].fn != 0)
        d_021E7AC8[idx].fn(p, buf);
    if (((struct Obj00907 *)p)->f824 != 0xFFFF) {
        q = (void *)func_02048A18(((struct Obj00907 *)p)->f820, ((struct Obj00907 *)p)->f824);
        n = func_0204779C(q);
        for (i = 0; i < n; i++)
            func_02047910(q, (u16)i, d_021E8144.amount);
    }
    func_02047964();
    func_02048AD0(((struct Obj00907 *)p)->f83C);
    func_020479D8();
    if (((struct Obj00907 *)p)->fC != 0) {
        func_02051534();
        func_02051574();
    }
    if (((struct Obj00907 *)p)->f824 != 0xFFFF)
        func_02047A60((void *)func_02048A18(((struct Obj00907 *)p)->f820, ((struct Obj00907 *)p)->f824), (struct Arg *)buf);
    if (*(Sub * *)&((struct Obj00907 *)p)->fC != 0) {
        if ((*(Sub * *)&((struct Obj00907 *)p)->fC)->a90 != 0) {
            if ((*(Sub * *)&((struct Obj00907 *)p)->fC)->aA8 == 0)
                (*(Sub * *)&((struct Obj00907 *)p)->fC)->aA8 = func_02011590((struct IcaAnime *)((*(Sub * *)&((struct Obj00907 *)p)->fC)->a90), d_021E8144.amount);
            if ((*(Sub * *)&((struct Obj00907 *)p)->fC)->aAC == 0)
                (*(Sub * *)&((struct Obj00907 *)p)->fC)->aAC = func_02011590((struct IcaAnime *)((*(Sub * *)&((struct Obj00907 *)p)->fC)->a94), d_021E8144.amount);
        }
        if ((*(Sub * *)&((struct Obj00907 *)p)->fC)->a9C != 0)
            func_02011590((struct IcaAnime *)((*(Sub * *)&((struct Obj00907 *)p)->fC)->a9C), d_021E8144.amount);
        if ((*(Sub * *)&((struct Obj00907 *)p)->fC)->a98 != 0)
            func_02011590((struct IcaAnime *)((*(Sub * *)&((struct Obj00907 *)p)->fC)->a98), d_021E8144.amount);
    }
}


/*
 * 2026-10-03 (wave B3): all concrete bytes match. The one open relocation is
 * the call to func_02015F04 (unlabelled arm9 Thumb leaf). Its witness is
 * filed as src/matched/arm9/func_02015F04.c (EXACT); once the integrator
 * seeds 0x02015F04 in layout/function_starts.txt this re-verifies as EXACT.
 * The empty-then if/else on *dir gives the original `bge; b` shape.
 */
void func_021E33FC(void *p0, int *dir, int p2, void *mon)
{
    Vec_021E33FC v;
    int flag = 0;
    int a, b, c;
    int found;
    u8 i;
    float f;

    a = func_02017E1C(mon, 5, 0);
    b = func_02017E1C(mon, 0x6f, 0);
    c = func_02017F00(mon);
    if (p2 == 0)
        flag = 1;
    found = 0;
    for (i = 0; i < 4; i++) {
        if (a == d_021E7B9C[i].a && b == d_021E7B9C[i].b
            && (d_021E7B9C[i].c == 3 || c == d_021E7B9C[i].c)
            && (d_021E7B9C[i].d == 2 || flag == d_021E7B9C[i].d)) {
            v.x = F32_TO_FX32(d_021E7B9C[i].x);
            if (*dir >= 0)
                v.x = -v.x;
            v.y = F32_TO_FX32(d_021E7B9C[i].y);
            v.z = F32_TO_FX32(d_021E7B9C[i].z);
            found = 1;
            break;
        }
    }
    if (!found) {
        func_02015F04(p0);
        c = func_02015F14(p0);
        if (*dir < 0)
            f = 0.33f * (float)c;
        else
            f = 0.33f * (float)-c;
        v.x = F32_TO_FX32(f);
        v.y = 0;
        v.z = 0;
    }
    func_02015C78(p0, (u32 *)(&v));
}

void func_021E35A0(Work *p, int idx, int side, void *mon, int flag)
{
    Vec_021E35A0 v = data_021E7B00;
    Table t = data_021E7B0C;
    if (flag) {
        u16 species = func_02017E1C(mon, 5, 0);
        u16 form = func_02017E1C(mon, 0x6f, 0);
        void *h = func_0201ADE4(species, form, p->heap);
        u32 r = func_0201AE1C(h, 0x22);
        func_0201AE14(h);
        if (r == 0)
            v.x = -v.x;
    }
    if (p->mode == 2)
        func_0215642C(1);
    if (side)
        p->obj[idx] = func_02017270(p->res, mon, 0, t.v[idx], -0x1C000, 0);
    else
        p->obj[idx] = func_02017270(p->res, mon, 1, t.v[idx], -0x1C000, 0);
    if (p->mode == 2)
        func_0215642C(0);
    func_020173B4((int)p->obj[idx]);
    func_02015CAC(p->obj[idx], (u32 *)(&v));
    func_02015FF0(p->obj[idx], 1);
    func_021E33FC(p->obj[idx], (int *)(&v), side, mon);
}


void func_021E36A8(void *a, int b, int c, void *d, int e, int f)
{
    if (f != 0 && c == 0) {
        c = 1;
        e = 0;
    }
    func_021E35A0(a, b, c, d, e);
}


void func_021E36C8(void *a, int b, int c, void *d, int e)
{
    func_021E35A0(a, b, c, d, e);
}


/*
 * Teardown of one slot of the 0x844 vector: releases it through
 * func_02015EA0, hands (the shared 0x840 handle, the slot value) to
 * func_02015BA4, then clears the slot.
 *
 * Addresses are Black-image addresses.
 */
void func_021E36D8(void *p, int idx)
{
    u32 v = ((u32 *)((char *)p + 0x844))[idx];

    if (v != 0) {
        func_02015EA0((void *)v);
        func_02015BA4((void *)(*(u32 *)&((struct Obj00001 *)p)->f840), (void *)(((u32 *)((char *)p + 0x844))[idx]));
        ((u32 *)((char *)p + 0x844))[idx] = 0;
    }
}


static inline void G3_Vtx(fx16 x, fx16 y, fx16 z)
{
    REG_VTX_16 = (u32)(u16)x | ((u32)(u16)y << 16);
    REG_VTX_16 = (u32)(u16)z;
}


static fx16 d_021E8190[24];


/*
 * The vertex table is a non-const file static: as an extern (or a const
 * static) the allocator keeps n*3 in r1; as a writable file static it keeps
 * n*3 in r4 and the base in r3 like the original.
 */
void func_021E3700(int n)
{
    G3_Vtx(d_021E8190[n * 3], d_021E8190[n * 3 + 1], d_021E8190[n * 3 + 2]);
}


void func_021E3730(int n)
{
    *(u32 *)0x04000484 = d_021E8178[n];
}


void func_021E3744(int n)
{
    *(u32 *)0x04000488 = d_021E8168[n];
}

/*
 * extent: 126-byte body followed by two zero padding bytes at 0x021E37D6.
 */
void func_021E3758(unsigned short *p, int x, int y, int colour)
{
    int end;
    int col;
    int row;
    int start;
    int index;
    int shift;
    start = x * 5 + 2;
    row = y * 6 + 3;
    end = row + 3;
    for (; row < end; row++) {
        for (col = start; col < start + 3; col++) {
            index = col + row * 32;
            shift = (index % 4) * 4;
            p[index / 4] &= (unsigned short)~(15 << shift);
            p[index / 4] |= (unsigned short)(colour << shift);
        }
    }
}
