/*
 * file:     weather_task_p13.c
 * unit:     yes
 * function: func_021A26D8, func_021A2724, func_021A273C, func_021A274C
 * address:  0x021A26D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   data_021D88E8  0x021D88E8  data  a1
 *   func_021A2BC4  0x021A2BC4  thumb  ov021
 */
typedef unsigned char u8;

typedef struct {
    u8 pad[0x24];
    u8 lo : 4;
    u8 hi : 4;
} Obj021A2724;

typedef struct {
    u8 data[0x38];
} Slot021A274C;

typedef struct {
    u8 pad[0x74];
    Slot021A274C slots[0x20];
} Obj021A274C;

void func_02082BCC(void *p, int v, int n);
void func_021A26D8(int *p);
int func_021A2724(Obj021A2724 *p, int (*cb)(Obj021A2724 *, int, int), int x);
u8 func_021A273C(u8 *p);
Slot021A274C *func_021A274C(Obj021A274C *p);
extern const u8 data_021D88E8[];


void func_021A26D8(int *p)
{
    int f0;
    int f4;
    int f10;
    int f8;
    int f18;
    int f14;
    int fc;
    unsigned short h;

    f0 = p[0];
    f4 = p[1];
    f14 = p[5];
    f10 = p[4];
    fc = p[3];
    f8 = p[2];
    h = *(unsigned short *)&p[7];
    f18 = p[6];
    func_02082BCC(p, 0, 0x784);
    p[5] = f14;
    p[0] = f0;
    p[3] = fc;
    p[1] = f4;
    *(unsigned short *)&p[7] = h;
    p[2] = f8;
    p[6] = f18;
    p[4] = f10;
}


int func_021A2724(Obj021A2724 *p, int (*cb)(Obj021A2724 *, int, int), int x)
{
    if (cb != 0)
        return cb(p, p->lo, x);
    return 1;
}


u8 func_021A273C(u8 *p)
{
    return data_021D88E8[p[0x26]];
}


Slot021A274C *func_021A274C(Obj021A274C *p)
{
    int i;
    for (i = 0; i < 0x20; i++) {
        if (func_021A2BC4((Slot021A274C *)((u8 *)p + 0x74) + i) == 0) {
            p = (Obj021A274C *)((u8 *)p + 0x74);
            return (Slot021A274C *)p + i;
        }
    }
    return 0;
}
