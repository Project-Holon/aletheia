/*
 * function: func_02012E4C
 * address:  0x02012E4C
 * packet:   pkt_02012E4C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012E4C.c \
 *       --func func_02012E4C --addr 0x02012E4C --cc 1.1p1 --thumb
 *
 * symbols:
 *   SAVE_CONTROL_BeginExtraSaveWrite  0x02007374  thumb
 *   WIH_DWC_PauseTimers  0x0201042C  thumb
 *   GAME_DATA_WriteToSave  0x02012CE0  thumb
 */
#include "../include/Obj00054.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern void func_02034F84(int v);
extern void GAME_DATA_WriteToSave(u8 *p);
extern void WIH_DWC_PauseTimers(void);
extern void func_0203516C(int mode);
extern void SAVE_CONTROL_BeginExtraSaveWrite(char *a0, u32 a1);

void func_02012E4C(u8 *p, u32 id)
{
    func_02034F84(0x80);
    GAME_DATA_WriteToSave(p);
    WIH_DWC_PauseTimers();
    ((struct Obj00054 *)p)->f1CE = 1;
    func_0203516C(2);
    SAVE_CONTROL_BeginExtraSaveWrite((char *)*(u32 *)&((struct Obj00054 *)p)->f0, id);
}
