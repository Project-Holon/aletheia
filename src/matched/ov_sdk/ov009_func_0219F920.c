/*
 * function: func_0219F920
 * address:  0x0219F920
 * packet:   pkt_ov009_0219F920
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SBReleaseStr (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   func_0219DF64  0x0219DF64  arm  ov009
 *   func_0218482C  0x0218482C  arm  ov009
 *   func_021847BC  0x021847BC  arm  ov009
 */

struct Ref { char *str; int refcount; };
extern void *func_0219DF64(void *l);
extern struct Ref *func_0218482C(void *t, void *k);
extern int func_021847BC(void *t, void *k);
void func_0219F920(void *slist, char *str)
{
	struct Ref ref;
	struct Ref *val;
	ref.str = str;
	val = func_0218482C(func_0219DF64(slist), &ref);
	if (val == 0)
		return;
	if (--val->refcount == 0)
		func_021847BC(func_0219DF64(slist), &ref);
}
