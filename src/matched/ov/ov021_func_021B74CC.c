/*
 * function: PDW_POSTMAN_PrintListWin
 * address:  0x021B74CC
 * packet:   pkt_ov021_021B74CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045B38  0x02045B38  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   FIELD_MSGBG_MsgWinPrintStr  0x02190758  thumb  ov021
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   FIELD_MSGBG_GetMsgWinBmpWin  0x021907C0  thumb  ov021
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 a;
    u16 b;
} Entry;

typedef struct {
    u16 f00;
    u8 pad02[6];
    u32 f08;
    u32 f0C;
    u8 pad10[4];
    u32 f14;
    u32 f18;
    u32 f1C;
    int f20;
    Entry *f24;
} Obj;

struct MsgBank;
struct Rec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
struct Descriptor;
struct WordSet;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void FIELD_MSGBG_MsgWinPrintStr(int a0, int a1, u16 a2, int a3);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 FIELD_MSGBG_GetMsgWinBmpWin(u8 *p);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 index);

void PDW_POSTMAN_PrintListWin(Obj *p)
{
    void *msg;
    int i;

    msg = func_02045B38(0, 2, 0x36, (u16)((p->f00 & 0x7fff) | 0x8000));
    for (i = 0; i < p->f20; i++) {
        MSGDATA_ReadString((struct MsgBank *)((u32)msg), p->f24[i].a, (void *)p->f18);
        FIELD_MSGBG_MsgWinPrintStr(p->f0C, 0, i * 14, p->f18);
        MSGDATA_ReadString((struct MsgBank *)p->f08, 5, (void *)p->f18);
        func_0201EFA4((struct WordSet *)p->f14, 0, p->f24[i].b, 2, 1, 1);
        func_0201F250((struct WordSet *)p->f14, (void *)p->f1C, (void *)p->f18);
        FIELD_MSGBG_MsgWinPrintStr(p->f0C, 0x6c, i * 14, p->f1C);
    }
    MSGDATA_Delete(msg);
    func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)FIELD_MSGBG_GetMsgWinBmpWin((u8 *)p->f0C)));
}
