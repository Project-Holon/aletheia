/*
 * function: func_021903B0
 * address:  0x021903B0
 * packet:   pkt_ov009_021903B0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiStartProfileSearch (libdwcgsgp.TWL.HYB.a gpisearch.o)
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
 */

typedef struct GPIBuffer {
    char *buffer;
    int size;
    int len;
    int pos;
} GPIBuffer;

typedef struct GPISearchData {
    int type;                        /* 0x000 */
    int sock;                        /* 0x004 */
    GPIBuffer inputBuffer;           /* 0x008 */
    GPIBuffer outputBuffer;          /* 0x018 */
    char pad028[0x164];
    unsigned int searchStartTime;    /* 0x18C */
} GPISearchData;

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

extern char g_021A5280[];
extern char g_021A5290[];
extern char g_021A52B8[];
extern char g_021A5240[];
extern char g_021A52EC[];
extern char g_021A531C[];

extern void *func_0217EAB0(unsigned long size);
extern void func_02193734(int *p, int b);
extern int func_0217EB18(int pf, int type, int protocol);
extern void func_02193710(int *connection, int result, int errorString);
extern int func_02189D78(int *connection, int a1, int a2);
extern int func_0217EE50(int sock, int isblocking);
extern struct SOCHostEnt *func_0215F650(char *name);
extern int func_0217EC08(int sock, void *addr, int len);
extern int func_0217ED54();
extern unsigned int func_0217F264(void);

int func_021903B0(void **connection, GPIOperation *operation)
{
    GPISearchData *data;
    int rcode;
    struct SOCHostEnt *host;
    int error;

    data = (GPISearchData *)operation->data;

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
