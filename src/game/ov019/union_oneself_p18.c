/*
 * file:     union_oneself_p18.c
 * unit:     yes
 * function: func_0217FCC0, func_0217FCC4
 * address:  0x0217FCC0
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216D88C 0x0216D88C thumb ov010
 *   func_02047AC8 0x02047AC8 arm
 */
struct E;
struct Actor;
struct Arg;
struct VecFx32;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { int x,y,z; } VecFx32;

extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern int func_02047AC8(void *a, struct Arg *b);
void func_0217FCC0(struct E *e);
void func_0217FCC4(u32 *p, u32 *b);


void func_0217FCC0(struct E *e)
{
}

void func_0217FCC4(u32 *p, u32 *b) { func_0216D88C((const struct Actor *)p[0], (struct VecFx32 *)b); b[1] -= 0x6800; func_02047AC8((void *)p[3], (struct Arg *)b); }
