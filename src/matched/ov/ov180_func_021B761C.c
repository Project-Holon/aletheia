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
 *   func_0202D7C8 0x0202D7C8 thumb
 *   func_020185F0 0x020185F0 thumb
 *   func_02017DBC 0x02017DBC thumb
 *   func_0202D934 0x0202D934 thumb
 *   func_0202D8D0 0x0202D8D0 thumb
 *   func_0202D9A4 0x0202D9A4 thumb
 *   func_02017DE4 0x02017DE4 thumb
 *   func_02049238 0x02049238 arm
 *   func_021B75A4 0x021B75A4 thumb ov180
 */
#include "../include/Obj02516.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
extern void func_021B75E8(char *,int),func_021B7510(char *,int),func_021B7530(char *,int),func_021B7550(char *,int);
extern int func_0202D7C8(int);
extern void *func_020185F0(void *);
struct Sav;
extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern int func_0202D934(int,void *,int,int,u16),func_0202D8D0(int,void *,int,int,u16,u16);
extern u32 func_0202D9A4(u32,u32,u32,u32,u16);
extern void func_02049238(u8 *);
extern int func_021B75A4(char *,const char *);
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
    bank=func_0202D7C8(141);
    mon=func_020185F0(*(void **)((u32)p+((struct Obj02516 *)p)->f915D*4+0x9140));
    lock=func_02017DBC(mon);
    ((struct Obj02516 *)p)->f90CC=func_0202D934(bank,mon,0,0,141);
    ((struct Obj02516 *)p)->f90E4=func_0202D8D0(bank,mon,0,0,96,141);
    ((struct Obj02516 *)p)->f9100=func_0202D9A4((u32)mon,0,2,0,141);
    ((struct Obj02516 *)p)->f90D0=func_0202D934(bank,mon,1,0,141);
    ((struct Obj02516 *)p)->f90E8=func_0202D8D0(bank,mon,1,0,128,141);
    ((struct Obj02516 *)p)->f9104=func_0202D9A4((u32)mon,1,2,0,141);
    func_02017DE4(mon,lock);func_02049238((u8 *)bank);
    ((struct Obj02516 *)p)->f9048=func_021B75A4(p,d_021B8174);
    ((struct Obj02516 *)p)->f904C=func_021B75A4(p,d_021B818C);
}
