/*
 * function: NAMEIN_SETUP_ScrCmdSetFieldSaveFlag
 * address:  0x0216CC30
 * packet:   pkt_0216CC30
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   NAMEIN_SETUP_SetFieldSaveFlag  0x0216CC40  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern int NAMEIN_SETUP_SetFieldSaveFlag();

int NAMEIN_SETUP_ScrCmdSetFieldSaveFlag(int a0, int a1)
{
    void *v0;

a0 = a1 + 0;
    v0 = SCRCMD_WORK_GetGameSystem((void *)a0);
loc_0216CC38:
    a0 = NAMEIN_SETUP_SetFieldSaveFlag(v0);
loc_0216CC3C:
a0 = 0;
    return a0;}
