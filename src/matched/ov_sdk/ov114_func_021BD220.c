/*
 * function: func_021BD220
 * address:  0x021BD220
 * packet:   pkt_ov114_021BD220
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_ThreadInit (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * symbols:
 *   func_021BA13C 0x021BA13C arm ov114
 */

typedef struct {
    int result;
    char sendBuf[0x100];
    char recvBuf[0x200];
    char pad0[0x314 - 0x304];
    int socket;
    int pipe;
    char pad1[0x324 - 0x31c];
    int a324;
    char pad2[0x32c - 0x328];
    int a32c;
    int a330;
    int a334;
    int a338;
    int a33c;
} ThreadData;

extern void func_021BA13C(int a, int b);

void func_021BD220(ThreadData *threadData_p)
{
    threadData_p->result = -1;
    func_021BA13C((int)threadData_p->sendBuf, 0x100);
    func_021BA13C((int)threadData_p->recvBuf, 0x200);
    threadData_p->socket = -1;
    threadData_p->pipe = -1;
    threadData_p->a324 = 0;
    threadData_p->a338 = 0;
    threadData_p->a33c = 0;
    threadData_p->a334 = 0;
    threadData_p->a32c = 0;
    threadData_p->a330 = 0;
}
