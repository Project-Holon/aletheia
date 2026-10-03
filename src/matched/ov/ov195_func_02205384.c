/*
 * function: func_02205384
 * address:  0x02205384
 * packet:   pkt_02205384
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0220549C 0x0220549C thumb ov195
 *   func_02205620 0x02205620 thumb ov195
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CD10 0x0201CD10 thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0220549C(char *, int);
extern u32 func_02205620(u32, u32, u32, u32, u32, u32, u32);
extern signed char func_02012FFC(void);
extern u32 func_0201CD10(u32, int, int, u32, u32, u32, u32, int, u16, int, u32);

void func_02205384(char *a, u32 b, u32 c, u32 d, u32 k0, u32 v0, u32 k1, u32 v1)
{
    func_0220549C(a, 0xf);
    *(u32 *)(a + 0x80) = func_02205620(*(u16 *)(a + 2), b, c, k0, v0, k1, v1);
    *(u32 *)(a + 0x64) = func_0201CD10(*(u32 *)(a + 0x6c), 0, 0, *(u32 *)(a + 0x80), *(u32 *)(a + 8),
                                       func_02012FFC(), *(u32 *)(a + 0x68), 2, *(u16 *)(a + 2), 0xf, d);
}
