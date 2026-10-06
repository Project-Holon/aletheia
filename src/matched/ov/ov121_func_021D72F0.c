/*
 * function: func_021D72F0
 * address: 0x021D72F0
 * packet: pkt_ov121_021D72F0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D9F08 0x021D9F08 thumb ov121
 *   func_021D81B0 0x021D81B0 thumb ov121
 *   func_021D83B0 0x021D83B0 thumb ov121
 *   func_021D8380 0x021D8380 thumb ov121
 *   func_021DA8C0 0x021DA8C0 thumb ov121
 *   func_021DA8B0 0x021DA8B0 thumb ov121
 *   func_021D9FF8 0x021D9FF8 thumb ov121
 *   func_021DA8C4 0x021DA8C4 thumb ov121
 *   func_021D6E3C 0x021D6E3C thumb ov121
 */
#include "../include/Obj00326.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021D9F08(u8 *a, int b, int c, int d);
extern void func_021D81B0(u8 *p, u32 which, int heap);
extern int func_021D83B0(char *p);
extern void func_021D8380(char *p);
extern void func_021DA8C0(u32 *p, u32 a);
extern void func_021DA8B0(u32 *p, u32 a);
extern unsigned func_021D9FF8(u8 *p);
extern void func_021DA8C4(u32 *p);
extern void func_021D6E3C(void *task, u32 *state, u8 *p);
void func_021D72F0(void *a, int *state, char *p)
{
    int result;
    switch (*state) {
    case 0:
        func_021D9F08(((struct Obj00326 *)p)->f284, ((struct Obj00326 *)p)->f3A4, 126, 0);
        func_021D81B0((u8 *)p, 3, 29);
        *state = 2;
        break;
    case 2:
        result = func_021D83B0(p);
        if (result == -1) break;
        func_021D8380(p);
        if (result == 0) {
            func_021D9F08(((struct Obj00326 *)p)->f284, ((struct Obj00326 *)p)->f3A4, 132, 1);
            func_021DA8C0(a, 0);
            *state = 3;
        } else if (result == 1) {
            func_021D9F08(((struct Obj00326 *)p)->f284, ((struct Obj00326 *)p)->f3A4, 133, 1);
            func_021DA8C0(a, 0);
            *state = 3;
        } else if (result == 2) {
            func_021D9F08(((struct Obj00326 *)p)->f284, ((struct Obj00326 *)p)->f3A4, 134, 1);
            func_021DA8C0(a, 0);
            *state = 3;
        } else if (result == 3) {
            func_021DA8B0(a, (u32)func_021D6E3C);
        }
        break;
    case 3:
        if (func_021D9FF8(((struct Obj00326 *)p)->f284)) func_021DA8C4(a);
        break;
    }
}
