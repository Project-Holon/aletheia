/*
 * function: func_021D39A8
 * address:  0x021D39A8
 * packet:   pkt_ov093_021D39A8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D8090  0x021D8090  thumb  ov093
 *   func_021D3A10  0x021D3A10  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D6064  0x021D6064  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021D8090(u32 v, u8 *out);
extern u32 func_021D3A10(u32 i);
extern u8 *func_021B9934(u8 *p, u8 i);
extern int func_021D5B68(u8 *p);
extern void func_021D6064(u8 *p, u32 a, int b, int c);

int func_021D39A8(u8 *a, int b, u32 *s)
{
    u8 buf[6];
    u32 i;
    u32 n;
    u32 m;
    u32 j;
    u32 t;
    u8 *q;

    n = s[1];
    m = s[0];
    func_021D8090(s[2], buf);
    for (i = 0; i < n; i++) {
        t = func_021D3A10(i);
        if (t == 0)
            break;
        for (j = 0; j < m; j++) {
            q = func_021B9934(*(u8 **)(a + 4), buf[j]);
            if (func_021D5B68(q) == 0)
                func_021D6064(q, t, 0, 0);
        }
    }
    return 1;
}
