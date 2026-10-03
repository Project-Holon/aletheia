/*
 * function: func_022112AC
 * address: 0x022112AC
 * packet: pkt_ov198_022112AC
 * region: ov198
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02021ED8 0x02021ED8 thumb
 *   func_02211958 0x02211958 thumb ov198
 *   func_02210A4C 0x02210A4C thumb ov198
 *   func_02211970 0x02211970 thumb ov198
 *   func_0220B760 0x0220B760 thumb ov198
 *   func_02211190 0x02211190 thumb ov198
 *   func_022110F8 0x022110F8 thumb ov198
 *   func_022110E0 0x022110E0 thumb ov198
 *   func_0220E13C 0x0220E13C thumb ov198
 */
typedef unsigned char u8;
extern int func_02021ED8(void *);
extern unsigned func_02211958(u8 **);
extern int func_02210A4C(u8 *);
extern void func_02211970(u8 **, unsigned);
extern void func_0220B760(u8 *, unsigned);
extern int func_02211190(u8 *);
extern void func_022110F8(u8 *, unsigned, unsigned);
extern void func_022110E0(u8 **, unsigned, unsigned);
extern void func_0220E13C(u8 *);
int func_022112AC(u8 *p)
{
    if (func_02021ED8(*(void **)(p + 0x1d8)) != 0) return 8;
    if (func_02211958((u8 **)p) == 1) return 0x1f;
    if (func_02210A4C(p) == 1) {
        if ((*(u8 **)p)[0x20] == 6) {
            func_02211970((u8 **)p, 0x552);
            func_0220B760(p, 6);
            (*(u8 **)p)[0x20] = p[0x2498];
            *(unsigned *)(p + 0x217c) = 0xc;
            return 0x1d;
        }
        if ((*(u8 **)p)[0x20] == p[0x2498]) return 0xc;
        if (func_02211190(p) == 1) {
            func_022110F8(p, (*(u8 **)p)[0x20], p[0x2498]);
            func_022110E0((u8 **)p, (*(u8 **)p)[0x20], p[0x2498]);
            p[0x2499] = (*(u8 **)p)[0x20];
            p[0x249a] = p[0x2498];
            p[0x1e98] = 0;
            return 9;
        }
        func_0220E13C(p);
        *(unsigned *)(p + 0x217c) = 0xa;
        return 0x17;
    }
    return 8;
}
