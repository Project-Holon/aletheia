/*
 * function: SCRCMD_WORK_CmdSetZukanFlagA
 * address:  0x0215AFE0
 * packet:   pkt_0215AFE0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CA28  0x0200CA28  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *func_0200CA1C(void *a);
struct Blk37;
extern struct Blk37 *func_0200CA28(struct Blk37 *p);

int SCRCMD_WORK_CmdSetZukanFlagA(int a0, int a1)
{
    void *p;
    void *v0;

a0 = a1 + 0;
    v0 = SCRCMD_WORK_GetGameData((void *)a0);
loc_0215AFE8:
    p = func_0200CA1C(v0);
loc_0215AFEC:
    a0 = (int)func_0200CA28(p);
loc_0215AFF0:
a0 = 0;
    return a0;}
