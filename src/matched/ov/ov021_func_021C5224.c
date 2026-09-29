/*
 * function: func_021C5224
 * address:  0x021C5224
 * packet:   pkt_ov021_021C5224
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C5334 0x021C5334 thumb ov021
 *   func_020061E4 0x020061E4 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_021C59BC 0x021C59BC thumb ov021
 *   func_02030EAC 0x02030EAC arm
 *   func_021C553C 0x021C553C thumb ov021
 *   func_021C5768 0x021C5768 thumb ov021
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02040618 0x02040618 arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021C5334(char *p);
extern void func_020061E4(u32 se);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern void func_021C59BC(void);
extern void func_02030EAC(void *p);
extern void func_021C553C(char *p);
extern int func_021C5768(char *p);
extern void func_0204B3DC(u32 obj, int on);
extern void func_02040618(int a, int b, int c);

void func_021C5224(char *p)
{
    int r;
    int i;

    if (func_021C5334(p) == 0) {
        return;
    }
    switch (*(u16 *)(p + 0x70)) {
    case 0:
        break;
    case 1:
        func_020061E4(0x54C);
        *(u16 *)(p + 0x72) = 0;
        *(u32 *)(p + 0x80) = 0;
        *(void **)(p + 0x84) = func_020056A0((void *)func_021C59BC, p, 0);
        *(u16 *)(p + 0x70) = 2;
        break;
    case 2:
        if (*(u32 *)(p + 0x80) != 0) {
            func_02030EAC(*(void **)(p + 0x84));
            *(u16 *)(p + 0x70) = 3;
        }
        break;
    case 3:
        func_021C553C(p);
        r = func_021C5768(p);
        switch (r) {
        case -1:
            *(u32 *)(p + 0x74) = 0;
            break;
        case -2:
            *(u32 *)(p + 0x74) = 2;
            break;
        default:
            *(u32 *)(p + 0x74) = 1;
            *(int *)(p + 0x78) = r;
            break;
        }
        break;
    case 4:
        for (i = 0; i < 3; i++) {
            func_0204B3DC(*(u32 *)(p + 0x58 + i * 4), 0);
        }
        *(u16 *)(p + 0x72) = 4;
        *(u16 *)(p + 0x70) = 5;
        break;
    case 5:
        func_02040618(1, 3, *(u16 *)(p + 0x72) * 0xC0 / 4 - 0xC0);
        if ((*(u16 *)(p + 0x72))-- == 0) {
            *(u16 *)(p + 0x70) = 0;
        }
        break;
    }
}
