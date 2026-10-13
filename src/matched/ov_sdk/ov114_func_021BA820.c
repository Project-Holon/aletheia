/*
 * function: NHTTPi_alloc
 * address:  0x021BA820
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NHTTPi_GetSystemInfoP  0x021BEF08  arm  ov114
 *
 *
 * Calls the +0x00 hook of the module object with two arguments.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *NHTTPi_GetSystemInfoP(void);

int NHTTPi_alloc(int a, int b)
{
    int (*g)(int, int) = *(int (**)(int, int))NHTTPi_GetSystemInfoP();
    if (g == 0)
        return 0;
    return g(a, b);
}
