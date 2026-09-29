/*
 * function: func_021C5E48
 * address:  0x021C5E48
 * packet:   pkt_ov093_021C5E48
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CD64C  0x021CD64C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void func_021CD64C(void *w, u8 id, ...);

void func_021C5E48(u8 *p, u32 a, u32 b, int n, int *v)
{
    switch (n) {
    default:
        func_021CD64C(*(void **)(p + 0xc), 0x5c, a, b, 0xffff0000);
        break;
    case 1:
        func_021CD64C(*(void **)(p + 0xc), 0x5c, a, b, v[0], 0xffff0000);
        break;
    case 2:
        func_021CD64C(*(void **)(p + 0xc), 0x5c, a, b, v[0], v[1], 0xffff0000);
        break;
    case 3:
        func_021CD64C(*(void **)(p + 0xc), 0x5c, a, b, v[0], v[1], v[2], 0xffff0000);
        break;
    case 4:
        func_021CD64C(*(void **)(p + 0xc), 0x5c, a, b, v[0], v[1], v[2], v[3], 0xffff0000);
        break;
    }
}
