/*
 * file:     btlv_effvm_p52.c
 * unit:     yes
 * function: func_021FD8CC, func_021FD9F0, func_021FDA28, func_021FDB08
 * address:  0x021FD8CC
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
 *   func_02051A34  0x02051A34  arm
 *   func_0207BC08  0x0207BC08  arm
 *   func_021FE1B8  0x021FE1B8  thumb  ov094
 *   func_02051838  0x02051838  arm
 *   d_020A1B38  0x020A1B38  data
 *   _ll_mul  0x0209C054  arm
 *   func_02051774  0x02051774  arm
 *   func_0205189C  0x0205189C  arm
 *   func_02051A2C  0x02051A2C  arm
 *   func_02051A24  0x02051A24  arm
 *   func_02051640  0x02051640  arm
 *   func_02050DB8  0x02050DB8  arm
 *   func_020307B0  0x020307B0  arm
 */
#define MUL(a,b) ((int)(((long long)(a) * (b) + 0x800) >> 12))
struct Obj;
typedef signed short s16;

typedef unsigned short u16;

typedef struct { int x, y, z; } VecFx32;

typedef struct {
    char pad00[0x0c];
    int k0c;                /* 0x0c */
    char pad10[0x2c];
    int k3c;                /* 0x3c */
} State;

typedef unsigned int   u32;

typedef unsigned char  u8;

extern int func_02051A34(void *p);
extern void func_0207BC08(const VecFx32 *a, const void *b, VecFx32 *out);
extern void func_02051838(void *p, const VecFx32 *v);
extern void func_021FE1B8(VecFx32 *v, const VecFx32 *ofs);
extern unsigned int func_02051774(void);
extern void func_0205189C(struct Obj *o, u32 v);
extern void func_02051A2C(void *p, int v);
extern void func_02051A24(void *p, int v);
extern void *func_02051640(char *p);
extern void func_02050DB8(u8 *p);
extern u32 func_020307B0(void *p);
void func_021FD8CC(void *p, int active);
void func_021FD9F0(void *p);
void func_021FDA28(void *p, int active);
void func_021FDB08(void *p);
extern const s16 d_020A1B38[];

/*
 * The 5 and default arms are separate `else if` / `else` blocks with the
 * whole MUL repeated; the compiler cross-jumps their common tail, and the
 * 0 high word of the rounding addend stays CSE'd in r4 across all three
 * arms (a ternary index colours it differently).
 * Caller func_021FD1CC (same lane) shows s is a 0x60 object: 3x3 matrix,
 * pos at 0x24, counters from 0x30.
 */
void func_021FD8CC(void *p, int active)
{
    VecFx32 v;
    u16 a;
    u16 b;
    int *s;

    s = (int *)func_02051A34(p);
    if (s[18] == 0 || active == 0)
        return;
    if (s[19] == 3) {
        if (s[20] != 0) {
            s[20]--;
            return;
        }
        s[22] += 0xc;
        s[21] += s[22];
        s[20] = s[21] >> 12;
    }
    s[18]--;
    s[14] += s[16];
    s[15] += s[17];
    a = (s[14] >> 12) + 0xc000;
    b = (s[15] >> 12) + 0xc000;
    v.x = d_020A1B38[(a >> 4) * 2];
    v.x = MUL(v.x, s[12]);
    v.x += s[12];
    if (s[19] == 6) {
        v.z = d_020A1B38[(b >> 4) * 2 + 1];
        v.z = MUL(v.z, s[13]);
        v.y = 0;
    } else if (s[19] == 5) {
        v.y = d_020A1B38[(b >> 4) * 2 + 1];
        v.y = MUL(v.y, s[13]);
        v.z = 0;
    } else {
        v.y = d_020A1B38[(a >> 4) * 2 + 1];
        v.y = MUL(v.y, s[13]);
        v.z = 0;
    }
    func_0207BC08(&v, s, &v);
    if (s[23] != 0)
        func_021FE1B8(&v, 0);
    func_02051838(p, &v);
}


void func_021FD9F0(void *p)
{
    State *s = (State *)func_02051774();

    if (s->k3c != 0 && s->k0c < 0)
        func_0205189C(p, 0x800);
    func_02051A2C(p, (int)s);
    func_02051A24(p, (int)func_021FDA28);
}

void func_021FDA28(void *p, int active)
{
    int *s;
    VecFx32 v;
    s = (int *)func_02051A34(p);
    if (active == 0)
        return;
    if (s[13] == 0) {
        if (s[10] == 0) {
            s[10] = s[11];
            if (s[0] & 1)
                s[6] -= s[7];
            else
                s[6] += s[7];
            s[6] = (u16)s[6];
            v.x = d_020A1B38[(s[6] >> 4) * 2];
            v.x = MUL(v.x, s[4]);
            v.x += s[1];
            v.y = s[2];
            v.z = d_020A1B38[(s[6] >> 4) * 2 + 1];
            v.z = MUL(v.z, s[5]);
            v.z += s[3];
            if (s[15] != 0)
                func_021FE1B8(&v, 0);
            func_02051838(p, &v);
            if (s[8] != 0) {
                s[8]--;
            } else {
                s[8] = s[9];
                s[13] = s[14];
            }
        } else {
            s[10]--;
        }
    } else {
        s[13]--;
    }
}


void func_021FDB08(void *p)
{
    void *q = func_02051640(p);

    func_02050DB8(p);
    func_020307B0(q);
}
