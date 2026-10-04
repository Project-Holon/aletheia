/*
 * function: func_021FB034
 * address:  0x021FB034
 * packet:   pkt_ov094_021FB034
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_021FCA04  0x021FCA04  thumb  ov094
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021FF870  0x021FF870  thumb  ov094
 */
typedef struct {
    char pad[0x23C];
    int f23c;
} State;

extern int func_0201134C(void *);
extern int func_021FCA04(State *s, int id, int *out);
extern int func_021F8694(void);
extern void func_021FF870(void *w, int a, int b, int c, int d);

int func_021FB034(void *a, State *s)
{
    int buf[8];
    int n;
    int x;
    int y;
    int z;
    int i;

    n = func_021FCA04(s, func_0201134C(a), buf);
    x = func_0201134C(a);
    y = func_0201134C(a);
    z = func_0201134C(a);
    if (n != 0) {
        if (z == 0)
            z = 1;
        for (i = 0; i < n; i++)
            func_021FF870((void *)func_021F8694(), buf[i], x, y, z);
    }
    return s->f23c;
}
