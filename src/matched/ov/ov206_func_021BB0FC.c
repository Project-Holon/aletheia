/*
 * function: func_021BB0FC
 * address:  0x021BB0FC
 * packet:   pkt_ov206_021BB0FC
 * region:   ov206
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */

struct Descriptor;
extern void func_02045334(struct Descriptor *);
typedef unsigned char  u8;
struct Cfg;
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
typedef unsigned int   u32;
extern void func_02041B6C(u32 bit);

void func_021BB0FC(void *obj)
{
    int p;

    if (*(int *)((char *)obj + 8) != 0) {
        p = *(int *)((char *)obj + 0x8c);
        func_02045334((struct Descriptor *)p);
        func_02045374((struct Cfg *)p);
        func_02041B6C(func_02045730((struct Descriptor *)p));
        return;
    }
    p = *(int *)((char *)obj + 0x90);
    func_02045334((struct Descriptor *)p);
    func_02045374((struct Cfg *)p);
    func_02041B6C(func_02045730((struct Descriptor *)p));
}

