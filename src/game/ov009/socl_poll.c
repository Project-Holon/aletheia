/*
 * file:     socl_poll.c
 * unit:     yes
 * function: func_0215EFB0, func_0215F080
 * address:  0x0215EFB0
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
 *   func_0215F3D0  0x0215F3D0  arm  ov009
 *   func_02087988  0x02087988  arm
 *   func_0215E2C0  0x0215E2C0  arm  ov009
 *   func_0208799C  0x0208799C  arm
 */
typedef struct {
	unsigned char pad0[8];
	unsigned char type;
	unsigned char pad1[0xa3];
	volatile short state;
	signed char flag_block;
	signed char flag_mode;
} Socket;

extern int func_0215F3D0(Socket *socket);
extern unsigned long func_02087988(void);
extern long func_0215E2C0(Socket *socket);
extern unsigned long func_0208799C(unsigned long state);
int func_0215EFB0(int s);
int func_0215F080(char *p);


static inline int IsStream(Socket *socket)
{
	int r = 1;
	if (socket->flag_mode != 0 && socket->flag_mode != 4) {
		r = 0;
	}
	return r;
}


/*
 * sdk:      SOCL_GetStatus (libsoc.TWL.HYB.a(socl_poll.o))
 *
 * note:     state is spelled volatile: the only spelling found that reproduces the
 *           per-test ldrsh reloads (the vendor DWARF carries no volatile).
 */
int func_0215EFB0(int s)
{
	unsigned long enable;
	int result;
	Socket *socket;

	result = 0;
	socket = (Socket *)s;
	if (func_0215F3D0(socket)) {
		result |= 0x80;
	} else {
		if (socket->state & 0x40) {
			result |= 0x20;
		}
		if (socket->flag_mode == 1 || (socket->state & 4)) {
			enable = func_02087988();
			if (func_0215F080((char *)socket) > 0) {
				result |= 1;
			}
			if (func_0215E2C0(socket) > 0) {
				result |= 8;
			}
			func_0208799C(enable);
		}
		if (IsStream(socket)) {
			if ((socket->state & 4) && socket->type != 4) {
				if (!(result & 1)) {
					socket->state &= ~6;
				}
			}
			if (!(socket->state & 2)) {
				if (!(socket->state & 4)) {
					result |= 0x40;
				}
			}
		}
	}
	return result;
}

/*
 * Reads the object at +0xa0 of the block: in mode 1 returns the halfword at
 * +4 of its +0x104 child, in modes 0 and 4 the +0x50 minus +0xf8 difference,
 * and 0 in every other case.
 */
int func_0215F080(char *p)
{
    char *q = *(char **)(p + 0xa0);
    int r = 0;

    if (q != 0) {
        int t = *(signed char *)(p + 0xaf);

        if (t == 1) {
            char *u = *(char **)(q + 0x104);

            if (u != 0) r = *(unsigned short *)(u + 4);
        } else if (t == 0 || t == 4) {
            r = *(int *)(p + 0x50) - *(int *)(q + 0xf8);
        }
    }
    return r;
}
