/*
 * function: func_021E3E84
 * address:  0x021E3E84
 * packet:   pkt_ov093_021E3E84
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetHitCount  0x021D6920  thumb  ov093
 *   BTL_POKEPARAM_GetHitRecord  0x021D6940  thumb  ov093
 *   func_021C7D00  0x021C7D00  thumb  ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C7F68  0x021C7F68  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef unsigned int   u32;
extern void *func_021C7CF4(int *p, int i);
extern int BTL_POKEPARAM_GetHitCount(u8 *p, u32 n);
extern int BTL_POKEPARAM_GetHitRecord(const u8 *p, int i, u32 j, u16 *out);
extern int func_021C7D00(u8 *p, int b);
extern int func_021C8010(u8 *p, unsigned int v);
extern u8 func_021C7F68(int *p, int b, u8 *out);
extern u32 BTL_CALC_Random(u32 range);

int func_021E3E84(int u, void *a, int c, int *w)
{
    u8 buf[16];
    void *q;
    unsigned i;
    int x;
    int t;
    int r;

    q = func_021C7CF4(a, c);
    for (i = 0; i < 3; i++) {
        if (BTL_POKEPARAM_GetHitCount(q, (u8)i) != 0) {
            BTL_POKEPARAM_GetHitRecord(q, (u8)i, (int)0, (u16 *)(&buf[6]));
            x = buf[0xb];
            if (func_021C7D00(a, x) == 6) {
                t = func_021C8010(a, c);
                r = func_021C7F68(a, (u16)(0x100 | t), buf);
                if (r != 0)
                    x = buf[(u8)BTL_CALC_Random(r)];
                else
                    x = 0x1f;
            }
            return x;
        }
    }
    return 0x1f;
}
