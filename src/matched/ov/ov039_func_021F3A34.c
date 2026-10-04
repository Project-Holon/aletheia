/*
 * function: func_021F3A34
 * address:  0x021F3A34
 * packet:   pkt_ov039_021F3A34
 * region:   ov039
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     spill slots follow reverse declaration order (last declared, lowest
 *           slot): d, v, qr, j2, sr, b, a gives a 8, b 0xc, sr 0x10, j2 0x14, qr 0x18,
 *           v 0x1c, d 0x20. The row pointers qr (q + j) and sr (s + j) and j2 = 2 * j
 *           are named locals so they take their declared places, and `b = v + 1`
 *           keeps v a real variable (with `b = s->cur[j] + 1` a CSE temporary
 *           takes the first slot instead). d_021F4C28 and d_021F4D54 need the ov039 token.
 *
 * symbols:
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021897BC 0x021897BC thumb
 *   func_02188C80 0x02188C80 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_02012A30 0x02012A30 thumb
 *   func_021F3DE4 0x021F3DE4 thumb ov039
 *   func_021F47D8 0x021F47D8 thumb ov039
 *   func_02011558 0x02011558 thumb
 *   func_02011428 0x02011428 thumb
 *   func_021BE674 0x021BE674 thumb ov021
 *   func_021BE6B0 0x021BE6B0 thumb ov021
 *   func_02028A7C 0x02028A7C thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_02006148 0x02006148 thumb
 *   func_02028B18 0x02028B18 thumb
 *   func_02006138 0x02006138 thumb
 *   func_02072F34 0x02072F34 arm
 *   func_021BE6E8 0x021BE6E8 thumb ov021
 *   func_021F4864 0x021F4864 thumb ov039
 *   func_02028B50 0x02028B50 thumb
 *   func_02006210 0x02006210 thumb
 *   func_02011688 0x02011688 thumb
 *   func_02188CB4 0x02188CB4 thumb ov021
 *   func_021A3044 0x021A3044 thumb ov021
 *   func_021F4A18 0x021F4A18 thumb ov039
 *   d_021F4C38    0x021F4C38 data a4
 *   d_021F4C28    0x021F4C28 data ov039 a1
 *   d_021F4D54    0x021F4D54 data ov039 a4
 *   d_021F4CA0    0x021F4CA0 data a4
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int x, y, z;
} Vec;

typedef struct {
    u8 pad0[4];
    u8 sel;
    u8 pad5[2];
    s8 hold;
    int timer[4];
    u32 anim;
    u8 f1c[0x21E4 - 0x1C];
    int active;
    u8 req[4];
    u8 cur[4];
    s8 slot[4];
} Work;

typedef struct {
    u8 pad0[0x10];
    u8 flag[8];
} Save;

extern int func_02188D2C(int *p);
extern Work *func_021897BC(void *p, int idx);
extern u32 func_02188C80(void *p);
struct Big;
struct Ctx;
struct IcaAnime;
struct SoundSys2;
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern Save *func_0200B3A4(unsigned int, unsigned int);
struct BigObj;
extern u32 func_02012A30(const struct BigObj *a);
extern int func_021F3DE4(int a, u8 b, u8 c);
extern void func_021F47D8(void *a, int f, int i);
extern void func_02011558(struct IcaAnime *p);
extern u32 func_02011428(u32 heap, u32 a1, u16 a2, void *a3, u32 a4);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern void func_021BE6B0(unsigned char *p, int v);
extern void func_02028A7C(struct SoundSys2 *s, u32 id);
extern void func_020061E4(u32 a);
extern int func_02006148(u32 a);
extern void func_02028B18(struct SoundSys2 *s, u32 id, u32 who);
extern u32 *func_02006138(int i);
extern void func_02072F34(void *o, u8 v);
extern int func_021BE6E8(int p, int i, u8 j, u8 k);
extern int func_021F4864(u32 a, u32 b, u8 *out);
extern void func_02028B50(u8 *p, int a0);
extern void func_02006210(void);
extern u32 func_02011688(u32 p, Vec *dst, u32 idx);
extern void *func_02188CB4(u8 *p);
extern void func_021A3044(void *q, Vec *v);
extern void func_021F4A18(void *a, Work *s);

extern u32 d_021F4C38[];
extern s8 d_021F4C28[][2];
extern Vec d_021F4D54;
extern Vec d_021F4CA0[];

void func_021F3A34(int a0, void *a1)
{
    u8 i;
    int j;
    int h;
    Work *s;
    u32 t;
    Save *q;
    int w;
    int d;
    u8 v;
    u8 *qr;
    int j2;
    s8 *sr;
    u8 b;
    u8 a;
    void *o;
    int snd;
    u8 k;
    Vec pos;
    u8 buf[4];
    u32 tmp2;

    h = func_02188D2C(a1);
    s = func_021897BC(a1, 1);
    t = (u32)func_020120F4((const struct Ctx *)func_02188C80(a1));
    q = func_0200B3A4((unsigned int)func_02012EC4((struct Big *)t), 2);
    w = func_02012A30((const struct BigObj *)t);
    for (i = 0; i < 4; i++) {
        j = i;
        if (s->req[j] != 0) {
            qr = (u8 *)q + j;
            d = (u8)((qr[0x10] + 1) % 2);
            j2 = j * 2;
            if (func_021F3DE4(h, j, d + (j2 + 1)) == 0) {
                func_021F47D8((void *)h, d, j);
                tmp2 = qr[0x10];
                s->cur[j] = j2 + tmp2;
                if (s->sel != 0xff && ((u32)s->sel >> 1) == j && s->sel != s->cur[j]) {
                    s->sel = s->cur[j];
                    func_02011558((struct IcaAnime *)s->anim);
                    s->anim = func_02011428(0x8015, 0x6b, d_021F4C38[s->sel], s->f1c, 0x21C0);
                }
                s->req[j] = 0;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        j = i;
        sr = (s8 *)s + j;
        v = s->cur[j];
        b = v + 1;
        a = j;
        o = func_021BE674((char *)h, 0, a, b);
        if (s->timer[j] != 0) {
            if (s->hold != j && --s->timer[j] == 0) {
                func_021BE6B0(o, 0);
                if (s->sel != 0xff && j == ((u32)s->sel >> 1)) {
                    func_02028A7C((struct SoundSys2 *)w, 0x68A);
                    func_020061E4(0x6DB);
                    snd = func_02006148(0x6DB);
                    func_02028B18((struct SoundSys2 *)w, 0x68A, 0x7f);
                    func_02072F34(func_02006138(snd), 0);
                }
                sr[0x21F0] = -1;
            }
        } else if (func_021F4864(v, func_021BE6E8(h, 0, a, b), buf)) {
            func_021BE6B0(o, 1);
            if (s->sel != 0xff && j == ((u32)s->sel >> 1)) {
                func_02028B50((u8 *)w, 0x68A);
                func_02006210();
            }
            s->timer[j] = 0x5a;
            sr[0x21F0] = d_021F4C28[v][buf[0]];
        }
    }
    if (s->active != 0) {
        pos = d_021F4D54;
        k = s->sel >> 1;
        if (func_02011688(s->anim, &pos, func_021BE6E8(h, 0, k, s->sel + 1) / 4096)) {
            pos.x += d_021F4CA0[k].x;
            pos.y += d_021F4CA0[k].y;
            pos.z += d_021F4CA0[k].z;
            func_021A3044(func_02188CB4((void *)a1), &pos);
        }
    } else {
        func_021F4A18(a1, s);
    }
}
