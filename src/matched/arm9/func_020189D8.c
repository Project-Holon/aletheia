/*
 * function: func_020189D8
 * address:  0x020189D8
 * packet:   pkt_020189D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  +0012 THM_CALL func_020189F0       : 020189F0 (thumb, from name) has no witness outside 020189D8..020189F0
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef signed char    s8;
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern s8 func_020189F0(u8 nature, u32 stat);

void func_020189D8(void *m, u32 a1)
{
    func_020189F0((u8)func_02017E88(m, 0x70, 0), a1);
}
