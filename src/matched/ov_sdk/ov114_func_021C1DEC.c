/*
 * function: func_021C1DEC
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
 *   func_021C3BAC                    0x021c3bac arm  ov114
 *   func_021C3D10                    0x021c3d10 arm  ov114
 *   func_021C3E10                    0x021c3e10 arm  ov114
 *   func_021C3EC0                    0x021c3ec0 arm  ov114
 *   func_021C4150                    0x021c4150 arm  ov114
 *   func_021C4384                    0x021c4384 arm  ov114
 *   func_021C4684                    0x021c4684 arm  ov114
 *   func_021C4764                    0x021c4764 arm  ov114
 *   func_021C492C                    0x021c492c arm  ov114
 *   func_021C4E7C                    0x021c4e7c arm  ov114
 *   func_021C5430                    0x021c5430 arm  ov114
 *   func_0217D254                    0x0217d254 arm  ov009
 *   func_021C0E58                    0x021c0e58 arm  ov114
 *   func_0217EF50                    0x0217ef50 arm  ov009
 *   func_021C1D30                    0x021c1d30 arm  ov114
 *   func_021C0B4C                    0x021c0b4c arm  ov114
 *   func_021C0244                    0x021c0244 arm  ov114
 *   func_021C0C14                    0x021c0c14 arm  ov114
 *   g_021CED74                       0x021ced74 data
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

extern void func_021C3BAC(GHIConnection *connection);
extern void func_021C3D10(GHIConnection *connection);
extern void func_021C3E10(GHIConnection *connection);
extern void func_021C3EC0(GHIConnection *connection);
extern void func_021C4150(GHIConnection *connection);
extern void func_021C4384(GHIConnection *connection);
extern void func_021C4684(GHIConnection *connection);
extern void func_021C4764(GHIConnection *connection);
extern void func_021C492C(GHIConnection *connection);
extern void func_021C4E7C(GHIConnection *connection);
extern void func_021C5430(GHIConnection *connection);
extern void func_0217D254(int theCat, int theType, unsigned char theLevel,
                          const char *theTokenStr, ...);
extern void func_021C0E58(GHIConnection *connection);
extern int func_0217EF50(int sock);
extern void func_021C1D30(GHIConnection *connection);
extern int func_021C0B4C(GHIConnection *connection);
extern void func_021C0244(GHIConnection *connection);
extern int func_021C0C14(GHIConnection *connection);
extern char g_021CED74[];

int func_021C1DEC(GHIConnection *connection)
{
    int completed;

    if (connection->processing)
        return 0;
    connection->processing = 1;

    if (connection->state == 0)
        func_021C3BAC(connection);
    if (connection->state == 1)
        func_021C3D10(connection);
    if (connection->state == 2)
        func_021C3E10(connection);
    if (connection->state == 3)
        func_021C3EC0(connection);
    if (connection->state == 4)
        func_021C4150(connection);
    if (connection->state == 5)
        func_021C4384(connection);
    if (connection->state == 6)
        func_021C4684(connection);
    if (connection->state == 7)
        func_021C4764(connection);
    if (connection->state == 8)
        func_021C492C(connection);
    if (connection->state == 9)
        func_021C4E7C(connection);
    if (connection->state == 10)
        func_021C5430(connection);
    if (connection->state == 11)
        func_0217D254(8, 3, 0x10, g_021CED74);

    if (connection->redirect)
        func_021C0E58(connection);

    completed = connection->completed;
    if (connection->result == 0x12 && !completed) {
        if (!func_0217EF50(connection->socket))
            connection->completed = 1;
    }

    if (connection->completed) {
        if (connection->handleStatus == 1) {
            func_021C1D30(connection);
            if (!func_021C0B4C(connection)) {
                connection->processing = 0;
                connection->state = 11;
                return 0;
            }
            func_021C0244(connection);
            if (!func_021C0C14(connection)) {
                connection->processing = 0;
                return 0;
            }
        } else {
            if (!func_021C0B4C(connection)) {
                connection->processing = 0;
                connection->state = 11;
                return 0;
            }
            func_021C0244(connection);
            if (!func_021C0C14(connection)) {
                connection->processing = 0;
                return 0;
            }
        }
    } else {
        connection->processing = 0;
    }

    return completed;
}
