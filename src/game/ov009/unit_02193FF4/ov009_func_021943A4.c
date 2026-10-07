/*
 * function: func_021943A4
 * address:  0x021943A4
 * packet:   pkt_ov009_021943A4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ProcessStatement (gstats.o)
 *
 * symbols:
 *   func_020949F4 0x020949F4  arm
 *   func_021940DC 0x021940DC  arm
 *   func_02194184 0x02194184  arm
 *   func_02194220 0x02194220  arm
 *   func_02194308 0x02194308  arm
 *   g_021A58DC   0x021A58DC  data
 *   g_021A58E8   0x021A58E8  data
 *   g_021A58F4   0x021A58F4  data
 *   g_021A5900   0x021A5900  data
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern int func_020949F4(const u8 *s1, const u8 *s2, u32 n);
extern void func_021940DC();
extern void func_02194184();
extern void func_02194220();
extern void func_02194308();
extern char g_021A58DC[];
extern char g_021A58E8[];
extern char g_021A58F4[];
extern char g_021A5900[];

void func_021943A4(char *buff, int len)
{
    buff[len] = 0;
    if (func_020949F4((const u8 *)buff, (const u8 *)g_021A58DC, 8) == 0)
        func_021940DC(buff, len);
    else if (func_020949F4((const u8 *)buff, (const u8 *)g_021A58E8, 9) == 0)
        func_02194184(buff, len);
    else if (func_020949F4((const u8 *)buff, (const u8 *)g_021A58E8, 9) == 0)
        func_02194184(buff, len);
    else if (func_020949F4((const u8 *)buff, (const u8 *)g_021A58F4, 8) == 0)
        func_02194220(buff, len);
    else if (func_020949F4((const u8 *)buff, (const u8 *)g_021A5900, 8) == 0)
        func_02194308(buff, len);
}
