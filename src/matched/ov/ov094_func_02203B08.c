/*
 * function: BTLV_INPUT_WazaScreenCloseTask
 * address:  0x02203B08
 * packet:   pkt_ov094_02203B08
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020498F4  0x020498F4  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   CLACT_SetUnitDrawEnable  0x0204B22C  arm
 *   BTLV_INPUT_StartBgScrollOffsetTask  0x02204960  thumb  ov094
 *   BTLV_INPUT_DeleteTask  0x0220687C  thumb  ov094
 */
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct Main {
    unsigned char pad00[0x48];
    int f48;
    unsigned char pad4C[0x1f8 - 0x4C];
    void *obj1f8;
    unsigned char pad1FC[0x228 - 0x1FC];
    void *obj228;
    unsigned char pad22C[0x240 - 0x22C];
    u16 h240;
} Main;

typedef struct Ctx {
    Main *main;
    int state;
    int f8;
    int fc;
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
extern void BTLV_INPUT_StartBgScrollOffsetTask(Main *m, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern void BTLV_INPUT_DeleteTask(char *p, void *q);

void BTLV_INPUT_WazaScreenCloseTask(int a0, Ctx *c)
{
    switch (c->state) {
    case 0:
        func_020498F4((void *)c->main->f48, c->fc, 4, 0, 0, 0, c->main->h240);
        BTLV_INPUT_StartBgScrollOffsetTask(c->main, 5, 0, 0xc0, 2, 2, 2, 2);
        c->state = c->state + 1;
        break;
    case 1:
        BMP_WIN_MakeScreen(c->main->obj228);
        BG_SYS_PushTile(6);
        func_020498F4((void *)c->main->f48, 0x68, 5, 0, 0, 0, c->main->h240);
        BMP_WIN_TransferChars(c->main->obj228);
        CLACT_SetUnitDrawEnable(c->main->obj1f8, 1);
        BTLV_INPUT_StartBgScrollOffsetTask(c->main, 5, 0x100, 0xc0, 2, 2, 2, 2);
        BTLV_INPUT_DeleteTask((char *)c->main, (void *)a0);
        break;
    }
}
