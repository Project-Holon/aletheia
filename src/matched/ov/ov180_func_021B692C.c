/*
 * function: func_021B692C
 * address: 0x021B692C
 * packet: pkt_ov180_021B692C
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021B80C0 0x021B80C0 data a4
 *   func_02017100 0x02017100 thumb
 *   func_020159C8 0x020159C8 thumb
 *   func_02015CAC 0x02015CAC thumb
 *   func_02015E04 0x02015E04 thumb
 */
#include "../include/Obj06586.h"
typedef struct { int x,y,z; } Vec;
typedef struct { unsigned words[9]; } Params;
extern const Vec d_021B80C0;
extern void func_02017100(int,Params *,int);
extern int func_020159C8(int,int,int,int,Params *);
extern void func_02015CAC(int,Vec *);
extern void func_02015E04(void *p);
void func_021B692C(char *p) {
    Params params;
    Vec pos=d_021B80C0;
    func_02017100(*(int *)(p+0x9140+((struct Obj06586 *)p)->f915D*4),&params,0);
    ((struct Obj06586 *)p)->f1C=func_020159C8(((struct Obj06586 *)p)->f18,0xb0000,-196608,0,&params);
    func_02015CAC(((struct Obj06586 *)p)->f1C,&pos);
    func_02015E04((void *)(((struct Obj06586 *)p)->f1C));
}
