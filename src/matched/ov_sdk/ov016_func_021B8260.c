/*
 * function: AOSS_Select
 * address:  0x021B8260
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _ull_mul  0x0209C054  arm
 *   SOC_Poll  0x0215FBCC  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol AOSS_Select (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 * The DWARF lists only readfds and timeout; nfds, writefds and exceptfds are
 * unused parameters (timeout arrives on the stack, so the arity is five).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B8260.c \
 *       --func AOSS_Select --addr 0x021B8260 --region ov016 --cc ../2.0/sp1p2 --thumb
 */

typedef struct {
    int   fd;
    short events;
    short revents;
} SOCPollFD;

struct timeval {
    int tv_sec;
    int tv_usec;
};

extern int SOC_Poll(SOCPollFD *fds, unsigned int nfds, unsigned long long timeout);

int AOSS_Select(int nfds, SOCPollFD *readfds, void *writefds, void *exceptfds, struct timeval *timeout)
{
    SOCPollFD fds[1];
    unsigned long long timuout_tic;

    fds[0] = *readfds;
    timuout_tic = 0;
    timuout_tic += ((unsigned long long)timeout->tv_sec * 0x01ff6210) >> 6;
    timuout_tic += ((unsigned long long)timeout->tv_usec * 0x01ff6210) >> 6;
    return SOC_Poll(fds, 1, timuout_tic);
}
