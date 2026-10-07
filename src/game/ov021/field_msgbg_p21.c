/*
 * file:     field_msgbg_p21.c
 * unit:     yes
 * function: func_0218C43C, func_0218C47C
 * address:  0x0218C43C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02047828  0x02047828  arm
 */
struct AnmCtl;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

u32 func_02047828(struct AnmCtl *c, u32 idx, s32 *frame);
int func_0218C43C(u32 *st, int i);
int func_0218C47C(int *p, int id);


/*
 * Reports whether slot i (0 if out of range) is in state 0 or 2.
 */
int func_0218C43C(u32 *st, int i)
{
    u8 j = i;

    if (j >= 4)
        j = 0;
    switch ((st + j)[2]) {
    case 0:
        return 1;
    case 1:
        return 0;
    case 2:
        return 1;
    case 3:
    case 4:
        return 0;
    }
    return 0;
}


int func_0218C47C(int *p, int id)
{
    int out;
    func_02047828((struct AnmCtl *)(*p), (unsigned short)id, &out);
    return out;
}
