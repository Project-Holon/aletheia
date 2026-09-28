/*
 * function: func_021D9960
 * address:  0x021D9960
 * packet:   pkt_021D9960
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02048AC4  0x02048AC4  arm
 *   func_02046788  0x02046788  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void func_02048AC4(void *);
extern void func_02046788(void);

void func_021D9960(char *p)
{
    *(u32 *)(p + 4) = 0;
    func_02048AC4(*(void **)p);
    func_02046788();
}
