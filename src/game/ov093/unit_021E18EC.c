/*
 * file:     unit_021E18EC.c
 * unit:     yes
 * function: func_021E18EC, func_021E192C, func_021E1938, func_021E1948, func_021E1958, func_021E1970, func_021E197C, func_021E198C, func_021E199C, func_021E19B4, func_021E19C0, func_021E19D0, func_021E19E0, func_021E19F8, func_021E1A2C, func_021E1AA4, func_021E1AE4, func_021E1B40
 * address:  0x021E18EC
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
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D69AC  0x021D69AC  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   d_021F2C00     0x021F2C00  data   ov093  a4
 *   d_021F2C18     0x021F2C18  data   ov093  a4
 *   d_021F2C30     0x021F2C30  data   ov093  a4
 *   func_021C7D00  0x021C7D00  thumb  ov093
 *   func_021C7D44  0x021C7D44  thumb  ov093
 *   func_021C8030  0x021C8030  thumb  ov093
 *   func_021D7B10  0x021D7B10  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D6940  0x021D6940  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   d_021F25C4     0x021F25C4  data   ov093  a4
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u32 f0; u8 pad[60]; } E64;

typedef struct Ent { unsigned short a; unsigned short b; unsigned char c, d, e, f; } Ent;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern u8 func_021D69AC(u8 *a, int i);
extern int func_021D76BC(int key, u32 val);
extern int func_021C7D00(u8 *p, int b);
extern int func_021C7D44(char *p, int i);
extern int func_021C8030(u8 *p, int v, u16 k);
extern u32 func_021D7B10(u32 a, u32 b);
extern u8 func_021D5440(u8 *p);
extern int func_021D6940(const u8 *p, int i, u32 j, u16 *out);
extern int func_021B9A24(u32 a, u32 b);
extern int WAZA_TOOL_GetDamageType(int a);
void func_021E18EC(int a, void *p, int id);
int *func_021E192C(int *p);
void func_021E1938(int a, int b, int c, int d);
void func_021E1948(int a, void *b, int c, int d);
void func_021E1958(int a, void *b, int c, int d);
int *func_021E1970(int *p);
void func_021E197C(int a, int b, int c, int d);
void func_021E198C(int a, void *b, int c, int d);
void func_021E199C(int a, void *b, int c, int d);
int *func_021E19B4(int *p);
void func_021E19C0(int a, int b, int c, int d);
void func_021E19D0(int a, void *b, int c, int d);
void func_021E19E0(int a, void *b, int c, int d);
void func_021E19F8(int a, int b, int c, int d);
void func_021E1A2C(void *p, int id, int u, int x);
void func_021E1AA4(void *p, int id, int u, int x, int arg);
int func_021E1AE4(void *m, int x, Ent *out);
int *func_021E1B40(int *p);
/* 021E1938  shifted 4-arg wrapper -> func_021E19F8(..., 0x1) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; adds r2, r3, #0; movs r3, #1; bl func_021E19F8; pop {r3, pc}.
 */
extern int d_021F2C00[];
/* 021E197C  shifted 4-arg wrapper -> func_021E19F8(..., 0x2) */
extern int d_021F2C18[];
/* 021E19C0  shifted 4-arg wrapper -> func_021E19F8(..., 0x0) */
extern int d_021F2C30[];
extern int d_021F25C4[];





void func_021E18EC(int a, void *p, int id)
{
    int two = 2;
    int v;
    if (id == func_021D775C(2)) {
        switch (func_021D69AC(func_021C7CF4(p, id), 0)) {
        case 1:
        default:
            v = 1 << 10;
            break;
        case 2:
            v = two << 10;
            break;
        case 3:
            v = two << 11;
            break;
        }
        func_021D76BC(0x35, v);
    }
}





int *func_021E192C(int *p)
{
    *p = 3;
    return d_021F2C00;
}





void func_021E1938(int a, int b, int c, int d)
{
    func_021E19F8(b, c, d, 0x1);
}







/* 021E1948  shifted 4-arg wrapper -> func_021E1A2C(..., 0x1) */
void func_021E1948(int a, void *b, int c, int d)
{
    func_021E1A2C(b, c, d, 0x1);
}






/*
 * Wrapper family member; the body is the hand-checked shape of the family's first instance with only the member's constants substituted, per the family uniformity assertion in o36/report.md.
 */
void func_021E1958(int a, void *b, int c, int d)
{
    func_021E1AA4(b, c, d, 1, 2 << 12);
}




int *func_021E1970(int *p)
{
    *p = 3;
    return d_021F2C18;
}




void func_021E197C(int a, int b, int c, int d)
{
    func_021E19F8(b, c, d, 0x2);
}






/* 021E198C  shifted 4-arg wrapper -> func_021E1A2C(..., 0x2) */
void func_021E198C(int a, void *b, int c, int d)
{
    func_021E1A2C(b, c, d, 0x2);
}






void func_021E199C(int a, void *b, int c, int d)
{
    func_021E1AA4(b, c, d, 2, 2 << 12);
}



int *func_021E19B4(int *p)
{
    *p = 3;
    return d_021F2C30;
}



void func_021E19C0(int a, int b, int c, int d)
{
    func_021E19F8(b, c, d, 0x0);
}





/* 021E19D0  shifted 4-arg wrapper -> func_021E1A2C(..., 0x0) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; adds r2, r3, #0; movs r3, #0; bl func_021E1A2C; pop {r3, pc}.
 */
void func_021E19D0(int a, void *b, int c, int d)
{
    func_021E1A2C(b, c, d, 0x0);
}





void func_021E19E0(int a, void *b, int c, int d)
{
    func_021E1AA4(b, c, d, 0, 6 << 10);
}




void func_021E19F8(int a, int b, int c, int d)
{
    Ent e;

    if (b == func_021D775C(2) && func_021E1AE4(func_021C7CF4((int *)a, b), d, &e) == 0)
        func_021D76BC(34, 26);
}



void func_021E1A2C(void *p, int id, int u, int x)
{
    Ent e;
    int t;
    int r;
    if (id == func_021D775C(3)) {
        if (func_021E1AE4(func_021C7CF4(p, id), x, &e)) {
            t = e.d;
            if (func_021C7D00(p, t) == 6) {
                r = e.e;
                t = 0x1f;
                if (r != 6)
                    t = func_021C7D44(p, r);
                if (t == 0x1f) {
                    r = func_021C8030(p, id, 1);
                    if (r != 6)
                        t = func_021C7D44(p, r);
                    if (t == 0x1f)
                        t = e.d;
                }
            }
            func_021D76BC(4, t);
        }
    }
}




void func_021E1AA4(void *p, int id, int u, int x, int arg)
{
    Ent e;
    if (id == func_021D775C(3)) {
        if (func_021E1AE4(func_021C7CF4(p, id), x, &e)) {
            func_021D76BC(0x37, func_021D7B10(e.b, arg));
        }
    }
}




int func_021E1AE4(void *m, int x, Ent *out)
{
    u8 q = func_021D5440(m);
    u8 i = 0;
    while (func_021D6940(m, 0, i++, (u16 *)out)) {
        if (func_021B9A24(q, out->d) == 0) {
            if (x == 0 || x == WAZA_TOOL_GetDamageType(out->a))
                return 1;
        }
    }
    return 0;
}


int *func_021E1B40(int *p)
{
    *p = 1;
    return d_021F25C4;
}
