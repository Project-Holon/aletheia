/*
 * function: SCRCMD_NETWORK_CmdGetAlwaysNet
 * address:  0x0215F2B8
 * packet:   pkt_0215F2B8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   GAMESYSTEM_GetAlwaysNetFlag  0x0201214C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
struct Ctx;
extern u32 GAMESYSTEM_GetAlwaysNetFlag(const struct Ctx *p);

int SCRCMD_NETWORK_CmdGetAlwaysNet(int a0, int a1)
{    int t5;
    int t6;
    u16 *q;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = SCRCMD_WORK_GetGameSystem((void *)a0);
loc_0215F2C4:
a0 = t5 + 0;
a1 = t6 + 0;
    q = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
loc_0215F2CE:
    a0 = GAMESYSTEM_GetAlwaysNetFlag(v0);
loc_0215F2D6:
*q = a0;
a0 = 0;
    return a0;}
