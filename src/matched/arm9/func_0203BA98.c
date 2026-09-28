/*
 * function: func_0203BA98
 * address:  0x0203BA98
 * packet:   pkt_0203BA98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469DC      0x021469DC  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long long u64;

extern u8 *g_021469DC;

extern u8  *func_0203D798(void);
extern u8  *func_0203D788(void);
extern void func_0203BC58(u8, u8, const void *);
extern u32  func_020377B8(u8);
extern void func_0203AD80(u32, u32, u32, u32);
extern void func_0203B9D4(u8 *);
extern void func_0203B950(void);
extern void func_0203B01C(void);
extern u32  func_02037928(u32, u16);
extern void func_02037A6C(u32, u32, u16, u32);

void func_0203BA98(u16 a0, u32 a1, u8 a2)
{
    u8 *s = func_0203D798();
    u8 *p;
    u64 x, y, r;
    u32 delay = 30;

    func_0203D788();
    func_0203BC58(0, a2, 0);

    if (s[0x65] == 3 || s[0x65] == 4) {
        func_020377B8(0);
        *(u32 *)(g_021469DC + 0x2C) = a1;
        p = g_021469DC;
        x = *(u64 *)(p + 0x0C);
        y = *(u64 *)(p + 0x14);
        r = y * x + *(u64 *)(p + 0x1C);
        *(u64 *)(p + 0x0C) = r;
        func_0203AD80((u32)p, (u32)func_0203B9D4, (u32)(((u64)(u32)(r >> 32) * delay) >> 32), delay + 0x3A8);
    } else {
        p = g_021469DC;
        if (p[0x53] != 0 && p[0x56] != 1) {
            func_02037A6C(1, (u32)(p + 0x57), 0x200, (u32)func_0203B01C);
        } else {
            func_02037928(1, 0x200);
        }
        *(u32 *)(g_021469DC + 0x2C) = a1;
        p = g_021469DC;
        func_0203AD80((u32)p, (u32)func_0203B950, delay, delay + 0x3B4);
    }
}
