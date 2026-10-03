/*
 * function: func_0217C37C
 * address:  0x0217C37C
 * packet:   pkt_ov018_0217C37C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02166618  0x02166618  thumb  ov010
 *   func_02166640  0x02166640  thumb  ov010
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0217C1D0  0x0217C1D0  thumb  ov018
 *   func_0202A128  0x0202A128  thumb
 *   func_0202A170  0x0202A170  thumb
 *   func_02005728  0x02005728  thumb
 *   d_02183678     0x02183678  data  a4
 *   d_021835F8     0x021835F8  data  a4
 *   d_02183650     0x02183650  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 species : 11;
    u32 move : 10;
    u32 f21 : 2;
    u32 f23 : 6;
    u32 f29 : 3;
} Entry;

typedef struct {
    int f0;
    int f4;
    int f8;
} Ctx;

extern const u8 d_02183678[20][2];
extern const u8 d_021835F8[20][2];
extern const u8 d_02183650[20][2];

extern int func_02166618(int);
extern int func_02166640(int);
extern int func_02188C84(int);
extern void *func_02188CB4(unsigned char *p);
extern void *func_021A3074(unsigned char *p);
extern int func_0216D83C(void *);
extern int func_0216D86C(void *);
extern int func_0202A128(int);
extern void func_0202A170(int);
extern u32 func_02005728(u32 range);
extern void func_0217C1D0(Ctx *, Entry *, u16, u16, u16, int);

void func_0217C37C(int a0, int a1, Entry *list, int a3, int kind)
{
    const u8 (*tbl)[2];
    Ctx ctx;
    void *obj;
    u16 cx;
    u16 cy;
    int i;
    int dx;
    int dy;
    int x;
    int y;

    if (func_02166618(kind))
        tbl = d_02183678;
    else if (func_02166640(kind))
        tbl = d_021835F8;
    else
        tbl = d_02183650;

    ctx.f0 = func_0202A128(func_02188C84(a0));
    ctx.f4 = a0;
    ctx.f8 = a1;
    obj = func_021A3074(func_02188CB4((void *)a0));
    cx = func_0216D83C(obj);
    cy = func_0216D86C(obj);

    for (i = 0; i < 20; i++) {
        if (list[i].species != 0) {
            dx = func_02005728(2) - 1;
            dy = func_02005728(2) - 1;
            x = dx + tbl[i][0];
            y = dy + tbl[i][1];
            if (cx == x && cy == y) {
                if (dx != 0)
                    x -= dx;
                else if (dy != 0)
                    y -= dy;
                else
                    x++;
            }
            func_0217C1D0(&ctx, &list[i], i, x, y, 0);
        }
    }
    func_0202A170(ctx.f0);
}
