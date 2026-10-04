/*
 * function: func_0220D98C
 * address:  0x0220D98C
 * packet:   pkt_0220D98C
 * region:   ov197
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0202616C  0x0202616C  thumb
 *   func_0220B000  0x0220B000  thumb  ov196
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *func_0202616C(void **obj, u32 idx);
extern void func_0220B000(int *p, u8 *q);

void func_0220D98C(u8 *p, u32 idx)
{
    void *t = func_0202616C(*(void ***)(p + 0x144), idx);

    func_0220B000((int *)(*(u32 *)(p + 0x148)), (u8 *)((u32)t));
}

