/*
 * file:     gpisearch.c
 * unit:     yes
 * function: gpiStartProfileSearch, gpiInitSearchData, gpiStartSearch, gpiProfileSearch, gpiOthersBuddyList, gpiProcessSearch, gpiProcessSearches
 * address:  0x021903B0
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
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   gpiSetErrorString  0x02193734  arm  ov009
 *   socket  0x0217EB18  arm  ov009
 *   gpiSetError  0x02193710  arm  ov009
 *   gpiCallErrorCallback  0x02189D78  arm  ov009
 *   SetSockBlocking  0x0217EE50  arm  ov009
 *   SOC_GetHostByName  0x0215F650  arm  ov009
 *   connect  0x0217EC08  arm  ov009
 *   GOAGetLastError  0x0217ED54  arm  ov009
 *   current_time  0x0217F264  arm  ov009
 *   g_021A5280     0x021A5280  data
 *   g_021A5290     0x021A5290  data
 *   g_021A52B8     0x021A52B8  data
 *   g_021A5240     0x021A5240  data
 *   g_021A52EC     0x021A52EC  data
 *   g_021A531C     0x021A531C  data
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm
 *   strzcpy  0x0219327C  arm  ov009
 *   _strlwr  0x0217F21C  arm  ov009
 *   g_021A5344     0x021A5344  data ov009
 *   gpiSendFromBuffer  0x0218998C  arm  ov009
 *   gpiCheckSocketConnect  0x02193488  arm  ov009
 *   gpiAppendStringToBuffer  0x0218946C  arm  ov009
 *   gpiAppendIntToBuffer  0x0218949C  arm  ov009
 *   gpiAppendCharToBuffer  0x0218934C  arm  ov009
 *   gpiEncodeString  0x02193748  arm  ov009
 *   gpiRecvToBuffer  0x02189780  arm  ov009
 *   gpiCheckForError  0x0219329C  arm  ov009
 *   gpiReadKeyAndValue  0x0219359C  arm  ov009
 *   gpiValueForKey  0x02193418  arm  ov009
 *   gpiAddCallback  0x02189DFC  arm  ov009
 *   gsiSafeStrcpyA  0x021803BC  arm  ov009
 *   msleep  0x0217F2BC  arm  ov009
 *   gsirealloc  0x0217EAC8  arm  ov009
 *   gsifree  0x0217EAE0  arm  ov009
 *   strcmp  0x020948E0  arm
 *   strstr  0x02094B20  arm
 *   atoi  0x020964E0  arm
 *   g_02191848                               0x021A5358  data
 *   g_0219184C                               0x021A5370  data
 *   g_02191850                               0x021A5374  data
 *   g_02191854                               0x021A53A0  data
 *   g_02191858                               0x021A53AC  data
 *   g_0219185C                               0x021A53B8  data
 *   g_02191860                               0x021A53C4  data
 *   g_02191864                               0x021A53D4  data
 *   g_02191868                               0x021A53E0  data
 *   g_0219186C                               0x021A53E8  data
 *   g_02191870                               0x021A53F8  data
 *   g_02191874                               0x021A5400  data
 *   g_02191878                               0x021A540C  data
 *   g_0219187C                               0x021A5418  data
 *   g_02191880                               0x021A5424  data
 *   g_02191884                               0x021A542C  data
 *   g_02191888                               0x021A543C  data
 *   g_0219188C                               0x021A544C  data
 *   g_02191890                               0x021A5454  data
 *   g_02191894                               0x021A545C  data
 *   g_02191898                               0x021A5468  data
 *   g_0219189C                               0x021A5474  data
 *   g_021918A0                               0x021A5480  data
 *   g_021918A4                               0x021A5488  data
 *   g_021918A8                               0x021A5494  data
 *   g_021918AC                               0x021A54A0  data
 *   g_021918B0                               0x021A54A8  data
 *   g_021918B4                               0x021A54B4  data
 *   g_021918B8                               0x021A54C4  data
 *   g_021918BC                               0x021A54D0  data
 *   g_021918C0                               0x021A54D8  data
 *   g_021918C4                               0x021A54DC  data
 *   g_021918C8                               0x021A54EC  data
 *   g_021918CC                               0x021A54FC  data
 *   g_021918D0                               0x021A550C  data
 *   g_021918D4                               0x021A5520  data
 *   g_021918D8                               0x021A5530  data
 *   g_021918DC                               0x021ACEFC  data
 *   g_021918E0                               0x021A553C  data
 *   g_021918E4                               0x021A5544  data
 *   g_021918EC                               0x021A5570  data
 *   g_021918F0                               0x021A5578  data
 *   g_021918F4                               0x021A5580  data
 *   g_021918F8                               0x021A5584  data
 *   g_021918FC                               0x021A5280  data
 *   g_02191900                               0x021A5588  data
 *   g_02191904                               0x021A5590  data
 *   g_02191908                               0x021A559C  data
 *   g_0219190C                               0x021A55A8  data
 *   g_02191910                               0x021A55B4  data
 *   g_02191914                               0x021A55C0  data
 *   g_02191918                               0x021A55C8  data
 *   g_0219191C                               0x021A55F0  data
 *   g_02192A94                               0x021A55F4  data
 *   g_02192A98                               0x021A55F8  data
 *   g_02192A9C                               0x021A5600  data
 *   g_02192AA0                               0x021A5608  data
 *   g_02192AA4                               0x021A560C  data
 *   g_02192AA8                               0x021A5614  data
 *   g_02192AAC                               0x021A5620  data
 *   g_02192AB0                               0x021A5624  data
 *   g_02192AB4                               0x021A562C  data
 *   g_02192AB8                               0x021A5630  data
 *   g_02192ABC                               0x021A5638  data
 *   g_02192AC0                               0x021A5640  data
 *   g_02192AC4                               0x021A5644  data
 *   g_02192AC8                               0x021A564C  data
 *   g_02192ACC                               0x021A5654  data
 *   g_02192AD0                               0x021A5660  data
 *   g_02192AD4                               0x021A5590  data
 *   g_02192AD8                               0x021A55C8  data
 *   g_02192ADC                               0x021A5280  data
 *   g_02192AE0                               0x021A5668  data
 *   g_02192AE4                               0x021A5588  data
 *   g_02192DFC                               0x021A566C  data
 *   g_02192E00                               0x021A5674  data
 *   g_02192E04                               0x021A5680  data
 *   g_02192E08                               0x021A5688  data
 *   g_02192E0C                               0x021A5690  data
 *   gpiRemoveOperation  0x0218e240  arm   ov009
 *   gpiProcess  0x02186E9C  arm
 *   gpiAddOperation  0x0218E114  arm
 */
#include "gpi_types.h"
#include "qr2_types.h"
extern void *__builtin__clear(void *dest, unsigned long size);

#define GPITrue  1
#define GPIFalse 0
#define GP_NON_FATAL 0
#define GP_FATAL     1
#define GP_VALID   1
#define GP_INVALID 0
#define GP_MORE 0x0600
#define GP_DONE 0x0601
#define GP_ONLINE 1
#define GPI_SEARCH_PROFILE            1
#define GPI_SEARCH_IS_VALID           2
#define GPI_SEARCH_NICKS              3
#define GPI_SEARCH_PLAYERS            4
#define GPI_SEARCH_CHECK              5
#define GPI_SEARCH_NEWUSER            6
#define GPI_SEARCH_OTHERS_BUDDY       7
#define GPI_SEARCH_SUGGEST_UNIQUE     8
#define GPI_SEARCH_OTHERS_BUDDY_LIST  9
#define GPI_SEARCH_PROFILE_UNIQUENICK 10
#define GPI_SEARCH_PROFILE_LIST       11
#define GPI_ADD_NICKS                   3
#define GPI_ADD_PMATCH                  4
#define GPI_ADD_REVERSE_BUDDIES         8
#define GPI_ADD_SUGGESTED_UNIQUE        9
#define GPI_ADD_REVERSE_BUDDIES_LIST    13
#define GPI_ADD_PROFILE_LIST            15
#define GPI_SEARCH_CONNECTION_FAILED 0x0d01
#define GPI_SEARCH_TIMED_OUT         0x0d02
#define GPI_CONNECTING   1
#define GPI_CONNECTED    3
#define GPI_DISCONNECTED 4
#define GPI_WAITING      4
#define GPI_FINISHING    5
#define GPI_SEARCH_TIMEOUT 60000
#define GP_SEARCH_TIMED_OUT 0x0d02
#define GP_PARSE 1
#define Error(connection, result, string) \
    { gpiSetErrorString(connection, string); return (result); }
#define CallbackError(connection, result, code, string) \
    { gpiSetError(connection, (code), string); \
      gpiCallErrorCallback(connection, (result), GP_NON_FATAL); return (result); }
#define CallbackFatalError(connection, result, code, string) \
    { gpiSetError(connection, (code), string); \
      gpiCallErrorCallback(connection, (result), GP_FATAL); return (result); }
#define CHECK_RESULT(result) \
    { GPResult __result__ = (result); if (__result__ != GP_NO_ERROR) { return __result__; } }
#define freeclear(mem) \
    { gsifree(mem); (mem) = 0; }
extern void *gsimalloc(unsigned long size);
extern void gpiSetErrorString(void **connection, char *string);
extern int socket(int pf, int type, int protocol);
extern void gpiSetError(void **connection, int code, char *string);
extern int gpiCallErrorCallback(void **connection, int result, int fatal);
extern int SetSockBlocking(int sock, int isblocking);
extern SOCHostEnt *SOC_GetHostByName(char *name);
struct SOCSockAddr;
extern int connect(int sock, struct SOCSockAddr *addr, int len);
extern int GOAGetLastError(int sock);
extern unsigned int current_time(void);
extern void *MSL_C_LIB_MemsetPtr(void *p, int c, u32 n);
extern int gpiAddOperation(void **connection, int type, void *data, GPIOperation **operation, int blocking, GPCallback callback, void *param);
extern int gpiProcess(void **connection, int operationID);
extern void strzcpy(char *dest, char *src, int len);
extern char *_strlwr(char *s);
extern GPResult gpiSendFromBuffer(GPConnection *connection, int sock, GPIBuffer *buffer,
                              GPIBool *connClosed, GPIBool flag, char *tag);
extern GPResult gpiCheckSocketConnect(GPConnection *connection, int sock, int *state);
extern int gpiAppendStringToBuffer(void **connection, GPIBuffer *buffer, const char *string);
extern int gpiAppendIntToBuffer(void **connection, GPIBuffer *buffer, int value);
extern int gpiAppendCharToBuffer(int *connection, int *buffer, int c);
extern void gpiEncodeString(const char *plaintext, char *encoded);
struct GPIBuffer;
extern GPResult gpiRecvToBuffer(int *connection, int sock, struct GPIBuffer *inputBuffer, int *bytesRead, int *connClosed, char *id);
extern int gpiCheckForError(void **connection, char *input, int flag);
extern int gpiReadKeyAndValue(void **connection, char *buffer, int *index, char *key, char *value);
extern int gpiValueForKey(const char *command, const char *key, char *value, int valueLen);
extern int gpiAddCallback(void **connection, GPICallback callback, void *arg, GPIOperation *operation, int type);
extern int gsiSafeStrcpyA(char *dst, const char *src, unsigned int n);
extern void msleep(u32 ms);
extern void *gsirealloc(void *ptr, unsigned int size);
extern void gsifree(void *ptr);
extern int strcmp(const char *s1, const char *s2);
extern unsigned char *strstr(unsigned char *s1, unsigned char *s2);
extern int atoi(const char *s);
extern void gpiRemoveOperation(void **connection, GPIOperation *operation);
int gpiStartProfileSearch(void **connection, GPIOperation *operation);
int gpiInitSearchData(void **connection, GPISearchData **out, int type);
int gpiStartSearch(void **connection, GPISearchData *data, int blocking, GPCallback callback, void *param);
int gpiProfileSearch(void **connection, char *nick, char *uniquenick, char *email, char *firstname, char *lastname, int icquin, int skip, int blocking, GPCallback callback, void *param);
int gpiOthersBuddyList(void **connection, int *profiles, int numOfProfiles, int blocking, void (*callback)(void **, void *, void *), void *param);
GPResult gpiProcessSearch(GPConnection *connection, GPIOperation *operation);
int gpiProcessSearches(void **connection);
extern char g_021A5280[];
extern char g_021A5290[];
extern char g_021A52B8[];
extern char g_021A5240[];
extern char g_021A52EC[];
extern char g_021A531C[];
extern char g_021A5344[];
extern char g_02191848[];
extern char g_0219184C[];
extern char g_02191850[];
extern char g_02191854[];
extern char g_02191858[];
extern char g_0219185C[];
extern char g_02191860[];
extern char g_02191864[];
extern char g_02191868[];
extern char g_0219186C[];
extern char g_02191870[];
extern char g_02191874[];
extern char g_02191878[];
extern char g_0219187C[];
extern char g_02191880[];
extern char g_02191884[];
extern char g_02191888[];
extern char g_0219188C[];
extern char g_02191890[];
extern char g_02191894[];
extern char g_02191898[];
extern char g_0219189C[];
extern char g_021918A0[];
extern char g_021918A4[];
extern char g_021918A8[];
extern char g_021918AC[];
extern char g_021918B0[];
extern char g_021918B4[];
extern char g_021918B8[];
extern char g_021918BC[];
extern char g_021918C0[];
extern char g_021918C4[];
extern char g_021918C8[];
extern char g_021918CC[];
extern char g_021918D0[];
extern char g_021918D4[];
extern char g_021918D8[];
extern char g_021918DC[];
extern char g_021918E0[];
extern char g_021918E4[];
extern char g_021918EC[];
extern char g_021918F0[];
extern char g_021918F4[];
extern char g_021918F8[];
extern char g_021918FC[];
extern char g_02191900[];
extern char g_02191904[];
extern char g_02191908[];
extern char g_0219190C[];
extern char g_02191910[];
extern char g_02191914[];
extern char g_02191918[];
extern char g_0219191C[];
extern char g_02192A94[];
extern char g_02192A98[];
extern char g_02192A9C[];
extern char g_02192AA0[];
extern char g_02192AA4[];
extern char g_02192AA8[];
extern char g_02192AAC[];
extern char g_02192AB0[];
extern char g_02192AB4[];
extern char g_02192AB8[];
extern char g_02192ABC[];
extern char g_02192AC0[];
extern char g_02192AC4[];
extern char g_02192AC8[];
extern char g_02192ACC[];
extern char g_02192AD0[];
extern char g_02192AD4[];
extern char g_02192AD8[];
extern char g_02192ADC[];
extern char g_02192AE0[];
extern char g_02192AE4[];
extern char g_02192DFC[];
extern char g_02192E00[];
extern char g_02192E04[];
extern char g_02192E08[];
extern char g_02192E0C[];




/*
 * sdk:      gpiStartProfileSearch (libdwcgsgp.TWL.HYB.a gpisearch.o)
 */
int gpiStartProfileSearch(void **connection, GPIOperation *operation)
{
    GPISearchData *data;
    int rcode;
    SOCHostEnt *host;
    int error;

    data = (GPISearchData *)operation->data;

    data->inputBuffer.size = 4096;
    data->inputBuffer.buffer = (char *)gsimalloc(data->inputBuffer.size + 1);
    if (data->inputBuffer.buffer == 0) {
        gpiSetErrorString(connection, g_021A5280);
        return 1;
    }

    data->sock = socket(2, 1, 0);
    if (data->sock == -1) {
        gpiSetError(connection, 5, g_021A5290);
        gpiCallErrorCallback(connection, 3, 1);
        return 3;
    }

    if (!SetSockBlocking(data->sock, 0)) {
        gpiSetError(connection, 5, g_021A52B8);
        gpiCallErrorCallback(connection, 3, 1);
        return 3;
    }

    host = SOC_GetHostByName(g_021A5240);
    if (host == 0) {
        gpiSetError(connection, 5, g_021A52EC);
        gpiCallErrorCallback(connection, 3, 1);
        return 3;
    }

    {
        SOCSockAddrIn address = {0};

        address.family = 2;
        address.addr = **(unsigned int **)host->addrList;
        address.port = 0xCD74;

        rcode = connect(data->sock, (struct SOCSockAddr *)(&address), sizeof(address));
    }
    if (rcode == -1) {
        error = GOAGetLastError(data->sock);
        if (error != -6 && error != -26 && error != -76) {
            gpiSetError(connection, 5, g_021A531C);
            gpiCallErrorCallback(connection, 3, 1);
            return 3;
        }
    }

    operation->state = 1;
    data->searchStartTime = current_time();
    return 0;
}




/*
 * gpiCreateSearchData-alike: allocate a 0x1a0-byte GPISearchData, clear it,
 * default the socket to -1 and the type to the caller's, hand the caller a
 * 0x1001-byte output buffer (size field 0x1000), and publish the object
 * through *out.  Returns 1 (and sets the "Out of memory" error string) when
 * either allocation fails, else 0.
 */
int gpiInitSearchData(void **connection, GPISearchData **out, int type)
{
    GPISearchData *data = gsimalloc(0x1a0);

    if (data == 0) {
        gpiSetErrorString(connection, g_021A5280);
        return 1;
    }
    MSL_C_LIB_MemsetPtr(data, 0, 0x1a0);
    data->type = type;
    data->sock = -1;
    data->inputBuffer.buffer = 0;
    data->inputBuffer.len = 0;
    data->inputBuffer.pos = 0;
    data->inputBuffer.size = 0;
    data->outputBuffer.len = 0;
    data->outputBuffer.pos = 0;
    data->outputBuffer.size = 0x1000;
    data->outputBuffer.buffer = gsimalloc(0x1001);
    if (data->outputBuffer.buffer == 0) {
        gpiSetErrorString(connection, g_021A5280);
        return 1;
    }
    data->processing = 0;
    data->remove = 0;
    *out = data;
    return 0;
}




/*
 * Bump the +0x238 counter of the object at *a, run the three-stage request
 * with a local out-parameter, and stop at the first stage that reports an
 * error.  The third stage is skipped when the produced object's +8 word is
 * zero.  Returns 0 when every stage passes.
 */
int gpiStartSearch(void **connection, GPISearchData *data, int blocking, GPCallback callback, void *param)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    GPIOperation *operation;
    int r;

    iconnection->numSearches++;

    r = gpiAddOperation(connection, 3, data, &operation, blocking, callback, param);
    if (r != 0)
        return r;
    r = gpiStartProfileSearch(connection, operation);
    if (r != 0)
        return r;

    if (operation->blocking != 0) {
        r = gpiProcess(connection, operation->id);
        if (r != 0)
            return r;
    }
    return 0;
}



int gpiProfileSearch(void **connection, char *nick, char *uniquenick, char *email,
                  char *firstname, char *lastname, int icquin, int skip,
                  int blocking, GPCallback callback, void *param)
{
    GPISearchData *data;
    int result;

    if ((nick == 0) || (*nick == 0))
        if ((email == 0) || (*email == 0))
            if ((firstname == 0) || (*firstname == 0))
                if ((lastname == 0) || (*lastname == 0))
                    if (icquin == 0)
                        if ((uniquenick == 0) || (*uniquenick == 0)) {
                            gpiSetErrorString(connection, g_021A5344);
                            return 2;
                        }

    result = gpiInitSearchData(connection, &data, 1);
    if (result != 0)
        return result;

    if (nick == 0)
        data->nick[0] = 0;
    else
        strzcpy(data->nick, nick, 0x1f);
    if (uniquenick == 0)
        data->uniquenick[0] = 0;
    else
        strzcpy(data->uniquenick, uniquenick, 0x15);
    if (email == 0)
        data->email[0] = 0;
    else
        strzcpy(data->email, email, 0x33);
    _strlwr(data->email);
    if (firstname == 0)
        data->firstname[0] = 0;
    else
        strzcpy(data->firstname, firstname, 0x1f);
    if (lastname == 0)
        data->lastname[0] = 0;
    else
        strzcpy(data->lastname, lastname, 0x1f);

    data->icquin = icquin;
    if (skip < 0)
        skip = 0;
    data->skip = skip;

    result = gpiStartSearch(connection, data, blocking, callback, param);
    if (result != 0)
        return result;
    return 0;
}




/*
 * sdk:      gpiOthersBuddyList (libdwcgsgp.TWL.HYB.a(gpisearch.o))
 */
int gpiOthersBuddyList(void **connection, int *profiles, int numOfProfiles, int blocking, void (*callback)(void **, void *, void *), void *param)
{
    GPISearchData *data;
    int result;

    result = gpiInitSearchData(connection, (GPISearchData * *)&data, 9);
    if (result != 0)
        return result;
    data->revBuddyProfileIds = profiles;
    data->numOfRevBuddyProfiles = numOfProfiles;
    result = gpiStartSearch(connection, data, blocking, callback, param);
    if (result != 0)
        return result;
    return 0;
}




/*
 * sdk:      gpiProcessSearch (TwlDWC/libdwcgsgp.TWL.HYB.a gpisearch.o)
 *
 * levers:   GPIBool is `enum _GPIBool` in the vendor DWARF, not `int`; the
 *           enum type is what keeps `loop` in r8 and the GPITrue /
 *           namespace-index scratch in r9/sb (idiom
 *           an-enum-type-keeps-values-out-of-constant-folding).  The `symbols:`
 *           block must have no blank `*` line inside it: read_header() ends the
 *           block at the first line that is not a symbol, so the data half was
 *           silently dropped and every g_ site wildcarded.  The g_0x0219xxxx
 *           names are pool addresses; their declared addresses are the pool
 *           *values* in asm/overlays/ov009.s (0x021A53xx..0x021A5xxx).
 *
 * Full-body reconstruction of gpiProcessSearch.  Types, struct offsets and
 * source line numbers are taken from the DWARF of the vendor member
 * (scratch/laneS10/gpisearch.o); the body tracks the public GameSpy
 * gpiSearch.c with the DWC deltas (GPI_SEARCH_PROFILE_LIST = 0xb in both the
 * request-build and response-parse switches, and GPISearchData.profile /
 * .maxResults at +0x198 / +0x19c).
 */
GPResult gpiProcessSearch(GPConnection *connection, GPIOperation *operation)
{
    int state;
    GPISearchData *data;
    char key[512];
    char value[512];
    GPIBool done;
    int index;
    int oldIndex;
    GPIBool loop;
    GPIBool more;
    GPICallback callback;
    GPIConnection *iconnection = (GPIConnection *)*connection;
    int len;
    GPIBool connClosed;
    GPResult result;
    void *tempPtr;
    GPIBool doneParsingMatch;
    int rcode;
    int pid;
    GPProfileSearchMatch *match;
    GPUniqueMatch *uniqueNickMatch;

    char passwordenc[45];

    data = (GPISearchData *)operation->data;

    if (operation->blocking)
        loop = GPITrue;
    else
        loop = GPIFalse;

    if (!operation->blocking && (current_time() - data->searchStartTime > GPI_SEARCH_TIMEOUT))
    {
        data->remove = GPITrue;
        CallbackError(connection, GP_NETWORK_ERROR, GP_SEARCH_TIMED_OUT, g_02191848);
    }

    do
    {
        CHECK_RESULT(gpiSendFromBuffer(connection, data->sock, &data->outputBuffer, &connClosed, GPITrue, g_0219184C));

        if (operation->state == GPI_CONNECTING)
        {
            CHECK_RESULT(gpiCheckSocketConnect(connection, data->sock, &state));

            if (state == GPI_DISCONNECTED)
                CallbackError(connection, GP_SERVER_ERROR, GPI_SEARCH_CONNECTION_FAILED, g_02191850);

            if (state == GPI_CONNECTED)
            {
                if (data->type == GPI_SEARCH_PROFILE)
                {
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191854);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191858);
                    gpiAppendIntToBuffer(connection, &data->outputBuffer, iconnection->sessKey);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_0219185C);
                    gpiAppendIntToBuffer(connection, &data->outputBuffer, iconnection->profileid);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191860);
                    gpiAppendIntToBuffer(connection, &data->outputBuffer, iconnection->namespaceID);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191864);
                    gpiAppendIntToBuffer(connection, &data->outputBuffer, iconnection->partnerID);
                    if (data->nick[0] != '\0')
                    {
                        gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191868);
                        gpiAppendStringToBuffer(connection, &data->outputBuffer, data->nick);
                    }
                    if (data->uniquenick[0] != '\0')
                    {
                        gpiAppendStringToBuffer(connection, &data->outputBuffer, g_0219186C);
                        gpiAppendStringToBuffer(connection, &data->outputBuffer, data->uniquenick);
                    }
                    if (data->email[0] != '\0')
                    {
                        gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191870);
                        gpiAppendStringToBuffer(connection, &data->outputBuffer, data->email);
                    }
                    if (data->firstname[0] != '\0')
                    {
                        gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191874);
                        gpiAppendStringToBuffer(connection, &data->outputBuffer, data->firstname);
                    }
                    if (data->lastname[0] != '\0')
                    {
                        gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191878);
                        gpiAppendStringToBuffer(connection, &data->outputBuffer, data->lastname);
                    }
                    if (data->icquin != 0)
                    {
                        gpiAppendStringToBuffer(connection, &data->outputBuffer, g_0219187C);
                        gpiAppendIntToBuffer(connection, &data->outputBuffer, data->icquin);
                    }
                    if (data->skip > 0)
                    {
                        gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191880);
                        gpiAppendIntToBuffer(connection, &data->outputBuffer, data->skip);
                    }
                }
                else if (data->type == GPI_SEARCH_PROFILE_UNIQUENICK)
                {
                    int i;
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191884);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191858);
                    gpiAppendIntToBuffer(connection, &data->outputBuffer, iconnection->sessKey);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_0219185C);
                    gpiAppendIntToBuffer(connection, &data->outputBuffer, iconnection->profileid);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_0219186C);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, data->uniquenick);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191888);
                    if (data->numNamespaces > 0)
                    {
                        for (i = 0; i < data->numNamespaces; i++)
                        {
                            if (i > 0)
                                gpiAppendCharToBuffer((int *)connection, (int *)(&data->outputBuffer), ',');
                            gpiAppendIntToBuffer(connection, &data->outputBuffer, data->namespaceIDs[i]);
                        }
                    }
                    else
                    {
                        gpiAppendIntToBuffer(connection, &data->outputBuffer, iconnection->namespaceID);
                    }
                }
                else if (data->type == GPI_SEARCH_IS_VALID)
                {
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_0219188C);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191870);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, data->email);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191864);
                    gpiAppendIntToBuffer(connection, &data->outputBuffer, iconnection->partnerID);
                }
                else if (data->type == GPI_SEARCH_NICKS)
                {
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191890);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191870);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, data->email);

                    gpiEncodeString(data->password, passwordenc);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191894);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, passwordenc);

                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191860);
                    gpiAppendIntToBuffer(connection, &data->outputBuffer, iconnection->namespaceID);

                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191864);
                    gpiAppendIntToBuffer(connection, &data->outputBuffer, iconnection->partnerID);
                }
                else if (data->type == GPI_SEARCH_PLAYERS)
                {
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191898);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191858);
                    gpiAppendIntToBuffer(connection, &data->outputBuffer, iconnection->sessKey);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_0219185C);
                    gpiAppendIntToBuffer(connection, &data->outputBuffer, iconnection->profileid);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_0219189C);
                    gpiAppendIntToBuffer(connection, &data->outputBuffer, data->productID);
                }
                else if (data->type == GPI_SEARCH_CHECK)
                {
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_021918A0);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191868);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, data->nick);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191870);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, data->email);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191864);
                    gpiAppendIntToBuffer(connection, &data->outputBuffer, iconnection->partnerID);
                    gpiEncodeString(data->password, passwordenc);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191894);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, passwordenc);
                }
                else if (data->type == GPI_SEARCH_NEWUSER)
                {
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_021918A4);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191868);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, data->nick);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191870);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, data->email);
                    gpiEncodeString(data->password, passwordenc);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191894);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, passwordenc);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_021918A8);
                    gpiAppendIntToBuffer(connection, &data->outputBuffer, iconnection->productID);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191860);
                    gpiAppendIntToBuffer(connection, &data->outputBuffer, iconnection->namespaceID);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_0219186C);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, data->uniquenick);
                    if (data->cdkey[0])
                    {
                        gpiAppendStringToBuffer(connection, &data->outputBuffer, g_021918AC);
                        gpiAppendStringToBuffer(connection, &data->outputBuffer, data->cdkey);
                    }
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191864);
                    gpiAppendIntToBuffer(connection, &data->outputBuffer, iconnection->partnerID);
                }
                else if (data->type == GPI_SEARCH_OTHERS_BUDDY)
                {
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_021918B0);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191858);
                    gpiAppendIntToBuffer(connection, &data->outputBuffer, iconnection->sessKey);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_0219185C);
                    gpiAppendIntToBuffer(connection, &data->outputBuffer, iconnection->profileid);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191860);
                    gpiAppendIntToBuffer(connection, &data->outputBuffer, iconnection->namespaceID);
                }
                else if (data->type == GPI_SEARCH_OTHERS_BUDDY_LIST)
                {
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_021918B4);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191858);
                    gpiAppendIntToBuffer(connection, &data->outputBuffer, iconnection->sessKey);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_0219185C);
                    gpiAppendIntToBuffer(connection, &data->outputBuffer, iconnection->profileid);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_021918B8);
                    gpiAppendIntToBuffer(connection, &data->outputBuffer, data->numOfRevBuddyProfiles);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_021918BC);
                    if (data->revBuddyProfileIds)
                    {
                        int i;

                        gpiAppendIntToBuffer(connection, &data->outputBuffer, data->revBuddyProfileIds[0]);

                        for (i = 1; i < data->numOfRevBuddyProfiles; i++)
                        {
                            gpiAppendStringToBuffer(connection, &data->outputBuffer, g_021918C0);
                            gpiAppendIntToBuffer(connection, &data->outputBuffer, data->revBuddyProfileIds[i]);
                        }
                    }
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191860);
                    gpiAppendIntToBuffer(connection, &data->outputBuffer, iconnection->namespaceID);
                }
                else if (data->type == GPI_SEARCH_SUGGEST_UNIQUE)
                {
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_021918C4);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_021918C8);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, data->uniquenick);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191860);
                    gpiAppendIntToBuffer(connection, &data->outputBuffer, iconnection->namespaceID);
                }
                else if (data->type == GPI_SEARCH_PROFILE_LIST)
                {
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_021918CC);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_02191858);
                    gpiAppendIntToBuffer(connection, &data->outputBuffer, iconnection->sessKey);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_0219185C);
                    gpiAppendIntToBuffer(connection, &data->outputBuffer, iconnection->profileid);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_021918D0);
                    gpiAppendIntToBuffer(connection, &data->outputBuffer, data->profile);
                    gpiAppendStringToBuffer(connection, &data->outputBuffer, g_021918D4);
                    gpiAppendIntToBuffer(connection, &data->outputBuffer, data->maxResults);
                }

                gpiAppendStringToBuffer(connection, &data->outputBuffer, g_021918D8);
                gpiAppendStringToBuffer(connection, &data->outputBuffer, g_021918DC);
                gpiAppendStringToBuffer(connection, &data->outputBuffer, g_021918E0);

                operation->state = GPI_WAITING;
            }
        }
        else if (operation->state == GPI_WAITING)
        {
            result = gpiRecvToBuffer((int *)connection, data->sock, &data->inputBuffer, (int *)(&len), (int *)(&connClosed), g_0219184C);
            if (result != GP_NO_ERROR)
            {
                if (result == GP_NETWORK_ERROR)
                    CallbackError(connection, GP_NETWORK_ERROR, GPI_SEARCH_CONNECTION_FAILED, g_021918E4);
                return result;
            }
            if (operation->blocking && (current_time() - data->searchStartTime > GPI_SEARCH_TIMEOUT))
            {
                data->remove = GPITrue;
                CallbackError(connection, GP_NETWORK_ERROR, GP_SEARCH_TIMED_OUT, g_02191848);
            }
            if (strstr((unsigned char *)data->inputBuffer.buffer, (unsigned char *)g_021918E0) != 0)
            {
                index = 0;

                operation->state = GPI_FINISHING;

                if (gpiCheckForError(connection, data->inputBuffer.buffer, GPITrue))
                {
                    data->remove = GPITrue;
                    return GP_SERVER_ERROR;
                }

                if ((data->type == GPI_SEARCH_PROFILE) || (data->type == GPI_SEARCH_PROFILE_UNIQUENICK))
                {
                    GPProfileSearchResponseArg arg;
                    arg.result = GP_NO_ERROR;
                    arg.numMatches = 0;
                    arg.matches = 0;
                    arg.more = GP_DONE;

                    done = GPIFalse;
                    do
                    {
                        CHECK_RESULT(gpiReadKeyAndValue(connection, data->inputBuffer.buffer, &index, key, value));

                        if (strcmp(key, g_021918EC) == 0)
                        {
                            CHECK_RESULT(gpiReadKeyAndValue(connection, data->inputBuffer.buffer, &index, key, value));
                            if (strcmp(key, g_021918F0) == 0)
                            {
                                if (strcmp(value, g_021918F4) != 0)
                                    arg.more = GP_MORE;
                            }

                            done = GPITrue;
                        }
                        else if (strcmp(key, g_021918F8) == 0)
                        {
                            arg.numMatches++;
                            arg.matches = (GPProfileSearchMatch *)gsirealloc(arg.matches, sizeof(GPProfileSearchMatch) * arg.numMatches);
                            if (arg.matches == 0)
                                Error(connection, GP_MEMORY_ERROR, g_021918FC);
                            match = &arg.matches[arg.numMatches - 1];
                            MSL_C_LIB_MemsetPtr(match, 0, sizeof(GPProfileSearchMatch));

                            match->profile = atoi(value);

                            doneParsingMatch = GPIFalse;
                            do
                            {
                                oldIndex = index;
                                CHECK_RESULT(gpiReadKeyAndValue(connection, data->inputBuffer.buffer, &index, key, value));

                                if (strcmp(key, g_02191900) == 0)
                                    strzcpy(match->nick, value, 31);
                                else if (strcmp(key, g_02191904) == 0)
                                    strzcpy(match->uniquenick, value, 21);
                                else if (strcmp(key, g_02191908) == 0)
                                    match->namespaceID = atoi(value);
                                else if (strcmp(key, g_0219190C) == 0)
                                    strzcpy(match->firstname, value, 31);
                                else if (strcmp(key, g_02191910) == 0)
                                    strzcpy(match->lastname, value, 31);
                                else if (strcmp(key, g_02191914) == 0)
                                    strzcpy(match->email, value, 51);
                                else if ((strcmp(key, g_021918F8) == 0) || (strcmp(key, g_021918EC) == 0))
                                {
                                    doneParsingMatch = GPITrue;
                                    index = oldIndex;
                                }
                            }
                            while (!doneParsingMatch);
                        }
                        else
                        {
                            CallbackFatalError(connection, GP_NETWORK_ERROR, GP_PARSE, g_02191918);
                        }
                    } while (!done);

                    more = (GPIBool)arg.more;

                    callback = operation->callback;

                    if (callback.callback != 0)
                        ((void (*)(GPConnection *, void *, void *))callback.callback)(connection, &arg, callback.param);

                    if ((more == GP_MORE) && (arg.more == GP_MORE))
                        CHECK_RESULT(gpiProfileSearch(connection, data->nick, data->uniquenick, data->email, data->firstname, data->lastname, data->icquin, arg.numMatches + data->skip, (GPEnum)operation->blocking, operation->callback.callback, operation->callback.param));

                    freeclear(arg.matches);
                }
                else if (data->type == GPI_SEARCH_IS_VALID)
                {
                    callback = operation->callback;
                    if (callback.callback != 0)
                    {
                        GPIsValidEmailResponseArg *arg;

                        CHECK_RESULT(gpiReadKeyAndValue(connection, data->inputBuffer.buffer, &index, key, value));
                        if (strcmp(key, g_0219191C) != 0)
                            CallbackFatalError(connection, GP_NETWORK_ERROR, GP_PARSE, g_02191918);

                        arg = (GPIsValidEmailResponseArg *)gsimalloc(sizeof(GPIsValidEmailResponseArg));
                        if (arg == 0)
                            Error(connection, GP_MEMORY_ERROR, g_021918FC);
                        arg->result = GP_NO_ERROR;
                        strzcpy(arg->email, data->email, 51);
                        if (value[0] == '0')
                            arg->isValid = GP_INVALID;
                        else
                            arg->isValid = GP_VALID;

                        CHECK_RESULT(gpiAddCallback(connection, callback, arg, (GPIOperation *)operation, 0));
                    }
                }
                else if (data->type == GPI_SEARCH_NICKS)
                {
                    callback = operation->callback;
                    if (callback.callback != 0)
                    {
                        GPGetUserNicksResponseArg *arg;

                        arg = (GPGetUserNicksResponseArg *)gsimalloc(sizeof(GPGetUserNicksResponseArg));
                        if (arg == 0)
                            Error(connection, GP_MEMORY_ERROR, g_021918FC);
                        arg->result = GP_NO_ERROR;
                        gsiSafeStrcpyA(arg->email, data->email, 51);
                        arg->numNicks = 0;
                        arg->nicks = 0;
                        arg->uniquenicks = 0;

                        CHECK_RESULT(gpiReadKeyAndValue(connection, data->inputBuffer.buffer, &index, key, value));
                        if (strcmp(key, g_02192A94) != 0)
                            CallbackFatalError(connection, GP_NETWORK_ERROR, GP_PARSE, g_02191918);

                        done = GPIFalse;
                        do
                        {
                            CHECK_RESULT(gpiReadKeyAndValue(connection, data->inputBuffer.buffer, &index, key, value));
                            if (strcmp(key, g_02191900) == 0)
                            {
                                tempPtr = gsirealloc(arg->nicks, sizeof(char *) * (arg->numNicks + 1));
                                if (tempPtr == 0)
                                    Error(connection, GP_MEMORY_ERROR, g_021918FC);
                                arg->nicks = (char **)tempPtr;
                                tempPtr = gsimalloc(31);
                                if (tempPtr == 0)
                                    Error(connection, GP_MEMORY_ERROR, g_021918FC);
                                arg->nicks[arg->numNicks] = (char *)tempPtr;
                                strzcpy(arg->nicks[arg->numNicks], value, 31);
                                arg->numNicks++;
                            }
                            else if (strcmp(key, g_02191904) == 0)
                            {
                                if (arg->numNicks <= 0)
                                    continue;

                                tempPtr = gsirealloc(arg->uniquenicks, sizeof(char *) * arg->numNicks);
                                if (tempPtr == 0)
                                    Error(connection, GP_MEMORY_ERROR, g_021918FC);
                                arg->uniquenicks = (char **)tempPtr;
                                tempPtr = gsimalloc(21);
                                if (tempPtr == 0)
                                    Error(connection, GP_MEMORY_ERROR, g_021918FC);
                                arg->uniquenicks[arg->numNicks - 1] = (char *)tempPtr;
                                strzcpy(arg->uniquenicks[arg->numNicks - 1], value, 21);
                            }
                            else if (strcmp(key, g_02192A98) == 0)
                            {
                                done = GPITrue;
                            }
                            else
                            {
                                CallbackFatalError(connection, GP_NETWORK_ERROR, GP_PARSE, g_02191918);
                            }
                        }
                        while (!done);

                        CHECK_RESULT(gpiAddCallback(connection, callback, arg, (GPIOperation *)operation, GPI_ADD_NICKS));
                    }
                }
                else if (data->type == GPI_SEARCH_PLAYERS)
                {
                    callback = operation->callback;
                    if (callback.callback != 0)
                    {
                        GPFindPlayersResponseArg *arg;
                        GPFindPlayerMatch *match;

                        arg = (GPFindPlayersResponseArg *)gsimalloc(sizeof(GPFindPlayersResponseArg));
                        if (arg == 0)
                            Error(connection, GP_MEMORY_ERROR, g_021918FC);
                        arg->productID = data->productID;
                        arg->result = GP_NO_ERROR;
                        arg->numMatches = 0;
                        arg->matches = 0;

                        done = GPIFalse;
                        do
                        {
                            CHECK_RESULT(gpiReadKeyAndValue(connection, data->inputBuffer.buffer, &index, key, value));

                            if (strcmp(key, g_02192A9C) == 0)
                            {
                                done = GPITrue;
                            }
                            else if (strcmp(key, g_02192AA0) == 0)
                            {
                                arg->numMatches++;
                                arg->matches = (GPFindPlayerMatch *)gsirealloc(arg->matches, sizeof(GPFindPlayerMatch) * arg->numMatches);
                                if (arg->matches == 0)
                                    Error(connection, GP_MEMORY_ERROR, g_021918FC);
                                match = &arg->matches[arg->numMatches - 1];
                                MSL_C_LIB_MemsetPtr(match, 0, sizeof(GPFindPlayerMatch));
                                match->status = GP_ONLINE;

                                match->profile = atoi(value);

                                doneParsingMatch = GPIFalse;
                                do
                                {
                                    oldIndex = index;
                                    CHECK_RESULT(gpiReadKeyAndValue(connection, data->inputBuffer.buffer, &index, key, value));

                                    if (strcmp(key, g_02192AA4) == 0)
                                        strzcpy(match->statusString, value, 256);
                                    else if (strcmp(key, g_02191900) == 0)
                                        strzcpy(match->nick, value, 31);
                                    if (strcmp(key, g_02192AA8) == 0)
                                        match->status = (GPEnum)atoi(value);
                                    else if ((strcmp(key, g_02192AA0) == 0) || (strcmp(key, g_02192A9C) == 0))
                                    {
                                        doneParsingMatch = GPITrue;
                                        index = oldIndex;
                                    }
                                }
                                while (!doneParsingMatch);
                            }
                            else
                            {
                                CallbackFatalError(connection, GP_NETWORK_ERROR, GP_PARSE, g_02191918);
                            }
                        } while (!done);

                        CHECK_RESULT(gpiAddCallback(connection, callback, arg, (GPIOperation *)operation, GPI_ADD_PMATCH));
                    }
                }
                else if (data->type == GPI_SEARCH_CHECK)
                {
                    callback = operation->callback;
                    if (callback.callback != 0)
                    {
                        GPCheckResponseArg *arg;

                        CHECK_RESULT(gpiReadKeyAndValue(connection, data->inputBuffer.buffer, &index, key, value));
                        if (strcmp(key, g_02192AAC) != 0)
                            CallbackFatalError(connection, GP_NETWORK_ERROR, GP_PARSE, g_02191918);

                        rcode = atoi(value);
                        if (rcode)
                        {
                            iconnection->errorCode = (GPErrorCode)rcode;
                            pid = 0;
                        }
                        else
                        {
                            if (!gpiValueForKey(data->inputBuffer.buffer, g_02192AB0, value, sizeof(value)))
                                CallbackFatalError(connection, GP_NETWORK_ERROR, GP_PARSE, g_02191918);
                            pid = atoi(value);
                        }

                        arg = (GPCheckResponseArg *)gsimalloc(sizeof(GPCheckResponseArg));
                        if (arg == 0)
                            Error(connection, GP_MEMORY_ERROR, g_021918FC);
                        arg->result = (GPResult)rcode;
                        arg->profile = pid;

                        CHECK_RESULT(gpiAddCallback(connection, callback, arg, (GPIOperation *)operation, 0));
                    }
                }
                else if (data->type == GPI_SEARCH_NEWUSER)
                {
                    callback = operation->callback;
                    if (callback.callback != 0)
                    {
                        GPNewUserResponseArg *arg;

                        CHECK_RESULT(gpiReadKeyAndValue(connection, data->inputBuffer.buffer, &index, key, value));
                        if (strcmp(key, g_02192AB4) != 0)
                            CallbackFatalError(connection, GP_NETWORK_ERROR, GP_PARSE, g_02191918);

                        rcode = atoi(value);
                        if (rcode)
                            iconnection->errorCode = (GPErrorCode)rcode;
                        if (!gpiValueForKey(data->inputBuffer.buffer, g_02192AB0, value, sizeof(value)))
                        {
                            if (rcode == 0)
                                CallbackFatalError(connection, GP_NETWORK_ERROR, GP_PARSE, g_02191918);
                            pid = 0;
                        }
                        else
                            pid = atoi(value);

                        arg = (GPNewUserResponseArg *)gsimalloc(sizeof(GPNewUserResponseArg));
                        if (arg == 0)
                            Error(connection, GP_MEMORY_ERROR, g_021918FC);
                        arg->result = (GPResult)rcode;
                        arg->profile = pid;

                        CHECK_RESULT(gpiAddCallback(connection, callback, arg, (GPIOperation *)operation, 0));
                    }
                }
                else if (data->type == GPI_SEARCH_OTHERS_BUDDY)
                {
                    callback = operation->callback;
                    if (callback.callback != 0)
                    {
                        GPGetReverseBuddiesResponseArg *arg;

                        arg = (GPGetReverseBuddiesResponseArg *)gsimalloc(sizeof(GPGetReverseBuddiesResponseArg));
                        if (arg == 0)
                            Error(connection, GP_MEMORY_ERROR, g_021918FC);
                        arg->result = GP_NO_ERROR;
                        arg->numProfiles = 0;
                        arg->profiles = 0;

                        CHECK_RESULT(gpiReadKeyAndValue(connection, data->inputBuffer.buffer, &index, key, value));
                        if (strcmp(key, g_02192AB8) != 0)
                            CallbackFatalError(connection, GP_NETWORK_ERROR, GP_PARSE, g_02191918);

                        done = GPIFalse;
                        do
                        {
                            CHECK_RESULT(gpiReadKeyAndValue(connection, data->inputBuffer.buffer, &index, key, value));

                            if (strcmp(key, g_02192ABC) == 0)
                            {
                                done = GPITrue;
                            }
                            else if (strcmp(key, g_02192AC0) == 0)
                            {
                                tempPtr = gsirealloc(arg->profiles, sizeof(GPProfileSearchMatch) * (arg->numProfiles + 1));
                                if (tempPtr == 0)
                                    Error(connection, GP_MEMORY_ERROR, g_021918FC);
                                arg->profiles = (GPProfileSearchMatch *)tempPtr;
                                match = &arg->profiles[arg->numProfiles];
                                MSL_C_LIB_MemsetPtr(match, 0, sizeof(GPProfileSearchMatch));
                                arg->numProfiles++;

                                match->profile = atoi(value);

                                doneParsingMatch = GPIFalse;
                                do
                                {
                                    oldIndex = index;
                                    CHECK_RESULT(gpiReadKeyAndValue(connection, data->inputBuffer.buffer, &index, key, value));

                                    if (strcmp(key, g_02191900) == 0)
                                        strzcpy(match->nick, value, 31);
                                    else if (strcmp(key, g_02191904) == 0)
                                        strzcpy(match->uniquenick, value, 21);
                                    else if (strcmp(key, g_02192AC4) == 0)
                                        strzcpy(match->firstname, value, 31);
                                    else if (strcmp(key, g_02192AC8) == 0)
                                        strzcpy(match->lastname, value, 31);
                                    else if (strcmp(key, g_02191914) == 0)
                                        strzcpy(match->email, value, 51);
                                    else if ((strcmp(key, g_02192AC0) == 0) || (strcmp(key, g_02192ABC) == 0))
                                    {
                                        doneParsingMatch = GPITrue;
                                        index = oldIndex;
                                    }
                                }
                                while (!doneParsingMatch);
                            }
                            else
                            {
                                CallbackFatalError(connection, GP_NETWORK_ERROR, GP_PARSE, g_02191918);
                            }
                        }
                        while (!done);

                        CHECK_RESULT(gpiAddCallback(connection, callback, arg, (GPIOperation *)operation, GPI_ADD_REVERSE_BUDDIES));
                    }
                }
                else if (data->type == GPI_SEARCH_OTHERS_BUDDY_LIST)
                {
                    callback = operation->callback;
                    if (callback.callback != 0)
                    {
                        GPGetReverseBuddiesListResponseArg *arg;

                        arg = (GPGetReverseBuddiesListResponseArg *)gsimalloc(sizeof(GPGetReverseBuddiesListResponseArg));
                        if (arg == 0)
                            Error(connection, GP_MEMORY_ERROR, g_021918FC);
                        arg->result = GP_NO_ERROR;
                        arg->numOfUniqueMatchs = 0;
                        arg->matches = 0;

                        CHECK_RESULT(gpiReadKeyAndValue(connection, data->inputBuffer.buffer, &index, key, value));
                        if (strcmp(key, g_02192ACC) != 0)
                            CallbackFatalError(connection, GP_NETWORK_ERROR, GP_PARSE, g_02191918);

                        done = GPIFalse;
                        do
                        {
                            CHECK_RESULT(gpiReadKeyAndValue(connection, data->inputBuffer.buffer, &index, key, value));

                            if (strcmp(key, g_02192AD0) == 0)
                            {
                                done = GPITrue;
                            }
                            else if (strcmp(key, g_02192AC0) == 0)
                            {
                                tempPtr = gsirealloc(arg->matches, sizeof(GPUniqueMatch) * (arg->numOfUniqueMatchs + 1));
                                if (tempPtr == 0)
                                    Error(connection, GP_MEMORY_ERROR, g_021918FC);
                                arg->matches = (GPUniqueMatch *)tempPtr;
                                uniqueNickMatch = &arg->matches[arg->numOfUniqueMatchs];
                                __builtin__clear(uniqueNickMatch, sizeof(GPUniqueMatch));
                                arg->numOfUniqueMatchs++;

                                uniqueNickMatch->profile = atoi(value);

                                doneParsingMatch = GPIFalse;
                                do
                                {
                                    oldIndex = index;
                                    CHECK_RESULT(gpiReadKeyAndValue(connection, data->inputBuffer.buffer, &index, key, value));

                                    if (strcmp(key, g_02191904) == 0)
                                        strzcpy(uniqueNickMatch->uniqueNick, value, 21);
                                    else if ((strcmp(key, g_02192AC0) == 0) || (strcmp(key, g_02192AD0) == 0))
                                    {
                                        doneParsingMatch = GPITrue;
                                        index = oldIndex;
                                    }
                                }
                                while (!doneParsingMatch);
                            }
                            else
                            {
                                CallbackFatalError(connection, GP_NETWORK_ERROR, GP_PARSE, g_02191918);
                            }
                        }
                        while (!done);

                        CHECK_RESULT(gpiAddCallback(connection, callback, arg, (GPIOperation *)operation, GPI_ADD_REVERSE_BUDDIES_LIST));
                    }
                }
                else if (data->type == GPI_SEARCH_SUGGEST_UNIQUE)
                {
                    callback = operation->callback;
                    if (callback.callback != 0)
                    {
                        int count = 0;
                        GPSuggestUniqueNickResponseArg *arg;

                        arg = (GPSuggestUniqueNickResponseArg *)gsimalloc(sizeof(GPSuggestUniqueNickResponseArg));
                        if (arg == 0)
                            Error(connection, GP_MEMORY_ERROR, g_021918FC);
                        arg->result = GP_NO_ERROR;
                        arg->numSuggestedNicks = 0;
                        arg->suggestedNicks = 0;

                        CHECK_RESULT(gpiReadKeyAndValue(connection, data->inputBuffer.buffer, &index, key, value));
                        if (strcmp(key, g_02192AE0) != 0)
                            CallbackFatalError(connection, GP_NETWORK_ERROR, GP_PARSE, g_02191918);
                        arg->numSuggestedNicks = atoi(value);

                        arg->suggestedNicks = (char **)gsimalloc(sizeof(char *) * arg->numSuggestedNicks);
                        if (!arg->suggestedNicks)
                            Error(connection, GP_MEMORY_ERROR, g_021918FC);

                        done = GPIFalse;
                        do
                        {
                            CHECK_RESULT(gpiReadKeyAndValue(connection, data->inputBuffer.buffer, &index, key, value));
                            if (strcmp(key, g_02191900) == 0)
                            {
                                arg->suggestedNicks[count] = gsimalloc(21);
                                if (arg->suggestedNicks[count] == 0)
                                    Error(connection, GP_MEMORY_ERROR, g_021918FC);
                                strzcpy(arg->suggestedNicks[count], value, 21);
                                count++;
                            }
                            else if (strcmp(key, g_02192DFC) == 0)
                            {
                                arg->numSuggestedNicks = count;

                                done = GPITrue;
                            }
                            else
                            {
                                CallbackFatalError(connection, GP_NETWORK_ERROR, GP_PARSE, g_02191918);
                            }
                        }
                        while (!done);

                        CHECK_RESULT(gpiAddCallback(connection, callback, arg, (GPIOperation *)operation, GPI_ADD_SUGGESTED_UNIQUE));
                    }
                }
                else if (data->type == GPI_SEARCH_PROFILE_LIST)
                {
                    callback = operation->callback;
                    if (callback.callback != 0)
                    {
                        GPProfileListResponseArg *arg;

                        arg = (GPProfileListResponseArg *)gsimalloc(sizeof(GPProfileListResponseArg));
                        if (arg == 0)
                            Error(connection, GP_MEMORY_ERROR, g_021918FC);
                        arg->result = GP_NO_ERROR;
                        arg->numMatches = 0;
                        arg->matches = 0;
                        arg->hidden = 0;
                        arg->profile = ((GPISearchData *)operation->data)->profile;

                        CHECK_RESULT(gpiReadKeyAndValue(connection, data->inputBuffer.buffer, &index, key, value));
                        if (strcmp(key, g_02192E00) != 0)
                            CallbackFatalError(connection, GP_NETWORK_ERROR, GP_PARSE, g_02191918);

                        done = GPIFalse;
                        do
                        {
                            CHECK_RESULT(gpiReadKeyAndValue(connection, data->inputBuffer.buffer, &index, key, value));
                            if (strcmp(key, g_02192E04) == 0)
                            {
                                done = GPITrue;
                            }
                            else if (strcmp(key, g_02192E08) == 0)
                            {
                                arg->hidden = 1;
                                done = GPITrue;
                            }
                            else if (strcmp(key, g_02192E0C) == 0)
                            {
                                int count = atoi(value);
                                if (count > 0)
                                {
                                    tempPtr = gsimalloc(sizeof(int) * count);
                                    if (tempPtr == 0)
                                        Error(connection, GP_MEMORY_ERROR, g_021918FC);
                                    arg->matches = (int *)tempPtr;
                                }
                            }
                            else if (strcmp(key, g_02192AC0) == 0)
                            {
                                arg->matches[arg->numMatches] = atoi(value);
                                arg->numMatches++;
                            }
                            else
                            {
                                CallbackFatalError(connection, GP_NETWORK_ERROR, GP_PARSE, g_02191918);
                            }
                        }
                        while (!done);

                        CHECK_RESULT(gpiAddCallback(connection, callback, arg, (GPIOperation *)operation, GPI_ADD_PROFILE_LIST));
                    }
                }

                data->remove = GPITrue;

                loop = GPIFalse;
            }
        }
        if (loop)
            msleep(10);
    } while (loop);

    return GP_NO_ERROR;
}



int gpiProcessSearches(void **connection)
{
    int i;
    int num;
    int result;
    GPISearchData *data;
    GPIOperation *operation;
    GPIOperation **searchList;
    GPIConnection *iconnection;

    iconnection = (GPIConnection *)*connection;
    num = 0;
    if (iconnection->numSearches > 0) {
        searchList = (GPIOperation **)gsimalloc(iconnection->numSearches * sizeof(GPIOperation *));
        if (searchList == 0) {
            gpiSetErrorString(connection, g_021A5280);
            return 1;
        }
        for (operation = iconnection->operationList; operation != 0; operation = operation->pnext) {
            if (operation->type == 3 && operation->state != 5) {
                if (operation->data->processing == 0) {
                    searchList[num++] = operation;
                    operation->data->processing = 1;
                }
            }
        }
        for (i = 0; i < num; i++) {
            result = gpiProcessSearch(connection, searchList[i]);
            if (result != 0)
                searchList[i]->result = result;
        }
        for (i = 0; i < num; i++) {
            data = searchList[i]->data;
            data->processing = 0;
            if (data->remove)
                gpiRemoveOperation(connection, (GPIOperation *)searchList[i]);
        }
        gsifree(searchList);
    }
    return 0;
}
