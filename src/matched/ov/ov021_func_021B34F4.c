/*
 * function: func_021B34F4
 * address:  0x021B34F4
 * packet:   pkt_ov021_021B34F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B34F4 0x021B34F4 thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201CE5C 0x0201CE5C thumb
 *   func_0203630C 0x0203630C arm
 *   func_020362DC 0x020362DC arm
 *   func_0201CE38 0x0201CE38 thumb
 *   func_020061E4 0x020061E4 thumb
 */

typedef unsigned char u8;

extern int func_0201CE30(void *);
extern void func_0201CE48(void *);
extern void func_0201CE5C(void *, int);
extern int func_0203630C(void);
extern int func_020362DC(void);
extern void func_0201CE38(void *);
extern void func_020061E4(int);

u8 func_021B34F4(u8 *p)
{
    int r = func_0201CE30(*(void **)(p + 440));

    if (r == 2) {
        func_0201CE48(*(void **)(p + 440));
        return p[1];
    }
    if (r == 0) {
        if ((func_0203630C() & 1) || (func_0203630C() & 2)) {
            func_0201CE5C(*(void **)(p + 440), 0);
        }
    } else if (r == 1) {
        if ((func_020362DC() & 1) || (func_020362DC() & 2)) {
            func_0201CE38(*(void **)(p + 440));
            func_020061E4(1351);
        }
    }
    return p[0];
}
