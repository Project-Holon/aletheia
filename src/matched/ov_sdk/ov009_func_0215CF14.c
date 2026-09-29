/*
 * function: func_0215CF14
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
 *   func_02085D94  0x02085D94  arm
 *   func_0215CEB0  0x0215CEB0  arm  ov009
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

extern void func_02085D94(MsgQueue *mq, void **msgArray, long msgCount);
extern int func_0215CEB0(void *pipe, Command *command);
extern int func_02085E50(MsgQueue *mq, void **msg, long flags);

int func_0215CF14(void *pipe, Command *command)
{
	long result;
	void *response;
	MsgQueue response_queue;

	if (command->flag_block == 1) {
		func_02085D94(&response_queue, &response, 1);
		command->response_queue = &response_queue;
		func_0215CEB0(pipe, command);
		func_02085E50(&response_queue, (void **)&result, 1);
	} else {
		command->response_queue = 0;
		result = func_0215CEB0(pipe, command);
	}
	return result;
}
