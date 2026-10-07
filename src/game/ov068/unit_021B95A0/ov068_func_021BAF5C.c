/*
 * function: func_021BAF5C
 * address:  0x021BAF5C
 * packet:   pkt_ov068_021BAF5C
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Byte-correct; blocked by two unwitnessed arm9 leaves (Ilias's):
 *   func_020083AC (bitfield read, verified EXACT: typedef struct { unsigned short a:7; unsigned short b:1; } S;
 *                  unsigned func_020083AC(S *p){ return p->b; })
 *   func_020083C8 (same with a:6, b:1; disasm ldrh; lsls #0x19; lsrs #0x1f)
 *
 * 2026-10-05: body byte-correct. Leaves 020083AC and 020083C8 are now filed
 * EXACT in src/matched/arm9/. Needs shard seeding by the integrator.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02008374  0x02008374  thumb
 *   func_020083AC  0x020083AC  thumb
 *   func_020083C8  0x020083C8  thumb
 *   func_02008390  0x02008390  thumb
 *   func_02008428  0x02008428  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02082BCC(void *p, u32 v, u32 n);
extern unsigned int func_02008374(int a0);
extern u32 func_020083AC(u32 a);
extern u32 func_020083C8(u32 a);
extern unsigned int func_02008390(char *a0);
extern int func_02008428(unsigned short *p);

void func_021BAF5C(u8 *p, short unsigned int *a)
{
    func_02082BCC(p, 0, 12);
    p[5] = 11;
    *(u32 *)(p + 8) = (u32)a;
    p[0] = func_02008374((int)a);
    p[1] = func_020083AC((u32)a);
    p[2] = func_020083C8((u32)a);
    p[3] = func_02008390((char *)a);
    p[4] = func_02008428(a);
}
