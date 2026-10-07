/*
 * file:     unit_021B7560_p09.c
 * unit:     yes
 * function: func_021B8C3C, func_021B8D08
 * address:  0x021B8C3C
 * region:   ov104
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020056EC 0x020056EC thumb
 *   func_0207CA00 0x0207CA00 arm
 *   func_0207CCA4 0x0207CCA4 arm
 *   func_021B8E8C 0x021B8E8C thumb ov104
 *   func_021B8DA4 0x021B8DA4 thumb ov104
 *   g_020A1B38 0x020A1B38 data a2
 *   func_02082BCC 0x02082BCC arm
 */
#define SHIFT(v,n) ((int)((u32)(v)<<(n)))
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef unsigned int u32;

typedef struct { int x,y,z; } Vec;

typedef struct { int x,y; } Point;

extern u32 func_020056EC(u32);
extern void func_0207CA00(const Vec *,const Vec *,Vec *);
extern void func_0207CCA4(const Vec *,Vec *);
extern u32 func_021B8E8C(u8 *);
extern void func_021B8DA4(u8 *,const Point *,const Point *,int,u32);
extern void func_02082BCC(void *,unsigned char,unsigned int);
void func_021B8C3C(u8 *p, const void *a, int color);
void func_021B8D08(unsigned int *p, unsigned int a, int b);
extern const s16 g_020A1B38[];

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
                func_0207CCA4(&delta,&delta);
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

void func_021B8D08(unsigned int *p, unsigned int a, int b) { func_02082BCC(p,0,44); p[0]=a; p[1]=b; }
