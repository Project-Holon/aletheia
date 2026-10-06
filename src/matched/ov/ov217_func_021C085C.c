/*
 * function: func_021C085C
 * address:  0x021C085C
 * packet:   pkt_021C085C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C29D8  0x021C29D8  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
extern u32 func_021C29D8(void *a0);

void func_021C085C(int *p)
{
    int i;
    for (i = 0; i < 8; i++)
        func_021C29D8((void *)p[i + 0xC9]);
}
