/*
 * function: func_0218BC6C
 * address:  0x0218BC6C
 * packet:   pkt_ov021_0218BC6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 */

void func_020470D0(void *h);
void func_02046EFC(void *h);

void func_0218BC6C(unsigned char *p)
{
    if (*(void **)(p + 0x1D0) != 0) {
        func_020470D0(*(void **)(p + 0x1D0));
        func_02046EFC(*(void **)(p + 0x1D0));
        *(void **)(p + 0x1D0) = 0;
    }
}
