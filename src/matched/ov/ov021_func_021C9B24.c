/*
 * function: BSUBWAY_SCR_DeleteWork
 * address:  0x021C9B24
 * packet:   pkt_ov021_021C9B24
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   BTL_SETUP_Delete  0x020130B4  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   GAME_DATA_SetCurrentEvent  0x02012EE4  thumb
 */
#include "../include/Obj05093.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020307B0(void *p);
struct Ctx;
extern int BTL_SETUP_Delete(int a0);
extern void MI_CpuFill8(void *p, int v, int n);
extern void *ICA_ANIME_GetField1C(const struct Ctx *p);
extern char *GAME_DATA_SetCurrentEvent(char *base, int v);

void BSUBWAY_SCR_DeleteWork(u32 a, u8 *p)
{
    if (p != 0) {
        if (((struct Obj05093 *)p)->f7C8 != 0) {
            func_020307B0(((struct Obj05093 *)p)->f7C8);
            ((struct Obj05093 *)p)->f7C8 = 0;
        }
        if (((struct Obj05093 *)p)->f7CC != 0) {
            BTL_SETUP_Delete((int)(((struct Obj05093 *)p)->f7CC));
            ((struct Obj05093 *)p)->f7CC = 0;
        }
        MI_CpuFill8(p, 0, 0x7EC);
        func_020307B0(p);
    }
    GAME_DATA_SetCurrentEvent(ICA_ANIME_GetField1C((const struct Ctx *)a), 0);
}
