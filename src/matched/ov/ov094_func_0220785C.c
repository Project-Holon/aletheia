/*
 * function: func_0220785C
 * address: 0x0220785C
 * packet: pkt_ov094_0220785C
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02207F6C 0x02207F6C thumb ov094
 *   func_022082FC 0x022082FC thumb ov094
 *   func_022080F4 0x022080F4 thumb ov094
 *   func_02208268 0x02208268 thumb ov094
 *   func_02208420 0x02208420 thumb ov094
 *   func_02208550 0x02208550 thumb ov094
 *   func_021F8720 0x021F8720 thumb ov094
 *   func_02208650 0x02208650 thumb ov094
 *   func_021F86D4 0x021F86D4 thumb ov094
 *   func_02208B10 0x02208B10 thumb ov094
 *   func_02030DA8 0x02030DA8 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct E {
    void *f00;
    char p04[0x0c];
    void *f10;
    char p14[0x30];
    int f44, f48, f4c, f50, f54, f58, f5c, f60, f64;
    char p68[8];
    u32 lo : 3;
    u32 b3 : 1;
    u32 mid : 12;
    u32 mode : 4;
    u32 hi : 12;
    char p74[8];
    void *f7c;
} E;
typedef struct O { char pad[0x40]; E e[8]; } O;
typedef unsigned char  u8;
extern int func_02207F6C(int n, int target, int delta, int *cur, u8 x, int speed);
extern void func_022082FC(O *, int, int);
extern void func_022080F4(O *, E *, void *);
extern void func_02208268(O *, E *);
extern void func_02208420(O *, E *, int);
extern void func_02208550(O *, E *);
extern int func_021F8720(void);
extern void func_02208650(O *, E *);
extern void *func_021F86D4(void);
extern void func_02208B10(void *, void *);
extern void *func_02030DA8(void *, void (*)(void *, void *), void *, u32);
void func_0220785C(O *o, int unused, int idx, void *data)
{
    func_02207F6C(o->e[idx].f4c, o->e[idx].f48, 0, &o->e[idx].f50, 6, 1);
    func_022082FC(o, idx, 0);
    if (o->e[idx].f10 != 0) {
        func_02207F6C(o->e[idx].f58, o->e[idx].f54, 0, &o->e[idx].f64, 10, 1);
        func_022082FC(o, idx, 1);
    }
    func_022080F4(o, &o->e[idx], data);
    func_02208268(o, &o->e[idx]);
    func_02208420(o, &o->e[idx], o->e[idx].f48);
    func_02208550(o, &o->e[idx]);
    if (o->e[idx].f44 != 0 && func_021F8720() == 0)
        func_02208650(o, &o->e[idx]);
    o->e[idx].b3 = 1;
    o->e[idx].mode = 2;
    o->e[idx].f7c = func_02030DA8(func_021F86D4(), func_02208B10, &o->e[idx], 0);
}
