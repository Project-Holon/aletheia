/*
 * function: func_021C0998
 * address:  0x021C0998
 * packet:   pkt_ov114_021C0998
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiNewConnection (ghttpconnection.o)
 *
 * symbols:
 *   func_021C0370                    0x021c0370 arm  ov114
 *   func_021C08B0                    0x021c08b0 arm  ov114
 *   func_021C0374                    0x021c0374 arm  ov114
 *   func_020923B0                    0x020923b0 arm
 *   func_021BFBD0                    0x021bfbd0 arm  ov114
 *   func_021C0D40                    0x021c0d40 arm  ov114
 *   g_021D3B30                       0x021d3b30 data
 */

#include "../include/G_GHIGlobals.h"

typedef struct GHIConnection {
    int inUse;               /* +0x000 */
    int index;               /* +0x004 */
    int uniqueID;            /* +0x008 */
    int f00C;                /* +0x00c */
    int f010;                /* +0x010 */
    int f014;                /* +0x014 */
    int f018;                /* +0x018 */
    int f01C;                /* +0x01c */
    short f020;              /* +0x020 */
    char pad022[0x2];
    int f024;                /* +0x024 */
    char pad028[0x4];
    int f02C;                /* +0x02c */
    int f030;                /* +0x030 */
    char pad034[0x4];
    int f038;                /* +0x038 */
    int f03C;                /* +0x03c */
    int f040;                /* +0x040 */
    int f044;                /* +0x044 */
    int f048;                /* +0x048 */
    int f04C;                /* +0x04c */
    int f050;                /* +0x050 */
    int f054;                /* +0x054 */
    char sendBuffer[0x24];   /* +0x058 */
    char encodeBuffer[0x24]; /* +0x07c */
    char recvBuffer[0x24];   /* +0x0a0 */
    char decodeBuffer[0x24]; /* +0x0c4 */
    char pad0E8[0x24];
    int f10C;                /* +0x10c */
    int f110;                /* +0x110 */
    int f114;                /* +0x114 */
    int f118;                /* +0x118 */
    int f11C;                /* +0x11c */
    int f120;                /* +0x120 */
    int f124;                /* +0x124 */
    int f128;                /* +0x128 */
    int f12C;                /* +0x12c */
    int f130;                /* +0x130 */
    int f134;                /* +0x134 */
    int f138;                /* +0x138 */
    char pad13C[0x18];
    int f154;                /* +0x154 */
    char pad158[0x4];
    int f15C;                /* +0x15c */
    int f160;                /* +0x160 */
    int f164;                /* +0x164 */
    char pad168[0x20];
    int f188;                /* +0x188 */
    int f18C;                /* +0x18c */
    short f190;              /* +0x190 */
    char pad192[0x2];
    int f194;                /* +0x194 */
    char pad198[0x4];
    int f19C;                /* +0x19c */
    char pad1A0[0x2c];
    int f1CC;                /* +0x1cc */
    int f1D0;                /* +0x1d0 */
    char pad1D4[0x0];
} GHIConnection;

extern void func_021C0370(void);
extern int func_021C08B0(void);
extern void func_021C0374(void);
extern void *func_020923B0(void *dst, int c, unsigned int n);
extern int func_021BFBD0(unsigned int a0, unsigned int *a1, int a2, int a3);
extern int func_021C0D40(GHIConnection *connection);
extern struct GHIGlobals g_021D3B30;

GHIConnection *func_021C0998(void)
{
    int bResult;
    GHIConnection *connection;
    int slot;

    func_021C0370();

    slot = func_021C08B0();
    if (slot == -1) {
        func_021C0374();
        return 0;
    }

    connection = ((GHIConnection **)g_021D3B30.connections)[slot];
    func_020923B0(connection, 0, sizeof(GHIConnection));
    connection->inUse = 1;
    connection->index = slot;
    connection->uniqueID = g_021D3B30.nextUniqueID++;
    connection->f00C = 0;
    connection->f010 = 0;
    connection->f014 = 0;
    connection->f018 = 0;
    connection->f01C = 0;
    connection->f020 = 0;
    connection->f024 = 0;
    connection->f02C = 0;
    connection->f030 = 0;
    connection->f038 = 0;
    connection->f03C = 0;
    connection->f040 = 0;
    connection->f044 = 0;
    connection->f048 = 0;
    connection->f04C = 0;
    connection->f050 = -1;
    connection->f054 = 0;
    connection->f10C = 0;
    connection->f110 = 0;
    connection->f114 = 0;
    connection->f118 = 0;
    connection->f11C = 0;
    connection->f120 = 0;
    connection->f124 = 0;
    connection->f128 = 0;
    connection->f12C = -1;
    connection->f130 = 0;
    connection->f134 = 0;
    connection->f138 = 0;
    connection->f154 = 0;
    connection->f15C = 0;
    connection->f160 = 0;
    connection->f164 = 0;
    connection->f188 = 500;
    connection->f190 = 80;
    connection->f18C = 0;
    connection->f194 = 0;
    connection->f19C = 0;
    connection->f1D0 = 0;
    connection->f1CC = 0;

    bResult = func_021BFBD0((unsigned int)connection, (unsigned int *)connection->sendBuffer, 0x800, 0x1000);
    if (bResult)
        bResult = func_021BFBD0((unsigned int)connection, (unsigned int *)connection->encodeBuffer, 0x800, 0x400);
    if (bResult)
        bResult = func_021BFBD0((unsigned int)connection, (unsigned int *)connection->recvBuffer, 0x800, 0x800);
    if (bResult)
        bResult = func_021BFBD0((unsigned int)connection, (unsigned int *)connection->decodeBuffer, 0x800, 0x400);
    if (!bResult) {
        func_021C0D40(connection);
        func_021C0374();
        return 0;
    }

    g_021D3B30.numConnections++;
    func_021C0374();
    return connection;
}
