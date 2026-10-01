/*
 * function: func_0218FE50
 * address:  0x0218FE50
 * packet:   pkt_ov021_0218FE50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef struct {
    u32 saved;
    u8 body[0x94];
    u32 active;
    u32 unk9c;
} Sub;

int func_0218FE50(u8 *a)
{
    Sub *s = (Sub *)(a + 0xf0);
    if (*(u32 *)(a + 0x1ac) != 0 && s->unk9c != 0)
        return 1;
    return 0;
}
