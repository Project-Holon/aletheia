/*
 * function: func_021E1A28
 * address:  0x021E1A28
 * packet:   pkt_ov170_021E1A28
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020260E0 0x020260E0 thumb
 *   func_021EE008 0x021EE008 thumb
 *   func_021EDF5C 0x021EDF5C thumb
 *   func_021EDD38 0x021EDD38 thumb
 */

typedef struct {
    unsigned char pad[0xE];
    unsigned short fE;
} Blk;

extern unsigned char func_020260E0(void *obj);
extern void func_021EE008(char *p, int a, int b);
extern void func_021EDF5C(char *p);
extern void func_021EDD38(char *p, int d);

int func_021E1A28(char *p)
{
    Blk *b = (Blk *)(*(char **)(p + 0x2C) + 0x58);
    if (b->fE == 5) {
        unsigned r = func_020260E0(*(void **)(*(char **)(p + 0x2C) + 0x70));
        if (r >= 0x22 && r <= 0x25)
            func_021EE008(p, r - 0x22, 1);
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
