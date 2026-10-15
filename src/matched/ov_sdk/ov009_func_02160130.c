/*
 * function: get_rootCA
 * address:  0x02160130
 * packet:   pkt_ov009_02160130
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * note: a do-while behind an `if (n > 0)` guard puts the list load after the loop entry test.
 *
 * sdk:      get_rootCA (libssl.TWL.HYB.a(ssl.o))
 *
 * symbols:
 *   func_020948E0  0x020948E0  arm
 */

typedef struct {
	char *name;
} CaInfo;

typedef struct {
	char pad0[0x814];
	CaInfo **rootCa;
	int rootCaNum;
} Con;

extern int func_020948E0(const char *s1, const char *s2);

CaInfo *get_rootCA(Con *con, char *dn)
{
	int i = 0;
	CaInfo **list;
	int n = con->rootCaNum;
	if (n > 0) {
		list = con->rootCa;
		do {
			CaInfo *ca = list[i];
			if (func_020948E0(ca->name, dn) == 0) {
				return ca;
			}
			i++;
		} while (i < n);
	}
	return 0;
}
