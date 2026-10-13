/*
 * function: func_0220B1D8
 * address: 0x0220B1D8
 * packet: pkt_ov187_0220B1D8
 * region: ov187
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetBgmInfo 0x02012A30 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   FIELD_SOUND_SYSTEM_FadeVolume 0x02028A58 thumb
 *   func_020307B0 0x020307B0 arm
 *   BTL_SETUP_ClearWithSlots 0x02013930 thumb
 *   func_0220B0F8 0x0220B0F8 thumb ov187
 */
#include "../include/Obj01819.h"
#include "../include/Obj10802.h"
#include "../include/Obj24886.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { unsigned char low:1, flag:1, rest:6; } Flag;
struct BigObj;
extern unsigned int GAME_DATA_GetBgmInfo(const struct BigObj *);
extern int GFL_USE_PopBgm(void);
struct SoundSys;
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern void GFL_USE_FadeInBgmFull(u32);
extern void FIELD_SOUND_SYSTEM_FadeVolume(struct SoundSys *sys, u8 level, u16 frames);
extern u32 func_020307B0(void *p);
struct Obj;
extern void BTL_SETUP_ClearWithSlots(struct Obj *p);
extern void func_0220B0F8(u8 *p, u32 v);
void func_0220B1D8(u8 *a, u8 *b)
{
    void *p = (void *)GAME_DATA_GetBgmInfo(((struct Obj24886 *)(*(u8 * *)&((struct Obj10802 *)b)->f17F0))->f4);
    GFL_USE_PopBgm();
    GFL_USE_SetBgmPlayerParam(0);
    GFL_USE_FadeInBgmFull(30);
    if (*(u32 *)*(u8 * *)&((struct Obj10802 *)b)->f17F0 == 0) FIELD_SOUND_SYSTEM_FadeVolume(p,64,0);
    ((struct Obj10802 *)b)->f17E4 = ((Flag *)(a+0xC1))->flag;
    func_020307B0(((struct Obj01819 *)a)->f34);
    BTL_SETUP_ClearWithSlots((struct Obj *)a);
    func_020307B0(a);
    func_0220B0F8((u8 *)((u32)b),0);
}
