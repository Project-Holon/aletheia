/*
 * file:     socl_command.c
 * unit:     yes
 * function: func_0215CD3C, func_0215CDD0, func_0215CE14, func_0215CE3C, func_0215CE7C, func_0215CE9C, func_0215CEB0, func_0215CEFC, func_0215CF14, func_0215CF88, func_0215CF98, func_0215CFA8, func_0215CFC0
 * address:  0x0215CD3C
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
 *   g_021A1CD8   0x021A1CD8  data
 *   g_021AA484   0x021AA484  data
 *   g_021AA480   0x021AA480  data
 *   func_02085D94  0x02085D94  arm
 *   OS_ReceiveMessage           0x02085e50 arm
 *   SOCLiCommandPacketQueue    0x021aa484 data
 *   func_02085DBC  0x02085DBC  arm
 *   func_02085E50  0x02085E50  arm
 *   func_02085F8C  0x02085F8C  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_DisableScheduler  0x02085B30  arm
 *   OS_EnableScheduler  0x02085B60  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 */
#include "../../matched/include/G_021A1CD8.h"
#include "../../matched/include/G_Cmd.h"

struct OSMessageQueue;
struct SOCLSocket;
struct SOCLiCommandPacket {
    int (*handler)(void *);
    struct SOCLSocket *socket;
    long field8;
    signed char fieldC;
    signed char fieldD;
};

typedef signed int     s32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
	unsigned char pad0[0x20];
} MsgQueue;

typedef struct Command Command;

typedef struct {
	unsigned char pad0[0xa8];
	long result;
} Reply;

struct Command {
	long (*exec)(Command *);
	Reply *reply;
	void *response_queue;
	unsigned char pad2;
	signed char flag_block;
};

extern void func_02085D94(struct OSMessageQueue *mq, void **msgArray, s32 msgCount);
extern int OS_ReceiveMessage(struct OSMessageQueue *mq, void **msg, long flags);
extern int func_02085DBC(struct OSMessageQueue *mq, void *msg, long flags);
extern int func_02085F8C(struct OSMessageQueue *mq, void **msg, s32 flags);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_DisableScheduler(void);
extern unsigned long OS_EnableScheduler(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
int func_0215CD3C(int n);
int func_0215CDD0(void);
struct SOCLiCommandPacket *SOCLi_AllocCommandPacket(long flag);
struct SOCLiCommandPacket *SOCLi_CreateCommandPacket(int (*handler)(void *), struct SOCLSocket *socket, long flag);
void func_0215CE7C(void *ptr);
int func_0215CE9C(const int *p, int b);
int func_0215CEB0(int a0, char *a1);
void func_0215CEFC(int a, int b);
int func_0215CF14(void *pipe, Command *command);
void func_0215CF88(const int *p, Command *command);
void func_0215CF98(const int *p, Command *command);
void func_0215CFA8(int a, int b);
void func_0215CFC0(void *arg);
extern struct G_021A1CD8 *g_021A1CD8;
extern struct OSMessageQueue SOCLiCommandPacketQueue;
extern struct Cmd g_021AA480;





int func_0215CD3C(int n)
{
    char *base;
    char *p;
    int off;
    int size;
    int i;

    size = (n * 0x2c + 3) & ~3;
    off = (n * 4 + 3) & ~3;

    base = (char *)g_021A1CD8->alloc(size + off);
    if (base == 0)
        return -1;

    func_02085D94(&SOCLiCommandPacketQueue, (void **)base, n);

    p = base + off;
    for (i = n; i > 0; i--) {
        func_0215CE7C(p);
        p += 0x2c;
    }

    g_021AA480.packets = base;
    return 0;
}






/*
 * sdk:      SOCLi_CleanupCommandPacketQueue (libsoc.TWL.HYB.a(socl_command.o))
 */
int func_0215CDD0(void)
{
	if (g_021AA480.b < g_021AA480.a)
		return -1;
	g_021A1CD8->free(g_021AA480.packets);
	g_021AA480.packets = 0;
	return 0;
}






struct SOCLiCommandPacket *SOCLi_AllocCommandPacket(long flag)
{
    struct SOCLiCommandPacket *cp;

    if (OS_ReceiveMessage(&SOCLiCommandPacketQueue, (void **)&cp, flag) != 0)
        return cp;
    return 0;
}





struct SOCLiCommandPacket *SOCLi_CreateCommandPacket(int (*handler)(void *),
                                                     struct SOCLSocket *socket,
                                                     long flag)
{
    struct SOCLiCommandPacket *cp = SOCLi_AllocCommandPacket(flag);

    if (cp != 0) {
        cp->handler = handler;
        cp->socket = socket;
        cp->field8 = 0;
        cp->fieldC = *(signed char *)((char *)socket + 0xaf);
        cp->fieldD = (signed char)flag;
    }
    return cp;
}



void func_0215CE7C(void *ptr)
{
    if (ptr != 0) {
        func_02085DBC(&SOCLiCommandPacketQueue, ptr, 0);
    }
}


/*
 * Word at +0xa0 of the block, falling back to +0xa4 when it is zero.
 */
int func_0215CE9C(const int *p, int b)
{
    int v = p[0x28];

    if (v == 0)
        v = p[0x29];
    return v;
}




/*
 * Runs one helper with a flag derived from bit 0 of the object's byte 0xd
 * (defaulting to 1 for a null object); on a zero result runs a teardown and
 * returns -0x29, otherwise 0.
 */
int func_0215CEB0(int a0, char *a1)
{
    int r2;
    int r4;

    if (a1 == 0 || (a1[0xd] & 1))
        r2 = 1;
    else
        r2 = 0;
    r4 = func_02085DBC((struct OSMessageQueue *)a0, a1, r2);
    if (r4 == 0)
        func_0215CE7C(a1);
    return r4 ? 0 : -0x2A;
}




/*
 * Passes the second argument on to both calls.
 */
void func_0215CEFC(int a, int b)
{
    int v = func_0215CE9C((const int *)a, b);

    func_0215CEB0(v, (char *)b);
}




/*
 * sdk:      SOCLi_ExecCommandPacket (libsoc.TWL.HYB.a(socl_command.o))
 */
int func_0215CF14(void *pipe, Command *command)
{
	long result;
	void *response;
	MsgQueue response_queue;

	if (command->flag_block == 1) {
		func_02085D94((struct OSMessageQueue *)(&response_queue), &response, 1);
		command->response_queue = &response_queue;
		func_0215CEB0((int)pipe, (char *)command);
		OS_ReceiveMessage((struct OSMessageQueue *)&response_queue, (void **)&result, 1);
	} else {
		command->response_queue = 0;
		result = func_0215CEB0((int)pipe, (char *)command);
	}
	return result;
}




/*
 * Tail call on the word at +0xa0 of the object.
 */
void func_0215CF88(const int *p, Command *command)
{
    func_0215CF14((void *)p[0x28], command);
}




/*
 * Tail call on the word at +0xa4 of the object.
 */
void func_0215CF98(const int *p, Command *command)
{
    func_0215CF14((void *)p[0x29], command);
}




void func_0215CFA8(int a, int b)
{
    int v = func_0215CE9C((const int *)a, b);

    func_0215CF14((void *)v, (Command *)b);
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
		enable = OS_DisableInterrupts();
		OS_DisableScheduler();
		OS_ReceiveMessage((struct OSMessageQueue *)cpipe, 0, 0);
		if (command->reply != 0) {
			command->reply->result = result;
		}
		if (command->response_queue != 0) {
			func_02085DBC((struct OSMessageQueue *)command->response_queue, (void *)result, 0);
		}
		func_0215CE7C(command);
		OS_EnableScheduler();
		OS_RestoreInterrupts(enable);
	}
}
