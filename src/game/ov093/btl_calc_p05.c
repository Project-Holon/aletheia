/*
 * file:     btl_calc_p05.c
 * unit:     yes
 * function: func_021D7320, func_021D7324
 * address:  0x021D7320
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

/* 021D7320  str r1,[r0,#0xc] */
struct QS { u8 pad[0xc]; u32 v; };

void func_021D7320(struct QS *p, u32 v);
void func_021D7324(u8 *p);

/*
 * Stores the second argument (a u32) into the field at #0xc.
 */
void func_021D7320(struct QS *p, u32 v) { p->v = v; }


void func_021D7324(u8 *p)
{
    *(u32 *)&p[0xc] = 0x0;
}
