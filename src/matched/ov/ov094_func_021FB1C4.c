/*
 * function: func_021FB1C4
 * address:  0x021FB1C4
 * packet:   pkt_ov094_021FB1C4
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
 *   func_021FF470  0x021FF470  thumb  ov094
 */
typedef unsigned char u8;

extern int func_0201134C(int a);
extern int func_021FCA04(int b, int t, int *out);
extern int func_021F8694(void);
extern void func_021FF470(void *p, int key, u8 v);

int func_021FB1C4(int a, char *b)
{
    int buf[8];
    int n;
    int i;
    int v;

    n = func_021FCA04((int)b, func_0201134C(a), buf);
    v = func_0201134C(a);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FF470((void *)func_021F8694(), buf[i], v);
    }
    return *(int *)(b + 0x23c);
}
