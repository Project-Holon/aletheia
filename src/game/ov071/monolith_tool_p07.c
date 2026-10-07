/*
 * file:     monolith_tool_p07.c
 * unit:     yes
 * function: func_021B79A0, func_021B7A08, func_021B7A14, func_021B7A68
 * address:  0x021B79A0
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_02040588  0x02040588  arm
 *   d_021BABF4     0x021BABF4  data  a1
 *   func_02028484  0x02028484  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02045808  0x02045808  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_021B6F40  0x021B6F40  thumb  ov071
 *   func_021B6F54  0x021B6F54  thumb  ov071
 *   d_021BAA4C     0x021BAA4C  data  a4
 *   d_021BA8A0     0x021BA8A0  data  a4
 */
struct MsgBank;
struct Blk;
struct CharBuf;
struct Descriptor;
struct Rec3;
struct U16Vec;
struct P;
typedef unsigned int u32;

typedef signed int     s32;

typedef unsigned char  u8;

typedef struct {
    int pad[3];
    int v[6];
} S;

extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_0201DD78(u32, u32, u32);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *a0, u32 a1, u32 a2, void *a3, u32 a4, u32 a5, void *a6, u32 a7, u32 a8, u32 a9);
extern void func_02040588(unsigned char which, unsigned char enable);
extern s32 func_02028484(struct Blk *blk, void *h);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
void func_021B79A0(void **p, int *c, int idx);
int func_021B7A08(char *p, char *q);
void func_021B7A14(void **p);
void func_021B7A68(S *a, int *b);
extern char d_021BABF4[];
extern const unsigned d_021BAA4C[];
extern const char d_021BA8A0[];


void func_021B79A0(void **p, int *c, int idx)
{
    if (p[2] != 0)
        func_02034714(d_021BABF4, 0, d_021BABF4);
    func_0201DD78(1, 2, 15);
    p[1] = func_02045EC0((void *)c[0x28 / 4], idx);
    p[2] = func_0201CCE4(p[0], 0, 0, p[1], c[0xc / 4], func_02012FFC(), (void *)c[0x18 / 4], 10, 0x61, 15);
    func_02040588(5, 1);
}

int func_021B7A08(char *p, char *q) { return func_02028484((struct Blk *)(p + 0x38), (void *)(*(int *)(q + 8))); }


void func_021B7A14(void **p)
{
    void *h;

    h = func_02045770(p[0]);
    if (p[2] == 0)
        func_02034714(d_021BABF4, 0, d_021BABF4);
    func_0201CE48(p[2]);
    p[2] = 0;
    func_02045808(p[1]);
    p[1] = 0;
    func_02040588(5, 0);
    func_02043B5C(h, 0xff);
    func_02045334(p[0]);
    func_0201DD78(15, 2, 0);
}

void func_021B7A68(S *a, int *b)
{
    void *func_021B6F40(u8 **p);
    int func_021B6F54(struct P *p, u8 *q, int c, const int *d, int e);
    int i;
    int t = (int)func_021B6F40((u8 **)b);

    for (i = 0; i < 6; i++) {
        int r;
        unsigned u = d_021BAA4C[i];
        r = func_021B6F54((struct P *)b[1], (u8 *)t, i, (const int *)(d_021BA8A0 + u * 8), 1);
        a->v[i] = r;
    }
}
