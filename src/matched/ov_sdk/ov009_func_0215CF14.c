/*
 * function: SOCLi_ExecCommandPacket
 * address:  0x0215CF14
 * packet:   pkt_ov009_0215CF14
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_ExecCommandPacket (libsoc.TWL.HYB.a(socl_command.o))
 *
 * symbols:
 *   OS_InitMessageQueue  0x02085D94  arm
 *   SOCLi_SendCommandPacket  0x0215CEB0  arm  ov009
 *   func_02085E50  0x02085E50  arm
 */

typedef struct {
	unsigned char pad0[0x20];
} MsgQueue;

typedef struct {
	unsigned long pad0;
	unsigned long pad1;
	MsgQueue *response_queue;
	unsigned char pad2;
	signed char flag_block;
} Command;

typedef signed int     s32;
struct OSMessageQueue;
extern void OS_InitMessageQueue(struct OSMessageQueue *mq, void **msgArray, s32 msgCount);
extern int SOCLi_SendCommandPacket(int a0, char *a1);
extern int func_02085E50(MsgQueue *mq, void **msg, long flags);

int SOCLi_ExecCommandPacket(void *pipe, Command *command)
{
	long result;
	void *response;
	MsgQueue response_queue;

	if (command->flag_block == 1) {
		OS_InitMessageQueue((struct OSMessageQueue *)(&response_queue), &response, 1);
		command->response_queue = &response_queue;
		SOCLi_SendCommandPacket((int)pipe, (char *)command);
		func_02085E50(&response_queue, (void **)&result, 1);
	} else {
		command->response_queue = 0;
		result = SOCLi_SendCommandPacket((int)pipe, (char *)command);
	}
	return result;
}
