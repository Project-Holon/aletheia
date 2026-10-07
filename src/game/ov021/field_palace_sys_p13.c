/*
 * file:     field_palace_sys_p13.c
 * unit:     yes
 * function: func_021D3270, func_021D3288, func_021D3294
 * address:  0x021D3270
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned short u16;

typedef struct {
    u16 f0;
    u16 pad2;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
} Rec_021D3270;

typedef struct {
    u16 f0;
    u16 pad2;
    int f4;
    int f8;
} Rec_021D3288;

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { u8 p0[2]; u16 t; u8 p1[0x14]; u32 a, b, c, d; } S;

void func_021D3270(Rec_021D3270 *p, int a, int b, int c, int d, int e);
void func_021D3288(Rec_021D3288 *p, int a, int b);
void func_021D3294(S *p, u32 a, u32 b, u32 c, u32 d);


/*
 * Addresses are Black-image addresses.
 */
void func_021D3270(Rec_021D3270 *p, int a, int b, int c, int d, int e)
{
    p->f0 = 4;
    p->f4 = a;
    p->f8 = b;
    p->fC = c;
    p->f10 = d;
    p->f14 = e;
}


/*
 * Unlabelled 10-byte leaf (movs/strh/str/str/bx lr) between labelled code;
 * called from func_021C622C.
 */
void func_021D3288(Rec_021D3288 *p, int a, int b)
{
    p->f0 = 5;
    p->f4 = a;
    p->f8 = b;
}


/*
 * Unlabelled Thumb leaf (a .word in ov021.s), blocker of ov032 func_021F0208.
 * Storing the u16 tag first is what makes the compiler save r3/r4 and keep
 * the constant in r4; the plain-pointer spelling gave a shorter body.
 */
void func_021D3294(S *p, u32 a, u32 b, u32 c, u32 d)
{
    p->t = 2;
    p->a = a;
    p->b = b;
    p->c = c;
    p->d = d;
}
