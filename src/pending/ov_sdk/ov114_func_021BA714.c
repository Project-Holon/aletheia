/* NHTTPi_Base64Encode (nhttp_stdlib_ntr, tbl = g_021CE3BC): near miss, ~15 attempts.
 * Residue: 4 bytes short. Original loads the three source chars in order [r6],[r6,#1],[r6,#2] into r2,r3,ip and
 * bumps r6 by 3 at the end; draft loads b,c,a and folds the +3 into a post-indexed ldrsb (r6 advances early).
 * Registers tbl=r4 wp=r5 already match (locals declared tbl,wp,i,len). */

extern char g_021CE3BC[];
extern int func_021BA118(char *str_p);

int func_021BA714(char *dst_p, char *src_p)
{
    char *tbl;
    char *wp;
    int i;
    int len;

    tbl = g_021CE3BC;
    wp = dst_p;
    len = func_021BA118(src_p);
    for (i = 0; i < len; i += 3) {
        char a = src_p[0];
        char b = src_p[1];
        char c = src_p[2];
        wp[0] = tbl[a >> 2];
        wp[1] = tbl[(b >> 4) + ((a & 0x3) << 4)];
        wp[2] = tbl[(c >> 6) + ((b & 0xf) << 2)];
        wp[3] = tbl[c & 0x3f];
        wp += 4;
        src_p += 3;
    }
    if (i == len + 1) {
        wp[-1] = '=';
    } else if (i == len + 2) {
        wp[-2] = '=';
        wp[-1] = '=';
    }
    *wp = 0;
    return func_021BA118(dst_p);
}
