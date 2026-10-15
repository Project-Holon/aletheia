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
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   MSG_SPEED_GetWait  0x02012FFC  thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
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
    extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
    extern void *func_02045EC0(struct MsgBank *bank, u32 index);
    extern signed char MSG_SPEED_GetWait(void);
    extern void *PRINTSYS_PrintStream(void *, unsigned, unsigned, void *, unsigned,
                               unsigned, unsigned, unsigned, unsigned, unsigned);
    extern void func_02040588(unsigned char which, unsigned char enable);

    if (w->f40 != 0) {
        func_02034714(d_021BABF8, 0, d_021BABF8);
    }
    GF_FONT_SetTextColor(1, 2, 0xf);
    w->f44 = func_02045EC0(x->f28, y);
    w->f40 = PRINTSYS_PrintStream(w->f3c, 0, 0, w->f44, x->fc, MSG_SPEED_GetWait(),
                           x->f18, 10, 0x61, 0xf);
    func_02040588(5, 1);
}
