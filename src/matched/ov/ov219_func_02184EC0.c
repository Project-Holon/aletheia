/*
 * function: BEACON_DETAIL_CreateMenuList
 * address: 0x02184EC0
 * packet: pkt_ov219_02184EC0
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: retain 1F878 fifth u16 stack argument loaded by this caller, absent from legacy callee declaration; 1FF30 heap explicitly narrowed in caller.
 * symbols:
 *   BEACON_DETAIL_CreateBmpWin 0x02184968 thumb ov219
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   BMP_MENUWORK_AddMsgItem 0x0201F878 thumb
 *   GF_FONT_GetLineHeight 0x0201DC80 thumb
 *   BMP_MENULIST_Create 0x0201FF30 thumb
 *   BMP_MENULIST_ResetCursorTile 0x02020CF8 thumb
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BEACON_DETAIL_OnMessageDone 0x02184EAC thumb ov219
 */
#include "../include/Obj00927.h"
#include "../include/Obj14777.h"
typedef unsigned short u16;
typedef unsigned int u32;
struct Src {u32 w[13];};
struct Descriptor;struct Font;struct Obj;struct Slot;
typedef struct {u32 bank,id;} Entry;
typedef unsigned char  u8;
extern u32 BEACON_DETAIL_CreateBmpWin(const u8 *p, int flag);
extern void *BMP_MENUWORK_Create(u32,u32);
extern void BMP_MENUWORK_AddMsgItem(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern u32 GF_FONT_GetLineHeight(struct Font *);
extern struct Obj *BMP_MENULIST_Create(struct Src *src, u16 a, u16 b, u32 heap);
extern void BMP_MENULIST_ResetCursorTile(struct Obj *,int);
extern void BMP_MENUWORK_DrawWindow(void *,int,int,int);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BEACON_DETAIL_OnMessageDone(int,int,int);
void BEACON_DETAIL_CreateMenuList(char *p,const unsigned char *descriptor,const struct Src *source,const Entry *entries)
{
    int i;
    struct Src cfg;
    *(struct Descriptor * *)&((struct Obj00927 *)p)->fC018=(struct Descriptor *)BEACON_DETAIL_CreateBmpWin(descriptor,1);
    ((struct Obj00927 *)p)->fC050=BMP_MENUWORK_Create(((struct Obj14777 *)source)->f10,((struct Obj00927 *)p)->f0);
    for(i=0;i<((struct Obj14777 *)source)->f10;i++)
        BMP_MENUWORK_AddMsgItem(*(struct Slot * *)&((struct Obj00927 *)p)->fC050,((struct Obj00927 *)p)->fC070,entries[i].bank,entries[i].id,(u16)(((struct Obj00927 *)p)->f0));
    ((struct Obj00927 *)p)->fC078=((struct Obj00927 *)p)->fC018;
    p[0xC07C]=0;
    cfg=*source;
    cfg.w[0]=*(u32 *)&((struct Obj00927 *)p)->fC050;
    cfg.w[3]=*(u32 *)(p+0xC018);
    cfg.w[1]=(u32)BEACON_DETAIL_OnMessageDone;
    *(u16 *)((char *)&cfg+32)=12;
    *(u16 *)((char *)&cfg+34)=GF_FONT_GetLineHeight(*(struct Font * *)&((struct Obj00927 *)p)->fC06C);
    cfg.w[9]=((struct Obj00927 *)p)->fC070;
    cfg.w[10]=(u32)(p+0xC078);
    cfg.w[11]=((struct Obj00927 *)p)->fC080;
    cfg.w[12]=*(u32 *)&((struct Obj00927 *)p)->fC06C;
    *(struct Obj * *)&((struct Obj00927 *)p)->fC04C=BMP_MENULIST_Create(&cfg,0,0,(u16)(((struct Obj00927 *)p)->f0));
    BMP_MENULIST_ResetCursorTile(*(struct Obj * *)&((struct Obj00927 *)p)->fC04C,((struct Obj00927 *)p)->f0);
    BMP_MENUWORK_DrawWindow(((struct Obj00927 *)p)->fC018,0,34,7);
    BMP_WIN_TransferChars(*(struct Descriptor **)(p+0xC018));
}
