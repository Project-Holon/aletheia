/*
 * function: func_021BD170
 * address:  0x021BD170
 * packet:   pkt_ov016_021BD170
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Char (libdwcutil.TWL.HYB.a(common.o))
 *
 * symbols:
 *   func_02094860  0x02094860  arm
 *   func_021C0EC8  0x021c0ec8  arm  ov016
 *   g_021DE510  0x021de510  data
 *   g_021DA044  0x021da044  data
 *   strncpy  0x02094860  arm
 */

#include "../../../matched/arm9_sdk/libc/string.h"

extern char *strncpy(char *d, const char *s, unsigned long n);

extern unsigned char g_021DE510[];
extern const unsigned char g_021DA044[];
extern int func_021C0EC8(void);

unsigned char *func_021BD170(unsigned char *name)
{
    int lang;

    strncpy((char *)g_021DE510, (char *)name, 0x3f);
    if (name[5] == 'x')
        return g_021DE510;
    lang = func_021C0EC8();
    if (name[5] == 'y' && lang != 0)
        return g_021DE510;
    g_021DE510[5] = g_021DA044[lang];
    return g_021DE510;
}
