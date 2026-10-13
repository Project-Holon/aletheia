/*
 * function: ghiProcessConnection
 * address:  0x021C1DEC
 * packet:   pkt_ov114_021C1DEC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiProcessConnection (ghttpmain.o, static)
 *
 * symbols:
 *   ghiDoSocketInit                    0x021c3bac arm  ov114
 *   ghiDoHostLookup                    0x021c3d10 arm  ov114
 *   ghiDoLookupPending                    0x021c3e10 arm  ov114
 *   ghiDoConnecting                    0x021c3ec0 arm  ov114
 *   ghiDoSecuringSession                    0x021c4150 arm  ov114
 *   ghiDoSendingRequest                    0x021c4384 arm  ov114
 *   ghiDoPosting                    0x021c4684 arm  ov114
 *   ghiDoWaiting                    0x021c4764 arm  ov114
 *   ghiDoReceivingStatus                    0x021c492c arm  ov114
 *   ghiDoReceivingHeaders                    0x021c4e7c arm  ov114
 *   ghiDoReceivingFile                    0x021c5430 arm  ov114
 *   func_0217D254                    0x0217d254 arm  ov009
 *   ghiRedirectConnection                    0x021c0e58 arm  ov114
 *   func_0217EF50                    0x0217ef50 arm  ov009
 *   ghiHandleStatus                    0x021c1d30 arm  ov114
 *   ghiCloseConnection                    0x021c0b4c arm  ov114
 *   ghiCallCompletedCallback                    0x021c0244 arm  ov114
 *   ghiFreeConnectionData                    0x021c0c14 arm  ov114
 *   sGhttpConnectionClosing                       0x021ced74 data
 */

typedef struct GHIConnection {
    char pad0[0x10];
    int state;                  /* +0x010 */
    char pad14[0x40 - 0x14];
    int result;                 /* +0x040 */
    char pad44[0x50 - 0x44];
    int socket;                 /* +0x050 */
    char pad54[0x124 - 0x54];
    int completed;              /* +0x124 */
    char pad128[0x130 - 0x128];
    int redirect;               /* +0x130 */
    char pad134[0x154 - 0x134];
    int processing;             /* +0x154 */
    char pad158[0x1c8 - 0x158];
    int handleStatus;           /* +0x1c8 */
} GHIConnection;

extern void ghiDoSocketInit(GHIConnection *connection);
extern void ghiDoHostLookup(GHIConnection *connection);
extern void ghiDoLookupPending(GHIConnection *connection);
extern void ghiDoConnecting(GHIConnection *connection);
extern void ghiDoSecuringSession(GHIConnection *connection);
extern void ghiDoSendingRequest(GHIConnection *connection);
extern void ghiDoPosting(GHIConnection *connection);
extern void ghiDoWaiting(GHIConnection *connection);
extern void ghiDoReceivingStatus(GHIConnection *connection);
extern void ghiDoReceivingHeaders(GHIConnection *connection);
extern void ghiDoReceivingFile(GHIConnection *connection);
struct Ctx;
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void ghiRedirectConnection(GHIConnection *connection);
extern int func_0217EF50(int sock);
extern void ghiHandleStatus(GHIConnection *connection);
extern int ghiCloseConnection(GHIConnection *connection);
extern void ghiCallCompletedCallback(struct Ctx *ctx);
extern int ghiFreeConnectionData(GHIConnection *connection);
extern char sGhttpConnectionClosing[];

int ghiProcessConnection(GHIConnection *connection)
{
    int completed;

    if (connection->processing)
        return 0;
    connection->processing = 1;

    if (connection->state == 0)
        ghiDoSocketInit(connection);
    if (connection->state == 1)
        ghiDoHostLookup(connection);
    if (connection->state == 2)
        ghiDoLookupPending(connection);
    if (connection->state == 3)
        ghiDoConnecting(connection);
    if (connection->state == 4)
        ghiDoSecuringSession(connection);
    if (connection->state == 5)
        ghiDoSendingRequest(connection);
    if (connection->state == 6)
        ghiDoPosting(connection);
    if (connection->state == 7)
        ghiDoWaiting(connection);
    if (connection->state == 8)
        ghiDoReceivingStatus(connection);
    if (connection->state == 9)
        ghiDoReceivingHeaders(connection);
    if (connection->state == 10)
        ghiDoReceivingFile(connection);
    if (connection->state == 11)
        func_0217D254(8, (char *)3, 0x10, sGhttpConnectionClosing);

    if (connection->redirect)
        ghiRedirectConnection(connection);

    completed = connection->completed;
    if (connection->result == 0x12 && !completed) {
        if (!func_0217EF50(connection->socket))
            connection->completed = 1;
    }

    if (connection->completed) {
        if (connection->handleStatus == 1) {
            ghiHandleStatus(connection);
            if (!ghiCloseConnection(connection)) {
                connection->processing = 0;
                connection->state = 11;
                return 0;
            }
            ghiCallCompletedCallback((struct Ctx *)connection);
            if (!ghiFreeConnectionData(connection)) {
                connection->processing = 0;
                return 0;
            }
        } else {
            if (!ghiCloseConnection(connection)) {
                connection->processing = 0;
                connection->state = 11;
                return 0;
            }
            ghiCallCompletedCallback((struct Ctx *)connection);
            if (!ghiFreeConnectionData(connection)) {
                connection->processing = 0;
                return 0;
            }
        }
    } else {
        connection->processing = 0;
    }

    return completed;
}
