/*
 * function: func_021B989C
 * address:  0x021B989C
 * packet:   pkt_ov099_021B989C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C4AC4  0x021C4AC4  thumb  ov127
 *   func_021C5858  0x021C5858  thumb  ov127
 *   func_021C584C  0x021C584C  thumb  ov127
 *   func_021B9F90  0x021B9F90  thumb
 */
typedef struct {
    short x, y;
} Pos;

typedef struct {
    void *f0;
    void *f4;
} Rec;

extern Pos func_021C4AC4(void *v);
typedef unsigned char  u8;
extern int func_021C5858(u8 *p);
extern void func_021C584C(u8 *p, int a);
extern void func_021B9F90(void *o, Pos pos, int c);

void func_021B989C(void *o, Rec *r)
{
    Pos p = func_021C4AC4(r->f0);

    func_021B9F90(o, p, func_021C5858(r->f4) - 2);
    func_021C584C(r->f4, 0);
}
