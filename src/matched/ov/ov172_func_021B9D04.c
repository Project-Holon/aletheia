/*
 * function: func_021B9D04
 * address:  0x021B9D04
 * packet:   pkt_ov172_021B9D04
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * State handler: on cancel closes the menu at +0x80; otherwise picks the next state from the probes.
 *
 * symbols:
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb
 *   APP_TASKMENU_UpdateMenu  0x02027974  thumb
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_020409B4  0x020409B4  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   func_021B7578  0x021B7578  thumb  ov172
 *   func_021B7B80  0x021B7B80  thumb  ov172
 *   func_021B80E4  0x021B80E4  thumb  ov172
 *   func_021B9C1C  0x021B9C1C  thumb  ov172
 *   func_021B9DF8  0x021B9DF8  thumb  ov172
 *   func_021BDFDC  0x021BDFDC  thumb  ov172
 *   func_021BDFE4  0x021BDFE4  thumb  ov172
 *   func_021BE054  0x021BE054  thumb  ov172
 *   func_021BE0A4  0x021BE0A4  thumb  ov172
 *   func_021BE0B0  0x021BE0B0  thumb  ov172
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct TaskMenu;
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void APP_TASKMENU_UpdateMenu(void *p);
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void func_0201F7A8(void *desc, u32 kind);
typedef unsigned short u16;
struct Cfg;
struct Descriptor;
struct Obj;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_020409B4(u32 index);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void func_021B7578(int x, char *p);
extern void func_021B7B80(int x, char *p);
extern u32 func_021B80E4(int unused, char *p);
extern void func_021B9C1C(void *p, char *q, int id);
extern int func_021B9DF8(void *p, int *out);
extern u32 func_021BDFDC(void *p);
extern u32 func_021BDFE4(void *p);
extern u8 func_021BE054(void *p);
extern u32 func_021BE0A4(void *p);
extern void func_021BE0B0(void *p, u32 v);

void func_021B9D04(int self, int *q)
{
    int r6;
    u32 r7;

    if (func_021B9DF8((void *)self, q) == 1) {
        APP_TASKMENU_CloseMenu((void *)q[0x20]);
        q[0x20] = 0;
        return;
    }
    APP_TASKMENU_UpdateMenu((void *)q[0x20]);
    if (APP_TASKMENU_IsFinish((void *)q[0x20]) != 1)
        return;
    if (APP_TASKMENU_GetCursorPos((const u8 *)q[0x20]) == 0) {
        if (func_021B80E4(self, (char *)func_021BDFE4((void *)self)) == 5) {
            q[0] = 0xF;
            q[0x21] = 1;
            func_021B9C1C((void *)self, (char *)q, 0x2A);
        } else if (func_021BE0A4((void *)self) == 0 && func_021BE054((void *)self) > 1) {
            q[0] = 0xB;
        } else {
            q[1] = 7;
            q[0] = 3;
            r6 = 1;
            func_021BE0B0((void *)self, 1);
            r7 = func_021BDFDC((void *)self);
            func_021B7578(self, (char *)r7);
            func_021B7B80(self, (char *)r7);
            q[2] = r6;
        }
    } else {
        q[0] = 5;
        func_0201F7A8((void *)q[0x1F], 1);
        BMP_WIN_ClearScreen((struct Descriptor *)q[0x1F]);
        BMP_WIN_MakeScreen((struct Cfg *)q[0xB]);
        func_020409B4(4);
        CLACT_SetActorAnimSeq((struct Obj *)q[0x26], 1);
    }
    APP_TASKMENU_CloseMenu((void *)q[0x20]);
    q[0x20] = 0;
}
