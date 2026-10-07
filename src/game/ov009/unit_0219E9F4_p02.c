/*
 * file:     unit_0219E9F4_p02.c
 * unit:     yes
 * function: func_0219EF08, func_0219EF60
 * address:  0x0219EF08
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
 *   func_0217ED38  0x0217ED38  arm  ov009
 *   func_021A1620  0x021A1620  arm  ov009
 *   func_021A174C  0x021A174C  arm  ov009
 */
struct ServerBrowser {
    char pad[0x60];
    char list[1];
};

extern int func_0217ED38(int a);
extern int func_021A1620(void *slist, unsigned int ip, unsigned short port, char *data, int len);
extern int func_021A174C(void *slist, unsigned int ip, unsigned short port, int cookie);
int func_0219EF08(struct ServerBrowser *sb, char *ip, unsigned short port, char *data, int len);
int func_0219EF60(struct ServerBrowser *sb, char *ip, unsigned short port, int cookie);


/*
 * sdk:      ServerBrowserSendMessageToServerA (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 */
int func_0219EF08(struct ServerBrowser *sb, char *ip, unsigned short port, char *data, int len)
{
    return func_021A1620(&sb->list, func_0217ED38((int)ip),
                         (unsigned short)(((port >> 8) & 0xff) | ((port << 8) & 0xff00)), data, len);
}


/*
 * sdk:      ServerBrowserSendNatNegotiateCookieToServerA (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 */
int func_0219EF60(struct ServerBrowser *sb, char *ip, unsigned short port, int cookie)
{
    return func_021A174C(&sb->list, func_0217ED38((int)ip),
                         (unsigned short)(((port >> 8) & 0xff) | ((port << 8) & 0xff00)), cookie);
}
