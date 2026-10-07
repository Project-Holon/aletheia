/*
 * file:     unit_0215CD3C_p05.c
 * unit:     yes
 * function: func_0215CFA8, func_0215CFC0
 * address:  0x0215CFA8
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
 *   func_0215CE9C  0x0215CE9C  arm  ov009
 *   func_0215CF14  0x0215CF14  arm  ov009
 *   func_02085F8C  0x02085F8C  arm
 *   func_02087988  0x02087988  arm
 *   func_02085B30  0x02085B30  arm
 *   func_02085E50  0x02085E50  arm
 *   func_02085DBC  0x02085DBC  arm
 *   func_0215CE7C  0x0215CE7C  arm  ov009
 *   func_02085B60  0x02085B60  arm
 *   func_0208799C  0x0208799C  arm
 */
struct OSMessageQueue;
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

extern int func_0215CE9C(const int *p, int b);
extern void func_0215CF14(int v, int b);
extern int func_02085F8C(struct OSMessageQueue *mq, void **msg, s32 flags);
extern unsigned long func_02087988(void);
extern unsigned long func_02085B30(void);
extern int func_02085E50(void *mq, void **msg, long flags);
extern int func_02085DBC(void *mq, void *msg, long flags);
extern void func_0215CE7C(void *ptr);
extern unsigned long func_02085B60(void);
extern unsigned long func_0208799C(unsigned long state);
void func_0215CFA8(int a, int b);
void func_0215CFC0(void *arg);


/*
 * Passes the second argument on to both calls.
 */
void func_0215CFA8(int a, int b)
{
    int v = func_0215CE9C((const int *)a, b);

    func_0215CF14(v, b);
}


/*
 * sdk:      SOCLi_CommandPacketHandler (libsoc.TWL.HYB.a(socl_command.o))
 */
void func_0215CFC0(void *arg)
{
	void *cpipe;
	Command *command;
	unsigned long enable;
	long result;

	cpipe = arg;
	for (;;) {
		func_02085F8C(cpipe, (void **)&command, 1);
		if (command == 0) {
			return;
		}
		result = command->exec(command);
		enable = func_02087988();
		func_02085B30();
		func_02085E50(cpipe, 0, 0);
		if (command->reply != 0) {
			command->reply->result = result;
		}
		if (command->response_queue != 0) {
			func_02085DBC(command->response_queue, (void *)result, 0);
		}
		func_0215CE7C(command);
		func_02085B60();
		func_0208799C(enable);
	}
}
