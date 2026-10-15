/*
 * function: IRC_RHYTHM_SpawnBurst
 * address: 0x021B8C3C
 * packet: pkt_ov104_021B8C3C
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Capture raw delta.y before the conversions, write both converted
 * endpoint fields before adding the origin, and keep end.y on the left
 * of its addition. This changes24 bytes to1 then EXACT; two ordering
 * variants used. Previous permuter remains consumed.
 * symbols:
 *   func_020056EC 0x020056EC thumb
 *   VEC_Subtract 0x0207CA00 arm
 *   VEC_Normalize 0x0207CCA4 arm
 *   IRC_RHYTHM_IsParticleActive 0x021B8E8C thumb ov104
 *   IRC_RHYTHM_StartParticle 0x021B8DA4 thumb ov104
 *   FX_SinCosTable_ 0x020A1B38 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct { int x,y,z; } Vec;
typedef struct { int x,y; } Point;
extern u32 func_020056EC(u32);
extern void VEC_Subtract(const Vec *,const Vec *,Vec *);
extern void VEC_Normalize(const Vec *,Vec *);
extern u32 IRC_RHYTHM_IsParticleActive(u8 *);
extern void IRC_RHYTHM_StartParticle(u8 *,const Point *,const Point *,int,u32);
extern const s16 FX_SinCosTable_[];
#define SHIFT(v,n) ((int)((u32)(v)<<(n)))
void IRC_RHYTHM_SpawnBurst(u8 *p, const void *a, int color)
{
    Vec origin, random, delta;
    Point end;
    int outer, i, offset, angle, tmp, rawY;
    origin.x=SHIFT(((const Point *)a)->x,12);
    origin.y=SHIFT(((const Point *)a)->y,12);
    origin.z=0;
    for(outer=0;outer<12;++outer) {
        for(i=0;i<30;++i) {
            tmp=i*44;
            offset=tmp;
            if(!IRC_RHYTHM_IsParticleActive(p+offset)) {
                angle=(u16)func_020056EC(65535)>>4;
                end.x=SHIFT(FX_SinCosTable_[angle*2],8)>>12;
                end.y=SHIFT(FX_SinCosTable_[angle*2+1],8)>>12;
                random.x=SHIFT(end.x,12);
                random.y=SHIFT(end.y,12);
                random.z=0;
                VEC_Subtract(&random,&origin,&delta);
                VEC_Normalize(&delta,&delta);
                rawY=delta.y;
                end.x=SHIFT(delta.x,8)>>12;
                end.y=SHIFT(rawY,8)>>12;
                end.x=(int)((u32)end.x+(u32)((const Point *)a)->x);
                end.y=(int)((u32)end.y+(u32)((const Point *)a)->y);
                IRC_RHYTHM_StartParticle(p+offset,a,&end,color,func_020056EC(5)+40);
                break;
            }
        }
    }
}
