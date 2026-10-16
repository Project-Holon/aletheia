/*
 * function: PMS_INPUT_PickWord
 * address: 0x021BF444
 * packet: pkt_ov110_021BF444
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x020245A0 Thumb; no witness outside caller range.
 *   Verified EXACT (blocker-r1.log), 12 bytes:
 *   void PMSI_PARAM_SetWordAt(u8 *p,unsigned i,u16 v) {
 *       if(i<2) *(u16 *)(p+4+2*i)=v;
 *   }
 * symbols:
 *   PMS_WORDLIST_GetSelectedIndex 0x021BEDD0 thumb ov110
 *   PMS_INPUT_DATA_GetCategoryWordId 0x021B99C4 thumb ov110
 *   PMSI_SEARCH_GetResultWordId 0x021BB1E4 thumb ov110
 *   PMS_INPUT_VIEW_GetEditEntry 0x021BABF4 thumb ov110
 *   PMSI_PARAM_SetWordAt 0x020245A0 thumb
 *   PMS_INPUT_IsComplete 0x021BF680 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern unsigned PMS_WORDLIST_GetSelectedIndex(u8 *p);
extern unsigned short PMS_INPUT_DATA_GetCategoryWordId(unsigned int a, unsigned int b, unsigned int c);
extern u16 PMSI_SEARCH_GetResultWordId(u32 p, u32 i);
extern int PMS_INPUT_VIEW_GetEditEntry(u8 *p, int i);
extern void PMSI_PARAM_SetWordAt(u8 *p, unsigned i, u16 v);
extern int PMS_INPUT_IsComplete(u8 *);
int PMS_INPUT_PickWord(u8 *p) {
    int i=*(u16 *)(p+98);
    u16 v;
    if(i==65535) i=PMS_WORDLIST_GetSelectedIndex(p+84);
    if(p[105]==0) v=PMS_INPUT_DATA_GetCategoryWordId((unsigned int)(*(void **)(p+24)),*(u16 *)(p+76),i);
    else v=PMSI_SEARCH_GetResultWordId((u32)(*(void **)(p+28)),i);
    switch(*(u32 *)(p+4)) {
    case 0: *(u16 *)(p+16)=v; break;
    case 1: *(u16 *)(p+16+2* *(u16 *)(p+74))=v; break;
    case 2: PMSI_PARAM_SetWordAt(p+8,PMS_INPUT_VIEW_GetEditEntry(*(void **)(p+20),*(u16 *)(p+74)),v); break;
    }
    return PMS_INPUT_IsComplete(p);
}
