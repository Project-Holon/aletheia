/*
 * function: func_021BF4E8
 * address: 0x021BF4E8
 * packet: pkt_ov204_021BF4E8
 * region: ov204
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Trailing two bytes are zero alignment padding.
 * symbols:
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 *   func_02082BCC 0x02082BCC arm
 */

extern void func_0201F7A8(void *, unsigned int);
extern void *func_02045770(void *);
extern void func_02043B5C(void *, unsigned char);
extern void func_02045334(void *);
extern void func_0202020C(void *, unsigned short *, unsigned short *);
extern void func_0201F868(void *);
extern void func_02082BCC(void *, int, unsigned int);

void func_021BF4E8(char *p)
{
    char *block = p + 0x24;
    func_0201F7A8(*(void **)(p + 0x38), 0);
    func_02043B5C(func_02045770(*(void **)(p + 0x38)), 0);
    func_02045334(*(void **)(p + 0x38));
    func_0202020C(*(void **)block, 0, 0);
    func_0201F868(*(void **)(block + 4));
    func_02082BCC(block, 0, 12);
}
