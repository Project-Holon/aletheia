/*
 * function: func_0206AE2C
 * address:  0x0206AE2C
 * packet:   pkt_0206AA78
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF (SIZE), 112 compiled against 104: the 0x40-byte stack buffer, the two accessor results and the four pool words are all recognisable but the argument shuffle and the frame differ throughout.  Not a near miss - the reconstruction is short of the original's shape; parked for the next pass
 *
 * symbols:
 *   g_02148B4C       0x02148B4C  data
 *   g_02148D4C       0x02148D4C  data
 *   func_0206AAD4    0x0206AAD4  arm
 *   func_0206AD20    0x0206AD20  arm
 *   func_0207B5C0    0x0207B5C0  arm
 *   func_0207BE14    0x0207BE14  arm
 *
 * Lazy initialiser for the 0x40 sub-object: two accessors produce the two
 * arguments, each is loaded in through its own call and a 0x40-byte stack
 * buffer, and the "built" bit is the 0x40 mask of the flags word at
 * 0x02148B4C + 0xFC.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0206AE2C.c \
 *       --func func_0206AE2C --addr 0x0206AE2C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32   g_02148B4C[];
extern char *g_02148D4C;
extern void *func_0206AAD4(void);
extern void *func_0206AD20(void);
extern void  func_0207B5C0(void *a, void *buf);
extern void  func_0207BE14(void *a, void *buf, void *tbl);

char *func_0206AE2C(void)
{
    u8 buf[0x40];
    void *a;
    void *b;

    if ((g_02148B4C[63] & 0x40) == 0) {
        a = func_0206AAD4();
        b = func_0206AD20();
        func_0207B5C0(a, buf);
        func_0207BE14(b, buf, g_02148D4C);
        g_02148B4C[63] |= 0x40;
    }
    return g_02148D4C;
}
