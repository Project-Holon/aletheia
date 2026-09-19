/*
 * function: func_02012E08
 * address:  0x02012E08
 * packet:   pkt_02012E08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  +0024 THM_CALL func_02034FE8       : 02034FE8 (arm, from name) has no witness outside 02012E08..02012E40
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_020351A0(int a);
extern void func_02010444(void);
extern void func_020071A8(u32 a);
extern int  func_02034FE8(u32 a);
extern void func_02034FB8(u32 a);

void func_02012E08(char *p)
{
    u32 x;

    if (*(u8 *)(p + 0x1CE) != 1)
        return;
    func_020351A0(2);
    func_02010444();
    *(u8 *)(p + 0x1CE) = 0;
    func_020071A8(*(u32 *)p);
    x = 0x80;
    if (func_02034FE8(x) == 1)
        func_02034FB8(x);
}
