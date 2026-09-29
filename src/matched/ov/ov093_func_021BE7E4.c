/*
 * function: func_021BE7E4
 * address:  0x021BE7E4
 * packet:   pkt_ov093_021BE7E4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021BE878  0x021BE878  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021C88E4  0x021C88E4  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021BE8C4  0x021BE8C4  thumb  ov093
 *   func_021C5718  0x021C5718  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 func_021CC8D8(void *lock, int line);
extern int func_021BE878(u8 *p, u8 *a, u32 c);
extern u8 func_021D5440(u8 *p);
extern int func_021B8D8C(void *p, void *a, u32 b);
extern int func_021C88E4(u8 *p);
extern void func_021CD4B0(void *w, u32 id, ...);
extern void func_021BE8C4(u8 *p, u8 *a);
extern void func_021C5718(u8 *p, u8 *a, u32 b);
extern void func_021CC95C(void *lock, u32 v, int line);

int func_021BE7E4(u8 *p, u8 *a, u32 b, u32 c, u8 *q)
{
    u32 lk = func_021CC8D8(p + 0x1D74, 3894);
    int r = func_021BE878(p, a, c);
    int s;
    *q = 0;
    if (r) {
        s = func_021B8D8C(*(void **)(p + 4), *(void **)(p + 8), func_021D5440(a));
        if (func_021C88E4(p) == 2) {
            func_021CD4B0(*(void **)(p + 0xC), 0x30, s, c, b, 0);
            func_021BE8C4(p, a);
            *q = 1;
        } else {
            func_021C5718(p, a, b);
        }
    }
    func_021CC95C(p + 0x1D74, lk, 3913);
    return r;
}
