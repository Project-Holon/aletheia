/*
 * function: ov208_func_021C569C
 * address:  0x021C569C
 * packet:   pkt_ov208_021C569C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BC3C0  0x021BC3C0  thumb
 *   func_021BC3A4  0x021BC3A4  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200D288  0x0200D288  thumb
 *   ov208_func_021C5128  0x021C5128  thumb
 *   func_021C80AC  0x021C80AC  thumb
 *   func_02015C48  0x02015C48  thumb
 *   func_02015EA0  0x02015EA0  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     fx32;

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} Vec;

struct Ov208Mdl {
    u32 obj;
    u32 f4;
    u8  pos[0x3c];
};

extern u16  func_021BC3C0(int key);
extern int  func_021BC3A4(int key);
extern void *func_0200CA1C(int a);
extern u32  func_0200D288(void *p, u32 v);
extern void ov208_func_021C5128(struct Ov208Mdl *m, u32 heap, u32 sys, u32 species, u32 a4,
                                u32 a5, u32 a6, u32 a7, u32 a8, u32 a9);
extern void func_021C80AC(struct Ov208Mdl *m, int k, Vec *v);
extern void func_02015C48(u32 obj, Vec *v);
extern void func_02015EA0(u32 obj);

#define W(o) (*(u32 *)(p + (o)))
#define MDL(i) ((struct Ov208Mdl *)(p + 0xc) + (i))

void ov208_func_021C569C(u16 *heap, u8 *p, int key, int a, int b, int pose, u16 idx)
{
    Vec v;
    u16 species;
    u32 form;
    u32 f152;
    u32 f153;
    u32 extra;

    extra = 0;
    species = func_021BC3C0(key);
    form = *(u16 *)(p + idx * 16 + 0x154);
    f152 = *(p + idx * 16 + 0x152);
    f153 = *(p + idx * 16 + 0x153);
    if (species == 0x147)
        extra = func_0200D288(func_0200CA1C(func_021BC3A4(key)), extra);
    if (a != 4) {
        ov208_func_021C5128(MDL(a), *heap, W(8), species, form, f152, f153, 0, 0, extra);
        func_021C80AC(MDL(a), pose, &v);
        func_02015C48(MDL(a)->obj, &v);
        if (W(0x124) == 0)
            func_02015EA0(MDL(a)->obj);
    }
    if (b != 4) {
        ov208_func_021C5128(MDL(b), *heap, W(8), species, form, f152, f153, 0, 1, extra);
        func_021C80AC(MDL(b), pose, &v);
        func_02015C48(MDL(b)->obj, &v);
        if (W(0x124) != 0)
            func_02015EA0(MDL(b)->obj);
    }
}
