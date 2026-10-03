/*
 * function: func_021A6BB4
 * address:  0x021A6BB4
 * packet:   pkt_ov021_021A6BB4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    u8 on : 1;
    u8 keep : 1;
    u8 flag : 1;
    u8 st : 5;
    u8 pad;
    s16 cnt;
    u32 val;
} St;

extern int func_0216D3CC(int a0);

void func_021A6BB4(St *p, u32 a1, u32 a2)
{
    if (p->on) {
        if (p->st != 0) {
            if (a1 != 9) {
                p->cnt = 0;
                p->st = 0;
                if (p->keep)
                    p->val = a1;
            }
        } else if (a1 == 9) {
            if (p->cnt < 30)
                p->cnt = p->cnt + 1;
            else
                p->st = 1;
        }
        if (func_0216D3CC(a2) == 1) {
            if (p->st == 0) {
                p->keep = 0;
                p->flag = 0;
            } else {
                p->keep = 1;
                p->flag = 1;
            }
        }
    }
}
