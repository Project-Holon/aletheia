/*
 * function: func_021D5BEC
 * address: 0x021D5BEC
 * packet: pkt_ov120_021D5BEC
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_021D846C 0x021D846C thumb ov120
 *   func_021D63F4 0x021D63F4 thumb ov120
 *   func_02040588 0x02040588 arm
 *   func_021D761C 0x021D761C thumb ov120
 *   func_021D7B38 0x021D7B38 thumb ov120
 *   func_021D883C 0x021D883C thumb ov120
 *   func_021D69F4 0x021D69F4 thumb ov120
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D588C 0x021D588C thumb ov120
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0203D7B0(int);
extern void func_0203D7BC(int);
extern void func_021D846C(u8 *);
extern void func_021D63F4(void *, int, int);
extern void func_02040588(u32, u32);
extern void func_021D761C(void *);
extern void func_021D7B38(int);
extern void func_021D883C(char *);
extern void func_021D69F4(void *, void *, int);
extern void func_021D4244(int, int, int);
extern void func_021D588C(void);
void func_021D5BEC(u8 *p)
{
    if (*(int *)(*(u8 **)(p + 0x48) + 0x1b0) != 1) {
        int zero = 0;
        func_0203D7B0(0);
        func_0203D7BC(0);
        func_021D846C(*(u8 **)(p + 0x40));
        func_021D63F4(*(void **)(p + 0x3c), 0, 0);
        func_02040588(4, 0);
        func_021D761C(*(void **)(p + 0x3c));
        func_021D7B38(*(int *)(p + 0x40));
        func_021D883C(*(char **)(p + 0x40));
        func_021D69F4(*(void **)(p + 0x3c), 0, 9);
        *(int *)(p + 0x1b0) = 1;
        *(int *)(p + 0x1b4) = zero;
        *(int *)(*(u8 **)(p + 0x48) + 0x1b0) = 1;
        func_021D4244((int)p, (int)func_021D588C, 0x937);
    }
}
