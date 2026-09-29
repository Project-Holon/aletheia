/*
 * function: func_021F3FC8
 * address:  0x021F3FC8
 * packet:   pkt_ov107_021F3FC8
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MB_SendGameInfoBeacon (libmb.TWL.HYB.a(mb_gameinfo.o))
 *
 * symbols:
 *   g_021F6EF4  0x021F6EF4  data
 *   func_021F4054  0x021F4054  arm  ov107
 *   func_021F40F4  0x021F40F4  arm  ov107
 *   func_021F4140  0x021F4140  arm  ov107
 *   func_021F42A4  0x021F42A4  arm  ov107
 *   func_021F42D4  0x021F42D4  arm  ov107
 */

extern unsigned char g_021F6EF4[];
extern int func_021F4054(void);
extern void func_021F40F4(void);
extern void func_021F4140(unsigned long ggid, unsigned short tgid, unsigned char attribute);
extern void func_021F42A4(void);
extern void func_021F42D4(unsigned long ggid, unsigned short tgid, unsigned char attribute);

void func_021F3FC8(unsigned long ggid, unsigned short tgid, unsigned char attribute)
{
    while (1) {
        switch (g_021F6EF4[0x24]) {
        case 0:
        case 1:
            if (!func_021F4054())
                return;
            break;
        case 2:
            func_021F40F4();
            break;
        case 3:
            func_021F4140(ggid, tgid, attribute);
            return;
        case 4:
            func_021F42A4();
            break;
        case 5:
            func_021F42D4(ggid, tgid, attribute);
            return;
        case 6:
            break;
        }
    }
}
