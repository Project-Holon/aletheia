/*
 * function: func_021C6980
 * address: 0x021C6980
 * packet: pkt_ov128_021C6980
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02031140 0x02031140 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 */
typedef unsigned char u8;
extern void func_0201C6EC(void *);
extern void func_0201C4C0(void *);
extern void func_0201CE48(void *);
extern void func_02031140(void *);
extern void func_0201D83C(void *);
extern void func_02045C04(void *);
extern void func_0201ED04(void *);
void func_021C6980(u8 *p)
{
    func_0201C6EC(*(void **)(p+0x34));
    func_0201C4C0(*(void **)(p+0x34));
    *(void **)(p+0x34)=0;
    if (*(void **)(p+0x2c)) {
        func_0201CE48(*(void **)(p+0x2c));
        *(void **)(p+0x2c)=0;
    }
    func_02031140(*(void **)(p+0x28));
    *(void **)(p+0x28)=0;
    func_0201D83C(*(void **)(p+0x17c));
    func_02045C04(*(void **)(p+4));
    func_0201ED04(*(void **)p);
}
