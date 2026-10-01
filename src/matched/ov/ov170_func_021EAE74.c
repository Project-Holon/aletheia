/*
 * function: func_021EAE74
 * address: 0x021EAE74
 * packet: pkt_ov170_021EAE74
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021EAC28 0x021EAC28 thumb ov170
 *   func_021EABD0 0x021EABD0 thumb ov170
 *   func_021EABA0 0x021EABA0 thumb ov170
 *   func_021EAAE4 0x021EAAE4 thumb ov170
 *   func_0201D304 0x0201D304 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 */
extern void *func_02045770(void *);
extern void func_02043B5C(void *, unsigned);
extern void func_021EAC28(char *, int, void *, unsigned, int, int, unsigned, unsigned short);
extern void func_021EABD0(char *, int, void *, unsigned, int, int, unsigned, unsigned short);
extern void func_021EABA0(void **);
extern void func_021EAAE4(char *, unsigned);
typedef struct { unsigned char pad[18]; unsigned char low : 7; unsigned char flag : 1; unsigned char kind : 4; unsigned char enabled : 1; unsigned char rest : 3; } Entry;
extern unsigned func_0201D304(void *, unsigned, unsigned);
extern void func_0201EFA4(void *, unsigned, unsigned, unsigned, unsigned, unsigned);
void func_021EAE74(char *p, Entry *e, unsigned i)
{
    unsigned n;
    func_02043B5C(func_02045770(*(void **)(p + 0x94 + i * 8)), 0);
    if (!e->flag) {
        func_021EAC28(p, i, *(void **)(p + 0x80), 107, 0, 0, *(unsigned *)(p + 0x78), 0x440);
        n = func_0201D304(*(void **)(p + 0x88), *(unsigned *)(p + 0x78), 0);
        func_0201EFA4(*(void **)(p + 0x84), 0, e->low, 3, 0, 1);
        func_021EAC28(p, i, *(void **)(p + 0x80), 103, n, 0, *(unsigned *)(p + 0x78), 0x440);
    } else {
        func_021EAAE4(p, i); return;
    }
    func_021EABA0((void **)(p + 0x94 + i * 8));
}
