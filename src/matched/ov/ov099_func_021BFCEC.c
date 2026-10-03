/*
 * function: func_021BFCEC
 * address: 0x021BFCEC
 * packet: pkt_ov099_021BFCEC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BFBBC 0x021BFBBC thumb ov099
 *   func_021BA858 0x021BA858 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_0201FEF4 0x0201FEF4 thumb
 *   func_02156A3C 0x02156A3C thumb ov009
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021BAADC 0x021BAADC thumb ov099
 */
typedef unsigned char u8;
extern void func_021BFBBC(char *);
typedef unsigned int   u32;
extern u32 func_021BA858(char *p);
extern void func_021BA8EC(char *);
extern void func_0201FEF4(u8 *o);
extern int func_02156A3C(void);
extern void func_021BA874(char *, int);
extern void func_021BAAB8(char *, int, int);
extern void func_021BAADC(char *, int, int);
int func_021BFCEC(char *p, int ret)
{
    int v;
    func_021BFBBC(p);
    v = func_021BA858(p);
    if (v == -1) {
        if (*(u8 *)(p + 0x1355)) {
            func_021BA8EC(p);
            func_0201FEF4(*(void **)(p + 0x108));
            *(void **)(p + 0x108) = 0;
            func_021BA874(p, func_02156A3C());
            func_021BAAB8(p, 0x10, 0);
            *(int *)(p + 0x1e0) = 0x3c;
            *(int *)(p + 0x1cc) = 0x94;
        }
    } else if (v == 0) {
        *(int *)(p + 0x1cc) = 0x92;
    } else {
        func_021BAADC(p, 0x7b, 0);
        *(int *)(p + 0x1cc) = 0x10;
    }
    return ret;
}
