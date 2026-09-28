/*
 * function: func_021C54C8
 * address:  0x021C54C8
 * packet:   pkt_ov093_021C54C8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C5480  0x021C5480  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021CD64C  0x021CD64C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void func_021C5480(u8 *p, u8 *a, int b);
extern u8 func_021D5440(u8 *p);
extern void func_021CD64C(void *w, u8 id, ...);

void func_021C54C8(u8 *p, u8 *a)
{
    func_021C5480(p, a, 0x25B);
    func_021CD64C(*(void **)(p + 0xc), 0x5b, 0x15C, func_021D5440(a), 0xffff0000);
}
