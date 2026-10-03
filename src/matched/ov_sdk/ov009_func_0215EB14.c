/*
 * function: func_0215EB14
 * address:  0x0215EB14
 * packet:   pkt_ov009_0215EB14
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_FreeCommandPipe (libsoc.TWL.HYB.a(socl_close.o))
 *
 * symbols:
 *   func_02085710  0x02085710  arm
 *   func_02087988  0x02087988  arm
 *   func_02085B30  0x02085B30  arm
 *   func_02085E50  0x02085E50  arm
 *   func_02085DBC  0x02085DBC  arm
 *   func_0215CE7C  0x0215CE7C  arm  ov009
 *   func_02085B60  0x02085B60  arm
 *   func_020858BC  0x020858BC  arm
 *   func_0208799C  0x0208799C  arm
 */

typedef struct {
	unsigned long pad0[2];
	void *reply;
} Command;

extern void func_02085710(void *thread);
extern unsigned long func_02087988(void);
extern unsigned long func_02085B30(void);
extern int func_02085E50(void *mq, void **msg, long flags);
extern int func_02085DBC(void *mq, void *msg, long flags);
extern void func_0215CE7C(void *ptr);
extern unsigned long func_02085B60(void);
extern void func_020858BC(void);
extern unsigned long func_0208799C(unsigned long state);

void func_0215EB14(unsigned char *pipe)
{
	unsigned long enable;
	Command *command;

	if (pipe == 0) {
		return;
	}
	func_02085710(pipe + 0x20);
	enable = func_02087988();
	func_02085B30();
	while (func_02085E50(pipe, (void **)&command, 0)) {
		if (command != 0) {
			if (command->reply != 0) {
				func_02085DBC(command->reply, (void *)-11, 0);
			}
			func_0215CE7C(command);
		}
	}
	func_02085B60();
	func_020858BC();
	func_0208799C(enable);
}
