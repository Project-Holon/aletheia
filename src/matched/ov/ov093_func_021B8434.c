/*
 * function: func_021B8434
 * address:  0x021B8434
 * packet:   pkt_ov093_021B8434
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D4270  0x021D4270  thumb  ov093
 *   func_021B8548  0x021B8548  thumb  ov093
 *   func_021BAB9C  0x021BAB9C  thumb  ov093
 *   func_021BABDC  0x021BABDC  thumb  ov093
 *   func_021CD97C  0x021CD97C  thumb  ov093
 *   func_021B8564  0x021B8564  thumb  ov093
 *   func_021CDD94  0x021CDD94  thumb  ov093
 *   func_021E908C  0x021E908C  thumb  ov093
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
extern void func_021B8548(u8 *);
extern int func_021BAB9C(int);
extern void func_021BABDC(int, u8 *);
extern u8 func_021CD97C(int);
extern int func_021B8564(u8 *);
extern void func_021CDD94(int, u8 *);
extern void func_021E908C(int);

int func_021B8434(u8 *p)
{
    int r, i;
    if (((B *)p)->a == 0) {
        if (func_021D4270()) {
            ((B *)p)->a = 1;
            func_021B8548(p);
        }
    } else if (((B *)p)->b != 0) {
        return 1;
    }
    r = func_021BAB9C(*(int *)(p + 8));
    if (r) {
        func_021BABDC(*(int *)(p + 8), p + 0x448);
    }
    for (i = 0; i < 4; i++) {
        if (*(int *)(p + i * 4 + 0x10) != 0 && p[i + 0xc4] == 0) {
            p[i + 0xc4] = func_021CD97C(*(int *)(p + i * 4 + 0x10));
        }
    }
    if (func_021B8564(p)) {
        func_021CDD94(*(int *)(p + p[0x46c] * 4 + 0x10), p + 0x448);
        r = 1;
    }
    func_021E908C(*(int *)(p + 4));
    return r;
}
