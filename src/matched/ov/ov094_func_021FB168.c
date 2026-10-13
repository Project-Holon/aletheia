/*
 * function: func_021FB168
 * address:  0x021FB168
 * packet:   pkt_ov094_021FB168
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   func_021FCA04  0x021FCA04  thumb  ov094
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021FF374  0x021FF374  thumb  ov094
 *   func_02200654  0x02200654  thumb  ov094
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
extern void func_021FF374(void *w, int a, int b);
extern void func_02200654(void *w);

int func_021FB168(void *a, State *s)
{
    int buf[8];
    int n;
    int v;
    int i;

    n = func_021FCA04(s, VM_GetU32(a), buf);
    v = VM_GetU32(a);
    if (v == 5) {
        func_02200654((void *)func_021F8694());
    } else if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FF374((void *)func_021F8694(), buf[i], v);
    }
    return s->f23c;
}
