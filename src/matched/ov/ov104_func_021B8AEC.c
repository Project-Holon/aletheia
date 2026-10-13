/*
 * function: func_021B8AEC
 * address: 0x021B8AEC
 * packet: pkt_ov104_021B8AEC
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: named end-Y local stored before the shared X assignment yields the original 336-byte schedule.
 * symbols:
 *   func_020056EC 0x020056EC thumb
 *   func_021B8E8C 0x021B8E8C thumb ov104
 *   func_021B8DA4 0x021B8DA4 thumb ov104
 *   func_021B8D20 0x021B8D20 thumb ov104
 *   FX_SinCosTable_ 0x020A1B38 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef enum { COLOR_TWO=2, COLOR_FIVE=5 } Color;
typedef enum { END_Y=-36 } EndY;
typedef struct { int x; long y; } Point;
extern u32 func_020056EC(u32);
extern u32 func_021B8E8C(u8 *);
extern void func_021B8DA4(u8 *,const Point *,const Point *,int,u32);
extern void func_021B8D20(u8 *);
extern const s16 FX_SinCosTable_[];
#define W(o) (*(u32 *)(p+(o)))
#define SHIFT(v,n) ((int)((u32)(v)<<(n)))
static inline void initialize(Point *start,Point *end,int x,EndY endY)
{
    int yy=endY;
    end->y=yy;
    start->x=end->x=x;
    start->y=228;

}
void func_021B8AEC(u8 *p)
{
    Point end,start;
    int i,offset,angle;
    u32 life;
    Color color;
    u8 direction;
    switch(W(0x528)) {
    case 0:
        if(W(0x52c)++>W(0x530)) {
            W(0x52c)=0;
            for(i=0;i<30;++i) {
                offset=i*44;
                if(!func_021B8E8C(p+offset)) {
                    direction=func_020056EC(2);
                    initialize(&start,&end,func_020056EC(256),-36);
                    life=func_020056EC(50)+110;
                    color=2;
                    if(func_020056EC(2)) color=5;
                    if(direction) func_021B8DA4(p+offset,&start,&end,color,life);
                    else func_021B8DA4(p+offset,&end,&start,color,life);
                    break;
                }
            }
        }
        break;
    case 1: break;
    case 2:
        if(W(0x52c)++>W(0x530)) {
            W(0x52c)=0;
            for(i=0;i<30;++i) {
                offset=i*44;
                if(!func_021B8E8C(p+offset)) {
                    angle=(u16)func_020056EC(65535)>>4;
                    end.x=SHIFT(FX_SinCosTable_[angle*2],8)>>12;
                    end.y=SHIFT(FX_SinCosTable_[angle*2+1],8)>>12;
                    start.x=128;start.y=96;
                    life=func_020056EC(50)+110;
                    color=2;
                    if(func_020056EC(2)) color=5;
                    func_021B8DA4(p+offset,&end,&start,color,life);
                    break;
                }
            }
        }
        break;
    }
    for(i=0;i<30;++i) func_021B8D20(p+i*44);
}


