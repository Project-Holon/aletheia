/*
 * unit: yes
 * function: func_021DEEAC, func_021DEEBC, func_021DEEC0, func_021DEEC4, func_021DEED0, func_021DEED8, func_021DEEEC
 * address: 0x021DEEAC
 * packet: pkt_ov121_021DEEAC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021DFC00 0x021DFC00 data a4
 */
extern int d_021DFC00[];
void func_021DEEEC(void);
int func_021DEEAC(int *p, int value)
{
    return *p == value;
}
void *func_021DEEBC(char *p)
{
    return p + 0x14;
}
int func_021DEEC0(void)
{
    return 0x20;
}
int func_021DEEC4(int a, int b)
{
    return a == b;
}
void func_021DEED0(char *p)
{
    *(int *)(p + 0x5c) = 1;
}
void func_021DEED8(int a, int b)
{
    d_021DFC00[1] = 1;
    d_021DFC00[3] = b;
    func_021DEEEC();
}
void func_021DEEEC(void)
{
    d_021DFC00[0] = 1;
}
