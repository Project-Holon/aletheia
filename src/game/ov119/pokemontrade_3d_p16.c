/*
 * file:     pokemontrade_3d_p16.c
 * unit:     yes
 * function: func_021E4AA4, func_021E4AB8, func_021E4AD0, func_021E4B00, func_021E4DBC, func_021E4E0C, func_021E4E64
 * address:  0x021E4AA4
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021E82A4 0x021E82A4 data
 *   func_021DF614 0x021DF614 thumb ov119
 *   func_020355C4 0x020355C4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021E4984 0x021E4984 thumb ov119
 *   func_021E49DC 0x021E49DC thumb ov119
 *   func_021E496C 0x021E496C thumb ov119
 *   func_0204B7C8 0x0204B7C8 arm
 *   func_021D8AF4 0x021D8AF4 thumb ov119
 *   func_021D8B0C 0x021D8B0C thumb ov119
 *   func_0204B454 0x0204B454 arm
 *   func_02061CA4 0x02061CA4 arm
 *   func_02082D44 0x02082D44 arm
 *   func_0201BBE8 0x0201BBE8 thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_02017E88 0x02017E88 thumb
 *   func_021E4A84 0x021E4A84 thumb ov119
 *   func_021E5164 0x021E5164 thumb ov119
 *   func_021E5158 0x021E5158 thumb ov119
 *   func_021E4F28 0x021E4F28 thumb ov119
 */
#include "../../matched/include/Obj00001.h"
#include "../../matched/include/Obj22807.h"
#include "../../matched/include/Obj08070.h"

struct Actor;
struct Obj;
struct Struct36;
struct PtS;
typedef unsigned int   u32;

typedef short s16;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct { u16 id; u8 b2, b3; } Ent;

typedef struct { s16 x, y; } Pt;

typedef struct { int a, b, c, d[6]; } Info;

typedef signed int     s32;

extern void func_0204B688(struct Actor *actor, u32 value);
extern int func_021DF614(char *p, int a, int b);
extern u8 func_020355C4(void);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern int func_021E4984(int v, int a, int b, char *p, int *out);
extern char *func_021E49DC(int a, int b, char *p);
extern void func_021E496C(int x, int y, u16 *out);
extern void func_0204B7C8(const char *src, struct Struct36 *dst);
extern int func_021D8AF4(int, char *);
extern int func_021D8B0C(int, int);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void func_02082D44(int src, int dst, int n);
extern int func_0201BBE8(void *a0);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B92C(struct Obj *p, u32 v);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern int func_021E4A84(char *p, int i);
extern void func_021E5164(int p);
extern int func_021E5158(int);
extern void func_021E4F28(char *);
int func_021E4AA4(int i, int x);
void func_021E4AB8(int a0, int a1, int a2);
void func_021E4AD0(char *p, int a1, int a2, int a3, int a4, int a5);
void func_021E4B00(char *p, int v, int a, int row, int flag);
int func_021E4DBC(char *p);
int func_021E4E0C(char *p, int *out);
void func_021E4E64(int a, char *p, int b);
extern const unsigned char d_021E82A4[];

int func_021E4AA4(int i, int x)
{
    if (x == d_021E82A4[i]) {
        return 1;
    }
    return 0;
}


/*
 * Normalise the third argument to 0 or 1 and tail call the setter.
 */
void func_021E4AB8(int a0, int a1, int a2)
{
    func_0204B688((struct Actor *)a1, a2 != 0);
}

void func_021E4AD0(char *p, int a1, int a2, int a3, int a4, int a5)
{
    int flag = 0;
    if (func_021DF614(p, a1, a2)) {
        flag = 1;
    }
    func_021E4AB8((int)p, ((int (*)[5])(p + 0xAC0))[a5][a2], flag);
}

void func_021E4B00(char *p, int v, int a, int row, int flag)
{
    int j, rec, id, b2, b3, idx, n;
    Ent *e;
    Info info;
    int kind;
    u16 pos[2];
    Pt pt;
    enum { VRAM_BASE = 0x06600000 } vram;
    if (a == ((struct Obj00001 *)p)->fF74 && func_020355C4() == 0) {
        func_0204B3DC(((void **)(p + row * 20 + 0xbb0))[((struct Obj00001 *)p)->fF78], 1);
    }
    for (j = 0; j < 5; j++) {
        rec = func_021E4984(v, a, j, p, &kind);
        e = (Ent *)func_021E49DC(a, j, p);
        if (e == 0) {
            *(u8 *)(p + row * 5 + j + 0xd90) = 0xff;
            continue;
        }
        if (e->id == 0) {
            *(u8 *)(p + row * 5 + j + 0xd90) = 0xff;
            continue;
        }
        ((u8 *)(p + row * 5) + j)[0xd90] = a;
        b2 = e->b2;
        id = e->id;
        b3 = e->b3;
        if (id == *(u16 *)(p + row * 10 + j * 2 + 0xca0) && b2 == ((u8 *)(p + row * 5) + j)[0xd18]
            && b3 == ((u8 *)(p + row * 5) + j)[0xd54]) {
            func_0204B3DC(*(void **)(p + row * 20 + j * 4 + 0xac0), 1);
            func_021E4AD0(p, a, j, rec, kind, row);
        } else if (id != *(u16 *)(p + row * 10 + j * 2 + 0xca0)
            || (id == *(u16 *)(p + row * 10 + j * 2 + 0xca0) && b2 != ((u8 *)(p + row * 5) + j)[0xd18])
            || (id == *(u16 *)(p + row * 10 + j * 2 + 0xca0) && b3 != ((u8 *)(p + row * 5) + j)[0xd54])) {
            *(u16 *)(p + row * 10 + j * 2 + 0xca0) = id;
            *(u8 *)(p + row * 5 + j + 0xd18) = b2;
            *(u8 *)(p + row * 5 + j + 0xd54) = b3;
            func_021E496C(a, j, pos);
            func_0204B7C8(*(void **)(p + row * 20 + j * 4 + 0xac0), (struct Struct36 *)(&info));
            n = func_021D8AF4(a, p);
            idx = func_021D8B0C(a, j);
            idx += n * 30;
            func_0204B454((struct Actor *)*(void **)(p + row * 20 + j * 4 + 0xac0), (struct PtS *)&pt, 1);
            if (flag == 1 && pt.x >= -16 && pt.x <= 0x110) {
                if (func_02061CA4((void *)0x23, info.c, *(int *)(p + 0x1184) + idx * 0x200, 0x200) == 0) {
                    vram = VRAM_BASE;
                    func_02082D44(*(int *)(p + 0x1184) + idx * 0x200, vram + info.c, 0x200);
                }
            } else {
                vram = VRAM_BASE;
                func_02082D44(*(int *)&((struct Obj00001 *)p)->f1184 + idx * 0x200, vram + info.c, 0x200);
            }
            func_021E4AD0(p, a, j, rec, kind, row);
            func_0204B6F4(*(void **)(p + row * 20 + (u32)j * 4 + 0xac0), func_0201BBE8((void *)rec), 1);
            func_0204B92C(*(void **)(p + row * 20 + (u32)j * 4 + 0xac0), 0);
            func_0204B3DC(*(void **)(p + row * 20 + (u32)j * 4 + 0xac0), 1);
        }
        if (func_02017E88((void *)rec, 0x4c, 0) == 0 && func_021E4A84(p, id)) {
            ((u8 *)(p + row * 5) + j)[0xebc] = 1;
        }
    }
}

/*
 * lever: a separate adjusted-coordinate local keeps the subtraction before division.
 */
int func_021E4DBC(char *p)
{
    int x, q, r, v;
    x = ((struct Obj22807 *)p)->f107C;
    if (x < 48) x = 0;
    else if (x < 96) x = 1;
    else {
        v = x - 96;
        q = v / 160;
        r = v - q * 160;
        x = q * 6 + 2;
        if (r >= 8) {
            if (r >= 152) x += 5;
            else x += (r - 8) / 24;
        }
    }
    return x;
}

int func_021E4E0C(char *p, int *out)
{
    int x, hi, n, t;
    x = func_021E4DBC(p);
    *out = x + 2;
    hi = x + 10;
    n = ((struct Obj08070 *)p)->f634;
    if (*out >= n) *out -= n;
    n = ((struct Obj08070 *)p)->f634;
    if (hi >= n) {
        t = ((struct Obj08070 *)p)->fF74;
        if (t < 20) t = t + 1 + n;
        if (x <= t && t <= hi) return 1;
    } else {
        t = ((struct Obj08070 *)p)->fF74;
        if (x <= t && t <= hi) return 1;
    }
    return 0;
}

/*
 * lever: i before n gives n the earlier spill slot.
 */
void func_021E4E64(int a, char *p, int b)
{
    int i, n, j;
    n = func_021E4DBC(p);
    if (((struct Obj00001 *)p)->f1080 != n) {
        ((struct Obj00001 *)p)->f1080 = n;
        for (i = 0; i < 12; i++) {
            for (j = 0; j < 5; j++) {
                func_0204B3DC((struct Obj *)*(int *)(p + i * 20 + j * 4 + 0xbb0), 0);
                *(unsigned char *)(p + i * 5 + j + 0xebc) = 0;
            }
        }
        ((struct Obj00001 *)p)->f1090 = n;
        func_021E5164((int)p);
        for (i = 0; i < 12; i++) {
            func_021E4B00(p, a, n, func_021E5158(((struct Obj00001 *)p)->f1080 + i), b);
            n++;
            if (n >= ((struct Obj00001 *)p)->f634) n = 0;
        }
    }
    func_021E4F28(p);
}
