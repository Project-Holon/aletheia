/*
 * function: MYSTERY_CreatePartyMenu
 * address: 0x021D83DC
 * packet: pkt_ov121_021D83DC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware argument 04001050 passed to blend helper
 * symbols:
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_SetStringN 0x02045994 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   func_02040588 0x02040588 arm
 *   func_0207D63C 0x0207D63C arm
 *   MYSTERY_UTIL_CreateWindowList 0x021DA1BC thumb ov121
 *   MYSTERY_SetupBg 0x021D694C thumb ov121
 *   d_021DF544 0x021DF544 data a4
 */
#include "../include/Obj06446.h"
typedef unsigned char u8;
typedef struct { int w[12]; } Config;
extern const Config d_021DF544;
typedef unsigned int   u32;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
struct Strbuf;
extern void STRBUF_SetStringN(struct Strbuf *,const unsigned short *,u32);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BG_SYS_PushTile(u32 index);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0207D63C(void *,int,int,int,int);
extern void *MYSTERY_UTIL_CreateWindowList(int,Config *,int,int,int,void *,void *,void *,int);
typedef unsigned short u16;
extern void MYSTERY_SetupBg(u16 *p, int mode);
void MYSTERY_CreatePartyMenu(u8 *p,int heap)
{
    Config c;
    if(((struct Obj06446 *)p)->f28C==0) {
        c=d_021DF544;
        c.w[2]=(int)STRBUF_Create(37,heap);
        STRBUF_SetStringN((struct Strbuf *)c.w[2],(const unsigned short *)(p+1068),37);
        c.w[8]=(int)STRBUF_Create(253,heap);
        STRBUF_SetStringN((struct Strbuf *)c.w[8],(const unsigned short *)(p+1180),253);
        ((struct Obj06446 *)p)->f28C=MYSTERY_UTIL_CreateWindowList(0,&c,2,4,15,((struct Obj06446 *)p)->f39C,((struct Obj06446 *)p)->f3A4,((struct Obj06446 *)p)->f398,heap);
        STRBUF_Delete((void *)c.w[2]);
        STRBUF_Delete((void *)c.w[8]);
        MYSTERY_SetupBg((u16 *)(p+912),1);
        BG_SYS_PushTile(6);
        func_02040588(6,1);
        func_0207D63C((void *)0x04001050,4,24,15,3);
    }
}
