/*
 * function: func_021EE96C
 * address:  0x021EE96C
 * packet:   pkt_ov170_021EE96C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02025DE8 0x02025DE8 thumb
 *   func_020362DC 0x020362DC arm
 *   func_0203633C 0x0203633C arm
 *   func_021DD238 0x021DD238 thumb
 */

typedef unsigned int u32;


struct Sound;
extern int func_02025DE8(struct Sound *obj);
extern u32 func_020362DC(void);
extern unsigned int func_0203633C(void);
extern void func_021DD238(char *p);

unsigned func_021EE96C(char *p)
{
    unsigned r = func_02025DE8(*(void **)(*(char **)(p + 0x2C) + 0x70));
    if (r == -1) {
        if (func_020362DC() & 0x800) {
            func_021DD238(p);
            return 0x28;
        }
        if (func_0203633C() & 0x200) {
            func_021DD238(p);
            return 0x25;
        }
        if (func_0203633C() & 0x100) {
            func_021DD238(p);
            return 0x26;
        }
    }
    return r;
}
