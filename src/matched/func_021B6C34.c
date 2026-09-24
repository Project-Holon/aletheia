/*
 * function: func_021B6C34
 * address:  0x021B6C34
 * packet:   pkt_021B6868
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Frees the +0x10 pointer with the ARM9 releaser, then the object itself.
 *
 * symbols:
 *   func_0203D7FC  0x0203D7FC  arm
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_0203D7FC(void *p);
extern void func_020307B0(void *p);

void func_021B6C34(char *p)
{
    func_0203D7FC(*(void **)(p + 0x10));
    func_020307B0(p);
}
