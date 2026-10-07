/*
 * file:     weather_task_p06.c
 * unit:     yes
 * function: func_021A2050, func_021A20C8
 * address:  0x021A2050
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
 *   func_021A273C  0x021A273C  thumb  ov021
 *   func_021A2724  0x021A2724  thumb  ov021
 *   func_021A2924  0x021A2924  thumb  ov021
 *   func_021A28A0  0x021A28A0  thumb  ov021
 *   func_021A284C  0x021A284C  thumb  ov021
 *   func_021A26D8  0x021A26D8  thumb  ov021
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct O_021A2050 {
    u32 pad0[9];
    u8  lo : 4;
    u8  hi : 4;
    u8  f25;
    u8  f26;
} O_021A2050;

typedef struct O_021A20C8 {
    u32 pad0[8];
    u32 *f20;
    u8  pad24[2];
    u8  f26;
} O_021A20C8;

extern u8 func_021A273C(u8 *p);
extern void func_021A2724(O_021A20C8 *p, u32 v, int z);
extern void func_021A2924(O_021A20C8 *p);
extern void func_021A28A0(O_021A20C8 *p);
extern void func_021A284C(O_021A20C8 *p);
extern void func_021A26D8(int *p);
void func_021A2050(O_021A2050 *p, u32 a, u32 b);
void func_021A20C8(O_021A20C8 *p);


/*
 * Addresses are Black-image addresses.
 */
void func_021A2050(O_021A2050 *p, u32 a, u32 b)
{
    u32 r;
    u32 s;

    r = func_021A273C((u8 *)p);
    s = p->f26;
    if (s == 0) {
        return;
    }
    if (r - 4 <= 1) {
        return;
    }
    p->hi = (u8)a;
    p->lo = (u8)b;
    if (s <= 5) {
        p->f26 = 0xb;
        return;
    }
    if (p->hi != 0) {
        p->f26 = 9;
        return;
    }
    p->f26 = 0xb;
}


void func_021A20C8(O_021A20C8 *p)
{
    if (p->f26 == 0) {
        return;
    }
    if (p->f26 <= 0xb) {
        func_021A2724(p, p->f20[0x11], 0);
    }
    if (p->f26 <= 0xc) {
        func_021A2924(p);
        func_021A28A0(p);
        func_021A284C(p);
    }
    func_021A26D8((int *)p);
}
