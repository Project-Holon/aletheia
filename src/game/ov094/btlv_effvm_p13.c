/*
 * file:     btlv_effvm_p13.c
 * unit:     yes
 * function: func_021F8168, func_021F8180
 * address:  0x021F8168
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 *   func_022089AC 0x022089AC thumb ov094
 *   func_02207C94 0x02207C94 thumb ov094
 */
typedef unsigned char  u8;

extern void func_022089AC(void *);
extern int func_02207C94(u8 *p);
void func_021F8168(void);
int func_021F8180(void);
extern char *d_0220AF20;


/*
 * Tail call to func_022089AC with the handle at 0x1a4 of the global work block.
 */
void func_021F8168(void)
{
    func_022089AC(*(void **)(d_0220AF20 + 0x1a4));
}


/*
 * Tail call to func_02207C94 with the handle at 0x1a4 of the global work block.
 */
int func_021F8180(void)
{
    return func_02207C94(*(void **)(d_0220AF20 + 0x1a4));
}
