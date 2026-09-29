/*
 * function: func_0215F854
 * address:  0x0215F854
 * packet:   pkt_ov009_0215F854
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOC_Fcntl (libsoc.TWL.HYB.a(soc.o))
 *
 * symbols:

 */

typedef struct {
	unsigned char pad[0xae];
	signed char flag;
} Sock;

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
