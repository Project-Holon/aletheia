/*
 * function: func_021E0980
 * address: 0x021E0980
 * packet: pkt_ov119_021E0980
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_021D8FA4 0x021D8FA4 thumb ov119
 *   func_0201A954 0x0201A954 thumb
 *   func_0201A98C 0x0201A98C thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200CDE0 0x0200CDE0 thumb
 *   func_020076A4 0x020076A4 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_0202136C 0x0202136C thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021E0958 0x021E0958 thumb ov119
 *   func_021E0A64 0x021E0A64 thumb ov119
 */
typedef unsigned short u16;
typedef unsigned char u8;
extern int func_021D8AA8(void *);
extern void *func_021D8FA4(void *,int);
typedef signed int     s32;
typedef unsigned int   u32;
struct Blk37;
struct Party;
struct PartyMon;
extern void func_0201A954(struct Party *p, s32 capacity);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void *func_0200CA1C(void *);
extern void func_0200CDE0(struct Blk37 *p, void *m);
extern u8 func_020076A4(void *);
extern void *func_0201AB28(void *p, u32 idx);
extern unsigned func_02017E1C(void *,unsigned,unsigned);
extern u32 func_0202136C(u16 v);
extern void func_02045CAC(int,int,int),func_021E1024(void *),func_021D8E84(void *,int),func_021E0958(void *),func_021E0A64(void *);
void func_021E0980(char *p)
{
    int i;
    void *mon;
    int z;
    char *t;
    if(func_021D8AA8(p)) {
        i=*(int *)(p+0xfa0)%3;
        mon=func_021D8FA4(p,0);
        *(u16 *)(*(char **)(p+8)+0x28)=*(int *)(p+i*4+0xfbc);
        *(u16 *)(*(char **)(p+8)+0x2a)=*(int *)(p+i*4+0xfa4);
    } else {
        mon=func_021D8FA4(p,1);
        *(u16 *)(*(char **)(p+8)+0x28)=*(int *)(p+0xf88);
        *(u16 *)(*(char **)(p+8)+0x2a)=*(int *)(p+0xf84);
    }
    func_0201A954(*(void **)(*(char **)(p+8)+0x1c),6);
    func_0201A98C(*(void **)(*(char **)(p+8)+0x1c),mon);
    func_0200CDE0(func_0200CA1C(*(void **)(p+0x82c)),mon);
    t=*(char **)(p+8);
    if(*(u16 *)(t+0x28)!=func_020076A4(*(void **)(p+0x828))) {
        z=0;
        if(func_0202136C(func_02017E1C(func_0201AB28(*(void **)(t+0x1c),0),6,0))) {
            func_02045CAC(*(int *)(p+0x720),106,*(int *)(p+0x738));
            func_021E1024(p);
            func_021D8E84(p,(int)func_021E0958);
            *(int *)(p+0xf2c)=z;
            return;
        }
    }
    func_021D8E84(p,(int)func_021E0A64);
}
