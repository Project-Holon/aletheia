/*
 * function: IRCBATTLEMENU_FreeMenuGraphics
 * address:  0x02196768
 * packet:   pkt_ov021_02196768
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GF_FONT_SetDefaultTextColor  0x0201DD68  thumb
 *   IRCBATTLEMENU_DeleteButtonWindows  0x02196454  thumb  ov021
 *   BG_SYS_FreeTiles  0x02040DA8  arm
 *   BG_SYS_FreeTileRun  0x0203FB44  arm
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   func_02040588  0x02040588  arm
 */
#include "../include/Obj03578.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void GF_FONT_SetDefaultTextColor(void);
extern void IRCBATTLEMENU_DeleteButtonWindows(u8 *p);
extern void BG_SYS_FreeTiles(u32 a, u32 b, u32 c);
extern void BG_SYS_FreeTileRun(u32 a, u32 b, u32 c);
extern void BG_SYS_FreeLayerBuf(u32 a);
struct Rec;
struct U16Vec;
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_02040588(unsigned char which, unsigned char enable);

void IRCBATTLEMENU_FreeMenuGraphics(u8 *p)
{
    u32 v;

    GF_FONT_SetDefaultTextColor();
    IRCBATTLEMENU_DeleteButtonWindows(p);
    BG_SYS_FreeTiles(5, 1, 0);
    v = ((struct Obj03578 *)p)->f3C;
    BG_SYS_FreeTileRun(5, (u16)v, (u16)(v >> 16));
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(4);
    MSGDATA_Delete((struct Rec *)(((struct Obj03578 *)p)->f28));
    GF_FONT_Delete((void *)(((struct Obj03578 *)p)->f2C));
    STRBUF_Delete((struct U16Vec *)(((struct Obj03578 *)p)->f38));
    func_02040588(5, 0);
}
