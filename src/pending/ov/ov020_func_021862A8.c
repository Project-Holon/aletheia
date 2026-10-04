/*
 * function: func_021862A8
 * address:  0x021862A8
 * packet:   pkt_ov020_021862A8
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-04 (wD3 lane 15): DIFF, 456 bytes (right size), 200 diff bytes, all from one cause. The original spills the
 * func_02012AC8 result (id) to [sp,#0x14] at once and loads it later for the u16 shift (id16 at sp24); this draft
 * keeps id in r7, so every later slot is one word lower (frame 0x2c vs 0x30). Control flow, the qq/items3 double store
 * and all calls match. Tried: id16, qq, items3 as named locals (current), compiler hoist of (u16)id (slots wrong),
 * u16 callee param for func_02186878 (extra mov). Next: find what makes id spill (a second use of id, decl order).
 *
 * symbols:
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_020127C4  0x020127C4  thumb
 *   func_020127E0  0x020127E0  thumb
 *   func_020127F0  0x020127F0  thumb
 *   func_02186278  0x02186278  thumb
 *   func_02161ECC  0x02161ECC  thumb
 *   func_02186BB8  0x02186BB8  thumb
 *   func_02186BE0  0x02186BE0  thumb
 *   func_02013DE0  0x02013DE0  thumb
 *   func_02186B2C  0x02186B2C  thumb
 *   func_02161E78  0x02161E78  thumb
 *   func_02161E60  0x02161E60  thumb
 *   func_02161EEC  0x02161EEC  thumb
 *   func_021867C4  0x021867C4  thumb
 *   func_02186818  0x02186818  thumb
 *   func_0218682C  0x0218682C  thumb
 *   func_020056EC  0x020056EC  thumb
 *   func_02186878  0x02186878  thumb
 *   func_021869D4  0x021869D4  thumb
 *   func_021869DC  0x021869DC  thumb
 *   func_02186804  0x02186804  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020127A4(int a);
extern u32 func_02012AC8(u32 p);
extern char *func_020127C4(int a);
extern u32 func_020127E0(int a);
extern u32 func_020127F0(int a);
extern u32 func_02186278(char *base, int a);
extern int func_02161ECC(char *p);
extern int func_02186BB8(char *p, int a);
extern void func_02186BE0(char *p, int a);
extern int func_02013DE0(u32 id);
extern void func_02186B2C(char *q, char *src);
extern void func_02161E78(char *p);
extern void func_02161E60(char *p, int a);
extern void func_02161EEC(u32 p);
extern int func_021867C4(int a, u32 b);
extern void func_02186818(int h, int a);
extern u16 *func_0218682C(int h);
extern u32 func_020056EC(u32 n);
extern void func_02186878(u32 p, u32 a, u32 b);
extern void func_021869D4(u32 p, u32 a);
extern void func_021869DC(u32 p, u32 a);
extern void func_02186804(int h);

void func_021862A8(int a0, int n, u32 flags)
{
    char *items3;
    char *qq;
    u32 id16;
    char *base;
    u32 p1;
    u32 p2;
    u32 id;
    u32 cnt;
    int mul;
    char *p;
    int off;
    int i;
    int j;
    int h;
    u16 *q;
    u32 acc;
    u32 t;

    id = func_02012AC8(func_020127A4(a0));
    base = func_020127C4(a0);
    p1 = func_020127E0(a0);
    p2 = func_020127F0(a0);
    if (n <= 0) {
        n = 1;
    }
    if (n > 21) {
        n = 21;
    }
    cnt = func_02186278(base, 1);
    j = 0;
    mul = (j - 5) * n;
    id16 = (u16)id;
    qq = base + 0xF8;
    for (i = 0; i < 10; i++) {
        char *e = base + 8 + i * 0x18;
        p = base + i * 0x18;
        if (func_02161ECC(e) != 0) {
            int r;
            p[0xb] = 7;
            r = func_02186BB8(e, mul);
            if (r != 0 && cnt + j >= 10) {
                func_02186BE0(e, 1);
            } else if (r != 0) {
                if (func_02013DE0(id16) == 0) {
                    func_02186B2C(qq, e);
                    func_02161E78(e);
                } else {
                    p[0xb] = 1;
                }
                j++;
            }
        }
    }
    i = 0;
    func_02161E60(base, 0);
    func_02161EEC(p1);
    h = func_021867C4(0, (u16)((flags & 0x7FFF) | 0x8000));
    if (*(u16 *)(base + 2) == 1) {
        for (i = 0; i < 10; i++) {
            char *e = base + 8 + i * 0x18;
            if (func_02161ECC(e) != 0) {
                func_02186818(h, *(u8 *)(base + i * 0x18 + 9));
                q = func_0218682C(h);
                if ((u16)func_020056EC(100) < q[0x26 / 2]) {
                    func_02186878(p1, q[0x24 / 2], (u16)func_020056EC(10));
                }
            }
        }
        i = 0;
        cnt = func_02186278(base, 0);
        if (cnt != 0) {
            acc = 0;
            items3 = base + 8;
            t = func_020056EC(cnt * 3);
            for (j = 0; j < 10; j++) {
                off = j * 0x18;
                if (func_02161ECC(items3 + off) != 0) {
                    acc += 3;
                    if (acc > t) {
                        func_02186818(h, *(u8 *)(base + off + 9));
                        q = func_0218682C(h);
                        func_021869D4(p2, q[(t % 3) + 4]);
                        func_021869DC(p2, q[0x24 / 2]);
                        break;
                    }
                }
            }
        }
    }
    func_02186804(h);
}
