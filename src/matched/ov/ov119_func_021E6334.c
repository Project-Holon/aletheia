/*
 * function: func_021E6334
 * address: 0x021E6334
 * packet: pkt_ov119_021E6334
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * initialization: both coordinate arms initialize x/y; z/a/b are stored before creation.
 * domain: primary calls 021D9084, 021DD670 and 021E25FA prove i=0..1,j=0..2. Wrappers 021D90AC/C0/D4 supply j=0/1/2; 021DD428 returns -1 or 0..2 and caller rejects -1; 021E24E8 has bounded 2x3 loops. Table row i*3+j=0..5 and byte offset i*12+j*4=0..20.
 * interface: 0204B294's fifth full-word payload is a Create address; its body forwards unchanged to 0204CFDC's request pointer. r0 is consumed after that void-declared wrapper.
 * interface: 020185F0 is an empty forwarder; caller supplies r0 and consumes its unchanged pointer result at 021E6346.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02049238 0x02049238 arm
 *   func_021E62D4 0x021E62D4 thumb ov119
 *   d_021E7D70 0x021E7D70 data a4
 *   d_021E7DA0 0x021E7DA0 data a4
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { short x,y,z; u8 a,b; } Create;
extern const int d_021E7D70[6][2];
extern const int d_021E7DA0[6][2];
extern void *func_020185F0(void *);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_021E62D4(void *,int,int);
extern u32 func_0201BA68(void *);
extern int func_0204A6C8(u32,u32,u32,u32,u16);
struct Obj;
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern int func_0201BBE8(void *);
extern void func_0204B6F4(int,u32,u32);
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(int,u32);
extern void func_02049238(int);
void func_021E6334(char *p,int i,int j,void *mon,int selected,u32 visible)
{
    Create c;
    void *q = func_020185F0(mon);
    void *h = func_020490F4(7,*(u16 *)(p+0x5f4));
    int n;
    func_021E62D4(p,i,j);
    if (selected) {
        c.x=d_021E7D70[i*3+j][0]; c.y=d_021E7D70[i*3+j][1]; n=0;
    } else {
        c.x=d_021E7DA0[i*3+j][0]; c.y=d_021E7DA0[i*3+j][1]; n=1;
    }
    c.z=1; c.a=16; c.b=1;
    *(int *)(p+0x1020+i*12+j*4) = func_0204A6C8((u32)h,func_0201BA68(q),0,n,*(u16 *)(p+0x5f4));
    *(int *)(p+0x1008+i*12+j*4) = (int)func_0204B294((void *)*(int *)(p+0x9c4),*(int *)(p+0x1020+i*12+j*4),*(int *)(p+0x890),*(int *)(p+0x8c0),&c,n,*(u16 *)(p+0x5f4));
    func_0204B6F4(*(int *)(p+0x1008+i*12+j*4),func_0201BBE8(q),1);
    func_0204B92C((struct Obj *)*(int *)(p+0x1008+i*12+j*4),0);
    func_0204B3DC(*(int *)(p+0x1008+i*12+j*4),visible);
    func_02049238((int)h);
}
