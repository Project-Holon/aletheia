/*
 * file:     socl_command.c
 * unit:     yes
 * function: SOCLi_StartupCommandPacketQueue, SOCLi_CleanupCommandPacketQueue, SOCLi_AllocCommandPacket, SOCLi_CreateCommandPacket, SOCLi_FreeCommandPacket, SOCLi_GetCtrlPipe, SOCLi_SendCommandPacket, SOCLi_SendCommandPacketToCtrlPipe, SOCLi_ExecCommandPacket, SOCLi_ExecCommandPacketInRecvPipe, SOCLi_ExecCommandPacketInSendPipe, SOCLi_ExecCommandPacketInCtrlPipe, SOCLi_CommandPacketHandler
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
 *   gSoclConfig   0x021A1CD8  data
 *   g_021AA484   0x021AA484  data
 *   gSoclCmdQueue   0x021AA480  data
 *   OS_InitMessageQueue  0x02085D94  arm
 *   OS_ReceiveMessage           0x02085e50 arm
 *   SOCLiCommandPacketQueue    0x021aa484 data
 *   OS_SendMessage  0x02085DBC  arm
 *   OS_ReceiveMessage  0x02085E50  arm
 *   OS_ReadMessage  0x02085F8C  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_DisableScheduler  0x02085B30  arm
 *   OS_EnableScheduler  0x02085B60  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 */
#include "socl_command_types.h"

typedef signed int     s32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void OS_InitMessageQueue(struct OSMessageQueue *mq, void **msgArray, s32 msgCount);
extern int OS_ReceiveMessage(struct OSMessageQueue *mq, void **msg, long flags);
extern int OS_SendMessage(struct OSMessageQueue *mq, void *msg, long flags);
extern int OS_ReadMessage(struct OSMessageQueue *mq, void **msg, s32 flags);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_DisableScheduler(void);
extern unsigned long OS_EnableScheduler(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
int SOCLi_StartupCommandPacketQueue(int n);
int SOCLi_CleanupCommandPacketQueue(void);
struct SOCLiCommandPacket *SOCLi_AllocCommandPacket(long flag);
struct SOCLiCommandPacket *SOCLi_CreateCommandPacket(int (*handler)(void *), struct SOCLSocket *socket, long flag);
void SOCLi_FreeCommandPacket(void *ptr);
int SOCLi_GetCtrlPipe(const int *p, int b);
int SOCLi_SendCommandPacket(int queue, struct SOCLiCommandPacket *packet);
void SOCLi_SendCommandPacketToCtrlPipe(int a, int b);
int SOCLi_ExecCommandPacket(void *pipe, struct SOCLiCommandPacket *command);
void SOCLi_ExecCommandPacketInRecvPipe(const int *p, struct SOCLiCommandPacket *command);
void SOCLi_ExecCommandPacketInSendPipe(const int *p, struct SOCLiCommandPacket *command);
void SOCLi_ExecCommandPacketInCtrlPipe(int a, int b);
void SOCLi_CommandPacketHandler(void *arg);
extern SoclConfig *gSoclConfig;
extern struct OSMessageQueue SOCLiCommandPacketQueue;
extern SoclCmdQueue gSoclCmdQueue;





int SOCLi_StartupCommandPacketQueue(int packetCount)
{
    char *pool;
    char *packet;
    int queueOffset;
    int packetBytes;
    int i;

    packetBytes = (packetCount * 0x2c + 3) & ~3;
    queueOffset = (packetCount * 4 + 3) & ~3;

    pool = (char *)gSoclConfig->alloc(packetBytes + queueOffset);
    if (pool == 0)
        return -1;

    OS_InitMessageQueue(&SOCLiCommandPacketQueue, (void **)pool, packetCount);

    packet = pool + queueOffset;
    for (i = packetCount; i > 0; i--) {
        SOCLi_FreeCommandPacket(packet);
        packet += 0x2c;
    }

    gSoclCmdQueue.packets = pool;
    return 0;
}






/*
 * sdk:      SOCLi_CleanupCommandPacketQueue (libsoc.TWL.HYB.a(socl_command.o))
 */
int SOCLi_CleanupCommandPacketQueue(void)
{
	if (gSoclCmdQueue.queueRead < gSoclCmdQueue.queueWrite)
		return -1;
	gSoclConfig->free(gSoclCmdQueue.packets);
	gSoclCmdQueue.packets = 0;
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
        cp->exec = handler;
        cp->target.socket = socket;
        cp->response_queue = 0;
        cp->pipeIndex = *(signed char *)((char *)socket + 0xaf);
        cp->blockFlag = (signed char)flag;
    }
    return cp;
}



void SOCLi_FreeCommandPacket(void *ptr)
{
    if (ptr != 0) {
        OS_SendMessage(&SOCLiCommandPacketQueue, ptr, 0);
    }
}


/*
 * Word at +0xa0 of the block, falling back to +0xa4 when it is zero.
 */
int SOCLi_GetCtrlPipe(const int *p, int b)
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
int SOCLi_SendCommandPacket(int queue, struct SOCLiCommandPacket *packet)
{
    int blocking;
    int sent;

    if (packet == 0 || (packet->blockFlag & 1))
        blocking = 1;
    else
        blocking = 0;
    sent = OS_SendMessage((struct OSMessageQueue *)queue, packet, blocking);
    if (sent == 0)
        SOCLi_FreeCommandPacket(packet);
    return sent ? 0 : -0x2A;
}




/*
 * Passes the second argument on to both calls.
 */
void SOCLi_SendCommandPacketToCtrlPipe(int socket, int packet)
{
    int v = SOCLi_GetCtrlPipe((const int *)socket, packet);

    SOCLi_SendCommandPacket(v, (struct SOCLiCommandPacket *)packet);
}




/*
 * sdk:      SOCLi_ExecCommandPacket (libsoc.TWL.HYB.a(socl_command.o))
 */
int SOCLi_ExecCommandPacket(void *pipe, struct SOCLiCommandPacket *command)
{
	long result;
	void *response;
	OSMessageQueue response_queue;

	if (command->blockFlag == 1) {
		OS_InitMessageQueue((struct OSMessageQueue *)(&response_queue), &response, 1);
		command->response_queue = &response_queue;
		SOCLi_SendCommandPacket((int)pipe, command);
		OS_ReceiveMessage((struct OSMessageQueue *)&response_queue, (void **)&result, 1);
	} else {
		command->response_queue = 0;
		result = SOCLi_SendCommandPacket((int)pipe, command);
	}
	return result;
}




/*
 * Tail call on the word at +0xa0 of the object.
 */
void SOCLi_ExecCommandPacketInRecvPipe(const int *p, struct SOCLiCommandPacket *command)
{
    SOCLi_ExecCommandPacket((void *)p[0x28], command);
}




/*
 * Tail call on the word at +0xa4 of the object.
 */
void SOCLi_ExecCommandPacketInSendPipe(const int *p, struct SOCLiCommandPacket *command)
{
    SOCLi_ExecCommandPacket((void *)p[0x29], command);
}




void SOCLi_ExecCommandPacketInCtrlPipe(int socket, int packet)
{
    int v = SOCLi_GetCtrlPipe((const int *)socket, packet);

    SOCLi_ExecCommandPacket((void *)v, (struct SOCLiCommandPacket *)packet);
}




/*
 * sdk:      SOCLi_CommandPacketHandler (libsoc.TWL.HYB.a(socl_command.o))
 */
void SOCLi_CommandPacketHandler(void *arg)
{
	void *cpipe;
	struct SOCLiCommandPacket *command;
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
		OS_ReceiveMessage((struct OSMessageQueue *)cpipe, 0, 0);
		if (command->target.reply != 0) {
			command->target.reply->result = result;
		}
		if (command->response_queue != 0) {
			OS_SendMessage((struct OSMessageQueue *)command->response_queue, (void *)result, 0);
		}
		SOCLi_FreeCommandPacket(command);
		OS_EnableScheduler();
		OS_RestoreInterrupts(enable);
	}
}
