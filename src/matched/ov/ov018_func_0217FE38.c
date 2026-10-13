/*
 * function: EVENT_COMM_COMMON_ExitCommonWork
 * address:  0x0217FE38
 * packet:   pkt_ov018_0217FE38
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     the call to 0x02175368 attests through src/matched/ov011_func_02175368.c
 *           (seeded in function_starts.txt). The star is the two bytes of
 *           alignment padding before EVENT_COMM_COMMON_TalkEventMain, not a byte difference.
 * symbols:
 *   EVENT_COMM_COMMON_DeleteChoice  0x0217F4C4  thumb
 *   EVENT_COMM_COMMON_ExitMsgBox  0x0217F318  thumb
 *   INTRUDE_COMM_SetState  0x02174E14  thumb  ov011
 *   INTRUDE_COMM_InitRequest  0x0217538C  thumb  ov011
 *   INTRUDE_COMM_ClearNotice  0x02175368  thumb  ov011
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

typedef struct {
    unsigned char pad00[0x10];
    Ov018Obj obj;
} Ov018Outer;

void EVENT_COMM_COMMON_DeleteChoice(Ov018Obj *p);
void EVENT_COMM_COMMON_ExitMsgBox(Ov018Obj *p);
typedef unsigned char  u8;
void INTRUDE_COMM_SetState(u8 *p, int a);
void INTRUDE_COMM_InitRequest(u8 *p, int a);
void INTRUDE_COMM_ClearNotice(char *p);

void EVENT_COMM_COMMON_ExitCommonWork(void *v, Ov018Outer *c)
{
    EVENT_COMM_COMMON_DeleteChoice(&c->obj);
    EVENT_COMM_COMMON_ExitMsgBox(&c->obj);
    if (v != 0) {
        INTRUDE_COMM_SetState(v, 0);
        INTRUDE_COMM_InitRequest(v, 4);
        INTRUDE_COMM_ClearNotice(v);
    }
}
