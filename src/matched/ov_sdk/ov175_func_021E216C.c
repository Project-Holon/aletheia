/*
 * function: func_021E216C
 * address:  0x021E216C
 * packet:   pkt_ov175_021E216C
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GdbSetUseSSL (libdwcgdb.TWL.HYB.a(dwc_gdb.o))
 *
 * symbols:
 *   func_02084F80  0x02084F80  arm
 *   func_021BF520  0x021BF520  arm  ov114
 *   func_021DD4B0  0x021DD4B0  arm  ov175
 *   func_021DD3F8  0x021DD3F8  arm  ov175
 *   g_021E4C88  0x021E4C88  data
 *   g_021AE01C  0x021AE01C  data
 *   g_021E47DC  0x021E47DC  data
 *   g_021E4830  0x021E4830  data
 *   g_021E4878  0x021E4878  data
 *   g_021E48C4  0x021E48C4  data
 *   g_021E4914  0x021E4914  data
 *   g_021E495C  0x021E495C  data
 *   g_021E5334  0x021E5334  data
 */

typedef unsigned char u8;
typedef unsigned long u32;

typedef struct {
    int size;
    u32 pseudo[3];
    u32 authentic[3];
    int gs_profile_id;
    int flag;
    u32 gamecode;
    int reserved[5];
    u32 crc32;
} DWCstAccUserData;

typedef struct {
    void *request;
    void *sake;
    int   state;
    int   process;
    int   result;
    u32   current_work;
    u8    work[2][56];
} DWCiGdbEntity;

extern int func_02084F80(char *dst, u32 len, const char *fmt, ...);
extern int func_021BF520(char *url);
extern int func_021DD4B0(char *a, char *b);
extern int func_021DD3F8(char *a, char *b);
extern char g_021E4C88[];
extern char g_021AE01C[];
extern char g_021E47DC[];
extern char g_021E4830[];
extern char g_021E4878[];
extern char g_021E48C4[];
extern char g_021E4914[];
extern char g_021E495C[];
extern DWCiGdbEntity g_021E5334;

void func_021E216C(int ssl_type)
{
    char upload_url[128];
    char download_url[128];

    switch (ssl_type) {
    case 1:
        func_02084F80(g_021E4C88, 128, g_021E47DC, g_021AE01C);
        func_021BF520(g_021E4C88);
        func_02084F80(upload_url, 128, g_021E4830, g_021AE01C);
        func_021BF520(upload_url);
        func_02084F80(download_url, 128, g_021E4878, g_021AE01C);
        func_021BF520(download_url);
        break;
    case 0:
    default:
        func_02084F80(g_021E4C88, 128, g_021E48C4, g_021AE01C);
        func_021BF520(g_021E4C88);
        func_02084F80(upload_url, 128, g_021E4914, g_021AE01C);
        func_021BF520(upload_url);
        func_02084F80(download_url, 128, g_021E495C, g_021AE01C);
        func_021BF520(download_url);
        break;
    }
    func_021DD4B0(g_021E5334.sake, upload_url);
    func_021DD3F8(g_021E5334.sake, download_url);
}
