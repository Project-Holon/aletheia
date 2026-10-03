/*
 * function: func_021BDC08
 * address: 0x021BDC08
 * packet: pkt_ov209_021BDC08
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B100 0x0204B100 arm
 *   func_021C940C 0x021C940C thumb ov212
 *   func_0204BA20 0x0204BA20 arm
 *   func_021BD8D8 0x021BD8D8 thumb ov209
 *   func_021BD890 0x021BD890 thumb ov209
 *   func_0200CA54 0x0200CA54 thumb
 *   func_0200CA38 0x0200CA38 thumb
 *   func_02012BF8 0x02012BF8 thumb
 *   d_021BE9F0 0x021BE9F0 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Template { u32 w0, w4, w8, wC, w10; u16 h14, h16; } Template;
extern const Template d_021BE9F0[10];
struct Actor;
struct Bank;
struct Blk37;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void *func_021C940C(void *, const Template *, u32);
extern void func_0204BA20(struct Actor *a, u32 v);
extern void func_021BD8D8(char *p, u32 idx, u32 value);
extern void func_021BD890(char *, int, int);
extern u32 func_0200CA54(struct Blk37 *p);
extern u32 func_0200CA38(struct Blk37 *p);
extern int func_02012BF8(int, int);
void func_021BDC08(char *p)
{
    unsigned i;
    Template t;
    *(void **)(p + 0xa70) = func_0204B100(60, 0, 0x6b);
    for (i = 0; i < 60; i++)
        *(unsigned *)(p + i * 4 + 0xa74) = 0;
    for (i = 0; i <= 9; i++) {
        t = d_021BE9F0[i];
        t.w8 = *(u32 *)(p + t.w8 * 4 + 0xb64);
        t.wC = *(u32 *)(p + t.wC * 4 + 0xbf4);
        t.w10 = *(u32 *)(p + t.w10 * 4 + 0xc0c);
        *(void **)(p + i * 4 + 0xa74) = func_021C940C(*(void **)(p + 0xa70), &t, 0x6b);
        func_0204BA20(*(void **)(p + i * 4 + 0xa74), 0);
    }
    if (*(u16 *)(*(char **)p + 10) <= 7) {
        func_021BD8D8(p, 0, 0);
        func_021BD8D8(p, 1, 0);
    }
    if (func_0200CA54(*(void **)(*(char **)p + 4)) == 0)
        func_021BD8D8(p, 9, 0);
    if (func_0200CA38(*(void **)(*(char **)p + 4)) == 0)
        func_021BD8D8(p, 8, 0);
    if (*(u16 *)(*(char **)p + 8) == 1) {
        func_021BD8D8(p, 8, 0);
        func_021BD8D8(p, 5, 0);
    } else if (func_02012BF8(**(int **)p, 15) == 1)
        func_021BD890(p, 5, 7);
}
