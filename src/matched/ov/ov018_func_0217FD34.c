/*
 * function: EVENT_COMM_COMMON_CreateTalkedEvent
 * address:  0x0217FD34
 * packet:   pkt_ov018_0217FD34
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   EVENT_COMM_COMMON_InitCommonWork  0x0217FDA0  thumb ov018
 *   EVENT_COMM_COMMON_TalkedEventMain  0x021800A4  thumb ov018
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int w[13];
} S52;

typedef unsigned int   u32;
struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void MI_CpuFill8(void *p, int v, int n);
void EVENT_COMM_COMMON_InitCommonWork(int a, u8 *b, u8 *c, int d, int e, int f, u16 g);
int EVENT_COMM_COMMON_TalkedEventMain(void);

void *EVENT_COMM_COMMON_CreateTalkedEvent(int a, int b, u8 *c, int d, int e, u16 f)
{
    void *r = func_020122C0((void *)a, 0, EVENT_COMM_COMMON_TalkedEventMain, 0x9c);
    u8 *q = func_020124E8(r);

    MI_CpuFill8(q, 0, 0x9c);
    EVENT_COMM_COMMON_InitCommonWork(a, (u8 *)((int *)c), q, b, d, e, f);
    q[0x41] = c[0x11c];
    *(S52 *)(q + 0x44) = *(S52 *)(c + 0x120);
    return r;
}
