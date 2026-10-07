/*
 * file:     townmap_p19.c
 * unit:     yes
 * function: func_021BBB04, func_021BBB0C, func_021BBB14, func_021BBB1C, func_021BBB24, func_021BBB34, func_021BBB3C
 * address:  0x021BBB04
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204A648 0x0204A648 arm
 *   func_0204A1BC 0x0204A1BC arm
 *   func_020307B0  0x020307B0  arm
 */
typedef unsigned int   u32;

extern void func_0204A648(void);
extern int func_0204A1BC(int,int,int,int);
u32 func_020307B0(void *p);
void func_021BBB04(void *p);
unsigned int func_021BBB0C(void *p, int n);
unsigned int func_021BBB14(void *p, int n);
int func_021BBB1C(char *p, int i);
int func_021BBB24(int a);
void func_021BBB34(void *p);
unsigned short func_021BBB3C(char *p, int a, int b);

void func_021BBB04(void *p) { func_0204A648(); }

unsigned int func_021BBB0C(void *p, int n)
{
    return *(unsigned int *)((char *)p + n * 4 + 4);
}

/*
 * Unlabelled Thumb leaf in a .word run:
 *   lsls r1,r1,#2; ldr r0,[r0,r1]; bx lr
 * Word at p + n*4.
 */
unsigned int func_021BBB14(void *p, int n)
{
    return *(unsigned int *)((char *)p + n * 4);
}

int func_021BBB1C(char *p, int i)
{
    return *(int *)(p + i * 4 + 0x18);
}

int func_021BBB24(int a) { return func_0204A1BC(0x56,0,0,a); }


void func_021BBB34(void *p)
{
    func_020307B0(p);
}

unsigned short func_021BBB3C(char *p, int a, int b)
{
    return *(unsigned short *)(p + a * 0x36 + b * 2);
}
