/*
 * function: POKETRADE_2D_LoadSubScreenGfx
 * address: 0x021E5C64
 * packet: pkt_ov119_021E5C64
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_020490F4 0x020490F4 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02040618 0x02040618 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   d_021E81D4 0x021E81D4 data a4
 */
#include "../include/Obj01055.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
typedef struct { u32 x, y; } Pos;
extern Pos d_021E81D4[26];
struct Cfg;
struct Descriptor;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02041B6C(u32 bit);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void ARC_TOOL_DeleteHandle(void *);
extern void GF_FONT_SetTextColor(u32, u32, u32);
struct MsgBank;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_Print(void *, s16, s16, void *, void *);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
void POKETRADE_2D_LoadSubScreenGfx(char *p)
{
    u32 i;
    void *h;
    func_02040588(4, 0);
    func_02040588(6, 0);
    h = func_020490F4(0x66, ((struct Obj01055 *)p)->f5F4);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 16, 4, 0, (u16)((struct Obj01055 *)p)->f870, 0, 0, ((struct Obj01055 *)p)->f5F4);
    func_02041B6C(4);
    func_02040618(4, 0, -4);
    func_02040618(6, 0, -4);
    ARC_TOOL_DeleteHandle(h);
    GF_FONT_SetTextColor(1, 2, 15);
    for (i = 0; i < 26; i++) {
        *(void **)(p + i * 4 + 0x750) = (void *)BMP_WIN_Create(6, (u8)d_021E81D4[i].x, (u8)d_021E81D4[i].y, 2, 2, 14, 0);
        MSGDATA_ReadString((struct MsgBank *)(((struct Obj01055 *)p)->f720), i + 0x35, (void *)(*(int *)&((struct Obj01055 *)p)->f730));
        PRINTSYS_Print(BMP_WIN_GetBmp(*(void **)(p + i * 4 + 0x750)), 0, 0, ((struct Obj01055 *)p)->f730, ((struct Obj01055 *)p)->f728);
        BMP_WIN_MakeScreen(*(void **)(p + i * 4 + 0x750));
        BMP_WIN_TransferChars(*(void **)(p + i * 4 + 0x750));
    }
    func_02041B6C(6);
    func_02040588(4, 1);
    func_02040588(6, 1);
}
