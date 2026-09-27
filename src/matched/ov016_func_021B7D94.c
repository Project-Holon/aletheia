/*
 * function: SendPacketUDP
 * address:  0x021B7D94
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   aoss_bss     0x021DC040  data
 *   AOSS_Memset  0x021B8240  thumb
 *   AOSS_Htons   0x021B830C  thumb
 *   AOSS_Htonl   0x021B82E4  thumb
 *   AOSS_Sendto  0x021B82B4  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol SendPacketUDP (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B7D94.c \
 *       --func SendPacketUDP --addr 0x021B7D94 --region ov016 --cc ../2.0/sp1p2 --thumb
 */

/*
 * aoss.o's main .bss section (3424 bytes at 0x021DC040). The vendor object
 * addresses these statics section-relative (one pool word for the section
 * base plus a field offset), so they are declared here as one object laid
 * out in the object's own order; member names are the vendor statics.
 */
typedef struct {
    unsigned char *p_name;
    unsigned int   p_name_len;
    unsigned int   sLevel;
    unsigned int   aLevel;
    unsigned int   apAddr;
    unsigned int   apMask;
    char           ip_chg;
    char           p_type;
} _AOSS_INFO;

typedef struct {
    unsigned long x;
    unsigned long mul;
    unsigned long add;
} MATHRandContext16;

typedef struct {
    int            SecurityType;    /* +0x000 */
    void          *bssList;         /* +0x004 */
    int            initflg;         /* +0x008 */
    void          *linkInfo;        /* +0x00C */
    unsigned int   gError;          /* +0x010 */
    void          *s_buf;           /* +0x014 */
    MATHRandContext16 randContext;  /* +0x018 */
    _AOSS_INFO     gData;           /* +0x024 */
    unsigned char  ProductInfo[0x280];   /* +0x040 PRODUCT_INFO_AOSS */
    unsigned long  crc_table[256];       /* +0x2C0 */
    unsigned char  SecurityInfo[0x6A0];  /* +0x6C0 ASTS_DATA_INFO[2] */
} AOSS_BSS;

extern AOSS_BSS aoss_bss;

typedef struct {
    unsigned long addr;
} SOCInAddr;

typedef struct {
    unsigned char  len;
    unsigned char  family;
    unsigned short port;
    SOCInAddr      addr;
} SOCSockAddrIn;

extern void *AOSS_Memset(void *s, int c, int n);
extern unsigned short AOSS_Htons(unsigned short hostshort);
extern unsigned long AOSS_Htonl(unsigned long hostlong);
extern int AOSS_Sendto(int s, void *msg, int len, int flags, void *to, int tolen);

int SendPacketUDP(unsigned char *packet, int size, unsigned char Mac, int port)
{
    int byte;
    SOCSockAddrIn server;

    AOSS_Memset(&server, 0, sizeof(server));
    server.family = 2;
    server.port = AOSS_Htons(0x5790);
    server.addr.addr = AOSS_Htonl(aoss_bss.gData.apAddr);
    if (Mac == 0xff || aoss_bss.gData.ip_chg == 0)
        server.addr.addr = 0xffffffff;
    byte = AOSS_Sendto(port, packet, size, 0, &server, sizeof(server));
    return byte;
}
