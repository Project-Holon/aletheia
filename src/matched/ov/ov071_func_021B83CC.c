/*
 * function: func_021B83CC
 * address:  0x021B83CC
 * packet:   pkt_ov071_021B83CC
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_02040588  0x02040588  arm
 *   d_021BABF8     0x021BABF8  data  a1
 */

extern char d_021BABF8[];

typedef struct {
    char pad[0x3c];
    void *f3c;
    void *f40;
    void *f44;
} W;

typedef struct {
    char pad0[0xc];
    unsigned fc;
    char pad10[8];
    unsigned f18;
    char pad1c[0xc];
    void *f28;
} X;

typedef unsigned int   u32;
struct MsgBank;
void func_021B83CC(W *w, X *x, unsigned y)
{
    extern void func_02034714(const char *expr, u32 line, const char *file);
    extern void func_0201DD78(u32 r, u32 g, u32 b);
    extern void *func_02045EC0(struct MsgBank *bank, u32 index);
    extern signed char func_02012FFC(void);
    extern void *func_0201CCE4(void *, unsigned, unsigned, void *, unsigned,
                               unsigned, unsigned, unsigned, unsigned, unsigned);
    extern void func_02040588(u32 which, u32 enable);

    if (w->f40 != 0) {
        func_02034714(d_021BABF8, 0, d_021BABF8);
    }
    func_0201DD78(1, 2, 0xf);
    w->f44 = func_02045EC0(x->f28, y);
    w->f40 = func_0201CCE4(w->f3c, 0, 0, w->f44, x->fc, func_02012FFC(),
                           x->f18, 10, 0x61, 0xf);
    func_02040588(5, 1);
}
