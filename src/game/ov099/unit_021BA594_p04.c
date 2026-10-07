/*
 * file:     unit_021BA594_p04.c
 * unit:     yes
 * function: func_021BA794, func_021BA7BC
 * address:  0x021BA794
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
 *   func_021BA770  0x021BA770  thumb  ov099
 *   func_021BA78C  0x021BA78C  thumb  ov099
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef struct {
    char pad[0x0D];
    u8 f0D;
} S;

extern void func_021BA770(void *p);
extern void func_021BA78C(void *p);
void func_021BA794(u8 *p, u8 b);
void func_021BA7BC(S *s);


void func_021BA794(u8 *p, u8 b)
{
    if (p[0xD] != 0) {
        func_021BA770(p);
    }

    p[0xC] = b;
    p[0x8] ^= (u8)(1 << b);
    func_021BA78C(p);
}


/*
 * When the byte at +0x0D is set, runs the reset at func_021BA78C on the block.
 */
void func_021BA7BC(S *s)
{
    if (s->f0D != 0) {
        func_021BA78C(s);
    }
}
