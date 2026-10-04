/*
 * function: func_021F5ECC
 * address:  0x021F5ECC
 * packet:   pkt_021F5ECC
 * region:   ov215
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02005D28  0x02005D28  thumb
 *   func_02005DE4  0x02005DE4  thumb
 *   func_02005E50  0x02005E50  thumb
 *   func_02005E64  0x02005E64  thumb
 *   func_02005F38  0x02005F38  thumb
 *   func_020063B4  0x020063B4  thumb
 *   func_021F5FEC  0x021F5FEC  thumb ov215
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02005D28(void);
extern void func_02005DE4(void *p);
extern int  func_02005E50(void);
extern void func_02005E64(void);
extern int  func_02005F38(void);
extern u32 func_020063B4(u8 *a0, u32 *a1, u32 a2);
extern void func_021F5FEC(void *, void *);

void func_021F5ECC(u8 *p, u8 *q)
{
    switch (*(u32 *)(q + 0x18)) {
    case 0:
        break;
    case 1:
        if (func_02005E50() == 0) {
            func_02005DE4((void *)1);
            func_02005E64();
            *(u32 *)(q + 0x18) = 0;
        }
        break;
    case 2:
        if (func_02005F38() == 0)
            *(u32 *)(q + 0x18) = 0;
        break;
    case 3:
        if (func_020063B4((u8 *)0x3F3, (u32 *)(q + 0x24), 0) != 0)
            *(u32 *)(q + 0x18) = 4;
        break;
    case 4:
        break;
    case 5:
        if (func_020063B4((u8 *)0x519, (u32 *)(q + 0x24), 0) != 0)
            *(u32 *)(q + 0x18) = 6;
        break;
    case 6:
        if (func_02005F38() == 0) {
            func_021F5FEC(p, q);
            *(u32 *)(q + 0x18) = 4;
        }
        break;
    case 7:
        if (func_02005E50() == 0) {
            func_02005D28();
            *(u32 *)(q + 0x18) = 0;
        }
        break;
    }
}
