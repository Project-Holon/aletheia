/*
 * unit: yes
 * function: func_021BAA54, func_021BAA84, func_021BAA98, func_021BAAA4, func_021BAAB0, func_021BAABC
 * address: 0x021BAA54
 * packet: pkt_ov181_021BAA54
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA594 0x021BA594 thumb ov181
 */
extern void func_021BA594(char *, unsigned char *);
int func_021BAA54(char *p, unsigned char *q)
{
    if (*(int *)(p + 0x2ec) == 0) {
        *(unsigned char *)(p + 0x2cd) = q[7];
        *(int *)(p + 0x2ec) = 2;
    }
    func_021BA594(p, q);
    if (q[0x16] != 1)
        return 1;
    return 0;
}
int func_021BAA84(char *p, unsigned char *q)
{
    *(unsigned char *)(p + 0x2cd) = q[7];
    *(int *)(p + 0x2ec) = 3;
    return 1;
}
int func_021BAA98(char *p)
{
    *(int *)(p + 0x2e0) = 1;
    return 0;
}
int func_021BAAA4(char *p)
{
    *(int *)(p + 0x2e0) = 0;
    return 0;
}
int func_021BAAB0(char *p)
{
    *(int *)(p + 0x2ec) = 5;
    return 1;
}
int func_021BAABC(void)
{
    return 1;
}
