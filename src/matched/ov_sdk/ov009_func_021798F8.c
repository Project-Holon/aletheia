/*
 * function: func_021798F8
 * address:  0x021798F8
 * packet:   pkt_ov009_021798F8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Http_CheckHeaderReceived (dwc_http.o)
 *
 * symbols:
 *   func_02094B20  0x02094B20  arm
 *   OS_LockMutex   0x02086028  arm
 *   OS_UnlockMutex 0x02086078  arm
 *   func_0209477C  0x0209477C  arm
 *   func_020964E0  0x020964E0  arm
 *   g_021A25D4     0x021A25D4  data
 *   g_021A25F0     0x021A25F0  data
 *   g_021A2604     0x021A2604  data
 */

typedef struct {
    char *base;
    char *cur;
    char *end;
    int cap;
} Buf;
extern char g_021A25D4[];
extern char g_021A25F0[];
extern char g_021A2604[];
extern char *func_02094B20(const char *s, const char *sub);
extern void OS_LockMutex(void *mutex);
extern void OS_UnlockMutex(void *mutex);
typedef unsigned char  u8;
extern int func_0209477C(const u8 *s);
typedef unsigned int   u32;
extern int func_020964E0(u32 a0);

int func_021798F8(char *http)
{
    char content_temp;
    char *content_end;
    char *content_length;
    char *endof_header;
    Buf *rep;
    char *hdr;

    hdr = *(char **)(http + 0x1a44);
    rep = (Buf *)(http + 0x1a44);
    if (func_02094B20(hdr, g_021A25D4) == 0) {
        return 0;
    }
    endof_header = func_02094B20(hdr, g_021A25D4) + 4;
    OS_LockMutex(http + 0x1a54);
    *(int *)(http + 0x1a70) = rep->cur - endof_header;
    OS_UnlockMutex(http + 0x1a54);
    content_length = func_02094B20(rep->base, g_021A25F0);
    if (content_length == 0) {
        return 1;
    }
    content_length += func_0209477C((const u8 *)g_021A25F0);
    content_end = func_02094B20(content_length, g_021A2604);
    content_temp = *content_end;
    *content_end = 0;
    OS_LockMutex(http + 0x1a54);
    *(int *)(http + 0x1a6c) = func_020964E0((u32)content_length);
    OS_UnlockMutex(http + 0x1a54);
    *content_end = content_temp;
    return 1;
}
