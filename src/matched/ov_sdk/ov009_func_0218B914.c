/*
 * function: gpiProcessRemoteAuthResponse
 * address:  0x0218B914
 * packet:   pkt_ov009_0218B914
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiProcessRemoteAuthResponse (gpiconnect.o)
 *
 * symbols:
 *   gpiCheckForError  0x0219329C  arm   ov009
 *   gpiValueForKey  0x02193418  arm   ov009
 *   gpiSetError  0x02193710  arm   ov009
 *   gpiCallErrorCallback  0x02189D78  arm   ov009
 *   atoi  0x020964E0  arm  
 *   g_021A492C     0x021A492C  data  ov009
 *   g_021A49AC     0x021A49AC  data  ov009
 *   g_021A48E8     0x021A48E8  data  ov009
 */

typedef struct GPIConnection {
    unsigned char pad0[0x1A4];
    int f1A4;
    unsigned char pad1[0x208 - 0x1A8];
    char *f208;
    unsigned char pad2[0x610 - 0x20C];
    int f610;
} GPIConnection;

extern int gpiCheckForError(int *connection, const char *input, int fatal);
extern int gpiValueForKey(const char *command, const char *key, char *value, int valueLen);
typedef unsigned int   u32;
extern void gpiSetError(int *connection, int result, int errorString);
extern int gpiCallErrorCallback(int *connection, int a1, int a2);
extern int atoi(u32 a0);
extern char g_021A492C[];
extern char g_021A49AC[];
extern char g_021A48E8[];

int gpiProcessRemoteAuthResponse(void **connection, char *input)
{
    GPIConnection *iconnection;
    char buffer[512];

    iconnection = (GPIConnection *)*connection;
    if (gpiCheckForError((int *)connection, input, 1))
        return 4;
    if (!gpiValueForKey(iconnection->f208, g_021A492C, buffer, 512)) {
        gpiSetError((int *)connection, 1, (int)g_021A49AC);
        gpiCallErrorCallback((int *)connection, 3, 1);
        return 3;
    }
    iconnection->f610 = atoi((u32)buffer);
    if (!gpiValueForKey(iconnection->f208, g_021A48E8, buffer, 512)) {
        gpiSetError((int *)connection, 1, (int)g_021A49AC);
        gpiCallErrorCallback((int *)connection, 3, 1);
        return 3;
    }
    iconnection->f1A4 = atoi((u32)buffer);
    return 0;
}
