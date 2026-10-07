/*
 * file:     btl_net_p08.c
 * unit:     yes
 * function: func_021D4898, func_021D48CC
 * address:  0x021D4898
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F3B88 0x021F3B88 data ov093 a4
 *   func_021D4330 0x021D4330 thumb ov093
 *   func_021D4394 0x021D4394 thumb ov093
 */
typedef unsigned char u8;

typedef unsigned int u32;

extern u8 func_021D4330(int);
extern u8 func_021D4394(u32);
int func_021D4898(void);
void *func_021D48CC(u8 a);
extern u8 *d_021F3B88;

int func_021D4898(void)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (func_021D4330(i) != 0 && *(void **)(d_021F3B88 + i * 4 + 0x3af4) == 0)
            return 0;
    }
    return 1;
}

void *func_021D48CC(u8 a)
{
    int i = func_021D4394(a);
    void *p;
    if (i != 0x28) return *(void **)(d_021F3B88 + i * 4 + 0x3ae4);
    p = *(void **)(d_021F3B88 + 0x3b14);
    if (p != 0 && *(void **)(d_021F3B88 + 0x3b18) != 0) return p;
    return 0;
}
