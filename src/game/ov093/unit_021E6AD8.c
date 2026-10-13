/*
 * file:     unit_021E6AD8.c
 * unit:     yes
 * function: func_021E6AD8, func_021E6B14, func_021E6B20, func_021E6BAC, func_021E6BE8, func_021E6BF4, func_021E6CD0, func_021E6CDC
 * address:  0x021E6AD8
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
 *   func_0689CA3C  0x0689CA3C  thumb
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C8174   0x021C8174  thumb
 *   func_021C8030   0x021C8030  thumb
 *   d_021F2928     0x021F2928  data   ov093  a4
 *   func_021C7FCC 0x021C7FCC thumb ov093
 *   func_021C8120 0x021C8120 thumb ov093
 *   func_021B9B94 0x021B9B94 thumb ov093
 *   func_021B9C00 0x021B9C00 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D5448 0x021D5448 thumb ov093
 *   func_021D54C0 0x021D54C0 thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 *   d_021F270C     0x021F270C  data   ov093  a4
 *   func_0689CA1C  0x0689CA1C  thumb
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   d_021F2BB8     0x021F2BB8  data   ov093  a4
 */
struct S;
struct Q1;
struct QG;
struct S2;
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int key);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 val);
extern int func_021D76BC(int key, u32 val);
extern int func_021C8174(int *p);
extern int func_021C8030(int a, int b, int c);
extern char *func_021C7FCC(u8 *p, int i);
extern u8 *func_021C8120(u8 *p, int b);
extern u8 func_021B9B94(struct Q1 *p);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern u8 func_021D5440(u8 *p);
extern u8 func_021D5448(struct QG *p);
extern u16 func_021D54C0(u8 *p, int i);
extern int func_0689CA3C(u16);
extern u32 func_021D78AC(u32);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_0689CA1C(int e);
extern int WAZA_TOOL_GetFlag(int bag, int item);
void func_021E6AD8(int x, int a, int c);
int *func_021E6B14(int *p);
void func_021E6B20(int x, int a, int b);
void func_021E6BAC(int x, int a, int c);
int *func_021E6BE8(int *p);
void func_021E6BF4(void *x, void *a, int c);
int *func_021E6CD0(int *p);
void func_021E6CDC(int x, int a, int c, u32 *d);
extern int d_021F2928[];
extern int d_021F270C[];
extern int d_021F2BB8[];



void func_021E6AD8(int x, int a, int c)
{
    void *p;
    u16 id;

    if (c == func_021D775C(2)) {
        p = (void *)func_021D775C(0x3f);
        id = func_021D775C(0x12);
        func_021C8838(p, 1, 0x78);
        func_021C8860(p, id);
        func_021D76BC(0x51, 1);
    }
}



int *func_021E6B14(int *p)
{
    *p = 2;
    return d_021F2928;
}



/*
 * 16-case jump table on func_021C8174(a), gated on b == func_021D775C(2);
 * every value 0..15 is covered by eight bodies sitting at 6B66, 6B6A, 6B6E,
 * 6B72, 6B76, 6B7A, 6B7E, 6B82 -- that is the order they are written in
 * below.  Each body picks a script id (0x192 and 0x1aa come out of the pool
 * because they do not fit a movs); the id goes to func_021C8030 and to
 * func_021D76BC(0x12,...), and func_021C8030's result to func_021D76BC(0xd,...).
 *
 * The `default:` label belongs on the case 4/14 group, not on a block of its
 * own: the `bhi` out-of-range arm of the table jumps to 6B6A, which is that
 * group's body, and the out-of-range arm being a real body is also what puts
 * the switch's temporary in r5 and the parameter a in r4 (mwcc allocates r4 to
 * the first web the dispatch block defines).  `default:` as a separate group
 * costs 40 bytes of diff; without it at all the `bhi` lands on the shared tail.
 */
void func_021E6B20(int x, int a, int b)
{
    int v;
    int r;

    if (func_021D775C(2) != b)
        return;
    switch (func_021C8174((int *)a)) {
    case 1: case 2: case 3: case 8: case 15:
        v = 0x59;
        break;
    case 4: case 14: default:
        v = 0xa1;
        break;
    case 10:
        v = 0x9d;
        break;
    case 0: case 5:
        v = 0x192;
        break;
    case 6: case 11: case 12:
        v = 0x38;
        break;
    case 9:
        v = 0x1aa;
        break;
    case 7:
        v = 0x3b;
        break;
    case 13:
        v = 0x3a;
        break;
    }
    r = func_021C8030(a, b, v);
    func_021D76BC(0x12, v);
    func_021D76BC(0xd, r);
}



void func_021E6BAC(int x, int a, int c)
{
    void *p;
    u16 id;

    if (c == func_021D775C(2)) {
        p = (void *)func_021D775C(0x3f);
        id = func_021D775C(0x12);
        func_021C8838(p, 1, 0x79);
        func_021C8860(p, id);
        func_021D76BC(0x51, 1);
    }
}



int *func_021E6BE8(int *p)
{
    *p = 1;
    return d_021F270C;
}



/*
 * lever: Both loop bounds and their accessor returns are u8; u32 n loses
 * its pre-loop reload, and u32 count schedules its reload before i's spill.
 */
void func_021E6BF4(void *x, void *a, int c)
{
    void *party;
    u16 *moves;
    u8 count;
    u8 i;
    u8 n;
    u8 used, j;
    void *mon;
    u16 move;
    u8 pick;
    int slot;
    if (c == func_021D775C(2)) {
        party = func_021C7FCC(a, c);
        moves = (u16 *)func_021C8120(a, 48);
        used = 0;
        count = func_021B9B94(party);
        for (i = 0; i < count; i++) {
            mon = func_021B9C00(party, i);
            if (c != func_021D5440(mon)) {
                n = func_021D5448(mon);
                for (j = 0; j < n; j++) {
                    move = func_021D54C0(mon, j);
                    if (func_0689CA3C(move) == 0) {
                        moves[used++] = move;
                    }
                }
            }
        }
        if (used != 0) {
            pick = func_021D78AC(used);
            slot = func_021C8030((int)a, c, moves[pick]);
            func_021D76BC(18, moves[pick]);
            func_021D76BC(13, slot);
        }
    }
}


int *func_021E6CD0(int *p)
{
    *p = 3;
    return d_021F2BB8;
}


void func_021E6CDC(int x, int a, int c, u32 *d)
{
    void *m;
    u8 n;
    u8 cnt;
    u8 i;
    int e;
    int t = 2;
    u16 id;
    int r;

    if (c == func_021D775C(2)) {
        m = func_021C7CF4((int *)a, c);
        if (func_021D62C4(m, t) != 0) {
            n = func_021D5448(m);
            i = 0;
            cnt = 0;
            for (; i < n; i++) {
                e = func_021D54C0(m, i);
                if (func_0689CA1C(e) == 0 && WAZA_TOOL_GetFlag(e, 1) == 0) {
                    d[cnt++] = e;
                }
            }
            if (cnt != 0) {
                id = d[(u8)func_021D78AC(cnt)];
                r = func_021C8030((int)a, c, id);
                func_021D76BC(0x12, id);
                func_021D76BC(0xd, r);
            } else {
                func_021D76BC(0x41, 1);
            }
        }
    }
}
