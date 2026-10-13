/*
 * function: func_021FAE48
 * address:  0x021FAE48
 * packet:   pkt_ov094_021FAE48
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   func_021FCA04  0x021FCA04  thumb  ov094
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021FF5B0  0x021FF5B0  thumb  ov094
 */
typedef struct {
    char pad[0x23C];
    int f23c;
} State;

typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int func_021FCA04(State *s, int id, int *out);
extern int func_021F8694(void);
extern void func_021FF5B0(void *w, int a, int b, int *c, int d, int e, int f);

int func_021FAE48(void *a, State *s)
{
    int t[3];
    int buf[8];
    int n;
    int x;
    int r;
    int u;
    int v;
    int i;

    n = func_021FCA04(s, VM_GetU32(a), buf);
    x = VM_GetU32(a);
    t[0] = VM_GetU32(a);
    t[1] = VM_GetU32(a);
    t[2] = 0x1000;
    r = VM_GetU32(a);
    u = VM_GetU32(a);
    v = VM_GetU32(a);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FF5B0((void *)func_021F8694(), buf[i], x, t, r, u, v);
    }
    return s->f23c;
}
