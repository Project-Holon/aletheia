/*
 * function: func_021A5F38
 * address:  0x021A5F38
 * packet:   pkt_ov021_021A5F38
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02197E7C  0x02197E7C  thumb
 *   func_0216D410  0x0216D410  thumb
 *   func_021A3964  0x021A3964  thumb
 *   func_021A6C6C  0x021A6C6C  thumb
 *   func_020061E4  0x020061E4  thumb
 */

typedef unsigned short u16;

typedef struct {
    int f0;
    int pad[4];
    unsigned char *f14;
} S;

extern int func_02197E7C(int a, int b);
extern void func_0216D410(void *p, int a);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021A3964(u8 *p, u32 v);

extern int func_021A6C6C(u8 *p, u32 k);
extern void func_020061E4(u32 a);

void func_021A5F38(S *a, void *b, int c, int d, u16 e)
{
    func_0216D410(b, func_02197E7C(e, 0x1c));
    a->f0 = 3;
    func_021A3964(a->f14, 0);
    if (func_021A6C6C((u8 *)a, e) == 0) {
        func_020061E4(0x55a);
    }
}
