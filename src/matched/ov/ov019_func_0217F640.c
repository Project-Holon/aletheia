/*
 * function: UNION_MSG_SetupRegulationWindow
 * address:  0x0217F640
 * packet:   pkt_ov019_0217F640
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * pass 4 2026-10-06 P4L11: closed. The palette value is assigned as a full
 * constant in each arm (pal = 0x1040 / 0x440). mwcc splits each constant into
 * movs + lsls #6 and merges the common shift at the join, which gives the same
 * stream as "pal = 0x41 / 0x11; pal <<= 6;" but a different pre-allocation
 * graph: self r5, h and pal r7, flag and tile temps r6 as in the original.
 * EXACT under --lang c99 and --lang c.
 *
 * symbols:
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   func_02034714  0x02034714  arm
 *   FIELD_MSGBG_CreatePlainWin  0x02191558  thumb  ov021
 *   POKE_REGULATION_CreateText  0x0201A4D4  thumb
 *   UNION_MSG_RegisterPartnerWords  0x0217EE90  thumb  ov019
 *   func_0200AE3C  0x0200AE3C  thumb
 *   FIELD_MSGBG_PlainWinPrintStr  0x02191648  thumb  ov021
 *   STRBUF_Delete  0x02045808  arm
 *   FIELD_MSGBG_PlainWinPrintMsg  0x0219161C  thumb  ov021
 *   FIELD_MSGBG_PlainWinPrintStrColor  0x02191674  thumb  ov021
 *   d_021807F8     0x021807F8  data  ov019  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Tiles {
    u32 f0;
    u32 a[6];
    u32 b[6];
} Tiles;

typedef struct Self {
    u8     pad0[0x2804];
    void  *win2804;
    void  *msg2808;
    u8     pad280C[0xc];
    void  *f2818;
    u8     pad281C[0xd10];
    void  *f352C;
    Tiles *f3530;
} Self;

struct Fx;
struct R;
struct Reg;
struct U16Vec;
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern void  func_02034714(const char *a, u32 b, const char *c);
extern struct R *FIELD_MSGBG_CreatePlainWin(struct Fx *a, u32 b, u32 c, u16 d, u16 e, u16 f, u16 g);
extern u8 *POKE_REGULATION_CreateText(u8 *a0, u32 a1, u16 a2, u32 a3);
extern void  UNION_MSG_RegisterPartnerWords(Self *self);
extern void *func_0200AE3C(struct Reg *p, u32 heap);
extern void FIELD_MSGBG_PlainWinPrintStr(struct R *r, int b, int c, u32 d);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void FIELD_MSGBG_PlainWinPrintMsg(struct R *r, int b, int c, u32 d);
extern void  FIELD_MSGBG_PlainWinPrintStrColor(void *a, int b, u16 c, u32 d, int e);
extern u32 d_021807F8[];

void UNION_MSG_SetupRegulationWindow(Self *self, u32 a1, u32 mask, int mode, int msg)
{
    u32 h = FIELDMAP_GetMsgBg((u8 *)a1);
    void *s;
    long i;
    int flag;

    if (self->win2804 == 0)
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    if (self->f2818 != 0)
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    if (self->f3530 != 0)
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);

    flag = 1;
    if (mode != 1)
        flag = 0;
    self->f2818 = FIELD_MSGBG_CreatePlainWin((struct Fx *)h, (u32)self->msg2808, 0, 1, 1, 0x1a, 0x10);
    self->f3530 = (Tiles *)POKE_REGULATION_CreateText(self->f352C, (u32)self->win2804, 0x41, flag);
    UNION_MSG_RegisterPartnerWords(self);

    if (msg == 0) {
        s = func_0200AE3C(self->f352C, 0x41);
        FIELD_MSGBG_PlainWinPrintStr(self->f2818, 0, 0, (u32)s);
        STRBUF_Delete(s);
    } else {
        FIELD_MSGBG_PlainWinPrintMsg(self->f2818, 0, 0, msg == 1 ? 0x14f : 0x150);
    }

    for (i = 0; i < 6; i++) {
        int pal;
        if (mask & (1 << i)) {
            pal = 0x1040;
        } else {
            pal = 0x440;
        }
        FIELD_MSGBG_PlainWinPrintStrColor(self->f2818, 0, (i * 2 + 4) * 8, self->f3530->a[i], pal);
        FIELD_MSGBG_PlainWinPrintStrColor(self->f2818, 0x70, (i * 2 + 4) * 8, self->f3530->b[i], pal);
    }
}
