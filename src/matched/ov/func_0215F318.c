/*
 * function: SCRCMD_NETWORK_CmdFreeNpcTable
 * address:  0x0215F318
 * packet:   pkt_0215F318
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_GetReturnFlag  0x0215911C  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   SCRIPT_WORK_SetReturnFlag  0x02159114  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern u32 SCRIPT_WORK_GetReturnFlag(void *p);
extern u32 func_020307B0(void *p);
extern void *SCRIPT_WORK_SetReturnFlag(void *p, u32 v);

int SCRCMD_NETWORK_CmdFreeNpcTable(void *a0, int a1)
{    void *v0;

a0 = (void *)(a1 + 0);
    v0 = SCRCMD_WORK_GetScriptWork((void *)a0);
loc_0215F320:
    a0 = (void *)SCRIPT_WORK_GetReturnFlag(v0);
loc_0215F326:
    if (a0 == 0) goto loc_0215F336;
loc_0215F32A:
    a0 = (void *)func_020307B0(a0);
loc_0215F32E:
a1 = 0;
    a0 = (void *)SCRIPT_WORK_SetReturnFlag(v0, a1);
loc_0215F336:
a0 = 0;
    return (int)a0;}
