/*
 * function: func_021D4AB0
 * address:  0x021D4AB0
 * packet:   pkt_ov115_021D4AB0
 * region:   ov115
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D426C  0x021D426C  thumb  ov115
 *   func_021D5F7C  0x021D5F7C  thumb  ov115
 *   func_021D5D3C  0x021D5D3C  thumb  ov115
 *   func_021D5C94  0x021D5C94  thumb  ov115
 *   func_021D5ED8  0x021D5ED8  thumb  ov115
 *   func_0203CD98  0x0203CD98  arm
 *   func_0200FBB0  0x0200FBB0  thumb
 *   func_0203CA04  0x0203CA04  arm
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_0203C968  0x0203C968  arm
 *   func_021D4B3C  0x021D4B3C  thumb  ov115
 *   func_021D460C  0x021D460C  thumb  ov115
 */

extern void func_021D426C(int, int);
extern void func_021D5F7C(int);
extern void func_021D5D3C(int);
extern void func_021D5C94(int);
extern void func_021D5ED8(int, int);
extern int func_0203CD98(void);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_0200FBB0(void);
extern void func_0203CA04(void);
extern void func_0200FBA0(void);
extern void func_0203C968(void);
extern void func_021D4B3C(u8 *p);
extern void func_021D460C(u8 *p);

void func_021D4AB0(int a)
{
    int r;

    if (*(int *)(*(int *)(a + 0x40) + 0x20) != 0 &&
        *(int *)(*(int *)(a + 0x40) + 0x1c) == 0) {
        r = ((int (*)(int, int)) * (int *)(*(int *)(a + 0x40) + 0x20))(
            *(int *)(a + 0x38), *(int *)(*(int *)(a + 0x40) + 0x24));
        if (r == 2)
            return;
        switch (r) {
        case 0:
            *(int *)(*(int *)(a + 0x40) + 0x1c) = 0;
            func_021D426C(a, (int)func_021D4B3C);
            break;
        case 1:
            *(int *)(*(int *)(a + 0x40) + 0x1c) = 1;
            func_021D5F7C(*(int *)(a + 0x38));
            func_021D5D3C(*(int *)(a + 0x38));
            func_021D5C94(*(int *)(a + 0x38));
            if (func_0203CD98() != 0)
                func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            func_021D5ED8(*(int *)(a + 0x38), 0x25);
            func_021D426C(a, (int)func_021D460C);
            break;
        }
    } else {
        func_021D426C(a, (int)func_021D4B3C);
    }
}
