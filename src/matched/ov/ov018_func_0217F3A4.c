/*
 * function: EVENT_COMM_COMMON_PrintText
 * address:  0x0217F3A4
 * packet:   pkt_ov018_0217F3A4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   EVENT_COMM_COMMON_SetupPrintWin  0x0217F36C  thumb
 *   FIELD_MSGBG_SysWinPrintStr  0x02190EB8  thumb  ov021
 */

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
    unsigned char pad29[3];
    void *f2C;
} Ov018Obj;

void EVENT_COMM_COMMON_SetupPrintWin(Ov018Obj *p);
typedef unsigned short u16;
typedef unsigned int   u32;
struct P;
void FIELD_MSGBG_SysWinPrintStr(struct P *p, u32 b, u16 c, u32 d);

void EVENT_COMM_COMMON_PrintText(Ov018Obj *p, void *a)
{
    EVENT_COMM_COMMON_SetupPrintWin(p);
    FIELD_MSGBG_SysWinPrintStr(p->f18, 0, 0, (u32)a);
    p->f28 = 1;
}
