/*
 * function: MANUAL_COMMON_CreateTouchbar
 * address: 0x021B9F24
 * packet: pkt_ov225_021B9F24
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: pooled overlay ID is an absolute data a1 symbol; callback leaf filed.
 * symbols:
 *   ov067_id 0x00000043 data a1
 *   func_02034AC4 0x02034AC4 arm
 *   func_02030734 0x02030734 arm
 *   gManualCommonTouchbarAllocFile 0x021BC014 data a1
 *   MANUAL_COMMON_CreateTouchbarWidget 0x021BA160 thumb ov225
 *   MANUAL_COMMON_TouchbarNoop 0x021BA1C0 thumb ov225
 *   MANUAL_COMMON_CreateTouchbarSlots 0x021BA1C4 thumb ov225
 *   MANUAL_COMMON_LoadTouchbarActors 0x021BA41C thumb ov225
 *   MANUAL_COMMON_SetTouchbarState 0x021BA068 thumb ov225
 *   MANUAL_COMMON_ResetTouchbar 0x021BA644 thumb ov225
 *   func_020056A0 0x020056A0 thumb
 *   MANUAL_COMMON_TouchbarTaskNoop 0x021BA15C thumb ov225
 */
#include "../include/Obj06734.h"
#include "../include/Obj26144.h"
typedef unsigned short u16;
extern const char ov067_id[];
extern const char gManualCommonTouchbarAllocFile[];
extern int func_02034AC4(int);
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void MANUAL_COMMON_CreateTouchbarWidget(char *);
extern void MANUAL_COMMON_TouchbarNoop(void *);
extern void MANUAL_COMMON_CreateTouchbarSlots(char *);
extern void MANUAL_COMMON_LoadTouchbarActors(char *);
extern void MANUAL_COMMON_SetTouchbarState(char *,unsigned);
extern void MANUAL_COMMON_ResetTouchbar(char *);
extern void *func_020056A0(unsigned,unsigned,unsigned);
extern void MANUAL_COMMON_TouchbarTaskNoop(void *,void *);
void *MANUAL_COMMON_CreateTouchbar(char *owner)
{
    char *p;
    func_02034AC4((int)ov067_id);
    p=func_02030734(((struct Obj26144 *)owner)->f4,0x4c,1,gManualCommonTouchbarAllocFile,235);
    ((struct Obj06734 *)p)->f0=owner;MANUAL_COMMON_CreateTouchbarWidget(p);MANUAL_COMMON_TouchbarNoop(p);MANUAL_COMMON_CreateTouchbarSlots(p);MANUAL_COMMON_LoadTouchbarActors(p);
    ((struct Obj06734 *)p)->f8=4;p[0xc]=0;p[0xd]=0;MANUAL_COMMON_SetTouchbarState(p,0);MANUAL_COMMON_ResetTouchbar(p);
    ((struct Obj06734 *)p)->f48=func_020056A0((unsigned)MANUAL_COMMON_TouchbarTaskNoop,(unsigned)p,1);
    return p;
}
