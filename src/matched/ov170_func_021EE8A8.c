/*
 * function: func_021EE8A8
 * address:  0x021EE8A8
 * packet:   pkt_ov170_021EE8A8
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020260E0 0x020260E0 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_02025DE8 0x02025DE8 thumb
 *   func_021EF5E8 0x021EF5E8 thumb
 *   func_021EE408 0x021EE408 thumb
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 */

extern unsigned char func_020260E0(void *obj);
extern void func_020260E4(void *obj, unsigned char sel);
extern unsigned func_02025DE8(void *obj);
extern int func_021EF5E8(int p);
extern void func_021EE408(char *p, int v);
extern unsigned func_020362DC(void);
extern void func_020355D8(int v);

#define WORK(p) (*(char **)((p) + 0x2C))

unsigned func_021EE8A8(char *p)
{
    unsigned char sel = func_020260E0(*(void **)(WORK(p) + 0x70));
    unsigned r = func_02025DE8(*(void **)(WORK(p) + 0x70));

    if (func_021EF5E8(*(int *)(WORK(p) + 0x74)) == 0) {
        if (r >= 9 && r <= 14) {
            func_020260E4(*(void **)(WORK(p) + 0x70), sel);
            func_021EE408(p, sel);
            return -1;
        }
        if (func_020362DC() & 0x400) {
            func_020355D8(0);
            return 7;
        }
        if (r == 7) {
            func_020355D8(1);
            return 7;
        }
        if (r == 8) {
            func_020260E4(*(void **)(WORK(p) + 0x70), sel);
            return 8;
        }
    } else if (r - 6 <= 2) {
        func_020260E4(*(void **)(WORK(p) + 0x70), sel);
        func_021EE408(p, sel);
        return -1;
    }
    return r;
}
