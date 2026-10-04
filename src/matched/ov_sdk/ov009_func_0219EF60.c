/*
 * function: func_0219EF60
 * address:  0x0219EF60
 * packet:   pkt_ov009_0219EF60
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ServerBrowserSendNatNegotiateCookieToServerA (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 *
 * symbols:
 *   func_0217ED38  0x0217ED38  arm  ov009
 *   func_021A174C  0x021A174C  arm  ov009
 */

struct ServerBrowser {
    char pad[0x60];
    char list[1];
};

extern int func_0217ED38(int a);
extern int func_021A174C(void *slist, unsigned int ip, unsigned short port, int cookie);

int func_0219EF60(struct ServerBrowser *sb, char *ip, unsigned short port, int cookie)
{
    return func_021A174C(&sb->list, func_0217ED38((int)ip),
                         (unsigned short)(((port >> 8) & 0xff) | ((port << 8) & 0xff00)), cookie);
}
