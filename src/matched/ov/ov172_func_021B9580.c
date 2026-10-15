/*
 * function: CTVT_TALK_HandleInput
 * address: 0x021B9580
 * packet: pkt_ov172_021B9580
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 wD4 lane03: EXACT. The 0xa4 store is written in each arm (= 2, = 2, = 0)
 *   instead of a local x stored once; tail merging then keeps the later x=2 copy and the first
 *   arm becomes the b stub, as in the listing.
 * symbols:
 *   COMM_TVT_SYS_GetComm 0x021BDFE4 thumb ov172
 *   COMM_TVT_SYS_GetMemberCount 0x021BE054 thumb ov172
 *   CTVT_TALK_CheckEnd 0x021B9DF8 thumb ov172
 *   COMM_TVT_SYS_GetViewSwapped 0x021BE0B4 thumb ov172
 *   COMM_TVT_SYS_GetCamView 0x021BDFDC thumb ov172
 *   CTVT_CAMVIEW_SetCameraEffect 0x021B7B3C thumb ov172
 *   CTVT_MIC_IsCaptureDone 0x021BA270 thumb ov172
 *   func_021B8B5C 0x021B8B5C thumb ov172
 *   func_021B8B68 0x021B8B68 thumb ov172
 *   func_021B8740 0x021B8740 thumb ov172
 *   CTVT_TALK_HitCenter 0x021B9F4C thumb ov172
 *   COMM_TVT_SYS_ToggleViewSwapped 0x021BE0B8 thumb ov172
 *   COMM_TVT_SYS_GetSelfSlot 0x021BE0A4 thumb ov172
 *   CTVT_CAMVIEW_IsLayoutChanging 0x021B77B4 thumb ov172
 *   COMM_TVT_SYS_ToggleHalfRes 0x021BE08C thumb ov172
 *   CTVT_TALK_HandleLevelSlider 0x021B99F4 thumb ov172
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   func_020355D8 0x020355D8 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   d_021C6F83 0x021C6F83 data a1
 *   d_021C6F77 0x021C6F77 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern u32 COMM_TVT_SYS_GetComm(void *);
extern u8 COMM_TVT_SYS_GetMemberCount(void *p);
extern int CTVT_TALK_CheckEnd(void *p, int *out);
extern u32 COMM_TVT_SYS_GetViewSwapped(void *);
extern u32 COMM_TVT_SYS_GetCamView(void *);
extern void CTVT_CAMVIEW_SetCameraEffect(int x, int y, int z);
extern int CTVT_MIC_IsCaptureDone(void *p);
extern u32 func_021B8B5C(void *, u32);
extern u8 func_021B8B68(int unused, char *p);
extern u32 func_021B8740(int a, int b, u8 c, u32 d);
extern int CTVT_TALK_HitCenter(int a, int b, int mode);
extern void COMM_TVT_SYS_ToggleViewSwapped(void *);
extern u32 COMM_TVT_SYS_GetSelfSlot(void *);
extern u32 CTVT_CAMVIEW_IsLayoutChanging(int unused, void *p);
extern void COMM_TVT_SYS_ToggleHalfRes(void *);
extern void CTVT_TALK_HandleLevelSlider(void *unused, u8 *q);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_HitTrg(const void *);
extern void func_020355D8(u8 v);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void CLACT_SetActorAnimSeq(struct Obj *, u16);
extern void CLACT_SetActorAutoAnim(struct Obj *, u32);
extern const u8 d_021C6F83[];
extern const u8 d_021C6F77[];

void CTVT_TALK_HandleInput(u8 *c, u8 *q)
{
    u32 a = COMM_TVT_SYS_GetComm(c);
    u32 b = COMM_TVT_SYS_GetMemberCount(c);
    int r6;

    if (CTVT_TALK_CheckEnd(c, (int *)q) == 1)
        return;
    if (*(int *)q <= 8 && COMM_TVT_SYS_GetViewSwapped(c) == 0) {
        u32 s = COMM_TVT_SYS_GetCamView(c);
        if (KEY_GetTrg() & 0x40) CTVT_CAMVIEW_SetCameraEffect((int)c, s, 0);
        if (KEY_GetTrg() & 0x10) CTVT_CAMVIEW_SetCameraEffect((int)c, s, 5);
        if (KEY_GetTrg() & 0x80) CTVT_CAMVIEW_SetCameraEffect((int)c, s, 1);
        if (KEY_GetTrg() & 0x20) CTVT_CAMVIEW_SetCameraEffect((int)c, s, 3);
    }
    if (b == 1 || CTVT_MIC_IsCaptureDone((void *)(*(u32 *)(q + 0x10))) == 0) {
        *(int *)(q + 0xa4) = 2;
    } else {
        u32 t = func_021B8B5C(c, a);
        u32 u = func_021B8B68((int)c, (char *)a);
        if (u != 0xff) {
            if (u == t) {
                u32 k = q[0xc];
                if (k) {
                    k--;
                    q[0xc] = k;
                } else if (func_021B8740((int)c, a, 9, 0) == 1) {
                    q[0xc] = 8;
                }
            }
            *(int *)(q + 0xa4) = 2;
        } else {
            u32 r = CTVT_TALK_HitCenter((int)c, (int)q, 0);
            if ((KEY_GetTrg() & 0x101) || r == 1) {
                *(int *)q = 6;
                GFL_USE_PlaySeDefaultVolume(0x66C);
                *(int *)(q + 0x34) = 1;
                q[0x38] = 0;
            }
            *(int *)(q + 0xa4) = 0;
        }
    }
    if (*(int *)q == 5) {
        if ((KEY_GetTrg() & 0x400) || (KEY_GetTrg() & 0x400) || TOUCHPANEL_HitTrg(d_021C6F83) != -1) {
            *(int *)q = 3;
            *(int *)(q + 4) = 6;
            CLACT_SetActorAnimSeq(*(struct Obj **)(q + 0x9c), 0x14);
            CLACT_SetActorAutoAnim(*(struct Obj **)(q + 0x9c), 1);
            GFL_USE_PlaySeDefaultVolume(0x66C);
        }
    }
    if (*(int *)q == 5) {
        r6 = TOUCHPANEL_HitTrg(d_021C6F77);
        if (r6 == 0 || (KEY_GetTrg() & 2)) {
            if (r6 == 0) func_020355D8(1); else func_020355D8(0);
            *(int *)q = 9;
            GFL_USE_PlaySeDefaultVolume(0x551);
            CLACT_SetActorAnimSeq(*(struct Obj **)(q + 0x98), 9);
        } else if (r6 == 1 || (KEY_GetTrg() & 0xc)) {
            COMM_TVT_SYS_ToggleViewSwapped(c);
            GFL_USE_PlaySeDefaultVolume(0x66F);
            if (COMM_TVT_SYS_GetViewSwapped(c) == 1)
                CLACT_SetActorAnimSeq(*(struct Obj **)(q + 0x94), 0x15);
            else
                CLACT_SetActorAnimSeq(*(struct Obj **)(q + 0x94), 0x16);
        }
    }
    if (COMM_TVT_SYS_GetSelfSlot(c) == 0 && (KEY_GetTrg() & 0x200)) {
        if (CTVT_CAMVIEW_IsLayoutChanging((int)c, (void *)COMM_TVT_SYS_GetCamView(c)) == 0) {
            COMM_TVT_SYS_ToggleHalfRes(c);
            GFL_USE_PlaySeDefaultVolume(0x66C);
        }
    }
    CTVT_TALK_HandleLevelSlider(c, q);
}
