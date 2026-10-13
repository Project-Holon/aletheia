/*
 * function: FIELD_MSGBG_CreateMenuFunc
 * address:  0x0219097C
 * packet:   pkt_0219097C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELD_MSGBG_CreateMenuFuncPos  0x02190960  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Handle;
extern struct Handle *FIELD_MSGBG_CreateMenuFuncPos(u16 *a, const u8 *b, u32 c, u16 d, u16 e);

u32 FIELD_MSGBG_CreateMenuFunc(u32 a, const void *b, u32 c)
{
return (int)FIELD_MSGBG_CreateMenuFuncPos((u16 *)a, (const u8 *)b, c, 0, 0);
}

