/*
 * function: func_021FA09C
 * address:  0x021FA09C
 * packet:   pkt_ov094_021FA09C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_021FCA04  0x021FCA04  thumb  ov094
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021FDB20  0x021FDB20  thumb  ov094
 *   func_021FF228  0x021FF228  thumb  ov094
 *   func_021FF1F4  0x021FF1F4  thumb  ov094
 */
typedef struct {
    char pad[0x23C];
    int f23c;
    char pad2[4];
    int f244;
} State;

extern int func_0201134C(void *);
extern int func_021FCA04(State *s, int id, int *out);
extern int func_021F8694(void);
extern void func_021FDB20(State *s);
extern void func_021FF228(void *w, int a);
extern void func_021FF1F4(void *w, int a);

int func_021FA09C(void *a, State *s)
{
    int buf[8];
    int x;
    int n;
    int i;

    x = func_0201134C(a);
    if (func_0201134C(a) == 0) {
        s->f244 = x;
        func_021FDB20(s);
    } else {
        n = func_021FCA04(s, 14, buf);
        if (n != 0) {
            for (i = 0; i < n; i++) {
                if (x == 1)
                    func_021FF228((void *)func_021F8694(), buf[i]);
                else
                    func_021FF1F4((void *)func_021F8694(), buf[i]);
            }
        }
    }
    return s->f23c;
}
