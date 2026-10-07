/*
 * file:     unit_021ECE60_p07.c
 * unit:     yes
 * function: func_021ED714, func_021ED724
 * address:  0x021ED714
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
 *   func_021F7D80  0x021F7D80  thumb  ov094
 *   func_021F7E38  0x021F7E38  thumb  ov094
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   func_02031194  0x02031194  arm
 */
struct TcblNode;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct S { char *w; u32 k; void *v; u32 c; u8 pad10; u8 f; u8 pad12[2]; u8 *cnt; };

extern void func_021F7D80(void *a, int b);
extern void func_021F7E38(void *a, int b);
extern int func_021F7EB4(void);
extern void func_02031194(struct TcblNode *n);
u32 func_021ED714(u8 *p);
void func_021ED724(u32 x, struct S *t);


u32 func_021ED714(u8 *p) { if (p[0x40] == 0) return 1; return 0; }


void func_021ED724(u32 x, struct S *t)
{
    switch (t->c) {
    case 0:
        if (t->f == 0)
            func_021F7D80(t->v, t->k);
        else
            func_021F7E38(t->v, t->k);
        t->c++;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            (*t->cnt)--;
            func_02031194((struct TcblNode *)x);
        }
        break;
    }
}
