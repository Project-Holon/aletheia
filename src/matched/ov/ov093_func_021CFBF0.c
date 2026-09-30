/*
 * function: func_021CFBF0
 * address: 0x021CFBF0
 * packet: pkt_ov093_021CFBF0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021CF8D4 0x021CF8D4 thumb ov093
 *   func_021B9B98 0x021B9B98 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021B8D8C 0x021B8D8C thumb ov093
 *   func_021CFD50 0x021CFD50 thumb ov093
 *   func_021D6C24 0x021D6C24 thumb ov093
 *   func_021B937C 0x021B937C thumb ov093
 *   func_021CFDCC 0x021CFDCC thumb ov093
 *   func_021CFE08 0x021CFE08 thumb ov093
 *   func_021CFE98 0x021CFE98 thumb ov093
 *   func_021CFFAC 0x021CFFAC thumb ov093
 *   func_021D0100 0x021D0100 thumb ov093
 *   func_021D0248 0x021D0248 thumb ov093
 *   func_021D0304 0x021D0304 thumb ov093
 *   func_021D0980 0x021D0980 thumb ov093
 *   func_021D09E0 0x021D09E0 thumb ov093
 *   func_021CFBBC 0x021CFBBC thumb ov093
 *   func_021CFBE0 0x021CFBE0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_021CF8D4(u8 *, void *, u8 *, u16 *);
extern u8 func_021B9B98(void *);
extern u8 func_021D5440(int);
extern int func_021B8D8C(void *, void *, u32);
extern int func_021CFD50(void *, int);
extern int func_021D6C24(int);
extern int func_021B937C(int, char *, int);
extern int func_021CFDCC(void *, int);
extern int func_021CFE08(void *, int, int);
extern int func_021CFE98(void *, int, int);
extern int func_021CFFAC(void *, int, int);
extern int func_021D0100(void *, int, int, u8 *);
extern int func_021D0248(void *, int, u8 *);
extern int func_021D0304(void *, int, int, u8 *);
extern u8 func_021D0980(u8 *, u8 *);
extern void func_021D09E0(void *, u8 *, u8, int);
extern int func_021CFBBC(void *, u8);
extern void func_021CFBE0(void *, u32, u8);
int func_021CFBF0(u8 *g, int m, u32 slot, u8 *out)
{
    u8 choice;
    u8 id;
    u16 k;
    u8 buf[6];
    int q;
    u32 n;
    u32 i;
    u8 ok;
    choice = 6;
    if (func_021CF8D4(g, (void *)m, &id, &k) != 4) return 0;
    if (func_021B9B98(*(void **)(g + 0x118)) <= g[0x11c]) return 0;
    q = func_021CFD50(g, func_021B8D8C(*(void **)g, *(void **)(g + 4), func_021D5440(m)));
    if (!q) return 0;
    if (func_021D6C24(q))
        q = func_021B937C(*(int *)g, *(char **)(g + 4), q);
    if (func_021CFDCC(g, m)) ok = 1;
    else if (func_021CFE08(g, m, q)) ok = 1;
    else if (func_021CFE98(g, m, q)) ok = 1;
    else if (func_021CFFAC(g, m, q)) ok = 1;
    else if (func_021D0100(g, m, q, &choice)) ok = 1;
    else if (func_021D0248(g, m, &choice)) ok = 1;
    else if (func_021D0304(g, m, q, &choice)) ok = 1;
    else return 0;
    if (!ok) return 0;
    if (choice == 6) {
        n = func_021D0980(g, buf);
        func_021D09E0(g, buf, n, q);
        for (i = 0; i < n; i++) {
            if (!func_021CFBBC(g, buf[i])) {
                choice = buf[i];
                break;
            }
        }
    }
    if (choice == 6) return 0;
    func_021CFBE0(g, slot, choice);
    *out = choice;
    return 1;
}
