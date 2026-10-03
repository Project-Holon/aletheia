/*
 * function: func_021BD628
 * address: 0x021BD628
 * packet: pkt_ov209_021BD628
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200CA70 0x0200CA70 thumb
 *   func_0200D0CC 0x0200D0CC thumb
 *   func_0200CF28 0x0200CF28 thumb
 *   func_0200D0F8 0x0200D0F8 thumb
 *   func_0200CF54 0x0200CF54 thumb
 *   func_021BD4F4 0x021BD4F4 thumb ov209
 *   func_021BD440 0x021BD440 thumb ov209
 *   func_021BD488 0x021BD488 thumb ov209
 *   func_021BD4DC 0x021BD4DC thumb ov209
 *   func_0201EFA4 0x0201EFA4 thumb
 */
typedef unsigned short u16;
typedef struct WordSet WordSet;
extern unsigned func_0200CA70(void *);
extern u16 func_0200D0CC(void *);
extern u16 func_0200CF28(void *);
extern u16 func_0200D0F8(void *, unsigned);
extern u16 func_0200CF54(void *, unsigned);
extern void func_021BD4F4(char *, unsigned);
extern void func_021BD440(char *, unsigned, unsigned, unsigned, unsigned, u16, unsigned);
extern void func_021BD488(char *, unsigned, unsigned, unsigned, unsigned, u16, unsigned);
extern void func_021BD4DC(char *);
extern void func_0201EFA4(WordSet *, unsigned, unsigned, unsigned, unsigned, unsigned);
void func_021BD628(char *p)
{
    unsigned a, b;
    if (func_0200CA70(*(void **)(*(char **)p + 4)) == 1) {
        a = func_0200D0CC(*(void **)(*(char **)p + 4));
        b = func_0200CF28(*(void **)(*(char **)p + 4));
    } else {
        a = func_0200D0F8(*(void **)(*(char **)p + 4), 0x806b);
        b = func_0200CF54(*(void **)(*(char **)p + 4), 0x806b);
    }
    func_021BD4F4(p, 1);
    func_021BD4F4(p, 2);
    func_021BD440(p, 1, 2, 0x48, 4, 0x31a0, 1);
    func_0201EFA4(*(WordSet **)(p + 0x40), 0, a, 3, 0, 1);
    func_021BD488(p, 1, 5, 0x68, 4, 0x31a0, 1);
    func_021BD440(p, 2, 3, 0x58, 4, 0x31a0, 1);
    func_0201EFA4(*(WordSet **)(p + 0x40), 0, b, 3, 0, 1);
    func_021BD488(p, 2, 5, 0x78, 4, 0x31a0, 1);
    func_021BD4DC(p + 0x28);
    func_021BD4DC(p + 0x30);
}
