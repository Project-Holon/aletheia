/*
 * file:     unit_021BA020.c
 * unit:     yes
 * function: func_021BA020, func_021BA068, func_021BA098
 * address:  0x021BA020
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BA014 0x021BA014 arm ov114
 *   func_021BEFCC  0x021BEFCC  arm  ov114
 *   func_021BEFD8  0x021BEFD8  arm  ov114
 *   SOC_InetAtoN 0x0215FAD0 arm
 *   SOC_GetHostByName 0x0215F650 arm
 *   func_021BA100 0x021BA100 arm ov114
 *   SOC_Shutdown  0x0215F638  arm  ov009
 */
typedef struct {
    int doCancel;
} Req;

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct {
    char pad[0xa];
    short h_length;
    char **h_addr_list;
} SOCHostEnt;

typedef struct {
    unsigned long addr;
} SOCInAddr;

extern int func_021BA014(int socket, char *buf_p, int len, int flags);
extern void func_021BEFCC(void);
extern void func_021BEFD8(int);
extern void SOC_Shutdown(int, int);
extern int SOC_InetAtoN(char *cp, SOCInAddr *inp);
extern SOCHostEnt *SOC_GetHostByName(char *name);
extern void func_021BA100(void *dst_p, void *src_p, int size);
int func_021BA020(Req *req_p, int socket, char *buf_p, int len, int flags);
void func_021BA068(int a, int b, int c);
unsigned long func_021BA098(int unused, char *hostname_p);


int func_021BA020(Req *req_p, int socket, char *buf_p, int len, int flags)
{
    int error;

    error = func_021BA014(socket, buf_p, len, flags);
    if (error < 0) {
        if (req_p->doCancel != 0) {
            return -1002;
        }
        if (error == -56) {
            return 0;
        }
        return -1001;
    }
    return error;
}


void func_021BA068(int a, int b, int c)
{
    func_021BEFCC();
    if (c >= 0)
        SOC_Shutdown(c, 2);
    func_021BEFD8(a);
}


unsigned long func_021BA098(int unused, char *hostname_p)
{
    SOCHostEnt *hostEnt;
    unsigned long addr = 0;
    SOCInAddr inAddr;

    if (SOC_InetAtoN(hostname_p, &inAddr)) {
        addr = inAddr.addr;
    } else {
        hostEnt = SOC_GetHostByName(hostname_p);
        if (hostEnt && hostEnt->h_length > 0) {
            func_021BA100(&addr, *hostEnt->h_addr_list, 4);
        }
    }
    return addr;
}
