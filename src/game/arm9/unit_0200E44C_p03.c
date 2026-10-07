/*
 * file:     unit_0200E44C_p03.c
 * unit:     yes
 * function: func_0200E9E0, func_0200E9F4, func_0200EA00, func_0200EA04, func_0200EA08
 * address:  0x0200E9E0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
struct Sub020071CCCtrl;
typedef unsigned char u8;

typedef unsigned int   u32;

extern void func_0200E904(void *p);
extern void func_0200DFCC(void *p);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
void func_0200E9E0(void *a0);
void *func_0200E9F4(void *p);
int func_0200EA00(int p);
int func_0200EA04(int p);
int func_0200EA08(int p);



void func_0200E9E0(void *a0)
{
    func_0200E904(a0);
    func_0200DFCC((u8 *)a0 + 0x5a);
}



/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 */
void *func_0200E9F4(void *p)
{
    return func_020071CC(p, 0x3c);
}


/*
 * Unlabelled leaf accessor matched to give overlay call sites a matched
 * witness.  Addresses are Black-image addresses.
 */
int func_0200EA00(int p)
{
    return p + 0x5a;
}


int func_0200EA04(int p)
{
    return p + 0x5a;
}


int func_0200EA08(int p)
{
    return p;
}
