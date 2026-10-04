/*
 * unit: yes
 * function: func_021B9774, func_021B97B8
 * address: 0x021B9774
 * packet: pkt_ov217_021B9774
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9AD0 0x021B9AD0 thumb ov217
 *   func_021BAB80 0x021BAB80 thumb ov217
 *   func_021BD5F4 0x021BD5F4 thumb ov217
 */
typedef unsigned int u32;
extern u32 func_021B9AD0(void *self);
extern u32 func_021BAB80(u32, u32);
extern void *func_021BD5F4(void *p);
void func_021B9774(u32 *p, u32 *state, u32 kind)
{
    switch (kind) {
    case 0:
    case 4:
        break;
    case 1:
        p[4] = func_021B9AD0((void *)p[3]);
        break;
    case 2:
        p[5] = func_021BAB80(p[3], p[7]);
        break;
    case 3:
        p[6] = (u32)func_021BD5F4((void *)p[3]);
        break;
    }
    *state = kind;
}
int func_021B97B8(void)
{
    return 1;
}
