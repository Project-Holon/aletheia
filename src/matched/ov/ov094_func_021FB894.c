/*
 * function: func_021FB894
 * address:  0x021FB894
 * packet:   pkt_ov094_021FB894
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_021F86F0  0x021F86F0  thumb  ov094
 *   func_02201DB4  0x02201DB4  thumb  ov094
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;

typedef struct {
    char pad[0xcc];
    int t[92];
    int f23c;
} State;

extern int func_0201134C(int);
extern int func_021F86F0(void);
extern void func_02201DB4(char *base, int idx, u8 b, u8 c, s8 step, u16 d);

int func_021FB894(int a, State *s)
{
    int v0 = func_0201134C(a);
    int v1 = func_0201134C(a);
    int v2 = func_0201134C(a);
    int v3 = func_0201134C(a);
    int v4 = func_0201134C(a);

    func_02201DB4((char *)func_021F86F0(), s->t[v0], v1, v2, v3, v4);
    return s->f23c;
}
