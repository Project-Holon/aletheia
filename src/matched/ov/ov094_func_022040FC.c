/*
 * function: BTLV_INPUT_ConfirmScreenOpenTask
 * address: 0x022040FC
 * packet: pkt_ov094_022040FC
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020498F4 0x020498F4 arm
 *   BTLV_INPUT_PlayConfirmSe 0x02206AF8 thumb ov094
 *   BTLV_INPUT_StartBgScrollOffsetTask 0x02204960 thumb ov094
 *   BTLV_INPUT_StartBgScrollTask 0x022043C0 thumb ov094
 *   BTLV_INPUT_StartBgWipeTask 0x022044C0 thumb ov094
 *   PALANM_RequestFade 0x0202173C thumb
 *   func_02040588 0x02040588 arm
 *   BTLV_INPUT_DeleteTask 0x0220687C thumb ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct Main {
    void *owner;
    char pad04[0x44];
    u32 f48;
    char pad4c[0x18];
    void *pal64;
    unsigned int f0:1, st:3, hi:28;
    char pad6c[0x1d4];
    u16 h240;
} Main;
typedef struct { Main *main; int state; } Ctx;
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void BTLV_INPUT_PlayConfirmSe(char *p);
extern void BTLV_INPUT_StartBgScrollOffsetTask(Main *, int, int, int, int, int, int, int);
extern void BTLV_INPUT_StartBgScrollTask(Main *, int, int, int, int);
extern void BTLV_INPUT_StartBgWipeTask(Main *, int, int, int, int);
extern int PALANM_RequestFade(void *, u16, u16, s16, u8, u8, u16, void *);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BTLV_INPUT_DeleteTask(char *p, void *q);
void BTLV_INPUT_ConfirmScreenOpenTask(void *h, Ctx *c)
{
    switch (c->state) {
    case 0:
        func_020498F4((void *)c->main->f48, 0x63, 4, 0, 0, 0, c->main->h240);
        func_020498F4((void *)c->main->f48, 0x6b, 5, 0, 0, 0, c->main->h240);
        BTLV_INPUT_PlayConfirmSe((char *)c->main);
        BTLV_INPUT_StartBgScrollOffsetTask(c->main, 5, 0, 0, 1, 0, 2, 1);
        BTLV_INPUT_StartBgScrollTask(c->main, 0x3000, 0x1000, -0x400, 0x98);
        BTLV_INPUT_StartBgWipeTask(c->main, 0, 0x1c0, 8, 8);
        PALANM_RequestFade(c->main->pal64, 2, 3, 1, 0xc, 0, 0x842, c->main->owner);
        c->state++;
        break;
    case 1:
    default:
        if (c->main->st == 0) {
            func_02040588(4, 1);
            func_02040588(5, 1);
            func_02040588(7, 0);
            BTLV_INPUT_DeleteTask((char *)c->main, h);
        }
        break;
    }
}
