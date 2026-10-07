/*
 * file:     calender_p04.c
 * unit:     yes
 * function: func_0216476C, func_02164778
 * address:  0x0216476C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_02171534 0x02171534 data ov010 a4
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_02034AC4 0x02034AC4 arm
 *   func_021F3800 0x021F3800 thumb ov047
 *   func_02034A5C 0x02034A5C arm
 *   ov_id_47 0x0000002F data
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
extern int func_02034AC4(int);
extern void func_021F3800(u32 a);
extern void func_02034A5C(int);
char *func_0216476C(unsigned short *n);
int func_02164778(void *a,void *b);
extern char d_02171534[];
extern u8 ov_id_47[];


char *func_0216476C(unsigned short *n)
{
    *n = 0xB1;
    return d_02171534;
}

int func_02164778(void *a,void *b){void *v=func_0215A5DC(b);func_02034AC4((int)ov_id_47);func_021F3800((u32)v);func_02034A5C((int)ov_id_47);return 0;}
