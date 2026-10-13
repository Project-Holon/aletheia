/*
 * function: FIELD_ENCOUNT_IsRepelled
 * address:  0x021A996C
 * packet:   pkt_ov021_021A996C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 *
 * symbols:

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Unit {
    u8 pad00[0x18];
    u16 f18;
    u8 pad1A[4];
    u8 f1E;
    u8 pad1F[9];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 2;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 b8 : 1;
    u32 b9 : 6;
    u32 b15 : 1;
};

int FIELD_ENCOUNT_IsRepelled(struct Unit *u, u8 n)
{
    if (u->b3)
        return 0;
    if (u->b15 && u->f1E >= n + 5)
        return 1;
    if (!u->b1 && u->b2 && n < u->f1E)
        return 1;
    return 0;
}
