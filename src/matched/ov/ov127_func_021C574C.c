/*
 * function: WF2DMAP_OBJDRAW_UpdateActor
 * address: 0x021C574C
 * packet: pkt_ov127_021C574C
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: alignment at 021C57D6 then already-filed 57D8, 57DC, 57E8 leaves.
 * symbols:
 *   WF2DMAP_OBJ_GetSlot 0x021C49A4 thumb ov127
 *   WF2DMAP_OBJDRAW_GetFrameValue 0x021C58F8 thumb ov127
 *   WF2DMAP_OBJDRAW_SetFrame 0x021C5944 thumb ov127
 *   WF2DMAP_OBJDRAW_GetOwnerPos 0x021C5914 thumb ov127
 *   func_021C41DC 0x021C41DC thumb ov127
 *   WF2DMAP_OBJDRAW_GetDepth 0x021C5878 thumb ov127
 *   func_021C4214 0x021C4214 thumb ov127
 *   func_021C42C4 0x021C42C4 thumb ov127
 */
#include "../include/Obj00328.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int   u32;
extern int WF2DMAP_OBJ_GetSlot(u8 *p, unsigned int i);
extern int WF2DMAP_OBJDRAW_GetFrameValue(char *p, int b);
extern void WF2DMAP_OBJDRAW_SetFrame(u8 *p, int n, int a);
extern void WF2DMAP_OBJDRAW_GetOwnerPos(char *p, short *x, short *y);
extern void func_021C41DC(u8 *p, int x, int y);
extern int WF2DMAP_OBJDRAW_GetDepth(int, int);
extern void func_021C4214(u8 *p, u32 v);
extern void func_021C42C4(u8 *p);
void WF2DMAP_OBJDRAW_UpdateActor(u8 *p)
{
    if (p[19]) {
        int a = WF2DMAP_OBJ_GetSlot(((struct Obj00328 *)p)->f0, 5);
        int b = WF2DMAP_OBJ_GetSlot(((struct Obj00328 *)p)->f0, 6);
        s16 c = WF2DMAP_OBJ_GetSlot(((struct Obj00328 *)p)->f0, 8);
        s16 x, y;
        u16 d;
        if (((struct Obj00328 *)p)->f8 != a || ((struct Obj00328 *)p)->fA != b || c == 0) {
            ((struct Obj00328 *)p)->f8 = a;
            ((struct Obj00328 *)p)->fA = b;
            WF2DMAP_OBJDRAW_SetFrame(p, WF2DMAP_OBJDRAW_GetFrameValue(((struct Obj00328 *)p)->f4, a), b);
        }
        WF2DMAP_OBJDRAW_GetOwnerPos((char *)p, &x, &y);
        func_021C41DC(((struct Obj00328 *)p)->f4, x, y);
        d = WF2DMAP_OBJDRAW_GetDepth(y, p[18]);
        func_021C4214(((struct Obj00328 *)p)->f4, d);
        func_021C42C4(((struct Obj00328 *)p)->f4);
    }
}
