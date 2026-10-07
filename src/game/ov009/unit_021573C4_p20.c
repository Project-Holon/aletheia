/*
 * file:     unit_021573C4_p20.c
 * unit:     yes
 * function: func_0215B584, func_0215B5C4, func_0215B644
 * address:  0x0215B584
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02150FEC  0x02150FEC  data
 *   func_0215B3A0  0x0215B3A0  arm  ov009
 *   func_02157E54  0x02157E54  arm  ov009
 *   func_02085A38  0x02085A38  arm
 *   func_020870D0  0x020870D0  arm
 *   g_021A826C  0x021A826C  data
 *   d_021A826C     0x021A826C  data
 *   func_02157290  0x02157290  arm
 */
typedef unsigned char u8;

extern unsigned long func_0215B3A0(unsigned char *buf, unsigned long len, unsigned char *buf2, unsigned long len2);
extern void func_02157E54(unsigned long ip);
extern void func_02085A38(unsigned long msec);
extern unsigned long long func_020870D0(void);
extern void func_02157290(int);
void func_0215B584(void);
int func_0215B5C4(void);
void func_0215B644(void);
extern char g_02150FEC[];
extern char g_021A826C[];
extern u8 d_021A826C[];


/*
 * sdk:      CPS_SocFlush (libcps.TWL.HYB.a(network.o))
 */
void func_0215B584(void)
{
    char *soc = *(char **)(*(char **)(g_02150FEC + 4) + 0xa4);

    if (soc != 0 && *(unsigned long *)(soc + 0x6c) != 0) {
        func_0215B3A0(*(unsigned char **)(soc + 0x68), *(unsigned long *)(soc + 0x6c), 0, 0);
        *(unsigned long *)(soc + 0x6c) = 0;
    }
}


/*
 * sdk:      garprequest (libcps.TWL.HYB.a(network.o))
 */
int func_0215B5C4(void)
{
    unsigned long start;

    func_02157E54(*(unsigned long *)(g_021A826C + 0x50));
    func_02085A38(100);
    func_02157E54(*(unsigned long *)(g_021A826C + 0x50));
    start = (unsigned long)(func_020870D0() >> 16);
    while ((*(int (**)(void))(g_021A826C + 0x18))() != 0 && (int)((unsigned long)(func_020870D0() >> 16) - start) < 0x17) {
        if (*(unsigned char *)(g_021A826C + 1) != 0)
            return 0;
        func_02085A38(100);
    }
    return 1;
}


/*
 * Addresses are Black-image addresses.
 */
void func_0215B644(void)
{
    ((void (*)(void))(*(unsigned int *)(d_021A826C + 0x28)))();
    if (*(unsigned int *)(d_021A826C + 0x50) == 0)
        return;
    if (func_0215B5C4() != 0)
        return;
    func_02157290(4);
}
