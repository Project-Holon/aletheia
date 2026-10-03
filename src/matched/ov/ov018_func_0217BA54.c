/*
 * function: func_0217BA54
 * address:  0x0217BA54
 * packet:   pkt_ov018_0217BA54
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02012204  0x02012204  thumb
 *   func_02035390  0x02035390  arm
 *   func_020353B0  0x020353B0  arm
 *   func_02030734  0x02030734  arm
 *   func_020263D8  0x020263D8  thumb
 *   d_02183AE0     0x02183AE0  data   a1
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int f00;
    int f04;
    int pad;
    u16 pad2;
    u8 f0e;
} Rec;

typedef unsigned int   u32;
struct Ctx;
extern u32 func_02012138(const struct Ctx *p);
extern u32 func_0200FB24(void);
extern u32 func_02012204(const struct Ctx *p);
extern int func_02035390(void);
extern int func_020353B0(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020263D8(int, int, void *);
extern const char d_02183AE0[];

void func_0217BA54(void *a)
{
    int h;
    Rec *r;

    h = func_02012138(a);
    if (func_0200FB24() != 0)
        return;
    if (func_02012204(a) == 1)
        return;
    if (func_02035390() == 1 && func_020353B0() == 1)
        return;
    r = func_02030734(0x8005, 0x10, 1, d_02183AE0, 0x528);
    r->f0e = 1;
    r->f00 = (int)a;
    r->f04 = h;
    func_020263D8(h, 2, r);
}
