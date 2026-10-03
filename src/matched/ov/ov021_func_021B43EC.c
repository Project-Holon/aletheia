/*
 * function: func_021B43EC
 * address:  0x021B43EC
 * packet:   pkt_ov021_021B43EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds a 0x34-byte list template on the stack (layout as read by
 * func_0201FF30) and creates the list object from it.
 *
 * symbols:
 *   func_021B468C 0x021B468C thumb ov021
 *   func_021B4510 0x021B4510 thumb ov021
 *   func_021B45A0 0x021B45A0 thumb ov021
 *   func_0201F91C 0x0201F91C thumb
 *   func_0201FF30 0x0201FF30 thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    void *arr;
    void *cb04;
    void *cb08;
    u32 w0c;
    u16 count;
    u16 rows;
    u8 f14;
    u8 f15;
    u8 f16;
    u8 f17lo : 4;
    u8 f17hi : 4;
    u8 f18lo : 4;
    u8 f18hi : 4;
    u8 f19;
    u16 f1Alo : 3;
    u16 f1Amid : 4;
    u16 f1Apad : 2;
    u16 f1Amid2 : 6;
    u16 f1Atop : 1;
    void *w1c;
    u16 h20;
    u16 h22;
    u32 w24;
    void *w28;
    u32 w2c;
    u32 w30;
} Tmpl;

extern void func_021B468C(u32 a, u32 idx);
struct Slot;
extern void func_021B4510(u8 *p, int a, u8 b);
extern void func_021B45A0(u32 unused, int a, u8 b);
extern u32 func_0201F91C(struct Slot *s);
extern u32 func_0201FF30(Tmpl *t, u16 a, u16 b, u32 heap);

void func_021B43EC(char *w)
{
    Tmpl t;

    t.arr = *(void **)(w + 0x180);
    t.cb04 = (void *)func_021B468C;
    if (*(u8 *)(w + 0x162) == 0) {
        t.cb08 = (void *)func_021B4510;
    } else {
        t.cb08 = (void *)func_021B45A0;
    }
    t.w0c = *(u32 *)(w + 0x16C);
    t.count = func_0201F91C(*(void **)(w + 0x180));
    t.rows = 7;
    t.f14 = 0;
    t.f15 = 0;
    t.f16 = 0;
    t.f17lo = 8;
    t.f17hi = 0xC;
    t.f18lo = 0;
    t.f18hi = 0xD;
    t.f1Alo = 0;
    t.f1Amid = 0;
    t.f1Apad = 1;
    t.f1Amid2 = 0;
    t.f1Atop = 1;
    t.w1c = w;
    t.h20 = 0xC;
    t.h22 = 0x10;
    t.w24 = 0;
    t.w28 = w + 0x1A8;
    t.w2c = *(u32 *)(w + 0x1B0);
    t.w30 = *(u32 *)(w + 8);
    *(u32 *)(w + 0x1A4) = func_0201FF30(&t, 0, 0, *(u16 *)(w + 4));
}
