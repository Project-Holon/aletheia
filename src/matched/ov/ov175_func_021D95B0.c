/*
 * function: func_021D95B0
 * address: 0x021D95B0
 * packet: pkt_ov175_021D95B0
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021DCB58 0x021DCB58 thumb ov175
 *   func_021DCC28 0x021DCC28 thumb ov175
 *   func_021D9B18 0x021D9B18 thumb ov175
 *   func_021E8AA8 0x021E8AA8 thumb ov177
 */
#include "../include/Obj03868.h"
#include "../include/Obj24294.h"
typedef unsigned long u32;
extern void func_02082BCC(void *, int, int);
extern void func_021DCB58(char *p, void *q, int mode);
typedef unsigned char  u8;
extern int func_021DCC28(char *p, u8 *out);
extern void func_021D9B18(char *save, char *response);
extern void func_021E8AA8(int a);
void func_021D95B0(u32 sys, int *state, char *ctx)
{
    char *save;
    int result;
    save = *(char * *)&((struct Obj24294 *)(*(char * *)&((struct Obj03868 *)ctx)->f104))->f14;
    switch (*state) {
    case 0: *state = 1; break;
    case 1:
        func_02082BCC(ctx + 0x44, 0, 0x9c);
        func_021DCB58(((struct Obj03868 *)ctx)->f34, save + 0xd4, 1);
        *state = 2;
        break;
    case 2:
        result = func_021DCC28(((struct Obj03868 *)ctx)->f34, (u8 *)(ctx + 0x44));
        if (result == 1) *state = 3;
        else if (result == 2) { ((struct Obj03868 *)ctx)->f40 = 2; *state = 4; }
        else if (result == 3) { ((struct Obj03868 *)ctx)->f40 = 3; *state = 4; }
        break;
    case 3:
        if (((struct Obj03868 *)ctx)->f44 == 0) {
            func_021D9B18(save, ctx + 0x44);
            ((struct Obj03868 *)ctx)->f40 = 0;
            *state = 4;
        } else {
            ((struct Obj03868 *)ctx)->f40 = 1;
            *state = 4;
        }
        break;
    case 4: func_021E8AA8(sys); break;
    }
}
