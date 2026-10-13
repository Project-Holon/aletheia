/*
 * function: SCRCMD_GetPartnerGreetingMessageFromScript
 * address:  0x021D00B8
 * packet:   pkt_ov021_021D00B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveSyncBlock  0x02012F38  thumb
 *   VM_GetU16  0x02011330  thumb
 *   SCRCMD_GetPartnerGreetingMessage  0x021CFD08  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
struct Stream;
extern void *SCRIPT_WORK_GetWordSet(void *p);
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern int GAME_DATA_GetSaveSyncBlock(int base);
extern u16 VM_GetU16(struct Stream *s);
extern int SCRCMD_GetPartnerGreetingMessage(u32 a, u32 b, u8 *c, int d, u32 e);

int SCRCMD_GetPartnerGreetingMessageFromScript(u32 a, u32 b)
{
    u32 s, k, g;
    void *p;
    void *x;
    u8 *f;
    u16 *out;

    p = SCRCMD_WORK_GetScriptWork((void *)b);
    x = SCRCMD_WORK_GetGameSystem((void *)b);
    f = (u8 *)GAME_DATA_GetSaveSyncBlock((int)GAMESYSTEM_GetGameData(x));
    s = (u32)SCRIPT_WORK_GetWordSet(p);
    k = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    g = VM_GetU16((struct Stream *)a);
    out = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    *out = SCRCMD_GetPartnerGreetingMessage(s, (u32)x, f, k, g);
    return 0;
}
