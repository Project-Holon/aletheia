/*
 * function: func_0218E018
 * address:  0x0218E018
 * packet:   pkt_ov021_0218E018
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_021DDA28     0x021DDA28  data  ov021  a4
 *   func_02048B78  0x02048B78  arm
 *   func_02048B88  0x02048B88  arm
 *   func_0207D184  0x0207D184  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0218E18C  0x0218E18C  thumb ov021
 *   func_0218EEFC  0x0218EEFC  thumb ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern void *func_02030734(u16, int, int, void *, int);
extern int d_021DDA28;
extern int func_02048B78(int a);
extern void func_02048B88(int a, int *out);
extern u16 func_0207D184(int a);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_0218E18C(char *p, int a);
extern void func_0218EEFC(int a, int b, int c, u16 heap, char *p);

char *func_0218E018(int a0, int a1, int a2, int a3, u16 heap)
{
    int t;
    char *p = func_02030734(heap, 0x1b0, 1, &d_021DDA28, 0x80);
    *(int *)(p + 0x10) = a0;
    *(int *)(p + 0x14) = a1;
    *(int *)(p + 0xc) = a2;
    *(int *)(p + 0x20) = 0;
    *(u16 *)p = heap;
    *(int *)(p + 0x24) = 0;
    *(int *)(p + 0x28) = 0;
    *(int *)(p + 0x2c) = 0;
    *(int *)(p + 0x48) = 0;
    *(int *)(p + 0x4c) = 0;
    *(int *)(p + 0x50) = 0;
    *(int *)(p + 0x6c) = 0;
    *(int *)(p + 0x70) = 0;
    *(int *)(p + 0x74) = 0;
    *(int *)(p + 0x30) = 0;
    *(int *)(p + 0x34) = 0;
    *(int *)(p + 0x38) = 0;
    *(u16 *)(p + 0x7a) = 0;
    *(u16 *)(p + 0x78) = 0;
    *(int *)(p + 0x7c) = 0x78;
    *(u8 *)(p + 0xe9) = 1;
    if (func_02048B78(a2) == 0) {
        func_02048B88(a2, &t);
        *(u16 *)(p + 0x80) = func_0207D184(t);
    }
    *(int *)(p + 4) = func_020490F4(0x3c, *(u16 *)p);
    *(int *)(p + 8) = func_020490F4(0x6c, *(u16 *)p);
    *(u16 *)(p + 0xea) = 0xffff;
    func_0218E18C(p, a3);
    func_0218EEFC(7, 6, 2, heap, p);
    *(int *)(p + 0x1ac) = 0;
    return p;
}
