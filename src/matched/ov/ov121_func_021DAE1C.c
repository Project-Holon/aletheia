/*
 * function: MYSTERY_ALBUM_DeleteWork
 * address: 0x021DAE1C
 * packet: pkt_ov121_021DAE1C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: The slot array at +0xa7c is the same layout as MYSTERY_ALBUM_RemoveCard;
 * its member access keeps the offset loaded before the loop index.
 * symbols:
 *   MYSTERY_ALBUM_Delete 0x021DD980 thumb ov121
 *   MYSTERY_ALBUM_DeleteSlotWork 0x021DD1FC thumb ov121
 *   MYSTERY_UTIL_DeleteMenuWindow 0x021D9E04 thumb ov121
 *   BG_SYS_FillScrollArea 0x02040618 arm
 *   MYSTERY_UTIL_ClearWindowList 0x021DA2A8 thumb ov121
 *   MYSTERY_UTIL_DeleteWindowList 0x021DA280 thumb ov121
 *   MYSTERY_ALBUM_UpdateSlots 0x021DB528 thumb ov121
 *   MYSTERY_ALBUM_Cleanup 0x021DB3E8 thumb ov121
 *   MYSTERY_DATA_GetCardSlotNum 0x0200A348 thumb
 *   MYSTERY_ALBUM_ClearEntry 0x021DBEE4 thumb ov121
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   func_02041B6C 0x02041B6C arm
 *   MYSTERY_UTIL_DeleteTask 0x021DA890 thumb ov121
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj01058.h"
typedef unsigned int u32;
typedef struct Obj { char pad[0xa7c]; char *slots[12]; } Obj;
extern void MYSTERY_ALBUM_Delete(char *);
extern void MYSTERY_ALBUM_DeleteSlotWork(void **);
typedef unsigned char  u8;
extern void MYSTERY_UTIL_DeleteMenuWindow(u8 *p);
extern void BG_SYS_FillScrollArea(u32,u32,u32);
extern void MYSTERY_UTIL_ClearWindowList(u8 *p);
extern void MYSTERY_UTIL_DeleteWindowList(u8 *p);
extern void MYSTERY_ALBUM_UpdateSlots(char *,int);
extern void MYSTERY_ALBUM_Cleanup(char *);
extern u32 MYSTERY_DATA_GetCardSlotNum(struct Obj *);
extern void MYSTERY_ALBUM_ClearEntry(u32 p);
extern void BG_SYS_ClearSlot(u32);
extern void func_02041B6C(u32);
extern void MYSTERY_UTIL_DeleteTask(void *);
extern u32 func_020307B0(void *p);
void MYSTERY_ALBUM_DeleteWork(Obj *obj)
{
    char *p=(char *)obj;
    int i;
    u32 j;
    for(i=0;i<12;i++) {
        if(obj->slots[i]) {
            MYSTERY_ALBUM_Delete(obj->slots[i]);
            obj->slots[i]=0;
        }
    }
    MYSTERY_ALBUM_DeleteSlotWork(*(void ** *)&((struct Obj01058 *)p)->fAB0);
    if(((struct Obj01058 *)p)->fABC) {
        MYSTERY_UTIL_DeleteMenuWindow(((struct Obj01058 *)p)->fABC);
        ((struct Obj01058 *)p)->fABC=0;
    }
    BG_SYS_FillScrollArea(3,0,0);
    BG_SYS_FillScrollArea(2,0,0);
    MYSTERY_UTIL_ClearWindowList(((struct Obj01058 *)p)->fAB8);
    MYSTERY_UTIL_DeleteWindowList(((struct Obj01058 *)p)->fAB8);
    MYSTERY_ALBUM_UpdateSlots(p,1);
    MYSTERY_ALBUM_UpdateSlots(p,0);
    MYSTERY_ALBUM_Cleanup(p);
    for(j=0;j<MYSTERY_DATA_GetCardSlotNum(((struct Obj01058 *)p)->fC);j++)
        MYSTERY_ALBUM_ClearEntry((u32)(p+0x28+j*0xdc));
    BG_SYS_ClearSlot(4);
    BG_SYS_ClearSlot(6);
    func_02041B6C(4);
    func_02041B6C(6);
    MYSTERY_UTIL_DeleteTask(((struct Obj01058 *)p)->fAC4);
    func_020307B0(p);
}
