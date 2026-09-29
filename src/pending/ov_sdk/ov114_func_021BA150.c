/* NHTTPi_strnicmp (nhttp_stdlib_ntr): near miss. Logic and shape match; residue is register assignment only
 * (original c1=sb c2=r8 zero=r4 ones=r5,lr,ip,r3; draft c1=r3 c2=sb zero=r6 ones=r7,r5,r4,lr). Tried decl/load/fold order permutations. */
#define NHTTPi_TOLOWER(c) ((((c) >= 'A') & ((c) <= 'Z')) ? (c) + 0x20 : (c))

int func_021BA150(char *p1_p, char *p2_p, int size)
{
    char c2;
    char c1;

    while (size > 0) {
        c2 = *p2_p++;
        c1 = *p1_p++;

        if (c1 == 0 || c2 == 0) {
            if (c1 == 0 && c2 == 0) {
                size = 0;
                break;
            }
        }
        c1 = NHTTPi_TOLOWER(c1);
        c2 = NHTTPi_TOLOWER(c2);

        if (c1 != c2) {
            break;
        }
        size--;
    }
    return size;
}
