/*
 * function: func_021E964C
 * address:  0x021E964C
 * packet:   pkt_ov093_021E964C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D3D90  0x021D3D90  thumb  ov093
 *   func_021E96A4  0x021E96A4  thumb  ov093
 *   func_021E96B4  0x021E96B4  thumb  ov093
 */
typedef unsigned char u8;
extern u8 func_021D3D90(void *p);
extern void func_021E96A4(void *a, int b, int c, int d, int e);
extern int func_021E96B4(void *a);

int func_021E964C(char *p, int *st)
{
    switch (*st) {
    case 0:
        func_021E96A4(*(void **)(p + 0x180), *(int *)(p + 0xbc), *(u8 *)(p + 0x175),
                      func_021D3D90(*(void **)(p + 4)), *(int *)(p + 0xb8));
        (*st)++;
    case 1:
        *(int *)(p + 0xc4) = func_021E96B4(*(void **)(p + 0x180));
        if (*(int *)(p + 0xc4))
            return 1;
    }
    return 0;
}
