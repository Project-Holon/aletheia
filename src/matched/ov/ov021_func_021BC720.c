/*
 * function: func_021BC720
 * address:  0x021BC720
 * packet:   pkt_ov021_021BC720
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct {
    char pad[0x24];
    void *f24;
} Obj;

typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);

void func_021BC720(Obj *p)
{
    func_02043B5C(func_02045770(p->f24), 3);
}
