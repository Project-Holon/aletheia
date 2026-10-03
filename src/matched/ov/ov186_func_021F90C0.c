/*
 * function: func_021F90C0
 * address: 0x021F90C0
 * packet: pkt_ov186_021F90C0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Lever: name the zero after allocation; initialise the second flag before FC3BC, not at entry (first spelling DIFF 46 bytes).
 * abi: caller consumes 0203159C's live r0 at 021F90E0, overriding its void matched signature.
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021FC3BC 0x021FC3BC thumb ov186
 *   func_02012F08 0x02012F08 thumb
 *   func_0200C3E0 0x0200C3E0 thumb
 *   func_021FB884 0x021FB884 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021F99CC 0x021F99CC thumb ov186
 *   func_021FE6C0 0x021FE6C0 thumb ov186
 *   func_021FE7B4 0x021FE7B4 thumb ov186
 *   func_021FC224 0x021FC224 thumb ov186
 *   func_021FE7F4 0x021FE7F4 thumb ov186
 *   func_021FE7F8 0x021FE7F8 thumb ov186
 *   func_021FC4DC 0x021FC4DC thumb ov186
 *   func_021FED50 0x021FED50 thumb ov186
 *   func_021F98F8 0x021F98F8 thumb ov186
 *   func_021FF408 0x021FF408 thumb ov186
 *   func_02034AC4 0x02034AC4 arm
 *   func_0203CD98 0x0203CD98 arm
 *   func_0203D34C 0x0203D34C arm
 *   func_02012A30 0x02012A30 thumb
 *   func_02028A58 0x02028A58 thumb
 *   func_02005D90 0x02005D90 thumb
 *   func_021FEE9C 0x021FEE9C thumb ov186
 *   func_021FEE4C 0x021FEE4C thumb ov186
 *   func_021FE840 0x021FE840 thumb ov186
 *   d_02200254 0x02200254 data a4
 *   ov125_id 0x0000007D data
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern char ov125_id[];
extern const char d_02200254[];
extern void func_0203064C(void *,u32,u32),func_02082BCC(void *,int,unsigned);
extern char *func_0203159C(void *,u32,u32);
extern void *func_021FC3BC(int,int,int),*func_02012F08(int *),*func_021FB884(unsigned,unsigned,unsigned);
extern u8 func_0200C3E0(void *);
extern void func_021FB964(int,int,u16);
extern void *func_021F99CC(unsigned,void *,unsigned,unsigned,unsigned *,u16);
extern int *func_021FE6C0(unsigned);
extern void func_021FE7B4(char *),func_021FE7F4(int *,int),func_021FE7F8(char *,int);
extern int func_021FC224(char *),func_021FC4DC(int);
extern char *func_021FED50(int,int,char *,unsigned);
extern void func_021F98F8(char *,int,int,int);
extern void *func_021FF408(void *,int,unsigned);
extern int func_02034AC4(int),func_0203CD98(void);
extern void func_0203D34C(u32,u32);
extern u32 func_02012A30(const void *);
extern void func_02028A58(void *,u8,u16),func_02005D90(u32,u16);
extern void func_021FEE9C(int),func_021FEE4C(int),func_021FE840(int,int,int);
int func_021F90C0(void *obj,int unused,char *q)
{
    char *p;
    int flag=1;
    unsigned mode;
    int enabled;
    int zero;
    func_0203064C((void *)1,0x5a,0x90000);
    p=func_0203159C(obj,0x1c,0x5a);
    zero=0;
    func_02082BCC(p,0,0x1c);
    *(char **)(p+0x18)=q;
    *(int *)(*(char **)(q+12)+12)=zero;
    if(**(int **)(*(char **)(p+0x18)+12)!=2) flag=zero;
    enabled=1;
    *(void **)p=func_021FC3BC(flag,1,0x5a);
    mode=func_0200C3E0(func_02012F08(*(int **)(*(char **)(*(char **)(p+0x18)+12)+4)));
    if(**(int **)(*(char **)(p+0x18)+12)) enabled=0;
    *(void **)(p+4)=func_021FB884(mode,enabled,0x5a);
    func_021FB964(*(int *)(p+4),0,0x5a);
    func_021FB964(*(int *)(p+4),1,0x5a);
    *(void **)(p+8)=func_021F99CC(0,(void *)d_02200254,0xd,(unsigned)p,(unsigned *)(*(u32 *)(*(char **)(p+0x18)+8)+0x1728),0x5a);
    *(int **)(p+12)=func_021FE6C0(0x5a);
    func_021FE7B4(*(char **)(p+12));
    func_021FE7F4(*(int **)(p+12),func_021FC224(*(char **)(p+4)));
    if(!*(int *)(*(char **)(p+0x18)+4)) func_021FE7F8(*(char **)(p+12),3);
    *(char **)(p+16)=func_021FED50(func_021FC4DC(*(int *)p),*(int *)(p+12),*(char **)(p+4),0x5a);
    func_021F98F8((char *)(*(u32 *)(*(char **)(p+0x18)+8)+0x1748),1,*(int *)(*(char **)(*(char **)(p+0x18)+12)+4),0x5a);
    if(**(int **)(*(char **)(p+0x18)+12)) {
        *(void **)(p+20)=func_021FF408(*(void **)(*(char **)(*(char **)(p+0x18)+12)+4),*(int *)(*(char **)(*(char **)(p+0x18)+12)+8),0x5a);
    } else func_02034AC4((int)ov125_id);
    if(func_0203CD98()) func_0203D34C(0,0x5a);
    if(!**(int **)(*(char **)(p+0x18)+12)) {
        if(*(int *)(*(char **)(p+0x18)+4)!=1) func_02028A58((void *)func_02012A30(*(void **)(*(char **)(*(char **)(p+0x18)+12)+4)),0x40,0);
    } else func_02005D90(0x484,0xffff);
    if(*(int *)(*(char **)(p+0x18)+4)==1) {
        func_021FEE9C(*(int *)(p+16));func_021FEE4C(*(int *)(p+16));
        func_021FE840(*(int *)(p+12),3,0);
    }
    return 1;
}
