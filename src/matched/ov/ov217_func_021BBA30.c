/*
 * function: func_021BBA30
 * address: 0x021BBA30
 * packet: pkt_ov217_021BBA30
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arity: BC400 forwards entry r0 into BC3F8, so retain supplied argument despite legacy void. BC3EC overwrites r1 with 24 and tail-calls signed division; legacy trailing a1 neither read nor forwarded.
 * symbols:
 *   func_021BC3D4 0x021BC3D4 thumb ov217
 *   func_021BC3E0 0x021BC3E0 thumb ov217
 *   func_021BC3F8 0x021BC3F8 thumb ov217
 *   func_021BC400 0x021BC400 thumb ov217
 *   func_021BC3EC 0x021BC3EC thumb ov217
 *   func_021BBAA4 0x021BBAA4 thumb ov217
 *   func_021BBD38 0x021BBD38 thumb ov217
 */
typedef unsigned char u8;
extern unsigned func_021BC3D4(void);
extern unsigned func_021BC3E0(void);
extern unsigned func_021BC3F8(unsigned);
extern unsigned func_021BC400(unsigned);
extern int func_021BC3EC(unsigned);
extern unsigned func_021BBAA4(unsigned, u8);
extern void func_021BBD38(void *, u8);
void func_021BBA30(u8 *p)
{
    int low, high, left, right;
    u8 index;
    low = func_021BC3D4();
    high = func_021BC3E0();
    left = func_021BC3F8(p[0x32]);
    right = func_021BC400(p[0x32]);
    if (right <= low) {
        index = func_021BC3EC(right + 1);
        if (*(unsigned *)(p + 0x160)) func_021BBAA4((unsigned)p, index);
        else func_021BBD38(p, index);
    }
    if (high <= left) {
        index = func_021BC3EC(left - 1);
        if (*(unsigned *)(p + 0x160)) func_021BBAA4((unsigned)p, index);
        else func_021BBD38(p, index);
    }
}
