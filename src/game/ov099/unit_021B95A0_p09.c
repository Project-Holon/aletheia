/*
 * file:     unit_021B95A0_p09.c
 * unit:     yes
 * function: func_021B9F84, func_021B9F90
 * address:  0x021B9F84
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_0204B3DC  0x0204B3DC  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B528  0x0204B528  arm
 *   func_0204B800  0x0204B800  arm
 */
struct Obj;
struct Actor;
struct Pt;
struct Node;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021B9F84;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef struct {
    char pad[0x28];
    void *f28;
} S;

typedef struct {
    short x, y;
} Pos;

typedef struct {
    char pad[0x2c];
    void *f2c;              /* 0x2c */
} Obj;

typedef unsigned int   u32_021B9F90;

extern void sub_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B528(struct Actor *actor, const struct Pt *src);
extern void func_0204B800(struct Node *node, u32_021B9F90 val);
extern void func_0204B3DC(struct Obj *p, u32_021B9F90 v);
void func_021B9F84(S *s);
void func_021B9F90(Obj *o, Pos pos, int c);


void func_021B9F84(S *s)
{
    sub_0204B3DC(s->f28, 0);
}


void func_021B9F90(Obj *o, Pos pos, int c)
{
    Pos t;

    t.x = pos.x + 8;
    t.y = pos.y;
    func_0204B528(o->f2c, (const struct Pt *)(&t));
    func_0204B800(o->f2c, (unsigned char)c);
    func_0204B3DC(o->f2c, 1);
}
