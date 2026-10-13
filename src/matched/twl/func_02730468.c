/*
 * function: MIi_InitWramManager
 * address:  0x02730468
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02732F5C 0x02732F5C data twl
 *   data_02732F6C 0x02732F6C data twl
 *   func_020885A0 0x020885A0 arm
 *   MIi_GetWramBank_A 0x02730210 arm twl
 *   MIi_GetWramBank_B 0x02730220 arm twl
 *   MIi_GetWramBank_C 0x02730230 arm twl
 *   MIi_CallbackForPxi 0x0273063C arm twl
 */
typedef unsigned short u16;
typedef unsigned int u32;

#define PIN(g, i) (((volatile u16 (*)[8])data_02732F6C)[g][i])

extern int data_02732F5C;
extern u16 data_02732F6C[3][8];
extern void func_020885A0(u32, void *);
extern u32 MIi_GetWramBank_A(u32);
extern u32 MIi_GetWramBank_B(u32);
extern u32 MIi_GetWramBank_C(u32);
extern void MIi_CallbackForPxi(u32 tag, u32 data, int err);

void MIi_InitWramManager(void)
{
    int i;
    if (data_02732F5C != 0) {
        return;
    }
    data_02732F5C = 1;
    for (i = 0; i < 4; i++) {
        switch (MIi_GetWramBank_A(i) & 1) {
        case 0:
            PIN(0, i) = PIN(0, i) & ~0x300;
            PIN(0, i) = PIN(0, i) & ~3;
            break;
        case 1:
            PIN(0, i) = (PIN(0, i) & ~0x300) | 0x100;
            PIN(0, i) = (PIN(0, i) & ~3) | 1;
            break;
        }
    }
    for (i = 0; i < 8; i++) {
        switch (MIi_GetWramBank_B(i) & 3) {
        case 0:
            PIN(1, i) = PIN(1, i) & ~0x300;
            PIN(1, i) = PIN(1, i) & ~3;
            break;
        case 1:
            PIN(1, i) = (PIN(1, i) & ~0x300) | 0x100;
            PIN(1, i) = (PIN(1, i) & ~3) | 1;
            break;
        default:
            PIN(1, i) = (PIN(1, i) & ~0x300) | 0x200;
            PIN(1, i) = (PIN(1, i) & ~3) | 2;
            break;
        }
    }
    for (i = 0; i < 8; i++) {
        switch (MIi_GetWramBank_C(i) & 3) {
        case 0:
            PIN(2, i) = PIN(2, i) & ~0x300;
            PIN(2, i) = PIN(2, i) & ~3;
            break;
        case 1:
            PIN(2, i) = (PIN(2, i) & ~0x300) | 0x100;
            PIN(2, i) = (PIN(2, i) & ~3) | 1;
            break;
        default:
            PIN(2, i) = (PIN(2, i) & ~0x300) | 0x200;
            PIN(2, i) = (PIN(2, i) & ~3) | 2;
            break;
        }
    }
    func_020885A0(0x12, MIi_CallbackForPxi);
}
