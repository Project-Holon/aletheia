/*
 * function: BTLV_INPUT_MessageScreenOpenTask
 * address: 0x02203D40
 * packet: pkt_ov094_02203D40
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTLV_INPUT_PlayConfirmSe 0x02206AF8 thumb ov094
 *   BTLV_INPUT_RestoreWindowPalette 0x02206A58 thumb ov094
 *   BTLV_INPUT_StartBgScrollOffsetTask 0x02204960 thumb ov094
 *   BTLV_INPUT_StartBgScrollTask 0x022043C0 thumb ov094
 *   BTLV_INPUT_StartPaletteCycleTask 0x022045A8 thumb ov094
 *   PALANM_RequestFade 0x0202173C thumb
 *   func_02040588 0x02040588 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_020409B4 0x020409B4 arm
 *   BTLV_INPUT_DeleteTask 0x0220687C thumb ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct Main {
    void *owner;
    char pad04[0x60];
    void *pal64;
    unsigned int f0:1, st:3, hi:28;
    char pad6c[0x1bc];
    void *obj228;
} Main;
typedef struct { Main *main; int state; } Ctx;
extern void BTLV_INPUT_PlayConfirmSe(char *p);
extern void BTLV_INPUT_RestoreWindowPalette(char *p);
extern void BTLV_INPUT_StartBgScrollOffsetTask(Main *, int, int, int, int, int, int, int);
extern void BTLV_INPUT_StartBgScrollTask(Main *, int, int, int, int);
extern void BTLV_INPUT_StartPaletteCycleTask(Main *, int, int);
extern int PALANM_RequestFade(void *, u16, u16, s16, u8, u8, u16, void *);
typedef unsigned int   u32;
struct Cfg;
struct Descriptor;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void func_020409B4(u32 index);
extern void BTLV_INPUT_DeleteTask(char *p, void *q);
void BTLV_INPUT_MessageScreenOpenTask(void *h, Ctx *c)
{
    switch (c->state) {
    case 0:
        BTLV_INPUT_PlayConfirmSe((char *)c->main);
        BTLV_INPUT_StartBgScrollOffsetTask(c->main, 5, 0, 0, 0, 0, 2, 1);
        BTLV_INPUT_StartBgScrollTask(c->main, 0x3000, 0x1000, -0x400, 0x98);
        BTLV_INPUT_RestoreWindowPalette((char *)c->main);
        PALANM_RequestFade(c->main->pal64, 2, 3, 1, 0xc, 0, 0x842, c->main->owner);
        c->state++;
        break;
    case 1:
        if (c->main->st == 0) {
            BTLV_INPUT_StartPaletteCycleTask(c->main, 0, 0);
            func_02040588(5, 1);
            func_02040588(7, 0);
            c->state++;
        }
        break;
    case 2:
    default:
        if (c->main->st == 0) {
            BMP_WIN_MakeScreen(c->main->obj228);
            func_020409B4(6);
            BMP_WIN_TransferChars(c->main->obj228);
            BTLV_INPUT_StartBgScrollOffsetTask(c->main, 5, 0x100, 0xc0, 2, 2, 2, 2);
            BTLV_INPUT_DeleteTask((char *)c->main, h);
        }
        break;
    }
}
