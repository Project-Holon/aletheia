/*
 * function: MAILVIEW_CreateWindows
 * address: 0x021C515C
 * packet: pkt_ov136_021C515C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_WIN_Init 0x02045088 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   PRINTSYS_QUE_Create  0x0201C440  thumb  arm9
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *win;
    u8 flag;
    u8 pad5[3];
} WinSlot;

typedef struct {
    u32 heapId;
    u8 pad4[0x44 - 4];
    void *win[7];
    WinSlot slot[6];
    u8 pad90[0x98 - 0x90];
    void *f98;
} Obj;

extern void BMP_WIN_Init(u16);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern u32 PRINTSYS_QUE_Create(void *p);
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 layer);

void MAILVIEW_CreateWindows(Obj *p)
{
    int i;
    void *w;

    BMP_WIN_Init((u16)p->heapId);
    p->win[0] = (void *)BMP_WIN_Create(1, 0, 0, 1, 1, 5, 0);
    p->win[1] = (void *)BMP_WIN_Create(1, 3, 3, 0x1A, 4, 1, 0);
    p->win[2] = (void *)BMP_WIN_Create(1, 3, 8, 0x1A, 4, 1, 0);
    p->win[3] = (void *)BMP_WIN_Create(1, 3, 0xD, 0x1A, 4, 1, 0);
    p->win[4] = (void *)BMP_WIN_Create(1, 8, 0x13, 0xB, 2, 1, 0);
    p->win[5] = (void *)BMP_WIN_Create(1, 0x15, 0x13, 8, 2, 1, 0);
    p->win[6] = (void *)BMP_WIN_Create(0, 2, 1, 0x1C, 4, 5, 1);
    for (i = 0; i < 6; i++) {
        p->slot[i].win = p->win[i];
        p->slot[i].flag = 0;
    }
    p->f98 = (void *)PRINTSYS_QUE_Create((void *)((u16)p->heapId));
    for (i = 0; i < 7; i++) {
        BMP_Clear(BMP_WIN_GetBmp(p->win[i]), 0);
        if (i < 5) {
            w = p->win[i];
            BMP_WIN_TransferChars(w);
            BMP_WIN_MakeScreen(w);
            func_020409B4(BMP_WIN_GetBgLayer(w));
        }
    }
}
