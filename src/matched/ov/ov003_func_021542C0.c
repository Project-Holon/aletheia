/*
 * function: EVENT_MENUPROC_Main
 * address:  0x021542C0
 * packet:   pkt_ov003_021542C0
 * region:   ov003
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stage machine installed by EVENT_MENUPROC_Create (allocator + link setup); the step
 * callback runs on *mode.  Same shape as arm9 FIELD_STATUS_SubProcNoFadeEvent.  This address is
 * also labelled by ov000/ov001/ov002/ov006, hence the overlay-qualified name.
 *
 * The 3rd argument to GAMESYSTEM_CallProc is the book-keeping table pointer
 * 0x0209DEFC, an interior entry of the seven-pointer table at 0x0209DEF0.
 * Its only pool word image-wide is the one inside this function, so it has no
 * `literal` witness, and `sole-ref/self` cannot read it: the site lives in an
 * overlapping overlay window and `rom_word_at` selects ov000's bytes there,
 * not ov003's.  It is therefore written as an opaque (void *) literal, which
 * reproduces the original pool word byte for byte with no relocation.
 *
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   GFL_USE_GetBgmNo  0x02005C44  thumb
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 */

typedef unsigned int u32;

struct Ctx;
extern u32   GAMESYSTEM_GetGameComm(const struct Ctx *a0);
struct IcaAnime;
extern u32 func_02026454(void *obj);
typedef unsigned short u16;
struct Evt;
extern u16 GFL_USE_GetBgmNo(void);
extern void GFL_USE_FadeOutBgm(u32 a);
extern int FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 GAMESYSTEM_GetProcStatus(const struct Ctx *p);
extern void  GFL_USE_CancelChangeAndPlayBgm(u32 a0, u32 a1);
extern void GFL_USE_FadeInBgmFull(u32 a);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *a0);

u32 EVENT_MENUPROC_Main(void *obj, u32 *mode, u32 *args)
{
    u32 a0 = args[1];

    switch (*mode) {
    case 0:
        if (func_02026454((void *)GAMESYSTEM_GetGameComm((const struct Ctx *)a0)) == 0) {
            args[0] = GFL_USE_GetBgmNo();
            GFL_USE_FadeOutBgm(6);
            (*mode)++;
        }
        break;
    case 1:
        GAME_EVENT_CallEvent(obj, (struct Evt **)FIELD_STATUS_CreateFieldCloseEvent(a0, args[2]));
        *mode = 2;
        break;
    case 2:
        args[3] = (u32)GAMESYSTEM_GetGameData((const struct Ctx *)a0);
        args[4] = args[5];
        GAMESYSTEM_CallProc((struct IcaAnime *)a0, (u32)-1, (void *)0x0209DEFC, &args[3]);
        (*mode)++;
        break;
    case 3:
        if (GAMESYSTEM_GetProcStatus((const struct Ctx *)a0) == 0)
            (*mode)++;
        break;
    case 4:
        (*mode)++;
        break;
    case 5:
        GFL_USE_CancelChangeAndPlayBgm(args[0], 0xFFFF);
        GFL_USE_FadeInBgmFull(0x3C);
        GAME_EVENT_CallEvent(obj, FIELD_STATUS_CreateFieldOpenEvent((void *)a0));
        (*mode)++;
        break;
    case 6:
        return 1;
    }
    return 0;
}
