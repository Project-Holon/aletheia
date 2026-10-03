/*
 * function: func_021C58CC
 * address:  0x021C58CC
 * packet:   pkt_ov021_021C58CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200C468 0x0200C468 thumb
 *   func_0200C464 0x0200C464 thumb
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F878 0x0201F878 thumb
 *   func_021C5880 0x021C5880 thumb ov021
 *   func_021C576C 0x021C576C thumb ov021
 *   func_0201FF30 0x0201FF30 thumb
 *   d_021DAA80    0x021DAA80 data  a4
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
    u8 f14[8];
    void *w1c;
    u16 h20;
    u16 h22;
    u32 w24;
    void *w28;
    u32 w2c;
    u32 w30;
} Tmpl;

extern const Tmpl d_021DAA80;

extern u16 func_0200C468(const u8 *a);
extern u8 func_0200C464(void *a, u8 i);
extern void *func_0201F81C(int n, u32 heap);
extern void func_0201F878(void *, u32, int, int, u32);
extern void func_021C5880(u16 *a, u16 *b, u16 c);
extern void func_021C576C(void *a);
extern void *func_0201FF30(Tmpl *t, u16 a, u16 b, u32 heap);

void func_021C58CC(char *p, u16 a, u16 b, u32 heap)
{
    Tmpl t;
    u32 n;
    u32 i;

    n = func_0200C468(*(void **)(p + 0x20));
    *(void **)p = func_0201F81C(n, heap);
    for (i = 0; i < n; i++) {
        u8 v = func_0200C464(*(void **)(p + 0x20), i);
        func_0201F878(*(void **)p, *(u32 *)(p + 0x38), v, v, heap);
    }
    while (b + a >= n) {
        if (b != 0) {
            b--;
        } else if (a != 0) {
            a--;
        }
    }
    func_021C5880(&a, &b, n);
    t = d_021DAA80;
    t.arr = *(void **)p;
    t.count = n;
    t.cb04 = (void *)func_021C576C;
    t.cb08 = 0;
    t.w0c = *(u32 *)(p + 8);
    t.w1c = p;
    t.w24 = *(u32 *)(p + 0x38);
    t.w28 = p + 0x10;
    t.w2c = *(u32 *)(p + 0xC);
    t.w30 = *(u32 *)(p + 0x3C);
    *(void **)(p + 4) = func_0201FF30(&t, a, b, heap);
}
