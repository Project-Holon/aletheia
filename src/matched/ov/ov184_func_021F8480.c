/*
 * function: func_021F8480
 * address: 0x021F8480
 * packet: pkt_ov184_021F8480
 * region: ov184
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ov112_id 0x00000070 data
 *   func_02034AC4 0x02034AC4 arm
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0201C440 0x0201C440 thumb
 *   func_021FC4DC 0x021FC4DC thumb ov186
 *   func_02025538 0x02025538 thumb
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200A5F8 0x0200A5F8 thumb
 *   func_0200A640 0x0200A640 thumb
 *   func_021F88A4 0x021F88A4 thumb ov184
 *   func_021F891C 0x021F891C thumb ov184
 *   func_021FD6D8 0x021FD6D8 thumb ov186
 *   func_021F85DC 0x021F85DC thumb ov184
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02034AC4(int);
extern char ov112_id[];
extern u16 func_021F9B9C(void *);
extern char *func_0203159C(void *,u32,u32);
extern void func_02082BCC(void *,int,unsigned);
extern u32 func_0201C440(void *);
extern void *func_021FC4DC(void *);
extern void *func_02025538(u32,u32);
extern void *func_021FD760(void *,int,int,u16);
extern int func_02012EBC(int);
extern int func_0200A5F8(int);
extern int func_0200A640(int);
extern void func_021F88A4(char *,char *);
extern void func_021F891C(char *,char *);
extern void *func_021FD6D8(char *,void *,u32);
extern void func_021F85DC(int,int *,char *);
int func_021F8480(void *obj,int b,char *q)
{
    char *p;
    void *v;
    int i;
    func_02034AC4((int)ov112_id);
    p=func_0203159C(obj,0x34,func_021F9B9C(*(void **)(q+0x10)));
    func_02082BCC(p,0,0x34);
    *(u16 *)(p+0x24)=func_021F9B9C(*(void **)(q+0x10));
    *(char **)(p+0x30)=q;
    *(u32 *)(p+0x20)=func_0201C440((void *)(unsigned int)*(u16 *)(p+0x24));
    v=func_021FC4DC(*(void **)(q+8));
    *(void **)(p+0x1c)=func_02025538(*(u16 *)(p+0x24),(u32)v);
    for (i=0;i<2;i++) *(void **)(p+i*4+0x14)=func_021FD760(v,*(int *)(q+0xc),i,*(u16 *)(p+0x24));
    *(int *)(p+0x28)=func_0200A640(func_0200A5F8(func_02012EBC(*(int *)(q+0x18))));
    func_021F88A4(p,q);
    func_021F891C(p,q);
    *(void **)(p+0xc)=func_021FD6D8(p,func_021F85DC,*(u16 *)(p+0x24));
    return 1;
}
