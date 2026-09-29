/*
 * unit:     yes
 * function: func_021E281C, func_021E288C
 * address:  0x021E281C
 * packet:   pkt_ov093_021E281C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D6940  0x021D6940  thumb  ov093
 *   func_021E8860  0x021E8860  thumb  ov093
 *   d_021F26AC     0x021F26AC  data   ov093  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern int func_021D775C(int key);
extern void *func_021C7CF4(void *a, int b);
extern int func_021D6940(void *m, int a, int b, u16 *out);
extern void func_021E8860(int n);
extern int d_021F26AC[];

void func_021E281C(int a, void *b, int c)
{
    void *v;
    u8 t;
    u8 j;
    u16 buf[4];

    if (c == func_021D775C(3)) {
        v = func_021C7CF4(b, c);
        t = func_021D775C(4);
        j = 0;
        while (func_021D6940(v, 0, j++, buf) != 0) {
            if (((u8 *)buf)[5] == t && buf[1] != 0) {
                func_021E8860(2);
                return;
            }
        }
    }
}

int *func_021E288C(int *p)
{
    *p = 1;
    return d_021F26AC;
}
