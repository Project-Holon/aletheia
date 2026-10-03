/*
 * function: func_021D7224
 * address: 0x021D7224
 * packet: pkt_ov123_021D7224
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: update the call-result local in both clamp arms to preserve its register.
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02030734 0x02030734 arm
 *   func_02082D44 0x02082D44 arm
 *   d_021DAB78 0x021DAB78 data a1
 *   func_02009290 0x02009290 thumb
 *   func_020092F8 0x020092F8 thumb
 *   func_020093D4 0x020093D4 thumb
 */
typedef unsigned short u16;
typedef signed int     s32;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sub02009210Obj;
struct Sub02009448Obj;
extern struct Sub02009448Obj *func_02009448(void *sys);
extern void func_020307B0(void *);
extern int func_020076D0(void *,void *,void *);
extern u32 func_020173EC(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 *func_02009290(struct Sub02009210Obj *obj);
extern void func_02082D44(void *,void *,int);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_02019CA0(void *p, u32 v);
extern void *func_020185F4(void *p);
extern void func_020074D8(void *,int);
extern void func_020092F8(struct Sub02009210Obj *obj, u8 value);
extern void func_020093D4(struct Sub02009210Obj *obj, s32 value);
extern const char d_021DAB78[];
void func_021D7224(char *p)
{
    void *g;
    void *q;
    int size;
    int n;
    g=func_02009448(*(void **)(p+0x28));
    if (*(void **)(p+0xc)) {
        func_020307B0(*(void **)(p+0xc));
        *(void **)(p+0xc)=0;
    }
    if (func_020076D0(*(void **)(p+0x24),p+0x48,p+0x4c)) {
        q=func_02030734(*(u16 *)p,func_020173EC(),1,d_021DAB78,0x245);
        size=func_020173EC();
        func_02082D44(func_02009290(g),q,size);
        if (*(int *)(p+0x6c)) {
            n=func_02017E1C(q,158,0);
            if (n==100) *(int *)(p+0x6c)=0;
            if (n+*(int *)(p+0x6c)>100) {
                *(int *)(p+0x6c)=100-n;
                n=100;
            } else {
                n+=*(int *)(p+0x6c);
            }
            func_02019CA0(q,n);
        }
        func_020074D8(*(void **)(p+0x24),(int)func_020185F4(q));
        *(void **)(p+0xc)=q;
        func_020092F8(g,0);
        func_020093D4(g,*(int *)(p+0x7c));
    }
}
