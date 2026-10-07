/*
 * file:     compatible_irc_sys_p10.c
 * unit:     yes
 * function: func_021B6ECC, func_021B6F9C, func_021B7090, func_021B70A8
 * address:  0x021B6ECC
 * region:   ov101
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 *   func_020084F4 0x020084F4 thumb
 *   _ffltu 0x0209BE04 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_02045A98 0x02045A98 arm
 *   func_0200AA00 0x0200AA00 thumb
 */
typedef unsigned int u32;

typedef unsigned short u16;

struct Date { unsigned a,b,c,d; };

extern u16 *func_020084F4(void *);
extern u16 func_02045A98(void);
extern unsigned char func_0200AA00(unsigned,unsigned,struct Date *);
int func_021B6ECC(u32 a, u32 b, int c, int d, char *x, char *y, int flag, u32 id, int a8);
u32 func_021B6F9C(u16 *p, u16 *q);
unsigned func_021B7090(unsigned bits, unsigned n);
unsigned char func_021B70A8(unsigned char *p,unsigned x);

int func_021B6ECC(u32 a, u32 b, int c, int d, char *x, char *y, int flag, u32 id, int a8)
{
    int base, rate, result;
    u32 sim;
    u16 *first;
    float f;
    base = ((((u32)func_021B70A8((unsigned char *)x, id) + (u32)func_021B70A8((unsigned char *)y, id)) >> 1) * 10) / 100;
    a = a * 50 / 100;
    b = b * 40 / 100;
    base += a + b;
    first = func_020084F4(x + 12);
    sim = func_021B6F9C(first, func_020084F4(y + 12));
    if (sim) f = 0.5f + (float)(sim << 12);
    else f = (float)(sim << 12) - 0.5f;
    rate = (int)f / 150;
    if (flag) rate = 0xccd;
    else {
        if (rate > 0x1000) rate = 0x1000;
        else if (rate < 0x800) rate = 0x800;
    }
    result = base + (((100 - base) * rate) >> 12) - (d + c);
    if (result > 100) return 100;
    if (result < 0) result = 0;
    return result;
}

/*
 * lever: equal declared before count fixes the two spilled counter slots; literal double assignments reproduce the lower-bound stores.
 * note 2026-10-05 (wave D9r lane 131): removed the 2 dead first assignments
 * (`lower1 = 0x30f4;` before `lower1 = 0x30a1;`; `lower2 = 0x30f4;` before
 * `lower2 = 0x30a1;`). Game code has no line table, so these were stand-ins.
 * The plain single assignment gives EXACT in --lang c99 and --lang c: the
 * output bytes do not change. Older text in this header that asks for the
 * double assignment is superseded.
 */
u32 func_021B6F9C(u16 *p, u16 *q)
{
    u32 a, b, bits1, bits2;
    u32 equal, count, lower1, lower2;
    a = *p;
    b = *q;
    if (a >= 0x30a1 && a <= 0x30f4) a -= 0x60;
    if (b >= 0x30a1 && b <= 0x30f4) b -= 0x60;
    bits1 = func_021B7090(a, 8);
    bits2 = func_021B7090(b, 8);
    count = 0;
    equal = 0;
    lower1 = 0x30a1;
    lower2 = 0x30a1;
    for (;;) {
        if (bits1 == 0) {
            a = *++p;
            if (a == func_02045A98()) break;
            if (a >= lower1 && a <= 0x30f4) a -= 0x60;
            bits1 = func_021B7090(a, 8);
        }
        if (bits2 == 0) {
            b = *++q;
            if (b == func_02045A98()) break;
            if (b >= lower2 && b <= 0x30f4) b -= 0x60;
            bits2 = func_021B7090(b, 8);
        }
        if (bits1 == 0 || bits2 == 0) continue;
        if (((a >> bits1) & 1) == ((b >> bits2) & 1)) ++equal;
        ++count;
        --bits1;
        --bits2;
    }
    return equal * 100 / count;
}

unsigned func_021B7090(unsigned bits, unsigned n) { unsigned i = n - 1; while (i) { if ((bits >> i) & 1) break; i--; } return i; }

unsigned char func_021B70A8(unsigned char *p,unsigned x) { struct Date d; d.a=(unsigned char)(x>>24); d.b=(unsigned char)(x>>16); d.c=(unsigned char)(x>>8); d.d=(unsigned char)x; return func_0200AA00(p[4],p[5],&d); }
