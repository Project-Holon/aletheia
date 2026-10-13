/*
 * function: SCRIPT_SYS_CheckCommandPermit
 * address:  0x02158DE8
 * packet:   pkt_ov010_02158DE8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRCMD_WORK_GetCallMode  0x0215A5D4  thumb  ov010
 *   SCRCMD_WORK_GetCallParam  0x0215A5D8  thumb  ov010
 *   SCRIPT_SYS_ForceExitNet  0x02158DBC  thumb  ov010
 *   d_02170374     0x02170374  data  ov010
 */

typedef unsigned char u8;

struct Bits { u8 b0 : 1; u8 b1 : 1; u8 b2 : 1; };

struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
typedef unsigned int   u32;
extern u32 SCRCMD_WORK_GetCallMode(void *p);
extern u32 SCRCMD_WORK_GetCallParam(void *p);
extern int SCRIPT_SYS_ForceExitNet(void);
extern struct Bits d_02170374[];

int SCRIPT_SYS_CheckCommandPermit(int a, int b, int c, int idx)
{
    int m, r;
    GAMESYSTEM_GetFieldMap((void *)c);
    SCRCMD_WORK_GetCallMode((void *)b);
    m = SCRCMD_WORK_GetCallParam((void *)b);
    r = 0;
    switch (m) {
    case 0: r = d_02170374[idx].b0; break;
    case 1: r = d_02170374[idx].b1; break;
    case 2: r = d_02170374[idx].b2; break;
    }
    if (r == 0)
        SCRIPT_SYS_ForceExitNet();
    return r;
}
