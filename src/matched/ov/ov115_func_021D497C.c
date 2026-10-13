/*
 * function: func_021D497C
 * address: 0x021D497C
 * packet: pkt_ov115_021D497C
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: 0202EB44 leaves r0 live for this caller; entry p is forwarded.
 * 02009860 is bx lr; its unchanged entry pointer feeds both SDK readers.
 * callbacks: both zero-status arms use 42E0; mode2 and final else use 46CC;
 * missing profile uses 45D0, missing console uses 493C, mode1 uses 460C.
 * symbols:
 *   func_0202EB44 0x0202EB44 thumb
 *   func_0202EB4C 0x0202EB4C thumb
 *   func_021D5D3C 0x021D5D3C thumb ov115
 *   func_021D5ED8 0x021D5ED8 thumb ov115
 *   func_021D426C 0x021D426C thumb ov115
 *   func_021D5B50 0x021D5B50 thumb ov115
 *   func_02009860 0x02009860 thumb
 *   DWC_CheckHasProfile 0x020597C8 arm
 *   DWC_CheckValidConsole 0x02059760 arm
 *   func_0202EB0C 0x0202EB0C thumb
 *   func_021D42E0 0x021D42E0 thumb ov115
 *   func_021D46CC 0x021D46CC thumb ov115
 *   func_021D45D0 0x021D45D0 thumb ov115
 *   func_021D493C 0x021D493C thumb ov115
 *   func_021D460C 0x021D460C thumb ov115
 */
#include "../include/Obj13850.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_0202EB44(u8 *);
struct DWCstAccUserData;
extern u32 func_0202EB4C(void);
extern void func_021D5D3C(u8 *p);
extern void func_021D5ED8(u8 *,u32);
extern void func_021D426C(u8 *,u32);
extern void func_021D5B50(void *,int);
struct Sub020097BCObj;
extern struct Sub020097BCObj *func_02009860(struct Sub020097BCObj *obj);
extern int DWC_CheckHasProfile(struct DWCstAccUserData *userdata);
extern int DWC_CheckValidConsole(struct DWCstAccUserData *userdata);
extern u32 func_0202EB0C(void);
extern void func_021D42E0(u8 *),func_021D46CC(u8 *),func_021D45D0(u8 *);
extern void func_021D493C(u8 *),func_021D460C(u8 *);
#define P(k) (*(u8 **)(p+(k)))
void func_021D497C(u8 *p)
{
    if(func_0202EB44(p)==0) {
        func_021D5D3C(P(0x38));
        func_021D5ED8(P(0x38),39);
        *(int *)(P(0x40)+0x1c)=1;
        func_021D426C(p,(u32)func_021D42E0);
        return;
    }
    if(func_0202EB4C()==0) {
        func_021D5D3C(P(0x38));
        func_021D5ED8(P(0x38),34);
        *(int *)(P(0x40)+0x1c)=1;
        func_021D426C(p,(u32)func_021D42E0);
        return;
    }
    if(*(int *)(P(0x40)+0x14)==2) {
        func_021D5B50(P(0x38),17);
        func_021D426C(p,(u32)func_021D46CC);
        return;
    }
    if(DWC_CheckHasProfile((struct DWCstAccUserData *)func_02009860((struct Sub020097BCObj *)P(0x3c)))==0) {
        ((struct Obj13850 *)p)->f20=1;
        func_021D5D3C(P(0x38));
        if(func_0202EB0C()==0) func_021D5ED8(P(0x38),18);
        else func_021D5ED8(P(0x38),43);
        func_021D426C(p,(u32)func_021D45D0);
        return;
    }
    if(DWC_CheckValidConsole((struct DWCstAccUserData *)func_02009860((struct Sub020097BCObj *)P(0x3c)))==0) {
        ((struct Obj13850 *)p)->f20=1;
        func_021D5D3C(P(0x38));
        if(func_0202EB0C()==0) func_021D5ED8(P(0x38),20);
        else func_021D5ED8(P(0x38),45);
        func_021D426C(p,(u32)func_021D493C);
        return;
    }
    if(*(int *)(P(0x40)+0x14)==1) {
        func_021D5D3C(P(0x38));
        func_021D5ED8(P(0x38),37);
        func_021D426C(p,(u32)func_021D460C);
    } else {
        func_021D5B50(P(0x38),17);
        func_021D426C(p,(u32)func_021D46CC);
    }
}
