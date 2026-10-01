/*
 * function: func_021F6F64
 * address: 0x021F6F64
 * packet: pkt_ov215_021F6F64
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02047E88 0x02047E88 arm
 *   func_021F66C8 0x021F66C8 thumb ov215
 *   func_020489F4 0x020489F4 arm
 *   func_02048A18 0x02048A18 arm
 *   func_020477A4 0x020477A4 arm
 *   func_0204784C 0x0204784C arm
 *   d_021F7330 0x021F7330 data a4
 */
typedef unsigned short u16;
struct Util; struct Setup; struct Record; struct G3dSys; struct AnmCtl;
extern const struct Setup d_021F7330;
extern u16 func_02047E88(struct Util *,const struct Setup *);
extern struct Record *func_021F66C8(unsigned,unsigned);
extern unsigned func_020489F4(unsigned char *,int);
extern unsigned func_02048A18(unsigned char *,int);
extern unsigned func_020477A4(struct G3dSys *,unsigned);
extern unsigned func_0204784C(struct AnmCtl *,unsigned,int *);
void func_021F6F64(char *p)
{
    unsigned id;
    char *entry;
    u16 i;
    void *q;
    int frame;
    *(u16 *)(p+0x4c)=func_02047E88(*(struct Util **)(p+0x48),&d_021F7330);
    *(u16 *)(p+0x50)=1;
    *(struct Record **)(p+0x54)=func_021F66C8(*(u16 *)p,*(u16 *)(p+0x50));
    id=func_020489F4(*(unsigned char **)(p+0x48),*(u16 *)(p+0x4c));
    *(u16 *)(p+0x4e)=0;
    entry=*(char **)(p+0x54);
    *(u16 *)entry=id;
    *(int *)(entry+4)=0;
    *(int *)(entry+8)=0;
    *(int *)(entry+12)=0;
    *(int *)(entry+0x40)=1;
    for(i=0;i<*(u16 *)(p+0x50);i++)
        func_020477A4((struct G3dSys *)func_02048A18(*(unsigned char **)(p+0x48),*(u16 *)(*(char **)(p+0x54)+i*68)),0);
    *(int *)(p+0x58)=0;
    q=(void *)func_02048A18(*(unsigned char **)(p+0x48),*(u16 *)(*(char **)(p+0x54)+*(u16 *)(p+0x4e)*68));
    frame=0;
    *(int *)(p+0x5c)=0;
    func_020477A4((struct G3dSys *)q,1);
    func_020477A4((struct G3dSys *)q,2);
    func_0204784C((struct AnmCtl *)q,1,&frame);
    func_0204784C((struct AnmCtl *)q,2,&frame);
}
