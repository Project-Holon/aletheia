/*
 * function: func_021C4E0C
 * address:  0x021C4E0C
 * packet:   pkt_ov111_021C4E0C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * blocker:  case 0 register choice: the original keeps the 0x305C address in r1 and derives 0x304C and 0x3050 from it, then pools 0x303C; 17 bytes out, see docs/notes/pkt_ov111_021C4E0C.c.txt
 *
 * symbols:
 *   func_021C4B74  0x021C4B74  thumb
 *   func_021C4D48  0x021C4D48  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 heap;
    u8 pad2[0x3034 - 2];
    int f3034;
    u8 pad3038[0x303C - 0x3038];
    int f303C;
    int f3040;
    u8 pad3044[0x304C - 0x3044];
    int f304C;
    int f3050;
    u8 pad3054[0x305C - 0x3054];
    u16 f305C;
    u16 f305E;
    u8 pad3060[0x32C6 - 0x3060];
    u8 seq;
    u8 pad32C7[3];
    u8 f32CA_0 : 1;
    u8 f32CA_1 : 1;
    u8 f32CA_2 : 1;
} Work;

extern void func_021C4B74(Work *p, int flag);
extern void func_021C4D48(int side);

int func_021C4E0C(Work *p)
{
    switch (p->seq) {
    case 0:
        if (p->f305C == 0) {
            p->f304C = 0x20;
        } else {
            p->f304C = 0xE0;
        }
        p->f3050 = 0x98;
        p->f303C = 0x103D;
        p->f3040 = 0x103D;
        p->seq = 1;
        break;
    case 1:
        p->f303C += 0x100;
        p->f3040 += 0x100;
        if (p->f303C >= 0x2000) {
            p->f303C = 0x2000;
            p->f3040 = 0x2000;
            p->seq = 2;
        }
        break;
    case 2:
        p->f305E = 1;
        func_021C4B74(p, p->f3034);
        func_021C4D48(p->f305C);
        return 1;
    case 3:
        p->seq = 4;
        break;
    case 4:
        p->f303C -= 0x100;
        p->f3040 -= 0x100;
        if (p->f303C <= 0x1000) {
            p->f303C = 0x1000;
            p->f3040 = 0x1000;
            p->seq = 5;
        }
        break;
    case 5:
        p->f304C = 0x80;
        p->f3050 = 0x60;
        p->f305E = 0;
        func_021C4B74(p, p->f3034);
        func_021C4D48(-1);
        return 1;
    case 6:
        p->seq = 7;
        break;
    case 7:
        p->f304C -= 8;
        if (p->f304C < 0x20) {
            p->f304C = 0x20;
            p->seq = 8;
        }
        break;
    case 8:
        p->f305C ^= 1;
        func_021C4D48(p->f305C);
        return 1;
    case 9:
        p->seq = 10;
        break;
    case 10:
        p->f304C += 8;
        if (p->f304C > 0xE0) {
            p->f304C = 0xE0;
            p->seq = 11;
        }
        break;
    case 11:
        p->f305C ^= 1;
        func_021C4D48(p->f305C);
        return 1;
    }
    p->f32CA_2 = 1;
    return 0;
}
