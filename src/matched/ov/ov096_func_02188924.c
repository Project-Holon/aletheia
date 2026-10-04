/*
 * function: func_02188924
 * address:  0x02188924
 * packet:   pkt_ov096_02188924
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D6314  0x021D6314  thumb  ov093
 *   func_021E8A78  0x021E8A78  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0201134C(int);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern int func_0218A0F4(u8 *a, int op, int x, int y, int z);
extern int func_021D62C4(void *, int);
typedef struct Slot { u32 a : 3; u32 rest : 29; } Slot;
extern Slot func_021D6314(void *, int);
extern int func_021E8A78(Slot);

void func_02188924(int a, int b, int c)
{
    int t1;
    int t3;
    u8 *r;
    u8 k;
    int x;
    Slot s;

    t1 = func_0201134C(a);
    t3 = func_0201134C(a);
    k = func_0218A160((u8 *)b, t1);
    r = func_0218A2FC((u8 *)b, k);
    x = 0;
    if (func_021D62C4(r, 5) != 0) {
        s = func_021D6314(r, 5);
        if (func_021E8A78(s) != 0)
            x = 1;
    }
    func_0218A0F4((u8 *)a, c, x, 1, t3);
}
