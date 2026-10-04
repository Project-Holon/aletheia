/*
 * function: func_02184148
 * address: 0x02184148
 * packet: pkt_ov022_02184148
 * region: ov022
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203CD98 0x0203CD98 arm
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1E8 0x0203D1E8 arm
 */
extern int func_0203CD98(void);
struct Entry;
extern struct Entry *func_020399A8(void);
typedef unsigned int   u32;
extern void func_0203D1E8(u32 unused, void *arg);
void func_02184148(unsigned char *p, int a)
{
    if (func_0203CD98()) {
        func_0203D1E8((int)func_020399A8(), (void *)1);
        p[9] = 2;
        p[11] = a;
        p[10] = 0;
    }
}
