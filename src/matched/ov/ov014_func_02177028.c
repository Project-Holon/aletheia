/*
 * function: func_02177028
 * address:  0x02177028
 * packet:   pkt_ov014_02177028
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   sDevWirelessWork     0x021797A0  data   a4
 *   sFileNetDevWireless     0x0217976C  data   a1
 *   func_02030734  0x02030734  arm
 *   func_0203D798  0x0203D798  arm
 *   func_02177280  0x02177280  thumb  ov014
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 *sDevWirelessWork;
extern char sFileNetDevWireless[];
typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 *func_0203D798(void);
extern int func_02177280(int a, int b, u32 c, int d);

int func_02177028(int a, u32 b, int c, int d)
{
    int ok;
    u32 *p;

    if (sDevWirelessWork != 0)
        return 0;
    p = func_02030734(a, 8, 1, sFileNetDevWireless, 0xb4);
    ok = 1;
    sDevWirelessWork = p;
    *p = b;
    if (func_0203D798()[0x65] != 5)
        ok = 0;
    return func_02177280(a, c, d, ok);
}
