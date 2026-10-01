/*
 * function: func_021EB114
 * address: 0x021EB114
 * packet: pkt_ov170_021EB114
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
 *   func_0201EF8C 0x0201EF8C thumb
 */
typedef struct { unsigned char pad[18]; unsigned char low : 7; unsigned char flag : 1; } Entry;
extern void *func_02045770(void *);
extern void func_02043B5C(void *, unsigned);
extern void func_021EAC28(char *, int, void *, unsigned, int, int, unsigned, unsigned short);
extern void func_021EABD0(char *, int, void *, unsigned, int, int, unsigned, unsigned short);
extern void func_021EABA0(void **);
extern void func_0201EF8C(void *, unsigned, unsigned);
void func_021EB114(char *p, unsigned char *e, int i)
{
    func_02043B5C(func_02045770(*(void **)(p + 0x94 + i * 8)), 0);
    if (!((Entry *)e)->flag) {
        func_0201EF8C(*(void **)(p + 0x84), 0, e[14]);
        func_021EAC28(p, i, *(void **)(p + 0x80), 97, 0, 0, *(unsigned *)(p + 0x78), 0x440);
    } else {
        func_021EABD0(p, i, *(void **)(p + 0x80), 106, 0, 0, *(unsigned *)(p + 0x78), 0x440);
    }
    func_021EABA0((void **)(p + 0x94 + i * 8));
}
