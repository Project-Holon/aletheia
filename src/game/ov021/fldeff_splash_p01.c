/*
 * file:     fldeff_splash_p01.c
 * unit:     yes
 * function: func_021C4938, func_021C4954
 * address:  0x021C4938
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
 *   func_021AC154  0x021AC154  thumb  ov021
 */
struct BbActSys;
typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 *p;
    u16 id;
} S;

typedef unsigned char  u8;

extern void func_02050468(struct BbActSys *o, u16 first, u32 count);
extern u32 func_020508EC(u8 *p, int i, u16 *out);
extern void func_021AC154(void *a);
void func_021C4938(void *a, S *s);
void func_021C4954(void *a, S *s);


/*
 * Sets flag 1 on the field object unless the id is 0xFFFF.
 */
void func_021C4938(void *a, S *s)
{
    u32 x = s->p[1];

    if (s->id != 0xFFFF)
        func_02050468((struct BbActSys *)x, s->id, 1);
}


void func_021C4954(void *a, S *s)
{
    u32 tmp;

    if (func_020508EC((u8 *)s->p[1], s->id, (u16 *)(&tmp)) != 0)
        func_021AC154(a);
}
