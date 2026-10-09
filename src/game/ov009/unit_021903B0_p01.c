/*
 * file:     unit_021903B0_p01.c
 * unit:     yes
 * function: func_021903B0, func_021905A4, func_02190650, func_021906E0
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
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_02193734  0x02193734  arm  ov009
 *   func_0217EB18  0x0217EB18  arm  ov009
 *   func_02193710  0x02193710  arm  ov009
 *   func_02189D78  0x02189D78  arm  ov009
 *   func_0217EE50  0x0217EE50  arm  ov009
 *   func_0215F650  0x0215F650  arm  ov009
 *   func_0217EC08  0x0217EC08  arm  ov009
 *   func_0217ED54  0x0217ED54  arm  ov009
 *   func_0217F264  0x0217F264  arm  ov009
 *   g_021A5280     0x021A5280  data
 *   g_021A5290     0x021A5290  data
 *   g_021A52B8     0x021A52B8  data
 *   g_021A5240     0x021A5240  data
 *   g_021A52EC     0x021A52EC  data
 *   g_021A531C     0x021A531C  data
 *   func_020923B0  0x020923B0  arm
 *   func_0219327C  0x0219327C  arm  ov009
 *   func_0217F21C  0x0217F21C  arm  ov009
 *   g_021A5344     0x021A5344  data ov009
 */
struct GPIOperation_s;
typedef struct GPIBuffer_021903B0 {
    char *buffer;
    int size;
    int len;
    int pos;
} GPIBuffer_021903B0;

typedef struct GPISearchData_021903B0 {
    int type;                        /* 0x000 */
    int sock;                        /* 0x004 */
    GPIBuffer_021903B0 inputBuffer;           /* 0x008 */
    GPIBuffer_021903B0 outputBuffer;          /* 0x018 */
    char pad028[0x164];
    unsigned int searchStartTime;    /* 0x18C */
} GPISearchData_021903B0;

typedef struct GPIOperation_s {
    int type;                        /* 0x00 */
    void *data;                      /* 0x04 */
    int blocking;                    /* 0x08 */
    void *callback[2];               /* 0x0C */
    int state;                       /* 0x14 */
    int id;                          /* 0x18 */
    int result;                      /* 0x1C */
    struct GPIOperation_s *pnext;    /* 0x20 */
} GPIOperation;

struct SOCHostEnt {
    char *name;
    char **aliases;
    short addrType;
    short length;
    unsigned char **addrList;
};

struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned int addr;
};

typedef struct {
    char *data;
    int size;
    int len;
} GPIBuffer_021905A4;

typedef struct {
    int type;
    int sock;
    GPIBuffer_021905A4 inputBuffer;
    int unk14;
    GPIBuffer_021905A4 outputBuffer;
    int unk24;
    char pad[0x15c];
    int processing;
    int remove;
    int searchStartTime;
    int revBuddyProfileIds;
    int numOfRevBuddyProfiles;
    int unk198;
    int unk19c;
} GPISearchData_021905A4;

typedef unsigned int   u32;

typedef struct {
    char *buffer;
    int size;
    int len;
    int pos;
} GPIBuffer;

typedef struct {
    int type;
    int sock;
    GPIBuffer inputBuffer;
    GPIBuffer outputBuffer;
    char nick[0x1f];
    char uniquenick[0x59];
    char email[0x33];
    char firstname[0x1f];
    char lastname[0x86];
    int icquin;
    int skip;
} GPISearchData;

extern void *func_0217EAB0(unsigned long size);
extern void func_02193734(int *p, int b);
extern int func_0217EB18(int pf, int type, int protocol);
extern void func_02193710(int *connection, int result, int errorString);
extern int func_02189D78(int *connection, int a1, int a2);
extern int func_0217EE50(int sock, int isblocking);
extern struct SOCHostEnt *func_0215F650(char *name);
extern int func_0217EC08(int sock, void *addr, int len);
extern int func_0217ED54(int sock);
extern unsigned int func_0217F264(void);
extern void *func_020923B0(void *p, int c, u32 n);
extern int func_0218E114(void *a, int b, int c, void **pp, int d, int e, int f);
extern int func_02186E9C(void *a, int x);
extern void func_0219327C(char *p, int b, int n);
extern char *func_0217F21C(char *s);
int func_021903B0(void **connection, GPIOperation *operation);
int func_021905A4(int connection, GPISearchData_021905A4 **out, int type);
int func_02190650(void *a, int a1, int a2, int a3, int a4);
int func_021906E0(int *connection, char *nick, char *uniquenick, char *email, char *firstname, char *lastname, int icquin, int skip, int blocking, int callback, int param);
extern char g_021A5280[];
extern char g_021A5290[];
extern char g_021A52B8[];
extern char g_021A5240[];
extern char g_021A52EC[];
extern char g_021A531C[];
extern char g_021A5344[];



/*
 * sdk:      gpiStartProfileSearch (libdwcgsgp.TWL.HYB.a gpisearch.o)
 */
int func_021903B0(void **connection, GPIOperation *operation)
{
    GPISearchData_021903B0 *data;
    int rcode;
    struct SOCHostEnt *host;
    int error;

    data = (GPISearchData_021903B0 *)operation->data;

    data->inputBuffer.size = 4096;
    data->inputBuffer.buffer = (char *)func_0217EAB0(data->inputBuffer.size + 1);
    if (data->inputBuffer.buffer == 0) {
        func_02193734((int *)connection, (int)g_021A5280);
        return 1;
    }

    data->sock = func_0217EB18(2, 1, 0);
    if (data->sock == -1) {
        func_02193710((int *)connection, 5, (int)g_021A5290);
        func_02189D78((int *)connection, 3, 1);
        return 3;
    }

    if (!func_0217EE50(data->sock, 0)) {
        func_02193710((int *)connection, 5, (int)g_021A52B8);
        func_02189D78((int *)connection, 3, 1);
        return 3;
    }

    host = func_0215F650(g_021A5240);
    if (host == 0) {
        func_02193710((int *)connection, 5, (int)g_021A52EC);
        func_02189D78((int *)connection, 3, 1);
        return 3;
    }

    {
        struct SOCSockAddrIn address = {0};

        address.family = 2;
        address.addr = **(unsigned int **)host->addrList;
        address.port = 0xCD74;

        rcode = func_0217EC08(data->sock, &address, sizeof(address));
    }
    if (rcode == -1) {
        error = func_0217ED54(data->sock);
        if (error != -6 && error != -26 && error != -76) {
            func_02193710((int *)connection, 5, (int)g_021A531C);
            func_02189D78((int *)connection, 3, 1);
            return 3;
        }
    }

    operation->state = 1;
    data->searchStartTime = func_0217F264();
    return 0;
}



/*
 * gpiCreateSearchData-alike: allocate a 0x1a0-byte GPISearchData, clear it,
 * default the socket to -1 and the type to the caller's, hand the caller a
 * 0x1001-byte output buffer (size field 0x1000), and publish the object
 * through *out.  Returns 1 (and sets the "Out of memory" error string) when
 * either allocation fails, else 0.
 */
int func_021905A4(int connection, GPISearchData_021905A4 **out, int type)
{
    GPISearchData_021905A4 *data = func_0217EAB0(0x1a0);

    if (data == 0) {
        func_02193734((int *)connection, (int)g_021A5280);
        return 1;
    }
    func_020923B0(data, 0, 0x1a0);
    data->type = type;
    data->sock = -1;
    data->inputBuffer.data = 0;
    data->inputBuffer.len = 0;
    data->unk14 = 0;
    data->inputBuffer.size = 0;
    data->outputBuffer.len = 0;
    data->unk24 = 0;
    data->outputBuffer.size = 0x1000;
    data->outputBuffer.data = func_0217EAB0(0x1001);
    if (data->outputBuffer.data == 0) {
        func_02193734((int *)connection, (int)g_021A5280);
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
int func_02190650(void *a, int a1, int a2, int a3, int a4)
{
    char *q;
    void *v;
    int r;

    q = *(char **)a;
    *(int *)(q + 0x238) += 1;

    r = func_0218E114(a, 3, a1, &v, a2, a3, a4);
    if (r != 0)
        return r;
    r = func_021903B0(a, v);
    if (r != 0)
        return r;

    if (*(int *)((char *)v + 8) != 0) {
        r = func_02186E9C(a, *(int *)((char *)v + 0x18));
        if (r != 0)
            return r;
    }
    return 0;
}


int func_021906E0(int *connection, char *nick, char *uniquenick, char *email,
                  char *firstname, char *lastname, int icquin, int skip,
                  int blocking, int callback, int param)
{
    GPISearchData *data;
    int result;

    if ((nick == 0) || (*nick == 0))
        if ((email == 0) || (*email == 0))
            if ((firstname == 0) || (*firstname == 0))
                if ((lastname == 0) || (*lastname == 0))
                    if (icquin == 0)
                        if ((uniquenick == 0) || (*uniquenick == 0)) {
                            func_02193734(connection, (int)g_021A5344);
                            return 2;
                        }

    result = func_021905A4((int)connection, (GPISearchData_021905A4 * *)&data, 1);
    if (result != 0)
        return result;

    if (nick == 0)
        data->nick[0] = 0;
    else
        func_0219327C(data->nick, (int)nick, 0x1f);
    if (uniquenick == 0)
        data->uniquenick[0] = 0;
    else
        func_0219327C(data->uniquenick, (int)uniquenick, 0x15);
    if (email == 0)
        data->email[0] = 0;
    else
        func_0219327C(data->email, (int)email, 0x33);
    func_0217F21C(data->email);
    if (firstname == 0)
        data->firstname[0] = 0;
    else
        func_0219327C(data->firstname, (int)firstname, 0x1f);
    if (lastname == 0)
        data->lastname[0] = 0;
    else
        func_0219327C(data->lastname, (int)lastname, 0x1f);

    data->icquin = icquin;
    if (skip < 0)
        skip = 0;
    data->skip = skip;

    result = func_02190650(connection, (int)data, blocking, callback, param);
    if (result != 0)
        return result;
    return 0;
}
