/*
 * file:     unit_021573C4_p27.c
 * unit:     yes
 * function: func_0215AD00, func_0215AD3C, func_0215ADC4, func_0215AE18, func_0215AEB0, func_0215AF14, func_0215B064
 * address:  0x0215AD00
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
 *   CPSi_SslShutdown                 0x02162dd8 arm
 *   CPSi_TcpShutdownRaw              0x0215aca0 arm
 *   OSi_ThreadInfo                   0x02150fec data
 *   func_02162E5C  0x02162E5C  arm  ov009
 *   func_020870D0  0x020870D0  arm
 *   func_02157390  0x02157390  arm  ov009
 *   g_02150FEC  0x02150FEC  data
 *   g_021A826C  0x021A826C  data
 *   func_02087988  0x02087988  arm
 *   func_020857B0  0x020857B0  arm
 *   func_0208799C  0x0208799C  arm
 *   func_02159404  0x02159404  arm  ov009
 *   func_020858D8  0x020858D8  arm
 *   func_021629BC  0x021629BC  arm  ov009
 *   OS_DisableInterrupts     0x02087988  arm
 *   MI_CpuMove               0x02083194  arm
 *   MI_CpuFill8              0x02082BCC  arm
 *   OS_Terminate             0x02088234  arm
 *   OS_RestoreInterrupts     0x0208799C  arm
 *   CPSi_SslConsume                  0x02162a94 arm
 *   CPSi_SocConsumeRaw               0x0215af14 arm
 */
struct CPSSoc;
struct soc;
struct _CPSSoc_0215AD00 {
	unsigned char pad[9];
	unsigned char ssl;
};

struct soc {
    char pad0[4];
    unsigned long state;
    char pad1[0x44];
    unsigned char *data;
    unsigned long len;
};

struct _CPSRwin {
	unsigned long start;
	unsigned long len;
	unsigned long pad;
};

struct _CPSSoc_0215AF14 {
	unsigned char pad0[8];
	unsigned char state;            /* 0x08 */
	unsigned char pad9[0x3f];
	unsigned long rcvbufsize;       /* 0x48 */
	unsigned char *rcvbuf;          /* 0x4c */
	unsigned long rcvlen;           /* 0x50 */
	unsigned char pad54[0x1c];
	struct _CPSRwin rwin[4];        /* 0x70 */
};

struct _CPSSoc_0215B064 {
	unsigned char pad[9];
	unsigned char ssl;
};

extern void CPSi_SslShutdown(struct _CPSSoc_0215AD00 *soc);
extern void CPSi_TcpShutdownRaw(struct _CPSSoc_0215AD00 *soc);
extern void func_02162E5C(void *soc);
extern unsigned long long func_020870D0(void);
extern void func_02157390(void);
extern unsigned long func_02087988(void);
extern void func_020857B0(void *queue);
extern unsigned long func_0208799C(unsigned long state);
extern void func_02159404(void *soc, int flush);
extern void func_020858D8(void);
extern unsigned char *func_021629BC(unsigned long *len, struct CPSSoc *soc);
extern unsigned long OS_DisableInterrupts(void);
extern void MI_CpuMove(void *srcp, void *destp, unsigned long size);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void OS_Terminate(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void CPSi_SslConsume(unsigned long len, struct _CPSSoc_0215B064 *soc);
extern void CPSi_SocConsumeRaw(unsigned long len, struct _CPSSoc_0215B064 *soc);
void CPS_TcpShutdown(void);
void func_0215AD3C(void);
unsigned char *func_0215ADC4(unsigned long *len, struct soc *soc);
unsigned char *func_0215AE18(unsigned long *len, char *soc);
unsigned char *func_0215AEB0(unsigned long *len);
void func_0215AF14(unsigned long len, struct _CPSSoc_0215AF14 *soc);
void CPS_SocConsume(unsigned long len);
extern int OSi_ThreadInfo;
extern char g_02150FEC[];
extern char g_021A826C[];


void CPS_TcpShutdown(void)
{
	struct _CPSSoc_0215AD00 *soc = *(struct _CPSSoc_0215AD00 **)((char *)*(unsigned long *)((char *)&OSi_ThreadInfo + 4) + 0xa4);

	if (soc == 0)
		return;
	if (soc->ssl != 0)
		CPSi_SslShutdown(soc);
	CPSi_TcpShutdownRaw(soc);
}


/*
 * sdk:      CPS_TcpClose (libcps.TWL.HYB.a(network.o))
 */
void func_0215AD3C(void)
{
    unsigned long start;
    char *soc = *(char **)(*(char **)(g_02150FEC + 4) + 0xa4);

    if (soc == 0)
        return;
    if (*(unsigned char *)(soc + 9) != 0)
        func_02162E5C(soc);
    start = (unsigned long)(func_020870D0() >> 16);
    while ((*(int (**)(void))(g_021A826C + 0x18))() != 0 && *(unsigned char *)(soc + 8) != 0 &&
           (int)((unsigned long)(func_020870D0() >> 16) - start) < 0x27)
        func_02157390();
    *(unsigned char *)(soc + 8) = 0;
}


/*
 * sdk:      udp_read_raw (libcps.TWL.HYB.a(network.o))
 */
unsigned char *func_0215ADC4(unsigned long *len, struct soc *soc)
{
    unsigned long tmp;
    unsigned long enable = func_02087988();

    tmp = soc->len;

    while (tmp == 0) {
        soc->state = 3;
        func_020857B0(0);
        tmp = soc->len;
    }
    func_0208799C(enable);
    *len = tmp;
    return soc->data;
}


/*
 * sdk:      CPSi_TcpReadRaw (libcps.TWL.HYB.a(network.o))
 */
unsigned char *func_0215AE18(unsigned long *len, char *soc)
{
    unsigned long enable;
    unsigned long n;

    if (*(unsigned char *)(soc + 8) == 4)
        func_02159404(soc, 1);
    if (*(unsigned long *)(soc + 0x50) == 0 && *(unsigned char *)(soc + 8) == 4) {
        enable = func_02087988();
        while (*(unsigned long *)(soc + 0x50) == 0 && *(unsigned char *)(soc + 8) == 4) {
            *(unsigned long *)(soc + 4) = 2;
            func_020857B0(0);
        }
        func_0208799C(enable);
    } else {
        func_020858D8();
    }
    n = *(unsigned long *)(soc + 0x50);
    *len = n;
    if (n != 0)
        return *(unsigned char **)(soc + 0x4c);
    return 0;
}


/*
 * sdk:      CPS_SocRead (libcps.TWL.HYB.a(network.o))
 */
unsigned char *func_0215AEB0(unsigned long *len)
{
    char *soc = *(char **)(*(char **)(g_02150FEC + 4) + 0xa4);

    if (soc != 0) {
        if (*(unsigned char *)(soc + 8) == 10 || *(unsigned char *)(soc + 8) == 11)
            return func_0215ADC4(len, (struct soc *)soc);
        if (*(unsigned char *)(soc + 9) != 0)
            return func_021629BC(len, (struct CPSSoc *)soc);
        return func_0215AE18(len, soc);
    }
    *len = 0;
    return 0;
}


/*
 * sdk:      CPSi_SocConsumeRaw (libcps.TWL.HYB.a network.o)
 */
void func_0215AF14(unsigned long len, struct _CPSSoc_0215AF14 *soc)
{
	unsigned char *d;
	unsigned char *s;
	unsigned long enabled;
	long ci;
	int was_full;
	unsigned long old;

	enabled = OS_DisableInterrupts();
	old = soc->rcvlen;
	was_full = 0;
	if (old == soc->rcvbufsize && len != 0)
		was_full = 1;
	if (len >= old) {
		soc->rcvlen = 0;
	} else {
		soc->rcvlen = old - len;
		MI_CpuMove(soc->rcvbuf + len, soc->rcvbuf, old - len);
	}
	if (soc->rwin[0].start != 0 && (old -= soc->rcvlen) != 0) {
		for (ci = 0; ci < 4 && soc->rwin[ci].start != 0; ci++)
			;
		if (soc->rwin[0].start > old) {
			s = soc->rcvbuf + soc->rwin[0].start;
			d = s - old;
			ci--;
			MI_CpuMove(s, d, soc->rwin[ci].start + soc->rwin[ci].len - soc->rwin[0].start);
			for (ci = 0; ci < 4 && soc->rwin[ci].start != 0; ci++)
				soc->rwin[ci].start -= old;
		} else {
			MI_CpuFill8(soc->rwin, 0, sizeof(soc->rwin));
			OS_Terminate();
		}
	}
	OS_RestoreInterrupts(enabled);
	if (soc->state != 0xa && soc->state != 0xb) {
		if (soc->rcvlen == 0 || was_full)
			func_02159404(soc, 0);
	}
}


void CPS_SocConsume(unsigned long len)
{
	struct _CPSSoc_0215B064 *soc = *(struct _CPSSoc_0215B064 **)((char *)*(unsigned long *)((char *)&OSi_ThreadInfo + 4) + 0xa4);

	if (soc == 0)
		return;
	if (soc->ssl != 0)
		CPSi_SslConsume(len, soc);
	else
		CPSi_SocConsumeRaw(len, soc);
}
