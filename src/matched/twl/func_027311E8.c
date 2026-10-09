/*
 * function: func_027311E8
 * address:  0x027311E8
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02084C68 0x02084C68 arm
 *   func_02084EB8 0x02084EB8 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02084C68(u32, void *, void *);
extern u32 func_02084EB8(void);

void func_027311E8(u16 *p)
{
    *p = func_02084EB8();
    func_02084C68(*p, (void *)0x02FFF680, 0);
}
