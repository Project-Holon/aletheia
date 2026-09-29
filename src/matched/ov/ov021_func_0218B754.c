/*
 * function: func_0218B754
 * address:  0x0218B754
 * packet:   pkt_ov021_0218B754
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates and initialises a 0x13F8-byte object.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_021DD9CC     0x021DD9CC  data  ov021  a4
 *   func_0218BCE4  0x0218BCE4  thumb
 *   func_0218C490  0x0218C490  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern void *func_02030734(int, int, int, void *, int);
extern int d_021DD9CC;
extern void func_0218BCE4(char *p, u8 a);
extern void func_0218C490(char *p, char *q);

char *func_0218B754(int a, int b, u16 c)
{
    char *p;
    int i;
    unsigned j;
    int z = 0;

    p = (char *)func_02030734(a, 0x13F8, 0, &d_021DD9CC, 0x193);
    *(u16 *)p = a;
    *(int *)(p + 4) = b;
    func_0218BCE4(p + 8, c);
    for (i = 0; i < 7; i++)
        *(int *)(p + 0x1DC + i * 4) = z;
    for (j = 0; j < 0x120; j++)
        func_0218C490(p, p + 0x1F8 + j * 16);
    *(int *)(p + 0x1B0) = 0;
    *(int *)(p + 0x1B4) = 0;
    *(int *)(p + 0x1B8) = 0;
    *(int *)(p + 0x1BC) = 0;
    *(int *)(p + 0x1C0) = 0;
    *(int *)(p + 0x1C4) = 0;
    *(int *)(p + 0x1C8) = 0;
    *(int *)(p + 0x1CC) = 0;
    *(int *)(p + 0x1D4) = 0;
    *(int *)(p + 0x1D8) = 0;
    return p;
}
