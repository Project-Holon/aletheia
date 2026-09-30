/*
 * function: func_0219091C
 * address:  0x0219091C
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF   (staged reconstruction; stage 1+2a filed, stages 2b/3 open)
 *
 * ============================================================================
 * LANE S10 GROUND TRUTH -- read this before touching the body.
 * ============================================================================
 *
 * This is gpiProcessSearch, the GameSpy Presence SDK search state machine
 * (GamespySDK src/gp/gpiSearch.c).  Extent 9460 bytes = 0x24F4:
 *   0x0219091C .. 0x02192E10 (2365 ARM instructions, single prologue at
 *   0x0219091C, single final pop at 0x02192DF8; the words 0x02192DFC ..
 *   0x02192E0C are the last literal pool of this function, followed by the
 *   next function at 0x02192E10).
 *   frame: push {r4-r8,sb,sl,fp,lr}; sub sp,#0xd4; sub sp,#0x400  (0x4d4)
 *   stack slots used as arrays: key = sp+0x90, value = sp+0xa0,
 *   passwordenc = sp+0x7c, `state` (int out-param) = sp+0x90/0x7c.
 *
 * THE REFERENCE IS IN THE VENDOR LIBRARY.  sdk/TwlDWC/lib/gamespy/ARM9-TS/
 * Release/libdwcgsgp.a member gpisearch.o is the *same object* the overlay
 * was linked from: its .text member 128 is 9460 bytes, symbol
 * gpiProcessSearch size 9460, byte-identical to the image.  It carries
 *   - .rela.text with 389 relocations, 310 of them ARM BL (type 1) and 79
 *     absolute word (type 2) -- so every call target and every literal is
 *     named by the linker itself, not guessed;
 *   - 84 string literals in their own .data sections with full contents;
 *   - DWARF .debug_info/.debug_line for the function.
 *
 * Regenerate the fully annotated listing (pc-relative pool loads resolved to
 * their literal, every `bl` resolved to its callee) with:
 *     python scratch/laneS10/anno2.py     ->  scratch/laneS10/anno2.txt
 *     python scratch/laneS10/anno.py      ->  scratch/laneS10/anno.txt
 *     python scratch/laneS10/callees.py   ->  scratch/laneS10/callees.txt
 * Scratch artifacts already produced: gpisearch.o (the extracted object),
 * symmap.txt (word address -> symbol), callmap.txt (bl site -> name),
 * strings.txt (all 84 literals), gpiSearch.c/.h, gpiUtility.h (the Error /
 * CallbackError / CallbackFatalError / CHECK_RESULT macros, read from
 * github.com/nitrocaster/GameSpy @d1deb2d1).
 *
 * DWC DELTA vs the public source (verified, not guessed):
 *   - the request-build switch has an ELEVENTH case, data->type == 0xb,
 *     compared at 0x0219129C, handler at 0x021912A4 (transcribed below);
 *   - GPISearchData gains two ints at +0x198 (profileListID) and +0x19c
 *     (maxResults), read at 0x0219130C / 0x0219132C;
 *   - GPIConnection sessKey +0x198, userid +0x19c, profileid +0x1a0,
 *     partnerID +0x1a4, productID +0x60c, namespaceID +0x610
 *     (the 0xb case reads +0x198 and +0x1a0);
 *   - the response-parse switch has the matching 0xb case at 0x02192C18..
 *     0x02192D5x: strcmp "profilelist" (0x02192C18), then a loop on
 *     "pldone" (0x02192C60) / "hidden" (0x02192CA4) / "count" (0x02192CC4)
 *     / "o" (0x02192D1C, atoi -> arg->matches[arg->numMatches++] ...),
 *     gsimalloc(sizeof(int) * atoi(count)) at 0x02192CEC;
 *   - `msleep(10)` at 0x02192DE0 is the tail of the public source's
 *     `if(loop) msleep(10);` inside `} while(loop);`.
 * Everything else in the public source maps 1:1 onto this body.
 *
 * WHY NO PARTIAL CREDIT: register allocation, the 0x4d4 frame and every
 * branch displacement are global to the whole 2365-instruction function, so
 * no leading run byte-matches until the entire body is present.  The staged
 * split below exists so that each stage *compiles*, not so that it matches.
 *
 * NOT YET DONE (this lane, budget exhausted at +0x0000 divergence):
 *   STAGE 2b: the GPI_WAITING response parse (0x02191364 .. 0x02192D7C):
 *             gpiRecvToBuffer, the second timeout test, strstr("\\final\\"),
 *             gpiCheckForError, then the 11 parse cases.
 *   STAGE 3 : the tail: data->remove = 1 at 0x02192D74, loop = 0,
 *             `if(loop) msleep(10)` at 0x02192DE0, `while(loop)`,
 *             return GP_NO_ERROR at 0x02192DF0.
 * The parked 232-byte fragment this file used to hold was a FABRICATED stub
 * (its struct names and code shape were invented); it has been discarded.
 *
 * symbols:
 *   func_0218998C  gpiSendFromBuffer        0x0218998C  arm  ov009
 *   func_02193488  gpiCheckSocketConnect    0x02193488  arm  ov009
 *   func_0218946C  gpiAppendStringToBuffer  0x0218946C  arm  ov009
 *   func_0218949C  gpiAppendIntToBuffer     0x0218949C  arm  ov009
 *   func_0218934C  gpiAppendCharToBuffer    0x0218934C  arm  ov009
 *   func_02193748  gpiEncodeString          0x02193748  arm  ov009
 *   func_02189780  gpiRecvToBuffer          0x02189780  arm  ov009
 *   func_0219329C  gpiCheckForError         0x0219329C  arm  ov009
 *   func_0219359C  gpiReadKeyAndValue       0x0219359C  arm  ov009
 *   func_02193418  gpiValueForKey           0x02193418  arm  ov009
 *   func_02189DFC  gpiAddCallback           0x02189DFC  arm  ov009
 *   func_02189D78  gpiCallErrorCallback     0x02189D78  arm  ov009
 *   func_02193710  gpiSetError              0x02193710  arm  ov009
 *   func_02193734  gpiSetErrorString        0x02193734  arm  ov009
 *   func_021906E0  gpiProfileSearch         0x021906E0  arm  ov009
 *   func_0219327C  strzcpy                  0x0219327C  arm  ov009
 *   func_021803BC  gsiSafeStrcpyA           0x021803BC  arm  ov009
 *   func_0217F264  current_time             0x0217F264  arm  ov009
 *   func_0217F2BC  msleep                   0x0217F2BC  arm  ov009
 *   func_0217EAB0  gsimalloc                0x0217EAB0  arm  ov009
 *   func_0217EAC8  gsirealloc               0x0217EAC8  arm  ov009
 *   func_0217EAE0  gsifree                  0x0217EAE0  arm  ov009
 *   func_020948E0  strcmp                   0x020948E0  arm  arm9
 *   func_02094B20  strstr                   0x02094B20  arm  arm9
 *   func_020923B0  memset                   0x020923B0  arm  arm9
 *   func_020964E0  atoi                     0x020964E0  arm  arm9   (thunk)
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/ov_sdk/ov009_func_0219091C.c \
 *       --func func_0219091C --addr 0x0219091C --region ov009 --arm \
 *       --cc dsi/1.1p1 --lang c99 --diff
 *
 * STAGE COVERAGE so far: prologue/frame, function-head init, the GPI_SEARCH_
 * TIMEOUT test, the do-loop head (gpiSendFromBuffer), the GPI_CONNECTING
 * branch and the complete 11-case request-build switch, i.e. image
 * 0x0219091C .. 0x0219135C.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    char *buffer;   /* +0x00 */
    int   size;     /* +0x04 */
    int   len;      /* +0x08 */
    int   pos;      /* +0x0c */
} GPIBuffer;        /* 0x10 */

/* gpiSearch.h GPISearchData; every offset below is witnessed by a load in
 * this function, and the two trailing fields are the DWC extras. */
typedef struct {
    int      type;                    /* +0x000 */
    int      sock;                    /* +0x004 */
    GPIBuffer inputBuffer;            /* +0x008 */
    GPIBuffer outputBuffer;           /* +0x018 */
    char     nick[0x1f];              /* +0x028 */
    char     uniquenick[0x51];        /* +0x047 */
    int      namespaceIDs[1];         /* +0x098 */
    int      numNamespaces;           /* +0x09c */
    char     email[0x33];             /* +0x0a0 */
    char     firstname[0x1f];         /* +0x0d3 */
    char     lastname[0x1f];          /* +0x0f2 */
    char     password[0x1f];          /* +0x111 */
    char     cdkey[0x44];             /* +0x130 (declared long: absorbs the
                                       *        SDK's alignment padding) */
    int      partnerID;               /* +0x174 */
    int      icquin;                  /* +0x178 */
    int      skip;                    /* +0x17c */
    int      productID;               /* +0x180 */
    int      processing;              /* +0x184 */
    int      remove;                  /* +0x188 */
    u32      searchStartTime;         /* +0x18c */
    int     *revBuddyProfileIds;      /* +0x190 */
    int      numOfRevBuddyProfiles;   /* +0x194 */
    int      profileListID;           /* +0x198   DWC extra */
    int      maxResults;              /* +0x19c   DWC extra */
} GPISearchData;

/* GPIConnection, only the members this function touches. */
typedef struct {
    char pad00[0x198];
    int  sessKey;                     /* +0x198 */
    int  userid;                      /* +0x19c */
    int  profileid;                   /* +0x1a0 */
    int  partnerID;                   /* +0x1a4 */
    char pad1a8[0x60c - 0x1a8];
    int  productID;                   /* +0x60c */
    int  namespaceID;                 /* +0x610 */
} GPIConnection;

/* GPIOperation, only the members this function touches. */
typedef struct {
    char      pad00[0x04];
    void     *data;                   /* +0x04  (the GPISearchData *) */
    int       blocking;               /* +0x08 */
    char      pad0c[0x14 - 0x0c];
    int       state;                  /* +0x14 */
} GPIOperation;

/* ---------------------------------------------------------------- literals
 * Every string argument is an absolute ov009 data address; a source that
 * emits its own literals can never match.  name = g_<linked address>.
 * 0x02191840 0x0000EA60 = GPI_SEARCH_TIMEOUT, 0x02191844 0x00000D02 =
 * GP_SEARCH_TIMED_OUT (see gpiSetError at 0x0219095C). */
extern char g_02191848[];  /* "The search timed out"                     */
extern char g_0219184C[];  /* "SM"                                       */
extern char g_02191850[];  /* "Could not connect to the search manager." */
extern char g_02191854[];  /* "\\search\\"        */
extern char g_02191858[];  /* "\\sesskey\\"       */
extern char g_0219185C[];  /* "\\profileid\\"     */
extern char g_02191860[];  /* "\\namespaceid\\"   */
extern char g_02191864[];  /* "\\partnerid\\"     */
extern char g_02191868[];  /* "\\nick\\"          */
extern char g_0219186C[];  /* "\\uniquenick\\"    */
extern char g_02191870[];  /* "\\email\\"         */
extern char g_02191874[];  /* "\\firstname\\"     */
extern char g_02191878[];  /* "\\lastname\\"      */
extern char g_0219187C[];  /* "\\icquin\\"        */
extern char g_02191880[];  /* "\\skip\\"          */
extern char g_02191884[];  /* "\\searchunique\\"  */
extern char g_02191888[];  /* "\\namespaces\\"    */
extern char g_0219188C[];  /* "\\valid\\"         */
extern char g_02191890[];  /* "\\nicks\\"         */
extern char g_02191894[];  /* "\\passenc\\"       */
extern char g_02191898[];  /* "\\pmatch\\"        */
extern char g_0219189C[];  /* "\\productid\\"     */
extern char g_021918A0[];  /* "\\check\\"         */
extern char g_021918A4[];  /* "\\newuser\\"       */
extern char g_021918A8[];  /* "\\productID\\"     */
extern char g_021918AC[];  /* "\\cdkey\\"         */
extern char g_021918B0[];  /* "\\others\\"        */
extern char g_021918B4[];  /* "\\otherslist\\"    */
extern char g_021918B8[];  /* "\\numopids\\"      */
extern char g_021918BC[];  /* "\\opids\\"         */
extern char g_021918C0[];  /* "|"                 */
extern char g_021918C4[];  /* "\\uniquesearch\\"  */
extern char g_021918C8[];  /* "\\preferrednick\\" */
extern char g_021918CC[];  /* "\\profilelist\\"   DWC 0xb */
extern char g_021918D0[];  /* "\\searchprofileid\\" DWC 0xb */
extern char g_021918D4[];  /* "\\maxresults\\"    DWC 0xb */
extern char g_021918D8[];  /* "\\gamename\\"      */
extern char g_021918DC[];  /* __GSIACGamename     */
extern char g_021918E0[];  /* "\\final\\"         */
extern char g_021918E4[];  /* "There was an error reading from the server." */
extern char g_021918EC[];  /* "bsrdone"   */
extern char g_021918F0[];  /* "more"      */
extern char g_021918F4[];  /* "0"         */
extern char g_021918F8[];  /* "bsr"       */
extern char g_021918FC[];  /* "Out of memory." */
extern char g_02191900[];  /* "nick"        */
extern char g_02191904[];  /* "uniquenick"  */
extern char g_02191908[];  /* "namespaceid" */
extern char g_0219190C[];  /* "firstname"   */
extern char g_02191910[];  /* "lastname"    */
extern char g_02191914[];  /* "email"       */
extern char g_02191918[];  /* "Error reading from the search server." */
extern char g_0219191C[];  /* "vr"          */
extern char g_02192A94[];  /* "nr"          */
extern char g_02192A98[];  /* "ndone"       */
extern char g_02192A9C[];  /* "psrdone"     */
extern char g_02192AA0[];  /* "psr"         */
extern char g_02192AA4[];  /* "status"      */
extern char g_02192AA8[];  /* "statuscode"  */
extern char g_02192AAC[];  /* "cur"         */
extern char g_02192AB0[];  /* "\\pid\\"     */
extern char g_02192AB4[];  /* "nur"         */
extern char g_02192AB8[];  /* "others"      */
extern char g_02192ABC[];  /* "odone"       */
extern char g_02192AC0[];  /* "o"           */
extern char g_02192AC4[];  /* "first"       */
extern char g_02192AC8[];  /* "last"        */
extern char g_02192ACC[];  /* "otherslist"  */
extern char g_02192AD0[];  /* "oldone"      */
extern char g_02192AD4[];  /* "uniquenick"  */
extern char g_02192AD8[];  /* "Error reading from the search server." */
extern char g_02192ADC[];  /* "Out of memory." */
extern char g_02192AE0[];  /* "us"          */
extern char g_02192AE4[];  /* "nick"        */
extern char g_02192DFC[];  /* "usdone"      */
extern char g_02192E00[];  /* "profilelist" DWC 0xb */
extern char g_02192E04[];  /* "pldone"      DWC 0xb */
extern char g_02192E08[];  /* "hidden"      DWC 0xb */
extern char g_02192E0C[];  /* "count"       DWC 0xb */

/* ------------------------------------------------------------------ callees */
extern int  func_0218998C(int *connection, int sock, GPIBuffer *buffer, int *connClosed, int flag, char *tag);
extern int  func_02193488(int *connection, int sock, int *state, void *out);
extern void func_0218946C(int *connection, GPIBuffer *buffer, char *str);
extern void func_0218949C(int *connection, GPIBuffer *buffer, int value);
extern void func_0218934C(int *connection, GPIBuffer *buffer, int ch);
extern void func_02193748(char *src, char *dst);
extern int  func_02189780(int *connection, int sock, GPIBuffer *buffer, int *len, int *connClosed, char *tag);
extern int  func_0219329C(int *connection, char *buffer, int flag);
extern int  func_0219359C(int *connection, char *buffer, int *index, char *key, char *value);
extern int  func_02193418(GPIBuffer *buffer, char *key, char *value, int len);
extern int  func_02189DFC(int *connection, int callback, void *arg, void *operation, int type);
extern void func_02189D78(int *connection, int result, int fatal);
extern void func_02193710(int *connection, int code, char *string);
extern void func_02193734(int *connection, char *string);
extern int  func_021906E0(int *connection, char *nick, char *uniquenick, char *email,
                          char *firstname, char *lastname, int icquin, int skip,
                          int blocking, int callback, int param);
extern void func_0219327C(char *dest, char *src, int len);
extern char *func_021803BC(char *dest, char *src, int len);
extern u32  func_0217F264(void);
extern void func_0217F2BC(u32 ms);
extern void *func_0217EAB0(int size);
extern void *func_0217EAC8(void *mem, int size);
extern void func_0217EAE0(void *mem);
extern int  func_020948E0(char *a, char *b);        /* strcmp */
extern char *func_02094B20(char *hay, char *needle); /* strstr */
extern void func_020923B0(void *dst, int ch, int n); /* memset */
extern int  func_020964E0(char *s);                  /* atoi   */

/* The Error / CallbackError / CallbackFatalError / CHECK_RESULT macros, as
 * spelled in gpiUtility.h (the expansions below are the observed call
 * sequences). */
#define Error(connection, result, string) \
    { func_02193734(connection, string); return (result); }
#define CallbackError(connection, result, code, string) \
    { func_02193710(connection, (code), string); \
      func_02189D78(connection, (result), 0); return (result); }
#define CallbackFatalError(connection, result, code, string) \
    { func_02193710(connection, (code), string); \
      func_02189D78(connection, (result), 1); return (result); }
#define CHECK_RESULT(result) \
    { int __result__ = (result); if (__result__ != 0) return __result__; }

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
#define GPI_SEARCH_PROFILE_LIST       11   /* DWC 0xb */

#define GPI_SEARCH_TIMEOUT   60000
#define GP_SEARCH_TIMED_OUT  3330          /* word at 0x02191844 */
#define GP_PARSE             1
#define GP_NETWORK_ERROR     3
#define GP_MEMORY_ERROR      1

#define GPI_CONNECTING 1
#define GPI_CONNECTED  2
#define GPI_WAITING    4      /* witnessed: 0x02191370 "mov r1,#4; str r1,[operation+0x14]",
                               * and the 0x0219137C test "cmp r0,#4; bne tail" */
#define GPI_DISCONNECTED 0

int func_0219091C(int *connection, GPIOperation *operation)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    GPISearchData *data;
    char key[0x10];
    char value[0x10];
    char passwordenc[0x14];
    int state;
    int loop;
    int done;
    int result;
    int index;

    data = (GPISearchData *)operation->data;

    if (operation->blocking)
        loop = 1;
    else
        loop = 0;

    if (!operation->blocking &&
        (func_0217F264() - data->searchStartTime > GPI_SEARCH_TIMEOUT)) {
        data->remove = 1;
        CallbackError(connection, GP_NETWORK_ERROR, GP_SEARCH_TIMED_OUT,
                      g_02191848);
    }

    do {
        /* Send anything that needs to be sent. */
        CHECK_RESULT(func_0218998C(connection, data->sock, &data->outputBuffer,
                                   &result, 1, g_0219184C));

        if (operation->state == GPI_CONNECTING) {
            CHECK_RESULT(func_02193488(connection, data->sock, &state, &state));

            if (state == GPI_DISCONNECTED)
                CallbackError(connection, 3 /*GP_SERVER_ERROR*/, 0x0e05,
                              g_02191850);

            if (state == GPI_CONNECTED) {
                if (data->type == GPI_SEARCH_PROFILE) {
                    func_0218946C(connection, &data->outputBuffer, g_02191854);
                    func_0218946C(connection, &data->outputBuffer, g_02191858);
                    func_0218949C(connection, &data->outputBuffer, iconnection->sessKey);
                    func_0218946C(connection, &data->outputBuffer, g_0219185C);
                    func_0218949C(connection, &data->outputBuffer, iconnection->profileid);
                    func_0218946C(connection, &data->outputBuffer, g_02191860);
                    func_0218949C(connection, &data->outputBuffer, iconnection->namespaceID);
                    func_0218946C(connection, &data->outputBuffer, g_02191864);
                    func_0218949C(connection, &data->outputBuffer, iconnection->partnerID);
                    if (data->nick[0] != 0) {
                        func_0218946C(connection, &data->outputBuffer, g_02191868);
                        func_0218946C(connection, &data->outputBuffer, data->nick);
                    }
                    if (data->uniquenick[0] != 0) {
                        func_0218946C(connection, &data->outputBuffer, g_0219186C);
                        func_0218946C(connection, &data->outputBuffer, data->uniquenick);
                    }
                    if (data->email[0] != 0) {
                        func_0218946C(connection, &data->outputBuffer, g_02191870);
                        func_0218946C(connection, &data->outputBuffer, data->email);
                    }
                    if (data->firstname[0] != 0) {
                        func_0218946C(connection, &data->outputBuffer, g_02191874);
                        func_0218946C(connection, &data->outputBuffer, data->firstname);
                    }
                    if (data->lastname[0] != 0) {
                        func_0218946C(connection, &data->outputBuffer, g_02191878);
                        func_0218946C(connection, &data->outputBuffer, data->lastname);
                    }
                    if (data->icquin != 0) {
                        func_0218946C(connection, &data->outputBuffer, g_0219187C);
                        func_0218949C(connection, &data->outputBuffer, data->icquin);
                    }
                    if (data->skip > 0) {
                        func_0218946C(connection, &data->outputBuffer, g_02191880);
                        func_0218949C(connection, &data->outputBuffer, data->skip);
                    }
                }
                else if (data->type == GPI_SEARCH_PROFILE_UNIQUENICK) {
                    int i;
                    func_0218946C(connection, &data->outputBuffer, g_02191884);
                    func_0218946C(connection, &data->outputBuffer, g_02191858);
                    func_0218949C(connection, &data->outputBuffer, iconnection->sessKey);
                    func_0218946C(connection, &data->outputBuffer, g_0219185C);
                    func_0218949C(connection, &data->outputBuffer, iconnection->profileid);
                    func_0218946C(connection, &data->outputBuffer, g_0219186C);
                    func_0218946C(connection, &data->outputBuffer, data->uniquenick);
                    func_0218946C(connection, &data->outputBuffer, g_02191888);
                    if (data->numNamespaces > 0) {
                        for (i = 0; i < data->numNamespaces; i++) {
                            if (i > 0)
                                func_0218934C(connection, &data->outputBuffer, ',');
                            func_0218949C(connection, &data->outputBuffer, data->namespaceIDs[i]);
                        }
                    }
                    else {
                        func_0218949C(connection, &data->outputBuffer, iconnection->namespaceID);
                    }
                }
                else if (data->type == GPI_SEARCH_IS_VALID) {
                    func_0218946C(connection, &data->outputBuffer, g_0219188C);
                    func_0218946C(connection, &data->outputBuffer, g_02191870);
                    func_0218946C(connection, &data->outputBuffer, data->email);
                    func_0218946C(connection, &data->outputBuffer, g_02191864);
                    func_0218949C(connection, &data->outputBuffer, iconnection->partnerID);
                }
                else if (data->type == GPI_SEARCH_NICKS) {
                    func_0218946C(connection, &data->outputBuffer, g_02191890);
                    func_0218946C(connection, &data->outputBuffer, g_02191870);
                    func_0218946C(connection, &data->outputBuffer, data->email);
                    func_02193748(data->password, passwordenc);
                    func_0218946C(connection, &data->outputBuffer, g_02191894);
                    func_0218946C(connection, &data->outputBuffer, passwordenc);
                    func_0218946C(connection, &data->outputBuffer, g_02191860);
                    func_0218949C(connection, &data->outputBuffer, iconnection->namespaceID);
                    func_0218946C(connection, &data->outputBuffer, g_02191864);
                    func_0218949C(connection, &data->outputBuffer, iconnection->partnerID);
                }
                else if (data->type == GPI_SEARCH_PLAYERS) {
                    func_0218946C(connection, &data->outputBuffer, g_02191898);
                    func_0218946C(connection, &data->outputBuffer, g_02191858);
                    func_0218949C(connection, &data->outputBuffer, iconnection->sessKey);
                    func_0218946C(connection, &data->outputBuffer, g_0219185C);
                    func_0218949C(connection, &data->outputBuffer, iconnection->profileid);
                    func_0218946C(connection, &data->outputBuffer, g_0219189C);
                    func_0218949C(connection, &data->outputBuffer, data->productID);
                }
                else if (data->type == GPI_SEARCH_CHECK) {
                    func_0218946C(connection, &data->outputBuffer, g_021918A0);
                    func_0218946C(connection, &data->outputBuffer, g_02191868);
                    func_0218946C(connection, &data->outputBuffer, data->nick);
                    func_0218946C(connection, &data->outputBuffer, g_02191870);
                    func_0218946C(connection, &data->outputBuffer, data->email);
                    func_0218946C(connection, &data->outputBuffer, g_02191864);
                    func_0218949C(connection, &data->outputBuffer, iconnection->partnerID);
                    func_02193748(data->password, passwordenc);
                    func_0218946C(connection, &data->outputBuffer, g_02191894);
                    func_0218946C(connection, &data->outputBuffer, passwordenc);
                }
                else if (data->type == GPI_SEARCH_NEWUSER) {
                    func_0218946C(connection, &data->outputBuffer, g_021918A4);
                    func_0218946C(connection, &data->outputBuffer, g_02191868);
                    func_0218946C(connection, &data->outputBuffer, data->nick);
                    func_0218946C(connection, &data->outputBuffer, g_02191870);
                    func_0218946C(connection, &data->outputBuffer, data->email);
                    func_02193748(data->password, passwordenc);
                    func_0218946C(connection, &data->outputBuffer, g_02191894);
                    func_0218946C(connection, &data->outputBuffer, passwordenc);
                    func_0218946C(connection, &data->outputBuffer, g_021918A8);
                    func_0218949C(connection, &data->outputBuffer, iconnection->productID);
                    func_0218946C(connection, &data->outputBuffer, g_02191860);
                    func_0218949C(connection, &data->outputBuffer, iconnection->namespaceID);
                    func_0218946C(connection, &data->outputBuffer, g_0219186C);
                    func_0218946C(connection, &data->outputBuffer, data->uniquenick);
                    if (data->cdkey[0]) {
                        func_0218946C(connection, &data->outputBuffer, g_021918AC);
                        func_0218946C(connection, &data->outputBuffer, data->cdkey);
                    }
                    func_0218946C(connection, &data->outputBuffer, g_02191864);
                    func_0218949C(connection, &data->outputBuffer, iconnection->partnerID);
                }
                else if (data->type == GPI_SEARCH_OTHERS_BUDDY) {
                    func_0218946C(connection, &data->outputBuffer, g_021918B0);
                    func_0218946C(connection, &data->outputBuffer, g_02191858);
                    func_0218949C(connection, &data->outputBuffer, iconnection->sessKey);
                    func_0218946C(connection, &data->outputBuffer, g_0219185C);
                    func_0218949C(connection, &data->outputBuffer, iconnection->profileid);
                    func_0218946C(connection, &data->outputBuffer, g_02191860);
                    func_0218949C(connection, &data->outputBuffer, iconnection->namespaceID);
                }
                else if (data->type == GPI_SEARCH_OTHERS_BUDDY_LIST) {
                    int i;
                    func_0218946C(connection, &data->outputBuffer, g_021918B4);
                    func_0218946C(connection, &data->outputBuffer, g_02191858);
                    func_0218949C(connection, &data->outputBuffer, iconnection->sessKey);
                    func_0218946C(connection, &data->outputBuffer, g_0219185C);
                    func_0218949C(connection, &data->outputBuffer, iconnection->profileid);
                    func_0218946C(connection, &data->outputBuffer, g_021918B8);
                    func_0218949C(connection, &data->outputBuffer, data->numOfRevBuddyProfiles);
                    func_0218946C(connection, &data->outputBuffer, g_021918BC);
                    if (data->revBuddyProfileIds) {
                        func_0218949C(connection, &data->outputBuffer, data->revBuddyProfileIds[0]);
                        for (i = 1; i < data->numOfRevBuddyProfiles; i++) {
                            func_0218946C(connection, &data->outputBuffer, g_021918C0);
                            func_0218949C(connection, &data->outputBuffer, data->revBuddyProfileIds[i]);
                        }
                    }
                    func_0218946C(connection, &data->outputBuffer, g_02191860);
                    func_0218949C(connection, &data->outputBuffer, iconnection->namespaceID);
                }
                else if (data->type == GPI_SEARCH_SUGGEST_UNIQUE) {
                    func_0218946C(connection, &data->outputBuffer, g_021918C4);
                    func_0218946C(connection, &data->outputBuffer, g_021918C8);
                    func_0218946C(connection, &data->outputBuffer, data->uniquenick);
                    func_0218946C(connection, &data->outputBuffer, g_02191860);
                    func_0218949C(connection, &data->outputBuffer, iconnection->namespaceID);
                }
                /* DWC eleventh case, 0xb: image 0x0219129C (compare) /
                 * 0x021912A4 (body), ends at 0x02191338. */
                else if (data->type == GPI_SEARCH_PROFILE_LIST) {
                    func_0218946C(connection, &data->outputBuffer, g_021918CC);
                    func_0218946C(connection, &data->outputBuffer, g_02191858);
                    func_0218949C(connection, &data->outputBuffer, iconnection->sessKey);
                    func_0218946C(connection, &data->outputBuffer, g_0219185C);
                    func_0218949C(connection, &data->outputBuffer, iconnection->profileid);
                    func_0218946C(connection, &data->outputBuffer, g_021918D0);
                    func_0218949C(connection, &data->outputBuffer, data->profileListID);
                    func_0218946C(connection, &data->outputBuffer, g_021918D4);
                    func_0218949C(connection, &data->outputBuffer, data->maxResults);
                }

                func_0218946C(connection, &data->outputBuffer, g_021918D8);
                func_0218946C(connection, &data->outputBuffer, g_021918DC);
                func_0218946C(connection, &data->outputBuffer, g_021918E0);

                operation->state = GPI_WAITING;
            }
        }
        else if (operation->state == GPI_WAITING) {
            /* ------------------------------------------------------------------
             * STAGE 2b FRONTIER: 0x02191364 .. 0x02192D7C.
             * Transcribe from scratch/laneS10/anno2.txt: gpiRecvToBuffer
             * (0x02191398), the blocking timeout retest, strstr("\\final\\")
             * (0x02191450), gpiCheckForError (0x0219147C), then the eleven
             * response-parse cases.  The 0xb case is at 0x02192C18..0x02192D5x
             * and is transcribed in the header comment above.
             * ------------------------------------------------------------------ */
            return 0;
        }
    } while (loop);

    return 0;
}
