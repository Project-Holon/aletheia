/*
 * function: GSISocketSelect
 * address:  0x0217ED64
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * GSISocketSelect: the DWC build implements the select probe through the SOC
 * poll wrapper (SOC_Poll) rather than select(2).  Build a one-entry
 * pollfd, request read (POLLIN 0x1) and/or write (POLLOUT 0x8) per the
 * non-NULL out-flags, poll with a zero timeout, then publish each flag from
 * the result: read tests 0x41, write 0x8, except 0x20.  A negative poll
 * result returns -1 with no flags touched.
 *
 * symbols:
 *   SOC_Poll  0x0215FBCC  arm  ov009
 */

typedef struct {
    int fd;
    short events;
    short revents;
} GSPollFd;

extern int SOC_Poll(GSPollFd *fds, int nfds, int timeout, int flags);

int GSISocketSelect(int theSocket, int *theReadFlag, int *theWriteFlag, int *theExceptFlag)
{
    GSPollFd pfd;
    int result;

    pfd.fd = theSocket;
    pfd.events = 0;
    if (theReadFlag != 0)
        pfd.events |= 1;
    if (theWriteFlag != 0)
        pfd.events |= 8;
    pfd.revents = 0;

    result = SOC_Poll(&pfd, 1, 0, 0);
    if (result < 0)
        return -1;

    if (theReadFlag != 0) {
        if (result > 0 && (pfd.revents & 0x41))
            *theReadFlag = 1;
        else
            *theReadFlag = 0;
    }
    if (theWriteFlag != 0) {
        if (result > 0 && (pfd.revents & 0x8))
            *theWriteFlag = 1;
        else
            *theWriteFlag = 0;
    }
    if (theExceptFlag != 0) {
        if (result > 0 && (pfd.revents & 0x20))
            *theExceptFlag = 1;
        else
            *theExceptFlag = 0;
    }
    return result;
}
