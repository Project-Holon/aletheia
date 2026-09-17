/*
 * unit:     no
 * function: func_02061158
 * address:  0x02061158
 * packet:   pkt_02060CD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  020610A0, 020610B4 has no witness outside this range
 */

extern void func_020610A0(void *p);
extern void func_020610B4(void *p);
void func_02061158(void *p, int flags)
{
    if (flags & 1)
        func_020610A0(p);
    if (flags & 2)
        func_020610B4(p);
}
