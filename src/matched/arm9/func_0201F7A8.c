/*
 * function: BMP_MENUWORK_DrawWindowBorder
 * address:  0x0201F7A8
 * packet:   pkt_0201F5BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The sibling of BMP_MENUWORK_DrawWindow: the same five ARM byte accessors on the same
 * descriptor, but the four geometry bytes are adjusted before the call, the
 * two extents shrunk by one and the two origins grown by two, and the worker
 * is BG_SYS_SetTileEntry with a zero second argument and a zero trailing one.
 * The four `lsls #24 / lsrs #24` pairs are the u8 truncation of each adjusted
 * value, not bitfield extraction: they are equal-amount pairs on values that
 * already left the accessors as bytes, so they only survive because the
 * arithmetic promoted to int in between.
 *
 * symbols:
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BMP_WIN_GetDispWidth  0x02045748  arm
 *   BMP_WIN_GetDispHeight  0x02045750  arm
 *   BMP_WIN_GetPosX  0x02045758  arm
 *   BMP_WIN_GetPosY  0x02045760  arm
 *   func_020409B4  0x020409B4  arm
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   func_02041B6C  0x02041B6C  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENUWORK_DrawWindowBorder.c \
 *       --func BMP_MENUWORK_DrawWindowBorder --addr 0x0201F7A8 --cc 1.1p1 --thumb
 */
typedef unsigned char u8;
typedef unsigned int  u32;

struct Descriptor;
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern u8 BMP_WIN_GetDispWidth(struct Descriptor *p);
extern u8 BMP_WIN_GetDispHeight(struct Descriptor *p);
extern u8 BMP_WIN_GetPosX(struct Descriptor *p);
extern u8 BMP_WIN_GetPosY(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void func_02041B6C(u32 bit);
extern void BG_SYS_SetTileEntry(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5,
                          u8 a6);

void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind)
{
    u8 id;
    u8 a;
    u8 b;
    u8 c;
    u8 d;

    id = BMP_WIN_GetBgLayer(desc);
    a = BMP_WIN_GetPosX(desc);
    b = BMP_WIN_GetPosY(desc);
    c = BMP_WIN_GetDispWidth(desc);
    d = BMP_WIN_GetDispHeight(desc);
    BG_SYS_SetTileEntry(id, 0, (u8)(a - 1), (u8)(b - 1), (u8)(c + 2), (u8)(d + 2), 0);
    if (kind == 0) {
        func_020409B4(id);
        return;
    }
    if (kind == 1) {
        func_02041B6C(id);
    }
}
