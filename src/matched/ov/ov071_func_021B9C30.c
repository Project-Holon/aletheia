/*
 * function: func_021B9C30
 * address:  0x021B9C30
 * packet:   pkt_ov071_021B9C30
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021B7170  0x021B7170  thumb  ov071
 */

typedef unsigned char u8;

extern void func_0204B3DC(void *a, int b);
extern void func_021B7170(void *a);

void func_021B9C30(u8 *p)
{
    if (*(int *)(p + 0x2d8) <= 0x800)
        func_0204B3DC(*(void **)(p + 0x18), 0);
    else
        func_0204B3DC(*(void **)(p + 0x18), 1);
    if ((*(int *)(p + 0x2d8) >> 8) >= p[0x27c] * 32 - 200)
        func_0204B3DC(*(void **)(p + 0x1c), 0);
    else
        func_0204B3DC(*(void **)(p + 0x1c), 1);
    func_021B7170(*(void **)(p + 0x18));
    func_021B7170(*(void **)(p + 0x1c));
}
