/*
 * unit: yes
 * function: func_021E1320, func_021E13A8
 * address: 0x021E1320
 * packet: pkt_ov137_021E1320
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: 021E13A8 tail-forwards r1 and r1+0xC88 to this callback.
 * symbols:
 *   func_021DFEA0 0x021DFEA0 thumb ov137
 *   func_021DFEAC 0x021DFEAC thumb ov137
 *   func_021DFEB8 0x021DFEB8 thumb ov137
 *   func_020061E4 0x020061E4 thumb
 */
typedef unsigned short u16;
typedef struct { u16 state, flag; int count; } State;
extern void func_021DFEA0(void *);
extern void func_021DFEAC(void *);
extern void func_021DFEB8(void *);
extern void func_020061E4(int);
void func_021E1320(void *task, State *p)
{
    switch (p->state) {
    case 0: break;
    case 1:
        func_021DFEA0(task);
        func_020061E4(1832);
        p->count = 0;
        p->state++;
    case 2:
        p->count++;
        if (p->count >= 2) {
            p->count = 0;
            p->state++;
            func_021DFEB8(task);
        }
        break;
    case 3:
        p->count++;
        if (p->count >= 4) {
            func_021DFEA0(task);
            p->count = 0;
            p->state++;
        }
        break;
    case 4:
        p->count++;
        if (p->count >= 2) {
            func_021DFEAC(task);
            p->flag = 0;
            p->state = 0;
        }
        break;
    }
}
void func_021E13A8(void *unused, char *p)
{
    func_021E1320(p, (State *)(p + 0xc88));
}
