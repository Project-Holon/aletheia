/*
 * function: func_02187508
 * address:  0x02187508
 * packet:   pkt_ov020_02187508
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02191388  0x02191388  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_02190BE4  0x02190BE4  thumb  ov021
 *   func_02190C78  0x02190C78  thumb  ov021
 *   func_021909BC  0x021909BC  thumb  ov021
 *   func_021912D8  0x021912D8  thumb  ov021
 *   func_021912F8  0x021912F8  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02191388(int);
extern u32 func_020362DC(void);
extern int func_02190BE4(int, int);
extern int func_02190C78(int);
extern int func_021909BC(u32 a);
extern int func_021912D8(u32 a);
extern int func_021912F8(int);

int func_02187508(char *p)
{
    int r;

    switch (*(u16 *)(p + 0x52)) {
    case 0:
        if (func_02191388(*(int *)(p + 0x10)) == 0)
            break;
        *(u16 *)(p + 0x52) = *(u16 *)(p + 0x52) + 1;
        break;
    case 1:
        if ((func_020362DC() & 0xf3) == 0)
            break;
        if (*(u8 *)(p + 0x55) == 0)
            *(u16 *)(p + 0x52) = 4;
        else
            *(u16 *)(p + 0x52) = 2;
        break;
    case 2:
        *(int *)(p + 0x14) = func_02190BE4(*(int *)(p + 0xc), 0);
        *(u16 *)(p + 0x52) = *(u16 *)(p + 0x52) + 1;
        break;
    case 3:
        r = func_02190C78(*(int *)(p + 0x14));
        if (r == 2)
            break;
        if (r == 0)
            *(u8 *)(p + 0x54) = 1;
        else
            *(u8 *)(p + 0x54) = 0;
        *(u16 *)(p + 0x52) = 4;
        func_021909BC(*(int *)(p + 0x14));
        *(int *)(p + 0x14) = 0;
        break;
    case 4:
        func_021912D8(*(int *)(p + 0x10));
        *(u16 *)(p + 0x52) = *(u16 *)(p + 0x52) + 1;
        break;
    case 5:
        if (func_021912F8(*(int *)(p + 0x10)) != 0) {
            *(int *)(p + 0x10) = 0;
            return 1;
        }
        break;
    }
    return 0;
}
