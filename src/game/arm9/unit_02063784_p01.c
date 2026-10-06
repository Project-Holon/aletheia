/*
 * file:     unit_02063784_p01.c
 * unit:     yes
 * function: func_02063784, func_02063790, func_020637AC, func_020637B4
 * address:  0x02063784
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

int func_02063784(unsigned short *p, int i);
void func_02063790(u32 *p);
void func_020637AC(int *p, int i, int v);
int func_020637B4(int *p, int i);


int func_02063784(unsigned short *p, int i){ return p[i]; }



void func_02063790(u32 *p)
{
    int i;

    for (i = 0; i < 3; i++) {
        p[i] = 0xffffffff;
    }
}


void func_020637AC(int *p, int i, int v){ p[i] = v; }

int func_020637B4(int *p, int i){ return p[i]; }
