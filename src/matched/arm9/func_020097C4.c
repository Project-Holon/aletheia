/*
 * function: WIFILIST_Create
 * address:  0x020097C4
 * packet:   pkt_020097C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   sWifilistFile      0x020A7198  data
 */

extern char sWifilistFile[];
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02009800(void *p);

void *WIFILIST_Create(int a0)
{
    void *p = func_02030734((unsigned short)a0, 0x7c4, 1, sWifilistFile, 0x39);
    func_02009800(p);
    return p;
}
