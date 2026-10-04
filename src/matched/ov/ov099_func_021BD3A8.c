/*
 * function: func_021BD3A8
 * address:  0x021BD3A8
 * packet:   pkt_ov099_021BD3A8
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0200AE54  0x0200AE54  thumb
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *   func_021BC090  0x021BC090  thumb  ov099
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern unsigned int func_02039CB4(struct Link *h, unsigned int a, unsigned int b);
struct Reg;
extern u32 func_0200AE54(struct Reg *p, u32 id);
extern void func_021BAAB8(char *p, int a, int b);
extern void func_021BC090(char *p);

int func_021BD3A8(char *p, int v)
{
    int a;
    int b;
    int id;

    if (func_02039CB4((struct Link *)func_020399A8(), 0x11, 0xA) != 0) {
        a = func_0200AE54((struct Reg *)(*(int *)(p + 0x1348)), 2);
        b = func_0200AE54((struct Reg *)(*(int *)(p + 0x1348)), 3);
        if (a == 3 && b == 3) {
            id = 0x92;
        } else if (a == 4 && b == 4) {
            id = 0x93;
        } else if (a == 6 && b == 6) {
            id = 0x94;
        } else {
            id = 0x91;
        }
        func_021BAAB8(p, id, 0);
        func_021BC090(p);
        *(u32 *)(p + 0x1E0) = 0x78;
        *(u32 *)(p + 0x1CC) = 0x69;
    }
    return v;
}
