/*
 * function: func_02202248
 * address: 0x02202248
 * packet: pkt_ov094_02202248
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203FC6C 0x0203FC6C arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204B100 0x0204B100 arm
 *   func_0220255C 0x0220255C thumb ov094
 *   func_022033F4 0x022033F4 thumb ov094
 *   func_02205E80 0x02205E80 thumb ov094
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02024A20 0x02024A20 thumb
 *   func_02040588 0x02040588 arm
 *   func_02043598 0x02043598 arm
 *   func_0203D34C 0x0203D34C arm
 *   func_020216D4 0x020216D4 thumb
 *   func_021F86D4 0x021F86D4 thumb ov094
 *   func_02030DA8 0x02030DA8 arm
 *   func_02202238 0x02202238 thumb ov094
 *   func_0220270C 0x0220270C thumb ov094
 *   d_0220A3D4 0x0220A3D4 data ov094 a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_0220A3D4[];
extern void func_0203FC6C(void *, int);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0204B100(int, int, u16);
extern void func_0220255C(char *);
extern void func_022033F4(char *);
extern void func_02205E80(char *);
extern void *func_020450F0(u32, u32, u32, u32, u32, u32, u32);
extern void *func_02045770(void *);
extern void func_02043B5C(void *, int);
extern void func_02045334(void *);
extern void func_02045374(void *);
extern void func_020409B4(u8);
extern void func_02024A20(u8, u8, void *, u16);
extern void func_02040588(u32, u8);
extern void func_02043598(int, int);
extern void func_0203D34C(u32, u32);
extern void func_020216D4(void *, u32, u32, u32);
extern void *func_021F86D4(void);
extern void *func_02030DA8(void *, void (*)(void *, void *), void *, u32);
extern void func_02202238(void *, void *);
extern void func_0220270C(char *, int, int);
void func_02202248(char *p)
{
    func_0203FC6C(d_0220A3D4, 1);
    *(u32 *)(p + 0x48) = func_020490F4(0xb, *(u16 *)(p + 0x240));
    *(int *)(p + 0x1f8) = func_0204B100(4, 2, *(u16 *)(p + 0x240));
    *(int *)(p + 0x118) = func_0204B100(0xc, 2, *(u16 *)(p + 0x240));
    *(int *)(p + 0x17c) = func_0204B100(6, 0, *(u16 *)(p + 0x240));
    *(int *)(p + 0x1c4) = func_0204B100(3, 2, *(u16 *)(p + 0x240));
    *(int *)(p + 0x20c) = func_0204B100(2, 2, *(u16 *)(p + 0x240));
    *(int *)(p + 0x218) = func_0204B100(1, 1, *(u16 *)(p + 0x240));
    func_0220255C(p);
    func_022033F4(p);
    func_02205E80(p);
    *(void **)(p + 0x228) = func_020450F0(6, 0, 4, 32, 12, 13, 1);
    *(void **)(p + 0x22c) = func_02045770(*(void **)(p + 0x228));
    *(void **)(p + 0x230) = func_020450F0(6, 3, 22, 3, 2, 13, 1);
    *(void **)(p + 0x234) = func_02045770(*(void **)(p + 0x230));
    func_02043B5C(*(void **)(p + 0x22c), 0);
    func_02043B5C(*(void **)(p + 0x234), 0);
    func_02045334(*(void **)(p + 0x228));
    func_02045334(*(void **)(p + 0x230));
    func_02045374(*(void **)(p + 0x228));
    func_02045374(*(void **)(p + 0x230));
    func_020409B4(6);
    func_02024A20(6, 15, *(void **)(p + 0x4c), *(u16 *)(p + 0x240));
    func_02040588(6, 1);
    func_02043598(16, 1);
    func_0203D34C(0, *(u16 *)(p + 0x240));
    func_020216D4(*(void **)(p + 0x64), 3, 0xe0, 0x20);
    *(u32 *)(p + 0x68) |= 0x2000;
    if (*(int *)(p + 0x23c) == 1)
        *(void **)(p + 0x238) = func_02030DA8(func_021F86D4(), func_02202238, p, 0);
    func_0220270C(p, 0, 0);
}
