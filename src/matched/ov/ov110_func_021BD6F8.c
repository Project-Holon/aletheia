/*
 * function: PMS_INPUT_PrevSentence
 * address: 0x021BD6F8
 * packet: pkt_ov110_021BD6F8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   PMSI_PARAM_GetSentenceCount  0x02024584  thumb  arm9
 *   PMSI_PARAM_SetSentenceId  0x02024598  thumb  arm9
 */
typedef signed char s8;
typedef short s16;
typedef struct { s16 a; s8 b,c; } State;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u8 PMSI_PARAM_GetSentenceCount(u32 i);
extern void PMSI_PARAM_SetSentenceId(void *,int,int);
void PMS_INPUT_PrevSentence(State *p,void *out) {
 p->b--;
 if(p->b<0) { p->a--; if(p->a<0) p->a=4; p->c=PMSI_PARAM_GetSentenceCount(p->a); p->b=p->c-1; }
 PMSI_PARAM_SetSentenceId(out,p->a,p->b);
}
