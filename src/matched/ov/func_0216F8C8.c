/*
 * function: func_0216F8C8
 * address:  0x0216F8C8
 * packet:   pkt_0216F8C8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocked:  
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_021F385C  0x021F385C  thumb  ov059
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5DC(int);
extern u32 func_0201210C(void *);
extern void func_021F385C(void *);

int func_0216F8C8(int a0, int a1)
{
    func_021F385C((void *)func_0201210C((void *)func_0215A5DC(a1)));
    return 0;
}
