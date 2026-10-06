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
typedef unsigned int   u32;
struct Obj;
struct Rec;
struct Stats;
struct Sub150;
extern void func_02017100(void *p, struct Stats *out, u32 lvl);
extern struct Rec *func_020159C8(struct Obj *obj, u32 a1, u32 a2, u32 a3, const struct Sub150 *src);
extern void func_02015CAC(void *p, u32 *src);
extern void func_02015E04(void *p);
void func_021B692C(char *p) {
    Params params;
    Vec pos=d_021B80C0;
    func_02017100((void *)(*(int *)(p+0x9140+((struct Obj06586 *)p)->f915D*4)),(struct Stats *)(&params),0);
    ((struct Obj06586 *)p)->f1C=(int)func_020159C8((struct Obj *)(((struct Obj06586 *)p)->f18),0xb0000,-196608,0,(const struct Sub150 *)(&params));
    func_02015CAC((void *)(((struct Obj06586 *)p)->f1C),(u32 *)(&pos));
    func_02015E04((void *)(((struct Obj06586 *)p)->f1C));
}
