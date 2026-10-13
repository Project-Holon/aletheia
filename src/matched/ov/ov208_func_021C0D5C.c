/*
 * function: func_021C0D5C
 * address: 0x021C0D5C
 * packet: pkt_ov208_021C0D5C
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * 2026-10-04 (D2-16): blocker BUTTON_MAN_InitSphere filed EXACT as src/matched/arm9/BUTTON_MAN_InitSphere.c (24 bytes). Remaining MATCH* is the missing shard
 * witness only; the integrator manifest run should make this EXACT.
 * Tail: 021C100A..021C100C is two zero alignment bytes.
 * blocker: integrator-owned ARM9 0x02051F1C has no code-start witness.
 *   Scratch fixed-flags one: EXACT, 24 bytes, blocker-02051F1C-1.log.
 *   struct Vec { int x,y,z; };
 *   struct Ball { struct Vec p; int radius; };
 *   void BUTTON_MAN_InitSphere(struct Ball *dst, struct Vec *src, unsigned radius)
 *   { dst->p=*src; dst->radius=radius; }
 *   Caller loads dst, src and radius into r0-r2; no overlay leaves filed.
 *   tu --suggest-split: no viable piece; singleton caller remains blocked.
 * symbols:
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_021BBB3C 0x021BBB3C thumb ov072
 *   BUTTON_MAN_InitSphere 0x02051F1C arm
 *   BUTTON_MAN_InitSegment 0x0205207C arm
 *   BUTTON_MAN_SegmentSphereTest 0x02051F34 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Vec { int x,y,z; };
struct Ball { struct Vec p; int radius; };
struct Seg { struct Vec a,b; int radius; };
struct Out { u32 hit; struct Vec n; int distance; };
extern u16 func_021BBB3C(char *,int,int);
extern void BUTTON_MAN_InitSphere(struct Ball *,struct Vec *,u32);
struct S12;
extern void BUTTON_MAN_InitSegment(char *p, struct S12 *q, struct S12 *r, u32 v);
extern u32 BUTTON_MAN_SegmentSphereTest(struct Seg *,struct Ball *,struct Out *);
#define FX(x) ((int)(((x)>0) ? ((float)((int)(x)<<12)+0.5f) : ((float)((int)(x)<<12)-0.5f)))
#define FIELD(n) func_021BBB3C(*(char **)(p+0x3c8),i,n)
u8 func_021C0D5C(void *unused,char *p,int unused2,u8 x,u8 y)
{
    struct Ball ball;
    struct Vec point;
    struct Seg seg;
    struct Vec a,b;
    struct Out out;
    int best;
    u8 i;
    u8 result=255;
    point.x=FX(x);
    point.y=FX(y);
    point.z=0;
    BUTTON_MAN_InitSphere(&ball,&point,0);
    for(i=0;i<61;i++) {
        if (*(u32 *)(p+i*8+0x1e0)==1) continue;
        a.x=FX(FIELD(6));
        a.y=FX(FIELD(7));
        a.z=0;
        b.x=FX(FIELD(8));
        b.y=FX(FIELD(9));
        b.z=0;
        BUTTON_MAN_InitSegment((char *)(&seg),(struct S12 *)(&a),(struct S12 *)(&b),FX(FIELD(10)));
        if (BUTTON_MAN_SegmentSphereTest(&seg,&ball,&out)) {
            if(result==255) { best=out.distance; result=i; }
            else if(best>out.distance) { best=out.distance; result=i; }
        }
    }
    return result;
}
