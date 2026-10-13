/*
 * function: DWCi_GdbSetUseSSL
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
 *   sakeSetFileUploadURL  0x021DD4B0  arm  ov175
 *   sakeSetFileDownloadURL  0x021DD3F8  arm  ov175
 *   gDwcGdbStorageServerUrl  0x021E4C88  data
 *   g_021AE01C  0x021AE01C  data
 *   sDwcGdbStorageUrlFormatSecure2  0x021E47DC  data
 *   sDwcGdbUploadUrlFormatSecure2  0x021E4830  data
 *   sDwcGdbDownloadUrlFormatSecure2  0x021E4878  data
 *   sDwcGdbStorageUrlFormatSecure  0x021E48C4  data
 *   sDwcGdbUploadUrlFormatSecure  0x021E4914  data
 *   sDwcGdbDownloadUrlFormatSecure  0x021E495C  data
 *   gDwcGdbEntity  0x021E5334  data
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
extern int func_021BF520(int a);
extern int sakeSetFileUploadURL(char *a, char *b);
extern int sakeSetFileDownloadURL(char *a, char *b);
extern char gDwcGdbStorageServerUrl[];
extern char g_021AE01C[];
extern char sDwcGdbStorageUrlFormatSecure2[];
extern char sDwcGdbUploadUrlFormatSecure2[];
extern char sDwcGdbDownloadUrlFormatSecure2[];
extern char sDwcGdbStorageUrlFormatSecure[];
extern char sDwcGdbUploadUrlFormatSecure[];
extern char sDwcGdbDownloadUrlFormatSecure[];
extern DWCiGdbEntity gDwcGdbEntity;

void DWCi_GdbSetUseSSL(int ssl_type)
{
    char upload_url[128];
    char download_url[128];

    switch (ssl_type) {
    case 1:
        func_02084F80(gDwcGdbStorageServerUrl, 128, sDwcGdbStorageUrlFormatSecure2, g_021AE01C);
        func_021BF520((int)gDwcGdbStorageServerUrl);
        func_02084F80(upload_url, 128, sDwcGdbUploadUrlFormatSecure2, g_021AE01C);
        func_021BF520((int)upload_url);
        func_02084F80(download_url, 128, sDwcGdbDownloadUrlFormatSecure2, g_021AE01C);
        func_021BF520((int)download_url);
        break;
    case 0:
    default:
        func_02084F80(gDwcGdbStorageServerUrl, 128, sDwcGdbStorageUrlFormatSecure, g_021AE01C);
        func_021BF520((int)gDwcGdbStorageServerUrl);
        func_02084F80(upload_url, 128, sDwcGdbUploadUrlFormatSecure, g_021AE01C);
        func_021BF520((int)upload_url);
        func_02084F80(download_url, 128, sDwcGdbDownloadUrlFormatSecure, g_021AE01C);
        func_021BF520((int)download_url);
        break;
    }
    sakeSetFileUploadURL(gDwcGdbEntity.sake, upload_url);
    sakeSetFileDownloadURL(gDwcGdbEntity.sake, download_url);
}
