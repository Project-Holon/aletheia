/*
 * function: func_021F4A18
 * address: 0x021F4A18
 * packet: pkt_ov039_021F4A18
 * region: ov039
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * symbols:
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_02188CB4 0x02188CB4 thumb ov021
 *   func_021A3038 0x021A3038 thumb ov021
 *   func_021BE4C4 0x021BE4C4 thumb ov021
 *   func_021BE674 0x021BE674 thumb ov021
 *   func_021BE748 0x021BE748 thumb ov021
 *   func_021F3DE4 0x021F3DE4 thumb ov039
 *   func_021F48C0 0x021F48C0 thumb ov039
 *   func_020120F4 0x020120F4 thumb
 *   func_02012A30 0x02012A30 thumb
 *   func_02028B18 0x02028B18 thumb
 *   func_02047790 0x02047790 arm
 *   func_02047674 0x02047674 arm
 *   func_0207C9D0 0x0207C9D0 arm
 *   func_0207CA00 0x0207CA00 arm
 *   func_0207CBD0 0x0207CBD0 arm
 *   d_021F4CA0 0x021F4CA0 data a4
 *
 * note (2026-10-04, wave D3 lane 09): DIFF, 6 bytes. Logic, frame size and every
 * other stack slot match. Residue: the two loop spills swap. The original keeps
 * q = a1 + k at sp+8 and n (u8, q[0x21EC] + 1) at sp+0xC; this draft gets n at
 * sp+8 and q at sp+0xC. Tried: swapping the q/n declarations, moving them into
 * the loop scope, n as u16 with a (u8) cast, q as u32, q as a compiler temp
 * (moves q to sp+0x28), n inlined as three expressions (no CSE, much worse),
 * int n (adds u16 truncations at the calls). The u8 local always gets the
 * lowest slot here. Keys that closed the rest: k is int k = (u8)i and
 * kk = k is a separate u8 (gives the double truncation), top-level declaration
 * order pos, h, best, bestK, bestN, first, snd, h2 sets the other slots, and
 * the d_021F4CA0 symbols line needs "data a4" (an ov039 token is contested).
 *
 * note (2026-10-05, wave D4 lane 12): still 6 bytes. Tried: int n = (u8)(...) with
 * int-width prototypes for func_021BE674/021F3DE4/02047790 (the loop then matches
 * byte for byte, q at sp+8 and n at sp+0xC, but the second block loses its per-call
 * u16 truncations of bestK/bestN); adding explicit (u16) casts there gets CSE'd once
 * and adds a stack word. So the loop wants a wide n and the second block wants u16
 * parameters. Next: find a source where n is a wide local but the calls keep u16
 * prototypes without re-truncating n (for example n passed through a u16 helper or
 * the second block reading bestK/bestN through u16 stack locals).
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec {
    int x;
    int y;
    int z;
} Vec;

extern Vec d_021F4CA0[];

extern void *func_02188D2C(void *p);
extern void *func_02188C80(void *p);
extern void *func_02188CB4(void *p);
extern void func_021A3038(void *p, Vec *out);
extern int func_021BE4C4(void *p, u32 i, u16 j);
extern u32 func_021BE674(void *p, int i, u16 j, u16 k);
extern int func_021BE748(u32 a);
extern int func_021F3DE4(void *p, u16 j, u16 k);
extern void func_021F48C0(void *a, int idx, int x, Vec *out);
extern void *func_020120F4(void *p);
extern void *func_02012A30(void *p);
extern void func_02028B18(void *s, u32 id, u32 v);
extern int func_02047790(int a, u16 n);
extern u8 *func_02047674(int a);
extern void func_0207C9D0(const Vec *a, const Vec *b, Vec *out);
extern void func_0207CA00(const Vec *a, const Vec *b, Vec *out);
extern int func_0207CBD0(const Vec *v);

void func_021F4A18(void *a0, u8 *a1)
{
    int pos;
    int h;
    int best;
    int bestK;
    int bestN;
    int first;
    void *snd;
    int h2;
    u8 *q;
    u8 n;
    void *sys;
    int i;
    int vol;

    sys = func_02188D2C(a0);
    snd = func_02012A30(func_020120F4(func_02188C80(a0)));
    first = 1;
    for (i = 0; i < 4; i++) {
        int k = (u8)i;
        u8 kk = k;
        Vec v6c;
        Vec v60;
        Vec v54;
        int d;

        h = func_021BE4C4(sys, 0, kk);
        q = a1 + k;
        n = q[0x21EC] + 1;
        func_021BE674(sys, 0, kk, n);
        pos = func_021F3DE4(sys, kk, n);
        func_021F48C0(*(void **)(func_02047674(func_02047790(h, n)) + 8), 0, pos, &v6c);
        func_0207C9D0(&v6c, &d_021F4CA0[k], &v6c);
        func_021A3038(func_02188CB4(a0), &v60);
        func_0207CA00(&v6c, &v60, &v54);
        d = func_0207CBD0(&v54);
        if (best > d || first) {
            best = d;
            bestK = kk;
            bestN = q[0x21EC] + 1;
            first = 0;
        }
    }
    if (best >= 0x60000) {
        vol = 0;
    } else {
        int lim;
        int cur;
        int nxt;
        u8 *img;
        Vec a48;
        Vec a3c;
        Vec a30;
        int d;

        h2 = func_021BE4C4(sys, 0, bestK);
        lim = func_021BE748(func_021BE674(sys, 0, bestK, bestN));
        cur = func_021F3DE4(sys, bestK, bestN);
        nxt = cur + 0x1000;
        if (nxt >= lim)
            nxt = 0;
        img = func_02047674(func_02047790(h2, bestN));
        vol = 0;
        func_021F48C0(*(void **)(img + 8), 0, cur, &a48);
        func_021F48C0(*(void **)(img + 8), 0, nxt, &a3c);
        func_0207CA00(&a48, &a3c, &a30);
        d = func_0207CBD0(&a30);
        if (d >= 0x20000)
            vol = 0x7F;
        else if (d >= 0x18000)
            vol = 0x78;
        else if (d >= 0x10000)
            vol = 0x5A;
        else if (d >= 0x8000)
            vol = 0x3C;
    }
    func_02028B18(snd, 0x68A, vol);
}
