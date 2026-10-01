/*
 * function: func_021C52F8
 * address: 0x021C52F8
 * packet: pkt_ov136_021C52F8
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: base + i * 4 + 0x44 keeps the base-plus-index inside the loop;
 * base + 0x44 + i * 4 hoists the field address and changes the loads.
 * symbols:
 *   func_02045808 0x02045808 arm
 *   func_020456F8 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020450C8 0x020450C8 arm
 */
typedef unsigned char u8;
extern void func_02028148(void *);
extern void func_02045808(void *);
extern void func_0201C4C0(void *);
extern void func_020456F8(void *);
extern void *func_02045730(void *);
extern void func_020409B4(void *);
extern void func_020452E8(void *);
extern void func_020450C8(void);
void func_021C52F8(u8 *p)
{
    int i;
    void *q;
    if (p[0xB] == 1) {
        func_02028148(*(void **)(p + 0x128));
        func_02028148(*(void **)(p + 0x12C));
        func_02045808(*(void **)(p + 0x130));
        func_02045808(*(void **)(p + 0x13C));
    }
    func_0201C4C0(*(void **)(p + 0x98));
    *(void **)(p + 0x98) = 0;
    for (i = 0; i < 7; i++) {
        q = *(void **)(p + i * 4 + 0x44);
        func_020456F8(q);
        func_020409B4(func_02045730(q));
        func_020452E8(*(void **)(p + i * 4 + 0x44));
    }
    func_020450C8();
}
