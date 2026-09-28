/*
 * function: func_020290F0
 * address:  0x020290F0
 * packet:   pkt_02028FD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02029374(u8 *p);
extern void func_02029344(void *p, u32 v);
extern void func_0202945C(u8 *p);
extern void func_02029364(u8 *p);

void func_020290F0(u8 *p)
{
    switch (*(u32 *)(p + 0x1c)) {
    case 0:
        break;
    case 1:
        func_02029374(p);
        func_02029344(p, 4);
        break;
    case 7:
        func_0202945C(p);
        func_02029344(p, 1);
        func_02029364(p);
        break;
    }
}
