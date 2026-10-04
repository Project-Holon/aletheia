/*
 * function: func_021B629C
 * address:  0x021B629C
 * packet:   pkt_ov067_021B629C
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B294  0x0204B294  arm
 *   func_0204B878  0x0204B878  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    u16 x;
    u16 y;
    u16 w;
    u16 h;
} Rect;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
} P;

struct Obj;
extern struct Obj *func_0204B294(void *a, unsigned int b, unsigned int c, unsigned int d, const void *r, u16 e, u16 f);
extern void func_0204B878(int h, u8 e);

int func_021B629C(P *p, int a, u16 x, u16 y, u8 e, u16 f)
{
    Rect rc = {0, 0, 0, 0};
    int r;

    rc.x = x;
    rc.y = y;
    r = (int)func_0204B294((void *)a, p->f0, p->f4, p->f8, &rc, (u16)p->fC, f);
    func_0204B878(r, e);
    return r;
}
