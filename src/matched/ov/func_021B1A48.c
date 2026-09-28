/*
 * function: func_021B1A48
 * address:  0x021B1A48
 * packet:   pkt_021B1A48
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021B2FE4  0x021B2FE4  arm  ov013
 */

extern void func_021B2FE4(void *p);

void func_021B1A48(char *p)
{
    if (*(void **)(p + 0x3c)) {
        func_021B2FE4(*(void **)(p + 0x3c));
        *(int *)(p + 0x3c) = 0;
    }
    *(int *)(p + 0x38) = -1;
}
