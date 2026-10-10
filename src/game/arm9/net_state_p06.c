/*
 * file:     net_state_p06.c
 * unit:     yes
 * function: func_0203B1D8, func_0203B224, func_0203B228, func_0203B22C
 * address:  0x0203B1D8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203C934  0x0203C934  arm
 *   g_021469DC     0x021469DC  data
 */
typedef unsigned char  u8;

typedef unsigned int   u32;

struct Sys {
    u8  pad_00[8];
    void (*f08)(u32 a);
};

extern void func_0203C934(void);
u32 func_0203B1D8(void);
void func_0203B224(void);
void func_0203B228(void);
int func_0203B22C(int a0, int a1, int a2, int a3);
extern struct Sys *g_021469DC;


u32 func_0203B1D8(void)
{
    struct Sys *s = g_021469DC;

    if (s == 0)
        return 1;
    if (s->f08 != 0)
        s->f08((u32)s);
    if (g_021469DC == 0)
        return 1;
    func_0203C934();
    return 0;
}


void func_0203B224(void)
{
}


void func_0203B228(void)
{
}

int func_0203B22C(int a0, int a1, int a2, int a3){ int t0 = func_0203AD80((int)*(int *)((char *)(0x21469DC)), (int)0x203B224, (int)0, (int)0x1f4); return 1; }
