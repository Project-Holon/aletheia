/*
 * function: EVENT_COMM_COMMON_SetupPrintWin
 * address:  0x0217F36C
 * packet:   pkt_ov018_0217F36C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   EVENT_COMM_COMMON_ClearPrintWin  0x0217F3E4  thumb
 *   FIELD_MSGBG_CreateBottomSysWin  0x02190F64  thumb  ov021
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

void EVENT_COMM_COMMON_ClearPrintWin(Ov018Obj *p);
typedef unsigned int   u32;
struct Fx;
struct Obj2;
struct Obj2 *FIELD_MSGBG_CreateBottomSysWin(struct Fx *a, u32 b);

void EVENT_COMM_COMMON_SetupPrintWin(Ov018Obj *p)
{
    if (p->f18 != 0) {
        if (p->f28 == 1) {
            EVENT_COMM_COMMON_ClearPrintWin(p);
        }
    } else {
        p->f18 = FIELD_MSGBG_CreateBottomSysWin(p->f24, (u32)p->f0C);
    }
}
