/*
 * function: PDW_POSTMAN_ListEvent
 * address:  0x021B7574
 * packet:   pkt_ov021_021B7574
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PDW_POSTMAN_CreateListWin  0x021B7400  thumb  ov021
 *   PDW_POSTMAN_PrintListWin  0x021B74CC  thumb  ov021
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_CreateCursor  0x02192788  thumb  ov021
 *   FIELD_MSGBG_IsMsgWinTransDone  0x0219077C  thumb  ov021
 *   FIELD_MSGBG_GetMsgWinBmpWin  0x021907C0  thumb  ov021
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   FIELD_MSGBG_AnimateCursor  0x021928C0  thumb  ov021
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FIELD_MSGBG_DeleteCursor  0x021927B0  thumb  ov021
 *   PDW_POSTMAN_DeleteListWin  0x021B7494  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Obj {
    u16 f0;
    u16 pad2;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
} Obj;

typedef struct Work {
    u32 f0;
    Obj *f4;
    u32 *f8;
    u32 fC;
    u16 f10;
} Work;

struct Cur;
struct Fx;
struct G;
extern struct Obj *PDW_POSTMAN_CreateListWin(u32 a, u32 b, int c);
extern void PDW_POSTMAN_PrintListWin(Obj *o);
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern struct G *FIELD_MSGBG_CreateCursor(struct Fx *a);
extern int FIELD_MSGBG_IsMsgWinTransDone(u8 *p);
extern u32 FIELD_MSGBG_GetMsgWinBmpWin(u8 *p);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void FIELD_MSGBG_AnimateCursor(struct Cur *c, u32 win, u32 col);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern u32 KEY_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void FIELD_MSGBG_DeleteCursor(u8 *p);
extern int PDW_POSTMAN_DeleteListWin(void *a);
extern u32 func_020307B0(void *p);

int PDW_POSTMAN_ListEvent(void *task, int *st, Work *w)
{
    u16 n;
    u32 h;
    u16 t;

    switch (*st) {
    case 0:
        n = w->fC - w->f10;
        if (n > 7) {
            n = 7;
        }
        w->f4 = PDW_POSTMAN_CreateListWin(w->f0, (u32)(w->f8 + w->f10), n);
        PDW_POSTMAN_PrintListWin(w->f4);
        w->f4->f10 = (u32)FIELD_MSGBG_CreateCursor((struct Fx *)FIELDMAP_GetMsgBg((u8 *)w->f0));
        (*st)++;
        break;
    case 1:
        if (FIELD_MSGBG_IsMsgWinTransDone((u8 *)w->f4->fC) == 1) {
            (*st)++;
        }
        break;
    case 2:
        h = FIELD_MSGBG_GetMsgWinBmpWin((u8 *)w->f4->fC);
        FIELD_MSGBG_AnimateCursor((struct Cur *)w->f4->f10, (u32)BMP_WIN_GetBmp((struct Descriptor *)h), 15);
        BMP_WIN_TransferChars((struct Descriptor *)h);
        if (KEY_GetTrg() & 1) {
            GFL_USE_PlaySeDefaultVolume(0x547);
            (*st)++;
        }
        break;
    case 3:
        FIELD_MSGBG_DeleteCursor((u8 *)w->f4->f10);
        PDW_POSTMAN_DeleteListWin((void *)w->f4);
        (*st)++;
        break;
    case 4:
        if (w->f10 + 7 >= w->fC) {
            func_020307B0(w->f8);
            return 1;
        }
        w->f10 += 7;
        *st = 0;
        break;
    }
    return 0;
}
