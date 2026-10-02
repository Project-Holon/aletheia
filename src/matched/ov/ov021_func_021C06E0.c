/*
 * function: func_021C06E0
 * address:  0x021C06E0
 * packet:   pkt_ov021_021C06E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DA08C  0x021DA08C  data
 *   ov021_id  0x00000015  data
 *   func_0200FB38  0x0200FB38  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012138  0x02012138  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_020146F8  0x020146F8  thumb
 *   func_0202647C  0x0202647C  thumb
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_02188BE8  0x02188BE8  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_021C0780  0x021C0780  thumb  ov021
 */

typedef unsigned int u32;

extern u32 d_021DA08C[];
extern char ov021_id[];
extern u32 func_020124E4(u32);
extern u32 func_0201210C(u32);
extern u32 func_02012138(u32);
extern u32 func_020120F4(u32);
extern int func_02012B70(u32);
extern int func_0202647C(u32);
extern u32 func_020122C0(u32 a, u32 b, void (*fn)(void), u32 c);
extern void func_0200FB38(void);
extern u32 func_020146F8(u32 a, u32 b, u32 c, void *d, u32 e);
extern void func_02012374(u32, u32);
extern u32 func_02188C7C(u32);
extern int func_02188BE8(u32);
extern void func_0216D9A0(u32);
extern void func_0216D9E4(u32);
extern void func_021C0780(void);

int func_021C06E0(u32 a, int *st)
{
    u32 h = func_020124E4(a);
    u32 o = func_0201210C(h);
    u32 v;

    switch (*st) {
    case 0:
        func_0216D9A0(func_02188C7C(o));
        if (func_0202647C(func_02012138(h)) == 2) {
            if (func_02012B70(func_020120F4(h)) == 1) {
                func_0200FB38();
                v = func_020146F8(h, o, (u32)ov021_id, d_021DA08C, h);
            } else {
                v = func_020122C0(h, 0, func_021C0780, 0);
            }
        } else {
            func_0200FB38();
            v = func_020146F8(h, o, (u32)ov021_id, d_021DA08C, h);
        }
        func_02012374(a, v);
        (*st)++;
        break;
    case 1:
        if (o != 0 && func_02188BE8(o) == 1) {
            func_0216D9E4(func_02188C7C(o));
            return 1;
        }
        break;
    }
    return 0;
}
