/*
 * function: func_021D68C4
 * address: 0x021D68C4
 * packet: pkt_ov120_021D68C4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 2-byte zero alignment padding at 0x021D692A.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02041300 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 *   func_021D6B5C 0x021D6B5C thumb ov120
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02041300(u32, int, int, int, u8, u8, u8);
extern void func_02041B6C(u32);
extern void func_02049990(void *, u32, u32, u32, u16, u32, u32, u16);
extern void func_02049238(void *);
extern void func_021D6B5C(u8 *);
void func_021D68C4(u8 *p)
{
    void *t = func_020490F4((void *)144, *(u16 *)(p + 0xf4));
    func_021D6B5C(p);
    func_02041300(6, 0, 0, 0, 32, 32, 17);
    func_02041B6C(6);
    func_02049990(t, 18, 4, 0, *(u32 *)p, 0, 0, *(u16 *)(p + 0xf4));
    func_02041B6C(4);
    func_02049238(t);
}
