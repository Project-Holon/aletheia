/*
 * function: FIELD_MSGBG_DeleteBgWin
 * address:  0x02191B14
 * packet:   pkt_ov021_02191B14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_02045738  0x02045738  arm
 *   func_02045740  0x02045740  arm
 *   FIELD_MSGBG_ClearBgWinFrame  0x02191FA0  thumb  ov021
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   func_02041300  0x02041300  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   func_020452E8  0x020452E8  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02040618  0x02040618  arm
 *   BMP_Delete  0x020437AC  arm
 *   STRBUF_Delete  0x02045808  arm
 *   FIELD_MSGBG_ExitCursor  0x021927E8  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Descriptor;
extern void *func_02045770(struct Descriptor *w);
struct Obj020437AC;
struct U16Vec;
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern u8 func_02045738(struct Descriptor *p);
extern u8 func_02045740(struct Descriptor *p);
extern void FIELD_MSGBG_ClearBgWinFrame(u32 layer, u32 x, u32 y, u32 w, u32 h, u32 tile, u32 mode);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void func_02041300(u32 layer, u32 tile, u32 x, u32 y, u32 w, u32 h, u32 mode);
extern void BMP_WIN_TransferChars(struct Descriptor *w);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020409B4(u32 layer);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void BMP_Delete(struct Obj020437AC *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void FIELD_MSGBG_ExitCursor(u32 *p);
extern u32 func_020307B0(void *p);

void FIELD_MSGBG_DeleteBgWin(u32 *a)
{
    u32 x;
    u32 y;
    u32 w;
    u32 h;

    func_02045770((struct Descriptor *)a[1]);
    x = func_02045758((struct Descriptor *)a[1]);
    y = func_02045760((struct Descriptor *)a[1]);
    w = func_02045738((struct Descriptor *)a[1]);
    h = func_02045740((struct Descriptor *)a[1]);
    FIELD_MSGBG_ClearBgWinFrame((u8)((u16 *)a[0])[1], x, y, w, h, 0, 15);
    BMP_WIN_ClearScreen((struct Descriptor *)a[1]);
    x = func_02045758((struct Descriptor *)a[1]);
    y = func_02045760((struct Descriptor *)a[1]);
    w = func_02045738((struct Descriptor *)a[1]);
    h = func_02045740((struct Descriptor *)a[1]);
    func_02041300((u8)((u16 *)a[0])[1], 0, x, y, w, h, 0x11);
    BMP_WIN_TransferChars((struct Descriptor *)a[1]);
    func_020452E8((struct Descriptor *)a[1]);
    func_020409B4((u8)((u16 *)a[0])[1]);
    func_02040618((u8)((u16 *)a[0])[1], 3, 0);
    BMP_Delete((struct Obj020437AC *)a[3]);
    BMP_Delete((struct Obj020437AC *)a[2]);
    if (a[5] != 0) {
        STRBUF_Delete((struct U16Vec *)a[5]);
    }
    FIELD_MSGBG_ExitCursor(a + 10);
    func_020307B0(a);
}
