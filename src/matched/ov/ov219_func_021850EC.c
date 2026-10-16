/*
 * function: BEACON_DETAIL_CreateMenuItemsFromIds
 * address: 0x021850EC
 * packet: pkt_ov219_021850EC
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 45B38 third/fourth original inputs explicitly narrowed u16;
 * 1F878 retains original fifth stack heap input absent from legacy source.
 * symbols:
 *   BEACON_DETAIL_CreateBmpWin 0x02184968 thumb ov219
 *   func_02045B38 0x02045B38 arm
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   BMP_MENUWORK_AddMsgItem 0x0201F878 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   BEACON_DETAIL_SetupMenuList 0x02184FC8 thumb ov219
 */
#include "../include/Obj01013.h"
typedef unsigned short u16;
struct Src;struct Descriptor;struct MsgBank;struct Rec;struct Slot;
typedef struct {const void *str;unsigned param;} BmpMenuWork;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 BEACON_DETAIL_CreateBmpWin(const u8 *p, int flag);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern BmpMenuWork *BMP_MENUWORK_Create(unsigned,unsigned);
extern void BMP_MENUWORK_AddMsgItem(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void BEACON_DETAIL_SetupMenuList(char *,const struct Src *,unsigned);
void BEACON_DETAIL_CreateMenuItemsFromIds(char *p,const unsigned char *descriptor,const struct Src *cfg,unsigned file,const unsigned char *ids,unsigned count)
{
    struct MsgBank *bank;
    unsigned i;
    *(struct Descriptor * *)&((struct Obj01013 *)p)->fC018=(struct Descriptor *)BEACON_DETAIL_CreateBmpWin(descriptor,1);
    bank=func_02045B38(0,2,(u16)file,(u16)(((struct Obj01013 *)p)->f0));
    *(BmpMenuWork * *)&((struct Obj01013 *)p)->fC050=BMP_MENUWORK_Create(130,((struct Obj01013 *)p)->f0);
    for(i=0;i<count;i++)BMP_MENUWORK_AddMsgItem(*(struct Slot **)(p+0xc050),(unsigned)bank,ids[i],ids[i],(u16)((struct Obj01013 *)p)->f0);
    MSGDATA_Delete((struct Rec *)bank);
    BEACON_DETAIL_SetupMenuList(p,cfg,count);
}
