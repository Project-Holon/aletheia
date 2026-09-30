/*
 * function: func_021C1908
 * address: 0x021C1908
 * packet: pkt_ov099_021C1908
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 94 bytes code, then two zero alignment bytes before 021C1968.
 * symbols:
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_021BDE30 0x021BDE30 thumb ov099
 *   func_021C27D4 0x021C27D4 thumb ov099
 *   func_021C27DC 0x021C27DC thumb ov099
 *   func_021C24A4 0x021C24A4 thumb ov099
 *   func_021BAEDC 0x021BAEDC thumb ov099
 */
typedef unsigned char u8;
extern u8 func_021BDD48(char *, void *);
extern int func_021BDD54(char *, void *);
extern void func_021BDE30(void *, int, int);
extern void func_021C27D4(void *, u8);
extern void func_021C27DC(void *, u8);
extern void func_021C24A4(char *, int);
extern void func_021BAEDC(char *);
void func_021C1908(char *p, int kind, int value)
{
    int old;
    int oldvalue;
    if (*(void **)(p + 8) != 0) {
        old = func_021BDD48(p, *(void **)(p + 8));
        oldvalue = func_021BDD54(p, *(void **)(p + 8));
        if (old != kind || oldvalue != value) {
            func_021BDE30(p, kind, value);
            func_021C27D4(*(void **)(p + 8), kind);
            func_021C27DC(*(void **)(p + 8), value);
            if (!(value == 5 && kind == 4)) {
                if (kind != 4) func_021C24A4(p, 127);
            }
        }
        func_021BAEDC(p);
    }
}
