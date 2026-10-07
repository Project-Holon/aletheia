/*
 * file:     shinka_demo_view_p02.c
 * unit:     yes
 * function: func_02205A84, func_02205AAC
 * address:  0x02205A84
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   d_02208D1C    0x02208D1C data ov195 a4
 *   func_02205B64 0x02205B64 thumb
 *   func_02205BD0 0x02205BD0 thumb
 */
typedef unsigned int   u32;

extern void func_020403F4(u32 i);
extern void func_02205B64(void *);
extern void func_02205BD0(void *);
void func_02205A84(int a0);
void func_02205AAC(int a, char *b);
extern char d_02208D1C[];


void func_02205A84(int a0)
{
    unsigned int i;
    for (i = 0; i < 6; i++)
    {
        unsigned int v = *(unsigned int *)(d_02208D1C + i * 0x2c);
        if (v >= 4)
        {
            func_020403F4(v & 0xff);
        }
    }
}


void func_02205AAC(int a, char *b)
{
    func_02205B64(b);
    func_02205BD0(b + 4);
}
