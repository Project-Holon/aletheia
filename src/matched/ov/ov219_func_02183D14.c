/*
 * function: BEACON_DETAIL_Update
 * address:  0x02183D14
 * packet:   pkt_ov219_02183D14
 * region:   ov219
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     2026-10-04 wave D3 lane 04: complete draft, same size (1884 bytes). The
 *           remaining residue is cross-jump (tail merge) direction only. In the original
 *           every "*state = X; SE(0x54C); break" tail (case 4 arms, case 9, case 17) jumps
 *           into the case 12 copy at 0x218400C, and the 0x551 tails jump into the case 9
 *           copy at 0x2183F8E. Natural C keeps the FIRST copy (case 4) instead. The draft
 *           uses gotos (n = X; goto snd54c / snd551) in case 4, which fixes case 4, but the
 *           case 9 0x54C tail still stays a full copy (case 12 then jumps to it); a goto in
 *           case 9 too lets the compiler thread the 0xA arm past the hop at 0x2183F8A.
 *           Tried: inner switch arm orders (case 0/default first, last, split), case 9 with
 *           SE in each arm, reversed outer case order (layout follows source, worse).
 *           Found and fixed: switch value u32 (compare tree, 0xFFFFFFFE case), switch on
 *           BMP_MENU_ProcessYesNo result cast to u32 in cases 6 and 15, case 19 written before
 *           case 18 (original block order), stack locals ids, count, tmp, old (int).
 *           d_02185xxx data words are sole references (MATCH at best once bytes agree).
 *           2026-10-05 wave D4 lane 08: still DIFF (84 lines, the draft above is unchanged). The original keeps
 *           ONE copy of `str r0,[r5]; ldr =0x54C; bl SE; b end` in case 12 (0x218400C) and every other 0x54C, 0x551,
 *           0x648, 0x649 tail jumps into it (case 17 to 0x218400E, 0x648/0x649 and case 9's 0x551 to the bl at
 *           0x2184010); case 9's arms join at a hop (0x2183F8A b 0x218400C), so case 9 had its own copy at threading
 *           time and lost it to cross-jumping later. Tried: case 9 arms `*state = X; goto se54c` (per arm, or one goto
 *           after the if) with a label on the SE call in case 12: case 12's label block then merges into case 17's
 *           copy instead (530 lines, worse). The survivor rule seems to drop the multi-predecessor label block.
 *           2026-10-05 wave D5 lane 05: unchanged DIFF (154 bytes, 84 lines). The original keeps case 12's
 *           copy for EVERY shared tail (0x54C store+call, the case 9 0x551 call, case 17), i.e. the LAST copy in
 *           source order, while every form here keeps the first. Tried: case 9 as an inner switch (default
 *           arm, case 0xFFFFFFFE arm): byte-identical output; fully natural C (no gotos): case 4 copies survive
 *           (381 bytes); case 9 arms `*state = X; goto se54c` plus case 17 `goto se54c` with se54c on the SE
 *           call in case 12: case 12 survives for 0x54C but case 9 arms skip the hop and case 12's call merges
 *           into case 9's 0x551 copy (291 bytes); case 9 arms `n = X; goto snd54c`: 6 bytes short (1004).
 *           2026-10-05 wave D6 lane 03: MATCH (0 concrete bytes differ). Two fixes. (1) Logic: the
 *           0x400 branches of case 17 test and set W(0xC350), not W(0xC33C) (the pool word read is
 *           0xC350; the old draft differed by one pool slot only). (2) Tail shape: case 9 sets n in each
 *           arm, then `*state = n; goto se54c;` (one store after the join; cross-jumping later turns
 *           that join into the hop at 0x2183F8A); se54c sits on `m = 0x54C;` in case 12, followed by
 *           a `call:` label on `GFL_USE_PlaySeDefaultVolume(m)`; the case 9 0x551 path does `m = 0x551; goto call;`;
 *           case 17 writes `if (W(0xC350) != 1) break; goto se54c;`. The 0x648/0x649 calls then
 *           merge into case 12's call by themselves. d_02185DE6 hint token dropped (contested).
 *           Remaining: three callees with no witness: arm9 BMP_OAM_Update5BE8 and GAME_BEACON_SetNationArea and ov219
 *           BEACON_DETAIL_Init3DParams. This lane filed all three EXACT (src/matched/arm9/BMP_OAM_Update5BE8.c,
 *           src/matched/arm9/GAME_BEACON_SetNationArea.c, src/matched/ov/ov219_func_021856CC.c); after the
 *           manifest picks them up this should verify EXACT.
 *
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   KEY_GetCont 0x0203630C arm
 *   TOUCHPANEL_HitCont 0x02035BA4 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   func_02045B38 0x02045B38 arm
 *   func_020490F4 0x020490F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02040588 0x02040588 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_MENULIST_Main 0x020200CC thumb
 *   BMP_MENU_CreateYesNo 0x0201FDA0 thumb
 *   BMP_MENU_ProcessYesNo 0x0201FEBC thumb
 *   BMP_OAM_Update5BE8 0x02025BE8 thumb
 *   BMP_OAM_Check5C44 0x02025C44 thumb
 *   BMP_OAM_Get 0x02025B94 thumb
 *   func_0200947C 0x0200947C thumb
 *   GAME_BEACON_SetNationArea 0x02027120 thumb
 *   APP_TASKMENU_WIN_IsFinish 0x02028230 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BEACON_DETAIL_WinActivate 0x02183CBC thumb ov219
 *   BEACON_DETAIL_MarkCurrentRecord 0x02184734 thumb ov219
 *   BEACON_DETAIL_ReadTouchInput 0x02184798 thumb ov219
 *   BEACON_DETAIL_InitMainScreen 0x021849A4 thumb ov219
 *   BEACON_DETAIL_CreateTaskMenuWin 0x02184C2C thumb ov219
 *   BEACON_DETAIL_DeleteTaskMenuWin 0x02184C8C thumb ov219
 *   BEACON_DETAIL_DeleteMainScreen 0x02184CB0 thumb ov219
 *   BEACON_DETAIL_PrintMessage 0x02184D70 thumb ov219
 *   BEACON_DETAIL_CreateMenuList 0x02184EC0 thumb ov219
 *   BEACON_DETAIL_CreateMenuItems 0x02185074 thumb ov219
 *   BEACON_DETAIL_CreateMenuItemsFromIds 0x021850EC thumb ov219
 *   BEACON_DETAIL_CloseMenu 0x0218516C thumb ov219
 *   BEACON_DETAIL_DrawCurrentArea 0x0218519C thumb ov219
 *   BEACON_DETAIL_DrawEntryDetail 0x02185254 thumb ov219
 *   BEACON_DETAIL_CloseDetailWin 0x02185310 thumb ov219
 *   BEACON_DETAIL_FindNearestRecord 0x0218532C thumb ov219
 *   BEACON_DETAIL_DrawCurrentInfo 0x0218544C thumb ov219
 *   BEACON_DETAIL_Create3DObjects 0x02185580 thumb ov219
 *   BEACON_DETAIL_Delete3DObjects 0x0218562C thumb ov219
 *   BEACON_DETAIL_Init3DParams 0x021856CC thumb ov219
 *   BEACON_DETAIL_SetupCamera 0x02185794 thumb ov219
 *   BEACON_DETAIL_MoveCursor 0x02185934 thumb ov219
 *   BEACON_DETAIL_UpdateCamera 0x02185AC8 thumb ov219
 *   BEACON_DETAIL_HasEntry 0x02185CF4 thumb ov219
 *   d_02185DE6 0x02185DE6 data a1
 *   d_02185DB6 0x02185DB6 data ov219 a1
 *   d_02185E98 0x02185E98 data ov219 a4
 *   d_02185E28 0x02185E28 data ov219 a4
 *   d_02185DB0 0x02185DB0 data ov219 a1
 *   d_02185DC4 0x02185DC4 data ov219 a1
 *   d_02185ECC 0x02185ECC data ov219 a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Src;
struct Descriptor;
struct CharBuf;

extern u32 KEY_GetTrg(void);
extern u32 KEY_GetCont(void);
extern int TOUCHPANEL_HitCont(const void *a);
typedef signed int     s32;
struct MsgBank;
struct Obj;
struct PrintSys;
struct Rec;
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern int TOUCHPANEL_GetTrg(void);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_020490F4(u32 id, u32 heap);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BMP_Clear(struct CharBuf *, u8);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 WIPE_SYS_EndCheck(void);
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern s32 BMP_MENULIST_Main(struct Obj *o);
extern void *BMP_MENU_CreateYesNo(const void *a, int b, int c, int d, u16 heap);
extern u32 BMP_MENU_ProcessYesNo(u8 *p);
extern int BMP_OAM_Update5BE8(void);
extern int BMP_OAM_Check5C44(u32 a0, u32 *a1, u32 *a2);
extern u32 BMP_OAM_Get(u32 a);
extern void func_0200947C(u32 a, u32 b, u32 c, u32 d);
extern void GAME_BEACON_SetNationArea(u8 a, u8 b);
extern u32 APP_TASKMENU_WIN_IsFinish(u8 *p);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void BEACON_DETAIL_WinActivate(u8 *p, u32 i);
extern void BEACON_DETAIL_MarkCurrentRecord(u8 *p);
extern void BEACON_DETAIL_ReadTouchInput(char *p);
extern void BEACON_DETAIL_InitMainScreen(char *p, void *arc);
extern void BEACON_DETAIL_CreateTaskMenuWin(char *p, int i);
extern void BEACON_DETAIL_DeleteTaskMenuWin(u8 *p, u32 i);
extern void BEACON_DETAIL_DeleteMainScreen(char *p);
extern int BEACON_DETAIL_PrintMessage(char *p, u32 message, int force);
extern void BEACON_DETAIL_CreateMenuList(u8 *p, const u8 *d, const struct Src *s, const void *e);
extern void BEACON_DETAIL_CreateMenuItems(u8 *p, const u8 *a, u32 b, u32 c);
extern void BEACON_DETAIL_CreateMenuItemsFromIds(char *p, const unsigned char *descriptor, const struct Src *cfg, unsigned file, const unsigned char *ids, unsigned count);
extern void BEACON_DETAIL_CloseMenu(u8 *p);
extern void BEACON_DETAIL_DrawCurrentArea(char *p);
extern void BEACON_DETAIL_DrawEntryDetail(char *p, unsigned key, unsigned member);
extern void BEACON_DETAIL_CloseDetailWin(char *p);
extern int BEACON_DETAIL_FindNearestRecord(char *p, u32 *out);
extern void BEACON_DETAIL_DrawCurrentInfo(char *p);
extern void BEACON_DETAIL_Create3DObjects(char *p, void *arc);
extern void BEACON_DETAIL_Delete3DObjects(char *p);
extern void BEACON_DETAIL_Init3DParams(u8 *p);
extern void BEACON_DETAIL_SetupCamera(char *p);
extern int BEACON_DETAIL_MoveCursor(u8 *p, u32 key, u32 b);
extern int BEACON_DETAIL_UpdateCamera(char *p);
extern int BEACON_DETAIL_HasEntry(int i);

extern const u8 d_02185DE6[];
extern const u8 d_02185DB6[];
extern const struct Src d_02185E98;
extern const u8 d_02185E28[];
extern const u8 d_02185DB0[];
extern const u8 d_02185DC4[];
extern const u8 d_02185ECC[];

#define W(o) (*(u32 *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))
#define B(o) (*(u8 *)(p + (o)))

static inline void close_win(u8 *p, int d, int f)
{
    void *win = *(void **)(p + 0xC080);
    if (B(f) != 0 && (int)PRINTSYS_QUE_IsExistTarget(win, BMP_WIN_GetBmp(*(struct Descriptor **)(p + d))) == 0) {
        BMP_WIN_TransferChars(*(struct Descriptor **)(p + d));
        B(f) = 0;
    }
}

int BEACON_DETAIL_Update(u8 *p, int *state)
{
    int ret = 0;
    int n;
    u32 m;
    void *arc;
    u32 r;
    u8 *ids;
    u32 count;
    u32 tmp;
    int old;
    u32 v;
    u32 w;

    W(0xC354) = KEY_GetTrg();
    W(0xC358) = KEY_GetCont();
    if (TOUCHPANEL_HitCont(d_02185DE6) != -1) {
        W(0xC360) = (int)TOUCHPANEL_GetPointCont((u32 *)(p + 0xC364), (u32 *)(p + 0xC368));
    } else {
        W(0xC360) = 0;
    }
    if (W(0xC360) == 1) {
        W(0xC35C) = TOUCHPANEL_GetTrg();
    } else {
        W(0xC35C) = (int)TOUCHPANEL_GetPointTrg((u32 *)(p + 0xC364), (u32 *)(p + 0xC368));
    }
    switch (*state) {
    case 0:
        *(void **)(p + 0xC070) = func_02045B38(0, 2, (u16)0xCF, (u16)W(0));
        arc = func_020490F4(0xC5, (u16)W(0));
        BEACON_DETAIL_Create3DObjects((char *)p, arc);
        BEACON_DETAIL_InitMainScreen((char *)p, arc);
        ARC_TOOL_DeleteHandle(arc);
        W(0xC314) = 0;
        WIPE_SYS_Start(0, (int)1, (int)1, (int)0, (int)6, (int)1, W(0));
        func_02040588(6, 1);
        func_02040588(2, 1);
        func_02040588(7, 1);
        func_02040588(3, 1);
        *state = 1;
        break;
    case 1:
        if (WIPE_SYS_EndCheck() == 1) {
            *state = 2;
        }
        break;
    case 2:
        if (BEACON_DETAIL_PrintMessage((char *)p, 0, 1) == 1) {
            if (W(0xC33C) == 0) {
                *state = 3;
            } else {
                *state = 0x10;
            }
        }
        break;
    case 3:
        if (BEACON_DETAIL_PrintMessage((char *)p, 1, 1) == 1) {
            BEACON_DETAIL_CreateMenuList(p, d_02185DB6, &d_02185E98, d_02185E28);
            *state = 4;
        }
        break;
    case 4:
        if ((int)PRINTSYS_QUE_IsFinished(*(void **)(p + 0xC080)) == 0) {
            break;
        }
        r = BMP_MENULIST_Main(*(void **)(p + 0xC04C));
        if (r == -1) {
            break;
        }
        BEACON_DETAIL_CloseMenu(p);
        switch (r) {
        case 0:
        default:
            n = 0x10;
            goto snd54c;
        case 1:
            n = 5;
            goto snd54c;
        case 2:
        case 0xFFFFFFFE:
            n = 0x14;
            goto snd551;
        }
        break;
    case 5:
        if (BEACON_DETAIL_PrintMessage((char *)p, 2, 1) == 1) {
            *(void **)(p + 0xC054) = BMP_MENU_CreateYesNo(d_02185DB0, 0x22, 7, 0, W(0));
            *state = 6;
        }
        break;
    case 6:
        switch ((u32)(int)BMP_MENU_ProcessYesNo(*(void **)(p + 0xC054))) {
        case 0:
            if (W(0xC318) == 1) {
                *(void **)(p + 0xC344) = (void *)BMP_OAM_Update5BE8();
                *state = 0xA;
            } else {
                *state = 7;
            }
            break;
        case 0xFFFFFFFE:
            *state = 3;
            break;
        }
        break;
    case 7:
        W(0xC344) = 0;
        BEACON_DETAIL_CreateMenuItems(p, d_02185DC4, (u32)d_02185ECC, 0xE7);
        *state = 8;
        break;
    case 8:
        if (BEACON_DETAIL_PrintMessage((char *)p, 3, 1) == 1) {
            *state = 9;
        }
        break;
    case 9:
        if ((int)PRINTSYS_QUE_IsFinished(*(void **)(p + 0xC080)) == 0) {
            break;
        }
        r = BMP_MENULIST_Main(*(void **)(p + 0xC04C));
        if (r == -1) {
            break;
        }
        BEACON_DETAIL_CloseMenu(p);
        if (r != -2) {
            W(0xC344) = r;
            if (BEACON_DETAIL_HasEntry(r) == 1) {
                n = 0xA;
            } else {
                W(0xC348) = 0;
                n = 0xD;
            }
            *state = n;
            goto se54c;
        } else {
            n = 3;
        snd551:
            *state = n;
            m = 0x551;
            goto call;
        }
        break;
    case 10:
        W(0xC348) = 0;
        BMP_OAM_Check5C44((u32)(*(void **)(p + 0xC344)), (u32 *)(&ids), &count);
        BEACON_DETAIL_CreateMenuItemsFromIds((char *)p, d_02185DC4, (const struct Src *)d_02185ECC, BMP_OAM_Get((u32)(*(void **)(p + 0xC344))), ids, count);
        *state = 0xB;
        break;
    case 11:
        if (BEACON_DETAIL_PrintMessage((char *)p, 4, 1) == 1) {
            *state = 0xC;
        }
        break;
    case 12:
        if ((int)PRINTSYS_QUE_IsFinished(*(void **)(p + 0xC080)) == 0) {
            break;
        }
        r = BMP_MENULIST_Main(*(void **)(p + 0xC04C));
        if (r == -1) {
            break;
        }
        BEACON_DETAIL_CloseMenu(p);
        if (r != -2) {
            W(0xC348) = r;
            n = 0xD;
        snd54c:
            *state = n;
        se54c:
            m = 0x54C;
        call:
            GFL_USE_PlaySeDefaultVolume(m);
        } else {
            GFL_USE_PlaySeDefaultVolume(0x551);
            if (W(0xC318) == 1) {
                *state = 3;
            } else {
                *state = 7;
            }
        }
        break;
    case 13:
        BEACON_DETAIL_DrawEntryDetail((char *)p, W(0xC344), W(0xC348));
        *state = 0xE;
        break;
    case 14:
        if (BEACON_DETAIL_PrintMessage((char *)p, 5, 1) == 1) {
            *(void **)(p + 0xC054) = BMP_MENU_CreateYesNo(d_02185DB0, 0x22, 7, 0, W(0));
            *state = 0xF;
        }
        break;
    case 15:
        switch ((u32)(int)BMP_MENU_ProcessYesNo(*(void **)(p + 0xC054))) {
        case 0:
            BEACON_DETAIL_CloseDetailWin((char *)p);
            func_0200947C(W(0x10), W(0xC), W(0xC344), W(0xC348));
            GAME_BEACON_SetNationArea(W(0xC344), W(0xC348));
            W(0xC33C) = W(0xC344);
            W(0xC340) = W(0xC348);
            *state = 0x10;
            break;
        case 0xFFFFFFFE:
            BEACON_DETAIL_CloseDetailWin((char *)p);
            *state = 3;
            break;
        }
        break;
    case 16:
        if (W(0xC318) == 1 && W(0xC34C) == 0) {
            H(0xC31C) = 0;
        } else {
            H(0xC31C) = 1;
        }
        BEACON_DETAIL_Init3DParams(p);
        BEACON_DETAIL_MarkCurrentRecord(p);
        BEACON_DETAIL_SetupCamera((char *)p);
        BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor **)(p + 0xC01C)), 0xF);
        BMP_WIN_TransferChars(*(struct Descriptor **)(p + 0xC01C));
        BEACON_DETAIL_CreateTaskMenuWin((char *)p, 1);
        if (W(0xC33C) != 0) {
            BEACON_DETAIL_DrawCurrentArea((char *)p);
        }
        BEACON_DETAIL_DrawCurrentInfo((char *)p);
        W(0xC350) = 0;
        W(0xC310) = 1;
        *state = 0x11;
        break;
    case 17:
        old = H(0xC30C);
        if ((int)PRINTSYS_QUE_IsFinished(*(void **)(p + 0xC080)) == 0) {
            break;
        }
        BEACON_DETAIL_ReadTouchInput((char *)p);
        if (BEACON_DETAIL_FindNearestRecord((char *)p, &tmp)) {
            BEACON_DETAIL_CreateTaskMenuWin((char *)p, 0);
        } else {
            BEACON_DETAIL_DeleteTaskMenuWin(p, 0);
        }
        v = W(0xC354);
        if ((v & 2) || ((w = W(0xC320)) & 2)) {
            BEACON_DETAIL_DeleteTaskMenuWin(p, 0);
            BEACON_DETAIL_WinActivate(p, 1);
            GFL_USE_PlaySeDefaultVolume(0x551);
            BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor **)(p + 0xC01C)), 0xF);
            BMP_WIN_TransferChars(*(struct Descriptor **)(p + 0xC01C));
            *state = 0x13;
            break;
        }
        if (((v & 0x400) || (w & 0x400)) && W(0xC350) == 0) {
            W(0xC350) = 1;
            BEACON_DETAIL_WinActivate(p, 0);
            BEACON_DETAIL_DrawCurrentInfo((char *)p);
            if (W(0xC350) != 1) {
                break;
            }
            goto se54c;
        }
        if (((v & 0x403) || (w & 0x400)) && W(0xC350) == 1) {
            W(0xC350) = 0;
            BEACON_DETAIL_DrawCurrentInfo((char *)p);
            break;
        }
        if (BEACON_DETAIL_MoveCursor(p, v, W(0xC358)) == 1 && W(0xC350) == 1) {
            W(0xC350) = 0;
            BEACON_DETAIL_DrawCurrentInfo((char *)p);
        }
        if (old != H(0xC30C)) {
            *state = 0x12;
            if (H(0xC30C) == 0) {
                GFL_USE_PlaySeDefaultVolume(0x649);
            } else {
                GFL_USE_PlaySeDefaultVolume(0x648);
            }
        }
        break;
    case 19:
        if ((int)APP_TASKMENU_WIN_IsFinish(*(void **)(p + 0xC060)) == 0) {
            break;
        }
        if (W(0xC33C) == 0) {
            W(0xC310) = 2;
            *state = 3;
        } else {
            BEACON_DETAIL_CloseDetailWin((char *)p);
            *state = 0x14;
        }
        BEACON_DETAIL_DeleteTaskMenuWin(p, 1);
        break;
    case 18:
        if (BEACON_DETAIL_UpdateCamera((char *)p) == 1) {
            *state = 0x11;
        }
        break;
    case 20:
        W(0xC314) = 0;
        WIPE_SYS_Start(0, (int)0, (int)0, (int)0, (int)6, (int)1, W(0));
        *state = 0x15;
        break;
    case 21:
        if (WIPE_SYS_EndCheck() == 1) {
            ret = 1;
            W(0xC310) = 1;
            BEACON_DETAIL_DeleteMainScreen((char *)p);
            BEACON_DETAIL_Delete3DObjects((char *)p);
            MSGDATA_Delete(*(void **)(p + 0xC070));
            *state = 0;
        }
        break;
    }
    close_win(p, 0xC078, 0xC07C);
    close_win(p, 0xC044, 0xC048);
    close_win(p, 0xC038, 0xC03C);
    close_win(p, 0xC02C, 0xC030);
    close_win(p, 0xC020, 0xC024);
    return ret;
}
