/*
 * function: func_021F3884
 * address:  0x021F3884
 * packet:   pkt_ov041_021F3884
 * region:   ov041
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Closed 2026-10-05 (wD9r lane 36), after many waves at an "s keeps r7" allocator residue. The residue
 * was source shape, not the allocator:
 *   - case 1: c and len read into locals (c first), and the clamp written as an if/else with BOTH
 *     stores (0x71C and 0x71E) in each arm; tail merging rebuilds the image's single join store and
 *     its empty-arm `b`. This alone moves s to its spill slot [sp,#0x24] and gives frame 0xE8.
 *   - cases 2, 4, 5: `v = func_021BE6E8(...)` then `v / 4096` at each compare (the r*2 index is then
 *     computed before the divide, as in the image).
 *   - all aggregate locals (req, pos, base, end, start, path, fin) are block-scoped where they are
 *     used; their slots then follow the order of appearance, and `Vec x = {0, 0, 0}` gives the
 *     `add rN,sp,#K; str [rN]` zeroing form.
 *   - the tail after the switch is `if (w[2] != 0) { ... } return 0;` (one shared epilogue).
 *   - the tail uses its own local m2 (declared between r and sel) for its spill slot.
 * symbols:
 *   func_021F3F18  0x021F3F18  thumb  ov041
 *   func_021F3F44  0x021F3F44  thumb  ov041
 *   func_021F3FC0  0x021F3FC0  thumb  ov041
 *   func_021F3FD8  0x021F3FD8  thumb  ov041
 *   func_021F3FEC  0x021F3FEC  thumb  ov041
 *   func_021F4000  0x021F4000  thumb  ov041
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_021BE6E8  0x021BE6E8  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_0218F818  0x0218F818  thumb  ov021
 *   func_02158780  0x02158780  thumb  ov010
 *   func_0218F900  0x0218F900  thumb  ov021
 *   func_0218FE50  0x0218FE50  thumb  ov021
 *   func_0218E13C  0x0218E13C  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_0218F05C  0x0218F05C  thumb  ov021
 *   func_0218F878  0x0218F878  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_0218ECE4  0x0218ECE4  thumb  ov021
 *   func_0218F930  0x0218F930  thumb  ov021
 *   func_0218FE70  0x0218FE70  thumb  ov021
 *   func_0218EC60  0x0218EC60  thumb  ov021
 *   func_0218F9C4  0x0218F9C4  thumb  ov021
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_02011428  0x02011428  thumb
 *   func_02011608  0x02011608  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_02011558  0x02011558  thumb
 *   func_02011688  0x02011688  thumb
 *   d_021F4320     0x021F4320  data  a4
 *   d_021F4198     0x021F4198  data  a2
 *   d_021F40F0     0x021F40F0  data  a2
 *   d_021F4084     0x021F4084  data  a2
 *   d_021F408C     0x021F408C  data  a2
 *   d_021F4094     0x021F4094  data  a2
 *   d_021F409C     0x021F409C  data  a2
 *   d_021F40B4     0x021F40B4  data  a2
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { int x, y, z; } Vec;
typedef struct { int id; int x, y, z; int k; } Ent;
typedef struct { u16 a; u16 b; u8 e; u8 c; u8 d; u8 f; } Anim;
typedef struct { u16 a; u16 pad; u16 b; } E6;
typedef struct { u8 pad[0x24]; u16 a; u16 b; u8 pad2[8]; int c; int d; int e; int f; int g; u8 pad3[4]; } Req;
typedef struct { int a, b, c, d, e, f; } Six;

extern Ent d_021F4320[][4];
extern Anim d_021F4198[];
extern E6 d_021F40F0[];
extern u16 d_021F4084[];
extern u16 d_021F408C[];
extern u16 d_021F4094[];
extern u16 d_021F409C[];
extern u16 d_021F40B4[];

struct Big;
struct Ctx;
struct IcaAnime;
struct Obj;
struct Rec12;
struct VecFx32;
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188D2C(int *p);
extern int *func_021897BC(char *p, int idx);
extern void *func_02188C58(void *);
extern void *func_02188C80(void *);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern void func_0200B3A4(void *, int);
extern void func_0218F0A8(u8 *a);
extern void func_021F3FEC(u8 *);
extern u32 func_0218F0E8(u8 *a);
extern int func_021F3F44(int);
extern int func_021F3FC0(u32, int);
extern u16 func_021F3F18(int);
extern void *func_02011428(u32 heap, u32 a1, u32 a2, u32 a3, u32 a4);
extern u16 func_02011608(u32);
extern void func_021BE700(void *p, int i, int j, int k, int flag);
extern void func_021BE6CC(void *, int, u16, u16, int);
extern int func_021BE6E8(int a, int b, int c, int d);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern void func_021BE6B0(unsigned char *p, int v);
extern void func_0218F818(u8 *a);
extern void func_020061E4(u32);
extern int func_02158780(void *p, int b, int c, int d, u16 e);
extern void func_0218F900(void *, Req *, u8);
extern int func_0218FE50(u8 *a);
extern void func_0218E13C(u8 *a, u32 s);
extern void *func_02188CB4(u8 *p);
extern void *func_021A3074(u8 *p);
extern void func_0216DAC8(unsigned int *p, unsigned int v);
extern void func_0216D548(u32 *p, u32 v);
extern void func_0216D568(void *p, u32 v);
extern void func_021F3FD8(u8 *);
extern void func_021A3044(u8 *p, void *v);
extern void func_0216D550(u32 *p, u32 v);
extern void func_02011558(struct IcaAnime *p);
extern void func_0218F05C(unsigned char *a);
extern void func_0218F878(u8 *a);
extern u32 func_02011688(struct IcaAnime *p, struct Rec12 *dst, u32 idx);
extern void func_021A3038(u8 *p, struct VecFx32 *out);
extern void func_0218EC54(u8 *p);
extern void func_0218ECE4(void *, Vec *);
extern void func_0218F930(u8 *p, u8 *a, u8 *b, u32 *c, u16 v);
extern u8 *func_0218FE70(u8 *p);
extern int func_0218EC60(u32 a);
extern void func_0218F9C4(u8 *p, u8 *src, u16 v);
extern void func_0216D570(char *p, u32 v);
extern u32 func_0216D57C(void *p, u32 v);
extern void func_021F4000(u8 *p, u8 *obj);

int func_021F3884(void *a0, int *state)
{
    void *ctx;
    void *s;
    u8 *w;
    void *obj;
    void *cam;
    int v;
    u16 b0;
    u16 n;
    int row;
    int r;
    void *m2;
    int sel;
    u16 len;
    int c;
    u16 i1;
    u16 i3;
    u16 i4;
    u16 i6;
    u16 idx;
    void *m;

    ctx = func_0201210C(func_020124E4(a0));
    s = (void *)func_02188D2C(ctx);
    w = (u8 *)func_021897BC(ctx, 1);
    obj = func_02188C58(ctx);
    func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(ctx))), 5);
    switch (*state) {
    case 0:
        func_0218F0A8(obj);
        func_021F3FEC(w + 0x720);
        (*state)++;
        break;
    case 1:
        if ((int)func_0218F0E8(obj) != 0)
            break;
        row = w[0];
        sel = func_021F3F44(w[1]);
        v = d_021F4320[w[0]][sel].id;
        if (v == -1)
            return 1;
        *(u32 *)(w + 0x714) = (u32)func_02011428((int)0x8015, (int)0x79, (int)v, (u32)(w + 4), (int)0x708);
        *(u16 *)(w + 0x71A) = func_02011608(*(u32 *)(w + 0x714));
        idx = (u16)d_021F4320[row][sel].k;
        c = d_021F4198[idx].c;
        len = d_021F4198[idx].d;
        n = *(u16 *)(w + 0x71A);
        if (c + len >= n) {
            *(u16 *)(w + 0x71C) = n - (len + 1);
            *(u16 *)(w + 0x71E) = len;
        } else {
            *(u16 *)(w + 0x71C) = c;
            *(u16 *)(w + 0x71E) = len;
        }
        w[3] = 0;
        b0 = w[0];
        i1 = func_021F3F18(func_021F3FC0(w[1], b0));
        func_021BE700(s, 0, (u16)b0, (u16)i1, 1);
        func_021BE700(s, 0, (u16)b0, (u16)(i1 + 1), 1);
        func_021BE6CC(s, 0, b0, i1, 0);
        func_021BE6CC(s, 0, b0, i1 + 1, 0);
        func_0218F818(obj);
        (*state)++;
        break;
    case 2:
        b0 = w[0];
        r = func_021F3FC0(w[1], b0);
        v = func_021BE6E8((int)s, 0, (u16)b0, (u16)func_021F3F18(r));
        if (v / 4096 == d_021F4084[r])
            func_020061E4(0x698);
        if (v / 4096 < d_021F408C[r])
            break;
        i3 = func_021F3F18(r);
        func_021BE6B0(func_021BE674(s, 0, (u16)b0, (u16)i3), 1);
        func_021BE6B0(func_021BE674(s, 0, (u16)b0, (u16)(i3 + 1)), 1);
        func_02158780(a0, 2, 0, 0, (int)0x8015);
        idx = (u16)d_021F4320[w[0]][func_021F3F44(w[1])].k;
        {
        Req req;
        req.a = d_021F4198[idx].a;
        req.b = d_021F4198[idx].b;
        req.c = 0;
        req.d = 1;
        req.e = 1;
        req.f = 0;
        req.g = 0;
        func_0218F900(obj, &req, d_021F4198[idx].e);
        }
        (*state)++;
        break;
    case 3:
        if (func_0218FE50(obj) != 0)
            break;
        func_0218E13C(obj, (int)2);
        m = func_021A3074(func_02188CB4(ctx));
        func_0216DAC8(m, (int)1);
        func_0216D548(m, (int)0x200);
        func_0216D568(m, (int)0x8000);
        b0 = w[0];
        i4 = func_021F3F18(func_021F3FC0(w[1], b0));
        func_021BE6B0(func_021BE674(s, 0, (u16)b0, (u16)i4), 0);
        func_021BE6B0(func_021BE674(s, 0, (u16)b0, (u16)(i4 + 1)), 0);
        func_020061E4(0x699);
        (*state)++;
        break;
    case 4:
        b0 = w[0];
        r = func_021F3FC0(w[1], b0);
        v = func_021BE6E8((int)s, 0, (u16)b0, (u16)func_021F3F18(r));
        if (v / 4096 < d_021F409C[r])
            break;
        func_020061E4(0x6A0);
        w[2] = 1;
        *(u16 *)(w + 0x718) = 0;
        (*state)++;
        break;
    case 5:
        b0 = w[0];
        r = func_021F3FC0(w[1], b0);
        v = func_021BE6E8((int)s, 0, (u16)b0, (u16)func_021F3F18(r));
        if (v / 4096 == d_021F4094[r]) {
            func_020061E4(0x696);
            if (w[3] == 0) {
                func_021F3FD8(w);
                func_0218E13C(obj, (int)1);
            }
            func_0216DAC8(func_021A3074(func_02188CB4(ctx)), (int)0);
        }
        if (w[2] != 0)
            break;
        cam = func_02188CB4(ctx);
        {
            Vec pos = {0, 0, 0};
            Ent *e = &d_021F4320[w[0]][func_021F3F44(w[1])];
            pos.x = (e->x << 16) + 0x8000;
            pos.y = e->y << 16;
            pos.z = (e->z << 16) + 0x8000;
            func_021A3044(cam, &pos);
        }
        (*state)++;
        break;
    case 6:
        func_0216D550(func_021A3074(func_02188CB4(ctx)), (int)0x200);
        func_02011558((struct IcaAnime *)(*(u32 *)(w + 0x714)));
        b0 = w[0];
        i6 = func_021F3F18(func_021F3FC0(w[1], b0));
        func_021BE700(s, 0, (u16)b0, (u16)i6, 0);
        func_021BE700(s, 0, (u16)b0, (u16)(i6 + 1), 0);
        func_0218F05C(obj);
        func_0218F878(obj);
        return 1;
    }
    if (w[2] != 0) {
        {
            Vec base = {0, 0, 0};
            b0 = w[0];
            if (func_02011688((struct IcaAnime *)(*(u32 *)(w + 0x714)), (struct Rec12 *)(&base), *(u16 *)(w + 0x718)) != 0) {
                base.x += (d_021F40F0[b0].a << 16) + 0x8000;
                base.y += d_021F40F0[b0].pad << 16;
                base.z += (d_021F40F0[b0].b << 16) + 0x8000;
                func_021A3044(func_02188CB4(ctx), &base);
            }
        }
        if (*(int *)(w + 0x724) != 0 && *(u16 *)(w + 0x718) < *(u16 *)(w + 0x71C)) {
            Vec end;
            Vec start;
            Six path;
            func_021A3038(func_02188CB4(ctx), (struct VecFx32 *)(&end));
            if (*(int *)(w + 0x728) == 0) {
                func_0218EC54(obj);
                func_0218ECE4(obj, &start);
                path.f = 1;
                path.e = 0;
                path.a = 0;
                path.b = 0;
                path.c = 0;
                path.d = 0;
                func_0218F930(obj, (u8 *)(&start), (u8 *)(&end), (u32 *)(&path), *(u16 *)(w + 0x71C) - *(u16 *)(w + 0x718));
                *(int *)(w + 0x728) = 1;
            } else {
                *(Vec *)(func_0218FE70(obj) + 0xC) = end;
            }
        }
        if (*(u16 *)(w + 0x718) == *(u16 *)(w + 0x71C)) {
            if (*(int *)(w + 0x720) != 0)
                *(int *)(w + 0x720) = 0;
            func_0218EC60((u32)obj);
            func_0218E13C(obj, (int)0);
            {
            Six fin;
            fin.a = 1;
            fin.b = 1;
            fin.c = 1;
            fin.d = 1;
            fin.e = 1;
            fin.f = 0;
            func_0218F9C4(obj, (u8 *)(&fin), *(u16 *)(w + 0x71E));
            }
            w[3] = 1;
        }
        row = w[0];
        idx = (u16)d_021F4320[row][func_021F3F44(w[1])].k;
        m2 = func_021A3074(func_02188CB4(ctx));
        if (*(u16 *)(w + 0x718) == *(u16 *)(w + 0x71A) - 1 - d_021F40B4[idx] && idx != 11) {
            func_0216D570(m2, (int)0x8000);
            func_020061E4(0x697);
        }
        if (idx == 11) {
            if (*(u16 *)(w + 0x718) == 0x46)
                func_020061E4(0x6A1);
            if (*(u16 *)(w + 0x718) + 8 >= *(u16 *)(w + 0x71A)) {
                if ((int)func_0216D57C(m2, (int)0x8000) != 0)
                    func_0216D570(m2, (int)0x8000);
            }
        }
        *(u16 *)(w + 0x718) += 1;
        if (*(u16 *)(w + 0x718) >= *(u16 *)(w + 0x71A))
            w[2] = 0;
        func_021F4000(w + 0x720, obj);
    }
    return 0;
}
