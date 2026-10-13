/*
 * function: TRCARD_SYS_ScrCmdSetRecordFlag36
 * address:  0x0216F8B8
 * packet:   pkt_0216F8B8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   TRCARD_SYS_SetRecordFlag36  0x0216F900  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void TRCARD_SYS_SetRecordFlag36(void *p);

int TRCARD_SYS_ScrCmdSetRecordFlag36(int a0, int a1)
{
    void *v0;

a0 = a1 + 0;
    v0 = SCRCMD_WORK_GetGameSystem((void *)a0);
loc_0216F8C0:
    TRCARD_SYS_SetRecordFlag36(v0);
loc_0216F8C4:
a0 = 0;
    return a0;}
