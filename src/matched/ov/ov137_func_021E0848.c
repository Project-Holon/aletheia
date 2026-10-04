/*
 * function: func_021E0848
 * address: 0x021E0848
 * packet: pkt_ov137_021E0848
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02048A18 0x02048A18 arm
 *   func_020520FC 0x020520FC arm
 *   func_02047A60 0x02047A60 arm
 *   func_0207ADC4 0x0207ADC4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {int x,y,z;} Vec;
typedef struct {int m[9];} Mtx;
typedef struct {Vec pos,scale;Mtx rot;} Transform;
typedef enum {INDEX_ZERO=0} Index;
extern void *func_02048A18(void *,u16);
struct Mtx33;
extern void func_020520FC(int,int,int,struct Mtx33 *);
extern void func_02047A60(void *,Transform *);
extern void func_0207ADC4(Mtx *);
static inline void VecSet(Vec *v,int x,int y,int z){v->x=x;v->y=y;v->z=z;}
void func_021E0848(u8 *p)
{
    int i=0;
    int count=*(int *)(p+0x30);
    u8 *base=p+0x1a0;
    u8 *first=base+0x140,*second=base+0x4c4,*third=base+0x730;
    for(;i<count;i=i+1) {
        if(*(int *)(first+4)) {
            Transform t;
            void *object=func_02048A18(*(void **)(p+0xaf4),*(int *)(base+0x938));
            VecSet(&t.pos,*(int *)(first+0x44),*(int *)(first+0x48),*(int *)(first+0x4c));
            VecSet(&t.scale,*(int *)(first+0x38),*(int *)(first+0x3c),*(int *)(first+0x40));
            func_020520FC(*(u16 *)(first+0x24),*(u16 *)(first+0x26),*(u16 *)(first+0x28),(struct Mtx33 *)&t.rot);
            func_02047A60(object,&t);
        }
        if(*(int *)second) {
            Transform t;
            void *object=func_02048A18(*(void **)(p+0xaf4),*(int *)(base+0x93c));
            VecSet(&t.pos,*(int *)(second+0x18),*(int *)(second+0x1c),*(int *)(second+0x20));
            VecSet(&t.scale,*(int *)(second+0xc),*(int *)(second+0x10),*(int *)(second+0x14));
            func_020520FC(*(u16 *)(second+4),*(u16 *)(second+6),*(u16 *)(second+8),(struct Mtx33 *)&t.rot);
            func_02047A60(object,&t);
        }
        if(*(int *)third) {
            Transform t;
            void *object=func_02048A18(*(void **)(p+0xaf4),*(int *)((unsigned)(base+i*4)+0x940));
            VecSet(&t.pos,*(int *)(third+4),*(int *)(third+8),*(int *)(third+12));
            VecSet(&t.scale,4096,4096,4096);
            func_0207ADC4(&t.rot);
            func_02047A60(object,&t);
        }
        first+=0xb4;second+=0x7c;third+=0x68;
    }
}
