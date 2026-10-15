/*
 * function: POKETRADE_PROC_FindMatchingBoxIcon
 * address: 0x021DB1BC
 * packet: pkt_ov119_021DB1BC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_2D_GetScrollColumn 0x021E4DBC thumb ov119
 *   POKETRADE_PROC_GetBoxIndexForSlot 0x021D8AF4 thumb ov119
 *   POKETRADE_PROC_GetSlotIndexInBox 0x021D8B0C thumb ov119
 *   POKETRADE_PROC_LoadSlotMonAlt 0x021D8DD0 thumb ov119
 *   func_02017E88 0x02017E88 thumb
 *   POKETRADE_2D_IsBoxIconMatch 0x021E4AA4 thumb ov119
 *   POKETRADE_PROC_GetSlotPosition 0x021DB4B4 thumb ov119
 *   POKETRADE_PROC_RedrawAndSyncGrid 0x021DB7AC thumb ov119
 */
#include "../include/Obj00001.h"
extern int POKETRADE_2D_GetScrollColumn(char *);
extern int POKETRADE_PROC_GetBoxIndexForSlot(int,char *);
extern int POKETRADE_PROC_GetSlotIndexInBox(int,int);
typedef unsigned int   u32;
extern void *POKETRADE_PROC_LoadSlotMonAlt(void *a, int b, int c, char *p);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern int POKETRADE_2D_IsBoxIconMatch(int,int);
extern int POKETRADE_PROC_GetSlotPosition(int);
extern void POKETRADE_PROC_RedrawAndSyncGrid(char *,int,int);
int POKETRADE_PROC_FindMatchingBoxIcon(char *p,int kind)
{
    int index=POKETRADE_2D_GetScrollColumn(p);
    int outer;
    for(outer=0;outer<((struct Obj00001 *)p)->f634;outer++) {
        int inner;
        index++;
        if(index>=((struct Obj00001 *)p)->f634) index=0;
        for(inner=0;inner<5;inner++) {
            int a=POKETRADE_PROC_GetBoxIndexForSlot(index,p);
            int b=POKETRADE_PROC_GetSlotIndexInBox(index,inner);
            int obj=(int)POKETRADE_PROC_LoadSlotMonAlt((void *)(*(int *)&((struct Obj00001 *)p)->f828),a,b,p);
            if(obj && POKETRADE_2D_IsBoxIconMatch(func_02017E88((void *)obj,0xab,0),kind) && !func_02017E88((void *)obj,0x4c,0)) {
                ((struct Obj00001 *)p)->f1080+=1;
                ((struct Obj00001 *)p)->f107C=POKETRADE_PROC_GetSlotPosition(index)-0x20;
                ((struct Obj00001 *)p)->f1084=1;
                POKETRADE_PROC_RedrawAndSyncGrid(p,0,1);
                return 1;
            }
        }
    }
    return 0;
}
