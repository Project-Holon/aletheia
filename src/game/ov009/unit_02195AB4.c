/*
 * file:     unit_02195AB4.c
 * unit:     yes
 * function: func_02195AB4, func_02195AD8, func_02195AF0
 * address:  0x02195AB4
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
 *   func_02197D94  0x02197D94  arm  ov009
 *   func_02195DE4  0x02195DE4  arm  ov009
 *   func_02197FDC  0x02197FDC  arm  ov009
 *   gti2ReceiveMessages              0x0219725c arm
 *   gti2SocketConnectionsThink       0x02198570 arm
 *   gti2FreeClosedConnections        0x021985ac arm
 */
struct GTI2Socket;
extern int func_02197D94(void **sock, char *addr, int outSize, int inSize, void *callback, int type);
extern void func_02195DE4(int *p);
extern void func_02197FDC(void *p);
extern int gti2ReceiveMessages(struct GTI2Socket *socket);
extern int gti2SocketConnectionsThink(struct GTI2Socket *socket);
extern void gti2FreeClosedConnections(struct GTI2Socket *socket);
int func_02195AB4(void **sock, char *addr, int outSize, int inSize, void *callback);
void func_02195AD8(void *p);
void gt2Think(struct GTI2Socket *socket);


/*
 * sdk:      gt2CreateSocket (libdwcgsgt2.TWL.HYB.a(gt2main.o))
 */
int func_02195AB4(void **sock, char *addr, int outSize, int inSize, void *callback)
{
	return func_02197D94(sock, addr, outSize, inSize, callback, 0);
}


/*
 * Calls the two helpers on the argument.
 */
void func_02195AD8(void *p)
{
    func_02195DE4(p);
    func_02197FDC(p);
}


void gt2Think(struct GTI2Socket *socket)
{
    if (gti2ReceiveMessages(socket) == 0)
        return;
    if (gti2SocketConnectionsThink(socket) == 0)
        return;
    gti2FreeClosedConnections(socket);
}
