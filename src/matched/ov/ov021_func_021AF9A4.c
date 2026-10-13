/*
 * function: SCRCMD_BufferPartyMonNickname
 * address:  0x021AF9A4
 * packet:   pkt_ov021_021AF9A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0201EEF4  0x0201EEF4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad[0x14];
    u8 *cur;
} Script;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *SCRIPT_WORK_GetWordSet(void *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
struct BigObj;
struct WordSet;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void *func_0201AB28(void *, u32);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);

int SCRCMD_BufferPartyMonNickname(Script *a, u32 b)
{
    void *c = SCRCMD_WORK_GetScriptWork((void *)b);
    void *d = SCRCMD_WORK_GetGameData((void *)b);
    u32 x = (u32)SCRIPT_WORK_GetWordSet(c);
    u8 *p = a->cur;
    u32 v = *p;
    u32 e;
    a->cur = p + 1;
    e = SCRIPT_WORK_ReadWorkValue(a, (void *)b);
    func_0201EEF4((void *)x, v, func_0201AB28(GAME_DATA_GetMyParty((void *)d), e));
    return 0;
}
