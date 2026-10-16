/*
 * function: POKETRADE_PROC_PollGridTouch
 * address: 0x021D9EBC
 * packet: pkt_ov119_021D9EBC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   POKETRADE_2D_HitTestBoxIcons 0x021E51A4 thumb ov119
 *   POKETRADE_PROC_LoadSlotMonAlt 0x021D8DD0 thumb ov119
 *   POKE_TOOL_GetBoxValue 0x02017E88 thumb
 */
#include "../include/Obj00001.h"

extern unsigned int TOUCHPANEL_GetPointTrg(unsigned int *outA, unsigned int *outB);
extern int POKETRADE_2D_HitTestBoxIcons(char *p, int x, int y, int *outA, int *outB, int *outSlot, int *outColumn, int *outRow);
typedef unsigned int   u32;
extern void *POKETRADE_PROC_LoadSlotMonAlt(void *a, int b, int c, char *p);
extern u32 POKE_TOOL_GetBoxValue(void *p, u32 id, u32 v);
int POKETRADE_PROC_PollGridTouch(char *p,int *a,int *b,int *c,int *d) {
    int x,y,z,n;
    if(TOUCHPANEL_GetPointTrg((unsigned int *)(&x),(unsigned int *)(&y))==1) {
        if(POKETRADE_2D_HitTestBoxIcons(p,x+12,y+12,a,b,c,d,&z)) {
            n=(int)POKETRADE_PROC_LoadSlotMonAlt((void *)(*(int *)&((struct Obj00001 *)p)->f828),*a,*b,p);
            if(n && POKE_TOOL_GetBoxValue((void *)n,0xA9,0)) return 1;
        }
    }
    return 0;
}
