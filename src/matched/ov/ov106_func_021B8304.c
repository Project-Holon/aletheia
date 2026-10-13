/*
 * function: IRC_RANKING_ListExit
 * address: 0x021B8304
 * packet: pkt_ov106_021B8304
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   IRC_RANKING_DataGetCount 0x021B8D8C thumb ov106
 *   IRC_RANKING_RowExit 0x021B89F4 thumb ov106
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   IRC_RANKING_ClearRowScreens 0x021B8B4C thumb ov106
 *   func_0201ED04 0x0201ED04 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj05281.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor;
struct Node;
struct WordSet;
extern void func_02030EAC(struct Node *n);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 IRC_RANKING_DataGetCount(u8 *);
extern void IRC_RANKING_RowExit(u8 *);
extern void CLACT_ReleasePalette(u32 i);
extern void IRC_RANKING_ClearRowScreens(void *);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void MI_CpuFill8(void *,int,int);
void IRC_RANKING_ListExit(u8 *p) {
    int i;
    func_02030EAC(((struct Obj05281 *)p)->f58C);
    for(i=0;i<2;i++)BMP_WIN_Delete(*(void **)((u8 *)((u32 *)p+i)+0x568));
    for(i=0;i<IRC_RANKING_DataGetCount(*(u8 * *)&((struct Obj05281 *)p)->f550);i++)IRC_RANKING_RowExit(p+0x188+i*32);
    CLACT_ReleasePalette((u32)(((struct Obj05281 *)p)->f0));
    CLACT_ReleasePalette((u32)(((struct Obj05281 *)p)->f4));
    IRC_RANKING_ClearRowScreens(p+8);
    func_0201ED04(((struct Obj05281 *)p)->f588);
    GF_FONT_Delete(((struct Obj05281 *)p)->f570);
    MI_CpuFill8(p,0,0x59c);
}
