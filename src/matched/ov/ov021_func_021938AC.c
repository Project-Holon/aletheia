/*
 * function: func_021938AC
 * address:  0x021938AC
 * packet:   pkt_ov021_021938AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm  arm9
 *   func_02193CBC  0x02193CBC  thumb  ov021
 *   d_021DDA60     0x021DDA60  data   ov021  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern char d_021DDA60[];

extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern void func_02193CBC(void *o);

void *func_021938AC(u32 heap)
{
    void *o = func_02030734(heap, 0x144, 1, d_021DDA60, 0x12A);
    func_02193CBC(o);
    return o;
}
