/*
 * function: func_021F9660
 * address:  0x021F9660
 * packet:   pkt_021F9660
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BGWINFRM_GetPos  0x0202CF98  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_Delete  0x020452E8  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02040DA8  0x02040DA8  arm
 *
 * Redraw the text windows of layout `mode` (0..6): clear and refresh the
 * first n windows of the window table, and when the second brightness
 * byte read by BGWINFRM_GetPos is 0x10 reset the two BG2 screen blocks
 * (func_02041300) and commit them; then refresh window 14 (and 15 for
 * layout 6) and schedule the +0x50 screen.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    void **win;
    u8 pad4[0x18 - 4];
    struct WinMgr *f18;
    u8 pad1C[0x50 - 0x1C];
    u32 f50;
} Obj;

struct WinMgr;
extern void BGWINFRM_GetPos(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);
struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_020409B4(u32 layer);
extern void func_02040DA8(u32, u32, u32);

void func_021F9660(Obj *p, int mode)
{
    s8 bright[2];
    int i = 0;

    BGWINFRM_GetPos(p->f18, 0, &bright[1], &bright[0]);
    switch (mode) {
    case 4:
        for (i = 0; i < 9; i++) {
            BMP_Clear(BMP_WIN_GetBmp(p->win[i]), 10);
            BMP_WIN_TransferChars(p->win[i]);
            BMP_WIN_Delete(p->win[i]);
        }
        if (bright[1] == 0x10) {
            func_02041300(2, 5, 0x10, 1, 1, 0xF, 0x10);
            func_02041300(2, 6, 0x11, 1, 0xF, 0xF, 0x10);
            func_020409B4(2);
        }
        BMP_WIN_Delete(p->win[14]);
        break;
    case 5:
        for (i = 0; i < 4; i++) {
            BMP_Clear(BMP_WIN_GetBmp(p->win[i]), 10);
            BMP_WIN_TransferChars(p->win[i]);
            BMP_WIN_Delete(p->win[i]);
        }
        if (bright[1] == 0x10) {
            func_02041300(2, 5, 0x10, 1, 1, 0xF, 0x10);
            func_02041300(2, 6, 0x11, 1, 0xF, 0xF, 0x10);
            func_020409B4(2);
        }
        BMP_WIN_Delete(p->win[14]);
        break;
    case 0:
        for (i = 0; i < 5; i++) {
            BMP_Clear(BMP_WIN_GetBmp(p->win[i]), 10);
            BMP_WIN_TransferChars(p->win[i]);
            BMP_WIN_Delete(p->win[i]);
        }
        if (bright[1] == 0x10) {
            func_02041300(2, 5, 0x10, 1, 1, 0xF, 0x10);
            func_02041300(2, 6, 0x11, 1, 0xF, 0xF, 0x10);
            func_020409B4(2);
        }
        BMP_WIN_Delete(p->win[14]);
        break;
    case 6:
        for (i = 0; i < 9; i++) {
            BMP_Clear(BMP_WIN_GetBmp(p->win[i]), 10);
            BMP_WIN_TransferChars(p->win[i]);
            BMP_WIN_Delete(p->win[i]);
        }
        if (bright[1] == 0x10) {
            func_02041300(2, 5, 0x10, 1, 1, 0xF, 0x10);
            func_02041300(2, 6, 0x11, 1, 0xF, 0xF, 0x10);
            func_020409B4(2);
        }
        BMP_WIN_Delete(p->win[14]);
        BMP_WIN_Delete(p->win[15]);
        break;
    case 3:
        for (i = 0; i < 6; i++) {
            BMP_Clear(BMP_WIN_GetBmp(p->win[i]), 10);
            BMP_WIN_TransferChars(p->win[i]);
            BMP_WIN_Delete(p->win[i]);
        }
        BMP_WIN_Delete(p->win[14]);
        break;
    case 1:
        for (i = 0; i < 3; i++) {
            BMP_WIN_Delete(p->win[i]);
        }
        BMP_WIN_Delete(p->win[14]);
        break;
    case 2:
        for (i = 0; i < 5; i++) {
            BMP_WIN_Delete(p->win[i]);
        }
        BMP_WIN_Delete(p->win[14]);
        break;
    }
    func_02040DA8(p->f50, 1, 0);
}
