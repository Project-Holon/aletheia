/*
 * function: func_020189D8
 * address:  0x020189D8
 * packet:   pkt_020189D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  +0012 THM_CALL func_020189F0       : 020189F0 (thumb, from name) has no witness outside 020189D8..020189F0
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int func_02017E88(int a0, int a1, int a2);
extern void func_020189F0(int a0, u32 a1);

void func_020189D8(int a0, u32 a1)
{
    func_020189F0((u8)func_02017E88(a0, 0x70, 0), a1);
}
