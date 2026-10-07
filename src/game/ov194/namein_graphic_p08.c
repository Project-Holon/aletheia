/*
 * file:     namein_graphic_p08.c
 * unit:     yes
 * function: func_021F2818, func_021F2828, func_021F2884, func_021F28FC, func_021F299C
 * address:  0x021F2818
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F2F8C 0x021F2F8C thumb ov194
 *   func_021F2F60 0x021F2F60 thumb ov194
 *   d_021F5544 0x021F5544 data a4
 *   d_021F5550 0x021F5550 data a4
 */
#include "../../matched/include/Obj14501.h"

typedef struct {int x,y;} Pair;

typedef int (*Conv)(Pair *, Pair *);

typedef struct {int x,y,z,w;} Box;

extern int func_021F2F8C(Pair *p, Pair *out);
extern int func_021F2F60(const int *p, int *out);
void func_021F2818(char *a, int b, int c);
int func_021F2828(const char *p,int target,Pair *out);
void func_021F2884(Pair *p, int oldmode, int newmode);
int func_021F28FC(const int *p,int *out);
int func_021F299C(Pair *p,Box *out);
extern const int d_021F5544[],d_021F5550[];

void func_021F2818(char *a, int b, int c)
{
    ((void (*)(int, int))(*(void **)(a + 0x14)))(b, c);
}

int func_021F2828(const char *p,int target,Pair *out) {
 Pair xy;
 for(xy.y=0;xy.y<=*(const unsigned short *)&((struct Obj14501 *)p)->f22;xy.y++)
 for(xy.x=0;xy.x<=*(const unsigned short *)&((struct Obj14501 *)p)->f20;xy.x++)
 if(((int (*)(int *,int *))*(void *const *)(p+0x1C))(&xy.x,0)==target) {*out=xy;return 1;}
 return 0;
}

/*
 * note: the original has no else arm: when neither mode is 3 it falls into
 *   the call with r2 (= newmode), r4, r5 and [sp,#4] never assigned
 *   (021F289A bne -> 021F28A6 skips the height store). The C leaves from/to/
 *   width/height unassigned on that path exactly as the image does; the
 *   earlier `else return;` spelling was a guard the original lacks.
 */
void func_021F2884(Pair *p, int oldmode, int newmode)
{
    Conv from;
    Conv to;
    int width, height, result;
    Pair xy;
    if (oldmode == 3) {
        from = func_021F2F8C;
        to = (Conv)func_021F2F60;
        width = 13;
        height = 5;
    } else if (newmode == 3) {
        from = (Conv)func_021F2F60;
        to = func_021F2F8C;
        width = 11;
        height = 4;
    }
    result = from(p, 0);
    for (xy.y = 0; xy.y <= height; xy.y++)
        for (xy.x = 0; xy.x <= width; xy.x++)
            if (to(&xy, 0) == result) {
                *p = xy;
                return;
            }
}

int func_021F28FC(const int *p,int *out) {
 int xy[2];enum { X_LEFT=15,X_RIGHT=22 } x;int y;
 switch(func_021F2F60(p,xy)) {
 case 1:case 10:case 11:
 x=xy[0]*2+3;out[0]=x;y=xy[1]*3+5;out[1]=y;out[2]=x+2;out[3]=y+3;break;
 case 2:case 3:case 4:case 5:
 x=(p[0]+1)*3;out[0]=x;y=p[1]*3+5;out[1]=y;out[2]=x+3;out[3]=y+3;break;
 case 6:x=15;out[0]=x;y=p[1]*3+5;out[1]=y;out[2]=x+7;out[3]=y+3;break;
 case 7:x=22;out[0]=x;y=p[1]*3+5;out[1]=y;out[2]=x+7;out[3]=y+3;break;
 case 0:return 0;
 case 8:case 9:break;
 }
 if(p[1]==5 && p[0]>6)return 0;return 1;
}

/*
 * lever: case 0 follows case 9; repeated stores in each case-8 arm preserve backward tail sharing.
 */
int func_021F299C(Pair *p,Box *out)
{
 Pair xy;
 switch((unsigned)func_021F2F8C(p,&xy)) {
 case 1:out->x=d_021F5544[xy.y]+xy.x*2;out->y=d_021F5550[xy.y];out->z=out->x+2;out->w=out->y+3;break;
 case 2:case 3:case 4:case 5:out->x=(p->x+1)*3;out->y=20;out->z=out->x+3;out->w=out->y+3;break;
 case 6:out->x=25;out->y=8;out->z=out->x+4;out->w=out->y+3;break;
 case 7:out->x=24;out->y=12;out->z=out->x+5;out->w=out->y+3;break;
 case 8:if(p->x==0){out->x=3;out->y=16;out->z=out->x+4;out->w=out->y+3;}else {out->x=23;out->y=16;out->z=out->x+4;out->w=out->y+3;}break;
 case 9:out->x=15;out->y=20;out->z=out->x+12;out->w=out->y+3;break;
 case 0:return 0;
 }
 switch(p->y) {
 case 1:if(p->x>9)return 0;break;
 case 2:if(p->x>9)return 0;break;
 case 3:if(p->x>4)return 0;break;
 }
 return 1;
}
