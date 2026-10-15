/*
 * function: SCRCMD_BufferConvertedEntryName
 * address:  0x021AF844
 * packet:   pkt_ov021_021AF844
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
 *   FILE_UTIL_Get_12B0  0x020212B0  thumb  arm9
 *   WORDSET_SetSlotFromMsgCB  0x0201EF34  thumb  arm9
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
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern u32 FILE_UTIL_Get_12B0(u32 a);
extern void WORDSET_SetSlotFromMsgCB(struct WordSet *p, u32 i, u32 v);

int SCRCMD_BufferConvertedEntryName(Ctx *s, u32 b)
{
    u32 w = (u32)SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork((void *)b));
    u8 c = Ctx_ReadByte(s);

    WORDSET_SetSlotFromMsgCB((struct WordSet *)w, c, FILE_UTIL_Get_12B0(SCRIPT_WORK_ReadWorkValue(s, (void *)b)));
    return 0;
}
