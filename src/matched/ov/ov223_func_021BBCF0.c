/*
 * function: func_021BBCF0
 * address: 0x021BBCF0
 * packet: pkt_ov223_021BBCF0
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   BG_SYS_LoadPlttEntry 0x02040EBC arm
 *   func_0207D63C 0x0207D63C arm
 *   func_021B99A0 0x021B99A0 thumb ov223
 *   func_021B9D9C 0x021B9D9C thumb ov223
 *   func_021BA984 0x021BA984 thumb ov223
 *   func_021BAC70 0x021BAC70 thumb ov223
 *   func_021BAD80 0x021BAD80 thumb ov223
 *   func_021BB944 0x021BB944 thumb ov223
 */
#include "../include/Obj00211.h"
#include "../include/Obj26100.h"
typedef enum { BIT8=8, BIT32=32 } Bits;
typedef unsigned int   u32;
extern void BG_SYS_SetLcdSwap(u32 swap);
extern void BG_SYS_LoadPlttEntry(u32 a0, u32 a1);
extern void func_0207D63C(unsigned,int,int,int,int);
typedef unsigned short u16;
extern void func_021B99A0(char *);
extern void func_021B9D9C(char *);
extern void func_021BA984(char *);
extern void func_021BAC70(const u16 *p);
extern void func_021BAD80(u16 *p);
extern void func_021BB944(char *);
static inline void setbit(char *p,Bits b) { ((struct Obj26100 *)p)->f24|=b; }
int func_021BBCF0(char *p)
{
    BG_SYS_SetLcdSwap(0);
    BG_SYS_LoadPlttEntry(0,0x2f3b); BG_SYS_LoadPlttEntry(4,0x2f3b);
    func_021B99A0(p); func_021B9D9C(p); func_021BA984(p); func_021BAC70((const u16 *)p); func_021BAD80((u16 *)p); func_021BB944(p);
    setbit(p,BIT8); setbit(p,BIT32);
    func_0207D63C(0x04000050,5,63,8,8); func_0207D63C(0x04001050,4,63,8,8);
    ((struct Obj00211 *)p)->f10=0;
    return 8;
}
