/*
 * function: func_021BB1C4
 * address:  0x021BB1C4
 * packet:   pkt_ov070_021BB1C4
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The work pointer must be struct-typed: with an int base and a cast
 * `*(int *)(p + 0x808)` the loop hoists the 0x808 pool offset into r7 and
 * rematerialises 0x3000 every pass; the struct field keeps the offset in the
 * load and lets 0x3000 take r7, as in the image. d declared before n puts d
 * in r2 and n in r3. func_02041090 takes u8 widths (its own file).
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_0204A380  0x0204A380  arm
 *   func_02062B30  0x02062B30  arm
 *   func_02041090  0x02041090  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02049238  0x02049238  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    u16 w;
    u16 h;
    u16 pad[4];
    u16 d[1];
} Img;

typedef struct {
    u8 pad0[0x544];
    u16 f544;
    u8 pad1[0x808 - 0x546];
    int f808;
} Work;

extern int func_020490F4(int, unsigned);
extern int func_0204A380(int, int, int, unsigned);
extern int func_02062B30(int, Img **);
extern void func_02041090(unsigned, void *, unsigned, unsigned, u8, u8);
extern void func_02041B6C(int);
extern void func_020307B0(int);
extern void func_02049238(int);

void func_021BB1C4(Work *p)
{
    int arc;
    int tex;
    Img *img;
    int i;
    u16 *d;
    int n;

    arc = func_020490F4(0x58, p->f544);
    tex = func_0204A380(arc, 0x23, 0, p->f544);
    i = 0;
    if (func_02062B30(tex, &img)) {
        d = img->d;
        n = ((unsigned)img->w >> 3) * ((unsigned)img->h >> 3);
        for (; i < n; i++) {
            d[i] += (u16)((u16)p->f808 | 0x3000);
        }
        func_02041090(3, img->d, 0x10, 0xC, (unsigned)img->w >> 3, (unsigned)img->h >> 3);
        func_02041B6C(3);
    }
    func_020307B0(tex);
    func_02049238(arc);
}
