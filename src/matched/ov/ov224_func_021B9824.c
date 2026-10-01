/*
 * function: func_021B9824
 * address: 0x021B9824
 * packet: pkt_ov224_021B9824
 * region: ov224
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(void *, u32);
extern void func_02049B68(void *, u32, u32, u32, u32, u16);
extern void func_02049658(void *, u32, u32, u32, u32, u32, u16);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
extern void func_02049238(void *);
extern void func_020409B4(u32);
void func_021B9824(u16 *work)
{
    void *narc = func_020490F4((void *)0xce, *work);
    func_02049B68(narc, 0, 0, 0, 0, *work);
    func_02049658(narc, 1, 1, 0, 0, 0, *work);
    func_020498F4(narc, 2, 1, 0, 0, 0, *work);
    func_020498F4(narc, 3, 2, 0, 0, 0, *work);
    func_02049238(narc);
    func_020409B4(1);
    func_020409B4(2);
}
