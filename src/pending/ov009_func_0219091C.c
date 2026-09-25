/*
 * function: func_0219091C
 * address:  0x0219091C
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF   (documented oversized near-miss; NOT EXACT, NOT MATCH)
 *
 * BLOCKER.  This is one ~9440-byte (0x24E0) ARM routine, ~2365
 * instructions, with embedded literal pools and a mid-function pool/table
 * at 0x02192A94..0x02192AE4.  Single prologue at 0x0219091C and single final
 * pop at 0x02192DF8; the words at 0x02192DFC.. belong to the unlabelled
 * follower, so the true extent is 0x0219091C..0x02192DFC.  It is the GameSpy
 * Presence SDK state machine gpiProcessSearch:
 *
 *   data = operation->data;  iconnection = *connection;
 *   if (operation->blocking) loop = 1; else loop = 0;
 *   if (!operation->blocking
 *       && current_time() - data->searchStartTime > GPI_SEARCH_TIMEOUT) {
 *       data->remove = 1;
 *       CallbackError(connection, GP_NETWORK_ERROR, GP_SEARCH_TIMED_OUT,
 *                     "The search timed out");
 *   }
 *   do {
 *       gpiSendFromBuffer(connection, data->sock, &data->outputBuffer,
 *                         &connClosed, 1, "SM");
 *       if (operation->state == GPI_CONNECTING) { ... request build ... }
 *       else if (operation->state == GPI_WAITING) { ... response parse ... }
 *   } while (loop);
 *
 * The near-identical public source is GameSpy SDK src/GameSpy/GP/gpiSearch.c
 * function gpiProcessSearch (github.com/nitrocaster/GameSpy).  The
 * Nintendo/DWC fork is NOT byte-identical:
 *  - the request-build switch on data->type has an ELEVENTH case (0xb) that
 *    the public enum (GPI_SEARCH_PROFILE=1 .. GPI_SEARCH_PROFILE_UNIQUENICK=10)
 *    lacks; the compare is at 0x0219129C, handler at 0x021912A4;
 *  - GPISearchData has two extra int fields at +0x198 and +0x19c (read by
 *    that handler at 0x0219130C / 0x0219132C), and GPIConnection exposes two
 *    fields used there at +0x198 / +0x1a0;
 *  - every string/table argument is an absolute overlay address, so each of
 *    the hundreds of gpiAppend and gpiValueForKey literals must be declared
 *    as an extern pinned in the symbols: block; a source port that emits its
 *    own string literals can never match.
 *
 * Offsets verified from the loads in this routine:
 *   operation->data        +0x04      operation->blocking +0x08
 *   operation->state       +0x14
 *   data->type             +0x00      data->sock         +0x04
 *   data->inputBuffer      +0x08      data->outputBuffer +0x18
 *   data->nick             +0x28      data->uniquenick   +0x47
 *   data->numNamespaces    +0x9c      data->email        +0xa0
 *   data->firstname        +0xd3      data->lastname     +0xf2
 *   data->password         +0x111     data->icquin       +0x178
 *   data->skip             +0x17c     data->productID    +0x180
 *   data->processing       +0x184     data->remove       +0x188
 *   data->searchStartTime  +0x18c     data->revBuddyProfileIds +0x190
 *   data->numOfRevBuddyProfiles +0x194   (Nintendo extras +0x198, +0x19c)
 * These match gpiSearch.h's GPISearchData exactly up to +0x194.
 *
 * Helpers (resolved label evidence): current_time 0x0217F264,
 * gpiSetError 0x02193710, gpiSetErrorString 0x02193734,
 * gpiCheckSocketConnect 0x02193488, gpiValueForKey 0x02193418,
 * gpiSendFromBuffer 0x0218998C, gpiRecvToBuffer 0x02189780,
 * gpiReadKeyAndValue 0x0219359C, gpiAppendStringToBuffer 0x0218946C,
 * gpiAppendIntToBuffer 0x0218949C, gpiEncodeString 0x02193748,
 * strcmp 0x020948E0, strstr 0x02094B20, memset 0x020923B0,
 * atoi 0x020964E0, gsimalloc 0x0217EAB0, gsirealloc 0x0217EAC8.
 * GPI_SEARCH_TIMEOUT = 60000 (0xEA60) is pooled at 0x02191840.
 *
 * Why no partial credit is possible: register allocation, the 0x4d4 stack
 * frame (push {r4-r8,sb,sl,fp,lr}; sub sp,#0xd4; sub sp,#0x400) and every
 * branch displacement are global to the whole function, so no leading run
 * byte-matches until the body is reconstructed in full.  match.py reports
 * compiled 232 bytes vs original 9460 listing bytes, 203 concrete bytes
 * differ from +0x0000, verdict DIFF.
 *
 * The C below is a FABRICATED, non-matching partial stub left by an earlier
 * pass (its struct names/fields are not the real GPConnection / GPIOperation
 * / GPISearchData).  Do not trust it; replace it with a port of
 * gpiProcessSearch once the 0xb handler and the extra fields are recovered.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef enum {
    GP_NO_ERROR = 0,
    GP_MEMORY_ERROR = 1,
    GP_PARAMETER_ERROR = 2,
    GP_NETWORK_ERROR = 3,
    GP_SERVER_ERROR = 4
} GPResult;

struct GPConnection {
    void *p3d;
};

struct GPISearchData {
    u32 type;
    void *sock;
    u32 state;
};

struct GPIOperation {
    u32 pad0;
    struct GPISearchData *searchData;
    u32 type;
    u32 padC[2];
    u32 state;
};

extern u32 current_time(void);
extern void gpiSetError(void *connection, void *error, void *string);
extern void gpiSetErrorString(void *connection, u32 result, u32 error);
extern u32 gpiCheckSocketConnect(void *connection, void *sock, void *state, void *buf);
extern u32 gpiValueForKey(void *connection, void *sock, void *buf);
extern void gpiAppendStringToBuffer(void *connection, void *buf, const char *str);
extern void gpiAppendIntToBuffer(void *connection, void *buf, int val);

GPResult func_0219091C(struct GPConnection *connection, struct GPIOperation *operation)
{
    u8 buffer[0x4d4];
    void *p3d;
    struct GPISearchData *searchData;
    void *op;
    u32 is_type_set;
    GPResult error;
    u32 now;
    u32 *p18c;
    int r8;
    int sb;
    int sl;
    int fp;

    p3d = connection->p3d;
    op = operation->searchData;
    searchData = (struct GPISearchData *)op;
    is_type_set = (operation->type != 0) ? 1 : 0;
    r8 = is_type_set;
    error = GP_NETWORK_ERROR;

    if (operation->type == 0) {
        now = current_time();
        p18c = (u32 *)((char *)searchData + 0x18c);
        if (now - *p18c > 0xed0) {
            *(u32 *)((char *)searchData + 0x188) = 1;
            gpiSetError(connection, (void *)0xec4, (void *)0xec4);
            gpiSetErrorString(connection, error, 0);
            return error;
        }
    }

    sb = 1;
    *(u32 *)buffer = sb;
    *(u32 **)(buffer + 4) = (u32 *)0xed0; // placeholder to pin scratch registers

    if (gpiCheckSocketConnect(connection, *(void **)((char *)searchData + 4), (char *)searchData + 0x18, buffer + 0x7c) != 0) {
        return GP_NO_ERROR;
    }

    if (operation->state == 1) {
        if (gpiValueForKey(connection, *(void **)((char *)searchData + 4), buffer + 0x90) != 0) {
            return GP_NO_ERROR;
        }
    }

    return GP_NO_ERROR;
}
