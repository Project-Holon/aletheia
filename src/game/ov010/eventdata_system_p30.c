/*
 * file:     eventdata_system_p30.c
 * unit:     yes
 * function: func_02163C9C, func_02163D04, func_02163E1C
 * address:  0x02163C9C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216D7E8  0x0216D7E8  thumb
 *   func_0216D660  0x0216D660  thumb
 *   func_0216D7F8  0x0216D7F8  thumb
 *   func_0216D66C  0x0216D66C  thumb
 *   func_0216DCB4  0x0216DCB4  thumb  ov010
 *   func_0216D91C  0x0216D91C  thumb  ov010
 *   func_0216D924  0x0216D924  thumb  ov010
 *   func_02163E34  0x02163E34  thumb  ov010
 *   func_021AB11C  0x021AB11C  thumb  ov021
 *   func_0216D7DC  0x0216D7DC  thumb  ov010
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   d_021714A0     0x021714A0  data
 *   d_02171490     0x02171490  data
 *   func_0216D67C 0x0216D67C thumb ov010
 *   func_0216D52C 0x0216D52C thumb ov010
 *   func_0218DAEC 0x0218DAEC thumb ov021
 */
typedef short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef int s32;

typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef int (*AttrTest)(u16 attr);

typedef struct { u16 a,b,c,d; int p,q; } E;

extern int func_0216D7E8(void *p);
extern int func_0216D660(void *p);
extern int func_0216D7F8(void *p);
extern int func_0216D66C(void *p);
extern int func_0216DCB4(void *m);
extern u8 func_0216D91C(int a0);
extern u8 func_0216D924(int a0);
extern int func_02163E34(void *m, VecFx32 *pos, u32 *attr);
extern int func_021AB11C(u32 attr);
extern u32 func_0216D7DC(void *m);
extern u16 func_021AB0F0(u32 attr);
extern void *func_0216D67C(void *);
extern u32 func_0216D52C(void *p);
extern int func_0218DAEC(char *, char *, E *);
int func_02163C9C(int a, int b, int c);
int func_02163D04(void *m, u32 kind, VecFx32 pos);
int func_02163E1C(void *a, char *b, E *c);
extern const AttrTest d_021714A0[];
extern const AttrTest d_02171490[];


int func_02163C9C(int a, int b, int c)
{
    int base;
    int d;
    int hi;
    int lo;

    base = func_0216D7E8((void *)a);
    d = func_0216D660((void *)a);
    if (d != -1) {
        hi = (s16)(base + d);
        lo = (s16)(base - d);
        if (lo > b || hi < b)
            return 1;
    }
    base = func_0216D7F8((void *)a);
    d = func_0216D66C((void *)a);
    if (d != -1) {
        hi = (s16)(base + d);
        lo = (s16)(base - d);
        if (lo > c || hi < c)
            return 1;
    }
    return 0;
}


/*
 * note: 2026-10-05 wave P8 lane W8. The older draft was DIFF 6 B (row copy src/dst r2/r3 swapped).
 *   Closed by writing the inner loop init as "for (j = 0, cur = row; ...)" (copy inside the for-init,
 *   after j = 0). All other spellings of the copy stayed DIFF 6 B.
 */
int func_02163D04(void *m, u32 kind, VecFx32 pos)
{
    int found;
    VecFx32 row;
    VecFx32 cur;
    u32 attr;
    u32 first;
    u8 i;
    u32 h;
    u8 j;
    u32 w;
    u16 a;

    if (func_0216DCB4(m) == 0) {
        found = 0;
        w = func_0216D91C((int)m);
        h = func_0216D924((int)m);
        row = pos;
        for (i = 0; i < h; i++, row.z -= 0x10000) {
            for (j = 0, cur = row; j < w; j++, cur.x += 0x10000) {
                if (func_02163E34(m, &cur, &attr) == 0)
                    return 1;
                if (func_021AB11C(attr) == 1)
                    return 1;
                if (found == 0) {
                    first = attr;
                    found = 1;
                }
            }
        }
        a = func_021AB0F0(func_0216D7DC(m));
        if (d_021714A0[kind](a) == 1)
            return 1;
        if (d_02171490[kind](func_021AB0F0(first)) == 1)
            return 1;
        return 0;
    }
    return 1;
}

int func_02163E1C(void *a, char *b, E *c) { return func_0218DAEC((char *)func_0216D52C(func_0216D67C(a)),b,c); }
