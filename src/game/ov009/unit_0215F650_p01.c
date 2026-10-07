/*
 * file:     unit_0215F650_p01.c
 * unit:     yes
 * function: func_0215F650, func_0215F714, func_0215F7B0, func_0215F7E8, func_0215F854, func_0215F8A4
 * address:  0x0215F650
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
 *   func_0215EDD0  0x0215EDD0  arm  ov009
 *   func_02082BCC  0x02082BCC  arm
 *   func_0208CB10  0x0208CB10  arm
 *   g_021AA544     0x021AA544  data
 *   g_021AA4BC     0x021AA4BC  data
 *   g_021AA4BC_ip  0x021AA4BC  data
 *   g_021AA4D4     0x021AA4D4  data
 *   g_021AA4DC     0x021AA4DC  data
 *   SOCL_GetHostID   0x0215ef48 arm
 *   func_0215EEE0  0x0215EEE0  arm  ov009
 */
#include "../../matched/include/G_SOCLAlloc.h"

#define SWAP32(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))
typedef struct {
	char *name;
	char **aliases;
	short addrType;
	short length;
	unsigned char **addrList;
} HostEnt;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
	unsigned char pad[0xae];
	signed char flag;
} Sock;

typedef struct {
    unsigned long w00;
    void *(*free_)(int, void *, unsigned long);
    unsigned long w08;
    void *(*alloc_)(int, unsigned long);
} SOCLAlloc;

extern unsigned long func_0215EDD0(char *hostname);
extern void func_02082BCC(void *dstp, unsigned char data, unsigned long size);
extern int func_0208CB10(char *destp, const char *srcp, int siz);
extern int func_0215EF48(void);
extern unsigned long SOCL_GetHostID(void);
extern int func_0215EEE0(unsigned long dns1, unsigned long dns2);
HostEnt *func_0215F650(const char *name);
int func_0215F714(u8 *p, u8 *dst);
long SOC_GetHostID(void);
int func_0215F7E8(unsigned long *dns1, unsigned long *dns2);
int func_0215F854(Sock *s, int cmd, int mode);
extern struct SOCLAlloc g_021AA4BC;
extern struct SOCLAlloc g_021AA4BC_ip;
extern unsigned char *g_021AA4D4[2];
extern HostEnt g_021AA4DC;
extern char g_021AA544[0x101];


/*
 * sdk:      SOC_GetHostByName (libsoc.TWL.HYB.a(soc.o))
 */
HostEnt *func_0215F650(const char *name)
{
	unsigned long h;

	h = func_0215EDD0((char *)name);
	if (h == 0) {
		return 0;
	}
	func_02082BCC(g_021AA544, 0, 0x101);
	func_0208CB10(g_021AA544, name, 0x101);
	g_021AA4BC.hostent_name = g_021AA544;
	g_021AA4BC.hostent_aliases = 0;
	g_021AA4BC.hostent_addrType = 2;
	g_021AA4BC.hostent_length = 4;
	g_021AA4BC.hostent_addrList = g_021AA4D4;
	g_021AA4BC.addrList[0] = (unsigned char *)&(*(unsigned long *)&g_021AA4BC_ip);
	g_021AA4BC.addrList[1] = 0;
	g_021AA4BC.w00 = SWAP32(h);
	return &g_021AA4DC;
}


/*
 * Build a packet header at `dst`: tag bytes 8, 2, then the byte-swapped
 * halfword at p+0xb0 and the byte-swapped word returned by func_0215EF48.
 * A null p returns -0x27.
 */
int func_0215F714(u8 *p, u8 *dst)
{
    u32 r;
    u16 t;

    if (p == 0)
        return -0x27;

    r = func_0215EF48();
    t = p ? *(u16 *)(p + 0xb0) : 0;
    t = r ? t : 0;

    dst[0] = 8;
    dst[1] = 2;
    *(u16 *)(dst + 2) = (u16)(((t >> 8) & 0xff) | ((t << 8) & 0xff00));
    *(u32 *)(dst + 4) = ((r >> 24) & 0xff) | ((r >> 8) & 0xff00)
                      | ((r << 8) & 0xff0000) | ((r << 24) & 0xff000000);
    return 0;
}


long SOC_GetHostID(void)
{
    unsigned long hostid = SOCL_GetHostID();

    return (long)(((hostid >> 24) & 0xff) | ((hostid >> 8) & 0xff00)
                | ((hostid << 8) & 0xff0000) | ((hostid << 24) & 0xff000000));
}


/*
 * sdk:      SOC_SetResolver (libsoc.TWL.HYB.a(soc.o))
 */
int func_0215F7E8(unsigned long *dns1, unsigned long *dns2)
{
	return func_0215EEE0(SWAP32(*dns1), SWAP32(*dns2));
}


/*
 * sdk:      SOC_Fcntl (libsoc.TWL.HYB.a(soc.o))
 */
int func_0215F854(Sock *s, int cmd, int mode)
{
	if (s == 0) {
		return -1;
	}
	switch (cmd) {
	case 3:
		if (s->flag == 1) {
			return 0;
		}
		return 4;
	case 4:
		if (mode & 4) {
			s->flag = 0;
		} else {
			s->flag = 1;
		}
		break;
	}
	return 0;
}


static void *AllocFunc_SOCL(unsigned long size)
{
    unsigned long *m;
    unsigned long msize = size + 4;

    m = (unsigned long *)g_021AA4BC.alloc_(0, msize);
    if (m != 0)
        *m++ = msize;
    return m;
}
