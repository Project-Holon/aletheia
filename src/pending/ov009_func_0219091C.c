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
 * BOTTOM-UP HELPER TREE (this lane, packet pkt_0219091C; every file below is
 * an EXACT entry in layout/matched/ov009/pkt_0219091C.json unless noted):
 *   direct callees of func_0219091C
 *     func_0218946C  gpiAppendStringToBuffer       EXACT (48)
 *       func_021893C8 gpiAppendDataToBuffer        EXACT (164)
 *         func_0218934C gpiAppendCharToBuffer      EXACT (124)
 *     func_0218949C  gpiAppendIntToBuffer          EXACT (60)
 *     func_02189D78  gpiAddCallback (wrapper)      EXACT (132)
 *     func_02189DFC  gpiAddCallback                EXACT (164)
 *     func_02193418  gpiValueForKey                EXACT (112)
 *     func_02193488  gpiCheckSocketConnect         EXACT (276)
 *     func_02193710  gpiSetError                   EXACT (36)
 *     func_02193748  gpiEncodeString               EXACT (136)
 *     func_0219329C  gpiCheckForError              MATCH -> src/pending (220)
 *         blocker: its atoi call targets the unlabelled thunk 0x020964E0,
 *         which no evidence class can attest, so it is capped at MATCH;
 *         scanner-promotes to EXACT once 0x020964E0 is seeded in
 *         layout/function_starts.txt (the two-word defaulting thunk is not
 *         producible from C).
 *     func_021803BC  bounded copy (strlcpy-shaped) EXACT (72)    [this run]
 *     func_0217F264  current_time                  EXACT (40)    [this run]
 *     func_0219359C  gpiReadKeyAndValue            EXACT (372)   [this run]
 *   already matched before this lane (witnesses, not re-filed)
 *     func_0219327C, func_02193734, func_0217EAB0, func_0217EAC8,
 *     func_0217EAE0, func_0217EC4C, func_0217ED54, func_0217F790,
 *     func_0217F2BC, func_02190650
 *   direct callees still parked (byte-correct but not EXACT)
 *     func_02189780  gpiRecvToBuffer               DIFF -> src/pending
 *         blocker: codegen only, the per-chunk GSIDebug raw-dump call
 *         schedules the `recvCount++` vararg before reloading the format
 *         pointer, where the original loads the format into r3 first; the
 *         whole main loop and all other branches line up.
 *     func_0218998C  gpiSendFromBuffer             EXACT (240)  [this run]
 *     func_021906E0  gpiProfileSearch              EXACT (464)  [this run]
 *     func_021894D8  gpiSendData (static)          DIFF -> src/pending
 *         blocker: 21 bytes at the `sendCount++` GSIDebug call, same
 *         argument-scheduling quirk as func_02189780.
 *     func_0219359C  gpiReadKeyAndValue            DIFF -> src/pending
 *         blocker: codegen only, the whole body is right but the register
 *         allocation is one cyclic rotation off (p/i/q/value); compiles 368
 *         vs 372.  Worth cracking, it has 20 call sites here.
 *   a second-level helper now filed:
 *     func_021905A4  gpiCreateSearchData-alike     EXACT (172)  [this run]
 *     func_0217F21C  ascii remap (_strlwr core)    EXACT (64)   [this run]
 *     func_0217D254  variadic logger thunk         EXACT (44)   [this run]
 *
 * Reached this run: three more EXACT helpers closed bottom-up --
 * func_0219359C gpiReadKeyAndValue (372, the four-error-tail parse loop,
 * previously DIFF by a four-register rotation cured by using the public
 * source's shared running cursor; see docs/idioms/
 * a-shared-running-cursor-settles-a-parse-loop-register-rotation.md),
 * func_021803BC (72, bounded strlcpy-shaped copy) and func_0217F264
 * current_time (40, the tick/33514 u64 divide) -- so every non-SDK direct
 * callee is now EXACT except: func_0219329C gpiCheckForError, capped at MATCH
 * on the unlabelled atoi thunk 0x020964E0, and the two network I/O helpers
 * func_021894D8 gpiSendData and func_02189780 gpiRecvToBuffer, byte-correct
 * except one GSIDebugFormat call site each (codegen only; the counter
 * increment is scheduled before the later format-pointer load, documented in
 * docs/idioms/a-varargs-counter-increment-is-scheduled-before-a-later-
 * format-pointer.md).  The shard layout/matched/ov009/pkt_0219091C.json now
 * holds 18 EXACT entries.
 *
 * func_0219091C itself is still DIFF (the stub body compiles 232 bytes
 * against the 9460-byte original).  Its register allocation and 0x4d4 frame
 * are global, so a partial port cannot byte-match; a full port of the public
 * gpiProcessSearch with every absolute string pinned as an extern is the only
 * route, and the 0xb case / extra +0x198, +0x19c fields still have to be
 * transcribed from the disassembly before that can be attempted.  The
 * function carries 165 PC-relative pool loads and 310 call sites, so the port
 * is a full multi-pass job; it was not attempted to completion this run.
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
