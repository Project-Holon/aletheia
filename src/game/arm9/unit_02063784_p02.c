/*
 * file:     unit_02063784_p02.c
 * unit:     yes
 * function: func_020637D4, func_020637F4, func_02063800
 * address:  0x020637D4
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

void func_020637D4(u32 *p);
void func_020637F4(char *p, int i, int v);
int func_02063800(char *p, int i);



void func_020637D4(u32 *p)
{
    int i;

    for (i = 0; i < 3; i++) {
        p[i + 2] = 0xffffffff;
    }
}


void func_020637F4(char *p, int i, int v){ *(int *)(p + i * 4 + 8) = v; }

int func_02063800(char *p, int i){ return *(int *)(p + i * 4 + 8); }
