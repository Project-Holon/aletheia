/*
 * function: func_0218C9E8
 * address:  0x0218C9E8
 * packet:   pkt_ov021_0218C9E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_021DD9EC     0x021DD9EC  data  ov021  a4
 *   func_0218B754  0x0218B754  thumb
 *   func_021938AC  0x021938AC  thumb ov021
 *   func_021C05D4  0x021C05D4  thumb ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern void *func_02030734(int, int, int, void *, int);
extern int d_021DD9EC;
extern int func_0218B754(int a, void *p, int b);
extern int func_021938AC(int a);
extern int func_021C05D4(int a, int b);

char *func_0218C9E8(int heap, int b)
{
    char *p = func_02030734(heap, 0x74, 1, &d_021DD9EC, 0xf9);
    int z = 0;
    *(u16 *)p = heap;
    *(int *)(p + 0x34) = z;
    *(int *)(p + 0x38) = z;
    *(int *)(p + 0x3c) = z;
    *(u16 *)(p + 0x14) = z;
    *(u16 *)(p + 0x16) = z;
    *(int *)(p + 0x18) = z;
    *(int *)(p + 0x1c) = z;
    *(int *)(p + 4) = z;
    *(int *)(p + 8) = z;
    *(int *)(p + 0xc) = 1;
    *(int *)(p + 0x10) = -1;
    *(u8 *)(p + 0x40) = z;
    *(int *)(p + 0x68) = z;
    *(int *)(p + 0x64) = func_0218B754(*(u16 *)p, p, b);
    *(int *)(p + 0x6c) = func_021938AC(heap);
    *(int *)(p + 0x70) = func_021C05D4(0x10, (u8)heap);
    return p;
}
