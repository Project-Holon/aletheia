/*
 * function: func_021BDC0C
 * address:  0x021BDC0C
 * packet:   pkt_ov021_021BDC0C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct {
    int pad0;
    void *f4;
    void *f8;
} Inner;

typedef struct {
    Inner *f0;
} Obj;

typedef unsigned int   u32;
struct BigObj;
extern u32 func_02012A30(const struct BigObj *p);
typedef unsigned char  u8;
struct Evt;
extern u8 *func_020294C0(u8 *p, u32 a);
extern void func_02012374(struct Evt *evt, struct Evt **out);

void func_021BDC0C(Obj *p, void *b)
{
    Inner *q = p->f0;
    void *r = q->f4;

    func_02012A30(q->f8);
    func_02012374(b, (struct Evt **)func_020294C0(r, 6));
}
