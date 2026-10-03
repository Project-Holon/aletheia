/*
 * function: func_021FB704
 * address: 0x021FB704
 * packet: pkt_ov186_021FB704
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: initialize total after assertions; declare i before total for r0/r1.
 * symbols:
 *   func_02034714 0x02034714 arm
 *   d_022007F0 0x022007F0 data a4
 *   d_02200D38 0x02200D38 data a1
 */
extern const unsigned short d_022007F0[][6];
extern char d_02200D38[];
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
void *func_021FB704(char *ctx, int section, unsigned item)
{
    int i;
    int total;
    if (section >= 12) func_02034714(d_02200D38, 0, d_02200D38);
    if (item >= d_022007F0[section][0]) func_02034714(d_02200D38, 0, d_02200D38);
    total = 0;
    for (i = 0; i < section; i++) total += d_022007F0[i][0];
    return ctx + 4 + (total + item) * 24;
}
