/*
 * file:     unit_021E700C.c
 * unit:     yes
 * function: func_021E700C, func_021E7040, func_021E704C, func_021E7074, func_021E7080, func_021E70E4, func_021E7158
 * address:  0x021E700C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   BTLV_CORE_EventScaleDamage  0x021E8860  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   d_021F268C     0x021F268C  data   ov093  a4
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   d_021F2404     0x021F2404  data  ov093  a1
 *   d_021F2654     0x021F2654  data  ov093  a4
 *   func_021C83A0  0x021C83A0  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   d_021F267C     0x021F267C  data   ov093  a4
 *   d_021F245C     0x021F245C  data   ov093  a4
 */
struct Unk021D62A8;
struct QI;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p);
extern void BTLV_CORE_EventScaleDamage(int a);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern int func_021D59B4(u8 *p, int k);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern u32 func_021C83A0(u8 *p, int i);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
void func_021E700C(int x, int a, int c);
int *func_021E7040(int *p);
void func_021E704C(int a, void *b, int c);
int *func_021E7074(int *p);
void func_021E7080(int x, int a, int c);
int *func_021E70D8(int *p);
void func_021E70E4(int x, int a, int c);
int *func_021E7158(int *p);
extern int d_021F268C[];
extern const u8 d_021F2404[7];
extern int d_021F2654[];
/*
 * note:     the bonus is a compound add onto the fetched value
 *           (`t = get(0x30); t += sum * 0x14; set(0x30, t);`): it copies sum
 *           into r1 and multiplies by 0x14 held in r0 like the image; every
 *           single-expression spelling (`t + sum * 0x14`, an inline helper,
 *           a narrow or enum multiplier local) multiplies in the constant's
 *           register and is 4 bytes short.  func_021E70D8 is the unlabelled
 *           12-byte store-and-return leaf after the pool (twin of
 *           ov093_func_021E7164.c's func_021E71D8).
 */
extern int d_021F267C[];
extern int d_021F245C[];



void func_021E700C(int x, int a, int c)
{
    if (c == BTL_EVENT_GetVar(3)) {
        if (BTL_POKEPARAM_GetMajorStatusIndex(func_021C7CF4((int *)a, (u8)BTL_EVENT_GetVar(4))) != 0) {
            BTLV_CORE_EventScaleDamage(2);
        }
    }
}



int *func_021E7040(int *p)
{
    *p = 1;
    return d_021F268C;
}



void func_021E704C(int a, void *b, int c)
{
    if (c == BTL_EVENT_GetVar(3)) {
        if (BTL_POKEPARAM_GetItem(func_021C7CF4(b, c)) == 0)
            BTLV_CORE_EventScaleDamage(2);
    }
}


int *func_021E7074(int *p)
{
    *p = 1;
    return d_021F267C;
}


void func_021E7080(int x, int a, int c)
{
    void *m;
    int sum;
    u32 i;
    int v;
    int t;

    if (c == BTL_EVENT_GetVar(3)) {
        m = func_021C7CF4((int *)a, c);
        sum = 0;
        for (i = 0; i < 7; i++) {
            v = func_021D59B4(m, d_021F2404[i]) - 6;
            if (v > 0) {
                sum += v;
            }
        }
        if (sum != 0) {
            t = BTL_EVENT_GetVar(0x30);
            t += sum * 0x14;
            BTL_EVENT_OverwriteVar(0x30, t);
        }
    }
}



int *func_021E70D8(int *p)
{
    *p = 1;
    return d_021F2654;
}



void func_021E70E4(int x, int a, int c)
{
    void *m;
    int p;
    int q;
    int r;
    int v;

    if (c == BTL_EVENT_GetVar(3)) {
        func_021C7CF4((int *)a, c);
        m = func_021C7CF4((int *)a, (u8)BTL_EVENT_GetVar(4));
        p = func_021C83A0((u8 *)a, c);
        q = func_021C83A0((u8 *)a, BTL_POKEPARAM_GetPokeId(m));
        r = p / q;
        if (r >= 5) {
            v = 0x78;
        } else if (r == 4) {
            v = 0x64;
        } else if (r == 3) {
            v = 0x50;
        } else {
            v = 0x3c;
            if (r != 2) {
                v = 0x28;
            }
        }
        BTL_EVENT_OverwriteVar(0x30, v);
    }
}


int *func_021E7158(int *p)
{
    *p = 1;
    return d_021F245C;
}
