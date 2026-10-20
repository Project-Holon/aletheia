/*
 * file:     socl_list.c
 * unit:     yes
 * function: SOCLi_SocketRegister, SOCLi_SocketRegisterList, SOCLi_SocketRegisterTrash, SOCLi_SocketUnregister, SOCLi_SocketUnregisterList, SOCLi_SocketGetNextPtr, SOCLi_SocketUnregisterTrash, SOCL_SocketIsInvalid, SOCL_SocketIsInTrash
 * address:  0x0215F2DC
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
 *   SOCLiSocketList  0x021AA4B4  data
 *   SOCLi_SocketRegisterList  0x0215F2F4  arm  ov009
 *   SOCLiTrashList  0x021AA4B8  data
 *   OS_DisableInterrupts  0x02087988  arm
 *   SOCLi_SocketGetNextPtr  0x0215F36C  arm  ov009
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   SOCLiSocketList          0x021aa4b4 data
 */
struct Sock;
struct SOCLSocket;
typedef struct Sock {
	char pad[0xb8];
	struct Sock *next;
} Sock;

typedef unsigned int OSIntrMode;
#include "../arm9/os_system.h"
void SOCLi_SocketRegister(void *a);
void SOCLi_SocketRegisterList(void **next, char *socket);
void SOCLi_SocketRegisterTrash(int a);
void SOCLi_SocketUnregister(int a);
void SOCLi_SocketUnregisterList(Sock **next, Sock *socket);
struct SOCLSocket **SOCLi_SocketGetNextPtr(struct SOCLSocket **next, struct SOCLSocket *socket);
void SOCLi_SocketUnregisterTrash(int a);
int SOCL_SocketIsInvalid(struct SOCLSocket *socket);
int SOCL_SocketIsInTrash(void *b);
extern struct SOCLSocket *SOCLiSocketList;
extern char SOCLiTrashList[];




void SOCLi_SocketRegister(void *a)
{
    SOCLi_SocketRegisterList((void **)((char *)&SOCLiSocketList), (char *)(a));
}



void SOCLi_SocketRegisterList(void **next, char *socket)
{
	*(void **)(socket + 0xb8) = *next;
	*next = socket;
}




/*
 * Tail call on the object at 0x021AA4B8 with the incoming argument.
 */
void SOCLi_SocketRegisterTrash(int a)
{
    SOCLi_SocketRegisterList((void **)(SOCLiTrashList), (char *)(a));
}




/*
 * Tail call on the object at 0x021AA4B4 with the incoming argument.
 */
void SOCLi_SocketUnregister(int a)
{
    SOCLi_SocketUnregisterList((Sock * *)((struct Sock **)&SOCLiSocketList), (Sock *)((struct Sock *)a));
}




/*
 * sdk:      SOCLi_SocketUnregisterList (libsoc.TWL.HYB.a(socl_list.o))
 */
void SOCLi_SocketUnregisterList(Sock **next, Sock *socket)
{
	unsigned long enable;

	enable = OS_DisableInterrupts();
	next = (Sock **)(SOCLi_SocketGetNextPtr((struct SOCLSocket **)(next), (struct SOCLSocket *)(socket)));
	if (next)
		*next = socket->next;
	OS_RestoreInterrupts(enable);
}




struct SOCLSocket **SOCLi_SocketGetNextPtr(struct SOCLSocket **next,
                                           struct SOCLSocket *socket)
{
    struct SOCLSocket *t;
    unsigned long enable = OS_DisableInterrupts();

    t = *next;
    while (t != 0) {
        if (t == socket) {
            OS_RestoreInterrupts(enable);
            return next;
        }
        next = (struct SOCLSocket **)((char *)t + 0xb8);
        t = *next;
    }
    OS_RestoreInterrupts(enable);
    return 0;
}



void SOCLi_SocketUnregisterTrash(int a)
{
    SOCLi_SocketUnregisterList((Sock * *)((struct Sock **)SOCLiTrashList), (Sock *)((struct Sock *)a));
}



int SOCL_SocketIsInvalid(struct SOCLSocket *socket)
{
    if ((sptr)socket <= 0
        || SOCLi_SocketGetNextPtr(&SOCLiSocketList, socket) == 0)
        return 1;
    return 0;
}



/*
 * Non-zero test on the call that takes the object and the argument.
 */
int SOCL_SocketIsInTrash(void *b)
{
    return (sptr)(Sock **)(SOCLi_SocketGetNextPtr((struct SOCLSocket **)((Sock * *)SOCLiTrashList), (struct SOCLSocket *)((Sock *)b))) != 0;
}
