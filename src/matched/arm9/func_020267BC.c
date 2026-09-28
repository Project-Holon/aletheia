/*
 * function: func_020267BC
 * address:  0x020267BC
 * packet:   pkt_020266E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  02026D88 label
 *
 * symbols:
 *   g_02146940     0x02146940  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern u32 *g_02146940;

extern void func_02026D88(u32 *p, u32 a0);
extern void func_02012FCC(u32 a0);
extern u32  func_0200864C(void);

void func_020267BC(u32 a0)
{
    u32 *p = g_02146940;

    *p++ = a0;
    func_02026D88(p, a0);
    func_02012FCC(a0);
    *(u16 *)((char *)g_02146940 + 0xbb0) = (u16)func_0200864C();
}
