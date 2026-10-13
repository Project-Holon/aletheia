/*
 * file:     unit_021E7DB0.c
 * unit:     yes
 * function: func_021E7DB0, func_021E7E00, func_021E7E0C, func_021E7E4C
 * address:  0x021E7DB0
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
 *   func_0689D098  0x0689D098  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C812C  0x021C812C  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   func_021C8138  0x021C8138  thumb  ov093
 *   BTLV_CORE_EventScaleDamage  0x021E8860  thumb  ov093
 *   BTLV_CORE_MakeSlotKind2Index  0x021E8940  thumb  ov093
 *   func_021B9A40  0x021B9A40  thumb  ov093
 *   func_021E556C  0x021E556C  thumb  ov093
 *   func_021E3C5C  0x021E3C5C  thumb  ov093
 *   d_021F2DB8     0x021F2DB8  data   ov093  a4
 *   d_021F26CC     0x021F26CC  data    a4
 */
struct Q7;
struct QQ;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Word { u32 v; } Word;

extern int BTL_EVENT_GetVar(int key);
extern u8 *func_021C812C(u8 *p);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern u16 func_021C8138(struct Q7 *p);
extern u32 func_0689D098(int a, int b, int c);
extern void BTLV_CORE_EventScaleDamage(int n);
extern Word BTLV_CORE_MakeSlotKind2Index(int v);
extern unsigned char func_021B9A40(unsigned int x);
extern void func_021E556C(int a, int b, int c, int d, int e, int f, Word g, int h);
extern void func_021E3C5C(void *a, int b, int c);
void func_021E7DB0(void *a, void *b, int c);
int *func_021E7E00(int *p);
void func_021E7E0C(int a, int b, int c, int d);
int *func_021E7E4C(int *p);
extern int d_021F2DB8[];
extern int d_021F26CC[];


void func_021E7DB0(void *a, void *b, int c)
{
    int x;
    u16 y;
    if (c == BTL_EVENT_GetVar(3)) {
        x = (int)func_021C812C((u8 *)((int)b));
        y = BTL_EVENT_GetFactorKey(a);
        if (func_0689D098(x, y, func_021C8138(b)) > 1)
            BTLV_CORE_EventScaleDamage(2);
    }
}


int *func_021E7E00(int *p)
{
    *p = 4;
    return d_021F2DB8;
}


void func_021E7E0C(int a, int b, int c, int d)
{
    Word t = BTLV_CORE_MakeSlotKind2Index(1);
    int e = func_021B9A40(c);
    func_021E556C(a, b, c, d, e, 10, t, 0xa2);
    func_021E3C5C((void *)b, c, 1);
}


int *func_021E7E4C(int *p)
{
    *p = 1;
    return d_021F26CC;
}
