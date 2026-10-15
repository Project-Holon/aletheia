/*
 * function: ServerBrowserSendMessageToServerA
 * address:  0x0219EF08
 * packet:   pkt_ov009_0219EF08
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ServerBrowserSendMessageToServerA (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverbrowsing.o))
 *
 * symbols:
 *   inet_addr  0x0217ED38  arm  ov009
 *   SBSendMessageToServer  0x021A1620  arm  ov009
 */

struct ServerBrowser {
    char pad[0x60];
    char list[1];
};

extern int inet_addr(int a);
extern int SBSendMessageToServer(void *slist, unsigned int ip, unsigned short port, char *data, int len);

int ServerBrowserSendMessageToServerA(struct ServerBrowser *sb, char *ip, unsigned short port, char *data, int len)
{
    return SBSendMessageToServer(&sb->list, inet_addr((int)ip),
                         (unsigned short)(((port >> 8) & 0xff) | ((port << 8) & 0xff00)), data, len);
}
