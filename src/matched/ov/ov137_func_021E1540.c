/*
 * function: func_021E1540
 * address: 0x021E1540
 * packet: pkt_ov137_021E1540
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DFF20 0x021DFF20 thumb ov137
 *   func_020307B0 0x020307B0 arm
 *   func_02030EAC 0x02030EAC arm
 */
typedef unsigned char  u8;
struct Node;
extern void func_021DFF20(u8 *p, int a);
extern void func_020307B0(void *);
extern void func_02030EAC(struct Node *n);
void func_021E1540(void *task, int *p)
{
    int done = 0;
    if (p[1] == 1) {
        p[2]--;
        if (p[2] <= 0) {
            p[2] = 0;
            done = 1;
        }
    } else {
        p[2]++;
        if (p[2] >= 8) {
            p[2] = 8;
            done = 1;
        }
    }
    func_021DFF20((void *)p[0], p[2]);
    if (done == 1) {
        func_020307B0(p);
        func_02030EAC(task);
    }
}
