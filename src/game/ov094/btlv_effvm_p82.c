/*
 * file:     btlv_effvm_p82.c
 * unit:     yes
 * function: func_02201AC4, func_02201AF0
 * address:  0x02201AC4
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
 *   func_02201CA4  0x02201CA4  thumb  ov094
 *   func_0204A600  0x0204A600  arm
 */
struct Bank;
typedef struct Ent { void *h8; void *hc; void *h10; void *h14; } Ent;

typedef struct Res { void *owner; void *h; Ent e[7]; } Res;

typedef unsigned int   u32;

extern void func_02201CA4(Res *r, int i);
extern unsigned int func_0204B1CC(struct Bank *bank);
extern u32 func_020307B0(void *p);
void func_0204A600(void);
void func_02201AC4(Res *r);
void func_02201AF0(void *a0);


void func_02201AC4(Res *r)
{
    int i;
    for (i = 0; i < 7; i++) {
        if (r->e[i].h8 != 0)
            func_02201CA4(r, i);
    }
    func_0204B1CC(r->h);
    func_020307B0(r);
}


void func_02201AF0(void *a0)
{
    func_0204A600();
}
