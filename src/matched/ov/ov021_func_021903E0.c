/*
 * function: FIELD_MSGBG_Main
 * address:  0x021903E0
 * packet:   pkt_ov021_021903E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   FIELD_MSGBG_SubMsgWinMain  0x021919C8  thumb  ov021
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   TCBL_Main  0x020310C4  arm
 *   TALKMSGWIN_Update  0x0219470C  thumb  ov021
 *   TALKMSGWIN_EndUpdate  0x02194760  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Slot {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u8  f20;
} Slot;

typedef struct Obj {
    u32  f00;
    u32  f04;
    u32  f08;
    u32  f0c;
    Slot slot[4];
    u32  f0a0[8];
} Obj;

struct PrintSys;
struct Q;
struct Tcbl;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern int FIELD_MSGBG_SubMsgWinMain(struct Q *q);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *a);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *a);
extern void TCBL_Main(struct Tcbl *p);
extern void TALKMSGWIN_Update(unsigned char *a);
extern void TALKMSGWIN_EndUpdate(u32 a);

void FIELD_MSGBG_Main(Obj *o)
{
    int i;
    u32 *w;
    Slot *s;
    int j;
    u32 t;

    PRINTSYS_QUE_Main((struct PrintSys *)o->f0c);
    i = 0;
    w = o->f0a0;
    for (; i < 8; i++, w++) {
        if (*w != 0) {
            FIELD_MSGBG_SubMsgWinMain((struct Q *)(*w));
        }
    }
    s = o->slot;
    for (j = 0; j < 4; j++, s++) {
        t = s->f0c;
        if (t != 0) {
            if (s->f20 != 0) {
                if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)t, (void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)s->f1c))) == 0) {
                    BMP_WIN_TransferChars((struct Descriptor *)s->f1c);
                    s->f20 = 0;
                }
            }
            s->f04 = (s->f20 == 0) ? 1 : 0;
        }
    }
    TCBL_Main((struct Tcbl *)(((u32 *)o)[0x59]));
    if (((u32 *)o)[0x57] != 0) {
        TALKMSGWIN_Update((unsigned char *)(((u32 *)o)[0x57]));
        TALKMSGWIN_EndUpdate(((u32 *)o)[0x57]);
    }
}
