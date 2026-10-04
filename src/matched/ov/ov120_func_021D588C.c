/*
 * function: func_021D588C
 * address: 0x021D588C
 * packet: pkt_ov120_021D588C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D70F0 0x021D70F0 thumb ov120
 *   func_0200F800 0x0200F800 thumb
 *   func_020355C4 0x020355C4 arm
 *   func_021D69F4 0x021D69F4 thumb ov120
 *   func_021D7D6C 0x021D7D6C thumb ov120
 *   func_021D4C98 0x021D4C98 thumb ov120
 *   func_021D42D8 0x021D42D8 thumb ov120
 *   func_02012934 0x02012934 thumb
 *   func_0201AA1C 0x0201AA1C thumb
 *   func_021D79F4 0x021D79F4 thumb ov120
 *   func_02040588 0x02040588 arm
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D5AD4 0x021D5AD4 thumb ov120
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021D70F0(void *);
extern void func_0200F800(void);
extern u8 func_020355C4(void);
typedef unsigned short u16;
struct BigObj;
extern void func_021D69F4(u8 *p, void *q, u32 n);
extern void func_021D7D6C(char *p, int a, int b);
extern void func_021D4C98(void *p, int n, u8 *s);
extern int func_021D42D8(int n, u8 *p);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA1C(void *);
extern void func_021D79F4(u8 *p, u16 n);
extern void func_02040588(u32, u32);
extern void func_021D4244(int, int, int);
extern void func_021D5AD4(u8 *p);
void func_021D588C(u8 *p)
{
    func_021D70F0(*(void **)(p + 0x3c));
    if (*(u32 *)(p + 0x1b0)) {
        if ((*(u32 *)(p + 0x1b4))++ < 3)
            return;
        func_0200F800();
        *(u32 *)(p + 0x1b0) = 0;
    }
    if (func_020355C4() == 0)
        func_021D69F4(*(void **)(p + 0x3c), 0, *(int *)(p + 0x15c));
    else
        func_021D69F4(*(void **)(p + 0x3c), 0, 9);
    func_021D7D6C(*(void **)(p + 0x40), (int)func_021D4C98, (int)p);
    *(void (**)(void))(p + 4) = (void (*)(void))func_021D42D8;
    if ((int)func_0201AA1C(func_02012934(*(void **)(p + 0x2c))) < 2)
        *(int *)(p + 0x184) = 1;
    if (*(int *)(p + 0x184) == 0)
        func_021D79F4(*(void **)(p + 0x40), 0x20);
    else
        func_021D79F4(*(void **)(p + 0x40), 0x2b);
    func_02040588(4, 1);
    func_02040588(6, 1);
    func_021D4244((int)p, (int)func_021D5AD4, 0x86c);
}
