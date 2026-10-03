/*
 * unit: yes
 * function: func_021C6BF0, func_021C6C28
 * address: 0x021C6BF0
 * packet: pkt_ov136_021C6BF0
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02031330 0x02031330 arm
 *   d_021C7D7C 0x021C7D7C data a4
 *   func_021C714C 0x021C714C thumb ov136
 */
typedef unsigned char u8;
struct Row { int (*call)(u8 *); int result; int other; };
extern const struct Row d_021C7D7C[];
typedef unsigned int   u32;
extern unsigned int func_02031330(void *p);
extern int func_021C714C(u8 *p, u32 v);
int func_021C6BF0(u8 *p)
{
    if (func_02031330(*(void **)(p + 0x30)) == 1) return 7;
    *(int *)(p + 0x28) = d_021C7D7C[*(int *)(p + 0x14)].call(p);
    return d_021C7D7C[*(int *)(p + 0x14)].result;
}
int func_021C6C28(u8 *p)
{
    return func_021C714C(p, 9);
}
