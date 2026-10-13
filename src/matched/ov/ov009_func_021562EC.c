/*
 * unit:     yes
 * function: DWC_RAP_GetMyAidIfConnected, DWC_RAP_OnVchatStopped, DWC_RAP_EnableLocalVchat
 * address:  0x021562EC
 * packet:   pkt_ov009_021562EC
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Three functions: 0x021562EC, 0x0215631C, 0x02156330.
 *
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009  a4
 *   DWC_GetMyAID  0x0216B838  arm  ov009
 */
#include "../include/Obj18650.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *g_021A8264;
extern unsigned char DWC_GetMyAID(void);

int DWC_RAP_GetMyAidIfConnected(void)
{
    u8 *g = g_021A8264;
    if (g != 0) {
        u32 s = ((struct Obj18650 *)g)->f754;
        if (s == 9 || s == 10 || s == 0x12) {
            return DWC_GetMyAID();
        }
    }
    return -1;
}

void DWC_RAP_OnVchatStopped(void)
{
    *(u32 *)(g_021A8264 + 0x76c) = 0;
}

void DWC_RAP_EnableLocalVchat(void)
{
    *(u16 *)(g_021A8264 + 0x794) = 1;
}
