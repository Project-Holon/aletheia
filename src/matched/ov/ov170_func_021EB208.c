/*
 * function: func_021EB208
 * address: 0x021EB208
 * packet: pkt_ov170_021EB208
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
 *   func_02045B38 0x02045B38 arm
 *   func_02045C04 0x02045C04 arm
 */
extern void *func_02045770(void *);
extern void func_02043B5C(void *, unsigned);
extern void func_021EAC28(char *, int, void *, unsigned, int, int, unsigned, unsigned short);
extern void func_021EABD0(char *, int, void *, unsigned, int, int, unsigned, unsigned short);
extern void func_021EABA0(void **);
extern void func_021EAAE4(char *, unsigned);
typedef struct { unsigned char pad[18]; unsigned char low : 7; unsigned char flag : 1; unsigned char kind : 4; unsigned char enabled : 1; unsigned char rest : 3; } Entry;
extern void *func_02045B38(unsigned, unsigned, unsigned, unsigned);
extern void func_02045C04(void *);
void func_021EB208(char *p, Entry *e, int i)
{
    void **windows;
    unsigned j;
    void *bank;
    windows = (void **)p;
    windows = (void **)(p + 0x94);
    func_02043B5C(func_02045770(windows[i * 2]), 0);
    j = 0;
    bank = func_02045B38(0, 2, 203, 0x804c);
    if (!e->flag) {
        for (; j < 4; j++) {
            func_021EABD0(p, i, bank, *(unsigned short *)((char *)e + 0x14 + j * 2), 0, j * 16, *(unsigned *)(p + 0x78), 0x440);
        }
    } else {
        func_021EABD0(p, i, *(void **)(p + 0x80), 106, 0, 0, *(unsigned *)(p + 0x78), 0x440);
    }
    func_02045C04(bank);
    func_021EABA0(windows + i * 2);
}
