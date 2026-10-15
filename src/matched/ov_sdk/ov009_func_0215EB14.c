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
 *   OS_JoinThread  0x02085710  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_DisableScheduler  0x02085B30  arm
 *   func_02085E50  0x02085E50  arm
 *   func_02085DBC  0x02085DBC  arm
 *   SOCLi_FreeCommandPacket  0x0215CE7C  arm  ov009
 *   OS_EnableScheduler  0x02085B60  arm
 *   OS_RescheduleThread  0x020858BC  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 */

typedef struct {
	unsigned long pad0[2];
	void *reply;
} Command;

extern void OS_JoinThread(void *thread);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_DisableScheduler(void);
extern int func_02085E50(void *mq, void **msg, long flags);
extern int func_02085DBC(void *mq, void *msg, long flags);
extern void SOCLi_FreeCommandPacket(void *ptr);
extern unsigned long OS_EnableScheduler(void);
extern void OS_RescheduleThread(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

void func_0215EB14(unsigned char *pipe)
{
	unsigned long enable;
	Command *command;

	if (pipe == 0) {
		return;
	}
	OS_JoinThread(pipe + 0x20);
	enable = OS_DisableInterrupts();
	OS_DisableScheduler();
	while (func_02085E50(pipe, (void **)&command, 0)) {
		if (command != 0) {
			if (command->reply != 0) {
				func_02085DBC(command->reply, (void *)-11, 0);
			}
			SOCLi_FreeCommandPacket(command);
		}
	}
	OS_EnableScheduler();
	OS_RescheduleThread();
	OS_RestoreInterrupts(enable);
}
