/*
 * function: PSEL_GRAPHIC_StateEnter
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
 *   PSEL_SetupSelectAnime 0x021B99A0 thumb ov223
 *   PSEL_CreateUnits 0x021B9D9C thumb ov223
 *   PSEL_CreateUnits2 0x021BA984 thumb ov223
 *   PSEL_SetBgSys 0x021BAC70 thumb ov223
 *   PSEL_UpdateBgAD80 0x021BAD80 thumb ov223
 *   PSEL_GRAPHIC_InitFadePalettes 0x021BB944 thumb ov223
 */
#include "../include/Obj00211.h"
#include "../include/Obj26100.h"
typedef enum { BIT8=8, BIT32=32 } Bits;
typedef unsigned int   u32;
extern void BG_SYS_SetLcdSwap(u32 swap);
extern void BG_SYS_LoadPlttEntry(u32 a0, u32 a1);
extern void func_0207D63C(unsigned,int,int,int,int);
typedef unsigned short u16;
extern void PSEL_SetupSelectAnime(char *);
extern void PSEL_CreateUnits(char *);
extern void PSEL_CreateUnits2(char *);
extern void PSEL_SetBgSys(const u16 *p);
extern void PSEL_UpdateBgAD80(u16 *p);
extern void PSEL_GRAPHIC_InitFadePalettes(char *);
static inline void setbit(char *p,Bits b) { ((struct Obj26100 *)p)->f24|=b; }
int PSEL_GRAPHIC_StateEnter(char *p)
{
    BG_SYS_SetLcdSwap(0);
    BG_SYS_LoadPlttEntry(0,0x2f3b); BG_SYS_LoadPlttEntry(4,0x2f3b);
    PSEL_SetupSelectAnime(p); PSEL_CreateUnits(p); PSEL_CreateUnits2(p); PSEL_SetBgSys((const u16 *)p); PSEL_UpdateBgAD80((u16 *)p); PSEL_GRAPHIC_InitFadePalettes(p);
    setbit(p,BIT8); setbit(p,BIT32);
    func_0207D63C(0x04000050,5,63,8,8); func_0207D63C(0x04001050,4,63,8,8);
    ((struct Obj00211 *)p)->f10=0;
    return 8;
}
