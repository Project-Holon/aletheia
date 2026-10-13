/*
 * function: DWCi_GdbCleanupRootCAList
 * address:  0x021E13BC
 * packet:   pkt_ov175_021E13BC
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GdbCleanupRootCAList (dwc_gdb.o)
 *
 * symbols:
 *   DWC_GHTTPCleanupRootCAList  0x021BF540  arm  ov114
 *   sakeGetFileUploadURL  0x021DD4D8  arm  ov175
 *   sakeGetFileDownloadURL  0x021DD420  arm  ov175
 *   gDwcGdbStorageServerUrl     0x021E4C88  data
 *   gDwcGdbEntity     0x021E5334  data
 */

typedef struct {
    int unk0;
    void *sake;
    int state;
} Tbl;
extern char gDwcGdbStorageServerUrl[];
extern Tbl gDwcGdbEntity;
extern int DWC_GHTTPCleanupRootCAList(char *url);
struct SAKEInternal;
extern int sakeGetFileUploadURL(struct SAKEInternal *sake, char *url);
extern int sakeGetFileDownloadURL(struct SAKEInternal *sake, int fileId, char *url);

void DWCi_GdbCleanupRootCAList(void)
{
    char upload_url[128];
    char download_url[128];

    DWC_GHTTPCleanupRootCAList(gDwcGdbStorageServerUrl);
    sakeGetFileUploadURL(gDwcGdbEntity.sake, upload_url);
    DWC_GHTTPCleanupRootCAList(upload_url);
    sakeGetFileDownloadURL(gDwcGdbEntity.sake, 1, download_url);
    DWC_GHTTPCleanupRootCAList(download_url);
}
