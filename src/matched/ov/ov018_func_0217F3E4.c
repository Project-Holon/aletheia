/*
 * function: EVENT_COMM_COMMON_ClearPrintWin
 * address:  0x0217F3E4
 * packet:   pkt_ov018_0217F3E4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02034714  0x02034714  arm
 *   FIELD_MSGBG_ClearSysWin  0x02190F7C  thumb  ov021
 *   d_02183B2C     0x02183B2C  data
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

extern unsigned char d_02183B2C[];

typedef unsigned int   u32;
void func_02034714(const char *expr, u32 line, const char *file);
struct P;
void FIELD_MSGBG_ClearSysWin(struct P *p);

void EVENT_COMM_COMMON_ClearPrintWin(Ov018Obj *p)
{
    if (p->f18 == 0) {
        func_02034714((const char *)d_02183B2C, 0, (const char *)d_02183B2C);
    }
    FIELD_MSGBG_ClearSysWin(p->f18);
    p->f28 = 0;
}
