/*
 * function: func_021BE1A4
 * address:  0x021BE1A4
 * packet:   pkt_021B6868
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Releases the four +0x1b8 slots and clears the two +0x1b4 bytes.
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10667.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);

void func_021BE1A4(char *p)
{
    u8 i;

    p[0x1b4] = 0;
    p[0x1b5] = 0;
    for (i = 0; i < 4; i++) {
        BMP_Clear((struct CharBuf *)((int)func_02045770((struct Descriptor *)*(u32 *)(p + i * 4 + 0x1b8))), 0);
        if (((struct Obj10667 *)p)->f8 != 3) {
            BMP_WIN_ClearScreen((struct Descriptor *)(*(u32 *)(p + i * 4 + 0x1b8)));
        }
    }
}
