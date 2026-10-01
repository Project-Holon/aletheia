/*
 * function: func_021E05D4
 * address: 0x021E05D4
 * packet: pkt_ov137_021E05D4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02048A18 0x02048A18 arm
 *   func_020520FC 0x020520FC arm
 *   func_02047A60 0x02047A60 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef struct { int x,y,z; } Vec;
typedef struct { int m[9]; } Mtx;
typedef struct { Vec pos,scale; Mtx rot; } Transform;
extern void *func_02048A18(void *,u16);
extern void func_020520FC(int,u16,int,Mtx *);
extern void func_02047A60(void *,Transform *);
static inline void VecSet(Vec *v,int x,int y,int z)
{
    v->x=x; v->y=y; v->z=z;
}
void func_021E05D4(u8 *p)
{
    Transform t;
    u8 *s;
    void *object;
    s=p+224;
    object=func_02048A18(*(void **)(p+2804),*(int *)(s+188));
    VecSet(&t.pos,*(int *)(s+12),*(int *)(s+16),*(int *)(s+20));
    VecSet(&t.scale,*(int *)(s+24),*(int *)(s+28),*(int *)(s+32));
    func_020520FC(*(u16 *)(s+76),*(s16 *)(s+78)*182,*(u16 *)(s+80),&t.rot);
    func_02047A60(object,&t);
}
