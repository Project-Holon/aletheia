/*
 * function: func_02199BE4
 * address:  0x02199BE4
 * packet:   pkt_ov009_02199BE4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CheckNatifyStatus (libdwcgsnatneg.TWL.HYB.a(natneg.o))
 *
 * symbols:
 *   current_time       0x0217F264  arm  ov009
 *   NatifyThink        0x02198E74  arm  ov009
 *   DetermineNatType   0x02198E80  arm  ov009
 *   closesocket        0x0217EB2C  arm  ov009
 *   g_021AE698         0x021AE698  data
 *   g_021AE6C8         0x021AE6C8  data
 *   g_021A5A70         0x021A5A70  data
 */

typedef unsigned int u32;

typedef struct NAT
{
    char pad0[0x8C];
    int natType;
    int mappingScheme;
    char pad1[0x44];
} NAT;

typedef struct NatifyState
{
    int negotiateList;
    int pad;
    int natMappingScheme;
    void (*natifyCallback)(int success, NAT nat);
    u32 natifyStartTime;
} NatifyState;

typedef struct NatSocks
{
    int natType;
    int ertSock;
    int mappingSock;
} NatSocks;

extern u32 current_time(void);
extern int NatifyThink();
extern int DetermineNatType();
extern int closesocket();
extern NatifyState g_021AE698;
extern NAT g_021AE6C8;
extern NatSocks g_021A5A70;

int func_02199BE4(int sock)
{
    int active = 1;
    int success;

    if (sock != -1)
    {
        if (current_time() - g_021AE698.natifyStartTime < 10000)
            active = NatifyThink(sock, &g_021AE6C8);
        else
            active = 0;
        if (active)
            goto done;
        success = DetermineNatType(&g_021AE6C8);
        g_021AE698.natifyCallback(success, g_021AE6C8);
        g_021A5A70.natType = g_021AE6C8.natType;
        g_021AE698.natMappingScheme = g_021AE6C8.mappingScheme;
        if (g_021A5A70.mappingSock != -1)
        {
            closesocket();
            g_021A5A70.mappingSock = -1;
        }
        if (g_021A5A70.ertSock != -1)
        {
            closesocket();
            g_021A5A70.ertSock = -1;
        }
    }
done:
    return active;
}
