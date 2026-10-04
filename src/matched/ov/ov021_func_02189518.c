/*
 * function: func_02189518
 * address:  0x02189518
 * packet:   pkt_ov021_02189518
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012134  0x02012134  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012B28  0x02012B28  thumb
 *   func_0202B544  0x0202B544  thumb
 *   func_02029CF0  0x02029CF0  thumb
 */

typedef unsigned short u16;

typedef unsigned int   u32;
struct Ctx;
struct Rec44;
struct SaveBlock;
struct BigObj;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012134(void *p);
extern u32 func_02012A30(const struct BigObj *p);
extern void *func_020127A4(struct SaveBlock *p);
extern u32 func_02012B28(const struct Rec44 *p);
extern void func_0202B544(void *a, u16 b);
extern void func_02029CF0(void *a, void *b, u16 c);

void func_02189518(char *p, unsigned int idx)
{
    void *a;
    void *b;
    void *c;
    int k;

    a = func_020120F4(*(void **)(p + 4));
    b = func_02012134(*(void **)(p + 4));
    c = (void *)func_02012A30(a);
    k = func_02012B28(func_020127A4(a));
    func_0202B544(b, idx);
    if (k != 2)
        func_02029CF0(c, a, idx);
}
