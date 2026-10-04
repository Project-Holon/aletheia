/*
 * function: func_022059A0
 * address: 0x022059A0
 * packet: pkt_ov195_022059A0
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware 04000050/04001050 writes and 04000000/04001000 read/write at 022059C2-022059DC.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_02205C48 0x02205C48 thumb ov195
 *   func_02205BAC 0x02205BAC thumb ov195
 *   func_02205B24 0x02205B24 thumb ov195
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj24952.h"
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_02205C48(int *);
extern void func_02205BAC(char *);
extern void func_02205B24(void *);
extern void func_0201DD68(void);
extern void func_02082BCC(void *, int, int);
extern void func_020307B0(void *);
void func_022059A0(char *p)
{
    func_02030EAC(((struct Obj24952 *)p)->fC);
    func_02205C48((int *)(p + 8));
    func_02205BAC(p + 4);
    func_02205B24(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_02082BCC(p, 0, 0x10);
    func_020307B0(p);
}
