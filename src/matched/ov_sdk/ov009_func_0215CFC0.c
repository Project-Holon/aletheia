/*
 * function: func_0215CFC0
 * address:  0x0215CFC0
 * packet:   pkt_ov009_0215CFC0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_CommandPacketHandler (libsoc.TWL.HYB.a(socl_command.o))
 *
 * symbols:
 *   OS_ReadMessage  0x02085F8C  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_DisableScheduler  0x02085B30  arm
 *   func_02085E50  0x02085E50  arm
 *   func_02085DBC  0x02085DBC  arm
 *   func_0215CE7C  0x0215CE7C  arm  ov009
 *   OS_EnableScheduler  0x02085B60  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 */

typedef struct Command Command;
typedef struct {
	unsigned char pad0[0xa8];
	long result;
} Reply;

struct Command {
	long (*exec)(Command *);
	Reply *reply;
	void *response_queue;
};

typedef signed int     s32;
struct OSMessageQueue;
extern int OS_ReadMessage(struct OSMessageQueue *mq, void **msg, s32 flags);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_DisableScheduler(void);
extern int func_02085E50(void *mq, void **msg, long flags);
extern int func_02085DBC(void *mq, void *msg, long flags);
extern void func_0215CE7C(void *ptr);
extern unsigned long OS_EnableScheduler(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

void func_0215CFC0(void *arg)
{
	void *cpipe;
	Command *command;
	unsigned long enable;
	long result;

	cpipe = arg;
	for (;;) {
		OS_ReadMessage(cpipe, (void **)&command, 1);
		if (command == 0) {
			return;
		}
		result = command->exec(command);
		enable = OS_DisableInterrupts();
		OS_DisableScheduler();
		func_02085E50(cpipe, 0, 0);
		if (command->reply != 0) {
			command->reply->result = result;
		}
		if (command->response_queue != 0) {
			func_02085DBC(command->response_queue, (void *)result, 0);
		}
		func_0215CE7C(command);
		OS_EnableScheduler();
		OS_RestoreInterrupts(enable);
	}
}
