/*
 * function: func_021BA1B4
 * address:  0x021BA1B4
 * packet:   pkt_021B6868
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates the +0x20 handle; on failure runs the error path and clears +0xc.
 *
 * symbols:
 *   func_02072A44  0x02072A44  arm
 *   func_02034714  0x02034714  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int  func_02072A44(int size);
extern void func_02034714(const char *expr, u32 line, const char *file);

void func_021BA1B4(char *p)
{
    u32 v = func_02072A44(7);

    *(u32 *)(p + 0x20) = v;
    if (v == 0) {
        func_02034714((void *)0x021C7224, 0, (void *)0x021C7224);
    }
    *(u32 *)(p + 0xc) = 0;
}
