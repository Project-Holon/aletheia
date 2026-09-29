/*
 * function: func_021BAB58
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
 *   func_021BA690 0x021BA690 arm ov114
 *   func_021BAB24 0x021BAB24 arm ov114
 *   g_021CDFC8 0x021CDFC8 data
 */

typedef struct {
    char pad[0x38];
    char tag[0x20];
} Req;

extern char g_021CDFC8[];

extern int func_021BA690(char *p_p, int size, char *pattern_p, int patternsize);
extern char func_021BAB24(unsigned char c);

int func_021BAB58(Req *req_p, char *value_p, unsigned long length)
{
    char c;
    int n;

    if (func_021BA690(value_p, length, &req_p->tag[2], 0x12) < 0) {
        return 1;
    }
    for (n = 0x13; n >= 2; n--) {
        char *tp = (char *)req_p + n;
        char t;
        c = tp[0x38];
        t = g_021CDFC8[n];
        while (1) {
            c = func_021BAB24(c);
            tp[0x38] = c;
            if (c == t) {
                break;
            }
            if (func_021BA690(value_p, length, &req_p->tag[2], 0x12) < 0) {
                return 1;
            }
        }
    }
    return 0;
}
