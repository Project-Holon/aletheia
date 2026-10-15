/*
 * function: RESEARCH_GRAPH_GetEntryIdBySave
 * address: 0x021BF910
 * packet: pkt_ov217_021BF910
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   RESEARCH_GRAPH_GetAppResource 0x021BF740 thumb ov217
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   SYMBOL_SAVE_GetBitBlock 0x0200E394 thumb
 *   SYMBOL_SAVE_GetQuestionnaireBits 0x0200E3A0 thumb
 *   RESEARCH_GRAPH_GetGroupKey 0x021BF7CC thumb ov217
 *   RESEARCH_GRAPH_GetPlayTimeGroupId 0x021BF968 thumb ov217
 *   SYMBOL_SAVE_GetQuestionnaireAnswer 0x0200E3A4 thumb
 *   GRAPHTABLE_GetEntryId 0x021C2644 thumb ov217
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Big;
extern u32 RESEARCH_GRAPH_GetAppResource(u8 *);
extern void *GAME_DATA_GetSaveControl(struct Big *);
extern void *SYMBOL_SAVE_GetBitBlock(void *a0);
extern void *SYMBOL_SAVE_GetQuestionnaireBits(void *a);
extern u32 RESEARCH_GRAPH_GetGroupKey(void *);
extern u32 RESEARCH_GRAPH_GetPlayTimeGroupId(u8 *);
extern u32 SYMBOL_SAVE_GetQuestionnaireAnswer(const u8 *, int);
extern u32 GRAPHTABLE_GetEntryId(void *, u32, u8);
u32 RESEARCH_GRAPH_GetEntryIdBySave(u8 *p)
{
    void *bits;
    u32 index;
    u16 n;
    bits = SYMBOL_SAVE_GetQuestionnaireBits(SYMBOL_SAVE_GetBitBlock(GAME_DATA_GetSaveControl((struct Big *)RESEARCH_GRAPH_GetAppResource(p))));
    index = RESEARCH_GRAPH_GetGroupKey(p);
    if (index == 29) return RESEARCH_GRAPH_GetPlayTimeGroupId(p);
    n = SYMBOL_SAVE_GetQuestionnaireAnswer((const u8 *)bits, index);
    if (n == 0) return 0;
    n--;
    return (u8)GRAPHTABLE_GetEntryId(p + 0x38, p[0x2b8], n);
}
