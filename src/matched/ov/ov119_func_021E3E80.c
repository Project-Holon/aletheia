/*
 * function: func_021E3E80
 * address: 0x021E3E80
 * packet: pkt_ov119_021E3E80
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 */
extern void *func_020490F4(unsigned int, unsigned int);
extern int func_021D8AA8(void *);
extern void func_02049B68(void *, int, int, int, int, unsigned int);
extern int func_02049740(void *, int, int, int, int, unsigned int);
extern void func_02049990(void *, unsigned int, int, int, unsigned short, int, int, unsigned int);
extern void func_02049238(void *);
void func_021E3E80(char *p)
{
    void *v;
    int kind;
    int mode;
    v = func_020490F4(0x66, *(unsigned short *)(p + 0x5F4));
    mode = func_021D8AA8(p);
    kind = 4;
    if (mode == 0)
        kind = 11;
    func_02049B68(v, 9, 0, 0, 0, *(unsigned short *)(p + 0x5F4));
    if (*(int *)(p + 0x86C) == 0)
        *(int *)(p + 0x86C) = func_02049740(v, 10, 2, 0, 0, *(unsigned short *)(p + 0x5F4));
    func_02049990(v, kind, 2, 0, *(unsigned int *)(p + 0x86C), 0, 0, *(unsigned short *)(p + 0x5F4));
    func_02049238(v);
}
