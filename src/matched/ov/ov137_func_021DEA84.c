/*
 * function: func_021DEA84
 * address: 0x021DEA84
 * packet: pkt_ov137_021DEA84
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02039338 0x02039338 arm
 */
typedef unsigned char u8;
extern int func_020221A4(void);
extern int func_02039338(void);
extern void *func_0202EE30(void *, void *, int, int, int);
int func_021DEA84(u8 *p)
{
    if (func_020221A4()) {
        *(int *)p = func_02039338() == 0 ? 2 : 8;
        *(void **)(p + 0xda8) = func_0202EE30(*(void **)(p + 0xd98), *(void **)(p + 0xcf0), 15, 16, 114);
        return 1;
    }
    return 0;
}
