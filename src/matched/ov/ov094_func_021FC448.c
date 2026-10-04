/*
 * function: func_021FC448
 * address:  0x021FC448
 * packet:   pkt_ov094_021FC448
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script reset: frees slot objects and buffers, restores display state, then resumes the
 * pending script at 0x1ec or reloads script 0x34 when the follow-up conditions hold.
 *
 * symbols:
 *   func_021FDB08 0x021FDB08 thumb ov094
 *   func_021F86F0 0x021F86F0 thumb ov094
 *   func_02201CA4 0x02201CA4 thumb ov094
 *   func_020307B0 0x020307B0 arm
 *   func_021F8A10 0x021F8A10 thumb ov094
 *   func_021FE4F8 0x021FE4F8 thumb ov094
 *   func_021FE520 0x021FE520 thumb ov094
 *   func_021F8934 0x021F8934 thumb ov094
 *   func_02011290 0x02011290 thumb
 *   func_021F8764 0x021F8764 thumb ov094
 *   func_021EB2A8 0x021EB2A8 thumb ov093
 *   func_0204047C 0x0204047C arm
 *   func_02040618 0x02040618 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_02006210 0x02006210 thumb
 *   func_021F8694 0x021F8694 thumb ov094
 *   func_021FFD9C 0x021FFD9C thumb ov094
 *   func_021FFF38 0x021FFF38 thumb ov094
 *   func_02040588 0x02040588 arm
 *   func_0201127C 0x0201127C thumb
 *   func_02048F60 0x02048F60 arm
 *   func_021FF374 0x021FF374 thumb ov094
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef union {
    unsigned word;
    struct {
        unsigned gap0 : 4;
        unsigned b4 : 1;
        unsigned b5 : 1;
        unsigned b6 : 1;
        unsigned gap7 : 5;
        unsigned b12 : 1;
        unsigned gap13 : 4;
        unsigned b17 : 1;
        unsigned b18 : 1;
    } bit;
} Flags;
typedef struct {
    Flags flags;
    int f4;
    int pad8;
    void *objects[16];
    int ids[16];
    char pad8c[0xcc - 0x8c];
    int res[4];
    int fdc;
    char pade0[0x1e8 - 0xe0];
    char *f1e8;
    char *f1ec;
    int f1f0;
    void *bufs[16];
    int nbufs;
    u16 h238;
    char pad23a[2];
    int f23c;
    char pad240[0x249 - 0x240];
    u8 b249;
    char pad24a[0x258 - 0x24a];
    u16 h258;
    char pad25a[0x264 - 0x25a];
    int f264;
    int f268;
} State;

extern void func_021FDB08(void *);
extern int func_021F86F0(void);
typedef unsigned int   u32;
struct Res;
struct ScriptVm;
extern void func_02201CA4(struct Res *r, int i);
extern void func_020307B0(void *);
extern void func_021F8A10(int);
extern void func_021FE4F8(State *);
extern void func_021FE520(State *);
extern void func_021F8934(int);
extern void func_02011290(struct ScriptVm *vm);
extern int func_021F8764(void);
extern void func_021EB2A8(const u8 *a);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_0207D63C(int, int, int, int, int);
extern void func_02006210(void);
extern int func_021F8694(void);
extern int func_021FFD9C(char *p, int key);
extern int func_021FFF38(char *p, int key);
extern void func_02040588(u32 which, u32 enable);
extern void func_0201127C(void *, char *);
extern void func_021FF374(void *, int, int);
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);

int func_021FC448(void *a, State *s)
{
    int i;
    int v;
    u16 id;
    u16 id2;
    int b;
    int off;
    char *p;
    void *q;

    for (i = 0; i < 16; i++) {
        if (s->objects[i] != 0) {
            func_021FDB08(s->objects[i]);
            s->objects[i] = 0;
        }
        s->ids[i] = -1;
    }
    for (i = 0; i < 4; i++) {
        if (s->res[i] != -1) {
            func_02201CA4((struct Res *)func_021F86F0(), s->res[i]);
            s->res[i] = -1;
        }
    }
    for (i = 0; i < s->nbufs; i++)
        func_020307B0(s->bufs[i]);
    s->nbufs = 0;
    func_021F8A10(1);
    func_021FE4F8(s);
    func_021FE520(s);
    if (s->flags.bit.b18 == 0)
        func_021F8934(1);
    func_02011290(a);
    s->f23c = 1;
    if (s->flags.bit.b4) {
        q = (void *)func_021F8764();
        if (q != 0)
            func_021EB2A8(q);
        func_0204047C(3, 0);
        s->flags.bit.b4 = 0;
        func_02040618(3, 0, s->f264);
        func_02040618(3, 3, s->f268);
    }
    if (s->flags.bit.b5) {
        func_0207D63C(0x04000050, 2, 0x3d, 0x1f, 7);
        s->flags.bit.b5 = 0;
    }
    if (s->flags.bit.b12)
        func_02006210();
    v = 0;
    if (func_021FFD9C((char *)func_021F8694(), s->fdc) != 0) {
        id = s->h258;
        if (((id == 0xf8 || id == 0x161) && s->b249 == 1) || id == 0x90 || id == 0x77 || id == 0x10b) {
        } else {
            v = func_021FFF38((char *)func_021F8694(), s->fdc) & 1;
        }
    }
    if (s->f1ec != 0) {
        func_020307B0(s->f1e8);
        p = s->f1ec;
        s->f1e8 = p;
        s->f1ec = 0;
        s->flags.bit.b6 = 0;
        off = s->f1f0;
        func_02040588(1, 0);
        func_02040588(2, 0);
        func_02040588(3, 0);
        s->f4 = 0;
        func_0201127C(a, s->f1e8 + *(int *)(p + off));
        return 1;
    }
    b = s->flags.bit.b17;
    if (b == 1 && s->h258 == 0x291) {
        func_020307B0(s->f1e8);
        s->h258 = 0x34;
        p = func_02048F60(0x43, s->h258, (u16)((s->h238 & 0x7fff) | 0x8000));
        s->f1e8 = p;
        s->flags.bit.b6 = 1;
        s->f4 = 0;
        s->flags.bit.b17 = 0;
        func_0201127C(a, p + *(int *)(p + 4));
        return 1;
    }
    id2 = s->h258;
    if ((id2 == 0x286 || s->flags.bit.b6 == 0) && id2 != 0x90 && id2 != 0xe2 && b == 0 && v != 0) {
        if (id2 == 0x1f6)
            func_021FF374((void *)func_021F8694(), s->fdc, 0);
        func_020307B0(s->f1e8);
        s->h258 = 0x34;
        p = func_02048F60(0x43, s->h258, (u16)((s->h238 & 0x7fff) | 0x8000));
        s->f1e8 = p;
        s->flags.bit.b6 = 1;
        s->f4 = 0;
        s->flags.bit.b17 = 0;
        func_0201127C(a, p + *(int *)(p + 4));
        return 1;
    }
    if (id2 != 0x27e) {
        func_02040588(1, 1);
        func_02040588(2, 1);
        func_02040588(3, 1);
    }
    return 1;
}
