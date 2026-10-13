/*
 * function: SCRCMD_PROC_FLD_CallCustomEvent
 * address:  0x021B5528
 * packet:   pkt_ov021_021B5528
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   FIELD_CAMERA_CreateShakeTask  0x021D2D50  thumb  ov021
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 h0;
    u16 h2;
    u16 h4;
    u16 h6;
    u16 h8;
    u16 ha;
    u16 hc;
    u8 be;
    u8 bf;
    u32 w10;
    u32 w14;
} Rec;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Blk021D2D50;
extern void *FIELD_CAMERA_CreateShakeTask(void *a, struct Blk021D2D50 *src);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_PROC_FLD_CallCustomEvent(int a0, int a1)
{
    int v0 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    int v1 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    int v2 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    int v3 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    int v4 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    int v5 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    int v6 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    int v7 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    void *r;
    void *o;
    Rec s;

    r = SCRCMD_WORK_GetScriptWork((void *)a1);
    o = SCRCMD_WORK_GetGameSystem((void *)a1);
    s.h0 = v0;
    s.h2 = v1;
    s.w10 = v2;
    s.bf = v3;
    s.be = v3;
    s.w14 = 0;
    s.h4 = v4;
    s.h6 = v5;
    s.h8 = v6;
    s.ha = 0;
    s.hc = v7;
    SCRIPT_SYS_CallEvent(r, FIELD_CAMERA_CreateShakeTask((void *)o, (struct Blk021D2D50 *)(&s)));
    return 1;
}
