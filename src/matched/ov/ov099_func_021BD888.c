/*
 * unit: yes
 * function: func_021BD888, func_021BD8C0
 * address: 0x021BD888
 * packet: pkt_ov099_021BD888
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201DD68 0x0201DD68 thumb
 *   func_021BA858 0x021BA858 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 */
extern void func_0201DD68(void);
extern int func_021BA858(char *);
extern void func_021BA8EC(char *);
int func_021BD888(char *p, int v)
{
    int t;
    func_0201DD68();
    t = func_021BA858(p);
    if (t == -1) return v;
    if (t == 0) {
        *(int *)(p + 0x1cc) = 0x80;
    } else {
        *(int *)(p + 0x1cc) = 0x86;
    }
    func_021BA8EC(p);
    return v;
}
int func_021BD8C0(char *p, int v)
{
    *(unsigned char *)(p + 0x1353) = 0x4a;
    *(int *)(p + 0x1cc) = 0x8a;
    return v;
}
