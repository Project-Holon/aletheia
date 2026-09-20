/*
 * function: func_020348A4
 * address:  0x020348A4
 * packet:   pkt_020348A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output.
 *           --suggest-split offers nothing (single function, both
 *           unresolved sites' only witnesses are inside this range).
 * blocker:  func_0204E328 (label) and str_020A796C (string) -- neither has a
 *           witness outside 020348A4..02034900; both of this site's calls to
 *           func_0204E328 are inside this function. Every concrete byte of the
 *           body reproduces.
 * symbols:
 *   g_021469AC    0x021469AC  data
 *   str_020A796C  0x020A796C  data
 *   func_0204E328 0x0204E328  arm
 */

typedef unsigned int u32;

extern char g_021469AC[];
extern const char str_020A796C[];
extern void func_0204E328(const char *s, const char *d);

void func_020348A4(char *s)
{
    int f;

    func_0204E328(s, g_021469AC);
    f = 0;
    while (*s != 0) {
        if (*s++ == '\n') {
            f = 1;
            break;
        }
    }
    if (f == 0) {
        func_0204E328(str_020A796C, g_021469AC);
    }
}
