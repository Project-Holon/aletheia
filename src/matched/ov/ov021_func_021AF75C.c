/*
 * function: SCRCMD_BufferPlayerName
 * address:  0x021AF75C
 * packet:   pkt_ov021_021AF75C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   GAME_DATA_GetMyStatus  0x02012944  thumb  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct Ctx { u32 f0; u32 f4; u32 f8; u32 fc; u32 f10; u8 *pc; } Ctx;

static inline u8 Ctx_ReadByte(Ctx *s)
{
    u8 v = *s->pc;

    s->pc++;
    return v;
}

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameData(void *a0);
struct WordSet;
extern int SCRIPT_WORK_ResetFieldParam(int a0);
extern void *SCRIPT_WORK_GetWordSet(void *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);

int SCRCMD_BufferPlayerName(Ctx *s, u32 b)
{
    void *x = SCRCMD_WORK_GetScriptWork((void *)b);
    u32 y;
    u32 w;

    SCRIPT_WORK_ResetFieldParam((int)x);
    y = (u32)GAME_DATA_GetMyStatus(SCRCMD_WORK_GetGameData((void *)b));
    w = (u32)SCRIPT_WORK_GetWordSet(x);
    func_0201F02C((struct WordSet *)w, Ctx_ReadByte(s), (void *)y);
    return 0;
}
