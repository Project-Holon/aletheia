/*
 * unit: yes
 * function: func_02167AC4, func_02167AF0, func_02167AF4
 * address: 0x02167AC4
 * packet: pkt_ov010_02167AC4
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Trailing unlabelled constant getter and equality predicate are included.
 * symbols:
 *   func_02012944 0x02012944 thumb
 *   func_02008494 0x02008494 thumb
 *   func_02087C6C 0x02087C6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *func_02012944(void *p);
extern void func_02008494(void *, void *);
extern void func_02087C6C(void *);
void *func_02167AC4(u8 *p)
{
    u8 *q;
    q = p + 0x6f4;
    func_02008494(func_02012944(*(void **)(p + 0x6c)), q);
    func_02087C6C(q + 0x20);
    *(u16 *)(q + 0x26) = 0x3a0b;
    return q;
}
int func_02167AF0(void)
{
    return 0x28;
}
int func_02167AF4(int a, int b)
{
    if (a == b) return 1;
    return 0;
}
