/*
 * function: PARTY_STATUS_Update
 * address: 0x021E5524
 * packet: pkt_ov178_021E5524
 * region: ov178
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_02FFFC3C 0x02FFFC3C data a4
 *   ov091_id 0x0000005B data a1
 *   ov131_id 0x00000083 data a1
 *   gPartyListProcData 0x021BED00 data a4 ov091
 *   gPokeStatusProcData 0x021DC800 data a4 ov131
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_GetInitParam 0x0203D798 arm
 *   func_0200FB24 0x0200FB24 thumb
 *   GFL_NET_ERR_RequestScreen 0x0200FB38 thumb
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   PROCSYS_Push 0x02031348 arm
 *   PROCSYS_Main 0x02031330 arm
 *   PLIST_COMM_Update 0x021B6114 thumb ov090
 * callee: 02031348 tail-forwards to 020314F4 whose own matched body reads all four arguments; retain caller register payloads.
 */
#include "../include/Obj00349.h"
#include "../include/Obj10715.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
extern u32 d_02FFFC3C;
extern u8 ov091_id[],ov131_id[],gPartyListProcData[],gPokeStatusProcData[];
extern int GFL_NET_GetRunState(void);
extern void *GFL_NET_GetInitParam(void);
extern u32 func_0200FB24(void);
extern void GFL_NET_ERR_RequestScreen(void);
extern int DWC_RAPCOMMON_HandleNetError(void *,void *);
extern int func_02034AC4(int);
extern void func_02034A5C(int);
extern void PROCSYS_Push(void *,u32,void *,void *);
extern u32 PROCSYS_Main(void *);
extern void PLIST_COMM_Update(u8 *);
int PARTY_STATUS_Update(void *unused,int unused2,char *q,char *p)
{
    if(((struct Obj00349 *)p)->f98==1 && ((struct Obj00349 *)p)->f68!=0) {
        u32 now;
        now=d_02FFFC3C;
        ((struct Obj00349 *)p)->fC8+=(u8)(now-((struct Obj00349 *)p)->fCC);
        ((struct Obj00349 *)p)->fCC=now;
        if(((struct Obj00349 *)p)->fC8>60) {
            --((struct Obj00349 *)p)->f68;
            ((struct Obj00349 *)p)->fC8-=60;
        }
    }
    if(GFL_NET_GetRunState()) {
        if(*((u8 *)GFL_NET_GetInitParam()+0x65)==3) {
            if(func_0200FB24()) {
                GFL_NET_ERR_RequestScreen();
                ((struct Obj10715 *)q)->f20=2;
                ((struct Obj00349 *)p)->f6B=1;((struct Obj00349 *)p)->fC4=1;
            }
        } else {
            int one;
            one=1;
            switch(DWC_RAPCOMMON_HandleNetError((void *)1,(void *)1)) {
            case 0:case 3:break;
            case 4:((struct Obj10715 *)q)->f20=3;((struct Obj00349 *)p)->f6B=one;((struct Obj00349 *)p)->fC4=one;break;
            case 1:case 2:default:((struct Obj10715 *)q)->f20=1;((struct Obj00349 *)p)->f6B=1;((struct Obj00349 *)p)->fC4=1;break;
            }
        }
    }
    switch(((struct Obj00349 *)p)->f0) {
    case 0:func_02034AC4((int)ov091_id);
        PROCSYS_Push(((struct Obj00349 *)p)->fD0,-1,gPartyListProcData,p+8);((struct Obj00349 *)p)->f0=1;break;
    case 1:if(PROCSYS_Main(((struct Obj00349 *)p)->fD0)==0)((struct Obj00349 *)p)->f0=2;break;
    case 2:func_02034A5C((int)ov091_id);
        if(((struct Obj00349 *)p)->f48==1) {((struct Obj00349 *)p)->fAF=((struct Obj00349 *)p)->f44;((struct Obj00349 *)p)->f0=3;}
        else return 1;
        break;
    case 3:func_02034AC4((int)ov131_id);
        PROCSYS_Push(((struct Obj00349 *)p)->fD0,-1,gPokeStatusProcData,p+0xa0);((struct Obj00349 *)p)->f0=4;break;
    case 4:
        if(((struct Obj00349 *)p)->f98==1 && ((struct Obj00349 *)p)->f68==0)((struct Obj00349 *)p)->fC4=1;
        if(PROCSYS_Main(((struct Obj00349 *)p)->fD0)==0)((struct Obj00349 *)p)->f0=5;break;
    case 5:func_02034A5C((int)ov131_id);
        if(((struct Obj00349 *)p)->f6B==0) {((struct Obj00349 *)p)->f44=((struct Obj00349 *)p)->fAF;((struct Obj00349 *)p)->f0=0;}
        else return 1;
        break;
    }
    if(((struct Obj00349 *)p)->f6B==0) {
        p+=8;
        PLIST_COMM_Update((u8 *)p);
    }
    return 0;
}
