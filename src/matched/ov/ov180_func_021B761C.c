/*
 * function: func_021B761C
 * address: 0x021B761C
 * packet: pkt_ov180_021B761C
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Caller evidence: 020185F0 is a bx-lr identity in this call; 021B75A4 leaves its return word live. 0202D7C8's three legacy trailing inputs are neither read nor forwarded and this caller sets only r0.
 * symbols:
 *   d_021B8174 0x021B8174 data ov180 a4
 *   d_021B818C 0x021B818C data a4
 *   func_021B75E8 0x021B75E8 thumb ov180
 *   func_021B7510 0x021B7510 thumb ov180
 *   func_021B7530 0x021B7530 thumb ov180
 *   func_021B7550 0x021B7550 thumb ov180
 *   POKEGRA_OpenHandle 0x0202D7C8 thumb
 *   POKE_TOOL_Dummy 0x020185F0 thumb
 *   POKE_TOOL_DecodeBoxParam 0x02017DBC thumb
 *   POKEGRA_RegisterCgrPP 0x0202D934 thumb
 *   POKEGRA_RegisterPalettePP 0x0202D8D0 thumb
 *   POKEGRA_RegisterCellAnimPP 0x0202D9A4 thumb
 *   POKE_TOOL_EncodeBoxParam 0x02017DE4 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_021B75A4 0x021B75A4 thumb ov180
 */
#include "../include/Obj02516.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
extern void func_021B75E8(char *,int),func_021B7510(char *,int),func_021B7530(char *,int),func_021B7550(char *,int);
extern int POKEGRA_OpenHandle(int);
extern void *POKE_TOOL_Dummy(void *);
struct Sav;
extern u32 POKE_TOOL_DecodeBoxParam(struct Sav *p);
extern u32 POKE_TOOL_EncodeBoxParam(struct Sav *p, u32 f);
extern int POKEGRA_RegisterCgrPP(int,void *,int,int,u16),POKEGRA_RegisterPalettePP(int,void *,int,int,u16,u16);
extern u32 POKEGRA_RegisterCellAnimPP(u32,u32,u32,u32,u16);
extern void ARC_TOOL_DeleteHandle(u8 *);
struct Obj;
extern struct Obj *func_021B75A4(char *p, const char *q);
extern const char d_021B8174[],d_021B818C[];
void func_021B761C(char *p)
{
    int bank;
    void *mon;
    u32 lock;
    if(((struct Obj02516 *)p)->f9048) {
        func_021B75E8(p,0);func_021B7510(p,0);func_021B7530(p,0);func_021B7550(p,0);
    }
    if(((struct Obj02516 *)p)->f904C) {
        func_021B75E8(p,1);func_021B7510(p,1);func_021B7530(p,1);func_021B7550(p,1);
    }
    bank=POKEGRA_OpenHandle(141);
    mon=POKE_TOOL_Dummy(*(void **)((u32)p+((struct Obj02516 *)p)->f915D*4+0x9140));
    lock=POKE_TOOL_DecodeBoxParam(mon);
    ((struct Obj02516 *)p)->f90CC=POKEGRA_RegisterCgrPP(bank,mon,0,0,141);
    ((struct Obj02516 *)p)->f90E4=POKEGRA_RegisterPalettePP(bank,mon,0,0,96,141);
    ((struct Obj02516 *)p)->f9100=POKEGRA_RegisterCellAnimPP((u32)mon,0,2,0,141);
    ((struct Obj02516 *)p)->f90D0=POKEGRA_RegisterCgrPP(bank,mon,1,0,141);
    ((struct Obj02516 *)p)->f90E8=POKEGRA_RegisterPalettePP(bank,mon,1,0,128,141);
    ((struct Obj02516 *)p)->f9104=POKEGRA_RegisterCellAnimPP((u32)mon,1,2,0,141);
    POKE_TOOL_EncodeBoxParam(mon,lock);ARC_TOOL_DeleteHandle((u8 *)bank);
    ((struct Obj02516 *)p)->f9048=(int)func_021B75A4(p,d_021B8174);
    ((struct Obj02516 *)p)->f904C=(int)func_021B75A4(p,d_021B818C);
}
