/*
 * function: func_021F18E0
 * address:  0x021F18E0
 * packet:   pkt_ov032_021F18E0
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F18E0 0x021F18E0 thumb
 *   func_021F1930 0x021F1930 thumb
 *   func_021F05E8 0x021F05E8 thumb
 *   func_020311B8 0x020311B8 arm
 *   func_02031290 0x02031290 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02045838 0x02045838 arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021F1930(void *task, u8 *s);
extern void func_021F05E8(char *p, int a, int b);
extern void *func_020311B8(u32 a, void *fn, u32 sz, u32 a3);
struct S02030FB4;
extern void *func_02031290(struct S02030FB4 *p);
extern void func_02082BCC(void *p, int v, int n);
extern void func_02045838(u32 a, u32 b);

void func_021F18E0(char *p, u32 a, int *c)
{
    u8 *r;

    r = func_02031290(func_020311B8(*(u32 *)(p + 0xa0), (void *)func_021F1930, 0x10, 0));
    func_02082BCC(r, 0, 0x10);
    func_02045838(*(u32 *)(p + 0x120), a);
    *(char **)(r + 8) = p;
    r[1] = 0x5a;
    func_021F05E8(p, 4, 2);
    *(int **)(r + 0xc) = c;
    (*c)++;
}
