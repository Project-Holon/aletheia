/*
 * function: func_021B7A64
 * address:  0x021B7A64
 * packet:   pkt_ov067_021B7A64
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B7B7C  0x021B7B7C  thumb  ov067
 *   func_021B7BE0  0x021B7BE0  thumb  ov067
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_021B9344  0x021B9344  thumb  ov067
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct S {
    u8 pad00[0x34];
    u32 f34;
    u8 pad38[0x4e - 0x38];
    u16 f4e;
} S;

extern void func_021B7B7C(S *p);
extern void func_021B7BE0(struct S *p, int a1);
extern int func_0201C6B4(int a);
extern void func_021B9344(S *p);

int func_021B7A64(S *p)
{
    switch (p->f4e) {
    case 0:
        func_021B7B7C(p);
        func_021B7BE0(p, 0);
        p->f4e = p->f4e + 1;
        break;
    case 1:
        if (func_0201C6B4(p->f34) == 1) {
            p->f4e = 0;
            return 0;
        }
        break;
    }
    func_021B9344(p);
    return 1;
}
