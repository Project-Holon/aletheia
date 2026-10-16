/*
 * function: BEACON_DETAIL_DeleteMainScreen
 * address: 0x02184CB0
 * packet: pkt_ov219_02184CB0
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BEACON_DETAIL_DeleteTaskMenuWin 0x02184C8C thumb ov219
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 */
#include "../include/Obj02933.h"
struct TaskMenuState;struct U16Vec;struct Descriptor;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void BEACON_DETAIL_DeleteTaskMenuWin(u8 *p, u32 i);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void STRBUF_Delete(struct U16Vec *);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BG_SYS_FreeLayerBuf(unsigned);
extern u32 GF_FONT_Delete(void *ptr);
extern void GF_FONT_SetTextColor(unsigned,unsigned,unsigned);
void BEACON_DETAIL_DeleteMainScreen(char *p)
{
    BEACON_DETAIL_DeleteTaskMenuWin((u8 *)p,0);BEACON_DETAIL_DeleteTaskMenuWin((u8 *)p,1);
    APP_TASKMENU_RES_Delete(*(struct TaskMenuState * *)&((struct Obj02933 *)p)->fC058);
    STRBUF_Delete(*(struct U16Vec * *)&((struct Obj02933 *)p)->fC064);STRBUF_Delete(*(struct U16Vec * *)&((struct Obj02933 *)p)->fC068);
    ((struct Obj02933 *)p)->fC05C=0;((struct Obj02933 *)p)->fC060=0;
    BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj02933 *)p)->fC01C);
    BG_SYS_FreeLayerBuf(2);BG_SYS_FreeLayerBuf(6);BG_SYS_FreeLayerBuf(3);BG_SYS_FreeLayerBuf(7);
    GF_FONT_Delete(((struct Obj02933 *)p)->fC06C);
    GF_FONT_SetTextColor((unsigned char)p[0xc084],(unsigned char)p[0xc085],(unsigned char)p[0xc086]);
}
