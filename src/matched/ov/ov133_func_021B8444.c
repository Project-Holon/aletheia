/*
 * function: func_021B8444
 * address: 0x021B8444
 * packet: pkt_ov133_021B8444
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: func_021F4B24 declared int here: its forwarded func_021F50D0 returns 0/1; original compares the returned r0 despite legacy void declarations.
 * symbols:
 *   func_021BA218 0x021BA218 thumb ov133
 *   func_021B8B78 0x021B8B78 thumb ov133
 *   func_021F50F4 0x021F50F4 thumb ov112
 *   func_021BA184 0x021BA184 thumb ov133
 *   func_021BA258 0x021BA258 thumb ov133
 *   func_021BA208 0x021BA208 thumb ov133
 *   d_021BA570 0x021BA570 data a4
 *   func_021F4F04 0x021F4F04 thumb ov112
 *   func_021B7458 0x021B7458 thumb ov133
 *   func_021BA148 0x021BA148 thumb ov133
 *   func_021BA124 0x021BA124 thumb ov133
 *   func_021BA228 0x021BA228 thumb ov133
 *   func_021BA22C 0x021BA22C thumb ov133
 *   func_021F4E8C 0x021F4E8C thumb ov112
 *   func_021F4ED4 0x021F4ED4 thumb ov112
 *   func_021BA21C 0x021BA21C thumb ov133
 *   func_021BA24C 0x021BA24C thumb ov133
 *   func_021F4EA4 0x021F4EA4 thumb ov112
 *   func_021F4EB4 0x021F4EB4 thumb ov112
 *   func_021BA254 0x021BA254 thumb ov133
 *   func_021F4B24 0x021F4B24 thumb ov112
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
typedef unsigned char u8;
typedef struct { int x,y,z; } Vec;
typedef struct { int x,y; } Pair;
extern const Vec d_021BA570;
extern u8 *func_021BA218(u8 *);
extern int func_021B8B78(u8 *,int);
extern int func_021F50F4(unsigned int);
extern u8 *func_021BA184(void *);
extern int func_021BA258(u8 *);
extern u8 *func_021BA208(u8 *);
extern void func_021F4F04(u8 *,Pair *);
extern void func_021B7458(void *,int *);
extern void func_021BA148(void *,u8 *);
extern void func_021BA124(void *,u8 *);
extern unsigned int *func_021BA228(u8 *);
extern void func_021BA22C(u8 *,const Pair *);
extern void func_021F4E8C(int,int,Vec *);
extern void func_021F4ED4(int,int,int);
extern void func_021BA21C(u8 *,const Pair *);
extern void func_021BA24C(u8 *,int);
extern void func_021F4EA4(int,int,Vec *);
extern void func_021F4EB4(int,int,short,short);
extern void func_021BA254(u8 *,int);
extern int func_021F4B24(u8 *);
void func_021B8444(u8 *p)
{
    Vec v, first, second;
    Pair pos, offset;
    u8 *sprite,*entry,*s;
    Pair *old;
    int state,depth;
    func_021BA218(*(u8 **)(p+0x38));
    sprite=func_021BA218(*(u8 **)(p+0x38));
    if(func_021B8B78(p,*(int *)(p+0x34))==1) {
        state=func_021F50F4(*(int *)(p+0x34));
        entry=func_021BA184(*(void **)(p+0x1824));
        while(entry) {
            if(state==func_021F50F4(func_021BA258(entry))) break;
            entry=func_021BA208(entry);
        }
        if(entry) {
            v=d_021BA570;
            s=func_021BA218(entry);
            func_021F4F04(s,&offset);
            func_021B7458(p,(int *)&pos);
            pos.x+=offset.x;
            pos.y+=offset.y;
            func_021BA148(*(void **)(p+0x1824),entry);
            func_021BA124(*(void **)(p+0x1820),entry);
            old=(Pair *)func_021BA228(entry);
            if(pos.x>0) v.x=(int)(0.5f+(float)(pos.x<<12));
            else v.x=(int)((float)(pos.x<<12)-0.5f);
            if(pos.y>0) v.y=(int)(0.5f+(float)(pos.y<<12));
            else v.y=(int)((float)(pos.y<<12)-0.5f);
            func_021BA22C(entry,old);
            func_021F4E8C(*(int *)(p+0x1884),(int)s,&v);
            func_021F4ED4(*(int *)(p+0x1884),(int)s,0);
            func_021BA21C(entry,&pos);
            func_021BA24C(entry,10);
            depth=0;
            entry=func_021BA184(*(void **)(p+0x1820));
            while(entry) {
                s=func_021BA218(entry);
                func_021F4EA4(*(int *)(p+0x1884),(int)s,&first);
                first.z=depth;
                func_021F4E8C(*(int *)(p+0x1884),(int)s,&first);
                depth-=1024;
                entry=func_021BA208(entry);
            }
        }
    }
    func_021BA148(*(void **)(p+0x1820),*(u8 **)(p+0x38));
    func_021BA124(*(void **)(p+0x1824),*(u8 **)(p+0x38));
    func_021F4EB4(*(int *)(p+0x1884),(int)sprite,4096,4096);
    func_021BA254(*(u8 **)(p+0x38),*(int *)(p+0x34));
    entry=func_021BA184(*(void **)(p+0x1824));
    depth=0;
    while(entry) {
        s=func_021BA218(entry);
        func_021F4EA4(*(int *)(p+0x1884),(int)s,&second);
        if(func_021F4B24(s)==1) second.z=depth+(102<<10);
        else if(func_021BA258(entry)==7 || func_021BA258(entry)==8) second.z=depth+(222<<10);
        else second.z=depth+(202<<10);
        func_021F4E8C(*(int *)(p+0x1884),(int)s,&second);
        depth-=1024;
        entry=func_021BA208(entry);
    }
}
