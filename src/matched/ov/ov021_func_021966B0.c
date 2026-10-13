/*
 * function: IRCBATTLEMENU_LoadSubBgScreen
 * address:  0x021966B0
 * packet:   pkt_ov021_021966B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle  0x02049990  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_02040588  0x02040588  arm
 */
#include "../include/Obj00093.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_020490F4(u32 id, u32 heap);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void ARC_TOOL_DeleteHandle(void *h);
extern void func_02040588(unsigned char which, unsigned char enable);

void IRCBATTLEMENU_LoadSubBgScreen(u8 *p, u32 a)
{
    void *h;

    h = func_020490F4(0x1D, ((struct Obj00093 *)p)->f10);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, a, 6, 0, (u16)((struct Obj00093 *)p)->f40, 0, 0, ((struct Obj00093 *)p)->f10);
    ARC_TOOL_DeleteHandle(h);
    func_02040588(6, 1);
}
