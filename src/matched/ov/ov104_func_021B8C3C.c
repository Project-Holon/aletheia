/*
 * function: func_021B8C3C
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
 *   func_0207CA00 0x0207CA00 arm
 *   VEC_Normalize 0x0207CCA4 arm
 *   func_021B8E8C 0x021B8E8C thumb ov104
 *   func_021B8DA4 0x021B8DA4 thumb ov104
 *   g_020A1B38 0x020A1B38 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct { int x,y,z; } Vec;
typedef struct { int x,y; } Point;
extern u32 func_020056EC(u32);
extern void func_0207CA00(const Vec *,const Vec *,Vec *);
extern void VEC_Normalize(const Vec *,Vec *);
extern u32 func_021B8E8C(u8 *);
extern void func_021B8DA4(u8 *,const Point *,const Point *,int,u32);
extern const s16 g_020A1B38[];
#define SHIFT(v,n) ((int)((u32)(v)<<(n)))
void func_021B8C3C(u8 *p, const void *a, int color)
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
            if(!func_021B8E8C(p+offset)) {
                angle=(u16)func_020056EC(65535)>>4;
                end.x=SHIFT(g_020A1B38[angle*2],8)>>12;
                end.y=SHIFT(g_020A1B38[angle*2+1],8)>>12;
                random.x=SHIFT(end.x,12);
                random.y=SHIFT(end.y,12);
                random.z=0;
                func_0207CA00(&random,&origin,&delta);
                VEC_Normalize(&delta,&delta);
                rawY=delta.y;
                end.x=SHIFT(delta.x,8)>>12;
                end.y=SHIFT(rawY,8)>>12;
                end.x=(int)((u32)end.x+(u32)((const Point *)a)->x);
                end.y=(int)((u32)end.y+(u32)((const Point *)a)->y);
                func_021B8DA4(p+offset,a,&end,color,func_020056EC(5)+40);
                break;
            }
        }
    }
}
