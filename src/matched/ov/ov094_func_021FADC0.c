/*
 * function: BTLV_EFFVM_CmdStartPokeBounce
 * address:  0x021FADC0
 * packet:   pkt_ov094_021FADC0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   func_0207C768  0x0207C768  arm
 *   BTLV_EFFVM_ResolveBattlerList  0x021FCA04  thumb  ov094
 *   BTLV_EFFECT_GetMcss  0x021F8694  thumb  ov094
 *   BTLV_MCSS_StartBounceTask  0x021FFB04  thumb  ov094
 */
typedef struct {
    char pad[0x23C];
    int f23c;
} State;

typedef struct {
    int f0;
    int item;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
} Req;

struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *p);
typedef unsigned int   u32;
extern u32 func_0207C768(u32 a, u32 b);
extern int BTLV_EFFVM_ResolveBattlerList(State *s, int id, int *out);
extern int BTLV_EFFECT_GetMcss(void);
extern void BTLV_MCSS_StartBounceTask(void *w, Req *r);

int BTLV_EFFVM_CmdStartPokeBounce(void *a, State *s)
{
    Req q;
    int buf[8];
    int n;
    int p;
    int r;
    int t;
    int u;
    int v;
    int i;

    n = BTLV_EFFVM_ResolveBattlerList(s, VM_GetU32(a), buf);
    p = VM_GetU32(a);
    r = VM_GetU32(a);
    t = VM_GetU32(a);
    u = VM_GetU32(a);
    v = VM_GetU32(a);
    q.f18 = r;
    q.f24 = v;
    q.f14 = p;
    q.f20 = u;
    q.f1c = func_0207C768(t - r, v << 12);
    if (n != 0) {
        for (i = 0; i < n; i++) {
            q.item = buf[i];
            BTLV_MCSS_StartBounceTask((void *)BTLV_EFFECT_GetMcss(), &q);
        }
    }
    return s->f23c;
}
