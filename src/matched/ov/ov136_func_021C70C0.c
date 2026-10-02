/*
 * function: func_021C70C0
 * address:  0x021C70C0
 * packet:   pkt_ov136_021C70C0
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B98C   0x0204B98C  arm
 *   func_021C66A0 0x021C66A0 thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int func_0204B98C(void *);
extern void func_021C66A0(u8 *, int, int);
int func_021C70C0(u8 *p)
{
    if (func_0204B98C(*(void **)(*(u8 **)(p + 8) + 0x1FC)) == 0) {
        *(u32 *)(*(u8 **)(p + 4) + 4) = 0;
        func_021C66A0(*(u8 **)(p + 8), 7, 0);
        return *(u32 *)(p + 0x28);
    }
    return 0x18;
}
