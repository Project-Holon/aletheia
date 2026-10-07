/*
 * file:     unit_0219F0E0_p04.c
 * unit:     yes
 * function: func_0219F888, func_0219F8B0, func_0219F920
 * address:  0x0219F888
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
 *   func_02184144  0x02184144  arm  ov009
 *   func_0219DF64  0x0219DF64  arm  ov009
 *   func_0218482C  0x0218482C  arm  ov009
 *   func_0217F1E0  0x0217F1E0  arm  ov009
 *   func_0218474C  0x0218474C  arm  ov009
 *   func_021847BC  0x021847BC  arm  ov009
 */
struct SBServerList {
    char pad0[4];
    void *servers;
    char pad1[0x7d8 - 8];
    void *deadlist;
};

struct Ref { char *str; int refcount; };

extern void *func_02184144(int elemSize, int numElemsToAllocate, void (*elemFreeFn)(void *));
extern void *func_0219DF64(void *l);
extern struct Ref *func_0218482C(void *t, void *k);
extern char *func_0217F1E0(char *s);
extern void func_0218474C(void *t, void *e);
extern int func_021847BC(void *t, void *k);
void func_0219F888(struct SBServerList *slist);
char *func_0219F8B0(void *slist, char *str);
void func_0219F920(void *slist, char *str);


/*
 * sdk:      SBAllocateServerList (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void func_0219F888(struct SBServerList *slist)
{
    slist->servers = func_02184144(4, 100, 0);
    slist->deadlist = 0;
}

/*
 * sdk:      SBRefStr (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
char *func_0219F8B0(void *slist, char *str)
{
	struct Ref ref;
	struct Ref *val;
	ref.str = str;
	val = func_0218482C(func_0219DF64(slist), &ref);
	if (val != 0) {
		val->refcount++;
		return val->str;
	}
	ref.str = func_0217F1E0(str);
	ref.refcount = 1;
	func_0218474C(func_0219DF64(slist), &ref);
	return ref.str;
}

/*
 * sdk:      SBReleaseStr (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
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
