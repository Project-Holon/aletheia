/*
 * function: func_021AED30
 * address:  0x021AED30
 * packet:   pkt_ov013_021AED30
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B2180  0x021B2180  arm  ov013
 *   func_021B0614  0x021B0614  arm  ov013
 *   func_021B1F54  0x021B1F54  arm  ov013
 *   func_021AEDEC  0x021AEDEC  thumb  ov013
 *   d_021B3C80     0x021B3C80  data  ov013
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct W {
    u8 pad0[0x19A8];
    u32 f19A8;
    u32 f19AC;
    u8 pad1[0x1A1C - 0x19B0];
    u32 f1A1C;
};

extern struct W *d_021B3C80;

struct Node;
extern int func_021B2180(int a, int b);
extern int func_021B0614(void *p);
extern int func_021B1F54(struct Node *p);
extern void func_021AEDEC(void *p);

void func_021AED30(int a, int code, u32 *p)
{
    switch (code) {
    case 1:
        if (d_021B3C80->f1A1C != 0) {
            func_021B2180((int)p, 3);
            func_021B1F54((struct Node *)p);
            return;
        }
        d_021B3C80->f1A1C = (u32)p;
        return;
    case 8:
        func_021B2180((int)p, 0);
        func_021AEDEC(p);
        return;
    case 9:
        func_021AEDEC(p);
        return;
    case 4:
        func_021B2180((int)p, 4);
        func_021AEDEC(p);
        return;
    case 7:
        if (*p != d_021B3C80->f19A8) {
            func_021AEDEC(p);
            return;
        }
        if (func_021B0614(p) != 0) {
            d_021B3C80->f19AC = 2;
            return;
        }
        break;
    case 2:
        func_021AEDEC(p);
        return;
    case 3:
    case 11:
    case 12:
        func_021AEDEC(p);
        break;
    }
}
