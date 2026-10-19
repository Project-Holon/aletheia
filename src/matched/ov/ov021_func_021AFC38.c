/*
 * function: SCRCMD_BufferBeaconThanksCount
 * address:  0x021AFC38
 * packet:   pkt_ov021_021AFC38
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
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   MISC_GetBlock  0x0200C0F0  thumb
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   MISC_GetThanksCount  0x0200C1DC  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 */

typedef unsigned char u8;

typedef struct {
    char pad[0x14];
    u8 *cur;
} Ctx;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameData(void *a0);
typedef unsigned int   u32;
struct Big;
struct Blk34;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *MISC_GetBlock(void *sys);
struct WordSet;
extern void *SCRIPT_WORK_GetWordSet(void *p);
extern u32 MISC_GetThanksCount(struct Blk34 *p);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);

int SCRCMD_BufferBeaconThanksCount(Ctx *a0, int a1)
{
    void *t = SCRCMD_WORK_GetScriptWork((void *)a1);
    void *h;
    int r;
    u8 *p;
    int b;

    h = MISC_GetBlock(GAME_DATA_GetSaveControl(SCRCMD_WORK_GetGameData((void *)a1)));
    r = (int)SCRIPT_WORK_GetWordSet(t);
    p = a0->cur;
    b = *p;
    a0->cur = p + 1;
    WORDSET_SetSlotNumber((struct WordSet *)r, b, MISC_GetThanksCount(h), 9, 1, 1);
    return 0;
}
