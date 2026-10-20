/*
 * file:     sciinterface.c
 * unit:     yes
 * function: sciInterfaceCreate, sciInterfaceInit, sciInterfaceDestroy, sciInterfaceSetSessionId, sciInterfaceSetConnectionId, sciGetServiceUrl
 * address:  0x021DF7FC
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * GameSpy Stats and Control client (libdwcgssc, object sciinterface.o): creation,
 * setup and teardown of the client state (SCInterface), its session and
 * connection GUIDs, and the URL of the stats service.
 *
 * symbols:
 *   OS_SNPrintf  0x02084F80  arm arm9
 *   sciWsInit  0x021E06DC  arm
 *   sciWsDestroy  0x021E0730  arm
 *   g_021ACEF8  0x021ACEF8  data
 *   g_021ACEFC  0x021ACEFC  data
 *   sSciServiceUrlFormat  0x021E412C  data
 *   sSciNoAvailabilityMessage  0x021E4184  data
 *   gScStatsServiceUrl  0x021E52B4  data
 *   gsDebugFormat  0x0217D254  arm ov009
 *   gsimalloc  0x0217EAB0  arm ov009
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm
 *   strcpy  0x02094798  arm
 */
#include "../../matched/arm9_sdk/libc/string.h"
#include "sc_types.h"
#include "../arm9/msl_string_mem.h"

#include "../arm9/os_printf.h"
#include "../ov009/gsmemory.h"
#include "../ov009/gsdebug.h"

extern int g_021ACEF8;
extern char g_021ACEFC[];
extern char gScStatsServiceUrl[128];
extern char sSciServiceUrlFormat[];
extern char sSciNoAvailabilityMessage[];

/*
 * sciInterfaceCreate: allocates a zeroed interface.  Also builds the stats
 * service URL the first time, when the availability check said it is up.
 */
int sciInterfaceCreate(SCInterface **theInterfaceOut)
{
    SCInterface *theInterface;

    if (g_021ACEF8 == 1) {
        if (gScStatsServiceUrl[0] == 0)
            OS_SNPrintf(gScStatsServiceUrl, 0x80, sSciServiceUrlFormat, g_021ACEFC);
    } else {
        return SCResult_NO_AVAILABILITY_CHECK;
    }
    theInterface = (SCInterface *)gsimalloc(sizeof(SCInterface));
    *theInterfaceOut = theInterface;
    if (theInterface == 0)
        return SCResult_OUT_OF_MEMORY;
    MSL_C_LIB_MemsetPtr(theInterface, 0, sizeof(SCInterface));
    return SCResult_NO_ERROR;
}

/*
 * sciInterfaceInit: starts the web services of the interface and, when that
 * works, clears the two GUID buffers and marks the interface live.
 */
int sciInterfaceInit(SCInterface *theInterface)
{
    int theResult = sciWsInit(&theInterface->mWebServices, theInterface);

    if (theResult != 0)
        return theResult;
    MSL_C_LIB_MemsetPtr(theInterface->mSessionId, 0, SC_GUID_SIZE);
    MSL_C_LIB_MemsetPtr(theInterface->mConnectionId, 0, SC_GUID_SIZE);
    theInterface->mInit = 1;
    return SCResult_NO_ERROR;
}

/*
 * sciInterfaceDestroy: stops the web services, blanks the two GUID buffers
 * with the 0xde 0xad signature on the front of each and clears the live flag.
 */
void sciInterfaceDestroy(SCInterface *theInterface)
{
    unsigned int theZero = 0;
    unsigned int theGuidSize = SC_GUID_SIZE;

    sciWsDestroy(&theInterface->mWebServices);
    MSL_C_LIB_MemsetPtr(theInterface->mSessionId, theZero, theGuidSize);
    MSL_C_LIB_MemsetPtr(theInterface->mConnectionId, theZero, theGuidSize);
    theInterface->mSessionId[0] = 0xde;
    theInterface->mSessionId[1] = 0xad;
    theInterface->mConnectionId[0] = 0xde;
    theInterface->mConnectionId[1] = 0xad;
    theInterface->mInit = theZero;
}

/*
 * sciInterfaceSetSessionId: copies the session GUID, or clears it when no GUID
 * is given.  Written as an early-return `if` so the compiler predicates the
 * store, the register clear and the epilogue (moveq/strbeq/popeq).
 */
void sciInterfaceSetSessionId(SCInterface *theInterface, const char *theSessionId)
{
    if (theSessionId == 0) {
        theInterface->mSessionId[0] = 0;
        return;
    }
    strcpy((char *)theInterface->mSessionId, theSessionId);
}

/* sciInterfaceSetConnectionId: as sciInterfaceSetSessionId for the connection GUID. */
void sciInterfaceSetConnectionId(SCInterface *theInterface, const char *theConnectionId)
{
    if (theConnectionId == 0) {
        theInterface->mConnectionId[0] = 0;
        return;
    }
    strcpy((char *)theInterface->mConnectionId, theConnectionId);
}

/*
 * sciGetServiceUrl: the URL of the stats service (built on first use), or null
 * after a debug message when the availability check has not passed.
 */
char *sciGetServiceUrl(void)
{
    if (g_021ACEF8 == 1) {
        if (gScStatsServiceUrl[0] == 0)
            OS_SNPrintf(gScStatsServiceUrl, 128, sSciServiceUrlFormat, g_021ACEFC);
        return gScStatsServiceUrl;
    }
    gsDebugFormat(0, 3, 1, sSciNoAvailabilityMessage);
    return 0;
}
