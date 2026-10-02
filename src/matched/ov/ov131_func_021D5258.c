/*
 * function: func_021D5258
 * address: 0x021D5258
 * packet: pkt_ov131_021D5258
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 */
extern void func_0201C6EC(void *);
extern void func_0201C4C0(void *);
extern void func_02045C04(void *);
extern void func_0201D83C(void *);
void func_021D5258(char *p)
{
    func_0201C6EC(*(void **)(p+0x84));
    func_0201C4C0(*(void **)(p+0x84));
    func_02045C04(*(void **)(p+0x7c));
    func_0201D83C(*(void **)(p+0x80));
}
