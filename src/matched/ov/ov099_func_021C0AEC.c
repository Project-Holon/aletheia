/*
 * function: WIFICLUB_StateAnswerMenu
 * address: 0x021C0AEC
 * packet: pkt_ov099_021C0AEC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x0203CB00 has no outside code witness; its blx at
 *   021C0B16 is the only open site, every other relocation resolves.
 * blocker: 0x0203CB00 ARM verified MATCH, 52 bytes, wave 82 R9 leaf run.
 *   extern char *d_021469DC;
 *   extern void GFL_NET_STATE_FatalError(void);
 *   int GFL_NET_STATE_IsFatalError(void) {
 *       if (d_021469DC != 0) {
 *           if (*(void **)(d_021469DC + 8) == (void *)GFL_NET_STATE_FatalError) return 1;
 *       }
 *       return 0;
 *   }
 *   symbols: d_021469DC 0x021469DC data; GFL_NET_STATE_FatalError 0x0203CADC arm.
 *   Leaf's only unresolved site is ARM9 0x0203CADC.
 * note: the earlier DIFF338 came from a guard-then-return spelling of the
 *   record compare; the image places the mismatch arm (021C0BDE) before the
 *   early return (021C0BFC), so the test is written as `!= || !=` with the
 *   return in the else.
 * volatile: none.
 * symbols:
 *   BMP_MENULIST_Main 0x020200CC thumb
 *   WIFICLUBACTOR_GetPickResult 0x021B97F4 thumb ov099
 *   WIFICLUB_FindPeerActor 0x021BE2A8 thumb ov099
 *   GFL_NET_STATE_IsFatalError 0x0203CB00 arm
 *   WIFICLUB_DeleteWindow 0x021BA8BC thumb ov099
 *   BMP_MENULIST_Delete 0x0202020C thumb
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   WIFICLUBACTOR_RestoreActorUpdate 0x021B9AE0 thumb ov099
 *   WIFICLUB_OnFatalError 0x021BE900 thumb ov099
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   WIFICLUB_SetPartnerNameWord 0x021BA874 thumb ov099
 *   WIFICLUB_ShowStreamedMessage 0x021BAAB8 thumb ov099
 *   WIFICLUB_GetFriendStatus 0x021C23B8 thumb ov099
 *   WIFICLUB_GetStatusKind 0x021BDD48 thumb ov099
 *   WIFICLUB_GetStatusSeatFlag 0x021C27E0 thumb ov099
 *   WIFICLUB_GetStatusPhase 0x021BDD54 thumb ov099
 *   WIFICLUB_TryStartPartnerRequest 0x021C08F8 thumb ov099
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
struct Obj;
extern s32 BMP_MENULIST_Main(struct Obj *);
extern u8 WIFICLUBACTOR_GetPickResult(char *);
extern void *WIFICLUB_FindPeerActor(char *, int);
extern int GFL_NET_STATE_IsFatalError(void);
extern int WIFICLUB_DeleteWindow(void *);
extern void BMP_MENULIST_Delete(struct Obj *, u16 *, u16 *);
extern u32 BMP_MENUWORK_Delete(void *p);
extern void WIFICLUBACTOR_RestoreActorUpdate(void *, u8 *);
extern void WIFICLUB_OnFatalError(char *);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void WIFICLUB_SetPartnerNameWord(char *, int);
extern void WIFICLUB_ShowStreamedMessage(char *, int, int);
extern int WIFICLUB_GetFriendStatus(int);
extern u8 WIFICLUB_GetStatusKind(char *, void *);
extern u8 WIFICLUB_GetStatusSeatFlag(void *);
extern u8 WIFICLUB_GetStatusPhase(char *, void *);
extern int WIFICLUB_TryStartPartnerRequest(char *);
extern void WIFICLUB_ClearTalkWindow(char *);
int WIFICLUB_StateAnswerMenu(char *p, int ret)
{
    int changed;
    s32 choice;
    int n;
    u8 *q;
    int state;
    int other;
    changed = 0;
    choice = BMP_MENULIST_Main(*(struct Obj **)(p + 0xbc));
    n = WIFICLUBACTOR_GetPickResult(p + 0x274);
    q = WIFICLUB_FindPeerActor(p, n);
    if (GFL_NET_STATE_IsFatalError()) {
        *(int *)(p + 0x1a4) = WIFICLUB_DeleteWindow(*(void **)(p + 0x1a4));
        BMP_MENULIST_Delete(*(struct Obj **)(p + 0xbc), 0, 0);
        BMP_MENUWORK_Delete(*(void **)(p + 0xb8));
        if (q)
            WIFICLUBACTOR_RestoreActorUpdate(p + 0x274, q);
        WIFICLUB_OnFatalError(p);
        return ret;
    }
    switch (choice) {
    case -1:
        if (q == 0) {
            BMP_MENULIST_Delete(*(struct Obj **)(p + 0xbc), 0, 0);
            WIFICLUB_SetPartnerNameWord(p, n - 1);
            WIFICLUB_ShowStreamedMessage(p, 13, 0);
            *(int *)(p + 0x1cc) = 0x15;
            changed = 1;
        } else {
            state = WIFICLUB_GetFriendStatus(n - 1);
            WIFICLUB_GetStatusKind(p, (void *)state);
            changed = WIFICLUB_GetStatusSeatFlag((void *)state);
            other = WIFICLUB_GetStatusPhase(p, (void *)state);
            if (other != WIFICLUB_GetStatusPhase(p, p + 0x24c) || changed != WIFICLUB_GetStatusSeatFlag(p + 0x24c)) {
                WIFICLUB_SetPartnerNameWord(p, n - 1);
                WIFICLUB_ShowStreamedMessage(p, 13, 0);
                *(int *)(p + 0x1cc) = 0x15;
                changed = 1;
            } else {
                return ret;
            }
        }
        break;
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        *(int *)(p + 0x1cc) = 11;
        break;
    default:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        if (choice == 1) {
            *(int *)(p + 0x1cc) = 11;
            WIFICLUB_TryStartPartnerRequest(p);
        } else if (choice == 2) {
            *(int *)(p + 0x1cc) = 0x2e;
        }
        break;
    }
    if (changed == 0)
        WIFICLUB_ClearTalkWindow(p);
    *(int *)(p + 0x1a4) = WIFICLUB_DeleteWindow(*(void **)(p + 0x1a4));
    BMP_MENULIST_Delete(*(struct Obj **)(p + 0xbc), 0, 0);
    BMP_MENUWORK_Delete(*(void **)(p + 0xb8));
    if (q)
        WIFICLUBACTOR_RestoreActorUpdate(p + 0x274, q);
    return ret;
}
