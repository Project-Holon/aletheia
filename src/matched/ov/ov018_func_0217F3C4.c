/*
 * function: EVENT_COMM_COMMON_PrintMsg
 * address:  0x0217F3C4
 * packet:   pkt_ov018_0217F3C4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   EVENT_COMM_COMMON_PrintText  0x0217F3A4  thumb
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

typedef unsigned int   u32;
struct MsgBank;
struct WordSet;
void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
void func_0201F250(struct WordSet *ws, void *dst, void *src);
void EVENT_COMM_COMMON_PrintText(Ov018Obj *p, void *a);

void EVENT_COMM_COMMON_PrintMsg(Ov018Obj *p, int a)
{
    MSGDATA_ReadString(p->f0C, a, p->f08);
    func_0201F250(p->f00, p->f04, p->f08);
    EVENT_COMM_COMMON_PrintText(p, p->f04);
}
