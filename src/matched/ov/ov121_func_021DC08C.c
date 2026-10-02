/*
 * function: func_021DC08C
 * address: 0x021DC08C
 * packet: pkt_ov121_021DC08C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * spelling: BF04 uses char-pointer arithmetic and a signed acc read, retaining the post-switch acc reload; raw integer address arithmetic was four bytes short.
 * interfaces: 02035C60's live r0 is consumed by this caller despite its legacy void definition.
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0203633C 0x0203633C arm
 *   func_02035C60 0x02035C60 arm
 *   func_020362DC 0x020362DC arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B404 0x0204B404 arm
 *   func_021DDF5C 0x021DDF5C thumb ov121
 *   func_021DBDB8 0x021DBDB8 thumb ov121
 *   func_021DBF04 0x021DBF04 thumb ov121
 *   func_021DA8B0 0x021DA8B0 thumb ov121
 *   func_021DC9CC 0x021DC9CC thumb ov121
 *   func_021D9E04 0x021D9E04 thumb ov121
 *   func_021DCCE4 0x021DCCE4 thumb ov121
 *   func_021DBA78 0x021DBA78 thumb ov121
 *   func_021DB528 0x021DB528 thumb ov121
 *   func_021DB478 0x021DB478 thumb ov121
 *   func_021DBA94 0x021DBA94 thumb ov121
 *   func_021DC4F0 0x021DC4F0 thumb ov121
 *   func_020061E4 0x020061E4 thumb
 *   data_021DF86E 0x021DF86E data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {short x,y;} Position;
typedef struct {u8 x,y,pad[6];} Coord;
extern const Coord data_021DF86E[];
extern void func_0204B3DC(void *,u32);
extern u32 func_0203633C(void);
extern int func_02035C60(void);
extern u32 func_020362DC(void);
extern void func_021DDF5C(void *);
extern void func_020061E4(int);
extern int func_021DBDB8(char *);
extern int func_021DBF04(void *);
extern void func_021DA8B0(void *,void *);
extern void func_021DC9CC(void);
extern void func_021DC4F0(void);
extern void func_021DCCE4(void);
extern void func_021D9E04(u8 *);
extern void func_021DBA78(char *,int);
extern void func_021DB528(char *,int);
extern void func_021DB478(char *,int,int,int,u16);
extern int func_021DBA94(char *);
extern void func_0204B878(void *,u32);
extern void func_0204B404(void *,Position *,u32);
static inline int wrap(int value,int low,int high)
{
    if(value>high) return low;
    if(value<low) return high;
    return value;
}
void func_021DC08C(void *task,u32 *state,char *p)
{
    u32 repeat;
    int delta,changed,count,next,direction;
    Position pos;
    switch(*state) {
    case 0:
        func_0204B3DC(*(void **)(p+0xaf4),1);
        func_0204B3DC(*(void **)(p+0xaf8),1);
        func_0204B3DC(*(void **)(p+0xaec),1);
        repeat=func_0203633C();
        changed=0;delta=0;
        if(func_02035C60()) {
            *(void **)(p+0xaac)=*(void **)((u32)p+0xa7c+(u16)(*(u32 *)(p+0xacc)+*(u32 *)(p+0xac8)*4)*4);
            if(*(void **)(p+0xaac)) func_021DDF5C(*(void **)(p+0xaac));
        }
        if(repeat==512) delta=-1;
        else if(repeat==256) delta=1;
        else if(repeat&64) {
            func_020061E4(0x548);
            switch(*(u32 *)(p+0xacc)) {
            case 0:
                if(*(int *)(p+0xae0)) *(u32 *)(p+0xacc)=2;
                else {*(int *)(p+0xae4)=1;*(u32 *)(p+0xacc)=4;}
                break;
            case 1:
                if(*(int *)(p+0xae0)) *(u32 *)(p+0xacc)=3;
                else {*(int *)(p+0xae4)=0;*(u32 *)(p+0xacc)=4;}
                break;
            case 2: *(u32 *)(p+0xacc)=0;break;
            case 3: *(u32 *)(p+0xacc)=1;break;
            case 4:
                if(*(int *)(p+0xae4)) *(u32 *)(p+0xacc)=2;
                else *(u32 *)(p+0xacc)=3;
                break;
            }
            changed=1;
        } else if(repeat&128) {
            func_020061E4(0x548);
            switch(*(u32 *)(p+0xacc)) {
            case 0: *(u32 *)(p+0xacc)=2;break;
            case 1: *(u32 *)(p+0xacc)=3;break;
            case 2:
                if(*(int *)(p+0xae0)) *(u32 *)(p+0xacc)=0;
                else {*(int *)(p+0xae4)=1;*(u32 *)(p+0xacc)=4;}
                break;
            case 3:
                if(*(int *)(p+0xae0)) *(u32 *)(p+0xacc)=1;
                else {*(int *)(p+0xae4)=0;*(u32 *)(p+0xacc)=4;}
                break;
            case 4:
                if(*(int *)(p+0xae4)) *(u32 *)(p+0xacc)=0;
                else *(u32 *)(p+0xacc)=1;
                break;
            }
            changed=1;
        } else if(repeat&32) {
            func_021DBDB8(p);
            if(*(u32 *)(p+0xacc)==0 || *(u32 *)(p+0xacc)==2) delta=-1;
            else if(*(u32 *)(p+0xacc)!=4) func_020061E4(0x548);
            if(*(u32 *)(p+0xacc)!=4) {
                if(*(u32 *)(p+0xacc)<=1) {
                    --*(u32 *)(p+0xacc);
                    *(u32 *)(p+0xacc)=wrap(*(u32 *)(p+0xacc),0,1);
                } else {
                    --*(u32 *)(p+0xacc);
                    *(u32 *)(p+0xacc)=wrap(*(u32 *)(p+0xacc),2,3);
                }
                changed=1;
            }
        } else if(repeat&16) {
            func_021DBDB8(p);
            if(*(u32 *)(p+0xacc)==1 || *(u32 *)(p+0xacc)==3) delta=1;
            else if(*(u32 *)(p+0xacc)!=4) func_020061E4(0x548);
            if(*(u32 *)(p+0xacc)!=4) {
                if(*(u32 *)(p+0xacc)<=1) {
                    ++*(u32 *)(p+0xacc);
                    *(u32 *)(p+0xacc)=wrap(*(u32 *)(p+0xacc),0,1);
                } else {
                    ++*(u32 *)(p+0xacc);
                    *(u32 *)(p+0xacc)=wrap(*(u32 *)(p+0xacc),2,3);
                }
                changed=1;
            }
        } else if(func_020362DC()&1) {
            if(*(u32 *)(p+0xacc)==4) {
                if(*(int *)(p+0xae0)==0) {
                    func_0204B3DC(*(void **)(p+0xaf4),0);
                    func_0204B3DC(*(void **)(p+0xaf8),0);
                    func_020061E4(0x54c);
                    func_021DA8B0(task,func_021DCCE4);
                }
            } else if(func_021DBF04(p+40+220*((u32)*(int *)(p+0xacc)+*(u32 *)(p+0xac8)*4))) {
                func_0204B3DC(*(void **)(p+0xaf4),0);
                func_0204B3DC(*(void **)(p+0xaf8),0);
                func_020061E4(0x54c);
                if(*(int *)(p+0xae0)) func_021DA8B0(task,func_021DC9CC);
                else func_021DA8B0(task,func_021DC4F0);
            }
        } else if(func_020362DC()&2) {
            func_020061E4(0x551);
            if(*(int *)(p+0xae0)) {
                if(*(u8 **)(p+0xabc)) {func_021D9E04(*(u8 **)(p+0xabc));*(void **)(p+0xabc)=0;}
                func_0204B3DC(*(void **)(p+0xaf0),0);
                *(int *)(p+0xae0)=0;
            } else {
                func_0204B3DC(*(void **)(p+0xaf4),0);
                func_0204B3DC(*(void **)(p+0xaf8),0);
                func_021DA8B0(task,func_021DCCE4);
            }
        }
        if(delta) {
            count=func_021DBDB8(p);
            if(delta<0) {
                if(*(int *)(p+0xac8)) next=*(int *)(p+0xac8)-1;
                else next=count-1;
                direction=1;
            } else if(delta>0) {
                if(*(int *)(p+0xac8)<count-1) next=*(int *)(p+0xac8)+1;
                else next=0;
                direction=0;
            }
            func_020061E4(0x642);
            func_021DBA78(p,direction);
            func_021DB528(p,0);
            func_021DB478(p,0,direction,next,*(u16 *)(p+36));
            *(int *)(p+0xac8)=next;
            func_0204B3DC(*(void **)(p+0xaec),0);
            func_0204B3DC(*(void **)(p+0xaf4),0);
            func_0204B3DC(*(void **)(p+0xaf8),0);
            *(u16 *)(p+0xbac)=0;
            *(int *)(p+0xa78)=1;
            *state=1;
        }
        if(changed) {
            if((int)*(u32 *)(p+0xacc)<4) {
                pos.x=data_021DF86E[*(u32 *)(p+0xacc)].x*8-24;
                pos.y=data_021DF86E[*(u32 *)(p+0xacc)].y*8-8;
                func_0204B878(*(void **)(p+0xaec),0);
            } else {
                pos.x=176;pos.y=152;
                func_0204B878(*(void **)(p+0xaec),11);
            }
            func_0204B404(*(void **)(p+0xaec),&pos,0);
            *(u16 *)(p+0xbac)=0;
            *(int *)(p+0xa78)=1;
        }
        break;
    case 1:
        if(func_021DBA94(p)) *state=0;
        break;
    }
}
