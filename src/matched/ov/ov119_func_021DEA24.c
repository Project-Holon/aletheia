/*
 * function: func_021DEA24
 * address: 0x021DEA24
 * packet: pkt_ov119_021DEA24
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 02035C08 returns the r0 consumed by original after its forwarding call; matched 021D98AC documents full ARM9 forwarding proof.
 * symbols:
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfPressing 0x021B6470 thumb ov067
 *   TOUCHBAR_SetButtonEnabled 0x021B6548 thumb ov067
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021DD09C 0x021DD09C thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DE9E8 0x021DE9E8 thumb ov119
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   d_021E80C4 0x021E80C4 data a4
 *   func_020355D8 0x020355D8 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021E68F4 0x021E68F4 thumb ov119
 *   func_021DE754 0x021DE754 thumb ov119
 *   func_020355C4 0x020355C4 arm
 *   func_020362DC 0x020362DC arm
 *   func_021DE208 0x021DE208 thumb ov119
 */
#include "../include/Obj00251.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct S S;
struct MsgBank;
extern void TOUCHBAR_Update(struct S *p);
extern int TOUCHBAR_SetButtonEnabled(unsigned char *p, unsigned int id, int v);
extern int TOUCHBAR_GetPressedButtonIdIfDone(u8 *),TOUCHBAR_GetPressedButtonIdIfPressing(u8 *);
extern void MSGDATA_ReadString(struct MsgBank *,unsigned,void *);
extern void func_021E1024(void *);
extern void func_021DD09C(char *p);
extern void func_021D8E84(void *,int);
extern void func_021DE9E8(void *);
extern int TOUCHPANEL_HitTrg(const void *);
extern u32 func_020362DC(void);
extern u8 func_020355C4(void);
extern const char d_021E80C4[];
extern void func_020355D8(u8);
extern void func_020061E4(u32 a);
extern void func_021E68F4(int,int);
extern int func_021DE754(char *,int),func_021DE208(char *);
static inline int poll(void) { int v=func_020362DC(); if(v)func_020355D8(0); return v; }
void func_021DEA24(char *p)
{
    int idx,sentinel;
    TOUCHBAR_Update(*(S * *)&((struct Obj00251 *)p)->f9C0);
    if(TOUCHBAR_GetPressedButtonIdIfDone(*(u8 * *)&((struct Obj00251 *)p)->f9C0)==1) {
        MSGDATA_ReadString(*(struct MsgBank * *)&((struct Obj00251 *)p)->f720,148,((struct Obj00251 *)p)->f738);
        func_021E1024(p);
        TOUCHBAR_SetButtonEnabled((unsigned char *)(*(int *)&((struct Obj00251 *)p)->f9C0),1,0);
        func_021DD09C(p);
        func_021D8E84(p,(int)func_021DE9E8);
        return;
    }
    sentinel=-1;
    if(TOUCHBAR_GetPressedButtonIdIfPressing(*(u8 * *)&((struct Obj00251 *)p)->f9C0)==sentinel) {
        idx=TOUCHPANEL_HitTrg(d_021E80C4);
        if(idx!=sentinel) {
            func_020355D8(1);
            func_020061E4(0x548);
            func_021E68F4((int)p,sentinel);
            if(func_021DE754(p,idx)) return;
        }
        if(func_020355C4() && poll()) {
            ((struct Obj00251 *)p)->f10A0%=6;
            if(((struct Obj00251 *)p)->f10A0<0) ((struct Obj00251 *)p)->f10A0=0;
            func_021E68F4((int)p,((struct Obj00251 *)p)->f10A0);
            func_020061E4(0x548);
            return;
        }
        if(poll()==1) {
            if(func_021DE754(p,((struct Obj00251 *)p)->f10A0)) return;
        }
        if(func_021DE208(p)) {
            func_021E68F4((int)p,((struct Obj00251 *)p)->f10A0);
            func_020061E4(0x548);
        }
    }
}
