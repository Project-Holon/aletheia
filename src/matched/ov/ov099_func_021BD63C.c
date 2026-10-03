/*
 * function: func_021BD63C
 * address: 0x021BD63C
 * packet: pkt_ov099_021BD63C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021BA928(void *);
struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_02039CB4(void *, u32, u32);
int func_021BD63C(char *p, int v)
{
    int state;
    func_021BA928(p);
    if (func_02039CB4(func_020399A8(), 0x1a, 10) != 0) {
        state = *(u8 *)(p + 0x1357);
        if (state != 0) *(u32 *)(p + 0x1cc) = state;
        else *(u32 *)(p + 0x1cc) = 0x15;
        *(u8 *)(p + 0x1357) = 0;
    }
    return v;
}
