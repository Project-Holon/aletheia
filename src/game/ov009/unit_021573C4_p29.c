/*
 * file:     unit_021573C4_p29.c
 * unit:     yes
 * function: func_0215B470, func_0215B504, func_0215B584, func_0215B5C4, func_0215B644
 * address:  0x0215B470
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
 *   func_0215B3A0  0x0215B3A0  arm  ov009
 *   func_02083194  0x02083194  arm
 *   g_02150FEC  0x02150FEC  data
 *   func_02159404  0x02159404  arm  ov009
 *   func_02162C28  0x02162C28  arm  ov009
 *   func_02157E54  0x02157E54  arm  ov009
 *   func_02085A38  0x02085A38  arm
 *   func_020870D0  0x020870D0  arm
 *   g_021A826C  0x021A826C  data
 *   d_021A826C     0x021A826C  data
 *   func_02157290  0x02157290  arm
 */
struct CPSSoc;
typedef unsigned char u8;

extern unsigned long func_0215B3A0(unsigned char *buf, unsigned long len, unsigned char *buf2, unsigned long len2);
extern void func_02083194(void *src, void *dst, unsigned long size);
extern void func_02159404(void *soc, int flush);
extern long func_02162C28(struct CPSSoc *soc);
extern void func_02157E54(unsigned long ip);
extern void func_02085A38(unsigned long msec);
extern unsigned long long func_020870D0(void);
extern void func_02157290(int);
/* * sdk: CPS_SocWrite (libcps.TWL.HYB.a(network.o)) */ unsigned long func_0215B470(unsigned char *buf, unsigned long len);
/* * sdk: CPS_SocGetLength (libcps.TWL.HYB.a(network.o)) */ long func_0215B504(void);
/* * sdk: CPS_SocFlush (libcps.TWL.HYB.a(network.o)) */ void func_0215B584(void);
/* * sdk: garprequest (libcps.TWL.HYB.a(network.o)) */ int func_0215B5C4(void);
/* * Addresses are Black-image addresses. */ void func_0215B644(void);
extern char g_02150FEC[];
extern char g_021A826C[];
extern u8 d_021A826C[];



/*
 * sdk:      CPS_SocWrite (libcps.TWL.HYB.a(network.o))
 */
unsigned long func_0215B470(unsigned char *buf, unsigned long len)
{
    char *soc = *(char **)(*(char **)(g_02150FEC + 4) + 0xa4);
    unsigned long pend;
    unsigned long n;
    unsigned long left;

    if (soc != 0) {
        pend = *(unsigned long *)(soc + 0x6c);
        if (pend != 0) {
            n = func_0215B3A0(*(unsigned char **)(soc + 0x68), pend, buf, len);
            left = *(unsigned long *)(soc + 0x6c);
            if (n >= left) {
                *(unsigned long *)(soc + 0x6c) = 0;
                return n - left;
            }
            func_02083194(*(unsigned char **)(soc + 0x68) + n, *(unsigned char **)(soc + 0x68), left - n);
            *(unsigned long *)(soc + 0x6c) = *(unsigned long *)(soc + 0x6c) - n;
            return 0;
        }
        return func_0215B3A0(buf, len, 0, 0);
    }
    return 0;
}



/*
 * sdk:      CPS_SocGetLength (libcps.TWL.HYB.a(network.o))
 */
long func_0215B504(void)
{
    long count;
    char *soc = *(char **)(*(char **)(g_02150FEC + 4) + 0xa4);

    if (soc != 0) {
        if (*(unsigned char *)(soc + 8) == 4)
            func_02159404(soc, 1);
        if (*(unsigned char *)(soc + 9) != 0)
            return func_02162C28((struct CPSSoc *)soc);
        count = *(long *)(soc + 0x50);
        if (count != 0)
            return count;
        if (*(unsigned char *)(soc + 8) == 4)
            return count;
        if (*(unsigned char *)(soc + 8) == 10 || *(unsigned char *)(soc + 8) == 11)
            return count;
        return -1;
    }
    return 0;
}



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
