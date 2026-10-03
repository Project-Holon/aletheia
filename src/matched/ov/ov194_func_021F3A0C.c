/*
 * function: func_021F3A0C
 * address: 0x021F3A0C
 * packet: pkt_ov194_021F3A0C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Integer address arithmetic for26E0 avoids caching p+D8 across2818.
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_020355C4 0x020355C4 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021F2818 0x021F2818 thumb ov194
 *   func_021F2614 0x021F2614 thumb ov194
 *   func_021F26E0 0x021F26E0 thumb ov194
 *   func_021F1A1C 0x021F1A1C thumb ov194
 */
typedef unsigned char u8;
typedef struct {int x,y;} Pair;
typedef struct {int left,top,right,bottom;} Rect;
extern unsigned func_020362DC(void),func_021F2614(char *,int *,unsigned short *);
extern u8 func_020355C4(void);
extern void func_020355D8(u8),func_020061E4(unsigned);
extern int func_021F2818(char *,int,int);
extern void func_021F26E0(char *,int,int);
extern void func_021F1A1C(char *,int,const Rect *,int,int);
int func_021F3A0C(char *p,int *out)
{
    Rect rect;
    Pair delta;
    Pair point;
    int changed=0;
    if(*(int *)(p+0x118)==0){
        if(func_020362DC()&64){delta.x=0;delta.y=-1;changed=1;}
        else if(func_020362DC()&128){delta.x=0;delta.y=1;changed=1;}
        else if(func_020362DC()&32){delta.x=-1;delta.y=0;changed=1;}
        else if(func_020362DC()&16){delta.x=1;delta.y=0;changed=1;}
    }
    if(changed){
        point=*(Pair *)(p+0xD8);
        func_021F26E0(p,(int)&point,(int)&delta);
        if(func_021F2614(p,&point.x,0)-2<=3){
            if(func_020355C4()==1){
                if(func_021F2818(p,(int)(p+0xD8),(int)&rect)){
                    func_020061E4(1352);func_020355D8(0);
                    func_021F1A1C(p+0x24,1,&rect,*(int *)(p+0x104),*(int *)(p+0x100));
                }
            }else{
                func_021F26E0(p,(int)p+0xD8,(int)&delta);
                if(func_021F2818(p,(int)(p+0xD8),(int)&rect)){
                    func_020061E4(1352);
                    func_021F1A1C(p+0x24,1,&rect,*(int *)(p+0x104),*(int *)(p+0x100));
                }
            }
        }
    }
    return 0;
}
