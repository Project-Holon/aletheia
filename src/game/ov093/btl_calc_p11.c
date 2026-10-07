/*
 * file:     btl_calc_p11.c
 * unit:     yes
 * function: func_021D77C4, func_021D77E8, func_021D780C, func_021D7840, func_021D787C, func_021D7894, func_021D78AC, func_021D78E4
 * address:  0x021D77C4
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
 *   d_021F6360 0x021F6360 data a4
 *   d_021F3AB8 0x021F3AB8 data a1
 *   func_02030734 0x02030734 arm
 *   d_021F6368 0x021F6368 data a4
 *   func_020307B0 0x020307B0 arm
 *   data_021F6360  0x021F6360  data  ov093
 *   _ull_mul       0x0209C054  arm
 *   d_021F0448 0x021F0448 data a1
 *   _u32_div_f 0x0209C2B0 arm
 */
#include "../../matched/include/G_Tbl.h"
#include "../../matched/include/G__anon_State.h"
#include "../../matched/include/G_Unk021F6360.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct {
    u32 count;
    u16 keys[0x60];
    u32 vals[0x60];
    u32 a[0x60];
    u32 b[0x60];
    u8 c[0x60];
} Tbl_021D77C4;

typedef struct { unsigned int count; unsigned short keys[0x60]; int vals[0x60]; int a[0x60]; int b[0x60]; unsigned char c[0x60]; } Tbl_021D77E8;

typedef struct { unsigned int count; unsigned short keys[0x60]; int vals[0x60]; int a[0x60]; int b[0x60]; unsigned char c[0x60]; } Tbl_021D780C;

typedef struct { unsigned int v[6]; } Words;

typedef struct { unsigned int f0; void *f4; Words words; } State;

typedef unsigned long long u64;

extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
extern u32 func_020307B0(void *p);
extern unsigned int _u32_div_f(unsigned int, unsigned int);
u32 func_021D77C4(Tbl_021D77C4 *p, int key);
int func_021D77E8(Tbl_021D77E8 *p, int key);
int func_021D780C(Tbl_021D780C *p, int i, int v);
void func_021D7840(const Words *p, unsigned int heap);
void func_021D787C(const Words *p);
void func_021D7894(void);
u32 func_021D78AC(u32 range);
unsigned short func_021D78E4(unsigned short a, int i);
extern struct Tbl_021D77C4 g_021F3ECC;
extern State d_021F6360;
extern const unsigned char d_021F3AB8[];
extern Words d_021F6368;
extern struct Unk021F6360 data_021F6360;
extern unsigned char d_021F0448[][2];


u32 func_021D77C4(Tbl_021D77C4 *p, int key)
{
    u32 i;
    for (i = p->count; i < 0x60; i++) {
        if (p->keys[i] == 0) break;
        if (key == p->keys[i]) break;
    }
    if (i >= 0x60) i = 0;
    return i;
}

int func_021D77E8(Tbl_021D77E8 *p, int key) { unsigned int i; for (i=p->count; i<0x60 && p->keys[i]!=0; i++) { if(key==p->keys[i]) return i; } return -1; }

int func_021D780C(Tbl_021D780C *p, int i, int v) { int hi = p->a[i]; if (hi || p->b[i]) { if (p->b[i] > v) v=p->b[i]; if (hi < v) v=hi; } return v; }

void func_021D7840(const Words *p, unsigned int heap) { d_021F6360.f4=func_02030734(heap,0x460,1,(const char *)d_021F3AB8,0x50); d_021F6360.words=*p; }

void func_021D787C(const Words *p) { d_021F6368 = *p; }

void func_021D7894(void) { if (d_021F6360.f4) { func_020307B0(d_021F6360.f4); d_021F6360.f4 = 0; } }


u32 func_021D78AC(u32 range)
{
    struct Unk021F6360 *p = &data_021F6360;
    u32 v;

    p->seed = p->mul * p->seed + p->add;
    if (range == 0) {
        v = (u32)(p->seed >> 32);
    } else {
        v = (u32)(((p->seed >> 32) * range) >> 32);
    }
    return v;
}

unsigned short func_021D78E4(unsigned short a, int i) { return _u32_div_f((unsigned short)(a*d_021F0448[i][0]), d_021F0448[i][1]); }
