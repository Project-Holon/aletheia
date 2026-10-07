/*
 * file:     dwc_rap_p08.c
 * unit:     yes
 * function: func_02155C24, func_02155C28, func_02155C6C
 * address:  0x02155C24
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
 *   func_0203D798  0x0203D798  arm
 *   g_021A8264    0x021A8264  data  ov009
 */
typedef int s32;

extern void *func_0203D798(void);
void func_02155C24(void);
void func_02155C28(s32 a, s32 b);
void func_02155C6C(void);
extern char *g_021A8264;

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
