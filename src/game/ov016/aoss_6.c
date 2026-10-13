/*
 * file:     aoss_6.c
 * unit:     yes
 * function: AOSS_Setsockopt, AOSS_Socket, AOSS_Bind, AOSS_Close
 * address:  0x021B82C4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   SOC_Close  0x0215F644  arm  ov009
 */
extern int func_0215F428(int domain, int type);
extern void func_0215F454(unsigned int fd, unsigned char *addr, unsigned char addrLen);
extern int SOC_Close(int fd);
void AOSS_Setsockopt(void);
int AOSS_Socket(int domain, int type);
void AOSS_Bind(unsigned int fd, unsigned char *addr, unsigned char addrLen);
int AOSS_Close(int fd);

/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/AOSS_Setsockopt.c \
 *       --func AOSS_Setsockopt --addr 0x021B82C4 --region ov016 --cc dsi/1.1p1 --thumb
 */
void AOSS_Setsockopt(void)
{
}


/*
 * Thumb tail-call thunk into func_0215F428.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/AOSS_Socket.c \
 *       --func AOSS_Socket --addr 0x021B82C8 --region ov016 --cc dsi/1.1p1 --thumb
 */
int AOSS_Socket(int domain, int type)
{
    return func_0215F428(domain, type);
}


/*
 * Store the length byte at the start of the address, then tail-call func_0215F454 with the same arguments.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/AOSS_Bind.c \
 *       --func AOSS_Bind --addr 0x021B82D0 --region ov016 --cc dsi/1.1p1 --thumb
 */
void AOSS_Bind(unsigned int fd, unsigned char *addr, unsigned char addrLen)
{
    *addr = addrLen;
    func_0215F454(fd, addr, addrLen);
}


int AOSS_Close(int fd)
{
    return SOC_Close(fd);
}
