/*
 * function: func_021E0698
 * address: 0x021E0698
 * packet: pkt_ov137_021E0698
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Position setter before scale setter keeps zero in r0 and scale in r1.
 * symbols:
 *   func_02048A18 0x02048A18 arm
 *   func_020520FC 0x020520FC arm
 *   func_02047A60 0x02047A60 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int x,y,z; } Vec;
typedef struct { int m[9]; } Mtx;
typedef struct { Vec pos,scale; Mtx rot; } Transform;
extern void *func_02048A18(void *,u16);
extern void func_020520FC(int,int,int,Mtx *);
extern void func_02047A60(void *,Transform *);
static inline void VecSet(Vec *v,int x,int y,int z)
{
    v->x=x;
    v->y=y;
    v->z=z;
}
void func_021E0698(u8 *p)
{
    Transform t;
    void *object;
    object = func_02048A18(*(void **)(p+2804),*(int *)(p+3492));
    VecSet(&t.pos,0,0,0);
    VecSet(&t.scale,4096,4096,4096);
    func_020520FC(0,0,0,&t.rot);
    func_02047A60(object,&t);
}
