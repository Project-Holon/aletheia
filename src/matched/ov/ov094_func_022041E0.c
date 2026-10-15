/*
 * function: BTLV_INPUT_ListScreenOpenInstantTask
 * address: 0x022041E0
 * packet: pkt_ov094_022041E0
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020498F4 0x020498F4 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   CLACT_SetUnitDrawEnable 0x0204B22C arm
 *   BTLV_INPUT_RestoreWindowPalette 0x02206A58 thumb ov094
 *   BTLV_INPUT_StartBgWipeTask 0x022044C0 thumb ov094
 *   BTLV_INPUT_StartPaletteCycleTask 0x022045A8 thumb ov094
 *   BTLV_INPUT_StartPaletteFlashTask 0x02204838 thumb ov094
 *   BTLV_INPUT_CreateCursorActors 0x02204698 thumb ov094
 *   BTLV_INPUT_StartBgScrollOffsetTask 0x02204960 thumb ov094
 *   BTLV_INPUT_DeleteTask 0x0220687C thumb ov094
 *   d_0220A4EC 0x0220A4EC data ov094 a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Main {
    char pad00[0x48];
    u32 f48;
    char pad4c[0x1c];
    unsigned int f0:1, st:3, pad4:15, mode:2, hi:11;
    char pad6c[0x18c];
    void *obj1f8;
    char pad1fc[0x2c];
    void *obj228;
    char pad22c[0x14];
    u16 h240;
} Main;
typedef struct { Main *main; int state, f8, fc, f10, f14, timer; } Ctx;
typedef struct { int a, b; } Pair;
extern const Pair d_0220A4EC[];
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
struct Bank;
struct Cfg;
struct Descriptor;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BG_SYS_PushTile(u32 index);
extern void CLACT_SetUnitDrawEnable(struct Bank *bank, u32 mode);
struct Obj;
extern void BTLV_INPUT_RestoreWindowPalette(char *p);
extern void BTLV_INPUT_StartBgWipeTask(Main *, int, int, int, int);
extern void BTLV_INPUT_StartPaletteCycleTask(Main *, int, int);
extern void BTLV_INPUT_StartPaletteFlashTask(Main *, int);
extern void BTLV_INPUT_CreateCursorActors(struct Obj *p, int a, int b);
extern void BTLV_INPUT_StartBgScrollOffsetTask(Main *, int, int, int, int, int, int, int);
extern void BTLV_INPUT_DeleteTask(char *p, void *q);
void BTLV_INPUT_ListScreenOpenInstantTask(void *h, Ctx *c)
{
    switch (c->state) {
    case 0:
        func_020498F4((void *)c->main->f48, 0x64, 4, 0, 0, 0, c->main->h240);
        BMP_WIN_MakeScreen(c->main->obj228);
        BTLV_INPUT_RestoreWindowPalette((char *)c->main);
        BG_SYS_PushTile(6);
        BTLV_INPUT_StartBgWipeTask(c->main, d_0220A4EC[c->main->mode].a, d_0220A4EC[c->main->mode].b, 8, 8);
        BTLV_INPUT_StartPaletteCycleTask(c->main, 0, 0);
        BTLV_INPUT_StartPaletteFlashTask(c->main, 0);
        BTLV_INPUT_StartBgScrollOffsetTask(c->main, -1, 0, 0, 1, 1, 2, 0);
        c->timer = 4;
        c->state++;
        break;
    case 1:
        if (--c->timer == 0) {
            BTLV_INPUT_CreateCursorActors((struct Obj *)c->main, 0, 0);
            c->state++;
        }
        break;
    case 2:
    default:
        if (c->main->st == 0) {
            BMP_WIN_TransferChars(c->main->obj228);
            CLACT_SetUnitDrawEnable(c->main->obj1f8, 1);
            BTLV_INPUT_StartBgScrollOffsetTask(c->main, 5, 0x100, 0xc0, 2, 2, 2, 2);
            BTLV_INPUT_DeleteTask((char *)c->main, h);
        }
        break;
    }
}
