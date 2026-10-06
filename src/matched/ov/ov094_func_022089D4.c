/*
 * function: func_022089D4
 * address: 0x022089D4
 * packet: pkt_ov094_022089D4
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02005E50 0x02005E50 thumb
 *   func_02005E9C 0x02005E9C thumb
 *   func_021F882C 0x021F882C thumb ov094
 *   func_02005D90 0x02005D90 thumb
 *   func_02208D24 0x02208D24 thumb ov094
 *   func_02005DF8 0x02005DF8 thumb
 *   func_02005E64 0x02005E64 thumb
 *   func_0202D034 0x0202D034 thumb
 *   func_02005C44 0x02005C44 thumb
 *   func_02005E30 0x02005E30 thumb
 */
typedef unsigned int u32;
typedef struct { char p0[0x40]; int f40, f44, f48, f4c; char p50[0x20]; u32 b0:1, b1:1, b2:1, b3:1, hi:28; char p74[12]; } E;
typedef struct { char p0[0x40]; E e[8]; u32 b0:1, b1:1, b2:1, b3:1, hi:28; int f444; } O;
extern int func_02005E50(void);
extern void func_02005E9C(void);
extern int func_021F882C(void);
extern void func_02005D90(u32, u32);
extern void func_02208D24(int);
extern void func_02005DF8(u32);
extern int func_02005E64(void);
typedef unsigned short u16;
extern int func_0202D034(u32 a, u32 b);
extern u16 func_02005C44(void);
extern void func_02005E30(u32);
void func_022089D4(O *o)
{
    int busy, found, i;
    if (o->b1) {
        if (func_02005E50() != 0) return;
        o->b1 = 0;
        if (o->b2) {
            func_02005E9C();
            if (!o->b3 && func_021F882C() != 0) {
                func_02005D90(o->f444, 0xffff);
                o->b3 = 1;
            } else {
                func_02208D24(0);
            }
            func_02005DF8(24);
        } else {
            func_02208D24(1);
            func_02005E64();
            func_02005D90(0x47a, 0xffff);
        }
        o->b2 ^= 1;
        return;
    }
    busy = 0;
    found = 0;
    for (i = 0; i < 8; i++) {
        if (o->e[i].b0 || o->e[i].b1 || o->e[i].b2) {
            busy = 1;
        } else if (o->e[i].f44 == 0 && o->e[i].b3 && o->e[i].f40 != 4) {
            if (func_0202D034(o->e[i].f48, o->e[i].f4c) == 2) found = 1;
        }
    }
    if (!o->b2 && o->f444 != func_02005C44()) return;
    if (busy != 0) return;
    if ((o->b2 && found == 0) || (!o->b2 && found == 1)) {
        o->b1 = 1;
        func_02005E30(8);
    }
}
