/*
 * function: SCRCMD_BufferGroupedEntryName
 * address:  0x021AFB2C
 * packet:   pkt_ov021_021AFB2C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   WORDSET_SetSlotFromMsgE7  0x0201F048  thumb  arm9
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
struct WordSet;
extern void *SCRIPT_WORK_GetWordSet(void *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);

extern void WORDSET_SetSlotFromMsgE7(struct WordSet *p, u32 i, u32 n);

int SCRCMD_BufferGroupedEntryName(Ctx *s, u32 b)
{
    u32 w = (u32)SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork((void *)b));
    u8 c = Ctx_ReadByte(s);

    WORDSET_SetSlotFromMsgE7((struct WordSet *)w, c, SCRIPT_WORK_ReadWorkValue(s, (void *)b));
    return 0;
}
