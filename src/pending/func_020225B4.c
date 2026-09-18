/*
 * function: func_020225B4
 * address:  0x020225B4
 * packet:   pkt_02022490
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 *
 * Blocked: 02022490 (thumb, from name) has no witness outside 020225B4..020225D4. Every concrete byte reproduces.
 * status:   MATCH
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02022490(u8 *o, u32 a, u32 b, u32 i);
extern void func_02030EAC(void *p);
extern void func_020307B0(void *ptr);

void func_020225B4(void *a, u32 *p)
{
    func_02022490((u8 *)p[0], p[1], p[2], p[3]);
    func_02030EAC(a);
    func_020307B0(p);
}
