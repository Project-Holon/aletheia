/*
 * function: func_021BD5FC
 * address: 0x021BD5FC
 * packet: pkt_ov099_021BD5FC
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
extern int func_021BA858(void *);
extern void func_021BA8EC(void *);
int func_021BD5FC(char *p, int ret)
{
    int v;
    func_0201DD68();
    v = func_021BA858(p);
    if (v == -1) return ret;
    if (v == 0) p[0x1353] = 0x44;
    else p[0x1353] = 0x4a;
    func_021BA8EC(p);
    *(int *)(p + 0x1cc) = 0x8a;
    return ret;
}
