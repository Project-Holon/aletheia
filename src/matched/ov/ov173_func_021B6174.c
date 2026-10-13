/*
 * function: func_021B6174
 * address: 0x021B6174
 * packet: pkt_ov173_021B6174
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: final 2 bytes are alignment padding
 * symbols:
 *   func_021B68B0 0x021B68B0 thumb ov173
 *   func_021B68C8 0x021B68C8 thumb ov173
 *   func_021B69F8 0x021B69F8 thumb ov173
 *   func_021B6A64 0x021B6A64 thumb ov173
 *   func_021B6AAC 0x021B6AAC thumb ov173
 *   func_021B6B0C 0x021B6B0C thumb ov173
 *   func_021B6B54 0x021B6B54 thumb ov173
 *   func_021B6B6C 0x021B6B6C thumb ov173
 *   func_021B6BA0 0x021B6BA0 thumb ov173
 *   func_021B7B60 0x021B7B60 thumb ov173
 *   func_021B7B8C 0x021B7B8C thumb ov173
 *   func_021B7C00 0x021B7C00 thumb ov173
 *   func_021B8110 0x021B8110 thumb ov173
 *   func_021B815C 0x021B815C thumb ov173
 *   func_021B817C 0x021B817C thumb ov173
 *   func_021B6390 0x021B6390 thumb ov173
 *   CLACT_DrawSystem 0x0204A600 arm
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 */
#include "../include/Obj06564.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Tcbl;
extern int func_021B68B0(int *p);
extern int func_021B68C8(char *p);
extern int func_021B69F8(char *p);
extern int func_021B6A64(u8 *p);
extern int func_021B6AAC(u8 *p);
extern int func_021B6B0C(char **p);
extern int func_021B6B54(int *p);
extern int func_021B6B6C(char *p);
extern int func_021B6BA0(char *p);
extern int func_021B7B60(u8 *p);
extern int func_021B7B8C(char *p);
extern int func_021B7C00(void *);
extern int func_021B8110(u8 *p);
extern int func_021B815C(char *p);
extern int func_021B817C(char *p);
extern void func_021B6390(int *p);
extern void CLACT_DrawSystem(void);
extern void TCBL_Main(struct Tcbl *p);
struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
int func_021B6174(void *unused0,u32 *state,void *unused2,u8 *p)
{
    switch(*state) {
    case 0: *state=func_021B68B0((int *)p);break;
    case 1: *state=func_021B68C8((char *)p);break;
    case 2: *state=func_021B69F8((char *)p);break;
    case 3: *state=func_021B6A64(p);break;
    case 4: *state=func_021B6AAC(p);break;
    case 5: *state=func_021B6B0C((char **)p);break;
    case 6: *state=func_021B6B54((int *)p);break;
    case 7: *state=func_021B6B6C((char *)p);break;
    case 8: *state=func_021B6BA0((char *)p);break;
    case 9: return 1;
    case 10: *state=func_021B7B60(p);break;
    case 11: *state=func_021B7B8C((char *)p);return 0;
    case 12: *state=func_021B7C00(p);return 0;
    case 13: *state=func_021B8110(p);break;
    case 14: *state=func_021B815C((char *)p);break;
    case 15: *state=func_021B817C((char *)p);break;
    }
    func_021B6390((int *)p);
    CLACT_DrawSystem();
    TCBL_Main(((struct Obj06564 *)p)->f64);
    PRINTSYS_QUE_Main(((struct Obj06564 *)p)->f218);
    return 0;
}
