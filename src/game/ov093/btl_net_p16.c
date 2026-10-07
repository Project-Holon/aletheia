/*
 * file:     btl_net_p16.c
 * unit:     yes
 * function: func_021D51CC, func_021D51DC
 * address:  0x021D51CC
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
 *   func_021D5208 0x021D5208 thumb ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct S { u16 h[6]; u8 f0c; };

extern void func_021D5208(struct S *p, u32 a, u32 b);
/* 021D51CC first round: `p[x] &= ~0xf` narrowed the mask to 0xf0 and used * ands; the image keeps a 32-bit intermediate and bics with 0xf. */ void func_021D51CC(u8 *p);
void func_021D51DC(struct S *p, u32 a, u32 b, u32 c);


/* 021D51CC  first round: `p[x] &= ~0xf` narrowed the mask to 0xf0 and used
 * ands; the image keeps a 32-bit intermediate and bics with 0xf. */
/*
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: ldrb r2, [r0, #0xb]; movs r1, #0xf; bics r2, r1; strb r2, [r0, #0xb]; ldrb r2, [r0, #5]; bics r2, r1; strb r2, [r0, #5]; bx lr.
 */
void func_021D51CC(u8 *p)
{
    u32 v;
    v = p[0xb];
    v &= ~0xf;
    p[0xb] = v;
    v = p[5];
    v &= ~0xf;
    p[5] = v;
}

void func_021D51DC(struct S *p, u32 a, u32 b, u32 c)
{
    if (c != 0) {
        func_021D5208(p, a, b);
        if (p->f0c != 0) {
            p->h[3] = p->h[0];
            p->h[4] = p->h[1];
            p->h[5] = p->h[2];
        }
    } else {
        func_021D5208((struct S *)(p->h + 3), a, b);
        p->f0c = 0;
    }
}
