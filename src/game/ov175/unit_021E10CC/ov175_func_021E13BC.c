/*
 * function: func_021E13BC
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
 *   func_021BF540  0x021BF540  arm  ov114
 *   func_021DD4D8  0x021DD4D8  arm  ov175
 *   func_021DD420  0x021DD420  arm  ov175
 *   g_021E4C88     0x021E4C88  data
 *   g_021E5334     0x021E5334  data
 */

typedef struct {
    int unk0;
    void *sake;
    int state;
} Tbl;
extern char g_021E4C88[];
extern Tbl g_021E5334;
extern int func_021BF540(char *url);
struct SAKEInternal;
extern int func_021DD4D8(struct SAKEInternal *sake, char *url);
extern int func_021DD420(struct SAKEInternal *sake, int fileId, char *url);

void func_021E13BC(void)
{
    char upload_url[128];
    char download_url[128];

    func_021BF540(g_021E4C88);
    func_021DD4D8(g_021E5334.sake, upload_url);
    func_021BF540(upload_url);
    func_021DD420(g_021E5334.sake, 1, download_url);
    func_021BF540(download_url);
}
