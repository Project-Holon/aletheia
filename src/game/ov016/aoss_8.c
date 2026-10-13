/*
 * file:     aoss_8.c
 * unit:     yes
 * function: AOSS_FD_ZERO, AOSS_FD_SET
 * address:  0x021B83E8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
/* Poll entry of the socket library (same layout as in aoss.o's users). */
typedef struct {
    int   fd;
    short events;
    short revents;
} SOCPollFD;

void AOSS_FD_ZERO(SOCPollFD *pollFd);
int AOSS_FD_SET(int fd, SOCPollFD *pollFd);


/*
 * Clear a u32 and two u16 fields of a small record.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/AOSS_FD_ZERO.c \
 *       --func AOSS_FD_ZERO --addr 0x021B83E8 --region ov016 --cc dsi/1.1p1 --thumb
 */
void AOSS_FD_ZERO(SOCPollFD *pollFd)
{
    pollFd->fd = 0;
    pollFd->events = 0;
    pollFd->revents = 0;
}


int AOSS_FD_SET(int fd, SOCPollFD *pollFd)
{
    pollFd->fd = fd;
    pollFd->events = 1;
    return 1;
}
