/*
 * function: func_021D5C60
 * address: 0x021D5C60
 * packet: pkt_ov120_021D5C60
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware halfword registers written at 0x021D5C78 and 0x021D5C7E.
 * prototype: 0203064C r2 explicitly loaded despite two-arg definition;
 * 0203159C r0 allocation result used despite void matched definition.
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021D5E88 0x021D5E88 thumb ov120
 *   func_021D7724 0x021D7724 thumb ov120
 *   func_0203CD98 0x0203CD98 arm
 *   func_0203A574 0x0203A574 arm
 *   d_021D88EC 0x021D88EC data a4
 *   func_0200F7E8 0x0200F7E8 thumb
 *   func_0203D34C 0x0203D34C arm
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D588C 0x021D588C thumb ov120
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0203064C(u32, u32, u32);
extern u8 *func_0203159C(void *, u32, u32);
extern void func_02082BCC(void *, int, u32);
extern u8 *func_021D5E88(u32, void *);
struct Big;
struct BigObj;
extern char *func_021D7724(u32 heap, u32 n);
extern void func_0202223C(u32, u32);
extern void *func_02012EBC(struct Big *p);
extern u32 func_0201283C(const struct BigObj *p);
extern u8 *func_02012944(void *p);
extern u32 func_02008530(void *);
extern int func_0203CD98(void);
extern void func_0203A574(u32, u32, u32, u32);
extern const u32 d_021D88EC[];
extern void func_0202208C(void *, u32, u32, u32, u32, u32, u32);
extern void func_02005D90(u32, u32);
extern void func_0203D34C(u32, u32);
extern void func_0200F7E8(u32 value);
extern void func_021D4244(int, int, int);
extern void func_021D588C(u8 *);
int func_021D5C60(void *a, int unused, u8 *q)
{
    u8 *p;
    int zero = 0;
    func_0203064C(1, 0x1f, 0x38000);
    *(volatile u16 *)0x04000050 = zero;
    *(volatile u16 *)0x04001050 = zero;
    func_0202223C(0, 0);
    func_0202223C(1, 0);
    p = func_0203159C(a, 0x1b8, 0x1f);
    func_02082BCC(p, 0, 0x1b8);
    *(u16 *)(p + 0xc) = 0x1f;
    *(u8 **)(p + 0x48) = q;
    *(void **)(p + 0x3c) = func_021D5E88(*(u16 *)(p + 0xc), *(void **)q);
    *(void **)(p + 0x40) = func_021D7724(*(u16 *)(p + 0xc), 0x28);
    *(void **)(p + 0x2c) = *(void **)q;
    *(void **)(p + 0x30) = func_02012EBC(*(void **)q);
    *(u32 *)(p + 0x44) = func_0201283C(*(void **)q);
    *(int *)(*(u8 **)(p + 0x48) + 0x1b0) = 1;
    *(int *)(p + 0x15c) = zero;
    *(int *)(p + 0x160) = 2;
    *(int *)(p + 0x164) = 6;
    *(u32 *)(p + 0x14c) = func_02008530(func_02012944(*(void **)q));
    if (func_0203CD98())
        func_0203A574(0x2200, (u32)d_021D88EC, 3, (u32)p);
    func_0202208C(0, 1, 1, 0, 6, 1, *(u16 *)(p + 0xc));
    func_02005D90(0x486, 0xffff);
    func_0203D34C(1, *(u16 *)(p + 0xc));
    func_0200F7E8(1);
    func_021D4244((int)p, (int)func_021D588C, 0x96a);
    return 1;
}
