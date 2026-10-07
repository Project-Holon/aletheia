/*
 * file:     btl_server_p116.c
 * unit:     yes
 * function: func_021CBF90, func_021CBFA0
 * address:  0x021CBF90
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
 *   func_021CC398   0x021CC398  thumb
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B9A40  0x021B9A40  thumb  ov093
 *   func_021E8940  0x021E8940  thumb  ov093
 *   func_021CBFF8  0x021CBFF8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct Word { u32 v; } Word;

extern u8 func_021D5440(u8 *p);
extern unsigned char func_021B9A40(unsigned int x);
extern Word func_021E8940(int v);
extern int func_021CBFF8(int a, int b, Word c);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 val);
extern void func_021C88C8(void *a, void *b);
/* 021CBF90 stack-arg wrapper: func_021CC398(a, b, c, d, 0x7) */ void func_021CBF90(int a, int b, int c, int d);
int func_021CBFA0(u8 *p, u8 *q);


/* 021CBF90  stack-arg wrapper: func_021CC398(a, b, c, d, 0x7) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #7; str r4, [sp]; bl func_021CC398; add sp, #4; pop {r3, r4, pc}.
 */
void func_021CBF90(int a, int b, int c, int d) { func_021CC398(a, b, c, d, 0x7); }


int func_021CBFA0(u8 *p, u8 *q)
{
    int m;
    u8 *w;
    Word t;
    m = func_021B9A40(func_021D5440(q));
    t = func_021E8940(5);
    if (func_021CBFF8(m, 3, t)) {
        w = func_021C88A4((char *)p, 4, 0x1f);
        func_021C8838(w + 4, 1, 0x88);
        func_021C8860((struct S *)(w + 4), m);
        func_021C88C8(p, w);
        return 1;
    }
    return 0;
}
