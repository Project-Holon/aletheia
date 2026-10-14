/*
 * function: func_021DB304
 * address: 0x021DB304
 * packet: pkt_ov119_021DB304
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: non-const table keeps reads after the p+0x800 store (const: 16 bytes differ).
 * volatile: hardware read/write at 021DB358/021DB35C and 021DB3C6/021DB3CA.
 * prototype: 02035C08 returns the live r0 result of 02035BBC (full original
 * 02035BBC and matched forwarder read); caller uses it despite void header.
 * symbols:
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   POKETRADE_SAVE_IsMessagePrintDone 0x021E12AC thumb ov119
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   d_021E8044 0x021E8044 data a1
 *   POKETRADE_2D_CreateCursorActor 0x021E6FD4 thumb ov119
 *   func_021DB1BC 0x021DB1BC thumb ov119
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   func_021DB2E8 0x021DB2E8 thumb ov119
 *   MSGDATA_ReadString 0x02045CAC arm
 *   POKETRADE_SAVE_OpenMessageWindow 0x021E0EF4 thumb ov119
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   POKETRADE_2D_ClearSubScreen 0x021E5D84 thumb ov119
 *   POKETRADE_SAVE_CloseMessageWindowClear 0x021E1098 thumb ov119
 *   POKETRADE_NEGO_SetOfferMarkersState 0x021DF7AC thumb ov119
 *   POKETRADE_2D_FadePaletteAll 0x021E71E0 thumb ov119
 *   func_021DBB6C 0x021DBB6C thumb ov119
 *   POKETRADE_2D_SetupSubBlend 0x021E6700 thumb ov119
 *   POKETRADE_2D_DeleteCursorActor 0x021E7058 thumb ov119
 *   func_021DB290 0x021DB290 thumb ov119
 */
#include "../include/Obj00001.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 a,b,c,d; } Rect;
extern Rect d_021E8044[];
extern void BG_SYS_SetSubVisiblePlanes(u32);
extern int POKETRADE_SAVE_IsMessagePrintDone(char *),TOUCHPANEL_HitTrg(const void *);
extern void POKETRADE_2D_CreateCursorActor(char *,int,int);
extern int func_021DB1BC(char *,int);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void func_021DB2E8(void *);
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void POKETRADE_SAVE_OpenMessageWindow(char *p, int flag, int x, int y, int w, int h);
struct S;
extern void TOUCHBAR_Update(struct S *p);
extern int TOUCHBAR_GetPressedButtonIdIfDone(u8 *);
extern void POKETRADE_2D_ClearSubScreen(char *),POKETRADE_SAVE_CloseMessageWindowClear(char *),POKETRADE_NEGO_SetOfferMarkersState(void *,int);
extern void POKETRADE_2D_FadePaletteAll(void *,int),func_021DBB6C(char *),POKETRADE_2D_SetupSubBlend(void *),POKETRADE_2D_DeleteCursorActor(void *),func_021DB290(void *);
void func_021DB304(char *p)
{
    int index;
    BG_SYS_SetSubVisiblePlanes(31);
    if(POKETRADE_SAVE_IsMessagePrintDone(p)) {
        index=TOUCHPANEL_HitTrg(d_021E8044);
        if(index!=-1) {
            ((struct Obj00001 *)p)->f800=(u32)index+1u;
            POKETRADE_2D_CreateCursorActor(p,d_021E8044[index].c,d_021E8044[index].a);
            if(func_021DB1BC(p,index)) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                *(volatile u32 *)0x04001000 &= 0xffff1fff;
                POKETRADE_PROC_SetStep(p,(int)func_021DB2E8);
                return;
            }
            MSGDATA_ReadString((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),0x34,(void *)(*(int *)&((struct Obj00001 *)p)->f738));
            POKETRADE_SAVE_OpenMessageWindow(p,1,1,1,0x1d,4);
            GFL_USE_PlaySeDefaultVolume(0x557);
        }
        TOUCHBAR_Update(((struct Obj00001 *)p)->f9C0);
        if(TOUCHBAR_GetPressedButtonIdIfDone(*(u8 * *)&((struct Obj00001 *)p)->f9C0)==1) {
            BG_SYS_SetSubVisiblePlanes(0x1a);
            *(int *)&((struct Obj00001 *)p)->f800=0;
            POKETRADE_2D_ClearSubScreen(p);
            POKETRADE_SAVE_CloseMessageWindowClear(p);
            *(volatile u32 *)0x04001000 &= 0xffff1fff;
            POKETRADE_NEGO_SetOfferMarkersState(p,1);
            POKETRADE_2D_FadePaletteAll(p,0);
            func_021DBB6C(p);
            POKETRADE_2D_SetupSubBlend(p);
            POKETRADE_2D_DeleteCursorActor(p);
            POKETRADE_PROC_SetStep(p,(int)func_021DB290);
        }
    }
}
