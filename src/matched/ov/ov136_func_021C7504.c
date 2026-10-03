/*
 * function: func_021C7504
 * address:  0x021C7504
 * packet:   pkt_ov136_021C7504
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202138C  0x0202138C  thumb
 *   func_02031348  0x02031348  arm
 *   func_021C3CC0  0x021C3CC0  thumb
 *   d_021C7D5C 0x021C7D5C data a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bf7 {
    u8 v : 7;
    u8 w : 1;
};
extern const u8 d_021C7D5C[];
extern u8 func_0202138C(u16 v);
extern void *func_021C3CC0(void *a, unsigned b, unsigned c, unsigned d, unsigned heap);
extern void func_02031348(void *, u32, const void *, void *);
int func_021C7504(u8 *p)
{
    *(void **)(p + 0x10) = (void *)func_021C3CC0(**(void ***)(p + 4), 2, ((struct Bf7 *)(p + 0x21))->v, func_0202138C(*(u16 *)(p + 0x22)), 0x65);
    func_02031348(*(void **)(p + 0x30), (u32)-1, d_021C7D5C, *(void **)(p + 0x10));
    return 0;
}
