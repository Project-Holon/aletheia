/*
 * function: func_021B7D80
 * address: 0x021B7D80
 * packet: pkt_ov180_021B7D80
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 func_0204B258; all concrete bytes match, 29/30 sites resolve.
 *   src/matched/arm9/unit_0204B22C.c defines sub_0204B258 but its function:
 *   line lists only sub_0204B22C. Ilias must add the missing unit entry.
 *   Scratch one --arm, dsi/1.1p1 -O4,p -lang c99: EXACT, 24 bytes, no sites.
 *   Verified C:
 *   typedef unsigned char u8;
 *   typedef unsigned int u32;
 *   struct Bank {
 *       u8 pad00[8]; void *f8; u8 pad0c[2];
 *       u8 source:4; u8 mode:4; u8 pad0f[9];
 *   };
 *   void func_0204B258(struct Bank *bank,void *p) {
 *       bank->f8=p;
 *       bank->source=1;
 *   }
 * arity: caller consumes live r0 after void 75A4/2DA48/2DA18;
 *   B0F4 forwards caller-loaded object and flag to BE38; 2DA04's unused
 *   trailing parameters are neither supplied nor read/forwarded in its body.
 * symbols:
 *   func_021B7C78 0x021B7C78 thumb ov180
 *   func_0204B034 0x0204B034 arm
 *   func_0204B0F4 0x0204B0F4 arm
 *   func_0204B258 0x0204B258 arm
 *   func_021B75A4 0x021B75A4 thumb ov180
 *   func_021B746C 0x021B746C thumb ov180
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_02008550 0x02008550 thumb
 *   func_0202DA04 0x0202DA04 thumb
 *   func_0202DA48 0x0202DA48 thumb
 *   func_0202DA18 0x0202DA18 thumb
 *   func_0202DA6C 0x0202DA6C thumb
 *   func_021B79F4 0x021B79F4 thumb ov180
 *   d_021B82B4 0x021B82B4 data a4
 *   d_021B8204 0x021B8204 data a4
 *   d_021B81EC 0x021B81EC data a4
 *   d_021B824C 0x021B824C data a4
 *   d_021B8264 0x021B8264 data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { u32 w[8]; } Setup;
struct Actor; struct Bank; struct Player;
extern const Setup d_021B82B4;
extern const char d_021B8204[],d_021B81EC[],d_021B824C[],d_021B8264[];
extern void func_021B7C78(char *);
struct Obj;
struct Sub0200852CObj;
extern struct Obj *func_0204B034(u8 *a0, u32 a1, u32 heap);
extern void func_0204B0F4(struct Actor *a0, int a1);
extern void func_0204B258(struct Bank *,void *);
extern u32 func_021B75A4(char *,const char *);
extern void func_021B746C(int *,int,int);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern signed int func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern int func_0204AF28(void *,u32,u32,u32);
extern void func_02049238(u8 *);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern int func_0202DA04(int);
extern u32 func_0202DA48(u32,u32,u32,u32);
typedef signed int     s32;
extern s32 func_0202DA18(u32 a, u32 b, u32 c, u32 d, u16 e);
extern int func_0202DA6C(int,int,int,int);
extern void func_021B79F4(char *);
void func_021B7D80(char *p) {
    Setup s;
    u8 *h;
    int mode;
    func_021B7C78(p);
    s=d_021B82B4;
    *(struct Actor **)(p+0x9118)=(struct Actor *)func_0204B034((u8 *)&s,2,141);
    func_0204B0F4(*(struct Actor **)(p+0x9118),1);
    func_0204B258(*(struct Bank **)(p+0x9044),*(void **)(p+0x9118));
    *(u32 *)(p+0x9064)=func_021B75A4(p,d_021B8204);
    *(u32 *)(p+0x9068)=func_021B75A4(p,d_021B81EC);
    func_021B746C((int *)p,7,0); func_021B746C((int *)p,8,0);
    h=func_020490F4(216,0x808d);
    *(int *)(p+0x90e0)=func_0204A6C8(h,25,0,1,141);
    *(u32 *)(p+0x90fc)=func_0204ABF0(h,3,1,0,141);
    *(int *)(p+0x9114)=func_0204AF28(h,27,33,141);
    func_02049238(h);
    mode=1;
    if(!func_02008550((const struct Sub0200852CObj *)(*(struct Player **)(*(char **)p+4)))) mode=0;
    h=(u8 *)func_0202DA04(0x808d);
    *(u32 *)(p+0x90d8)=func_0202DA48((u32)h,mode,0,141);
    *(u32 *)(p+0x90f4)=func_0202DA18((u32)h,mode,0,192,141);
    *(int *)(p+0x910c)=func_0202DA6C(mode,2,0,141);
    *(u32 *)(p+0x90dc)=func_0202DA48((u32)h,mode,1,141);
    *(u32 *)(p+0x90f8)=func_0202DA18((u32)h,mode,1,96,141);
    *(int *)(p+0x9110)=func_0202DA6C(mode,0,1,141);
    func_02049238(h);
    *(u32 *)(p+0x905c)=func_021B75A4(p,d_021B824C);
    *(u32 *)(p+0x9060)=func_021B75A4(p,d_021B8264);
    func_021B79F4(p);
}
