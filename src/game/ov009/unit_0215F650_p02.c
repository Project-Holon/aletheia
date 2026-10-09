/*
 * file:     unit_0215F650_p02.c
 * unit:     yes
 * function: SOC_InetNtoA, func_0215FAD0, func_0215FB28, func_0215FBAC, func_0215FBCC
 * address:  0x0215FA9C
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
 *   _ZZ12SOC_InetNtoA9SOCInAddrE6buffer   0x021aa4ec data
 *   func_0215EE98  0x0215EE98  arm  ov009
 *   MI_CpuCopy8      0x02082d44 arm
 *   SOC_U32to4U8     0x0215fbac arm
 *   OS_SNPrintf      0x02084f80 arm
 *   g_021A1D2C       0x021a1d2c data
 *   func_0215EFB0  0x0215EFB0  arm  ov009
 *   func_02085A38  0x02085A38  arm
 */
struct SOCInAddr {
    unsigned long addr;
};

typedef struct {
	int fd;
	short events;
	short revents;
} PollFD;

extern unsigned long func_0215EE98(char *hostname);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void SOC_U32to4U8(unsigned long adr_u32, unsigned char *adr_4u8);
extern int OS_SNPrintf(char *dst, unsigned long len, char *fmt, ...);
extern int func_0215EFB0(int s);
extern void func_02085A38(unsigned long msec);
/* * sdk: SOC_InetAtoN (libsoc.TWL.HYB.a(soc.o)) */ int func_0215FAD0(char *cp, unsigned long *inp);
char *SOC_InetNtoP(int af, void *src, char *dst, unsigned int len);
/* * Writes a word big-endian into four bytes. */ void func_0215FBAC(unsigned v, unsigned char *p);
/* * sdk: SOC_Poll (libsoc.TWL.HYB.a(soc.o)) */ int func_0215FBCC(PollFD *fds, unsigned int nfds, long long timeout);
extern char _ZZ12SOC_InetNtoA9SOCInAddrE6buffer[16];
extern char g_021A1D2C[];


char *SOC_InetNtoA(struct SOCInAddr in)
{
    SOC_InetNtoP(2, &in, _ZZ12SOC_InetNtoA9SOCInAddrE6buffer, 16);
    return _ZZ12SOC_InetNtoA9SOCInAddrE6buffer;
}

#define SWAP32(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))



/*
 * sdk:      SOC_InetAtoN (libsoc.TWL.HYB.a(soc.o))
 */
int func_0215FAD0(char *cp, unsigned long *inp)
{
	unsigned long h;

	h = func_0215EE98(cp);
	if (h == 0) {
		return 0;
	}
	if (inp != 0) {
		*inp = SWAP32(h);
	}
	return 1;
}



char *SOC_InetNtoP(int af, void *src, char *dst, unsigned int len)
{
    unsigned long addr32;
    unsigned char addr[4];

    if (af != 2)
        return 0;
    if (len < 0x10)
        return 0;
    MI_CpuCopy8(src, &addr32, 4);
    SOC_U32to4U8(addr32, addr);
    OS_SNPrintf(dst, 16, g_021A1D2C, addr[3], addr[2], addr[1], addr[0]);
    return dst;
}


/*
 * Writes a word big-endian into four bytes.
 */
void func_0215FBAC(unsigned v, unsigned char *p)
{
    p[0] = (unsigned char)(v >> 24);
    p[1] = (unsigned char)(v >> 16);
    p[2] = (unsigned char)(v >> 8);
    p[3] = (unsigned char)v;
}



/*
 * sdk:      SOC_Poll (libsoc.TWL.HYB.a(soc.o))
 */
int func_0215FBCC(PollFD *fds, unsigned int nfds, long long timeout)
{
	PollFD *fp;
	int is_enable_timeout;
	long long time;
	unsigned int i;
	int num_good;
	int status;
	int status_mask;

	if (nfds == 0 || fds == 0) {
		return 0;
	}
	time = timeout;
	is_enable_timeout = (time != -1);
	for (;;) {
		num_good = 0;
		fp = fds;
		for (i = 0; i < nfds; i++, fp++) {
			status_mask = fp->events | 0xe0;
			status = status_mask & func_0215EFB0(fp->fd);
			fp->revents = (short)status;
			if (status) {
				num_good++;
			}
		}
		if (num_good > 0) {
			break;
		}
		if (is_enable_timeout && time <= 0) {
			break;
		}
		func_02085A38(1);
		time -= 523;
	}
	return num_good;
}
