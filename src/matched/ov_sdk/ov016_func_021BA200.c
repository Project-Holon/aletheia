/*
 * function: GetCommandElement
 * address:  0x021BA200
 * packet:   pkt_ov016_021BA804
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GetFrameData     0x021B9EEC  thumb
 *   keywrap_decrypt  0x021BADD8  thumb
 *   memcpy           0x02092344  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol GetCommandElement (name from the vendor object).
 * atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021BA200.c \
 *       --func GetCommandElement --addr 0x021BA200 --region ov016 --cc ../2.0/sp1p2 --thumb
 */
extern unsigned char *GetFrameData(unsigned char *lpframe, int *pid, int *psize);
extern int keywrap_decrypt(char *dest, char *src, unsigned long buflen, char *keyptr, unsigned long keylen);
extern void *memcpy(void *dst, const void *src, unsigned long n);

int GetCommandElement(unsigned char *lpframe, int cmdid, unsigned char *lpelement, unsigned char *lpkey)
{
    int id;
    int size;
    unsigned char *lpb;

    lpb = GetFrameData(lpframe, &id, &size);
    if (lpb == 0)
        return 0;
    if (id != cmdid)
        return 0;
    if (lpkey != 0) {
        keywrap_decrypt((char *)lpelement, (char *)lpb, size, (char *)lpkey, 16);
        size -= 8;
    } else {
        memcpy(lpelement, lpb, size);
    }
    return size;
}
