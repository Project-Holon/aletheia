/*
 * function: BR_POKESEARCH_CreateText
 * address: 0x021F8E90
 * packet: pkt_ov185_021F8E90
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: 2026-10-04 (D2-13): body is byte-correct. Callee BR_UTIL_CreateProfileScreen (ov186, 0x021FD1C4) is a 1148-byte function in pengy's ov186 split with no witness (its listing extent shows 64 bytes, a wrong label gap); the relocation cannot resolve until it is filed. No change possible here.
 * blocker: ov186021FD1C4 has no outside witness. Complete 1148-byte body
 * has a seven-case resource loop, nested branches, stack aggregates and
 * many calls; no mechanical whole-body lever. W29 S24 evidence agrees.
 * tu --suggest-split confirms no viable partition; no speculative leaf C.
 * note 2026-10-05 (D4-14): re-run, still MATCH, only BR_UTIL_CreateProfileScreen (ov186, pengy split) unresolved. No change.
 * note 2026-10-05 (D8-02): re-run, still MATCH. show --region ov186 at 0x021FD1C4 starts with push {r3-r7,lr},
 *   a real 1148-byte function in pengy's ov186 split; outside this lane's write set. No change.
 *
 * symbols:
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_GRAPHIC_GetActorUnit 0x021FC4DC thumb ov186
 *   BR_UTIL_CreateProfileScreen 0x021FD1C4 thumb ov186
 *   BR_UTIL_SetTextFromMessage 0x021FC754 thumb ov186
 */
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern unsigned BR_RES_GetFont(char *p);
extern int BR_RES_GetMsgData(char *);
extern u32 BR_GRAPHIC_GetActorUnit(u8 *p);
extern char *BR_UTIL_CreateProfileScreen(void *prof, char *q, void *a2, void *a3, int mode, u16 heap);
extern void BR_UTIL_SetTextFromMessage(char *,void *,void *,void *,unsigned short);
void BR_POKESEARCH_CreateText(char *p,int *source)
{
    if(*(int *)(p+0x10)==0) {
        int a=BR_RES_GetFont((char *)source[3]);
        int b=BR_RES_GetMsgData((char *)source[3]);
        int c=BR_GRAPHIC_GetActorUnit((u8 *)source[2]);
        *(void **)(p+0x10)=BR_UTIL_CreateProfileScreen(((void **)(p+0x40))[*(unsigned short *)(p+0xc)],(char *)source[3],(void *)c,(void *)(*(int *)(p+0x2c)),1,*(unsigned short *)(p+0x30));
        BR_UTIL_SetTextFromMessage(*(char **)(p+0x1c),(void *)b,(void *)0x72,(void *)a,0x3da0);
    }
}
