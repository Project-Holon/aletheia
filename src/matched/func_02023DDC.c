/*
 * function: func_02023DDC
 * address:  0x02023DDC
 * packet:   pkt_02023DDC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern void func_02023C3C(int a, int b, int c, int d, u32 e, u32 f);
extern void func_02030EAC(void *p);

void func_02023DDC(void *a0, short *a1)
{
    func_02023C3C(a1[0], a1[1], a1[2], a1[3],
                  *(u32 *)((char *)a1 + 8), *(u32 *)((char *)a1 + 0xc));
    func_02030EAC(a0);
}
