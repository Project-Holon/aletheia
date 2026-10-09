/*
 * file:     dwc_rap_p13.c
 * unit:     yes
 * function: func_02155BDC, func_02155C0C, func_02155C24, func_02155C28, func_02155C6C
 * address:  0x02155BDC
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021A8264 0x021A8264 data ov009 a4
 *   func_0216B65C 0x0216B65C arm ov009
 *   func_02155374 0x02155374 thumb ov009
 *   func_0203D798  0x0203D798  arm
 *   g_021A8264    0x021A8264  data  ov009
 */
typedef unsigned char u8;

typedef int s32;

extern int func_0216B65C(void);
extern void func_02155374(int);
extern void *func_0203D798(void);
void func_02155BDC(unsigned int n);
void func_02155C0C(int a);
/* * Unlabelled empty callback leaf for func_021554C8. Reads no arguments. */ void func_02155C24(void);
/* * Stores a and b into every one of 0x20 slots at +0x17C and +0x1FC whose first word is -1. */ void func_02155C28(s32 a, s32 b);
void func_02155C6C(void);
extern u8 *d_021A8264;
extern char *g_021A8264;


void func_02155BDC(unsigned int n)
{
    if (n < 2 && d_021A8264[0x7A8]) {
        func_0216B65C();
        *(int *)(d_021A8264 + 0x774) = -1;
        func_02155374(20);
    }
}



void func_02155C0C(int a)
{
    if (a == 0) {
        func_02155374(6);
        return;
    }

    func_02155374(0xe);
}


/*
 * Unlabelled empty callback leaf for func_021554C8. Reads no arguments.
 */
void func_02155C24(void)
{
}



/*
 * Stores a and b into every one of 0x20 slots at +0x17C and +0x1FC whose first word is -1.
 */
void func_02155C28(s32 a, s32 b)
{
    s32 i;

    func_0203D798();
    for (i = 0; i < 0x20; i++) {
        if (*(s32 *)(g_021A8264 + i * 4 + 0x17C) == -1) {
            *(s32 *)(g_021A8264 + i * 4 + 0x17C) = a;
            *(s32 *)(g_021A8264 + i * 4 + 0x1FC) = b;
        }
    }
}


void func_02155C6C(void)
{
}
