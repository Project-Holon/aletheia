/*
 * function: VIEWER_MAIN_UploadBg
 * address:  0x021C58E0
 * packet:   pkt_ov111_021C58E0
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_LoadTileData  0x02040B1C  arm
 *   BG_SYS_DrawTileEx  0x020410D0  arm
 *   func_020409B4  0x020409B4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x10];
    u32 size;
    void *data;
} CharData;

typedef struct {
    u16 w;
    u16 h;
} ScrnData;

typedef struct {
    u8 pad0[0x3030];
    CharData *chr;
    u8 pad3034[0x31DC - 0x3034];
    ScrnData *scrn;
} Work;

extern void BG_SYS_LoadTileData(int index, const void *src, u32 size, u32 tile);
extern void BG_SYS_DrawTileEx(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_020409B4(u32 layer);

void VIEWER_MAIN_UploadBg(Work *p)
{
    ScrnData *s;

    BG_SYS_LoadTileData(7, p->chr->data, p->chr->size, 0);
    s = p->scrn;
    BG_SYS_DrawTileEx(7, 0x15, 2, 10, 11, (u32)s + 0xC, 0x15, 2, s->w >> 3, s->h >> 3);
    func_020409B4(7);
}
