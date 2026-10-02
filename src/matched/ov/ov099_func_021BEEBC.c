/*
 * function: func_021BEEBC
 * address: 0x021BEEBC
 * packet: pkt_ov099_021BEEBC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: a named enabled result before kind initialization preserves call/store scheduling.
 * symbols:
 *   func_02155664 0x02155664 thumb ov009
 *   func_021BEE64 0x021BEE64 thumb ov099
 *   func_020490F4 0x020490F4 arm
 *   func_021C19A8 0x021C19A8 thumb ov099
 *   func_021C0290 0x021C0290 thumb ov099
 *   func_02082BCC 0x02082BCC arm
 *   func_020452E8 0x020452E8 arm
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 *   func_021B96CC 0x021B96CC thumb ov099
 *   func_02012944 0x02012944 thumb
 *   func_02008550 0x02008550 thumb
 *   func_02009A54 0x02009A54 thumb
 *   func_021B95A0 0x021B95A0 thumb ov099
 *   func_021B9900 0x021B9900 thumb ov099
 *   func_021BE21C 0x021BE21C thumb ov099
 *   func_021C1A44 0x021C1A44 thumb ov099
 *   func_021C1A58 0x021C1A58 thumb ov099
 *   func_021C282C 0x021C282C thumb ov099
 *   func_021C205C 0x021C205C thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021BE788 0x021BE788 thumb ov099
 *   func_021BEDA0 0x021BEDA0 thumb ov099
 *   func_021BDD0C 0x021BDD0C thumb ov099
 *   func_02049238 0x02049238 arm
 *   func_0202208C 0x0202208C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_02155664(void (*)(void));
extern void func_021BEE64(void);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_021C19A8(char *);
extern void func_021C0290(char *);
extern void func_02082BCC(void *,int,int);
extern void func_020452E8(void *);
extern void func_0202020C(void *,void *,void *);
extern void func_0201F868(void *);
extern int func_021B96CC(char *);
extern void *func_02012944(void *);
extern int func_02008550(void *);
extern unsigned func_02009A54(void *);
extern void func_021B95A0(char *,int,void *,int,int,int,void *,void *);
extern void *func_021B9900(char *,int);
extern void func_021BE21C(char *,void *);
extern int func_021C1A44(char *);
extern void func_021C1A58(char *,int,int);
extern int func_021C282C(void *);
extern void func_021C205C(char *,int);
extern void func_021BA8EC(char *);
extern int func_021BE788(char *);
extern void func_021BEDA0(char *);
extern void func_021BDD0C(char *,int);
extern void func_02049238(void *);
extern void func_0202208C(void *,int,int,int,int,int,int);
void func_021BEEBC(char *p)
{
    void *h;
    int kind, enabled;
    func_02155664(func_021BEE64);
    h=func_020490F4(33,33);
    func_021C19A8(p);
    func_021C0290(p);
    func_02082BCC(p+0x30,0,32);
    if(*(void **)(p+0xb0)){
        func_020452E8(*(void **)(p+0x1a0));
        func_0202020C(*(void **)(p+0xb4),0,0);
        *(void **)(p+0xb4)=0;
        func_0201F868(*(void **)(p+0xb0));
        *(void **)(p+0xb0)=0;
    }
    if(!func_021B96CC(p+0x274)){
        enabled=func_02008550(func_02012944(*(void **)(p+0xc4)));
        kind=16;
        if(enabled)kind=17;
        *(u16 *)(p+0x132a)=func_02009A54(*(void **)(p+4));
        func_021B95A0(p+0x274,33,h,kind,*(u16 *)(p+0x132a),33,*(void **)(p+0x110),*(void **)(p+0x114));
        func_021BE21C(p,func_021B9900(p+0x274,kind));
    }
    if(!func_021C1A44(p))func_021C1A58(p,(int)h,33);
    func_021C282C(*(void **)(p+8));
    *(u8 *)(p+0x1351)=0;
    func_021C205C(p,33);
    func_021BA8EC(p);
    func_021BE788(p);
    func_021BEDA0(p);
    func_021BDD0C(p,0);
    *(int *)(p+0x1f0)=-1;
    func_02049238(h);
    func_0202208C(0,1,1,0,6,1,33);
}
