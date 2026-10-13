/*
 * function: FIELD_MSGBG_CreateMenuFuncCallback
 * address:  0x02190938
 * packet:   pkt_ov021_02190938
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_MSGBG_CreateMenuFuncPalette  0x02190860  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Handle {
    u16 *owner;
    u32 slot;
    u32 id;
    u32 c;
    u32 obj;
} Handle;

extern Handle *FIELD_MSGBG_CreateMenuFuncPalette(u16 *a, const u8 *b, u32 c, u16 d, u16 e, u16 f, u32 g, u32 h, u32 i);

Handle *FIELD_MSGBG_CreateMenuFuncCallback(u16 *a, const u8 *b, u32 c, u16 d, u16 e, u32 g, u32 h, u32 i)
{
    a[3] = 0xe;
    return FIELD_MSGBG_CreateMenuFuncPalette(a, b, c, d, e, a[3], g, h, i);
}
