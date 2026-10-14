/*
 * function: BTLV_EFFVM_CmdStartPokeCry
 * address: 0x021FBFC0
 * packet: pkt_ov094_021FBFC0
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   VM_GetU32 0x0201134C thumb
 *   func_02030DA8 0x02030DA8 arm
 *   BTLV_EFFECT_RegisterTask 0x021F896C thumb ov094
 *   BTLV_EFFVM_WaitVoiceTaskMain 0x021FE8D8 thumb ov094
 *   BTLV_EFFVM_SeModulationTaskMain 0x021FE6A4 thumb ov094
 *   BTLV_EFFVM_SeModulationTaskEnd 0x021FE750 thumb ov094
 *   BTLV_EFFVM_ResolveBattlerList 0x021FCA04 thumb ov094
 *   BTLV_EFFVM_FindFreeSeSlot 0x021FE4D0 thumb ov094
 *   BTLV_EFFECT_GetMcss 0x021F8694 thumb ov094
 *   BTLV_EFFVM_StartSeVolumeTweenTask 0x021FE410 thumb ov094
 *   BTLV_MCSS_PlayCry 0x02200218 thumb ov094
 *   d_0220AE68 0x0220AE68 data ov094 a1
 */
#include "../include/Obj00177.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { unsigned low : 10; unsigned bit10 : 1; unsigned high : 21; } Flags;
extern char d_0220AE68[];
extern void *func_02030734(u32, u32, int, const char *, u16);
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern void *func_02030DA8(void *, void (*)(void *, void *), void *, int);
extern void BTLV_EFFECT_RegisterTask(void *h, void (*cb)(void *), int arg);
extern void BTLV_EFFVM_WaitVoiceTaskMain(void *, void *);
extern void BTLV_EFFVM_SeModulationTaskMain(void *, void *);
extern void BTLV_EFFVM_SeModulationTaskEnd(void *);
extern int BTLV_EFFVM_ResolveBattlerList(char *, int, int *);
extern int BTLV_EFFVM_FindFreeSeSlot(char *);
extern int BTLV_EFFECT_GetMcss(void);
extern void BTLV_EFFVM_StartSeVolumeTweenTask(char *, int, int, int);
extern int BTLV_MCSS_PlayCry(char *, int, int, int, int, int, int);
int BTLV_EFFVM_CmdStartPokeCry(void *a, char *s)
{
    int buf[8];
    int n;
    int x;
    int y;
    int z;
    int q;
    int r;
    int duration;
    int i;
    int slot;
    int *p;
    n = BTLV_EFFVM_ResolveBattlerList(s, VM_GetU32(a), buf);
    x = VM_GetU32(a);
    y = VM_GetU32(a);
    z = VM_GetU32(a);
    q = VM_GetU32(a);
    r = VM_GetU32(a);
    duration = VM_GetU32(a);
    if (n != 0) {
        if (duration == 0) {
            for (i = 0; i < n; i++) {
                slot = BTLV_EFFVM_FindFreeSeSlot(s);
                *(int *)(s + slot * 4 + 0x26c) = BTLV_MCSS_PlayCry((char *)BTLV_EFFECT_GetMcss(), buf[i], x, y, z, q, r);
            }
            BTLV_EFFVM_StartSeVolumeTweenTask(s, 0x7f000, 0x6b000, 10);
            if (!((Flags *)s)->bit10) {
                p = func_02030734((u16)((((struct Obj00177 *)s)->f238 & 0x7fff) | 0x8000), 4, 0, d_0220AE68, 0x10f9);
                p[0] = (int)s;
                BTLV_EFFECT_RegisterTask(func_02030DA8(((struct Obj00177 *)s)->f8, BTLV_EFFVM_WaitVoiceTaskMain, p, 0), 0, 0);
            }
        } else {
            for (i = 0; i < n; i++) {
                p = func_02030734((u16)((((struct Obj00177 *)s)->f238 & 0x7fff) | 0x8000), 0x20, 0, d_0220AE68, 0x1104);
                p[0] = (int)s;
                p[1] = buf[i];
                p[2] = x;
                p[3] = y;
                p[4] = z;
                p[5] = q;
                p[6] = r;
                p[7] = duration;
                ((struct Obj00177 *)s)->f0 |= 0x800;
                BTLV_EFFECT_RegisterTask(func_02030DA8(((struct Obj00177 *)s)->f8, BTLV_EFFVM_SeModulationTaskMain, p, 0), BTLV_EFFVM_SeModulationTaskEnd, 1);
            }
        }
    }
    return ((struct Obj00177 *)s)->f23C;
}
