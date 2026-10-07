/*
 * file:     unit_021DE14C_p03.c
 * unit:     yes
 * function: func_021DEAD4, func_021DEAF8, func_021DEB1C
 * address:  0x021DEAD4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DE14C  0x021DE14C  arm
 */
typedef unsigned long u32;

extern void func_021DE2E0(u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_021DE8AC(u32 a, u32 b, u32 c);
extern int func_021DE14C(char **names, int n);
void func_021DEAD4(char *obj);
void func_021DEAF8(char *obj);
int func_021DEB1C(char *p);


/*
 * Five-argument forward to func_021DE2E0 (ov175): the object itself
 *  *  is the first argument, its +0x0c cursor is passed bare and +4, and the
 *  *  +0x08 block contributes its second and third words.
 */
void func_021DEAD4(char *obj)
{
    u32 *ip = *(u32 **)(obj + 8);
    u32 v = *(u32 *)(obj + 0xc);
    func_021DE2E0((u32)obj, v + 4, v, ip[2], ip[1]);
}


/*
 * If the +0x0c cursor is live, forwards its first two words as the
 *  *  second and third arguments and the +0x08 block's +0x08 word as the
 *  *  first to func_021DE8AC (ov175).
 */
void func_021DEAF8(char *obj)
{
    u32 *cur = *(u32 **)(obj + 0xc);
    char *blk = *(char **)(obj + 8);
    if (cur == 0)
        return;
    func_021DE8AC(*(u32 *)(blk + 8), cur[0], cur[1]);
}


int func_021DEB1C(char *p)
{
    int *q = *(int **)(p + 8);

    if (q[0] == 0)
        return 4;
    if (q[2] <= 0)
        return 6;
    if (q[1] == 0)
        return 5;
    return func_021DE14C((char **)q[1], q[2]);
}
