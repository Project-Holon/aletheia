/*
 * file:     un_select_p02.c
 * unit:     yes
 * function: func_021B991C, func_021B9924
 * address:  0x021B991C
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02027974 0x02027974 thumb
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Obj Obj;

extern void func_02027974(Obj *);
extern void func_02023F98(u32 mask);
extern int func_02023EF4(int a, int b, int c, int d, int e);
void func_021B991C(Obj *p);
int func_021B9924(void);

void func_021B991C(Obj *p)
{
    func_02027974(p);
}


/*
 * Initialises one record: enable flag 1 through 0x02023F98, then issue the
 * five-argument setup 0x02023EF4(8, -8, 0, 0x3c, 1) and return its result.
 * Blocker target of func_021BA0B0.
 *
 * Addresses are Black-image addresses.
 */
int func_021B9924(void)
{
    func_02023F98(1);
    return func_02023EF4(8, -8, 0, 0x3c, 1);
}
