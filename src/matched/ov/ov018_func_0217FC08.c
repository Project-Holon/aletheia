/*
 * function: EVENT_COMM_COMMON_CreateTalkEvent
 * address:  0x0217FC08
 * packet:   pkt_ov018_0217FC08
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   EVENT_COMM_COMMON_InitCommonWork  0x0217FDA0  thumb ov018
 *   INTRUDE_COMM_InitRequest  0x0217538C  thumb  ov011
 *   INTRUDE_COMM_ClearNotice  0x02175368  thumb  ov011
 *   EVENT_COMM_COMMON_GetTalkType  0x021803F0  thumb  ov018
 *   EVENT_COMM_COMMON_TalkEventMain  0x0217FE6C  thumb  ov018
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef unsigned int   u32;
struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void func_02082BCC(void *p, int v, int n);
void EVENT_COMM_COMMON_InitCommonWork(int a, u8 *b, u8 *c, int d, int e, int f, u16 g);
void INTRUDE_COMM_InitRequest(u8 *w, int a);
void INTRUDE_COMM_ClearNotice(char *p);
int EVENT_COMM_COMMON_GetTalkType(u8 *a, u8 *b);
int EVENT_COMM_COMMON_TalkEventMain(void);

void *EVENT_COMM_COMMON_CreateTalkEvent(int a, int b, u8 *c, int d, int e, u16 f)
{
    void *r = func_020122C0((void *)a, 0, EVENT_COMM_COMMON_TalkEventMain, 0x9c);
    u8 *q = func_020124E8(r);

    func_02082BCC(q, 0, 0x9c);
    EVENT_COMM_COMMON_InitCommonWork(a, (u8 *)((int *)c), q, b, d, e, f);
    INTRUDE_COMM_InitRequest(c, e);
    INTRUDE_COMM_ClearNotice((char *)c);
    q[0x41] = EVENT_COMM_COMMON_GetTalkType(q, c);
    return r;
}
