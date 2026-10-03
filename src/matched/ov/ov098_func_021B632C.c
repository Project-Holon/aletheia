/*
 * function: func_021B632C
 * address: 0x021B632C
 * packet: pkt_ov098_021B632C
 * region: ov098
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02031140 0x02031140 arm
 *   func_021B68DC 0x021B68DC thumb ov098
 *   func_021F7808 0x021F7808 thumb ov094
 *   func_022021F4 0x022021F4 thumb ov094
 *   func_0201D83C 0x0201D83C thumb
 *   func_021B6438 0x021B6438 thumb ov098
 *   func_020307B0 0x020307B0 arm
 */
extern void func_02031140(void *);
extern void func_021B68DC(void *);
extern void func_021F7808(void);
extern void func_022021F4(void *);
extern void func_0201D83C(void *);
extern void func_021B6438(void);
extern void func_020307B0(void *);
void func_021B632C(unsigned p)
{
    func_02031140(*(void **)(p + 0x18));
    func_021B68DC(*(void **)(p + 0x14));
    func_021F7808();
    func_022021F4(*(void **)(p + 0x10));
    func_0201D83C(*(void **)(p + 8));
    func_0201D83C(*(void **)(p + 0xc));
    func_021B6438();
    func_020307B0(*(void **)(p + 0x70));
    func_020307B0((void *)p);
}
