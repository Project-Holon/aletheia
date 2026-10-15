/*
 * function: SBRefStr
 * address:  0x0219F8B0
 * packet:   pkt_ov009_0219F8B0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SBRefStr (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   func_0219DF64  0x0219DF64  arm  ov009
 *   func_0218482C  0x0218482C  arm  ov009
 *   goastrdup  0x0217F1E0  arm  ov009
 *   func_0218474C  0x0218474C  arm  ov009
 */

struct Ref { char *str; int refcount; };
extern void *func_0219DF64(void *l);
extern struct Ref *func_0218482C(void *t, void *k);
extern char *goastrdup(char *s);
extern void func_0218474C(void *t, void *e);
char *SBRefStr(void *slist, char *str)
{
	struct Ref ref;
	struct Ref *val;
	ref.str = str;
	val = func_0218482C(func_0219DF64(slist), &ref);
	if (val != 0) {
		val->refcount++;
		return val->str;
	}
	ref.str = goastrdup(str);
	ref.refcount = 1;
	func_0218474C(func_0219DF64(slist), &ref);
	return ref.str;
}
