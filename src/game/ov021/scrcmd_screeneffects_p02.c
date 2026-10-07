/*
 * file:     scrcmd_screeneffects_p02.c
 * unit:     yes
 * function: func_021AE754, func_021AE79C, func_021AE7A8, func_021AE884
 * address:  0x021AE754
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
 *   func_021AE72C  0x021AE72C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_0216D5A8  0x0216D5A8  thumb
 *   func_0216E434  0x0216E434  thumb
 *   func_0216D828  0x0216D828  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_02163994  0x02163994  thumb  ov010
 *   func_021AA900  0x021AA900  thumb  ov021
 *   func_0216D5B8  0x0216D5B8  thumb  ov010
 *   func_0215A460  0x0215A460  thumb
 */
struct S;
struct Self;
typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

extern int func_021AE72C(struct S *s);
extern u32 func_020307B0(void *p);
extern u32 func_0216D5A8(u32);
extern u32 func_0216E434(u32);
extern void func_0216D828(u32 a, Vec3s *out);
extern s16 func_021641E8(u32 dir);
extern s16 func_021641F8(u32 dir);
extern int func_02163994(u32 a, int x, int y, int z, u32 dir);
extern int func_021AA900(struct Self *self, short *pos);
extern u32 func_0215A460(u32);
extern u32 func_0216D5B8(void *p);
int func_021AE754(u32 a, u32 b, u32 *c);
int func_021AE79C(u32 a);
int func_021AE7A8(u32 a, u32 dir, int n, void *p);
int func_021AE884(u32 a);


/*
 * Addresses are Black-image addresses.
 */
int func_021AE754(u32 a, u32 b, u32 *c)
{
    if (c[0] != 0) {
        if (func_021AE72C((struct S *)c[0]) == 1) {
            func_020307B0((void *)c[0]);
            c[0] = 0;
        }
    }
    if (c[1] != 0) {
        if (func_021AE72C((struct S *)c[1]) == 1) {
            func_020307B0((void *)c[1]);
            c[1] = 0;
        }
    }
    if (c[0] == 0 && c[1] == 0) {
        return 1;
    }
    return 0;
}


/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D5A8 (0x0216D5A8) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021AE79C(u32 a)
{
return func_0216E434(func_0216D5A8(a));
}


int func_021AE7A8(u32 a, u32 dir, int n, void *p)
{
    Vec3s pos;
    s16 dx;
    s16 dz;
    int i;

    if (n != 0) {
        i = 0;
        func_0216D828(a, &pos);
        dx = func_021641E8(dir);
        dz = func_021641F8(dir);
        pos.x += dx;
        pos.z += dz;
        for (; i < n - 1; i++) {
            if ((func_02163994(a, pos.x, pos.y, pos.z, dir) & ~1) != 0)
                return 1;
            if (p != 0 && func_021AA900(p, (short int *)(&pos)) != 0)
                return 1;
            pos.x += dx;
            pos.z += dz;
        }
        if ((func_02163994(a, pos.x, pos.y, pos.z, dir) & ~1) != 4)
            return 1;
        if (p != 0 && func_021AA900(p, (short int *)(&pos)) != 0)
            return 1;
    }
    return 0;
}


/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0215A460 (0x0215A460) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021AE884(u32 a)
{
return func_0215A460(func_0216D5B8((void *)a));
}
