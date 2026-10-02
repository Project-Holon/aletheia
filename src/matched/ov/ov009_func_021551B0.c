/*
 * unit: yes
 * function: func_021551B0, func_021551D4
 * address: 0x021551B0
 * packet: pkt_ov009_021551B0
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203D5EC 0x0203D5EC arm
 *   func_0203D610 0x0203D610 arm
 *   func_0215539C 0x0215539C thumb ov009
 *   func_0215592C 0x0215592C thumb ov009
 */
typedef unsigned int u32;
extern u32 func_0203D5EC(void);
extern u32 func_0203D610(void);
extern int func_0215539C(int, int);
extern int func_0215592C(int);
int func_021551B0(void (*cb)(int))
{
    u32 a;
    int r;
    a = func_0203D5EC();
    r = func_0215539C(a, func_0203D610());
    if (cb) cb(1);
    return r;
}
int func_021551D4(int a)
{
    return func_0215592C(a);
}
