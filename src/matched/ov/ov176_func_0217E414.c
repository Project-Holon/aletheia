/*
 * function: func_0217E414
 * address: 0x0217E414
 * packet: pkt_ov176_0217E414
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02157E78 0x02157E78 thumb ov010
 *   func_02157E8C 0x02157E8C thumb ov010
 *   func_0203D210 0x0203D210 arm
 */
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_02157E78(u8 *p);
extern int func_02157E8C(int a0);
extern u32 func_0203D210(void);
int func_0217E414(char *p)
{
    if (*(void **)(p + 0x1018))
        func_02157E78(*(void **)(p + 0x1018));
    switch (*(int *)p) {
    case 0:
        if (*(void **)(p + 0x1018)) {
            func_02157E8C((int)(*(void **)(p + 0x1018)));
            *(void **)(p + 0x1018) = 0;
        }
        (*(int *)p)++;
        break;
    case 1:
        if (func_0203D210())
            return 1;
        break;
    }
    return 0;
}
