/*
 * file:     unit_021B95A0_p02.c
 * unit:     yes
 * function: func_021B9930, func_021B9944, func_021B9950, func_021B995C, func_021B9964
 * address:  0x021B9930
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9FC0 0x021B9FC0 thumb ov068
 *   func_021B9BD0 0x021B9BD0 thumb ov068
 *   func_021BA018  0x021BA018  thumb  ov068
 *   func_021BA020  0x021BA020  thumb  ov068
 *   func_021B9BFC  0x021B9BFC  thumb  ov068
 *   func_021B9D58  0x021B9D58  thumb  ov068
 */
typedef unsigned char u8;

extern void func_021B9FC0(u8 *);
extern void func_021B9BD0(u8 *);
void func_021B9930(u8 *p);
int func_021B9944(void *p, int i);
int func_021B9950(void *p);
int func_021B995C(int *p, int i);
void func_021B9964(char *p);

void func_021B9930(u8 *p)
{
    func_021B9FC0(p + 0x7c);
    func_021B9BD0(p);
}

int func_021B9944(void *p, int i)
{
    int func_021BA018(char *, int);
    return func_021BA018((char *)p + 0x7c, i);
}


int func_021B9950(void *p)
{
    int func_021BA020(int *p);
    return func_021BA020((int *)((char *)p + 0x7c));
}


int func_021B995C(int *p, int i)
{
    int func_021B9BFC(int *, int);
    return func_021B9BFC(p, i);
}


void func_021B9964(char *p)
{
    void func_021B9D58(char *);
    func_021B9D58(p);
}
