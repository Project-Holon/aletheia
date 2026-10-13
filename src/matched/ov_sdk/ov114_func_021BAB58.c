/*
 * function: checkTagPost
 * address:  0x021BAB58
 * packet:   pkt_ov114_021BAB58
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      checkTagPost (libnhttp.TWL.HYB.a(nhttp_control.o))
 *
 * symbols:
 *   NHTTPi_memfind 0x021BA690 arm ov114
 *   incAscii 0x021BAB24 arm ov114
 *   g_021CDFC8 0x021CDFC8 data
 */

typedef struct {
    char pad[0x38];
    char tag[0x20];
} Req;

extern char g_021CDFC8[];

extern int NHTTPi_memfind(signed char *hay, int len1, signed char *needle, int len2);
extern char incAscii(unsigned char c);

int checkTagPost(Req *req_p, char *value_p, unsigned long length)
{
    char c;
    int n;

    if (NHTTPi_memfind((signed char *)value_p, length, (signed char *)(&req_p->tag[2]), 0x12) < 0) {
        return 1;
    }
    for (n = 0x13; n >= 2; n--) {
        char *tp = (char *)req_p + n;
        char t;
        c = tp[0x38];
        t = g_021CDFC8[n];
        while (1) {
            c = incAscii(c);
            tp[0x38] = c;
            if (c == t) {
                break;
            }
            if (NHTTPi_memfind((signed char *)value_p, length, (signed char *)(&req_p->tag[2]), 0x12) < 0) {
                return 1;
            }
        }
    }
    return 0;
}
