/*
 * function: EVENT_SHORTCUT_MENU_Create
 * address:  0x0215FF54
 * packet:   pkt_ov010_0215FF54
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   RECENT_ID_LIST_SAVEDATA_GetBlockFromSys  0x0200C404  thumb
 *   RECENT_ID_LIST_SAVEDATA_CountIds  0x0200C468  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_02030734  0x02030734  arm
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   UI_SetInputMode  0x020355D8  arm
 *   EVENT_SHORTCUT_MENU_ReturnEvent  0x0216025C  thumb  ov010
 *   EVENT_SHORTCUT_MENU_MainEvent  0x02160018  thumb  ov010
 *   d_02172960     0x02172960  data  a4
 *   EVENT_SHORTCUT_MENU_ResumeLinkHook  0x02160668  thumb  ov010
 *   EVENT_SHORTCUT_MENU_SuspendLinkHook  0x021606D0  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
struct Big;
struct Desc;

extern void *ICA_ANIME_GetField1C(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *RECENT_ID_LIST_SAVEDATA_GetBlockFromSys(void *sys);
struct Work;
extern u16 RECENT_ID_LIST_SAVEDATA_CountIds(const u8 *a);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern void MI_CpuFill8();
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *FIELDMAP_GetMmdlSys(unsigned char *p);
extern void FLDMMDL_SysPauseMove(void *map);
extern void UI_SetInputMode(u8 v);
extern int EVENT_SHORTCUT_MENU_ReturnEvent(void *evt, u32 *state, struct Ctx *c);
extern int EVENT_SHORTCUT_MENU_MainEvent(void *evt, u32 *state, struct Work *w);
extern u8 d_02172960[];
extern int EVENT_SHORTCUT_MENU_ResumeLinkHook(int *a0, int *a1);
extern void EVENT_SHORTCUT_MENU_SuspendLinkHook(int a, int b);

/* the 0x40-byte block hung off the record */
struct Sub {
    int          owner;  /* 0x00 */
    int          field;  /* 0x04 */
    struct Desc *desc;   /* 0x08 */
    u32          f0C;
    u32          f10;
    void        *fn14;
    void        *fn18;
    u32          f1C;
    void        *rec;    /* 0x20 */
    u8           pad24[0x40 - 0x24];
};

/* the 0x20-byte record behind the descriptor */
struct Rec {
    struct Desc *desc;   /* 0x00 */
    int          owner;  /* 0x04 */
    int          field;  /* 0x08 */
    u32          f0C;
    struct Sub  *sub;    /* 0x10 */
    u16          id;     /* 0x14 */
    u16          f16;
    u32          f18;
    u32          f1C;
};

struct Desc *EVENT_SHORTCUT_MENU_Create(int a0, int a1, u16 a2)
{
    void *sp8;
    struct Desc *r5;
    struct Rec *p;

    sp8 = RECENT_ID_LIST_SAVEDATA_GetBlockFromSys(GAME_DATA_GetSaveControl((struct Big *)ICA_ANIME_GetField1C((const struct Ctx *)a0)));
    if (RECENT_ID_LIST_SAVEDATA_CountIds(sp8) == 1) {
        r5 = func_020122C0((void *)a0, 0, (void *)EVENT_SHORTCUT_MENU_ReturnEvent, 0x20);
    } else {
        r5 = func_020122C0((void *)a0, 0, (void *)EVENT_SHORTCUT_MENU_MainEvent, 0x20);
    }
    p = (struct Rec *)func_020124E8((struct Obj *)r5);
    MI_CpuFill8(p, 0, 0x20);
    p->owner = a0;
    p->desc = r5;
    p->field = a1;
    p->id = a2;
    p->f18 = 0;
    p->sub = (struct Sub *)func_02030734(4, 0x40, 0, (const char *)d_02172960, 0xc2);
    MI_CpuFill8(p->sub, 0, 0x40);
    p->sub->owner = p->owner;
    p->sub->field = p->field;
    p->sub->desc = r5;
    if (RECENT_ID_LIST_SAVEDATA_CountIds(sp8) != 1) {
        p->sub->fn14 = (void *)EVENT_SHORTCUT_MENU_ResumeLinkHook;
        p->sub->fn18 = (void *)EVENT_SHORTCUT_MENU_SuspendLinkHook;
        p->sub->rec = p;
    }
    FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys((unsigned char *)p->field));
    UI_SetInputMode(0);
    return r5;
}
