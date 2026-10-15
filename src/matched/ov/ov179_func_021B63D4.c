/*
 * function: CDEMO_SCENE_Create
 * address: 0x021B63D4
 * packet: pkt_ov179_021B63D4
 * region: ov179
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware writes 021B63E8 and 021B63EC.
 * symbols:
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   CDEMO_MAIN_SetupVram 0x021B615C thumb ov179
 *   CDEMO_MAIN_SetupScreen 0x021B616C thumb ov179
 *   func_020490F4 0x020490F4 arm
 *   CDEMO_MAIN_SetScript 0x021B622C thumb ov179
 *   CDEMO_MAIN_StartTask 0x021B624C thumb ov179
 *   CDEMO_WIPE_StartFadeOut 0x021B6290 thumb ov179
 *   d_021B6A1C 0x021B6A1C data a4
 */
#include "../include/Obj14386.h"
typedef unsigned short u16;

typedef unsigned int   u32;
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void BG_SYS_SetLcdSwap(u32 swap);
extern void CDEMO_MAIN_SetupVram(void);
extern void CDEMO_MAIN_SetupScreen(char *);
extern void *func_020490F4(u32 id, u32 heap);
extern void CDEMO_MAIN_SetScript(char *);
extern void CDEMO_MAIN_StartTask(int *);
extern void CDEMO_WIPE_StartFadeOut(char *,unsigned,unsigned,unsigned);
typedef struct {unsigned short value;char pad[10];} Entry;
extern const Entry d_021B6A1C[];
int CDEMO_SCENE_Create(char *p)
{
 BG_SYS_SetMainVisiblePlanes(0);BG_SYS_SetSubVisiblePlanes(0);
 *(volatile unsigned short *)0x04000050=0;
 *(volatile unsigned short *)0x04001050=0;
 BG_SYS_SetLcdSwap(1);CDEMO_MAIN_SetupVram();CDEMO_MAIN_SetupScreen(p);
 ((struct Obj14386 *)p)->f4=func_020490F4(d_021B6A1C[**(unsigned short **)p].value,0x7F);
 CDEMO_MAIN_SetScript(p);CDEMO_MAIN_StartTask((int *)p);CDEMO_WIPE_StartFadeOut(p,1,1,5);
 ((struct Obj14386 *)p)->f6058=1;
 return 2;
}
