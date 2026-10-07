/*
 * file:     unit_0215FDA4_p03.c
 * unit:     yes
 * function: func_02160108, func_02160130
 * address:  0x02160108
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02150FEC  0x02150FEC  data
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
void func_02160108(int a, int b);
CaInfo *func_02160130(Con *con, char *dn);
extern char g_02150FEC[];


/*
 * Hands a and b to the +0xc child of the object at +0xa4 as its +0x814 and
 * +0x818 words.
 */
void func_02160108(int a, int b)
{
    char *p = *(char **)(*(char **)(g_02150FEC + 4) + 0xa4);
    char *q;

    if (p != 0 && (q = *(char **)(p + 0xc)) != 0) {
        *(int *)(q + 0x814) = a;
        *(int *)(q + 0x818) = b;
    }
}


/*
 * note: a do-while behind an `if (n > 0)` guard puts the list load after the loop entry test.
 *
 * sdk:      get_rootCA (libssl.TWL.HYB.a(ssl.o))
 */
CaInfo *func_02160130(Con *con, char *dn)
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
