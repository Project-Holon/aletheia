/*
 * function: func_0203971C
 * address:  0x0203971C
 * packet:   pkt_0203971C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203A28C  0x0203A28C  arm
 *   func_02082BCC  0x02082BCC  arm
 *
 * Clears the slot's `0x3e` field, refreshes its `0x40` field from the
 * selector, then clears the 0x10-byte record its indexed pointer names.
 * The early `popeq` is the null test written as an early return.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0203A28C(u32 h, u32 b, u32 z);
extern void func_02082BCC(void *p, u32 v, u32 n);

void func_0203971C(unsigned char *a, u32 b)
{
    if (b != 0xFF) {
        u16 h = *(u16 *)(a + 0x40);
        *(u16 *)(a + 0x3E) = 0;
        *(u16 *)(a + 0x40) = (u16)func_0203A28C(h, b, 0);
    }
    {
        void *p = *(void **)(a + b * 4 + 8);
        if (p == 0)
            return;
        func_02082BCC(p, 0, 0x10);
    }
}
