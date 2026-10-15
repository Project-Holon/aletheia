/*
 * function: BTLV_INPUT_ActionScreenOpenInstantTask
 * address: 0x02203978
 * packet: pkt_ov094_02203978
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
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
    unsigned char pad00[0x48];
    int f48;
    unsigned char pad4c[0x68 - 0x4c];
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
void BTLV_INPUT_ActionScreenOpenInstantTask(void *task, Ctx *c)
{
    switch (c->state) {
    case 0:
        func_020498F4((void *)c->main->f48, c->fc, 4, 0, 0, 0, c->main->h240);
        func_020498F4((void *)c->main->f48, 0x68, 5, 0, 0, 0, c->main->h240);
        BMP_WIN_MakeScreen(c->main->obj230);
        BTLV_INPUT_BlendWindowPalette((char *)c->main);
        BG_SYS_PushTile(6);
        BTLV_INPUT_StartBgScrollOffsetTask(c->main, 5, 0, 0xc0, 1, 1, 2, 0);
        c->state++;
        break;
    case 1:
        BTLV_INPUT_CreateCursorActors((struct Obj *)c->main, 0, 1);
        c->timer = 4;
        c->state++;
        break;
    case 2:
        if (--c->timer == 0) {
            BTLV_INPUT_StartBgWipeTask(c->main, 0, 0x1c0, 8, 8);
            BTLV_INPUT_StartPaletteCycleTask(c->main, 0, 1);
            BTLV_INPUT_StartPaletteFlashTask(c->main, 1);
            c->state++;
        }
        break;
    case 3:
    default:
        if (c->main->st == 0) {
            BTLV_INPUT_SetActionUnitVisible((char *)c->main, 1);
            BMP_WIN_TransferChars(c->main->obj230);
            BTLV_INPUT_DeleteTask((char *)c->main, task);
        }
        break;
    }
}
