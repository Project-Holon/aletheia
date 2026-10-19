/*
 * function: GF_PANIC_Print
 * address:  0x020348A4
 * packet:   pkt_020348A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *           --suggest-split offers nothing (single function, both
 *           unresolved sites' only witnesses are inside this range).
 * blocker:  TEXTPRINT_PrintText (label) and str_020A796C (string) -- neither has a
 *           witness outside 020348A4..02034900; both of this site's calls to
 *           TEXTPRINT_PrintText are inside this function. Every concrete byte of the
 *           body reproduces.
 * symbols:
 *   g_021469AC    0x021469AC  data
 *   str_020A796C  0x020A796C  data
 *   TEXTPRINT_PrintText 0x0204E328  arm
 */

#include "../include/G_Console.h"

typedef unsigned int u32;

extern struct Console g_021469AC;
extern const char str_020A796C[];
extern void TEXTPRINT_PrintText(const char *s, const char *d);

void GF_PANIC_Print(char *s)
{
    int f;

    TEXTPRINT_PrintText(s, ((char *)&g_021469AC));
    f = 0;
    while (*s != 0) {
        if (*s++ == '\n') {
            f = 1;
            break;
        }
    }
    if (f == 0) {
        TEXTPRINT_PrintText(str_020A796C, ((char *)&g_021469AC));
    }
}
