/*
 * function: func_0215FD00
 * address:  0x0215FD00
 * packet:   pkt_ov009_0215FD00
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_ExecEnableSslCommand (libsoc.TWL.HYB.a(socl_ssl.o))
 *
 * symbols:
 *   func_0215CE3C  0x0215CE3C  arm  ov009
 *   func_0215CF88  0x0215CF88  arm  ov009
 *   func_0215FD40  0x0215FD40  arm  ov009
 */

extern void *func_0215CE3C(int (*handler)(void *), void *socket, long flag);
extern int func_0215CF88(void *socket, void *command);
extern int func_0215FD40(void *arg);

int func_0215FD00(void *socket, void *con)
{
	int *command;

	command = func_0215CE3C(func_0215FD40, socket, 1);
	if (command == 0) {
		return -33;
	}
	command[4] = (int)con;
	return func_0215CF88(socket, command);
}
