/*
 * unit: yes
 * function: func_021892F8,func_021893AC,func_021893B4,func_021893CC,func_021893D4
 * address: 0x021892F8
 * packet: pkt_ov096_021892F8
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Extent contains four followers at 021893AC, 021893B4, 021893CC, 021893D4.
 * Followers have 6,22,6,6 code bytes with 2 zero alignment bytes each.
 * Lever: bind each comparison's call result before comparing, per existing cmp idiom.
 * Caller-visible return overrides the tail-forwarder's void declaration.
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_0218A160 0x0218A160 thumb ov096
 *   func_0218A378 0x0218A378 thumb ov096
 *   func_0218A0F4 0x0218A0F4 thumb ov096
 *   func_021D5448 0x021D5448 thumb ov093
 *   func_021D54C0 0x021D54C0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 pad[0x4c]; u16 values[8]; u8 pad2[0xb0-0x5c]; int fb0, fb4, fb8; u8 *fbc; int fc0, fc4; } Obj;
extern unsigned int func_0201134C(int);
extern int func_0218A160(Obj *, int);
extern int func_0218A378(Obj *, int, int);
extern int func_0218A0F4(int, int, int, int, int);
extern int func_021D5448(void *);
extern int func_021D54C0(void *, u8);
int func_021892F8(int a, Obj *b, int c)
{
    int k, z, y, r, i, t;
    unsigned int value;
    k = func_0201134C(a);
    value = func_0201134C(a);
    z = func_0201134C(a);
    y = func_0218A160(b, k);
    r = 0;
    switch (k) {
    case 1:
        for (i = 0; i < func_021D5448(b->fbc); i++) {
            t = func_0218A378(b, func_021D54C0(b->fbc, i), 28);
            if (t == value) {
                r = 1;
                break;
            }
        }
        break;
    case 0:
        for (i = 0; i < 4; i++) {
            if (b->values[y * 4 + i] != 0) {
                t = func_0218A378(b, b->values[y * 4 + i], 28);
                if (t == value) {
                    r = 1;
                    break;
                }
            }
        }
        break;
    }
    return func_0218A0F4(a, c, r, 1, z);
}
int func_021893AC(int a, Obj *b) { return b->fc4; }
int func_021893B4(int a, Obj *b) {
    ((u8 *)b)[0x44] |= 2;
    return b->fc4;
}
int func_021893CC(int a, Obj *b) { return b->fc4; }
int func_021893D4(int a, Obj *b) { return b->fc4; }
