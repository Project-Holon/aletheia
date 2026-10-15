/*
 * function: DWCi_Http_CheckHeaderReceived
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
 *   strstr  0x02094B20  arm
 *   OS_LockMutex   0x02086028  arm
 *   OS_UnlockMutex 0x02086078  arm
 *   strlen  0x0209477C  arm
 *   atoi  0x020964E0  arm
 *   gDwcHttpHeaderTerminator     0x021A25D4  data
 *   gDwcHttpContentLengthPrefix     0x021A25F0  data
 *   gDwcHttpCrLf     0x021A2604  data
 */

typedef struct {
    char *base;
    char *cur;
    char *end;
    int cap;
} Buf;
extern char gDwcHttpHeaderTerminator[];
extern char gDwcHttpContentLengthPrefix[];
extern char gDwcHttpCrLf[];
extern unsigned char *strstr(const unsigned char *s1, const unsigned char *s2);
extern void OS_LockMutex(void *mutex);
extern void OS_UnlockMutex(void *mutex);
typedef unsigned char  u8;
extern int strlen(const u8 *s);
typedef unsigned int   u32;
extern int atoi(u32 a0);

int DWCi_Http_CheckHeaderReceived(char *http)
{
    char content_temp;
    char *content_end;
    char *content_length;
    char *endof_header;
    Buf *rep;
    char *hdr;

    hdr = *(char **)(http + 0x1a44);
    rep = (Buf *)(http + 0x1a44);
    if (strstr((const unsigned char *)hdr, (const unsigned char *)gDwcHttpHeaderTerminator) == 0) {
        return 0;
    }
    endof_header = (char *)(strstr((const unsigned char *)hdr, (const unsigned char *)gDwcHttpHeaderTerminator) + 4);
    OS_LockMutex(http + 0x1a54);
    *(int *)(http + 0x1a70) = rep->cur - endof_header;
    OS_UnlockMutex(http + 0x1a54);
    content_length = (char *)strstr((const unsigned char *)rep->base, (const unsigned char *)gDwcHttpContentLengthPrefix);
    if (content_length == 0) {
        return 1;
    }
    content_length += strlen((const u8 *)gDwcHttpContentLengthPrefix);
    content_end = (char *)strstr((const unsigned char *)content_length, (const unsigned char *)gDwcHttpCrLf);
    content_temp = *content_end;
    *content_end = 0;
    OS_LockMutex(http + 0x1a54);
    *(int *)(http + 0x1a6c) = atoi((u32)content_length);
    OS_UnlockMutex(http + 0x1a54);
    *content_end = content_temp;
    return 1;
}
