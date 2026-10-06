/*
 * function: func_021E1458
 * address:  0x021E1458
 * packet:   pkt_ov170_021E1458
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ED544 0x021ED544 thumb
 *   func_021EC0B0 0x021EC0B0 thumb
 *   func_021EC08C 0x021EC08C thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021ED108 0x021ED108 thumb
 *   func_021EBFA8 0x021EBFA8 thumb
 *   func_021EBFEC 0x021EBFEC thumb
 *   func_021EC000 0x021EC000 thumb
 */

typedef struct {
    unsigned char pad[0xC];
    unsigned short state;
    unsigned short cnt;
} Blk;

extern void func_021ED544(char *p, int b);
extern void func_021EC0B0(char *p, int i, short *a, short *b, unsigned short space);
extern void func_021EC08C(char *p, int i, int a, int b, unsigned short c);
extern void func_020061E4(unsigned se);
extern void func_021ED108(char *p, int on);
extern void func_021EBFA8(char *p, int i, int v);
extern int func_021EBFEC(char *p, int i);
extern void func_021EC000(char *p, int i, int v);

#define WORK(p) (*(char **)((p) + 0x2C))

int func_021E1458(char *p)
{
    Blk *b = (Blk *)(WORK(p) + 0x58);
    short t[2];
    switch (b->state) {
    case 0:
        func_021ED544(p, 7);
        b->state = 1;
    case 1:
        if (b->cnt == 4) {
            b->cnt = 0;
            b->state = 2;
            break;
        }
        func_021EC0B0(WORK(p), 10, &t[1], &t[0], 0);
        func_021EC08C(WORK(p), 10, (short)t[1], (short)(t[0] + 2), (short)0);
        b->cnt++;
        break;
    case 2:
        func_020061E4(0x667);
        func_021ED544(p, 6);
        func_021ED108(WORK(p), 1);
        func_021EBFA8(WORK(p), 10, 2);
        b->state = 3;
        break;
    case 3:
        if (func_021EBFEC(WORK(p), 10) == 0) {
            func_021ED108(WORK(p), 0);
            func_021EC000(WORK(p), 10, 0);
            b->state = 4;
        }
        break;
    case 4:
        func_021ED544(p, 6);
        b->state = 0;
        return 0;
    }
    return 1;
}
