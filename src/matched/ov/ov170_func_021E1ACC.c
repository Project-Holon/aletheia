/*
 * function: func_021E1ACC
 * address: 0x021E1ACC
 * packet: pkt_ov170_021E1ACC
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020260E0 0x020260E0 thumb
 *   func_021EE008 0x021EE008 thumb ov170
 *   func_021EDF5C 0x021EDF5C thumb ov170
 *   func_021EDD38 0x021EDD38 thumb ov170
 */
typedef struct { unsigned char pad[0xE]; unsigned short fE; } Blk;
extern unsigned char func_020260E0(void *);
extern void func_021EE008(char *, int, int);
extern void func_021EDF5C(char *);
extern void func_021EDD38(char *, int);
int func_021E1ACC(char *p)
{
    Blk *b = (Blk *)(*(char **)(p + 0x2C) + 0x58);
    if (b->fE == 5) {
        unsigned r = func_020260E0(*(void **)(*(char **)(p + 0x2C) + 0x70));
        if (r >= 1 && r <= 4)
            func_021EE008(p, r - 1, 1);
        else
            func_021EE008(p, 0, 0);
        func_021EDF5C(p);
        b->fE = 0;
        return 0;
    }
    b->fE++;
    func_021EDD38(p, (short)b->fE);
    return 1;
}
