/*
 * function: func_02181748
 * address:  0x02181748
 * packet:   pkt_ov009_02181748
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsUdpEngineRemoveMsgHandler (gsudpengine)
 *
 * symbols:
 *   gsUdpEngineGetEngine     0x02180404 arm ov009
 *   gsDebugFormat            0x0217D254 arm ov009
 *   ArraySearch              0x021843E8 arm ov009
 *   ArrayDeleteAt            0x0218437C arm ov009
 *   g_021A3B9C               0x021A3B9C data
 *   g_021A3CE4               0x021A3CE4 data
 *   gsUdpMsgHandlerCompare2  0x02180430 arm ov009
 */

typedef struct { char c[16]; } GSUdpHdr;

typedef struct GSUdpMsgHandler {
    char pad0[0x10];
    char header[16];
    char pad1[0x1C];
} GSUdpMsgHandler;

typedef struct GSUdpEngineObject {
    char pad0[4];
    void *peers;
    void *handlers;
    int initialized;
} GSUdpEngineObject;

extern GSUdpEngineObject *gsUdpEngineGetEngine(void);
extern void gsDebugFormat(int theCat, int theType, unsigned char theLevel, char *theTokenStr, ...);
extern int ArraySearch(void *array, void *key, int (*comparator)(void *, void *), int fromIndex, int isSorted);
extern void ArrayDeleteAt(void *array, int n);
extern int gsUdpMsgHandlerCompare2(void *theFirstHandler, void *theSecondHandler);
extern void *memcpy(void *dst, const void *src, unsigned long n);
extern char g_021A3B9C[];
extern char g_021A3CE4[];

int func_02181748(char *theHeader)
{
    int index;
    GSUdpMsgHandler aHandler;
    GSUdpEngineObject *aUdp;

    aUdp = gsUdpEngineGetEngine();
    if (aUdp->initialized == 0)
    {
        gsDebugFormat(12, 0, 15, g_021A3B9C);
        return 3;
    }
    if (theHeader == 0 || theHeader[0] == 0)
    {
        gsDebugFormat(12, 0, 15, g_021A3CE4);
        return 10;
    }
    *(GSUdpHdr *)aHandler.header = *(GSUdpHdr *)theHeader;
    index = ArraySearch(aUdp->handlers, &aHandler, gsUdpMsgHandlerCompare2, 0, 0);
    if (index != -1)
        ArrayDeleteAt(aUdp->handlers, index);
    return 0;
}
