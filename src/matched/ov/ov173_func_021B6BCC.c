/*
 * function: POKE_SUMMARY_MAIN_RefreshMoveList
 * address: 0x021B6BCC
 * packet: pkt_ov173_021B6BCC
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_SUMMARY_MAIN_GetRecordWord 0x021B7438 thumb ov173
 *   POKE_SUMMARY_MAIN_DrawMoveDetail 0x021B71C4 thumb ov173
 *   POKE_SUMMARY_ACTOR_LayoutMoveActors 0x021B7968 thumb ov173
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 POKE_SUMMARY_MAIN_GetRecordWord(char **);
extern void POKE_SUMMARY_MAIN_DrawMoveDetail(char *,int);
extern void POKE_SUMMARY_ACTOR_LayoutMoveActors(char *);
void POKE_SUMMARY_MAIN_RefreshMoveList(char *p) { int n; n=POKE_SUMMARY_MAIN_GetRecordWord((char **)p); if(n!=65535) POKE_SUMMARY_MAIN_DrawMoveDetail(p,n); else POKE_SUMMARY_MAIN_DrawMoveDetail(p,-2); POKE_SUMMARY_ACTOR_LayoutMoveActors(p); }
