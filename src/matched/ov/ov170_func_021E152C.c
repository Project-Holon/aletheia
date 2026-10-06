/*
 * function: func_021E152C
 * address:  0x021E152C
 * packet:   pkt_ov170_021E152C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DD210 0x021DD210 thumb
 *   func_021EC35C 0x021EC35C thumb
 *   func_021DEDCC 0x021DEDCC thumb
 *   func_021DEC98 0x021DEC98 thumb
 *   func_021ED544 0x021ED544 thumb
 *   func_021DEA4C 0x021DEA4C thumb
 *   func_021E00C4 0x021E00C4 thumb
 *   func_021E0128 0x021E0128 thumb
 *   func_021DEB08 0x021DEB08 thumb ov170
 *   func_020061E4 0x020061E4 thumb
 *   func_021ED108 0x021ED108 thumb
 *   func_021EBFA8 0x021EBFA8 thumb
 *   func_021EBFEC 0x021EBFEC thumb
 *   func_021EC000 0x021EC000 thumb
 */

typedef struct {
    unsigned char pad[0xC];
    unsigned short state;
} Blk;

extern int func_021DD210(unsigned char *p, unsigned a, unsigned b);
extern void func_021EC35C(char **p, int box);
extern int func_021DEDCC(char *p, int box);
extern void func_021DEC98(char *p, void *a, int dir);
extern void func_021ED544(char *p, int b);
extern void func_021DEA4C(char *p, int a, int b);
extern int func_021E00C4(char *p);
extern int func_021E0128(char *p);
extern int func_021DEB08(unsigned char *p);
extern void func_020061E4(unsigned se);
extern void func_021ED108(char *p, int on);
extern void func_021EBFA8(char *p, int i, int v);
typedef unsigned int   u32;
extern u32 func_021EBFEC(char *p, int i);
extern void func_021EC000(char *p, int i, int v);

#define WORK(p) (*(char **)((p) + 0x2C))

int func_021E152C(unsigned char *p)
{
    Blk *b = (Blk *)(WORK(p) + 0x58);
    switch (b->state) {
    case 0:
        if (p[0x17] != 0xFF && p[0x17] != p[0x14]) {
            int dir = func_021DD210(p, p[0x14], p[0x17]);
            p[0x14] = p[0x17];
            func_021EC35C((char **)p, p[0x14]);
            func_021DEC98((char *)p, (void *)func_021DEDCC((char *)p, p[0x14]), dir);
            if (dir == 0)
                b->state = 2;
            else
                b->state = 3;
            break;
        }
    case 1:
        func_021ED544((char *)p, 7);
        func_021DEA4C((char *)p, *(unsigned short *)(WORK(p) + 0xA16E), 2);
        b->state = 4;
        break;
    case 2:
        if (func_021E00C4((char *)p) == 0)
            b->state = 1;
        break;
    case 3:
        if (func_021E0128((char *)p) == 0)
            b->state = 1;
        break;
    case 4:
        if (func_021DEB08(p) == 0) {
            func_020061E4(0x667);
            b->state = 5;
        }
        break;
    case 5:
        func_021ED108(WORK(p), 1);
        func_021EBFA8(WORK(p), 10, 2);
        b->state = 6;
        break;
    case 6:
        if (func_021EBFEC(WORK(p), 10) == 0) {
            func_021ED108(WORK(p), 0);
            func_021EC000(WORK(p), 10, 0);
            b->state = 7;
        }
        break;
    case 7:
        func_021ED544((char *)p, 6);
        b->state = 0;
        return 0;
    }
    return 1;
}
