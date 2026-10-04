/*
 * function: func_021BD96C
 * address:  0x021BD96C
 * packet:   pkt_ov021_021BD96C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct {
    char pad[4];
    void *f4;
    char pad2[0x44];
    int f4C;
} Inner;

typedef struct {
    char pad[8];
    Inner *f8;
} Obj;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Evt;
extern u8 *func_0202952C(u8 *p, u32 a);
extern void func_02012374(struct Evt *evt, struct Evt **out);

void func_021BD96C(Obj *p, void *b)
{
    Inner *q = p->f8;

    func_02012374(b, (struct Evt **)func_0202952C(q->f4, 0x1E));
    q->f4C = 1;
}
