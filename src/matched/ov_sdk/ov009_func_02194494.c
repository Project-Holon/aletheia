/*
 * function: func_02194494
 * address:  0x02194494
 * packet:   pkt_ov009_02194494
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ProcessInBuffer (gstats.o)
 *
 * symbols:
 *   func_02193FF4 0x02193FF4  arm
 *   func_02193EB8 0x02193EB8  arm
 *   func_021943A4 0x021943A4  arm
 *   g_021A57F0   0x021A57F0  data
 *   g_021A57C8   0x021A57C8  data
 */

extern char *func_02193FF4(char *buff, int len);
extern void func_02193EB8(char *buf, int len);
extern void func_021943A4(char *buff, int len);
extern char *g_021A57C8;
extern char g_021A57F0[];

int func_02194494(char *buff, int len)
{
    char *pos;
    int oldlen;

    oldlen = len;
    pos = func_02193FF4(buff, len);

    while (len > 0 && pos != 0) {
        g_021A57C8 = g_021A57F0;
        func_02193EB8(buff, pos - buff);
        func_021943A4(buff, pos - buff);
        len -= (pos - buff) + 7;
        buff = pos + 7;
        if (len > 0)
            pos = func_02193FF4(buff, len);
    }
    return oldlen - len;
}
