/*
 * function: WIFICLUB_StateOpenAnswerMenu
 * address: 0x021C0858
 * packet: pkt_ov099_021C0858
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x0203CB00 and unlabelled ov099 0x021BDD98 lack outside witnesses.
 * blocker: 0x0203CB00 ARM verified MATCH, 52 bytes; copied from
 *   ov099_func_021BEB68.c (leaf-cb00-r1.log); no retry of the integrator's blocker.
 *   extern char *d_021469DC;
 *   extern void GFL_NET_STATE_FatalError(void);
 *   int GFL_NET_STATE_IsFatalError(void) {
 *       if (d_021469DC != 0) {
 *           if (*(void **)(d_021469DC + 8) == (void *)GFL_NET_STATE_FatalError) return 1;
 *       }
 *       return 0;
 *   }
 *   symbols: d_021469DC 0x021469DC data; GFL_NET_STATE_FatalError 0x0203CADC arm.
 *   Leaf's unresolved site is ARM9 0x0203CADC. No overlay leaf filed.
 * note (2026-10-04, lane17): lane17 wave D2: leaf WIFICLUB_IsActivePhase (16 bytes, range test) filed EXACT as src/matched/ov/ov099_func_021BDD98.c. The 0x021BDD98 relocation still reports no witness because it has no shard yet; re-run after the integrator registers the leaf. Body and other 10 relocations are byte-correct.
 * note (2026-10-05, wD9r lane82): the enum-typed offset local (a stand-in) is removed. The real
 *   form is a pointer local `st = p + 0x24c;` set as the first statement and passed to
 *   WIFICLUB_GetStatusKind/WIFICLUB_GetStatusPhase; the other uses are plain p + 0x274 and p + 0x1cc. mwcc keeps 0x24C
 *   in r5 and derives 0x274/0x1CC from it, as in the image. EXACT in c99 and c. Writing the other
 *   uses as st + 0x28 / st - 0x80 gives DIFF.
 *
 * symbols:
 *   GFL_NET_STATE_IsFatalError 0x0203CB00 arm
 *   WIFICLUB_OnFatalError 0x021BE900 thumb ov099
 *   WIFICLUBACTOR_GetPickResult 0x021B97F4 thumb ov099
 *   WIFICLUB_FindPeerActor 0x021BE2A8 thumb ov099
 *   WIFICLUB_UpdateTalkStream 0x021BA928 thumb ov099
 *   WIFICLUB_GetStatusKind 0x021BDD48 thumb ov099
 *   WIFICLUB_GetStatusPhase 0x021BDD54 thumb ov099
 *   WIFICLUB_CreateAnswerMenu 0x021BAD74 thumb ov099
 *   WIFICLUB_IsActivePhase 0x021BDD98 thumb ov099
 *   WIFICLUBACTOR_RestoreActorUpdate 0x021B9AE0 thumb ov099
 */
extern int GFL_NET_STATE_IsFatalError(void);
extern void WIFICLUB_OnFatalError(char *);
extern int WIFICLUBACTOR_GetPickResult(char *);
extern void *WIFICLUB_FindPeerActor(char *,int);
extern int WIFICLUB_UpdateTalkStream(char *);
extern unsigned char WIFICLUB_GetStatusKind(char *,void *);
extern int WIFICLUB_GetStatusPhase(char *,void *);
extern void WIFICLUB_CreateAnswerMenu(char *);
extern int WIFICLUB_IsActivePhase(int);
typedef unsigned char  u8;
extern void WIFICLUBACTOR_RestoreActorUpdate(void *w, u8 *s);
int WIFICLUB_StateOpenAnswerMenu(char *p,int ret) {
    void *q; unsigned r; int v;
    char *st;
    st=p+0x24c;
    if(GFL_NET_STATE_IsFatalError()){WIFICLUB_OnFatalError(p);return ret;}
    q=WIFICLUB_FindPeerActor(p,WIFICLUBACTOR_GetPickResult(p+0x274));
    if(!WIFICLUB_UpdateTalkStream(p))return ret;
    r=WIFICLUB_GetStatusKind(p,st);
    v=WIFICLUB_GetStatusPhase(p,st);
    switch(r) {
    case 1: WIFICLUB_CreateAnswerMenu(p); *(int *)(p+0x1cc)=64;break;
    case 2: case 5:
        if(WIFICLUB_IsActivePhase(v)){WIFICLUB_CreateAnswerMenu(p);*(int *)(p+0x1cc)=36;break;}
    case 0: case 3: case 4: default:
        WIFICLUBACTOR_RestoreActorUpdate(p+0x274,q);
        *(int *)(p+0x1cc)=113;
        break;
    }
    return ret;
}
