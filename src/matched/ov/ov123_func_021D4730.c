/*
 * function: func_021D4730
 * address: 0x021D4730
 * packet: pkt_ov123_021D4730
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero padding at 0x021D4776; next function starts 0x021D4778.
 * symbols:
 *   func_02051C6C 0x02051C6C arm
 *   func_020456F8 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020452E8 0x020452E8 arm
 */
extern void func_02051C6C(void *);
typedef unsigned int   u32;
struct Descriptor;
extern void func_020456F8(struct Descriptor *d);
extern void func_02041B6C(u32 bit);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_020452E8(struct Descriptor *d);
typedef struct {
    char pad00[0x10];
    void *f10[4];
    void *f20;
    char pad24[0x238];
    int f25c;
} Object;
void func_021D4730(Object *p)
{
    int i;
    if (p->f20)
        func_02051C6C(p->f20);
    p->f20 = 0;
    for (i = 0; i < 4; i++) {
        if (p->f10[i]) {
            func_020456F8(p->f10[i]);
            func_02041B6C(5);
            func_0201F7A8(p->f10[i], 2);
            func_020452E8(p->f10[i]);
        }
        p->f10[i] = 0;
    }
    p->f25c = 0;
}
