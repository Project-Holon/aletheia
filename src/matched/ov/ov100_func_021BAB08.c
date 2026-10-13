/*
 * function: IRCBATTLEMATCH_StepStartSession
 * address: 0x021BAB08
 * packet: pkt_ov100_021BAB08
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 veneer 0203D0C4 has no outside witness at +BC/+C6.
 *   Exact non-C body: E59FC000,E12FFF1C,0203DA68; unlabelled target.
 *   Data021BB83C resolves sole-ref on the byte-correct 256-byte run.
 *   D0C4 tail-forwards r0 unchanged; full DA68 body reads only that u32,
 *   copies it unchanged to singleton+74, no arithmetic or narrowing.
 *   scratch-only DA68 one --arm (no region), fixed flags: EXACT20, literal15.
 *   Verified C (not filed ARM9): extern unsigned char *gNetIrcWirelessLink;
 *   void GFL_NET_IRC_WIRELESS_SetSessionParamValue(unsigned int value) {
 *       *(unsigned int *)(gNetIrcWirelessLink+0x74)=value;
 *   }
 *   caller-only TU suggest-split MATCH256: two witnesses, both inside this
 *   sole function; zero viable pieces. Do not file overlay leaves while capped.
 * note 2026-10-04 (wD2 lane18): still MATCH, only unresolved relocations remain: callee GFL_NET_IRC_WIRELESS_SetSessionParam (veneer to 0x0203DA68) still has no witness; GFL_NET_IRC_WIRELESS_SetSessionParamValue filed EXACT as src/matched/arm9/GFL_NET_IRC_WIRELESS_SetSessionParamValue.c, integrator must regenerate labels so the veneer resolves.
 * symbols:
 *   gIrcBattleMatchSessionReq 0x021BB83C data a4
 *   GFL_NET_StartSession 0x0203CBAC arm
 *   GFL_NET_IRC_WIRELESS_SetSessionParam 0x0203D0C4 arm
 *   GFL_NET_IRC_WIRELESS_SetRetryRequest 0x0203D164 arm
 *   GFL_NET_SetGameKindOverride 0x0203D0AC arm
 *   IRCBATTLEMATCH_IsCompatibleGameKind 0x021BAAEC thumb ov100
 *   IRCBATTLEMATCH_OpenWaitMenu 0x021BA290 thumb ov100
 *   IRCBATTLEMATCH_SetStep 0x021B95B8 thumb ov100
 *   IRCBATTLEMATCH_StepStartChangeover 0x021BAC80 thumb ov100
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Req {
    u32 first[24];
    u8 a,b,c,d,e,mode,f,kind;
    u32 word68;
    u16 value,limit;
};
extern const struct Req gIrcBattleMatchSessionReq;
extern void GFL_NET_StartSession(struct Req *,u32,u32);
extern void GFL_NET_IRC_WIRELESS_SetSessionParam(u32);
extern void GFL_NET_IRC_WIRELESS_SetRetryRequest(int);
extern void GFL_NET_SetGameKindOverride(int);
extern int IRCBATTLEMATCH_IsCompatibleGameKind(int,int);
extern void IRCBATTLEMATCH_OpenWaitMenu(int,int);
extern void IRCBATTLEMATCH_SetStep(u8 *,u32);
extern void IRCBATTLEMATCH_StepStartChangeover(int);
void IRCBATTLEMATCH_StepStartSession(int p)
{
    struct Req req;
    int zero,q;
    req=gIrcBattleMatchSessionReq;
    req.mode=4;
    switch(*(u32 *)(p+0x24c)) {
    case 1:case 2:case 3:case 4:
        req.kind=12;
        break;
    case 5:
        req.kind=38;
        req.a=4;
        break;
    case 7:
        req.kind=29;
        break;
    case 6:
        req.kind=28;
        break;
    case 11:
        req.kind=44;
        break;
    case 9:
        req.limit=17;
        req.kind=19;
        req.e=1;
        q=*(int *)(p+0x244);
        req.a=*(u8 *)(*(int *)(q+0x20)+0x60);
        req.b=*(u8 *)(*(int *)(q+0x20)+0x61);
        req.value=*(u16 *)(*(int *)(q+0x20)+0x6c);
        *(int *)(p+0xce8)=-1;
        break;
    case 10:
        req.limit=17;
        req.kind=18;
        req.e=1;
        q=*(int *)(p+0x244);
        req.a=*(u8 *)(*(int *)(q+0x20)+0x60);
        req.b=*(u8 *)(*(int *)(q+0x20)+0x61);
        req.value=*(u16 *)(*(int *)(q+0x20)+0x6c);
        *(int *)(p+0xce8)=-1;
        break;
    }
    zero=0;
    GFL_NET_StartSession(&req,0,p);
    switch(*(int *)(p+0x24c)) {
    case 10:
        GFL_NET_IRC_WIRELESS_SetSessionParam((u32)IRCBATTLEMATCH_IsCompatibleGameKind);
        GFL_NET_IRC_WIRELESS_SetRetryRequest(1);
        GFL_NET_SetGameKindOverride(17);
        break;
    case 9:
        GFL_NET_IRC_WIRELESS_SetSessionParam((u32)IRCBATTLEMATCH_IsCompatibleGameKind);
        GFL_NET_IRC_WIRELESS_SetRetryRequest(zero);
        GFL_NET_SetGameKindOverride(17);
        break;
    case 5:
        GFL_NET_SetGameKindOverride(37);
        break;
    }
    IRCBATTLEMATCH_OpenWaitMenu(p,0);
    IRCBATTLEMATCH_SetStep((u8 *)p,(u32)IRCBATTLEMATCH_StepStartChangeover);
}
