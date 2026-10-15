/*
 * function: SOC_Poll
 * address:  0x0215FBCC
 * packet:   pkt_ov009_0215FBCC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOC_Poll (libsoc.TWL.HYB.a(soc.o))
 *
 * symbols:
 *   SOCL_GetStatus  0x0215EFB0  arm  ov009
 *   OS_Sleep  0x02085A38  arm
 */

typedef struct {
	int fd;
	short events;
	short revents;
} PollFD;

extern int SOCL_GetStatus(int s);
extern void OS_Sleep(unsigned long msec);

int SOC_Poll(PollFD *fds, unsigned int nfds, long long timeout)
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
			status = status_mask & SOCL_GetStatus(fp->fd);
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
		OS_Sleep(1);
		time -= 523;
	}
	return num_good;
}
