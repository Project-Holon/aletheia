/*
 * function: func_021F6A80
 * address: 0x021F6A80
 * packet: pkt_ov112_021F6A80
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Padding then separately verified follower func_021F6AF0.
 * symbols:
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_0204F638 0x0204F638 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct { int x,y,z; } Vec;
extern void func_0204F638(void *,u32,Vec *);
void func_021F6A80(char *o,u32 *p)
{
    Vec v;
    float f;
    if(p[1]==1) {
        if(*(u16 *)(o+2)!=0) f=0.5f+(float)(*(u16 *)(o+2)<<12);
        else f=(float)(*(u16 *)(o+2)<<12)-0.5f;
        v.x=((int)p[2]-(int)f)/16;
        v.y=(786432-(int)p[3])/16;
        v.z=p[4];
        func_0204F638(*(void **)(o+4),p[6],&v);
        p[1]=0;
    }
}
