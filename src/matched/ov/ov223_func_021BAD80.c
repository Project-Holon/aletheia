/*
 * function: func_021BAD80
 * address: 0x021BAD80
 * packet: pkt_ov223_021BAD80
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Trailing ADFA halfword is zero alignment padding.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049BDC 0x02049BDC arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049BDC(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, u16);
extern void func_02049658(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, u16);
extern void func_020498F4(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, u16);
extern void func_02049238(void *);
extern void func_020409B4(unsigned);
void func_021BAD80(u16 *p)
{
    void *object;
    object = func_020490F4((void *)205, *p);
    func_02049BDC((unsigned)object, 7, 4, 256, 256, 256, *p);
    func_02049658((unsigned)object, 16, 4, 0, 0, 0, *p);
    func_020498F4((unsigned)object, 19, 4, 0, 0, 0, *p);
    func_020498F4((unsigned)object, 20, 5, 0, 0, 0, *p);
    func_02049238(object);
    func_020409B4(4);
    func_020409B4(5);
}
