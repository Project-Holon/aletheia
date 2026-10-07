/*
 * file:     btlv_effvm_p53.c
 * unit:     yes
 * function: func_021FDB20, func_021FDB40, func_021FDBB0
 * address:  0x021FDB20
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021FF16C  0x021FF16C  thumb  ov094
 *   func_021FF1B0  0x021FF1B0  thumb  ov094
 *   func_020061E4  0x020061E4  thumb
 *   func_02006148  0x02006148  thumb
 *   func_0200616C  0x0200616C  thumb
 *   func_02006138  0x02006138  thumb
 *   func_02006268  0x02006268  thumb
 *   func_02072F34  0x02072F34  arm
 *   func_02073058  0x02073058  arm
 *   func_02073078  0x02073078  arm
 *   func_021FFF0C 0x021FFF0C thumb ov094
 *   func_021FFF38 0x021FFF38 thumb ov094
 *   func_021FFF68 0x021FFF68 thumb ov094
 *   func_021FFFAC 0x021FFFAC thumb ov094
 *   func_021FF348 0x021FF348 thumb ov094
 *   func_021F8730 0x021F8730 thumb ov094
 *   func_021F8710 0x021F8710 thumb ov094
 *   func_021F8740 0x021F8740 thumb ov094
 */
struct Obj;
typedef struct {
    char pad[0x244];
    int f244;
} State_021FDB20;

typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct {
    unsigned int pad0:13;
    unsigned int f13:1;
    unsigned int pad14:1;
    unsigned int f15:1;
    unsigned int pad16:16;
    int f4;
    char pad8[0xd4];
    int dc, e0;
    char pade4[0x164];
    u8 b248, b249, b24a, b24b;
    int f24c, f250;
    u16 f254;
    char pad256[0x2e];
    int f284;
    char pad288[0x18];
    int f2a0;
} State_021FDBB0;

extern int func_021F8694(void);
extern void func_021FF16C(void *w);
extern void func_021FF1B0(void *w);
extern void func_020061E4(u32 a);
extern int func_02006148(u32 a);
extern void func_0200616C(void *arg, int i);
extern u32 *func_02006138(int i);
extern void func_02006268(int i, u32 a, u32 b, u32 c);
extern void func_02072F34(char *p, unsigned int v);
extern void func_02073058(struct Obj *o, u32 v, u32 w);
extern void func_02073078(struct Obj *o, u32 v, u32 w);
extern int func_021FFF0C(char *p, int key);
extern int func_021FFF38(char *p, int key);
extern int func_021FFF68(void *, int);
extern int func_021FFFAC(void *, int);
extern int func_021FF348(void *, int);
extern int func_021F8730(void);
extern int func_021F8710(void);
extern unsigned short func_021F8740(int a);
void func_021FDB20(State_021FDB20 *s);
void func_021FDB40(u32 a0, int m, int a2, int a3, unsigned int e, unsigned int f, unsigned int g);
int func_021FDBB0(State_021FDBB0 *s, unsigned int key);


void func_021FDB20(State_021FDB20 *s)
{
    if (s->f244 == 1)
        func_021FF1B0((void *)func_021F8694());
    else
        func_021FF16C((void *)func_021F8694());
}


void func_021FDB40(u32 a0, int m, int a2, int a3, unsigned int e, unsigned int f, unsigned int g)
{
    if (m == 5) {
        func_020061E4(a0);
        m = func_02006148(a0);
    } else {
        func_0200616C((void *)a0, m);
    }
    func_02072F34((char *)func_02006138(m), e);
    func_02006268(m, -1, -1, a2);
    func_02006268(m, -1, a3, -1);
    if (f) {
        func_02073058((struct Obj *)func_02006138(m), 0xffff, f);
        func_02073078((struct Obj *)func_02006138(m), 0xffff, g);
    }
}

/*
 * leaves: parent-cleared ov094 getters 0x021F8730 and 0x021F8740 filed separately.
 * domain: selector values 0..57; out-of-range result is unspecified.
 */
int func_021FDBB0(State_021FDBB0 *s, unsigned int key)
{
    switch (key) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
        return func_021FFF0C((char *)func_021F8694(), key);
    case 8: return func_021FFF0C((char *)func_021F8694(), s->dc);
    case 9: return s->b248;
    case 10: return s->b249;
    case 11: return s->b24a;
    case 12: return s->b24b;
    case 13: return s->f24c;
    case 14: return s->f250;
    case 15: return s->f254;
    case 16: return s->f4;
    case 17: return s->dc;
    case 18: return func_021FF348((void *)func_021F8694(), s->dc);
    case 19: return s->dc & 1;
    case 20: case 21: case 22: case 23: case 24: case 25: case 26: case 27:
        if (func_021FFF38((char *)func_021F8694(), key - 20) & 2)
            return 1;
        return 0;
    case 28:
        if (func_021FFF38((char *)func_021F8694(), s->dc) & 2)
            return 1;
        return 0;
    case 29: case 30: case 31: case 32: case 33: case 34: case 35: case 36:
        return func_021FFF68((void *)func_021F8694(), key - 29);
    case 37: return func_021FFF68((void *)func_021F8694(), s->dc);
    case 38: return func_021F8730();
    case 39: return func_021F8710();
    case 40: case 41: case 42: case 43: return func_021F8740(key - 40);
    case 44: case 45: case 46: case 47: case 48: case 49: case 50: case 51:
        return func_021FFFAC((void *)func_021F8694(), key - 44);
    case 52: return func_021FFFAC((void *)func_021F8694(), s->dc);
    case 53: return s->f13;
    case 54: return s->f284;
    case 55: return s->f2a0;
    case 56: return s->f15;
    case 57: return s->e0;
    }
}
