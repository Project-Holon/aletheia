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
 *   func_02043B5C  0x02043B5C  arm
 *   func_020456F8  0x020456F8  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
extern void func_02043B5C(int a, int b);
extern void func_020456F8(int a);

void func_021BE1A4(char *p)
{
    u8 i;

    p[0x1b4] = 0;
    p[0x1b5] = 0;
    for (i = 0; i < 4; i++) {
        func_02043B5C((int)func_02045770((struct Descriptor *)*(u32 *)(p + i * 4 + 0x1b8)), 0);
        if (*(u32 *)(p + 8) != 3) {
            func_020456F8(*(u32 *)(p + i * 4 + 0x1b8));
        }
    }
}
