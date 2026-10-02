/*
 * function: func_021F022C
 * address: 0x021F022C
 * packet: pkt_ov031_021F022C
 * region: ov031
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0204B1CC 0x0204B1CC arm
 */
extern void func_02045C04(void *);
extern void func_0201D83C(void *);
extern void func_0201C6EC(void *);
extern void func_0201C4C0(void *);
extern void func_0204B1CC(void *);
void func_021F022C(char *p)
{
    func_02045C04(*(void **)(p + 0x48));
    func_0201D83C(*(void **)(p + 0x44));
    func_0201C6EC(*(void **)(p + 0x40));
    func_0201C4C0(*(void **)(p + 0x40));
    func_0204B1CC(*(void **)(p + 0x14));
}
