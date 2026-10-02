/*
 * function: func_021BB2B4
 * address: 0x021BB2B4
 * packet: pkt_ov217_021BB2B4
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   func_021BB91C 0x021BB91C thumb ov217
 *   func_021BB910 0x021BB910 thumb ov217
 *   func_021BBA00 0x021BBA00 thumb ov217
 *   func_021BC5A8 0x021BC5A8 thumb ov217
 *   func_021BC580 0x021BC580 thumb ov217
 *   func_021BB934 0x021BB934 thumb ov217
 *   func_021BC6D0 0x021BC6D0 thumb ov217
 *   func_020362DC 0x020362DC arm
 *   func_02035C08 0x02035C08 arm
 *   func_020061E4 0x020061E4 thumb
 */
typedef unsigned int u32;
extern u32 func_020362DC(void);
extern int func_02035C08(void *p);
extern void func_020061E4(int id);
extern void func_021BB91C(void *p);
extern void func_021BB910(void *p, int v);
extern void func_021BBA00(void *p, int v);
extern void func_021BC5A8(void *p, int v);
extern void func_021BC580(void *p, int v);
extern void func_021BB934(void *p, int v);
extern int func_021BC6D0(void *p);

void func_021BB2B4(char *p)
{
    u32 keys = func_020362DC();
    int st = func_02035C08(p + 0x58);
    if ((keys & 0x40) || (keys & 0x80) || (keys & 0x20) || (keys & 0x10) || (keys & 1)) {
        func_021BB91C(p);
        func_021BB910(p, 9);
        return;
    }
    if (st == 0) {
        func_021BBA00(p, 0);
        func_021BC5A8(p, 3);
        func_021BC580(p, 5);
        func_021BB934(p, 1);
        func_021BB91C(p);
        func_021BB910(p, 12);
        return;
    }
    if (func_021BC6D0(p) != 0 || (keys & 2) || st == 1) {
        func_021BBA00(p, 1);
        func_021BC5A8(p, 3);
        func_021BC580(p, 5);
        func_020061E4(0x551);
        func_021BB91C(p);
        func_021BB910(p, 11);
        func_021BB910(p, 2);
    }
}
