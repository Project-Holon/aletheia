/*
 * function: ProcessStatement
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
 *   ProcessPlayerAuth 0x021940DC  arm
 *   ProcessGetPid 0x02194184  arm
 *   ProcessGetData 0x02194220  arm
 *   ProcessSetData 0x02194308  arm
 *   gGstatsKeySecPauthr   0x021A58DC  data
 *   gGstatsKeySecGetpidr   0x021A58E8  data
 *   gGstatsKeySecGetpdr   0x021A58F4  data
 *   gGstatsKeySecSetpdr   0x021A5900  data
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern int func_020949F4(const u8 *s1, const u8 *s2, u32 n);
extern void ProcessPlayerAuth();
extern void ProcessGetPid();
extern void ProcessGetData();
extern void ProcessSetData();
extern char gGstatsKeySecPauthr[];
extern char gGstatsKeySecGetpidr[];
extern char gGstatsKeySecGetpdr[];
extern char gGstatsKeySecSetpdr[];

void ProcessStatement(char *buff, int len)
{
    buff[len] = 0;
    if (func_020949F4((const u8 *)buff, (const u8 *)gGstatsKeySecPauthr, 8) == 0)
        ProcessPlayerAuth(buff, len);
    else if (func_020949F4((const u8 *)buff, (const u8 *)gGstatsKeySecGetpidr, 9) == 0)
        ProcessGetPid(buff, len);
    else if (func_020949F4((const u8 *)buff, (const u8 *)gGstatsKeySecGetpidr, 9) == 0)
        ProcessGetPid(buff, len);
    else if (func_020949F4((const u8 *)buff, (const u8 *)gGstatsKeySecGetpdr, 8) == 0)
        ProcessGetData(buff, len);
    else if (func_020949F4((const u8 *)buff, (const u8 *)gGstatsKeySecSetpdr, 8) == 0)
        ProcessSetData(buff, len);
}
