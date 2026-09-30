/*
 * function: func_0219091C
 * address:  0x0219091C
 * packet:   pkt_ov009_0219091C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      gpiProcessSearch (TwlDWC/libdwcgsgp.TWL.HYB.a gpisearch.o)
 *
 * blocker:  codegen, not the C.  The full body is present and compiles to 9456
 *           of the 9460 bytes with 389 relocation sites (the image has 389);
 *           every call and data site resolves.  What is unresolved is the
 *           callee-saved register assignment (the image keeps `loop` in r8 and
 *           the pooled GPITrue scratch in r9; 1.1p1 does the reverse, and
 *           carries key/value/&index in different registers), two scheduled
 *           instruction orders (the two-part `sp+0x2d1` address computation is
 *           emitted in the other order), and the image's inlined unrolled
 *           zeroing of the new GPUniqueMatch: 1.1p1 does not inline `memset`
 *           (probed at -O1..-O4 and -O4,p: always a call) and folds an explicit
 *           zeroing loop back into a `memset` call, so that 28-byte body is not
 *           reproducible from this front end.  Ruled out: struct layout (all
 *           offsets are DWARF-exact), callee/string addresses (all resolve),
 *           and the 0xb request/response cases (transcribed from the object's
 *           own relocations).
 *
 * Full-body reconstruction of gpiProcessSearch.  Types, struct offsets and
 * source line numbers are taken from the DWARF of the vendor member
 * (scratch/laneS10/gpisearch.o); the body tracks the public GameSpy
 * gpiSearch.c with the DWC deltas (GPI_SEARCH_PROFILE_LIST = 0xb in both the
 * request-build and response-parse switches, and GPISearchData.profile /
 * .maxResults at +0x198 / +0x19c).
 *
 * symbols:
 *   func_0218998C  0x0218998C  arm  ov009
 *   func_02193488  0x02193488  arm  ov009
 *   func_0218946C  0x0218946C  arm  ov009
 *   func_0218949C  0x0218949C  arm  ov009
 *   func_0218934C  0x0218934C  arm  ov009
 *   func_02193748  0x02193748  arm  ov009
 *   func_02189780  0x02189780  arm  ov009
 *   func_0219329C  0x0219329C  arm  ov009
 *   func_0219359C  0x0219359C  arm  ov009
 *   func_02193418  0x02193418  arm  ov009
 *   func_02189DFC  0x02189DFC  arm  ov009
 *   func_02189D78  0x02189D78  arm  ov009
 *   func_02193710  0x02193710  arm  ov009
 *   func_02193734  0x02193734  arm  ov009
 *   func_021906E0  0x021906E0  arm  ov009
 *   func_0219327C  0x0219327C  arm  ov009
 *   func_021803BC  0x021803BC  arm  ov009
 *   func_0217F264  0x0217F264  arm  ov009
 *   func_0217F2BC  0x0217F2BC  arm  ov009
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_0217EAC8  0x0217EAC8  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_020948E0  0x020948E0  arm
 *   func_02094B20  0x02094B20  arm
 *   memset        0x020923B0  arm
 *   func_020964E0  0x020964E0  arm
 *
 *   g_02191848                               0x02191848  data
 *   g_0219184C                               0x0219184C  data
 *   g_02191850                               0x02191850  data
 *   g_02191854                               0x02191854  data
 *   g_02191858                               0x02191858  data
 *   g_0219185C                               0x0219185C  data
 *   g_02191860                               0x02191860  data
 *   g_02191864                               0x02191864  data
 *   g_02191868                               0x02191868  data
 *   g_0219186C                               0x0219186C  data
 *   g_02191870                               0x02191870  data
 *   g_02191874                               0x02191874  data
 *   g_02191878                               0x02191878  data
 *   g_0219187C                               0x0219187C  data
 *   g_02191880                               0x02191880  data
 *   g_02191884                               0x02191884  data
 *   g_02191888                               0x02191888  data
 *   g_0219188C                               0x0219188C  data
 *   g_02191890                               0x02191890  data
 *   g_02191894                               0x02191894  data
 *   g_02191898                               0x02191898  data
 *   g_0219189C                               0x0219189C  data
 *   g_021918A0                               0x021918A0  data
 *   g_021918A4                               0x021918A4  data
 *   g_021918A8                               0x021918A8  data
 *   g_021918AC                               0x021918AC  data
 *   g_021918B0                               0x021918B0  data
 *   g_021918B4                               0x021918B4  data
 *   g_021918B8                               0x021918B8  data
 *   g_021918BC                               0x021918BC  data
 *   g_021918C0                               0x021918C0  data
 *   g_021918C4                               0x021918C4  data
 *   g_021918C8                               0x021918C8  data
 *   g_021918CC                               0x021918CC  data
 *   g_021918D0                               0x021918D0  data
 *   g_021918D4                               0x021918D4  data
 *   g_021918D8                               0x021918D8  data
 *   g_021918DC                               0x021918DC  data
 *   g_021918E0                               0x021918E0  data
 *   g_021918E4                               0x021918E4  data
 *   g_021918EC                               0x021918EC  data
 *   g_021918F0                               0x021918F0  data
 *   g_021918F4                               0x021918F4  data
 *   g_021918F8                               0x021918F8  data
 *   g_021918FC                               0x021918FC  data
 *   g_02191900                               0x02191900  data
 *   g_02191904                               0x02191904  data
 *   g_02191908                               0x02191908  data
 *   g_0219190C                               0x0219190C  data
 *   g_02191910                               0x02191910  data
 *   g_02191914                               0x02191914  data
 *   g_02191918                               0x02191918  data
 *   g_0219191C                               0x0219191C  data
 *   g_02192A94                               0x02192A94  data
 *   g_02192A98                               0x02192A98  data
 *   g_02192A9C                               0x02192A9C  data
 *   g_02192AA0                               0x02192AA0  data
 *   g_02192AA4                               0x02192AA4  data
 *   g_02192AA8                               0x02192AA8  data
 *   g_02192AAC                               0x02192AAC  data
 *   g_02192AB0                               0x02192AB0  data
 *   g_02192AB4                               0x02192AB4  data
 *   g_02192AB8                               0x02192AB8  data
 *   g_02192ABC                               0x02192ABC  data
 *   g_02192AC0                               0x02192AC0  data
 *   g_02192AC4                               0x02192AC4  data
 *   g_02192AC8                               0x02192AC8  data
 *   g_02192ACC                               0x02192ACC  data
 *   g_02192AD0                               0x02192AD0  data
 *   g_02192AD4                               0x02192AD4  data
 *   g_02192AD8                               0x02192AD8  data
 *   g_02192ADC                               0x02192ADC  data
 *   g_02192AE0                               0x02192AE0  data
 *   g_02192AE4                               0x02192AE4  data
 *   g_02192DFC                               0x02192DFC  data
 *   g_02192E00                               0x02192E00  data
 *   g_02192E04                               0x02192E04  data
 *   g_02192E08                               0x02192E08  data
 *   g_02192E0C                               0x02192E0C  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef int GPIBool;
typedef int GPResult;
typedef int GPEnum;
typedef int GPErrorCode;
typedef void *GPConnection;
typedef u32 gsi_time;

#define GPITrue  1
#define GPIFalse 0

#define GP_NO_ERROR          0
#define GP_MEMORY_ERROR      1
#define GP_PARAMETER_ERROR   2
#define GP_NETWORK_ERROR     3
#define GP_SERVER_ERROR      4

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

typedef struct {
    char *buffer;   /* +0x00 */
    int   size;     /* +0x04 */
    int   len;      /* +0x08 */
    int   pos;      /* +0x0c */
} GPIBuffer;        /* 0x10 */

typedef struct {
    int      type;                    /* +0x000 */
    int      sock;                    /* +0x004 */
    GPIBuffer inputBuffer;            /* +0x008 */
    GPIBuffer outputBuffer;           /* +0x018 */
    char     nick[31];                /* +0x028 */
    char     uniquenick[21];          /* +0x047 */
    int      namespaceIDs[16];        /* +0x05c */
    int      numNamespaces;           /* +0x09c */
    char     email[51];               /* +0x0a0 */
    char     firstname[31];           /* +0x0d3 */
    char     lastname[31];            /* +0x0f2 */
    char     password[31];            /* +0x111 */
    char     cdkey[65];               /* +0x130 */
    int      partnerID;               /* +0x174 */
    int      icquin;                  /* +0x178 */
    int      skip;                    /* +0x17c */
    int      productID;               /* +0x180 */
    int      processing;              /* +0x184 */
    int      remove;                  /* +0x188 */
    u32      searchStartTime;         /* +0x18c */
    int     *revBuddyProfileIds;      /* +0x190 */
    int      numOfRevBuddyProfiles;   /* +0x194 */
    int      profile;                 /* +0x198 */
    int      maxResults;              /* +0x19c */
} GPISearchData;

typedef struct {
    char pad00[0x198];
    int  sessKey;                     /* +0x198 */
    int  userid;                      /* +0x19c */
    int  profileid;                   /* +0x1a0 */
    int  partnerID;                   /* +0x1a4 */
    char pad1a8[0x5b8 - 0x1a8];
    GPErrorCode errorCode;            /* +0x5b8 */
    char pad5bc[0x60c - 0x5bc];
    int  productID;                   /* +0x60c */
    int  namespaceID;                 /* +0x610 */
} GPIConnection;

typedef struct {
    void *callback;                   /* +0x00 */
    void *param;                      /* +0x04 */
} GPICallback;

typedef struct {
    int       type;                   /* +0x00 */
    void     *data;                   /* +0x04 */
    GPIBool   blocking;               /* +0x08 */
    GPICallback callback;             /* +0x0c */
    int       state;                  /* +0x14 */
    int       id;                     /* +0x18 */
    GPResult  result;                 /* +0x1c */
    void     *pnext;                  /* +0x20 */
} GPIOperation;                       /* 0x24 */

typedef struct {
    int  profile;                     /* +0x00 */
    char nick[31];                    /* +0x04 */
    char uniquenick[21];              /* +0x23 */
    int  namespaceID;                 /* +0x38 */
    char firstname[31];               /* +0x3c */
    char lastname[31];                /* +0x5b */
    char email[51];                   /* +0x7a */
} GPProfileSearchMatch;               /* 0xb0 */

typedef struct {
    int   profile;                    /* +0x00 */
    char  uniqueNick[21];             /* +0x04 */
} GPUniqueMatch;                      /* 0x1c */

typedef struct {
    int                   result;     /* +0x00 */
    int                   numMatches; /* +0x04 */
    GPEnum                more;       /* +0x08 */
    GPProfileSearchMatch *matches;    /* +0x0c */
} GPProfileSearchResponseArg;         /* 0x10 */

typedef struct {
    int       result;                 /* +0x00 */
    int       numProfiles;            /* +0x04 */
    GPProfileSearchMatch *profiles;   /* +0x08 */
} GPGetReverseBuddiesResponseArg;     /* 0x0c */

typedef struct {
    int           result;             /* +0x00 */
    int           numOfUniqueMatchs;  /* +0x04 */
    GPUniqueMatch *matches;           /* +0x08 */
} GPGetReverseBuddiesListResponseArg; /* 0x0c */

typedef struct {
    int   result;                     /* +0x00 */
    char  email[51];                  /* +0x04 */
    GPEnum isValid;                   /* +0x38 */
} GPIsValidEmailResponseArg;          /* 0x3c */

typedef struct {
    int   result;                     /* +0x00 */
    char  email[51];                  /* +0x04 */
    int   numNicks;                   /* +0x38 */
    char **nicks;                     /* +0x3c */
    char **uniquenicks;               /* +0x40 */
} GPGetUserNicksResponseArg;          /* 0x44 */

typedef struct {
    int   profile;                    /* +0x00 */
    char  nick[31];                   /* +0x04 */
    GPEnum status;                    /* +0x24 */
    char  statusString[256];          /* +0x28 */
} GPFindPlayerMatch;                  /* 0x128 */

typedef struct {
    int                 result;       /* +0x00 */
    int                 productID;    /* +0x04 */
    int                 numMatches;   /* +0x08 */
    GPFindPlayerMatch  *matches;      /* +0x0c */
} GPFindPlayersResponseArg;           /* 0x10 */

typedef struct {
    int     result;                   /* +0x00 */
    int     profile;                  /* +0x04 */
} GPNewUserResponseArg;               /* 0x08 */

typedef struct {
    int     result;                   /* +0x00 */
    int     profile;                  /* +0x04 */
} GPCheckResponseArg;                 /* 0x08 */

typedef struct {
    int     result;                   /* +0x00 */
    int     numSuggestedNicks;        /* +0x04 */
    char  **suggestedNicks;           /* +0x08 */
} GPSuggestUniqueNickResponseArg;     /* 0x0c */

typedef struct {
    int   result;                     /* +0x00 */
    int   profile;                    /* +0x04 */
    int   hidden;                     /* +0x08 */
    int   numMatches;                 /* +0x0c */
    int  *matches;                    /* +0x10 */
} GPProfileListResponseArg;           /* 0x14 */

extern GPResult func_0218998C(GPConnection *connection, int sock, GPIBuffer *buffer,
                              GPIBool *connClosed, GPIBool flag, char *tag);
extern GPResult func_02193488(GPConnection *connection, int sock, int *state);
extern void func_0218946C(GPConnection *connection, GPIBuffer *buffer, char *str);
extern void func_0218949C(GPConnection *connection, GPIBuffer *buffer, int value);
extern void func_0218934C(GPConnection *connection, GPIBuffer *buffer, int ch);
extern void func_02193748(char *src, char *dst);
extern GPResult func_02189780(GPConnection *connection, int sock, GPIBuffer *buffer,
                              int *len, GPIBool *connClosed, char *tag);
extern GPIBool func_0219329C(GPConnection *connection, char *buffer, GPIBool flag);
extern GPResult func_0219359C(GPConnection *connection, char *buffer, int *index,
                              char *key, char *value);
extern GPIBool func_02193418(char *buffer, char *key, char *value, int len);
extern GPResult func_02189DFC(GPConnection *connection, GPICallback callback, void *arg,
                              GPIOperation *operation, int type);
extern void func_02189D78(GPConnection *connection, GPResult result, GPIBool fatal);
extern void func_02193710(GPConnection *connection, GPErrorCode code, char *string);
extern void func_02193734(GPConnection *connection, char *string);
extern GPResult func_021906E0(GPConnection *connection, char *nick, char *uniquenick,
                              char *email, char *firstname, char *lastname, int icquin,
                              int skip, GPEnum blocking, void *callback, void *param);
extern void func_0219327C(char *dest, char *src, int len);
extern char *func_021803BC(char *dest, char *src, int len);
extern u32 func_0217F264(void);
extern void func_0217F2BC(u32 ms);
extern void *func_0217EAB0(int size);
extern void *func_0217EAC8(void *mem, int size);
extern void func_0217EAE0(void *mem);
extern int func_020948E0(char *a, char *b);
extern char *func_02094B20(char *hay, char *needle);
extern void *memset(void *dst, int ch, unsigned long n);
extern int func_020964E0(char *s);

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

#define Error(connection, result, string) \
    { func_02193734(connection, string); return (result); }
#define CallbackError(connection, result, code, string) \
    { func_02193710(connection, (code), string); \
      func_02189D78(connection, (result), GP_NON_FATAL); return (result); }
#define CallbackFatalError(connection, result, code, string) \
    { func_02193710(connection, (code), string); \
      func_02189D78(connection, (result), GP_FATAL); return (result); }
#define CHECK_RESULT(result) \
    { GPResult __result__ = (result); if (__result__ != GP_NO_ERROR) { return __result__; } }
#define freeclear(mem) \
    { func_0217EAE0(mem); (mem) = 0; }

GPResult func_0219091C(GPConnection *connection, GPIOperation *operation)
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

    if (!operation->blocking && (func_0217F264() - data->searchStartTime > GPI_SEARCH_TIMEOUT))
    {
        data->remove = GPITrue;
        CallbackError(connection, GP_NETWORK_ERROR, GP_SEARCH_TIMED_OUT, g_02191848);
    }

    do
    {
        CHECK_RESULT(func_0218998C(connection, data->sock, &data->outputBuffer, &connClosed, GPITrue, g_0219184C));

        if (operation->state == GPI_CONNECTING)
        {
            CHECK_RESULT(func_02193488(connection, data->sock, &state));

            if (state == GPI_DISCONNECTED)
                CallbackError(connection, GP_SERVER_ERROR, GPI_SEARCH_CONNECTION_FAILED, g_02191850);

            if (state == GPI_CONNECTED)
            {
                if (data->type == GPI_SEARCH_PROFILE)
                {
                    func_0218946C(connection, &data->outputBuffer, g_02191854);
                    func_0218946C(connection, &data->outputBuffer, g_02191858);
                    func_0218949C(connection, &data->outputBuffer, iconnection->sessKey);
                    func_0218946C(connection, &data->outputBuffer, g_0219185C);
                    func_0218949C(connection, &data->outputBuffer, iconnection->profileid);
                    func_0218946C(connection, &data->outputBuffer, g_02191860);
                    func_0218949C(connection, &data->outputBuffer, iconnection->namespaceID);
                    func_0218946C(connection, &data->outputBuffer, g_02191864);
                    func_0218949C(connection, &data->outputBuffer, iconnection->partnerID);
                    if (data->nick[0] != '\0')
                    {
                        func_0218946C(connection, &data->outputBuffer, g_02191868);
                        func_0218946C(connection, &data->outputBuffer, data->nick);
                    }
                    if (data->uniquenick[0] != '\0')
                    {
                        func_0218946C(connection, &data->outputBuffer, g_0219186C);
                        func_0218946C(connection, &data->outputBuffer, data->uniquenick);
                    }
                    if (data->email[0] != '\0')
                    {
                        func_0218946C(connection, &data->outputBuffer, g_02191870);
                        func_0218946C(connection, &data->outputBuffer, data->email);
                    }
                    if (data->firstname[0] != '\0')
                    {
                        func_0218946C(connection, &data->outputBuffer, g_02191874);
                        func_0218946C(connection, &data->outputBuffer, data->firstname);
                    }
                    if (data->lastname[0] != '\0')
                    {
                        func_0218946C(connection, &data->outputBuffer, g_02191878);
                        func_0218946C(connection, &data->outputBuffer, data->lastname);
                    }
                    if (data->icquin != 0)
                    {
                        func_0218946C(connection, &data->outputBuffer, g_0219187C);
                        func_0218949C(connection, &data->outputBuffer, data->icquin);
                    }
                    if (data->skip > 0)
                    {
                        func_0218946C(connection, &data->outputBuffer, g_02191880);
                        func_0218949C(connection, &data->outputBuffer, data->skip);
                    }
                }
                else if (data->type == GPI_SEARCH_PROFILE_UNIQUENICK)
                {
                    int i;
                    func_0218946C(connection, &data->outputBuffer, g_02191884);
                    func_0218946C(connection, &data->outputBuffer, g_02191858);
                    func_0218949C(connection, &data->outputBuffer, iconnection->sessKey);
                    func_0218946C(connection, &data->outputBuffer, g_0219185C);
                    func_0218949C(connection, &data->outputBuffer, iconnection->profileid);
                    func_0218946C(connection, &data->outputBuffer, g_0219186C);
                    func_0218946C(connection, &data->outputBuffer, data->uniquenick);
                    func_0218946C(connection, &data->outputBuffer, g_02191888);
                    if (data->numNamespaces > 0)
                    {
                        for (i = 0; i < data->numNamespaces; i++)
                        {
                            if (i > 0)
                                func_0218934C(connection, &data->outputBuffer, ',');
                            func_0218949C(connection, &data->outputBuffer, data->namespaceIDs[i]);
                        }
                    }
                    else
                    {
                        func_0218949C(connection, &data->outputBuffer, iconnection->namespaceID);
                    }
                }
                else if (data->type == GPI_SEARCH_IS_VALID)
                {
                    func_0218946C(connection, &data->outputBuffer, g_0219188C);
                    func_0218946C(connection, &data->outputBuffer, g_02191870);
                    func_0218946C(connection, &data->outputBuffer, data->email);
                    func_0218946C(connection, &data->outputBuffer, g_02191864);
                    func_0218949C(connection, &data->outputBuffer, iconnection->partnerID);
                }
                else if (data->type == GPI_SEARCH_NICKS)
                {
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
                else if (data->type == GPI_SEARCH_PLAYERS)
                {
                    func_0218946C(connection, &data->outputBuffer, g_02191898);
                    func_0218946C(connection, &data->outputBuffer, g_02191858);
                    func_0218949C(connection, &data->outputBuffer, iconnection->sessKey);
                    func_0218946C(connection, &data->outputBuffer, g_0219185C);
                    func_0218949C(connection, &data->outputBuffer, iconnection->profileid);
                    func_0218946C(connection, &data->outputBuffer, g_0219189C);
                    func_0218949C(connection, &data->outputBuffer, data->productID);
                }
                else if (data->type == GPI_SEARCH_CHECK)
                {
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
                else if (data->type == GPI_SEARCH_NEWUSER)
                {
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
                    if (data->cdkey[0])
                    {
                        func_0218946C(connection, &data->outputBuffer, g_021918AC);
                        func_0218946C(connection, &data->outputBuffer, data->cdkey);
                    }
                    func_0218946C(connection, &data->outputBuffer, g_02191864);
                    func_0218949C(connection, &data->outputBuffer, iconnection->partnerID);
                }
                else if (data->type == GPI_SEARCH_OTHERS_BUDDY)
                {
                    func_0218946C(connection, &data->outputBuffer, g_021918B0);
                    func_0218946C(connection, &data->outputBuffer, g_02191858);
                    func_0218949C(connection, &data->outputBuffer, iconnection->sessKey);
                    func_0218946C(connection, &data->outputBuffer, g_0219185C);
                    func_0218949C(connection, &data->outputBuffer, iconnection->profileid);
                    func_0218946C(connection, &data->outputBuffer, g_02191860);
                    func_0218949C(connection, &data->outputBuffer, iconnection->namespaceID);
                }
                else if (data->type == GPI_SEARCH_OTHERS_BUDDY_LIST)
                {
                    func_0218946C(connection, &data->outputBuffer, g_021918B4);
                    func_0218946C(connection, &data->outputBuffer, g_02191858);
                    func_0218949C(connection, &data->outputBuffer, iconnection->sessKey);
                    func_0218946C(connection, &data->outputBuffer, g_0219185C);
                    func_0218949C(connection, &data->outputBuffer, iconnection->profileid);
                    func_0218946C(connection, &data->outputBuffer, g_021918B8);
                    func_0218949C(connection, &data->outputBuffer, data->numOfRevBuddyProfiles);
                    func_0218946C(connection, &data->outputBuffer, g_021918BC);
                    if (data->revBuddyProfileIds)
                    {
                        int i;

                        func_0218949C(connection, &data->outputBuffer, data->revBuddyProfileIds[0]);

                        for (i = 1; i < data->numOfRevBuddyProfiles; i++)
                        {
                            func_0218946C(connection, &data->outputBuffer, g_021918C0);
                            func_0218949C(connection, &data->outputBuffer, data->revBuddyProfileIds[i]);
                        }
                    }
                    func_0218946C(connection, &data->outputBuffer, g_02191860);
                    func_0218949C(connection, &data->outputBuffer, iconnection->namespaceID);
                }
                else if (data->type == GPI_SEARCH_SUGGEST_UNIQUE)
                {
                    func_0218946C(connection, &data->outputBuffer, g_021918C4);
                    func_0218946C(connection, &data->outputBuffer, g_021918C8);
                    func_0218946C(connection, &data->outputBuffer, data->uniquenick);
                    func_0218946C(connection, &data->outputBuffer, g_02191860);
                    func_0218949C(connection, &data->outputBuffer, iconnection->namespaceID);
                }
                else if (data->type == GPI_SEARCH_PROFILE_LIST)
                {
                    func_0218946C(connection, &data->outputBuffer, g_021918CC);
                    func_0218946C(connection, &data->outputBuffer, g_02191858);
                    func_0218949C(connection, &data->outputBuffer, iconnection->sessKey);
                    func_0218946C(connection, &data->outputBuffer, g_0219185C);
                    func_0218949C(connection, &data->outputBuffer, iconnection->profileid);
                    func_0218946C(connection, &data->outputBuffer, g_021918D0);
                    func_0218949C(connection, &data->outputBuffer, data->profile);
                    func_0218946C(connection, &data->outputBuffer, g_021918D4);
                    func_0218949C(connection, &data->outputBuffer, data->maxResults);
                }

                func_0218946C(connection, &data->outputBuffer, g_021918D8);
                func_0218946C(connection, &data->outputBuffer, g_021918DC);
                func_0218946C(connection, &data->outputBuffer, g_021918E0);

                operation->state = GPI_WAITING;
            }
        }
        else if (operation->state == GPI_WAITING)
        {
            result = func_02189780(connection, data->sock, &data->inputBuffer, &len, &connClosed, g_0219184C);
            if (result != GP_NO_ERROR)
            {
                if (result == GP_NETWORK_ERROR)
                    CallbackError(connection, GP_NETWORK_ERROR, GPI_SEARCH_CONNECTION_FAILED, g_021918E4);
                return result;
            }
            if (operation->blocking && (func_0217F264() - data->searchStartTime > GPI_SEARCH_TIMEOUT))
            {
                data->remove = GPITrue;
                CallbackError(connection, GP_NETWORK_ERROR, GP_SEARCH_TIMED_OUT, g_02191848);
            }
            if (func_02094B20(data->inputBuffer.buffer, g_021918E0) != 0)
            {
                index = 0;

                operation->state = GPI_FINISHING;

                if (func_0219329C(connection, data->inputBuffer.buffer, GPITrue))
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
                        CHECK_RESULT(func_0219359C(connection, data->inputBuffer.buffer, &index, key, value));

                        if (func_020948E0(key, g_021918EC) == 0)
                        {
                            CHECK_RESULT(func_0219359C(connection, data->inputBuffer.buffer, &index, key, value));
                            if (func_020948E0(key, g_021918F0) == 0)
                            {
                                if (func_020948E0(value, g_021918F4) != 0)
                                    arg.more = GP_MORE;
                            }

                            done = GPITrue;
                        }
                        else if (func_020948E0(key, g_021918F8) == 0)
                        {
                            arg.numMatches++;
                            arg.matches = (GPProfileSearchMatch *)func_0217EAC8(arg.matches, sizeof(GPProfileSearchMatch) * arg.numMatches);
                            if (arg.matches == 0)
                                Error(connection, GP_MEMORY_ERROR, g_021918FC);
                            match = &arg.matches[arg.numMatches - 1];
                            memset(match, 0, sizeof(GPProfileSearchMatch));

                            match->profile = func_020964E0(value);

                            doneParsingMatch = GPIFalse;
                            do
                            {
                                oldIndex = index;
                                CHECK_RESULT(func_0219359C(connection, data->inputBuffer.buffer, &index, key, value));

                                if (func_020948E0(key, g_02191900) == 0)
                                    func_0219327C(match->nick, value, 31);
                                else if (func_020948E0(key, g_02191904) == 0)
                                    func_0219327C(match->uniquenick, value, 21);
                                else if (func_020948E0(key, g_02191908) == 0)
                                    match->namespaceID = func_020964E0(value);
                                else if (func_020948E0(key, g_0219190C) == 0)
                                    func_0219327C(match->firstname, value, 31);
                                else if (func_020948E0(key, g_02191910) == 0)
                                    func_0219327C(match->lastname, value, 31);
                                else if (func_020948E0(key, g_02191914) == 0)
                                    func_0219327C(match->email, value, 51);
                                else if ((func_020948E0(key, g_021918F8) == 0) || (func_020948E0(key, g_021918EC) == 0))
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
                        CHECK_RESULT(func_021906E0(connection, data->nick, data->uniquenick, data->email, data->firstname, data->lastname, data->icquin, arg.numMatches + data->skip, (GPEnum)operation->blocking, operation->callback.callback, operation->callback.param));

                    freeclear(arg.matches);
                }
                else if (data->type == GPI_SEARCH_IS_VALID)
                {
                    callback = operation->callback;
                    if (callback.callback != 0)
                    {
                        GPIsValidEmailResponseArg *arg;

                        CHECK_RESULT(func_0219359C(connection, data->inputBuffer.buffer, &index, key, value));
                        if (func_020948E0(key, g_0219191C) != 0)
                            CallbackFatalError(connection, GP_NETWORK_ERROR, GP_PARSE, g_02191918);

                        arg = (GPIsValidEmailResponseArg *)func_0217EAB0(sizeof(GPIsValidEmailResponseArg));
                        if (arg == 0)
                            Error(connection, GP_MEMORY_ERROR, g_021918FC);
                        arg->result = GP_NO_ERROR;
                        func_0219327C(arg->email, data->email, 51);
                        if (value[0] == '0')
                            arg->isValid = GP_INVALID;
                        else
                            arg->isValid = GP_VALID;

                        CHECK_RESULT(func_02189DFC(connection, callback, arg, operation, 0));
                    }
                }
                else if (data->type == GPI_SEARCH_NICKS)
                {
                    callback = operation->callback;
                    if (callback.callback != 0)
                    {
                        GPGetUserNicksResponseArg *arg;

                        arg = (GPGetUserNicksResponseArg *)func_0217EAB0(sizeof(GPGetUserNicksResponseArg));
                        if (arg == 0)
                            Error(connection, GP_MEMORY_ERROR, g_021918FC);
                        arg->result = GP_NO_ERROR;
                        func_021803BC(arg->email, data->email, 51);
                        arg->numNicks = 0;
                        arg->nicks = 0;
                        arg->uniquenicks = 0;

                        CHECK_RESULT(func_0219359C(connection, data->inputBuffer.buffer, &index, key, value));
                        if (func_020948E0(key, g_02192A94) != 0)
                            CallbackFatalError(connection, GP_NETWORK_ERROR, GP_PARSE, g_02191918);

                        done = GPIFalse;
                        do
                        {
                            CHECK_RESULT(func_0219359C(connection, data->inputBuffer.buffer, &index, key, value));
                            if (func_020948E0(key, g_02191900) == 0)
                            {
                                tempPtr = func_0217EAC8(arg->nicks, sizeof(char *) * (arg->numNicks + 1));
                                if (tempPtr == 0)
                                    Error(connection, GP_MEMORY_ERROR, g_021918FC);
                                arg->nicks = (char **)tempPtr;
                                tempPtr = func_0217EAB0(31);
                                if (tempPtr == 0)
                                    Error(connection, GP_MEMORY_ERROR, g_021918FC);
                                arg->nicks[arg->numNicks] = (char *)tempPtr;
                                func_0219327C(arg->nicks[arg->numNicks], value, 31);
                                arg->numNicks++;
                            }
                            else if (func_020948E0(key, g_02191904) == 0)
                            {
                                if (arg->numNicks <= 0)
                                    continue;

                                tempPtr = func_0217EAC8(arg->uniquenicks, sizeof(char *) * arg->numNicks);
                                if (tempPtr == 0)
                                    Error(connection, GP_MEMORY_ERROR, g_021918FC);
                                arg->uniquenicks = (char **)tempPtr;
                                tempPtr = func_0217EAB0(21);
                                if (tempPtr == 0)
                                    Error(connection, GP_MEMORY_ERROR, g_021918FC);
                                arg->uniquenicks[arg->numNicks - 1] = (char *)tempPtr;
                                func_0219327C(arg->uniquenicks[arg->numNicks - 1], value, 21);
                            }
                            else if (func_020948E0(key, g_02192A98) == 0)
                            {
                                done = GPITrue;
                            }
                            else
                            {
                                CallbackFatalError(connection, GP_NETWORK_ERROR, GP_PARSE, g_02191918);
                            }
                        }
                        while (!done);

                        CHECK_RESULT(func_02189DFC(connection, callback, arg, operation, GPI_ADD_NICKS));
                    }
                }
                else if (data->type == GPI_SEARCH_PLAYERS)
                {
                    callback = operation->callback;
                    if (callback.callback != 0)
                    {
                        GPFindPlayersResponseArg *arg;
                        GPFindPlayerMatch *match;

                        arg = (GPFindPlayersResponseArg *)func_0217EAB0(sizeof(GPFindPlayersResponseArg));
                        if (arg == 0)
                            Error(connection, GP_MEMORY_ERROR, g_021918FC);
                        arg->productID = data->productID;
                        arg->result = GP_NO_ERROR;
                        arg->numMatches = 0;
                        arg->matches = 0;

                        done = GPIFalse;
                        do
                        {
                            CHECK_RESULT(func_0219359C(connection, data->inputBuffer.buffer, &index, key, value));

                            if (func_020948E0(key, g_02192A9C) == 0)
                            {
                                done = GPITrue;
                            }
                            else if (func_020948E0(key, g_02192AA0) == 0)
                            {
                                arg->numMatches++;
                                arg->matches = (GPFindPlayerMatch *)func_0217EAC8(arg->matches, sizeof(GPFindPlayerMatch) * arg->numMatches);
                                if (arg->matches == 0)
                                    Error(connection, GP_MEMORY_ERROR, g_021918FC);
                                match = &arg->matches[arg->numMatches - 1];
                                memset(match, 0, sizeof(GPFindPlayerMatch));
                                match->status = GP_ONLINE;

                                match->profile = func_020964E0(value);

                                doneParsingMatch = GPIFalse;
                                do
                                {
                                    oldIndex = index;
                                    CHECK_RESULT(func_0219359C(connection, data->inputBuffer.buffer, &index, key, value));

                                    if (func_020948E0(key, g_02192AA4) == 0)
                                        func_0219327C(match->statusString, value, 256);
                                    else if (func_020948E0(key, g_02191900) == 0)
                                        func_0219327C(match->nick, value, 31);
                                    if (func_020948E0(key, g_02192AA8) == 0)
                                        match->status = (GPEnum)func_020964E0(value);
                                    else if ((func_020948E0(key, g_02192AA0) == 0) || (func_020948E0(key, g_02192A9C) == 0))
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

                        CHECK_RESULT(func_02189DFC(connection, callback, arg, operation, GPI_ADD_PMATCH));
                    }
                }
                else if (data->type == GPI_SEARCH_CHECK)
                {
                    callback = operation->callback;
                    if (callback.callback != 0)
                    {
                        GPCheckResponseArg *arg;

                        CHECK_RESULT(func_0219359C(connection, data->inputBuffer.buffer, &index, key, value));
                        if (func_020948E0(key, g_02192AAC) != 0)
                            CallbackFatalError(connection, GP_NETWORK_ERROR, GP_PARSE, g_02191918);

                        rcode = func_020964E0(value);
                        if (rcode)
                        {
                            iconnection->errorCode = (GPErrorCode)rcode;
                            pid = 0;
                        }
                        else
                        {
                            if (!func_02193418(data->inputBuffer.buffer, g_02192AB0, value, sizeof(value)))
                                CallbackFatalError(connection, GP_NETWORK_ERROR, GP_PARSE, g_02191918);
                            pid = func_020964E0(value);
                        }

                        arg = (GPCheckResponseArg *)func_0217EAB0(sizeof(GPCheckResponseArg));
                        if (arg == 0)
                            Error(connection, GP_MEMORY_ERROR, g_021918FC);
                        arg->result = (GPResult)rcode;
                        arg->profile = pid;

                        CHECK_RESULT(func_02189DFC(connection, callback, arg, operation, 0));
                    }
                }
                else if (data->type == GPI_SEARCH_NEWUSER)
                {
                    callback = operation->callback;
                    if (callback.callback != 0)
                    {
                        GPNewUserResponseArg *arg;

                        CHECK_RESULT(func_0219359C(connection, data->inputBuffer.buffer, &index, key, value));
                        if (func_020948E0(key, g_02192AB4) != 0)
                            CallbackFatalError(connection, GP_NETWORK_ERROR, GP_PARSE, g_02191918);

                        rcode = func_020964E0(value);
                        if (rcode)
                            iconnection->errorCode = (GPErrorCode)rcode;
                        if (!func_02193418(data->inputBuffer.buffer, g_02192AB0, value, sizeof(value)))
                        {
                            if (rcode == 0)
                                CallbackFatalError(connection, GP_NETWORK_ERROR, GP_PARSE, g_02191918);
                            pid = 0;
                        }
                        else
                            pid = func_020964E0(value);

                        arg = (GPNewUserResponseArg *)func_0217EAB0(sizeof(GPNewUserResponseArg));
                        if (arg == 0)
                            Error(connection, GP_MEMORY_ERROR, g_021918FC);
                        arg->result = (GPResult)rcode;
                        arg->profile = pid;

                        CHECK_RESULT(func_02189DFC(connection, callback, arg, operation, 0));
                    }
                }
                else if (data->type == GPI_SEARCH_OTHERS_BUDDY)
                {
                    callback = operation->callback;
                    if (callback.callback != 0)
                    {
                        GPGetReverseBuddiesResponseArg *arg;

                        arg = (GPGetReverseBuddiesResponseArg *)func_0217EAB0(sizeof(GPGetReverseBuddiesResponseArg));
                        if (arg == 0)
                            Error(connection, GP_MEMORY_ERROR, g_021918FC);
                        arg->result = GP_NO_ERROR;
                        arg->numProfiles = 0;
                        arg->profiles = 0;

                        CHECK_RESULT(func_0219359C(connection, data->inputBuffer.buffer, &index, key, value));
                        if (func_020948E0(key, g_02192AB8) != 0)
                            CallbackFatalError(connection, GP_NETWORK_ERROR, GP_PARSE, g_02191918);

                        done = GPIFalse;
                        do
                        {
                            CHECK_RESULT(func_0219359C(connection, data->inputBuffer.buffer, &index, key, value));

                            if (func_020948E0(key, g_02192ABC) == 0)
                            {
                                done = GPITrue;
                            }
                            else if (func_020948E0(key, g_02192AC0) == 0)
                            {
                                tempPtr = func_0217EAC8(arg->profiles, sizeof(GPProfileSearchMatch) * (arg->numProfiles + 1));
                                if (tempPtr == 0)
                                    Error(connection, GP_MEMORY_ERROR, g_021918FC);
                                arg->profiles = (GPProfileSearchMatch *)tempPtr;
                                match = &arg->profiles[arg->numProfiles];
                                memset(match, 0, sizeof(GPProfileSearchMatch));
                                arg->numProfiles++;

                                match->profile = func_020964E0(value);

                                doneParsingMatch = GPIFalse;
                                do
                                {
                                    oldIndex = index;
                                    CHECK_RESULT(func_0219359C(connection, data->inputBuffer.buffer, &index, key, value));

                                    if (func_020948E0(key, g_02191900) == 0)
                                        func_0219327C(match->nick, value, 31);
                                    else if (func_020948E0(key, g_02191904) == 0)
                                        func_0219327C(match->uniquenick, value, 21);
                                    else if (func_020948E0(key, g_02192AC4) == 0)
                                        func_0219327C(match->firstname, value, 31);
                                    else if (func_020948E0(key, g_02192AC8) == 0)
                                        func_0219327C(match->lastname, value, 31);
                                    else if (func_020948E0(key, g_02191914) == 0)
                                        func_0219327C(match->email, value, 51);
                                    else if ((func_020948E0(key, g_02192AC0) == 0) || (func_020948E0(key, g_02192ABC) == 0))
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

                        CHECK_RESULT(func_02189DFC(connection, callback, arg, operation, GPI_ADD_REVERSE_BUDDIES));
                    }
                }
                else if (data->type == GPI_SEARCH_OTHERS_BUDDY_LIST)
                {
                    callback = operation->callback;
                    if (callback.callback != 0)
                    {
                        GPGetReverseBuddiesListResponseArg *arg;

                        arg = (GPGetReverseBuddiesListResponseArg *)func_0217EAB0(sizeof(GPGetReverseBuddiesListResponseArg));
                        if (arg == 0)
                            Error(connection, GP_MEMORY_ERROR, g_021918FC);
                        arg->result = GP_NO_ERROR;
                        arg->numOfUniqueMatchs = 0;
                        arg->matches = 0;

                        CHECK_RESULT(func_0219359C(connection, data->inputBuffer.buffer, &index, key, value));
                        if (func_020948E0(key, g_02192ACC) != 0)
                            CallbackFatalError(connection, GP_NETWORK_ERROR, GP_PARSE, g_02191918);

                        done = GPIFalse;
                        do
                        {
                            CHECK_RESULT(func_0219359C(connection, data->inputBuffer.buffer, &index, key, value));

                            if (func_020948E0(key, g_02192AD0) == 0)
                            {
                                done = GPITrue;
                            }
                            else if (func_020948E0(key, g_02192AC0) == 0)
                            {
                                tempPtr = func_0217EAC8(arg->matches, sizeof(GPUniqueMatch) * (arg->numOfUniqueMatchs + 1));
                                if (tempPtr == 0)
                                    Error(connection, GP_MEMORY_ERROR, g_021918FC);
                                arg->matches = (GPUniqueMatch *)tempPtr;
                                uniqueNickMatch = &arg->matches[arg->numOfUniqueMatchs];
                                {
                                    unsigned char *d = (unsigned char *)uniqueNickMatch;
                                    unsigned int n = sizeof(GPUniqueMatch) / 4;
                                    do {
                                        d[0] = 0; d[1] = 0; d[2] = 0; d[3] = 0;
                                        d += 4;
                                    } while (--n);
                                }
                                arg->numOfUniqueMatchs++;

                                uniqueNickMatch->profile = func_020964E0(value);

                                doneParsingMatch = GPIFalse;
                                do
                                {
                                    oldIndex = index;
                                    CHECK_RESULT(func_0219359C(connection, data->inputBuffer.buffer, &index, key, value));

                                    if (func_020948E0(key, g_02191904) == 0)
                                        func_0219327C(uniqueNickMatch->uniqueNick, value, 21);
                                    else if ((func_020948E0(key, g_02192AC0) == 0) || (func_020948E0(key, g_02192AD0) == 0))
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

                        CHECK_RESULT(func_02189DFC(connection, callback, arg, operation, GPI_ADD_REVERSE_BUDDIES_LIST));
                    }
                }
                else if (data->type == GPI_SEARCH_SUGGEST_UNIQUE)
                {
                    callback = operation->callback;
                    if (callback.callback != 0)
                    {
                        int count = 0;
                        GPSuggestUniqueNickResponseArg *arg;

                        arg = (GPSuggestUniqueNickResponseArg *)func_0217EAB0(sizeof(GPSuggestUniqueNickResponseArg));
                        if (arg == 0)
                            Error(connection, GP_MEMORY_ERROR, g_021918FC);
                        arg->result = GP_NO_ERROR;
                        arg->numSuggestedNicks = 0;
                        arg->suggestedNicks = 0;

                        CHECK_RESULT(func_0219359C(connection, data->inputBuffer.buffer, &index, key, value));
                        if (func_020948E0(key, g_02192AE0) != 0)
                            CallbackFatalError(connection, GP_NETWORK_ERROR, GP_PARSE, g_02191918);
                        arg->numSuggestedNicks = func_020964E0(value);

                        arg->suggestedNicks = (char **)func_0217EAB0(sizeof(char *) * arg->numSuggestedNicks);
                        if (!arg->suggestedNicks)
                            Error(connection, GP_MEMORY_ERROR, g_021918FC);

                        done = GPIFalse;
                        do
                        {
                            CHECK_RESULT(func_0219359C(connection, data->inputBuffer.buffer, &index, key, value));
                            if (func_020948E0(key, g_02191900) == 0)
                            {
                                arg->suggestedNicks[count] = func_0217EAB0(21);
                                if (arg->suggestedNicks[count] == 0)
                                    Error(connection, GP_MEMORY_ERROR, g_021918FC);
                                func_0219327C(arg->suggestedNicks[count], value, 21);
                                count++;
                            }
                            else if (func_020948E0(key, g_02192DFC) == 0)
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

                        CHECK_RESULT(func_02189DFC(connection, callback, arg, operation, GPI_ADD_SUGGESTED_UNIQUE));
                    }
                }
                else if (data->type == GPI_SEARCH_PROFILE_LIST)
                {
                    callback = operation->callback;
                    if (callback.callback != 0)
                    {
                        GPProfileListResponseArg *arg;

                        arg = (GPProfileListResponseArg *)func_0217EAB0(sizeof(GPProfileListResponseArg));
                        if (arg == 0)
                            Error(connection, GP_MEMORY_ERROR, g_021918FC);
                        arg->result = GP_NO_ERROR;
                        arg->numMatches = 0;
                        arg->matches = 0;
                        arg->hidden = 0;
                        arg->profile = data->profile;

                        CHECK_RESULT(func_0219359C(connection, data->inputBuffer.buffer, &index, key, value));
                        if (func_020948E0(key, g_02192E00) != 0)
                            CallbackFatalError(connection, GP_NETWORK_ERROR, GP_PARSE, g_02191918);

                        done = GPIFalse;
                        do
                        {
                            CHECK_RESULT(func_0219359C(connection, data->inputBuffer.buffer, &index, key, value));
                            if (func_020948E0(key, g_02192E04) == 0)
                            {
                                done = GPITrue;
                            }
                            else if (func_020948E0(key, g_02192E08) == 0)
                            {
                                arg->hidden = 1;
                                done = GPITrue;
                            }
                            else if (func_020948E0(key, g_02192E0C) == 0)
                            {
                                int count = func_020964E0(value);
                                if (count > 0)
                                {
                                    tempPtr = func_0217EAB0(sizeof(int) * count);
                                    if (tempPtr == 0)
                                        Error(connection, GP_MEMORY_ERROR, g_021918FC);
                                    arg->matches = (int *)tempPtr;
                                }
                            }
                            else if (func_020948E0(key, g_02192AC0) == 0)
                            {
                                arg->matches[arg->numMatches] = func_020964E0(value);
                                arg->numMatches++;
                            }
                            else
                            {
                                CallbackFatalError(connection, GP_NETWORK_ERROR, GP_PARSE, g_02191918);
                            }
                        }
                        while (!done);

                        CHECK_RESULT(func_02189DFC(connection, callback, arg, operation, GPI_ADD_PROFILE_LIST));
                    }
                }

                data->remove = GPITrue;

                loop = GPIFalse;
            }
        }
        if (loop)
            func_0217F2BC(10);
    } while (loop);

    return GP_NO_ERROR;
}
