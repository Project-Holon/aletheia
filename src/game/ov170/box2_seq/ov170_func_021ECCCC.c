/*
 * function: func_021ECCCC
 * address: 0x021ECCCC
 * packet: pkt_ov170_021ECCCC
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: 0202D7C8 reads and forwards only r0; legacy r1-r3 omitted.
 * prototype: 0202D8D0 stack mode is full-width in this caller, with no
 * truncation; its callee forwards the same low-halfword value.
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_02049238 0x02049238 arm
 *   func_0202D7C8 0x0202D7C8 thumb
 *   func_02017DBC 0x02017DBC thumb
 *   func_0202D934 0x0202D934 thumb
 *   func_0202D8D0 0x0202D8D0 thumb
 *   func_0202D9A4 0x0202D9A4 thumb
 *   func_02017DE4 0x02017DE4 thumb
 *   func_021EBEE0 0x021EBEE0 thumb ov170
 *   func_021EC000 0x021EC000 thumb ov170
 *   d_021EFD80 0x021EFD80 data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern int func_0202D7C8(int);
struct Sav;
extern u32 func_02017DBC(struct Sav *p);
extern int func_0202D934(int,void *,int,int,u16);
extern int func_0202D8D0(int,void *,int,int,u32,u16);
extern u32 func_0202D9A4(u32,u32,u32,u32,u16);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern void func_02049238(int);
extern void *func_021EBEE0(char *,const void *);
extern void func_021EC000(char *,int,int);
extern const char d_021EFD80[];
#define W(p) (*(char **)((p)+44))
void func_021ECCCC(char *p,void **mon,int index)
{
    int *bmp,*cell,*anim;
    int other;
    int mode;
    int archive,state;
    if (*(u16 *)(W(p)+0xA164)==0) {
        bmp=(int *)(W(p)+0xA088);cell=(int *)(W(p)+0xA10C);
        anim=(int *)(W(p)+0xA138);mode=96;other=index+1;
    } else {
        bmp=(int *)(W(p)+0xA08C);cell=(int *)(W(p)+0xA110);
        anim=(int *)(W(p)+0xA13C);mode=128;other=index;index++;
    }
    if (*(void **)((W(p)+index*4)+0x9E74)) {
        func_0204B3B4(*(void **)((W(p)+index*4)+0x9E74));
        func_0204A8D4(*bmp);func_0204ADA4(*cell);func_0204AFD8(*anim);
    }
    archive=func_0202D7C8(76);
    state=func_02017DBC(*mon);
    *bmp=func_0202D934(archive,*mon,0,1,76);
    *cell=func_0202D8D0(archive,*mon,0,1,mode,76);
    *anim=func_0202D9A4((u32)*mon,0,2,1,76);
    func_02017DE4(*mon,state);func_02049238(archive);
    *(void **)((W(p)+index*4)+0x9E74)=func_021EBEE0(W(p),d_021EFD80+24*(u32)index);
    func_021EC000(W(p),index,1);
    if (*(void **)((W(p)+other*4)+0x9E74)) func_021EC000(W(p),other,0);
    *(u16 *)(W(p)+0xA164)^=1;
}
