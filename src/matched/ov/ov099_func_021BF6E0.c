/*
 * function: func_021BF6E0
 * address: 0x021BF6E0
 * packet: pkt_ov099_021BF6E0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: unchanged concrete-correct caller resolves after the ov009 02156BA8 leaf is verified.
 * symbols:
 *   GFL_NET_STATE_SetError 0x0203C9AC arm
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_021BF280 0x021BF280 thumb ov099
 *   func_021C1BEC 0x021C1BEC thumb ov099
 *   func_021B9B54 0x021B9B54 thumb ov099
 *   func_021BF03C 0x021BF03C thumb ov099
 *   GFL_USE_PlaySeInSlot 0x0200616C thumb
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   func_021BF068 0x021BF068 thumb ov099
 *   DWC_RAP_GetCanceledPeerIndex 0x02156BA8 thumb ov009
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   DWC_RAP_GetNewClientAid 0x02156B8C thumb ov009
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   KEY_GetTrg 0x020362DC arm
 *   func_021BDDA8 0x021BDDA8 thumb ov099
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021C1A30 0x021C1A30 thumb ov099
 *   func_021B96D0 0x021B96D0 thumb ov099
 *   func_021B9B64 0x021B9B64 thumb ov099
 *   func_021B9B24 0x021B9B24 thumb ov099
 *   func_021B97F4 0x021B97F4 thumb ov099
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_02082D44 0x02082D44 arm
 */
#include "../include/Obj00901.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void GFL_NET_STATE_SetError(int a, u32 b, u32 c, u32 d);
extern int func_021BA928(char *);
extern void func_021BF280(void *a, void *b);
extern void func_021C1BEC(u8 *p);
extern void func_021B9B54(char *);
extern int func_021BF03C(char *);
extern void GFL_USE_PlaySeInSlot(void *arg, int i);
extern void GFL_NET_SetAutoExit(u8 a0);
extern void GFL_NET_SetLoginOption(u8 a0);
extern int func_021BF068(char *);
extern int DWC_RAP_GetCanceledPeerIndex(void);
extern void func_021BA874(char *,int);
extern void func_021BAAB8(char *,int,int);
extern int DWC_RAP_GetNewClientAid(void);
extern unsigned func_021BDD48(char *,void *);
extern u32 KEY_GetTrg(void);
extern int func_021BDDA8(int x);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void func_021C1A30(u8 *p, int v);
extern unsigned func_021B96D0(char *);
extern void func_021B9B64(char *);
extern void func_021B9B24(char *);
extern int func_021B97F4(char *);
extern int func_021C23B8(int i);
extern void func_02082D44(void *,void *,int);
int func_021BF6E0(char *p,int ret)
{
    unsigned action=0,kind;
    int index;
    if(((struct Obj00901 *)p)->f1F0!=-1){
        if(++((struct Obj00901 *)p)->f1C8>0xe10){GFL_NET_STATE_SetError(0,0,0,0x3f1);return ret;}
    }
    func_021BA928(p);
    ((struct Obj00901 *)p)->f1356=0;
    func_021BF280(p,(void *)33);
    func_021C1BEC((u8 *)p);
    func_021B9B54(p+0x274);
    if(func_021BF03C(p) && ((struct Obj00901 *)p)->f1F0!=-1){
        GFL_USE_PlaySeInSlot((void *)0x806,0);
        GFL_NET_SetAutoExit(1);
        GFL_NET_SetLoginOption(1);
        ((struct Obj00901 *)p)->f1CC=40;
        return ret;
    }
    if(func_021BF068(p) && ((struct Obj00901 *)p)->f1F0!=-1){
        func_021BA874(p,DWC_RAP_GetCanceledPeerIndex());
        func_021BAAB8(p,15,0);
        ((struct Obj00901 *)p)->f1CC=19;
        return ret;
    }
    if(((struct Obj00901 *)p)->f1F0==-1 && DWC_RAP_GetNewClientAid()!=-1){
        index=DWC_RAP_GetNewClientAid();
        ((struct Obj00901 *)p)->f1F0=index;
        func_021BA874(p,index);
        if(!((struct Obj00901 *)p)->f1351)func_021BAAB8(p,46,0);
        ((struct Obj00901 *)p)->f1C8=0;
    }else if(DWC_RAP_GetCanceledPeerIndex()!=-1){
        func_021BA874(p,DWC_RAP_GetCanceledPeerIndex());
        func_021BAAB8(p,15,0);
        ((struct Obj00901 *)p)->f1CC=19;
        return ret;
    }
    kind=func_021BDD48(p,((struct Obj00901 *)p)->f8);
    if(((struct Obj00901 *)p)->f1F0==-1){
        if((KEY_GetTrg()&2) && func_021BDDA8(kind)){
            GFL_USE_PlaySeDefaultVolume(0x54c);
            ((struct Obj00901 *)p)->f1CC=31;
            func_021C1A30((u8 *)p,33);
            return ret;
        }
        action=func_021B96D0(p+0x274);
        func_021B9B64(p+0x274);
    }
    switch(action){
    case 0:return ret;
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        if(func_021BDDA8(kind)){
            ((struct Obj00901 *)p)->f1CC=31;
        }else{
            ((struct Obj00901 *)p)->f1D0=0;
            ((struct Obj00901 *)p)->f1CC=49;
            func_021BAAB8(p,25,1);
        }
        func_021C1A30((u8 *)p,33);
        return ret;
    case 3:
        if(kind==1){
            ((struct Obj00901 *)p)->f135C=1;
            GFL_USE_PlaySeDefaultVolume(0x54c);
            func_021B9B24(p+0x274);
            ((struct Obj00901 *)p)->f1CC=28;
            func_021C1A30((u8 *)p,33);
            return ret;
        }
        break;
    case 2:
        if(kind==1){
            index=func_021B97F4(p+0x274);
            GFL_USE_PlaySeDefaultVolume(0x54c);
            func_02082D44((void *)func_021C23B8(index-1),p+0x24c,32);
            ((struct Obj00901 *)p)->f1CC=34;
            func_021C1A30((u8 *)p,33);
            return ret;
        }
        break;
    }
    return ret;
}
