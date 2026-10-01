/*
 * function: func_021F9EDC
 * address: 0x021F9EDC
 * packet: pkt_ov132_021F9EDC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02050C04 0x02050C04 arm
 *   func_0205121C 0x0205121C arm
 *   func_020056BC 0x020056BC thumb
 *   func_02051230 0x02051230 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_02050C04(char *, unsigned, unsigned, unsigned);
extern void *func_0205121C(unsigned, unsigned, unsigned);
extern unsigned func_020056BC(void);
extern void func_02051230(void *, void *, unsigned, unsigned);
char *func_021F9EDC(char *p, u16 a)
{
    char *q = 0;
    void *v;
    u8 i;
    u8 j;
    for (i = 0; i < 8; i++) if (*(int *)(p + i * 0x4848 + 4) == 0) q = (p + 4) + i * 0x4848;
    j = 0;
    *(void **)(q + 0x4804) = func_02050C04(q + 4, 0x4800, 0, *(u16 *)p);
    v = func_0205121C(47, a, *(u16 *)p);
    func_02051230(*(void **)(q + 0x4804), v, 0, func_020056BC());
    for (; j < 4; j++) *(int *)(q + j * 16 + 0x4808) = 0;
    *(int *)q = 1;
    return q;
}
