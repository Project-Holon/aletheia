/*
 * function: func_02190344
 * address:  0x02190344
 * packet:   pkt_ov021_02190344
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02194798  0x02194798  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_02194798(void *p);
extern void func_02040DA8(u32 a, int b, int c);
extern void func_020403F4(u8 a);

void func_02190344(u8 *a)
{
    if (*(void **)(a + 0x15c) != 0) {
        func_02194798(*(void **)(a + 0x15c));
        *(void **)(a + 0x15c) = 0;
    }
    if (*(u16 *)(a + 2) != 0xff) {
        func_02040DA8(*(u16 *)(a + 2), 1, 0);
        func_020403F4(*(u16 *)(a + 2));
        *(u16 *)(a + 2) = 0xff;
    }
}
