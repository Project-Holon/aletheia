/*
 * function: func_021F5004
 * address:  0x021F5004
 * packet:   pkt_ov194_021F5004
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * note (2026-10-04): DIFF, 227 bytes but only stack slot numbering and one pad. Control flow and calls match. Original slots: t=sp+0, v=4, k=8, idx=0xc, j=0x10, h=0x14, ret=0x18, idx*2=0x1c, (u16)j=0x20, bufs=0x24; compiled differs (ret=4, idx=0x10, k=0x14, v=0x18, h=0x1c) and pushes r3. Tried declaration reorders and v&0xFFFF to break the cast CSE.
 *
 * note (2026-10-04, lane17): re-run, still 312 bytes vs original, no new change. Lever to try next: slot order is reverse declaration order, original highest slot is bufs then (u16)j, idx*2, ret, h, j, idx, k, v, t.
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
extern u8 *func_021F4D20(u32 a, u32 b);
extern u8 *func_021F4F50(u32 a);
extern u32 func_021F4DA4(u8 *p, u32 a, u32 b);
extern u32 func_021F4D9C(u8 *p);
extern u32 func_021F4DA0(u8 *p);
extern int func_021F4F68(u8 *p);
extern u32 func_021F4F6C(u8 *base, u32 i, u32 j);
extern void func_021F4F60(u8 *p);
extern void func_021F4D34(u8 *p);
extern u32 func_02045A98(void);
u32 func_021F5004(u16 *s, u32 x)
{
    u8 *bufs[4];
    u8 *h;
    u32 v;
    int i, k, idx, j, m, t;
    u32 ret, found;
    v = (x & 0x7FFF) | 0x8000;
    for (i = 0; i < 4; i++) bufs[i] = func_021F4D20(i, (u16)v);
    h = func_021F4F50(v & 0xFFFF);
    ret = 1;
    idx = 0;
    while (s[idx] != func_02045A98()) {
        found = 0;
        for (k = 0; (u32)k < 4; k++) {
            u8 *p = bufs[k];
            for (j = 0; j < (int)func_021F4DA0(p) && found == 0; j++) {
                for (m = 0; m < (int)func_021F4D9C(p) && found == 0; m++) {
                    if (s[idx] == func_021F4DA4(p, (u16)m, (u16)j)) found = 1;
                }
            }
        }
        for (t = 0; t < func_021F4F68(h); t++) {
            for (m = 0; m < 3; m++) {
                if (s[idx] == func_021F4F6C(h, (u16)t, (u16)m)) found = 1;
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
