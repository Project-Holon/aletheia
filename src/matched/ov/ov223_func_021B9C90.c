/*
 * function: func_021B9C90
 * address: 0x021B9C90
 * packet: pkt_ov223_021B9C90
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02048A18 0x02048A18 arm
 *   func_0204779C 0x0204779C arm
 *   func_020477D4 0x020477D4 arm
 *   func_020477A4 0x020477A4 arm
 *   func_0204784C 0x0204784C arm
 *   func_0204B908 0x0204B908 arm
 */
typedef unsigned short u16;
extern void *func_02048A18(void *,int);
typedef signed int     s32;
typedef unsigned int   u32;
struct AnmCtl;
struct G3dSys;
struct Owner;
extern int func_0204779C(int *p);
extern int func_020477D4(struct Owner *owner, u32 index);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern u32 func_0204784C(struct AnmCtl *c, u32 idx, s32 *frame);
/* B908 reads only r0, forwarding its live r1 to D478; legacy r2/r3 unused. */
extern void func_0204B908(void *,int);
void func_021B9C90(char *p,unsigned next)
{
    void *object;
    unsigned count;
    u16 i;
    int frame;
    if(*(unsigned *)(p+556)!=4 && *(unsigned *)(p+556)!=next) {
        object=func_02048A18(*(void **)(p+40),*(u16 *)(*(char **)(p+60)+68*(*(u16 *)(p+48+2*(*(unsigned *)(p+556)+2)))));
        count=func_0204779C(object);
        for(i=0;i<count;i++) func_020477D4(object,i);
    }
    if(next!=4 && *(unsigned *)(p+556)!=next) {
        object=func_02048A18(*(void **)(p+40),*(u16 *)(*(char **)(p+60)+68*(*(u16 *)(p+48+2*(next+2)))));
        count=func_0204779C(object);
        frame=0;
        for(i=0;i<count;i++) {
            func_020477A4(object,i);
            func_0204784C(object,i,&frame);
        }
        func_0204B908(*(void **)(p+548),0);
    }
    *(unsigned *)(p+556)=next;
}
