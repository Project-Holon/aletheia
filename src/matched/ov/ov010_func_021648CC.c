/*
 * function: CALENDER_GetDayOfYear
 * address:  0x021648CC
 * packet:   pkt_ov010_021648CC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sums the first n entries of a 13-byte days-per-month table, plus k - 1.
 *
 * symbols:
 *   DaysPerMonthTable  0x02171C20  data  ov010  a1
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u8 b[13]; } Days;
extern const Days DaysPerMonthTable;

u16 CALENDER_GetDayOfYear(int n, int k)
{
    Days t = DaysPerMonthTable;
    int i;
    u16 s = 0;
    for (i = 0; i < n; i++) {
        s = s + t.b[i];
    }
    return s + (u16)(k - 1);
}
