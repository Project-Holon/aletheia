/*
 * function: BSUBWAY_SCR_CmdClearWorkPtr
 * address:  0x021CA57C
 * packet:   pkt_ov021_021CA57C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_GetGameSystem  0x02158F54  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   BSUBWAY_SCR_ClearWorkPtr  0x021C9924  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern void *SCRIPT_WORK_GetGameSystem(void *p);
extern int BSUBWAY_SCR_ClearWorkPtr(u32 a);
int BSUBWAY_SCR_CmdClearWorkPtr(u32 a, u32 b)
{
    void *h = SCRCMD_WORK_GetScriptWork((void *)b);
    SCRIPT_WORK_ResetFieldParam((int)h);
    BSUBWAY_SCR_ClearWorkPtr((u32)SCRIPT_WORK_GetGameSystem(h));
    return 0;
}
