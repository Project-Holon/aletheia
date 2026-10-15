/*
 * function: ZKNSEARCH_RESULT_SetRowMulti,ZKNSEARCH_RESULT_Noop4
 * unit: yes
 * address: 0x021C0608
 * packet: pkt_ov210_021C0608
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * trailing: unit aligns the bx-lr follower at 021C065C after zero pad
 * 021C065A; two additional zero alignment bytes at 021C065E follow the unit.
 * symbols:
 *   ZKNSEARCH_MAIN_PrintListRow 0x021BEC60 thumb ov210
 *   ZKNSEARCH_MAIN_GetListIndexB 0x021BCEF0 thumb ov210
 *   ZKNSEARCH_MAIN_PlaceColumnActor 0x021BF7B0 thumb ov210
 */
#include "../include/Obj04620.h"
typedef unsigned int   u32;
extern void ZKNSEARCH_MAIN_PrintListRow(int p, int *a, u32 b);
extern u32 ZKNSEARCH_MAIN_GetListIndexB(u32 a, u32 b);
extern void ZKNSEARCH_MAIN_PlaceColumnActor(char *,int,int,int);
void ZKNSEARCH_RESULT_SetRowMulti(char *p,int index,void *data,int value,int flag)
{
    ZKNSEARCH_MAIN_PrintListRow((int)p,data,(*(unsigned *)(p+484+index*4)));
    if(index==ZKNSEARCH_MAIN_GetListIndexB((u32)p,(unsigned char)(*(char **)(*(char * *)&((struct Obj04620 *)p)->f0+8))[3]))ZKNSEARCH_MAIN_PlaceColumnActor(p,0,value,flag);
    if(index==ZKNSEARCH_MAIN_GetListIndexB((u32)p,(unsigned char)(*(char **)(*(char * *)&((struct Obj04620 *)p)->f0+8))[4]))ZKNSEARCH_MAIN_PlaceColumnActor(p,1,value,flag);
}
void ZKNSEARCH_RESULT_Noop4(void){}
