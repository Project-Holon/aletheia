/*
 * function: func_021B835C
 * address:  0x021B835C
 * packet:   pkt_ov093_021B835C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D4270  0x021D4270  thumb  ov093
 *   func_021B6818  0x021B6818  thumb  ov093
 *   func_021E8F20  0x021E8F20  thumb  ov093
 *   func_021CD95C  0x021CD95C  thumb  ov093
 *   func_021BAB40  0x021BAB40  thumb  ov093
 *   func_021B8434  0x021B8434  thumb  ov093
 *   func_021B84D8  0x021B84D8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad[0x473];
    u8 a : 1;
    u8 b : 1;
} B;

extern int func_021D4270(void);
extern int func_021B6818(int *);
extern int func_021E8F20(u8 *, int, u8 *, int, int);
extern void func_021CD95C(int, int);
extern void func_021BAB40(int);
extern int func_021B8434(u8 *);
extern int func_021B84D8(u8 *);

int func_021B835C(u8 *p, int *q)
{
    int r, t;
    if (func_021D4270()) {
        ((B *)p)->a = 1;
        return 1;
    }
    if (*q == 0) {
        r = func_021B6818(*(int **)p);
        t = func_021E8F20(p, *(int *)(p + p[0x46c] * 4 + 0x10), p + 0xc8, r, 0x13);
        *(int *)(p + 4) = t;
        func_021CD95C(*(int *)(p + p[0x46c] * 4 + 0x10), t);
        if (p[0x46e]) {
            *(u32 *)(p + 0x464) = (u32)func_021B8434;
            func_021BAB40(*(int *)(p + 8));
        } else {
            *(u32 *)(p + 0x464) = (u32)func_021B84D8;
        }
        *q = *q + 1;
    } else {
        return 1;
    }
    return 0;
}
