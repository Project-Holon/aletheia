/*
 * function: func_021E2070
 * address: 0x021E2070
 * packet: pkt_ov119_021E2070
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E0DA0 0x021E0DA0 thumb ov119
 *   func_021E0DBC 0x021E0DBC thumb ov119
 *   func_02017E1C 0x02017E1C thumb
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int a,b,c,d; } Quad;
extern void func_021E0DA0(void *);
extern void func_021E0DBC(char *,void *,int,int,int,int,int,u16);
extern u32 func_02017E1C(void *,u32,u32);
extern void func_0204B3DC(void *,u32);
void func_021E2070(char *p,void *mon,Quad *t)
{
    u32 a,b;
    func_021E0DA0(p+0x900+t->a*20);
    func_021E0DA0(p+0x900+t->b*20);
    func_021E0DBC(p+0x900+t->a*20,mon,0,*(int *)(p+0x9c4),176,95,0,*(u16 *)(p+0x5f4));
    a=func_02017E1C(mon,174,0);
    b=func_02017E1C(mon,175,0);
    if(a!=b)
        func_021E0DBC(p+0x900+t->b*20,mon,1,*(int *)(p+0x9c4),210,95,0,*(u16 *)(p+0x5f4));
    if(*(void **)(p+t->c*20+0x910))
        func_0204B3DC(*(void **)(p+t->c*20+0x910),0);
    if(*(void **)(p+t->d*20+0x910))
        func_0204B3DC(*(void **)(p+t->d*20+0x910),0);
}
