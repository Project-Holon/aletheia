/*
 * file:     unit_021D87C8_p02.c
 * unit:     yes
 * function: func_021D88B8, func_021D88D0, func_021D88E8, func_021D890C, func_021D8940
 * address:  0x021D88B8
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
 *   func_021D76BC   0x021D76BC  thumb
 *   func_021D775C   0x021D775C  thumb
 *   func_021D84F0 0x021D84F0 thumb ov093
 *   d_021F05A0 0x021F05A0 data a4
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_0201C1E8 0x0201C1E8 thumb
 *   func_021D8974 0x021D8974 thumb ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern unsigned int func_021D84F0(unsigned int,unsigned int);
extern int func_021D775C(int);
extern void func_021D7704(int,int);
extern int func_0201C1E8(int a);
extern void func_021D8974(void *, int, int, int *);
/* 021D88B8 shape F1: gate on func_021D775C(2) */ void func_021D88B8(int a, int b, int c);
void *func_021D88D0(unsigned int *p);
void func_021D88E8(int a, int b, int c, int *d);
void func_021D890C(int a, int b, int c, int *d);
void func_021D8940(void *a, int b, int c, int *d);
extern unsigned char d_021F05A0[];


/* 021D88B8  shape F1: gate on func_021D775C(2) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #2; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021D88CE; movs r0, #0x11; movs r1, #0; bl func_021D76BC; pop {r4, pc}.
 */
void func_021D88B8(int a, int b, int c)
{
    if (c == func_021D775C(2))
        func_021D76BC(0x11, 0);
}


void *func_021D88D0(unsigned int *p)
{
    *p=func_021D84F0(7,1); return d_021F05A0;
}


void func_021D88E8(int a, int b, int c, int *d)
{
    int k=2; if(c==func_021D775C(k) && d[3]!=0) func_021D7704(0x35,k<<10);
}


void func_021D890C(int a, int b, int c, int *d)
{
    if(c==func_021D775C(3) && d[3]!=0 && func_0201C1E8((unsigned short)func_021D775C(0x12))==1) func_021D7704(0x35,0x800);
}


void func_021D8940(void *a, int b, int c, int *d)
{
    if(c==func_021D775C(2)) func_021D8974(a,b,c,d);
}
