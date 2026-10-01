/*
 * function: func_021E121C
 * address: 0x021E121C
 * packet: pkt_ov137_021E121C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E203C 0x021E203C data a4
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B8D4 0x0204B8D4 arm
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02030EAC 0x02030EAC arm
 */
typedef unsigned int u32;
typedef struct { int v[4]; } Table;
struct Actor;
extern const Table d_021E203C;
extern void func_020061E4(int);
extern void func_0204B8D4(struct Actor *, int);
extern u32 func_0204B98C(struct Actor *);
extern void func_0204B3B4(struct Actor *);
extern void func_020307B0(void *);
extern void func_02030EAC(void *);
void func_021E121C(void *task, int *p)
{
    switch (p[0]) {
    case 0:
        if (p[3] < 4) {
            Table sounds = d_021E203C;
            p[1]--;
            if (p[1] <= 0) {
                p[1] = 30;
                func_020061E4(sounds.v[p[3]]);
                p[3]++;
            }
        }
        func_0204B8D4((struct Actor *)p[5], 0x1800);
        if (func_0204B98C((struct Actor *)p[5]) == 0) p[0]++;
        break;
    case 1:
        func_0204B3B4((struct Actor *)p[5]);
        func_020307B0(p);
        func_02030EAC(task);
        break;
    }
}
