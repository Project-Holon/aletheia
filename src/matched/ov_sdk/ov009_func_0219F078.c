/*
 * function: func_0219F078
 * address:  0x0219F078
 * packet:   pkt_ov009_0219F078
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ServerBrowserSortA (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 *
 * symbols:
 *   func_02094798  0x02094798  arm
 *   func_0219F50C  0x0219F50C  arm  ov009
 */

struct SortInfo {
    char sortkey[255];
    int comparemode;
};

struct ServerBrowser {
    char pad[0x60];
    char list[1];
};

extern char *func_02094798(char *dst, const char *src);
extern void func_0219F50C(void *slist, int ascending, struct SortInfo sortinfo);

void func_0219F078(struct ServerBrowser *sb, int ascending, char *sortkey, int comparemode)
{
    struct SortInfo info;

    info.comparemode = comparemode;
    func_02094798(info.sortkey, sortkey);
    func_0219F50C(&sb->list, ascending, info);
}
