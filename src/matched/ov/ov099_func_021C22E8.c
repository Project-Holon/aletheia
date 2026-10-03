/*
 * function: func_021C22E8
 * address: 0x021C22E8
 * packet: pkt_ov099_021C22E8
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_021BE4BC 0x021BE4BC thumb ov099
 *   func_021C285C 0x021C285C thumb ov099
 *   func_021BE3CC 0x021BE3CC thumb ov099
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
extern void *func_021C23B8(int);
extern u8 func_021BDD48(char *, void *);
extern int func_021BDD54(char *, void *);
extern void func_021BE4BC(char *, int, u8, u8, int, int, int);
extern int func_021C285C(void *);
extern void func_021BE3CC(char *, int, u8, u8, int, int);
typedef unsigned int   u32;
extern void func_02041B6C(u32 bit);
void func_021C22E8(char *p, int unused, int id, int flag, int x, int y)
{
    int offset;
    void *s;
    int kind;
    int value;
    int icon;
    offset = 0;
    if (flag != 0) offset = 16;
    s = func_021C23B8(id - 1);
    kind = func_021BDD48(p, s);
    value = func_021BDD54(p, s);
    func_021BE4BC(p + 0x898, 6, x + 2, y + 2, kind, value, offset);
    if (func_021C285C(s)) icon = 15;
    else icon = 11;
    func_021BE3CC(p + 0x898, 6, x + 12, y + 2, icon + offset, 0);
    func_02041B6C(7);
}
