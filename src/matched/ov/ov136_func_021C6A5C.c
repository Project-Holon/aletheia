/*
 * function: func_021C6A5C
 * address: 0x021C6A5C
 * packet: pkt_ov136_021C6A5C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020306F0 0x020306F0 arm
 *   func_021C5AA8 0x021C5AA8 thumb ov136
 *   func_021C5954 0x021C5954 thumb ov136
 *   func_021C76A8 0x021C76A8 thumb ov136
 *   func_021C5E30 0x021C5E30 thumb ov136
 *   func_021C657C 0x021C657C thumb ov136
 *   func_021C5918 0x021C5918 thumb ov136
 *   func_021C5F44 0x021C5F44 thumb ov136
 *   func_021C5714 0x021C5714 thumb ov136
 *   func_021C5BE0 0x021C5BE0 thumb ov136
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02030EAC(void *);
extern void func_021C5AA8(u8 *);
extern void func_021C5954(void *);
extern void func_021C76A8(void *);
extern void func_021C5E30(void *);
extern void func_021C657C(u8 *);
extern void func_021C5918(void *);
extern void func_021C5F44(void *);
extern void func_021C5714(void *);
extern void func_021C5BE0(void *);
extern void func_02043534(int);
extern void func_020435F4(int);
extern void func_020307B0(void *);
extern void func_020306F0(u32);
u32 func_021C6A5C(u8 *p)
{
    if (*(void **)(p + 0x2c) != 0) {
        func_02030EAC(*(void **)(p + 0x2c));
        *(void **)(p + 0x2c) = 0;
    }
    func_021C5AA8(p);
    func_021C5954(*(void **)(p + 8));
    func_021C76A8(p);
    func_021C5E30(p);
    func_021C657C(p);
    func_021C5918(p);
    func_021C5F44(p);
    func_021C5714(p);
    func_021C5BE0(p);
    *(u16 *)0x04000050 = 0;
    *(u16 *)0x04001050 = 0;
    func_02043534(0);
    func_020435F4(0);
    func_020307B0(*(void **)(p + 8));
    *(void **)(p + 8) = 0;
    func_020306F0(102);
    return *(u32 *)(p + 0x28);
}
