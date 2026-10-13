/*
 * function: EVENTDATA_SYSTEM_Create
 * address:  0x0216237C
 * packet:   pkt_ov010_0216237C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   d_0217299C     0x0217299C  data  ov010  a1
 */

typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern char d_0217299C[];

int EVENTDATA_SYSTEM_Create(int a)
{
    void **p = (void **)func_02030734(a, 0xAA8, 1, d_0217299C, 0xAF);
    p[1] = func_020490F4(0x7D, a);
    p[2] = func_020490F4(0x7E, a);
    p[3] = func_020490F4(0x39, a);
    return (int)p;
}
