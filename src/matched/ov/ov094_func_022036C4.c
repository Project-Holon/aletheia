/*
 * function: BTLV_INPUT_WazaScreenOpenTask
 * address: 0x022036C4
 * packet: pkt_ov094_022036C4
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTLV_INPUT_PlayConfirmSe 0x02206AF8 thumb ov094
 *   BTLV_INPUT_StartBgScrollTask 0x022043C0 thumb ov094
 *   PALANM_RequestFadeOverwrite 0x02021848 thumb
 *   func_02040588 0x02040588 arm
 *   BTLV_INPUT_BlendWindowPalette 0x02206A14 thumb ov094
 *   BTLV_INPUT_SetActionUnitVisible 0x02205B80 thumb ov094
 *   func_020498F4 0x020498F4 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   CLACT_SetUnitDrawEnable 0x0204B22C arm
 *   BTLV_INPUT_StartBgWipeTask 0x022044C0 thumb ov094
 *   BTLV_INPUT_StartPaletteCycleTask 0x022045A8 thumb ov094
 *   BTLV_INPUT_StartPaletteFlashTask 0x02204838 thumb ov094
 *   BTLV_INPUT_RestoreWindowPalette 0x02206A58 thumb ov094
 *   BTLV_INPUT_CreateCursorActors 0x02204698 thumb ov094
 *   BTLV_INPUT_StartBgScrollOffsetTask 0x02204960 thumb ov094
 *   BTLV_INPUT_DeleteTask 0x0220687C thumb ov094
 */
typedef unsigned short u16;
typedef struct Main {
    void *owner;
    unsigned char pad04[0x48 - 4];
    int f48;
    unsigned char pad4c[4];
    int mode;
    unsigned char pad54[0x64 - 0x54];
    void *pal;

    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
    unsigned char pad6c[0x1f8 - 0x6c];
    void *obj1f8;
    unsigned char pad1fc[0x228 - 0x1fc];
    void *obj228;
    unsigned char pad22c[4];
    void *obj230;
    unsigned char pad234[0x240 - 0x234];
    u16 h240;
} Main;
typedef struct Ctx {
    Main *main;
    int state;
    int f8;
    int fc;
    int f10;
    int f14;
    int timer;
} Ctx;
extern void func_020498F4(void *a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f, u16 g);
typedef unsigned int   u32;
struct Bank;
struct Cfg;
struct Descriptor;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BG_SYS_PushTile(u32 index);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void CLACT_SetUnitDrawEnable(struct Bank *bank, u32 mode);
extern void BTLV_INPUT_StartBgWipeTask(Main *, int, int, int, int);
extern void BTLV_INPUT_StartPaletteCycleTask(Main *, int, int);
extern void BTLV_INPUT_StartPaletteFlashTask(Main *, int);
extern void BTLV_INPUT_RestoreWindowPalette(char *p);
struct Obj;
extern void BTLV_INPUT_CreateCursorActors(struct Obj *p, int a, int b);
extern void BTLV_INPUT_StartBgScrollOffsetTask(Main *, int, int, int, int, int, int, int);
extern void BTLV_INPUT_DeleteTask(char *, void *);
extern void BTLV_INPUT_BlendWindowPalette(char *p);
extern void BTLV_INPUT_SetActionUnitVisible(char *p, int a);
typedef unsigned char u8;
typedef signed short s16;
extern void BTLV_INPUT_PlayConfirmSe(char *p);
extern void BTLV_INPUT_StartBgScrollTask(Main *, int, int, int, int);
extern int PALANM_RequestFadeOverwrite(void *, u16, u16, s16, u8, u8, u16, void *);
extern void func_02040588(unsigned char which, unsigned char enable);
void BTLV_INPUT_WazaScreenOpenTask(void *task, Ctx *c)
{
    switch (c->state) {
    case 0:
        func_020498F4((void *)c->main->f48, 0x5d, 4, 0, 0, 0, c->main->h240);
        func_020498F4((void *)c->main->f48, 0x6f, 5, 0, 0, 0, c->main->h240);
        BTLV_INPUT_PlayConfirmSe((char *)c->main);
        BTLV_INPUT_StartBgScrollOffsetTask(c->main, 5, 0, 0, 0, 0, 2, 1);
        BTLV_INPUT_StartBgScrollTask(c->main, 0x3000, 0x1000, -0x400, 0x98);
        BG_SYS_PushTile(6);
        PALANM_RequestFadeOverwrite(c->main->pal, 2, 3, 1, 12, 0, 0x842, c->main->owner);
        c->state++;
        break;
    case 1:
        if (c->main->st == 0) {
            if (c->main->mode == 2 && c->f8 != 4) {
                func_020498F4((void *)c->main->f48, 0x5e, 4, 0, 0, 0, c->main->h240);
            } else {
                func_020498F4((void *)c->main->f48, 0x5d, 4, 0, 0, 0, c->main->h240);
            }
            BMP_WIN_MakeScreen(c->main->obj228);
            BG_SYS_PushTile(6);
            BTLV_INPUT_StartBgWipeTask(c->main, 0x100, 0x1c0, 8, 8);
            BTLV_INPUT_StartPaletteCycleTask(c->main, 0, 0);
            BTLV_INPUT_StartPaletteFlashTask(c->main, 0);
            BTLV_INPUT_StartBgScrollOffsetTask(c->main, -1, 0, 0, 1, 1, 2, 0);
            c->timer = 4;
            c->state++;
        }
        break;
    case 2:
        if (--c->timer == 0) {
            BTLV_INPUT_CreateCursorActors((struct Obj *)c->main, 0, 0);
            c->state++;
        }
        break;
    case 3:
    default:
        if (c->main->st == 0) {
            BMP_WIN_TransferChars(c->main->obj228);
            CLACT_SetUnitDrawEnable(c->main->obj1f8, 1);
            BTLV_INPUT_StartBgScrollOffsetTask(c->main, 5, 0x100, 0xc0, 2, 2, 2, 2);
            BTLV_INPUT_DeleteTask((char *)c->main, task);
        }
        break;
    }
}
