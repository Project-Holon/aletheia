/*
 * function: func_021EB324
 * address:  0x021EB324
 * packet:   pkt_ov170_021EB324
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EABB8 0x021EABB8 thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021EAAE4 0x021EAAE4 thumb
 */

typedef struct {
    void *obj;
    int pad;
} Item;

typedef struct {
    unsigned char pad[0x94];
    Item items[14];
} Work;

extern void func_021EABB8(void **p);
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021EAAE4(unsigned char *p, unsigned i);

void func_021EB324(Work *w)
{
    unsigned i;
    for (i = 1; i <= 9; i++) {
        func_021EABB8((void **)(&w->items[i]));
        func_02043B5C(func_02045770(w->items[i].obj), 0);
        func_021EAAE4((unsigned char *)w, i);
    }
    func_021EABB8((void **)(&w->items[10]));
    func_021EABB8((void **)(&w->items[11]));
    func_021EABB8((void **)(&w->items[12]));
    func_021EABB8((void **)(&w->items[13]));
}
