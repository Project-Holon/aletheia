/*
 * function: FIELD_MSGBG_CreateMenuFuncWork
 * address:  0x02190988
 * packet:   pkt_ov021_02190988
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_MENULIST_SetCancelDisabled  0x02020D10  thumb  arm9
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
extern void BMP_MENULIST_SetCancelDisabled(u8 *p, u32 v);

Handle *FIELD_MSGBG_CreateMenuFuncWork(u16 *a, const u8 *b, u32 c, u32 d, u32 x, u16 y, u16 z, u32 w)
{
    Handle *r = FIELD_MSGBG_CreateMenuFuncPalette(a, b, c, y, z, a[3], d, 0, x);
    if (w == 0)
        BMP_MENULIST_SetCancelDisabled((u8 *)r->obj, 1);
    return r;
}
