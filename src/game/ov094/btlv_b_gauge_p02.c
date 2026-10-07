/*
 * file:     btlv_b_gauge_p02.c
 * unit:     yes
 * function: func_02207D60, func_02207D78, func_02207DA0
 * address:  0x02207D60
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
 *   func_0220793C  0x0220793C  thumb  ov094
 *   func_0220868C  0x0220868C  thumb  ov094
 *   func_0204B454  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0204B3DC  0x0204B3DC  arm
 */
struct Obj;
struct Vec2;
struct Actor;
struct PtS;
typedef unsigned char u8;

typedef unsigned int u32;

struct Flags { u32 low:3; u32 bit3:1; u32 high:28; };

typedef struct {
    unsigned int b0 : 27;
    unsigned int b27 : 1;
    unsigned int b28 : 4;
} Bits;

typedef short s16;

typedef struct S {
    char p0[8];
    void *f8;
    void *fc;
    char p10[0x38];
    int f48;
    int f4c;
    u32 f50;
    char p54[0x14];
    int f68;
    int p6c;
    u32 lo : 1;
    u32 hi : 31;
    char p74[4];
    int f78;
} S;

typedef unsigned short u16;

extern void func_0220793C(char *p);
extern void func_0220868C(void *obj, S *q, int n);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B3DC(struct Obj *p, u32 v);
int func_02207D60(u8 *p, int index);
int func_02207D78(char *p, int i);
void func_02207DA0(void *obj, S *q, int n);

int func_02207D60(u8 *p, int index)
{
    if (((struct Flags *)(p + (index << 7) + 0xb0))->bit3) return 1;
    return 0;
}


/*
 * lane S13 leaf of func_0220680C
 */
int func_02207D78(char *p, int i)
{
    int r = 0;

    if (*(int *)(p + i * 128 + 0x40) != 0) {
        Bits *q = (Bits *)(p + 0xb0 + i * 128);

        r = q->b27;
        q->b27 = 0;
    }
    return r;
}


/*
 * Lever: q->f48 is read from the struct in both statements (no local), so
 * the load stays after the 0x50 store.
 */
void func_02207DA0(void *obj, S *q, int n)
{
    s16 v[2];

    q->f50 = 0x80000000;
    q->f68 = q->f48 - n;
    if (q->f48 < 0) {
        q->f48 = 0;
    }
    if (q->f48 > q->f4c) {
        q->f48 = q->f4c;
    }
    q->lo = 1;
    if (q->f68 > 0) {
        func_0220793C((char *)q);
        func_0204B454(q->f8, (struct PtS *)v, 0);
        v[0] = v[0] - (s16)(0x30 - q->f78);
        func_0204B404(q->fc, (const struct Vec2 *)v, 0);
        func_0204B3DC(q->fc, 1);
        func_0220868C(obj, q, q->f78);
    }
}
