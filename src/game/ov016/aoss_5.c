/*
 * file:     aoss_5.c
 * unit:     yes
 * function: AOSS_Recvfrom, AOSS_Select, func_021B82B4
 * address:  0x021B824C
 * region:   ov016
 * compiler: dsi/../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _ull_mul  0x0209C054  arm
 *   SOC_Poll  0x0215FBCC  arm
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

extern void SOC_RecvFrom(int, int, int, int, void *);
extern int SOC_Poll(SOCPollFD *fds, unsigned int nfds, unsigned long long timeout);
extern void func_0215F5B4(int, int, int, int, void *);
void AOSS_Recvfrom(int a, int b, int c, int d, unsigned char *p, unsigned int *v);
int AOSS_Select(int nfds, SOCPollFD *readfds, void *writefds, void *exceptfds, struct timeval *timeout);
void func_021B82B4(int a, int b, int c, int d, unsigned char *p, int v);


void AOSS_Recvfrom(int a, int b, int c, int d, unsigned char *p, unsigned int *v)
{
    *p = (unsigned char)*v;
    SOC_RecvFrom(a, b, c, d, p);
}

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


void func_021B82B4(int a, int b, int c, int d, unsigned char *p, int v)
{
    *p = (unsigned char)v;
    func_0215F5B4(a, b, c, d, p);
}
