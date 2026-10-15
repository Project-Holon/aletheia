/*
 * function: BTLV_INPUT_ScreenResetTask
 * address: 0x022042E4
 * packet: pkt_ov094_022042E4
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTLV_INPUT_ClearButtonState 0x022056B4 thumb ov094
 *   BTLV_INPUT_InitButtonState 0x022053DC thumb ov094
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   CLACT_SetUnitDrawEnable 0x0204B22C arm
 *   BTLV_INPUT_StartBgWipeTask 0x022044C0 thumb ov094
 *   BTLV_INPUT_StartBgScrollOffsetTask 0x02204960 thumb ov094
 *   BTLV_INPUT_DeleteTask 0x0220687C thumb ov094
 *   d_0220A4EC 0x0220A4EC data ov094 a4
 */
typedef struct Main {
    char pad00[0x68];
    unsigned int f0:1, st:3, pad4:15, mode:2, hi:11;
    char pad6c[0x18c];
    void *obj1f8;
    char pad1fc[0x2c];
    void *obj228;
} Main;
typedef struct { Main *main; int state; } Ctx;
typedef struct { int a, b; } Pair;
extern const Pair d_0220A4EC[];
extern void BTLV_INPUT_ClearButtonState(Main *);
extern void BTLV_INPUT_InitButtonState(char *m);
typedef unsigned int   u32;
struct Bank;
struct Cfg;
struct Descriptor;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BG_SYS_PushTile(u32 index);
extern void CLACT_SetUnitDrawEnable(struct Bank *bank, u32 mode);
extern void BTLV_INPUT_StartBgWipeTask(Main *, int, int, int, int);
extern void BTLV_INPUT_StartBgScrollOffsetTask(Main *, int, int, int, int, int, int, int);
extern void BTLV_INPUT_DeleteTask(char *p, void *q);
void BTLV_INPUT_ScreenResetTask(void *h, Ctx *c)
{
    switch (c->state) {
    case 0:
        BTLV_INPUT_ClearButtonState(c->main);
        c->state++;
        break;
    case 1:
        BTLV_INPUT_InitButtonState((char *)c->main);
        BMP_WIN_MakeScreen(c->main->obj228);
        BG_SYS_PushTile(6);
        BTLV_INPUT_StartBgWipeTask(c->main, d_0220A4EC[c->main->mode].a, d_0220A4EC[c->main->mode].b, 8, 8);
        BTLV_INPUT_StartBgScrollOffsetTask(c->main, -1, 0, 0, 1, 1, 2, 0);
        c->state++;
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
