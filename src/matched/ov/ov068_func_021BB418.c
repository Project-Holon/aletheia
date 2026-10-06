/*
 * function: func_021BB418
 * address:  0x021BB418
 * packet:   pkt_ov068_021BB418
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA9E0  0x021BA9E0  thumb  ov068
 *   func_021BB0D0  0x021BB0D0  thumb  ov068
 *   func_021BAE90  0x021BAE90  thumb  ov068
 *   func_02040588  0x02040588  arm
 *   func_021BAEBC  0x021BAEBC  thumb  ov068
 *   func_021BB138  0x021BB138  thumb  ov068
 *   func_021BB4A4  0x021BB4A4  thumb  ov068
 *   func_021BB4D4  0x021BB4D4  thumb  ov068
 *   func_021BAE28  0x021BAE28  thumb  ov068
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
} Blk;

extern void func_021BA9E0(u8 *p, Blk *out);
extern u32  func_021BB0D0(Blk *b);
extern void func_021BAE90(void *p, u32 value);
extern void func_02040588(u32 which, unsigned char enable);
extern u16  func_021BAEBC(u8 *p);
extern void func_021BB138(void *p, int v);
extern void func_021BB4A4(void *a, u32 b, u8 *p);
extern void func_021BB4D4(void *a, u32 b, u8 *p);
extern void func_021BAE28(u8 *p);

void func_021BB418(void *a0, u32 *st, u8 *base)
{
    Blk b;
    u16 r;

    switch (*st) {
    case 0:
        func_021BA9E0(base + 0x148, &b);
        func_021BAE90(base + 0x1d8, func_021BB0D0(&b));
        func_02040588(4, 0);
        *st = 1;
        break;
    case 1:
        r = func_021BAEBC(base + 0x1d8);
        switch (r) {
        case 1:
            *st = 2;
            break;
        case 2:
            *st = 3;
            break;
        }
        break;
    case 2:
        func_021BB138(a0, (int)func_021BB4D4);
        break;
    case 3:
        func_021BB138(a0, (int)func_021BB4A4);
        break;
    }
    func_021BAE28(base + 0x1d8);
}
