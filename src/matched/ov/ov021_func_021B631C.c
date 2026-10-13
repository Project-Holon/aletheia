/*
 * function: SCRCMD_POKEMON_FLD_StartSelectEvent
 * address:  0x021B631C
 * packet:   pkt_ov021_021B631C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_CreateNicknameEvent  0x021C5AAC  thumb  ov021
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern int SCRCMD_CreateNicknameEvent(void *a, int b, int c, int d);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_POKEMON_FLD_StartSelectEvent(u32 a, u32 b)
{
    void *x;
    void *y;
    u16 *p;
    u32 q;

    x = SCRCMD_WORK_GetScriptWork((void *)b);
    y = SCRCMD_WORK_GetGameSystem((void *)b);
    p = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    q = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    SCRIPT_SYS_CallEvent(x, (void *)SCRCMD_CreateNicknameEvent(y, (int)p, q, SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b)));
    return 1;
}
