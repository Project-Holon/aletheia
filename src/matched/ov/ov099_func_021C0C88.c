/*
 * function: WIFICLUB_StatePartnerMenuResult
 * address:  0x021C0C88
 * packet:   pkt_ov099_021C0C88
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note: 2026-10-05 (wD9r lane72): EXACT 472/472, 31 of 31 relocations. The fix is a pointer local
 *   `st = p + 0x24c;` set at the top of the function (before the first call) and passed to
 *   WIFICLUB_GetStatusPhase and to the first WIFICLUB_GetStatusSeatFlag. With the field address written at each use, mwcc
 *   made 0x24C one constant temp in r6 and derived 0x1CC from it (`subs r6,#0x80`) in the r4 == 5 and
 *   0x76 paths. The early pointer local is propagated after that pass, so each use rebuilds
 *   `movs #0x93; lsls #2` and every 0x1CC store is fresh, as in the image. Same idiom as ov223
 *   021BB18C (docs/idioms/a-spilled-offset-derived-at-the-top-is-an-early-pointer-local.md). The
 *   pointer set just before the WIFICLUB_GetStatusPhase call instead gives 464 B DIFF. Earlier DIFF notes
 *   (wD4 to wD9r) tried struct fields, raw and integer offsets, inline helpers, switch and goto shapes;
 *   the enum-local form from lane61 is not used.
 * symbols:
 *   BMP_MENULIST_Main  0x020200CC  thumb
 *   WIFICLUB_HasNewClientAid  0x021BF050  thumb  ov099
 *   WIFICLUBACTOR_GetPickResult  0x021B97F4  thumb  ov099
 *   WIFICLUB_FindPeerActor  0x021BE2A8  thumb  ov099
 *   GFL_NET_STATE_IsFatalError  0x0203CB00  arm
 *   WIFICLUB_DeleteWindow  0x021BA8BC  thumb  ov099
 *   BMP_MENULIST_Delete  0x0202020C  thumb
 *   BMP_MENUWORK_Delete  0x0201F868  thumb
 *   WIFICLUBACTOR_RestoreActorUpdate  0x021B9AE0  thumb  ov099
 *   WIFICLUB_OnFatalError  0x021BE900  thumb  ov099
 *   WIFICLUB_ClearTalkWindow  0x021BA8EC  thumb  ov099
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   WIFICLUB_GetStatusPhase  0x021BDD54  thumb  ov099
 *   func_0202EB14  0x0202EB14  thumb
 *   func_0202EB0C  0x0202EB0C  thumb
 *   WIFICLUB_ShowStreamedMessage  0x021BAAB8  thumb  ov099
 *   WIFICLUB_HasEnoughPartyMembers  0x021BDDD0  thumb  ov099
 *   WIFICLUB_IsBusyPhase  0x021BDD60  thumb  ov099
 *   WIFICLUB_LoadOwnRegulation  0x021BCC4C  thumb  ov099
 *   WIFICLUB_HasRuleViolation  0x021BDDF4  thumb  ov099
 *   WIFICLUB_GetStatusSeatFlag  0x021C27E0  thumb  ov099
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

struct P { char a[0x1cc]; u32 f1cc; char b[0x7c]; char f24c[4]; };
typedef signed int     s32;
struct Obj;
extern s32 BMP_MENULIST_Main(struct Obj *o);
extern int WIFICLUB_HasNewClientAid(char *p);
extern u8 WIFICLUBACTOR_GetPickResult(char *p);
extern void *WIFICLUB_FindPeerActor(char *p, int key);
extern int GFL_NET_STATE_IsFatalError(void);
extern int WIFICLUB_DeleteWindow(void *p);
extern void BMP_MENULIST_Delete(struct Obj *o, u16 *a, u16 *b);
extern u32 BMP_MENUWORK_Delete(void *p);
extern void WIFICLUBACTOR_RestoreActorUpdate(void *w, u8 *s);
extern void WIFICLUB_OnFatalError(char *p);
extern void WIFICLUB_ClearTalkWindow(char *p);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int WIFICLUB_GetStatusPhase(char *p, char *s);
extern int func_0202EB14(void);
extern u32 func_0202EB0C(void);
extern void WIFICLUB_ShowStreamedMessage(char *p, int a, int b);
extern int WIFICLUB_HasEnoughPartyMembers(char *p);
extern int WIFICLUB_IsBusyPhase(int x);
extern void WIFICLUB_LoadOwnRegulation(void *a);
extern int WIFICLUB_HasRuleViolation(char *p);
extern int WIFICLUB_GetStatusSeatFlag(void *p);

int WIFICLUB_StatePartnerMenuResult(char *p, int v)
{
    int r6;
    int r4;
    int r7;
    char *st;
    u16 t;

    st = p + 0x24c;
    r6 = BMP_MENULIST_Main((struct Obj *)(*(u32 *)(p + 0xbc)));
    if (WIFICLUB_HasNewClientAid(p)) {
        r6 = -2;
    }
    t = WIFICLUBACTOR_GetPickResult(p + 0x274);
    *(u16 *)(p + 0x242) = t;
    r7 = (int)WIFICLUB_FindPeerActor(p, t);
    if (GFL_NET_STATE_IsFatalError()) {
        *(u32 *)(p + 0x1a4) = WIFICLUB_DeleteWindow((void *)(*(u32 *)(p + 0x1a4)));
        BMP_MENULIST_Delete((struct Obj *)(*(u32 *)(p + 0xbc)), 0, 0);
        BMP_MENUWORK_Delete((void *)(*(u32 *)(p + 0xb8)));
        if (r7) {
            WIFICLUBACTOR_RestoreActorUpdate(p + 0x274, (u8 *)r7);
        }
        WIFICLUB_OnFatalError(p);
        return v;
    }
    if (r6 != -1) {
        WIFICLUB_ClearTalkWindow(p);
        *(u32 *)(p + 0x1a4) = WIFICLUB_DeleteWindow((void *)(*(u32 *)(p + 0x1a4)));
        BMP_MENULIST_Delete((struct Obj *)(*(u32 *)(p + 0xbc)), 0, 0);
        BMP_MENUWORK_Delete((void *)(*(u32 *)(p + 0xb8)));
    }
    switch (r6) {
    case -1:
        return v;
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        ((struct P *)p)->f1cc = 0xb;
        goto end;
    }
    GFL_USE_PlaySeDefaultVolume(0x54c);
    r4 = WIFICLUB_GetStatusPhase(p, st);
    if (r4 == 5 && !func_0202EB14() && func_0202EB0C()) {
        WIFICLUB_ShowStreamedMessage(p, 0x95, 0);
        ((struct P *)p)->f1cc = 0xa2;
        return v;
    }
    if (r4 == 6 && !WIFICLUB_HasEnoughPartyMembers(p)) {
        WIFICLUB_ShowStreamedMessage(p, 0x79, 0);
        ((struct P *)p)->f1cc = 0x71;
        goto end;
    }
    if (WIFICLUB_IsBusyPhase(r4)) {
        *(u16 *)(p + 0x134c) = (r4 - 7) / 2;
        *(u16 *)(p + 0x134e) = (r4 - 7) % 2;
        WIFICLUB_LoadOwnRegulation(p);
        if (!WIFICLUB_HasRuleViolation(p)) {
            WIFICLUB_ShowStreamedMessage(p, 0x68, 0);
            ((struct P *)p)->f1cc = 0x71;
        }
    }
    *(u32 *)(p + 0x135c) = 2;
    r4 = WIFICLUB_GetStatusSeatFlag(st);
    if (r4 == WIFICLUB_GetStatusSeatFlag(*(void **)(p + 8))) {
        ((struct P *)p)->f1cc = 0x76;
    } else {
        if (WIFICLUB_GetStatusSeatFlag(*(void **)(p + 8))) {
            WIFICLUB_ShowStreamedMessage(p, 0x49, 0);
        } else {
            WIFICLUB_ShowStreamedMessage(p, 0x48, 0);
        }
        ((struct P *)p)->f1cc = 0x37;
    }
end:
    if (r7) {
        WIFICLUBACTOR_RestoreActorUpdate(p + 0x274, (u8 *)r7);
    }
    return v;
}
