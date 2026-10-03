/*
 * function: func_021DBD3C
 * address: 0x021DBD3C
 * packet: pkt_ov119_021DBD3C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E665C 0x021E665C thumb ov119
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DBC98 0x021DBC98 thumb ov119
 *   func_021DBC3C 0x021DBC3C thumb ov119
 */
extern int func_021E665C(char *p);
extern int func_021D8A24(void *);
extern void func_021D8E84(void *, int);
extern void func_021DBC98(char *p);
extern void func_021DBC3C(char *p);
void func_021DBD3C(char *p)
{
    if (func_021E665C(p)) {
        if (func_021D8A24(p)) {
            func_021D8E84(p, (int)func_021DBC98);
            return;
        }
        func_021D8E84(p, (int)func_021DBC3C);
    }
}
