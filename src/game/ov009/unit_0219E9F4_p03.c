/*
 * file:     unit_0219E9F4_p03.c
 * unit:     yes
 * function: func_0219EFA8, func_0219EFD0, func_0219EFF0, func_0219F00C, func_0219F024, func_0219F058, func_0219F068, func_0219F078
 * address:  0x0219EFA8
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
 *   func_0219F674  0x0219F674  arm  ov009
 *   func_0219F768  0x0219F768  arm  ov009
 *   func_0219A4A4  0x0219A4A4  arm  ov009
 *   func_0219DE88  0x0219DE88  arm  ov009
 *   func_021A1928  0x021A1928  arm  ov009
 *   func_021A02E0  0x021A02E0  arm  ov009
 *   func_0219D8E0  0x0219D8E0  arm  ov009
 *   func_0219F830  0x0219F830  arm  ov009
 *   func_0219F7C4  0x0219F7C4  arm
 *   func_0219F7B4  0x0219F7B4  arm
 *   func_02094798  0x02094798  arm
 *   func_0219F50C  0x0219F50C  arm  ov009
 */
struct SBServer;
struct SBL;
struct ServerBrowser {
    char pad[0x60];
    char list[1];
};

struct SortInfo {
    char sortkey[255];
    int comparemode;
};

extern int func_0219F674(struct SBL *slist, void *findserver);
extern void func_0219F768(struct SBL *slist, int index);
extern void func_0219A4A4(void *p);
extern void func_0219DE88(void *p);
extern int func_021A1928(int *p);
extern void func_021A02E0(struct SBL *slist);
extern void func_0219D8E0(char *p);
extern void func_0219F830(struct SBL *slist);
extern int func_0219F7C4(int *p);
extern void func_0219F7B4(char *p);
extern char *func_02094798(char *dst, const char *src);
extern void func_0219F50C(void *slist, int ascending, struct SortInfo sortinfo);
void func_0219EFA8(struct ServerBrowser *sb, struct SBServer *server);
int func_0219EFD0(char *p);
void func_0219EFF0(char *p);
void func_0219F00C(char *p);
int func_0219F024(char *p);
void func_0219F058(char *p);
void func_0219F068(char *p);
void func_0219F078(struct ServerBrowser *sb, int ascending, char *sortkey, int comparemode);


/*
 * sdk:      ServerBrowserRemoveServer (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 */
void func_0219EFA8(struct ServerBrowser *sb, struct SBServer *server)
{
    int i;

    i = func_0219F674((struct SBL *)(&sb->list), server);
    if (i != -1)
        func_0219F768((struct SBL *)(&sb->list), i);
}


/*
 * Releases the object and the block 0x60 bytes in.
 */
int func_0219EFD0(char *p)
{
    func_0219A4A4(p);
    func_0219DE88(p);
    return func_021A1928((int *)(p + 0x60));
}


/*
 * Prepares the block 0x60 bytes in and then the object itself.
 */
void func_0219EFF0(char *p)
{
    func_021A02E0((struct SBL *)(p + 0x60));
    func_0219D8E0(p);
}


/*
 * Calls the two block helpers sixty bytes apart.
 */
void func_0219F00C(char *p)
{
    func_0219EFF0(p);
    func_0219F830((struct SBL *)(p + 0x60));
}

/*
 * Maps the +0x10 sign and the +0x60 state word to a small mode code.
 */
int func_0219F024(char *p)
{
    int v;

    if (*(int *)(p + 0x10) > 0) return 2;
    v = *(int *)(p + 0x60);
    if (v == 3 || v == 0) return 1;
    if (v == 1) return 0;
    return 3;
}


void func_0219F058(char *p)
{
    func_0219F7C4((int *)(p + 0x60));
}


/*
 * Tail call on the object 0x60 bytes in.
 *
 *   (ov009's listing emits it as a .word run, ov021's as Thumb code), so
 *   neither `label` nor `sole-ref/code` can attest the ABS32 site.  Witness
 *   class: label / sole-ref/code.
 */
void func_0219F068(char *p)
{
    func_0219F7B4(p + 0x60);
}


/*
 * sdk:      ServerBrowserSortA (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 */
void func_0219F078(struct ServerBrowser *sb, int ascending, char *sortkey, int comparemode)
{
    struct SortInfo info;

    info.comparemode = comparemode;
    func_02094798(info.sortkey, sortkey);
    func_0219F50C(&sb->list, ascending, info);
}
