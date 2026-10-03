/*
 * function: func_021CBB34
 * address: 0x021CBB34
 * packet: pkt_ov093_021CBB34
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: A u16 mode homes its spill early; named u16 form avoids an
 * argument copy. Ternary count selection shares the flag read across
 * the preceding threshold branch and settles the register allocation.
 * symbols:
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021BA1A8 0x021BA1A8 thumb ov093
 *   func_021CBCF4 0x021CBCF4 thumb ov093
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_02019C90 0x02019C90 thumb
 *   func_021CBD48 0x021CBD48 thumb ov093
 *   func_021D62A8 0x021D62A8 thumb ov093
 *   func_020111BC 0x020111BC thumb
 *   func_021CBEA8 0x021CBEA8 thumb ov093
 *   FX_Div 0x0207C768 arm
 *   FX_Sqrt 0x0207C7B4 arm
 *   func_021D78AC 0x021D78AC thumb ov093
 *   _ffltu 0x0209BE04 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   _ll_mul 0x0209C054 arm
 *   _u32_div_f 0x0209C2B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed long long s64;
extern int func_021D59B4(u8 *p, int k);
struct QF;
struct Unk021D62A8;
extern int func_021BA1A8(char **p, int m);
extern u32 func_021CBCF4(u8 *p);
extern u16 func_021D5444(struct QF *p);
extern u32 func_02019C90(u16 a, u16 b, u32 k);
extern int func_021CBD48(u8 *, void *, void *, int);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern int func_020111BC(int);
extern int func_021CBEA8(u8 *p, int x);
extern int FX_Div(int, int);
extern int FX_Sqrt(int);
extern u32 func_021D78AC(u32);
int func_021CBB34(u8 *p, void *q, void *m, u16 mode, u8 *out, u8 *flag)
{
    u32 a, t;
    int rate, factor, v;
    u32 count, i;
    u16 species, form;
    *flag = 0;
    if (mode == 1) { *out = 3; return 1; }
    a = func_021D59B4((void *)m, 14) * 3;
    t = a - func_021D59B4((void *)m, 13) * 2;
    v = (int)(t != 0 ? 0.5f + (float)(t << 12) : (float)(t << 12) - 0.5f);
    if (func_021BA1A8(*(void **)(p + 4), 32)) {
        factor = func_021CBCF4(p);
        v = ((s64)v * factor + 0x800) >> 12;
    }
    species = func_021D5444((void *)m);
    form = func_021D59B4((void *)m, 19);
    v *= (u16)func_02019C90(species, form, 8);
    factor = func_021CBD48(p, q, (void *)m, mode);
    v = ((s64)v * factor + 0x800) >> 12;
    v = (u32)v / a;
    switch (func_021D62A8((void *)m)) {
    case 2: case 3: v = ((s64)v * 0x2800 + 0x800) >> 12; break;
    case 1: case 4: case 5: v = ((s64)v * 0x1800 + 0x800) >> 12; break;
    }
    rate = func_020111BC(v);
    *flag = func_021CBEA8(p, rate);
    if (rate >= 0xff000) { *out = *flag ? 1 : 3; return 1; }
    count = *flag ? 1 : 3;
    rate = FX_Div(0x10000000, FX_Sqrt(FX_Sqrt(FX_Div(0xff000, rate)))) >> 12;
    *out = 0;
    for (i = 0; i < count; i++) {
        if (func_021D78AC(0x10000) < (u32)rate) (*out)++;
        else return 0;
    }
    return 1;
}
