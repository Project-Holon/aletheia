/*
 * function: func_021D9760
 * address: 0x021D9760
 * packet: pkt_ov129_021D9760
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D8950 0x021D8950 thumb ov129
 *   func_021DA164 0x021DA164 thumb ov129
 *   func_021DA1A8 0x021DA1A8 thumb ov129
 *   func_021D8AF4 0x021D8AF4 thumb ov129
 *   func_021D9E60 0x021D9E60 thumb ov129
 *   func_021D97B8 0x021D97B8 thumb ov129
 * Extent ends with two bytes of zero alignment padding.
 */
#include "../include/Obj00361.h"

extern void func_021D8950(char *,int);
extern void func_021DA164(void *);
extern void func_021DA1A8(char *,int);
extern void func_021D8AF4(char *,int);
extern void func_021D9E60(char *,int);
extern void func_021D97B8(char *);
void func_021D9760(char *p)  {
    switch(((struct Obj00361 *)p)->f31C)  {
        case 0: break;
        case 1: func_021D8950(p,((struct Obj00361 *)p)->f320);
        func_021DA164(p);
        func_021DA1A8(p,1);
        func_021D8AF4(p,2);
        ((struct Obj00361 *)p)->f31C=255;
        break;
        case 2: func_021D9E60(p,((struct Obj00361 *)p)->f320);
        func_021D97B8(p);
        break;
        case 255: break;
    }
}
