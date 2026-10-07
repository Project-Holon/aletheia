/*
 * function: func_021C5724
 * address:  0x021C5724
 * packet:   pkt_ov114_021C5724
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SVLTokenWaitThread (libdwcnd.TWL.HYB.a(dwc_nd.o))
 *
 * symbols:
 *   func_02168040  0x02168040  arm  ov009
 *   strlen         0x0209477C  arm
 *   func_021C58C8  0x021C58C8  arm  ov114
 *   func_02084F80  0x02084F80  arm
 *   func_02059B40  0x02059B40  arm
 *   func_021C6348  0x021C6348  arm  ov114
 *   func_02059E18  0x02059E18  arm
 *   func_02059F54  0x02059F54  arm
 *   func_02085A38  0x02085A38  arm
 *   func_021C569C  0x021C569C  arm  ov114
 *   func_021C56B4  0x021C56B4  arm  ov114
 *   g_021D3B68     0x021D3B68  data
 *   @16277         0x021CF348  data
 *   @16278         0x021CF35C  data
 *
 * DWC_SVLProcess (0x02168040) is catalogued in ov009 (libdwcnas.TWL.HYB.a,
 * dwc_nasfunc.o), which the ov009 token on its line records.  The file statics
 * of dwc_nd.o are reached through s_userCallback (0x021D3B68); +0x18 holds the
 * SVL result pointer.
 */

#include "../../../matched/arm9_sdk/libc/string.h"
#include "../../../matched/include/G_NdState.h"

typedef unsigned long u32;

typedef struct SvlResult {
    char gamecd[0x20];          /* +0x00 */
    char passwd[0x20];          /* +0x20 */
    int status;                 /* +0x40 */
    char pad44[4];
    char svlhost[0x89 - 0x48];  /* +0x48 */
    char svltoken[1];           /* +0x89 */
} SvlResult;

extern struct NdState g_021D3B68;

extern int func_02168040(void);
extern void func_021C58C8(int reason, int error, int servererror);
extern int func_02084F80(char *dst, u32 len, const char *fmt, ...);
extern int func_02059B40(char *src, u32 srclen, char *dst, u32 dstlen);
extern int func_021C6348(void *(*alloc)(u32, int), void (*free)(void *), char *url,
                         char *token, char *gamecd, char *passwd,
                         void (*callback)(int, int, int));
extern int func_02059E18(int *errorCode);
extern void func_02059F54(int error, int errorCode);
extern void func_02085A38(u32 msec);
extern void *func_021C569C(u32 size, int align);
extern void func_021C56B4(void *ptr);

static void func_021C5724(void)
{
    char url[256];
    char token[400];
    int errorcode;

    while (1) {
        switch (func_02168040()) {
        case 3:
            if (strlen(((SvlResult *)g_021D3B68.svl)->svlhost) + strlen("https:///download") > sizeof(url) - 1) {
                func_021C58C8(0, 8, -1);
                return;
            }
            func_02084F80(url, sizeof(url), "https://%s/download", ((SvlResult *)g_021D3B68.svl)->svlhost);
            if (func_02059B40(((SvlResult *)g_021D3B68.svl)->svltoken, strlen(((SvlResult *)g_021D3B68.svl)->svltoken),
                              token, sizeof(token)) < 0) {
                func_021C58C8(0, 8, -1);
                return;
            }
            if (!func_021C6348(func_021C569C, func_021C56B4, url, token, ((SvlResult *)g_021D3B68.svl)->gamecd,
                               ((SvlResult *)g_021D3B68.svl)->passwd, func_021C58C8)) {
                func_021C58C8(0, 8, -1);
                return;
            }
            ((SvlResult *)g_021D3B68.svl)->status = 1;
            func_021C58C8(0, 0, -1);
            return;
        case 4:
            func_02059E18(&errorcode);
            func_02059F54(13, errorcode);
            func_021C58C8(0, 3, -1);
            return;
        case 5:
            func_021C58C8(0, 6, -1);
            return;
        }
        func_02085A38(100);
    }
}
