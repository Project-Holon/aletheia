/*
 * file:     scrcmd_c03center_p07.c
 * unit:     yes
 * function: func_021B6AAC, func_021B6AB0, func_021B6AE0
 * address:  0x021B6AAC
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
 *   func_021B6AA4  0x021B6AA4  thumb ov021
 *   func_0201134C  0x0201134C  thumb
 *   func_0215A6D0  0x0215A6D0  thumb ov010
 */
struct Cursor;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u8 pad[0x14];
    u8 *p;
} Ctx;

extern int func_021B6AA4(u32 a, u32 b);
extern u32 func_0201134C(struct Cursor *p);
extern void func_0215A6D0(void *p, u32 v);
void func_021B6AAC(u16 *a0);
int func_021B6AB0(void *a);
int func_021B6AE0(Ctx *c, void *b);


void func_021B6AAC(u16 *a0)
{
}


int func_021B6AB0(void *a)
{
    int i;
    u16 *p;

    for (i = 0; i < 8; i++) {
        p = (u16 *)func_021B6AA4((u32)a, i);
        func_021B6AAC(p);
        if (*p == 0xFFFF) {
            return i;
        }
    }
    return 0;
}


/*
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 */
int func_021B6AE0(Ctx *c, void *b)
{
    func_0215A6D0(b, (u32)(c->p + func_0201134C((struct Cursor *)c)));
    return 0;
}
