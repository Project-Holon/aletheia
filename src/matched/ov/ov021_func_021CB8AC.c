/*
 * function: func_021CB8AC
 * address:  0x021CB8AC
 * packet:   pkt_ov021_021CB8AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Task step: closes the message window, optionally resumes the field, then waits for the save to finish.
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 * The caller leaves the owner pointer in r0 for func_02167B18, so the extern
 * keeps one (ignored) parameter.
 *
 * symbols:
 *   func_0203D378  0x0203D378  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_02167B18  0x02167B18  thumb  ov010
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_0203CDBC  0x0203CDBC  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8  pad0[0xc];
    u16 lo   : 9;
    u16 flag : 1;
    u16 hi   : 6;
} Owner;

extern u32 func_0203D378(void);
extern void func_0203D7BC(int a);
extern void func_02167B18(void *p);
extern int func_0203D1B4(void);
extern int func_0203CEAC(int a0);
extern int func_0203CDBC(void);

int func_021CB8AC(void *task, int *state, Owner **work)
{
    switch (*state) {
    case 0:
        if (func_0203D378() == 1)
            func_0203D7BC(0);
        if ((*work)->flag == 1)
            func_02167B18(*work);
        (*state)++;
        break;
    case 1:
        if (func_0203D378() == 1) {
            if (func_0203D1B4() <= 1) {
                func_0203CEAC(0);
                (*state)++;
            }
        } else {
            func_0203CEAC(0);
            (*state)++;
        }
        break;
    case 2:
        if (func_0203CDBC() == 1)
            return 1;
        break;
    }
    return 0;
}
