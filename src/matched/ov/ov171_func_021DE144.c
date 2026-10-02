/*
 * function: func_021DE144
 * address: 0x021DE144
 * packet: pkt_ov171_021DE144
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020275E4 0x020275E4 thumb
 *   func_02027618 0x02027618 thumb
 *   func_02027614 0x02027614 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_020275E4(void);
extern int func_02027618(void);
extern int func_02027614(void);
extern int func_0202761C(int);
extern int func_02027620(int);
extern u8 *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0204A6C8(u8 *, int, int, int, u16);
extern int func_0204ABF0(u8 *, int, int, int, u16);
extern int func_0204AF28(u8 *, int, int, int);
extern void func_02049238(u8 *);
void func_021DE144(char *p)
{
    unsigned i;
    u8 *s;
    int a;
    for (i = 0; i < 13; ++i)
        *(int *)(p + 0xbb4 + i * 4) = -1;
    for (i = 0; i < 13; ++i)
        *(int *)(p + 0xbe8 + i * 4) = -1;
    for (i = 0; i < 13; ++i)
        *(int *)(p + 0xc1c + i * 4) = -1;
    s = func_020490F4(func_020275E4(), 0x808c);
    *(int *)(p + 0xbe4) = func_0204A6C8(s, func_02027618(), 0, 0, 0x8c);
    *(int *)(p + 0xc18) = func_0204ABF0(s, func_02027614(), 0, 0x180, 0x8c);
    a = func_0202761C(2);
    *(int *)(p + 0xc4c) = func_0204AF28(s, a, func_02027620(2), 0x8c);
    func_02049238(s);
}
