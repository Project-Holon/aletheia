/*
 * function: SCRCMD_MSGWIN_CmdInitMenu
 * address:  0x021B01DC
 * packet:   pkt_ov021_021B01DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   VM_GetU16  0x02011330  thumb
 *   SCRIPT_WORK_GetWorkPtr  0x02158FE0  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   SCRCMD_WORK_InitMenu  0x0215A77C  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad[0x14];
    u8 *p;
} Ctx;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern u16 *SCRIPT_WORK_GetWorkPtr(void *a, void *b, unsigned int id);
extern void *SCRIPT_WORK_GetWordSet(void *p);
extern u32 SCRCMD_WORK_InitMenu(u32, u32, u32, u32, u32, u32, u32, u32, u32);

int SCRCMD_MSGWIN_CmdInitMenu(Ctx *c, u32 b)
{
    u8 *q;
    u32 v0, v1, v2, v3, r;
    void *t0;
    void *t1;

    t0 = SCRCMD_WORK_GetScriptWork((void *)b);
    t1 = SCRCMD_WORK_GetGameData((void *)b);
    v0 = *c->p;
    c->p = c->p + 1;
    v1 = *c->p;
    c->p = c->p + 1;
    v2 = SCRIPT_WORK_ReadWorkValue(c, (void *)b);
    q = c->p;
    v3 = q[0];
    c->p = q + 1;
    r = (u32)SCRIPT_WORK_GetWorkPtr(t0, t1, VM_GetU16((struct Stream *)c));
    SCRCMD_WORK_InitMenu(b, v0, v1, v2, v3, 0, r, (u32)SCRIPT_WORK_GetWordSet(t0), 0);
    return 1;
}
