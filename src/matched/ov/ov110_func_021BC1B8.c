/*
 * function: func_021BC1B8
 * address: 0x021BC1B8
 * packet: pkt_ov110_021BC1B8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment padding after return.
 * lever: coordinate arguments are int; the callee stores low halfwords
 * without caller-side narrowing, including y+192.
 * symbols:
 *   func_021BC578 0x021BC578 thumb ov110
 *   func_021BAC64 0x021BAC64 thumb ov110
 *   func_021BAC78 0x021BAC78 thumb ov110
 *   func_021BC69C 0x021BC69C thumb ov110
 *   func_0204B878 0x0204B878 arm
 *   func_0204B84C 0x0204B84C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef struct { int a,b,c; } Triple;
typedef struct { s16 x,y; } Pair;
extern void func_021BC578(Pair *,Pair *);
extern void func_021BAC64(void *,Triple *,int,int);
extern void *func_021BAC78(void *,Triple *,int,int,int,int);
struct Obj;
extern void func_021BC69C(u8 *p, int flag);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B84C(void *,int);
void func_021BC1B8(u8 *p)
{
    Triple t;
    Pair pos;
    if (*(int *)(p+0x44)) func_021BC578((Pair *)(p+0x38),&pos);
    else { pos.x=128; pos.y=24; }
    func_021BAC64(*(void **)p,&t,1,0);
    *(void **)(p+0x18)=func_021BAC78(*(void **)p,&t,pos.x,pos.y+192,0,2);
    func_0204B878(*(void **)(p+0x18),1);
    func_0204B84C(*(void **)(p+0x18),1);
    func_021BAC64(*(void **)p,&t,0,0);
    *(void **)(p+0x14)=func_021BAC78(*(void **)p,&t,pos.x,pos.y,0,1);
    func_021BC69C(p,1);
}
