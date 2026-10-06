/*
 * function: func_021DC170
 * address:  0x021DC170
 * packet:   pkt_ov093_021DC170
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C7F68  0x021C7F68  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021D85C0  0x021D85C0  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../include/Obj06259.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D775C(int);
struct Unk021D62A8;
extern int func_021C8010(u8 *p, unsigned int v);
extern u8 func_021C7F68(int *p, int b, u8 *out);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern int func_021D85C0(int a, u32 b);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *, void *);
void func_021DC170(int a, void *b, int c)
{
    u8 buf[4];
    u8 n;
    u8 i;
    u8 *p;
    int two = 2;

    if (c == func_021D775C(2)) {
        n = func_021C7F68(b, (u16)((two << 9) | func_021C8010(b, c)), buf);
        for (i = 0; i < n; i++) {
            if (buf[i] != c) {
                if (func_021D62A8(func_021C7CF4(b, buf[i])) && func_021D85C0((int)b, 0x1e)) {
                    p = func_021C88A4(b, 0xb, c);
                    ((struct Obj06259 *)p)->f0 |= 2 << 22;
                    ((struct Obj06259 *)p)->f0 |= 2 << 24;
                    p[0x14] = 1;
                    p[8] = buf[i];
                    ((struct Obj06259 *)p)->f4 = 0x24;
                    func_021C88C8(b, p);
                }
            }
        }
    }
}
