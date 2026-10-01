/*
 * function: func_021B9788
 * address: 0x021B9788
 * packet: pkt_ov182_021B9788
 * region: ov182
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 2-byte zero alignment at 021B980E after code; next function 021B9810.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_020111E8 0x020111E8 thumb
 *   func_020413B0 0x020413B0 arm
 *   func_02049238 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02040588 0x02040588 arm
 */
extern unsigned char *func_020490F4(int, int);
extern void func_02049B68(unsigned char *, int, int, int, int, int);
extern void func_02049658(unsigned char *, int, int, int, int, int, int);
extern void func_020498F4(unsigned char *, int, int, int, int, int, int);
extern int func_020111E8(void);
extern void func_020413B0(int, int, int, int, int, int);
extern void func_02049238(unsigned char *);
extern void func_020409B4(int);
extern void func_02040588(unsigned char, unsigned char);
void func_021B9788(unsigned short *p)
{
    unsigned char *q = func_020490F4(0xdc, *p);
    func_02049B68(q, 2, 0, 0, 0, *p);
    func_02049658(q, 3, 1, 0, 0, 0, *p);
    func_020498F4(q, 5, 1, 0, 0, 0, *p);
    if (func_020111E8() == 0x14)
        func_020413B0(1, 0, 0, 0x20, 0x18, 1);
    func_02049238(q);
    func_020409B4(1);
    func_02040588(1, 1);
    func_02040588(2, 0);
}
