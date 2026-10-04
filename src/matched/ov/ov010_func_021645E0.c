/*
 * function: func_021645E0
 * address:  0x021645E0
 * packet:   pkt_ov010_021645E0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Three-step wait state machine on *st; step 0 also counts frames in w[1].
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02012138  0x02012138  thumb
 *   func_0215870C  0x0215870C  thumb ov010
 *   func_02188C7C  0x02188C7C  thumb ov021
 *   func_02188BF8  0x02188BF8  thumb ov021
 *   func_02188CB4  0x02188CB4  thumb ov021
 *   func_021A2F54  0x021A2F54  thumb ov021
 *   func_021A34F8  0x021A34F8  thumb ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02012138(const struct Ctx *p);
extern int   func_0215870C(int a, int b);
extern void *func_02188C7C(u8 *p);
extern u32 func_02188BF8(u8 *a);
extern void *func_02188CB4(u8 *p);
extern int   func_021A2F54(u8 *p);
extern int   func_021A34F8(u8 *p);

int func_021645E0(void *unused, int *st, int *w)
{
    int r;
    u8 *h = func_0201210C((void *)w[0]);
    func_02188C7C(h);
    switch (*st) {
    case 0:
        r = func_02012138((const struct Ctx *)w[0]);
        w[1]++;
        if (func_0215870C(r, w[1]) == 1 && (u32)w[1] < 0x1e) {
            break;
        }
        func_02188BF8(h);
        (*st)++;
        /* fall through */
    case 1:
        if (func_021A2F54((u8 *)func_02188CB4(h)) == 1) {
            (*st)++;
        }
        break;
    case 2:
        if (func_021A34F8((u8 *)func_02188CB4(h)) == 1) {
            return 1;
        }
        break;
    }
    return 0;
}
