/*
 * function: func_021F5004
 * address:  0x021F5004
 * packet:   pkt_ov194_021F5004
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note (2026-10-05, wD4 lane09): EXACT. `j = 0;` before `p = bufs[k];` at the k-loop top, declaration
 *   order bufs, ret, h, j, idx, k, v, t, and func_021F4DA4 declared with u16 parameters (as its other
 *   callers do) so the call passes m and j uncast; the conversion temp then takes sp+0x20, not sp+0.
 *
 * symbols:
 *   func_021F4D20 0x021F4D20 thumb ov194
 *   func_021F4F50 0x021F4F50 thumb ov194
 *   func_021F4DA4 0x021F4DA4 thumb ov194
 *   func_021F4D9C 0x021F4D9C thumb ov194
 *   func_021F4DA0 0x021F4DA0 thumb ov194
 *   func_021F4F68 0x021F4F68 thumb ov194
 *   func_021F4F6C 0x021F4F6C thumb ov194
 *   func_021F4F60 0x021F4F60 thumb ov194
 *   func_021F4D34 0x021F4D34 thumb ov194
 *   func_02045A98 0x02045A98 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021F4D20(u32 a, u32 b);
extern int func_021F4F50(int a);
extern u32 func_021F4DA4(u8 *p, u16 a, u16 b);
extern u16 func_021F4D9C(const u16 *p);
extern u16 func_021F4DA0(const u16 *p);
extern int func_021F4F68(const u16 *p);
extern unsigned short func_021F4F6C(char *base, int i, int j);
extern void func_021F4F60(void *p);
extern void func_021F4D34(void *p);
extern u16 func_02045A98(void);
u32 func_021F5004(u16 *s, u32 x)
{
    u8 *bufs[4];
    u32 ret;
    u8 *h;
    int j, idx, k;
    u32 v;
    int t;
    int i, m;
    u32 found;
    u8 *p;
    v = (x & 0x7FFF) | 0x8000;
    for (i = 0; i < 4; i++) bufs[i] = (u8 *)func_021F4D20(i, (u16)v);
    h = (u8 *)func_021F4F50(v & 0xFFFF);
    ret = 1;
    idx = 0;
    while (s[idx] != func_02045A98()) {
        found = 0;
        for (k = 0; (u32)k < 4; k++) {
            j = 0;
            p = bufs[k];
            for (; j < (int)func_021F4DA0((const u16 *)p) && found == 0; j++) {
                for (m = 0; m < (int)func_021F4D9C((const u16 *)p) && found == 0; m++) {
                    if (s[idx] == func_021F4DA4(p, m, j)) found = 1;
                }
            }
        }
        for (t = 0; t < func_021F4F68((const u16 *)h); t++) {
            for (m = 0; m < 3; m++) {
                if (s[idx] == func_021F4F6C((char *)h, (u16)t, (u16)m)) found = 1;
            }
        }
        if (found == 0) {
            ret = 0;
            break;
        }
        idx++;
    }
    func_021F4F60(h);
    for (i = 0; i < 4; i++) func_021F4D34(bufs[i]);
    return ret;
}
