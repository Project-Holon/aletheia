/*
 * unit: yes
 * function: P_STATUS_MainSeq,P_STATUS_VBlankTask
 * address: 0x021D44C8
 * packet: pkt_ov131_021D44C8
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interface: 02035CB8 writes fields only on success; their previous values
 *   remain initialized on failure. 021D5BAC guards a null output pointer.
 *   Tick difference is unsigned full-word arithmetic then byte truncation.
 *   Follower 021D46E4 is the complete eight-byte no-argument tail stub
 *   to owner 0204A648 (void(void)), with no return consumed.
 * symbols:
 *   func_0204A648 0x0204A648 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   P_STATUS_UpdateRefresh 0x021D5DC4 thumb ov131
 *   func_0202208C 0x0202208C thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_0204B98C 0x0204B98C arm
 *   P_STATUS_UpdateTouch 0x021D5280 thumb ov131
 *   P_STA_SUB_Main 0x021D6614 thumb ov131
 *   P_STATUS_UpdateInput 0x021D52A8 thumb ov131
 *   P_STA_INFO_Main 0x021D7B48 thumb ov131
 *   P_STA_SKILL_Main 0x021D9740 thumb ov131
 *   P_STA_RIBBON_Main 0x021D8830 thumb ov131
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0204A600 0x0204A600 arm
 *   MCSS_Main 0x02014C08 thumb
 *   func_02047964 0x02047964 arm
 *   func_020479D8 0x020479D8 arm
 *   MCSS_Draw 0x02014D2C thumb
 *   func_02047970 0x02047970 arm
 *   func_02041EE4 0x02041EE4 arm
 *   P_STATUS_SearchPokemon 0x021D5BAC thumb ov131
 *   func_0204B878 0x0204B878 arm
 *   P_STATUS_UpdatePaletteAnime 0x021D5650 thumb ov131
 */
#include "../include/Obj00035.h"
#include "../include/Obj23121.h"
#include "../include/Obj23122.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 TOUCHPANEL_GetPointCont(u32 *,u32 *);
extern void P_STATUS_UpdateRefresh(u8 *p);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern u32 func_020221A4(void);
struct Actor;
struct McssSys;
struct Obj;
struct PrintSys;
extern u32 func_0204B98C(struct Actor *a);
extern void P_STATUS_UpdateTouch(char *p);
extern void P_STA_SUB_Main(u8 *a, u8 *p);
extern void P_STATUS_UpdateInput(char *p);
extern void P_STA_INFO_Main(void *,void *);
extern void P_STA_SKILL_Main(u8 *a, u8 *p);
extern void P_STA_RIBBON_Main(u8 *,u8 *);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_0204A600(void);
extern void MCSS_Main(char *);
extern void func_02047964(void);
extern void func_020479D8(void);
extern void MCSS_Draw(struct McssSys *sys);
extern void func_02047970(void);
extern void func_02041EE4(u32,u32,u32);
extern int P_STATUS_SearchPokemon(u8 *,int,u16 *);
extern void func_0204B878(struct Obj *p, u16 value);
typedef signed int     s32;
struct W;
extern s32 P_STATUS_UpdatePaletteAnime(struct W *p);
int P_STATUS_MainSeq(char *p)
{
    u32 tick;
    ((struct Obj00035 *)p)->f30=((struct Obj00035 *)p)->f28;
    ((struct Obj00035 *)p)->f34=((struct Obj00035 *)p)->f2C;
    TOUCHPANEL_GetPointCont((u32 *)(p+0x28),(u32 *)(p+0x2c));
    switch (*(u32 *)&((struct Obj00035 *)p)->f50) {
    case 0:
        if (((struct Obj00035 *)p)->fC==1) P_STATUS_UpdateRefresh((u8 *)p);
        else {
            func_0202208C(0,1,1,0,6,1,((struct Obj00035 *)p)->f0);
            ((struct Obj00035 *)p)->f50=1;
        }
        break;
    case 1:
        if (func_020221A4()==1) ((struct Obj00035 *)p)->f50=4;
        break;
    case 2:
        if (((struct Obj00035 *)p)->f1A0==0 || func_0204B98C(((struct Obj00035 *)p)->f1A0)==0 || ((struct Obj23121 *)(*(char * *)&((struct Obj00035 *)p)->f8))->f24==1) {
            func_0202208C(0,0,0,0,6,1,((struct Obj00035 *)p)->f0);
            ((struct Obj00035 *)p)->f50=3;
        }
        break;
    case 3:
        if (func_020221A4()==1) return ((struct Obj00035 *)p)->f54;
        break;
    case 4:
        P_STATUS_UpdateTouch(p);
        if (((struct Obj00035 *)p)->fC==1) P_STATUS_UpdateRefresh((u8 *)p);
        else {
            P_STA_SUB_Main((u8 *)p,((struct Obj00035 *)p)->f88);
            if (((struct Obj23122 *)(*(char * *)&((struct Obj00035 *)p)->f8))->f24==1) {
                ((struct Obj00035 *)p)->f54=1;
                ((struct Obj00035 *)p)->f50=2;
            }
            P_STATUS_UpdateInput(p);
            if (((struct Obj00035 *)p)->fC==0) {
                switch (((struct Obj00035 *)p)->f5C) {
                case 0: P_STA_INFO_Main(p,((struct Obj00035 *)p)->f8C); break;
                case 1:
                case 3: P_STA_SKILL_Main((u8 *)p,((struct Obj00035 *)p)->f90); break;
                case 2: P_STA_RIBBON_Main((u8 *)p,*(u8 * *)&((struct Obj00035 *)p)->f94); break;
                }
            }
        }
        break;
    }
    func_0201C4E4(((struct Obj00035 *)p)->f84);
    func_0204A600();
    MCSS_Main(*(char * *)&((struct Obj00035 *)p)->f78);
    func_02047964();
    func_020479D8();
    MCSS_Draw(((struct Obj00035 *)p)->f78);
    func_02047970();
    tick=*(u32 *)0x02fffc3c;
    ((struct Obj00035 *)p)->f1B+=(u8)(tick-((struct Obj00035 *)p)->f20);
    ((struct Obj00035 *)p)->f20=tick;
    while (((struct Obj00035 *)p)->f1B>=4) {
        func_02041EE4(3,1,1);
        func_02041EE4(3,4,1);
        func_02041EE4(7,1,1);
        func_02041EE4(7,4,1);
        ((struct Obj00035 *)p)->f1B-=4;
    }
    if (((struct Obj00035 *)p)->f48==1 && func_0204B98C(((struct Obj00035 *)p)->f188)==0) {
        if (P_STATUS_SearchPokemon((u8 *)p,0,0)==1) func_0204B878(((struct Obj00035 *)p)->f188,3);
        else func_0204B878(((struct Obj00035 *)p)->f188,17);
        ((struct Obj00035 *)p)->f48=0;
    }
    if (((struct Obj00035 *)p)->f4C==1 && func_0204B98C(((struct Obj00035 *)p)->f18C)==0) {
        if (P_STATUS_SearchPokemon((u8 *)p,1,0)==1) func_0204B878(((struct Obj00035 *)p)->f18C,2);
        else func_0204B878(((struct Obj00035 *)p)->f18C,16);
        ((struct Obj00035 *)p)->f4C=0;
    }
    P_STATUS_UpdatePaletteAnime((struct W *)p);
    return 0;
}


extern void func_0204A648(void);
void P_STATUS_VBlankTask(void) { func_0204A648(); }
