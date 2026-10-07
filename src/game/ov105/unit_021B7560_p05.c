/*
 * file:     unit_021B7560_p05.c
 * unit:     yes
 * function: func_021B8434, func_021B8438, func_021B8440
 * address:  0x021B8434
 * region:   ov105
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B878 0x0204B878 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021B8974 0x021B8974 data a4
 */
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32;

typedef struct { u32 objects[3]; u8 pad[0x24]; u8 digits[3]; u8 pad1; int state[3]; } Display;

extern void func_0204B878(struct Obj *p, u16 value);
int func_021B8434(void *a0);
int func_021B8438(u8 *p,int i);
void func_021B8440(Display *p, unsigned n);
extern const unsigned d_021B8974[];


int func_021B8434(void *a0) { return 0; }

/*
 * extent: unowned follower at 021B8440 is outside this getter.
 */
int func_021B8438(u8 *p,int i) {return *(int *)(p+0x34+i*4);}

void func_021B8440(Display *p, unsigned n)
{
    u8 t;
    int i, j;
    t = n;
    if (t) { for (;;) { if (!t) break; t = t / 10; } }
    for (i = 0; i < 3; i++) func_0204B878((struct Obj *)p->objects[i],0);
    for (j = 0; j < 3; j++) {
        p->digits[j] = n % d_021B8974[j+1] / d_021B8974[j];
        func_0204B878((struct Obj *)p->objects[2-j],p->digits[j]+1);
    }
}
