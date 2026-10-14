/*
 * function: BTLV_EFFVM_CmdStartPokeRotateTween
 * address:  0x021FAECC
 * packet:   pkt_ov094_021FAECC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   BTLV_EFFVM_ResolveBattlerList  0x021FCA04  thumb  ov094
 *   BTLV_EFFECT_GetMcss  0x021F8694  thumb  ov094
 *   BTLV_MCSS_StartRotateTween  0x021FF730  thumb  ov094
 */
typedef struct {
    char pad[0x23C];
    int f23c;
} State;

typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int BTLV_EFFVM_ResolveBattlerList(State *s, int id, int *out);
extern int BTLV_EFFECT_GetMcss(void);
extern void BTLV_MCSS_StartRotateTween(void *w, int a, int b, int *c, int d, int e, int f);

int BTLV_EFFVM_CmdStartPokeRotateTween(void *a, State *s)
{
    int buf[8];
    int t[3];
    int n;
    int x;
    int r;
    int u;
    int v;
    int i;

    n = BTLV_EFFVM_ResolveBattlerList(s, VM_GetU32(a), buf);
    x = VM_GetU32(a);
    i = 0;
    t[0] = 0;
    t[1] = 0;
    t[2] = VM_GetU32(a);
    r = VM_GetU32(a);
    u = VM_GetU32(a);
    v = VM_GetU32(a);
    if (n != 0) {
        for (; i < n; i++)
            BTLV_MCSS_StartRotateTween((void *)BTLV_EFFECT_GetMcss(), buf[i], x, t, r, u, v);
    }
    return s->f23c;
}
