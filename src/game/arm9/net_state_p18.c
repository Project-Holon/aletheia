/*
 * file:     net_state_p18.c
 * unit:     yes
 * function: func_02037D78, func_02037D98
 * address:  0x02037D78
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02037478  0x02037478  arm
 *   g_021469D0     0x021469D0  data
 *   lbl_020A7A20    0x020A7A20  data
 *   lbl_021469D0    0x021469D0  data
 *   func_02038AE0   0x02038AE0  arm
 *   func_0203D6BC   0x0203D6BC  arm
 */
struct Conn;
struct Hdr;
typedef unsigned int u32;

typedef unsigned char u8;

struct S02037D98 {
    u32 f0;
    u8 pad04[0x1b0 - 4];
    int f1B0;
    u8 pad1B4[0x1d5 - 0x1b4];
    u8 f1D5;
};

typedef signed int     s32;

extern void func_02037478(void);
extern s32 func_02038AE0(struct Hdr *h, struct Conn *c, s32 len, u8 a3);
extern u32 func_0203D6BC(void);
void func_02037D78(void);
int func_02037D98(int a);
extern u32  g_021469D0;
extern u8 lbl_020A7A20[];
extern struct S02037D98 *lbl_021469D0;


/*
 * Teardown hook for the same global src/matched/func_02037BE8.c guards: the
 * armed pointer goes to func_02037478, an unarmed one is a `popeq`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037D78.c \
 *       --func func_02037D78 --addr 0x02037D78 --cc 1.1p1 --arm
 */
void func_02037D78(void)
{
    u32 v;

    v = g_021469D0;
    if (v == 0)
        return;
    func_02037478();
}


int func_02037D98(int a)
{
    int r = 0;
    if (lbl_020A7A20[1] != 4)
        return r;
    if (a != 0) {
        struct S02037D98 *p = lbl_021469D0;
        if (p->f1B0 > 0)
            return r;
        if (func_02038AE0((struct Hdr *)p->f0, (struct Conn *)((u32)p + 0xcc), func_0203D6BC(), p->f1D5) != 0) {
            struct S02037D98 *q = lbl_021469D0;
            q->f1D5++;
        }
        lbl_020A7A20[1] = 0;
        r = 1;
    } else {
        struct S02037D98 *p = lbl_021469D0;
        if (func_02038AE0((struct Hdr *)p->f0, (struct Conn *)((u32)p + 0xcc), func_0203D6BC(), p->f1D5) != 0) {
            struct S02037D98 *q = lbl_021469D0;
            q->f1D5++;
            lbl_020A7A20[1] = 0;
            r = 1;
        }
    }
    return r;
}
