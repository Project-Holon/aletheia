/*
 * function: func_021EEEE0
 * address:  0x021EEEE0
 * packet:   pkt_ov025_021EEEE0
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021A244C 0x021A244C thumb ov021
 *   func_021A2564 0x021A2564 thumb ov021
 *   func_021A2190 0x021A2190 thumb ov021
 *   func_021A21A0 0x021A21A0 thumb ov021
 *   _s32_div_f    0x0209C0A4 arm
 *   _u32_div_f    0x0209C2B0 arm
 *   d_021EF765    0x021EF765 data a1
 *   d_021EF75C    0x021EF75C data ov025 a1
 *
 * The remainder goes back into t before the store (`t = (t+1) % 252u;
 * s[8] = t;`): storing the expression directly lets the compiler sink
 * `i = t / 28` below the _u32_div_f call. `const` on the two s8 tables
 * schedules the second table's pool load above the s[2] store.
 */

typedef signed char s8;

typedef signed int     s32;
typedef unsigned char  u8;
extern void func_021A244C(u8 *o, s32 *outX, s32 *outY);
extern void func_021A2564(int, int, int);
extern void func_021A2190(unsigned char *o, unsigned int v, int i);
extern void func_021A21A0(unsigned char *o, unsigned int v, int i);
extern const s8 d_021EF765[];
extern const s8 d_021EF75C[];

void func_021EEEE0(int a, int *s)
{
    int w;
    int h;
    int i;
    int t;

    func_021A244C((u8 *)a, &w, &h);
    func_021A2564(a, w, h);
    t = s[8];
    i = t / 28;
    t = (unsigned)(t + 1) % 252u;
    s[8] = t;
    s[2] = s[2] + d_021EF765[i] - w / 2;
    s[9] = s[9] + d_021EF75C[i] - h / 2;
    if (s[2] < 0) {
        s[2] = s[2] + 256;
    }
    if (s[9] < 0) {
        s[9] = s[9] + 256;
    }
    s[2] = s[2] % 256;
    s[9] = s[9] % 256;
    func_021A2190((unsigned char *)a, -s[2], 0);
    func_021A21A0((unsigned char *)a, -s[9], 0);
}
