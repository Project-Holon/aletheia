/*
 * function: BMP_MENUWORK_LoadFrameGfx
 * address:  0x0201F5DC
 * packet:   pkt_0201F5DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENUWORK_LoadFrameGfx.c \
 *       --func BMP_MENUWORK_LoadFrameGfx --addr 0x0201F5DC --cc 1.1p1 --thumb
 *
 * symbols:
 *   BMP_MENUWORK_GetCharFileId  0x0201F53C  thumb
 *   BMP_MENUWORK_LoadPltt  0x0201F57C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern u8 BMP_MENUWORK_GetCharFileId(int i);
extern void *func_020496E4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a5, u32 a6);
extern void BMP_MENUWORK_LoadPltt(u32 a, u32 b, u32 c, u32 d);

void *BMP_MENUWORK_LoadFrameGfx(void *a0, u32 a1, u32 a2, u32 a3)
{
    void *r = func_020496E4(5, BMP_MENUWORK_GetCharFileId(a2), (u32)a0, 0, 0, a3);

    BMP_MENUWORK_LoadPltt((u32)a0, a1, a2, a3);
    return r;
}
