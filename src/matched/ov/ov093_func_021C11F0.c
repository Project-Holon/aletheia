/*
 * function: func_021C11F0
 * address:  0x021C11F0
 * packet:   pkt_ov093_021C11F0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 2026-10-05 Q10/Q10b/Q10c/G7L9 (pengy share, user-approved): body from the listing, 47 of 704 bytes off (spill
 *   slot order m/k*4 around the third count, and the 5798/5840/59C4 argument order). Facts kept: v28 is u8,
 *   021C4104 takes sa/sb as separate stack args, 021C1198 takes an int, a7 is a one-bit field struct, the last
 *   loop's byte argument is d_021F3B20[k], 021C5798 has 8 parameters (two unused).
 * pass 2 2026-10-06 P2L45: EXACT (was 47 bytes off). Closing form: variables reused as a person would. The third
 *   count reuses `cnt` (no separate cnt3), the m loop reuses `j` from the cnt2 loop, and the later loops reuse
 *   `i` (neutral). A reused variable gets a second web numbered after the declared locals, which puts the m index
 *   at the lowest slot and the k*4 temp above the count (36 B). Then `cnt` and `cnt2` as u8 (the counts are u8
 *   results): mwcc keeps the reload of a spilled narrow local below the outgoing stack stores
 *   (docs/idioms/a-reload-kept-below-outgoing-stack-stores-is-a-narrow-local.md), which fixes the
 *   5798/5840/59C4 order; u8 cnt2 fixes the cnt/cnt2 slot swap. No (u8) casts needed. EXACT in --lang c99 and c.
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D6D7C  0x021D6D7C  thumb  ov093
 *   func_021D5FC0  0x021D5FC0  thumb  ov093
 *   func_021C14B0  0x021C14B0  thumb  ov093
 *   func_021C14C0  0x021C14C0  thumb  ov093
 *   func_021C14D0  0x021C14D0  thumb  ov093
 *   func_021C0C38  0x021C0C38  thumb  ov093
 *   func_021C0CB4  0x021C0CB4  thumb  ov093
 *   func_021C0CE8  0x021C0CE8  thumb  ov093
 *   func_021C0D70  0x021C0D70  thumb  ov093
 *   func_021C1184  0x021C1184  thumb  ov093
 *   func_021C1194  0x021C1194  thumb  ov093
 *   func_021C1198  0x021C1198  thumb  ov093
 *   func_021C15E8  0x021C15E8  thumb  ov093
 *   func_021C16F8  0x021C16F8  thumb  ov093
 *   func_021C1788  0x021C1788  thumb  ov093
 *   func_021C1828  0x021C1828  thumb  ov093
 *   func_021C1880  0x021C1880  thumb  ov093
 *   func_021C1CCC  0x021C1CCC  thumb  ov093
 *   func_021C1DCC  0x021C1DCC  thumb  ov093
 *   func_021C4104  0x021C4104  thumb  ov093
 *   func_021C4218  0x021C4218  thumb  ov093
 *   func_021C4F64  0x021C4F64  thumb  ov093
 *   func_021C5798  0x021C5798  thumb  ov093
 *   func_021C5840  0x021C5840  thumb  ov093
 *   func_021C59C4  0x021C59C4  thumb  ov093
 *   d_021F3B2C  0x021F3B2C  data  ov093  a4
 *   d_021F3B20  0x021F3B20  data  ov093  a4
 *   d_021F3B38  0x021F3B38  data  a4
 *   d_021F3B26  0x021F3B26  data  ov093  a4
 *   d_021F3B23  0x021F3B23  data  ov093  a4
 *   d_021F3B20b 0x021F3B20  data  ov093  a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Fl { u32 f : 1; };

extern u32 d_021F3B2C[];
extern u8 d_021F3B20[];
extern u8 *d_021F3B38[];
extern u16 d_021F3B26[];
extern u8 d_021F3B23[];
extern u32 d_021F3B20b[];

extern u8 func_021D5440(u8 *p);
extern int func_021D6D7C(u8 *c);
extern void func_021D5FC0(void *c, int v);
extern u8 func_021C14B0(void *p, int n);
extern void func_021C14C0(void *w, u8 *c, int h, int f);
extern void func_021C14D0(void *w, u8 *c, int d, int f);
extern int func_021C0C38(u8 *p, u8 *q, void *o1, void *o2, void *o3, void *o4);
extern int func_021C0CB4(u8 *p, u8 *q, void *out);
extern int func_021C0CE8(u8 *p, u8 *q, void *o1, void *o2, void *o3, void *o4, void *o5);
extern u32 func_021C0D70(u8 *q);
extern int func_021C1184(u8 *p);
extern u8 func_021C1194(u8 *p);
extern void func_021C1198(u8 *p, int x);
extern void func_021C15E8(u8 *p, u8 *a, u8 *b, u16 *c);
extern void func_021C16F8(u8 *p, u8 *a, int k);
extern void func_021C1788(u8 *p, u16 *x, u8 *a, u32 n, void *arr);
extern void func_021C1828(u8 *p, u8 b, u8 *x, u8 *c, u8 *q, u16 w);
extern void func_021C1880(u8 *p, u8 *q, u8 *a, u8 *b, u32 s0, int s1);
extern int func_021C1CCC(u8 *p, u16 *x, u8 *a, u8 *q);
extern void func_021C1DCC(u8 *p, u8 *q, u8 *a, u8 *b, u32 s);
extern int func_021C4104(u8 *p, u8 *q, u8 *c, u16 d, int sa, u8 sb, u16 *e);
extern void func_021C4218(u8 *p, u8 *a, u8 *b, u8 *c, u32 s0, u32 s1, u32 s2, u32 s3);
extern void func_021C4F64(u8 *p, u8 *a);
extern void func_021C5798(u8 *p, u16 *a, u32 n, void *arr, void *ptrs, void *vals, void *w, int f);
extern void func_021C5840(u8 *p, u32 count, void *v, void *a, int flag);
extern void func_021C59C4(u8 *p, u32 n, void *a, void *b, int flag);

int func_021C11F0(u8 *p, u8 *x, u32 unused, u8 *y, u16 *e, u8 *st, u32 a6, struct Fl a7)
{
    int sum;
    u8 v28;
    u8 cnt;
    u8 cnt2;
    int h;
    int i;
    int j;
    int flag;

    v28 = func_021C14B0(p + 0x1AB8, func_021D5440(x));
    sum = func_021C0D70(y);
    cnt = func_021C0C38(p, y, d_021F3B38, d_021F3B26, d_021F3B2C, d_021F3B20);
    for (i = 0; i < cnt; i++) {
        if (func_021D6D7C(d_021F3B38[i])) {
            h = func_021C4104(p, x, d_021F3B38[i], d_021F3B26[i], d_021F3B2C[i], d_021F3B20[i], e);
            func_021C14C0(*(void **)(p + 0x860), d_021F3B38[i], h, 1);
            sum -= d_021F3B26[i] - h;
        }
    }
    if (func_021C1184(st)) {
        cnt2 = func_021C0CB4(p, y, d_021F3B38);
        for (j = 0; j < cnt2; j++)
            func_021C15E8(p, x, d_021F3B38[j], e);
    }
    st[1] = st[1] + 1;
    cnt = func_021C0CE8(p, y, d_021F3B38, d_021F3B26, d_021F3B2C, d_021F3B20, d_021F3B23);
    if (cnt == 0)
        return sum;
    func_021C1788(p, e, x, cnt, d_021F3B38);
    flag = a7.f;
    func_021C5798(p, e, cnt, d_021F3B2C, d_021F3B38, d_021F3B26, d_021F3B20, flag);
    if (func_021C1194(st) == 0)
        func_021C5840(p, cnt, d_021F3B2C, d_021F3B38, flag);
    else
        func_021C1198(st, d_021F3B20b[3]);
    func_021C59C4(p, cnt, d_021F3B38, d_021F3B20, flag);
    for (j = 0; j < cnt; j++) {
        func_021C14D0(*(void **)(p + 0x860), d_021F3B38[j], d_021F3B26[j], 0);
        func_021C1828(p, v28, x, d_021F3B38[j], (u8 *)e, d_021F3B26[j]);
        func_021D5FC0(d_021F3B38[j], 2);
    }
    for (i = 0; i < cnt; i++) {
        if (d_021F3B23[i])
            func_021C16F8(p, d_021F3B38[i], d_021F3B23[i]);
    }
    for (i = 0; i < cnt; i++) {
        func_021C1CCC(p, e, x, d_021F3B38[i]);
        func_021C1DCC(p, (u8 *)e, x, d_021F3B38[i], d_021F3B26[i]);
        func_021C1880(p, (u8 *)e, x, d_021F3B38[i], d_021F3B26[i], 0);
        func_021C4218(p, x, d_021F3B38[i], (u8 *)e, d_021F3B2C[i], d_021F3B26[i], d_021F3B20[i], 0);
    }
    for (i = 0; i < cnt; i++)
        func_021C4F64(p, d_021F3B38[i]);
    func_021C4F64(p, x);
    return sum;
}
