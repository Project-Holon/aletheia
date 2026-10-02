/*
 * function: func_021BB0B0
 * address:  0x021BB0B0
 * packet:   pkt_021BB0B0
 * region:   ov223
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203630C  0x0203630C  arm
 *   func_02035C38  0x02035C38  arm
 *   func_020362DC  0x020362DC  arm
 *   func_02035C60  0x02035C60  arm
 */

typedef unsigned int u32;

extern u32 func_0201CE30(u32);
extern u32 func_0201CE5C(u32, int);
extern u32 func_0201CE38(u32);
extern unsigned int func_0203630C(void);
extern u32 func_02035C38(void);
extern u32 func_020362DC(void);
extern u32 func_02035C60(void);

int func_021BB0B0(char *a)
{
    int r = 0;

    switch (func_0201CE30(*(u32 *)(a + 0x250))) {
    case 0:
        if ((func_0203630C() & 3) != 0 || func_02035C38() != 0) {
            func_0201CE5C(*(u32 *)(a + 0x250), 0);
            if ((func_0203630C() & 3) != 0)
                *(int *)(a + 8) = 0;
            else
                *(int *)(a + 8) = 1;
        }
        break;
    case 1:
        if ((func_020362DC() & 3) != 0 || func_02035C60() != 0) {
            func_0201CE38(*(u32 *)(a + 0x250));
            if ((func_020362DC() & 3) != 0)
                *(int *)(a + 8) = 0;
            else
                *(int *)(a + 8) = 1;
        }
        break;
    case 2:
        r = 1;
        break;
    }
    return r;
}
