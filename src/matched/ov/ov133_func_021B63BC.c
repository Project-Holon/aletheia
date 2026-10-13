/*
 * function: func_021B63BC
 * address: 0x021B63BC
 * packet: pkt_ov133_021B63BC
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: both display updates belong inside the counter reset guard; byte counter is +18c1, flag word +18d0. Correct pointer base +187c and descriptor +18ec; typed sentinel/window fields prevent raw-offset CSE.
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   func_021B9818 0x021B9818 thumb ov133
 *   func_021B8A30 0x021B8A30 thumb ov133
 *   func_021B98A0 0x021B98A0 thumb ov133
 *   func_021B75E0 0x021B75E0 thumb ov133
 *   func_021B9C08 0x021B9C08 thumb ov133
 *   func_021B918C 0x021B918C thumb ov133
 *   func_021B940C 0x021B940C thumb ov133
 *   func_021B9784 0x021B9784 thumb ov133
 *   func_021FCDEC 0x021FCDEC thumb ov132
 *   func_021FCE00 0x021FCE00 thumb ov132
 *   func_021FD6A4 0x021FD6A4 thumb ov132
 *   func_021B9F5C 0x021B9F5C thumb ov133
 *   func_021B8C6C 0x021B8C6C thumb ov133
 *   func_021F51E8 0x021F51E8 thumb ov112
 *   func_021F51F4 0x021F51F4 thumb ov112
 *   func_021F4990 0x021F4990 thumb ov112
 *   CLACT_DrawSystem 0x0204A600 arm
 *   func_02047964 0x02047964 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   BILLBOARD_Draw 0x0204F7DC arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_0204152C 0x0204152C arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_021B9C90 0x021B9C90 thumb ov133
 *   func_0201F73C 0x0201F73C thumb
 *   func_021BA0C8 0x021BA0C8 thumb ov133
 *   func_0204047C 0x0204047C arm
 *   func_0204989C 0x0204989C arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_020452E8 0x020452E8 arm
 *   func_021BA20C 0x021BA20C thumb ov133
 *   func_021B9CBC 0x021B9CBC thumb ov133
 *   func_0201C6B4 0x0201C6B4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 prefix[0x18c1]; u8 counter; u16 timer,pad18c4; u8 brightness,pad; u32 mode,busy,flag; u16 sentinel; u8 pad18d6[0x16]; u32 window; } Context;
#define W(k) (*(u32 *)((u8 *)p+(k)))
#define H(k) (*(u16 *)((u8 *)p+(k)))
#define B(k) (*(u8 *)((u8 *)p+(k)))
#define P(k) (*(u8 **)((u8 *)p+(k)))
extern void func_020061E4(u32);
extern u32 WIPE_SYS_EndCheck(void);
extern int GFL_USE_IsBgmFading(void);
extern void GFL_USE_FadeOutBgm(u32);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern void func_021B9818(u8 *),func_021B8A30(u8 *),func_021B98A0(u8 *),func_021B75E0(u8 *);
extern void func_021B9C08(u8 *,u32,void *),func_021B918C(u8 *),func_021B9784(u8 *);
extern int func_021B940C(u8 *);
extern void func_021FCDEC(int,int);
struct Board;
struct Camera;
struct Cfg;
struct Descriptor;
struct Lights;
struct O;
struct PrintSys;
extern int func_021FCE00(char *p, int id);
extern int func_021FD6A4(char *p);
extern void func_021B9F5C(u8 *);
extern void func_021B8C6C(struct O *p);
extern void func_021F51E8(u8 *);
extern void func_021F51F4(void **p);
extern void func_021F4990(void *);
extern void CLACT_DrawSystem(void),func_02047964(void),G3D_SYSTEM_ApplyLookAt(void),G3D_SYSTEM_DrawEnd(void);
extern void BILLBOARD_Draw(struct Board *b, struct Camera *cam, struct Lights *lights);
extern void func_02041EE4(u32,u32,u32);
extern void func_0204152C(int,u16);
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
extern void func_021B9C90(u8 *),func_0201F73C(void *,int,int,int),func_021BA0C8(u8 *,u8);
extern void func_0204047C(int,u16),func_0204989C(u32,u32,u32,u32,u32,u32,u16),func_02041B6C(u32);
extern void func_0201C6EC(struct PrintSys *p);
extern u32 func_020452E8(struct Descriptor *d);
struct Descriptor;
extern u32 func_021BA20C(u8 *p);
extern void func_021B9CBC(u8 *,u8 *);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern u32 func_0200FB24(void);
struct Obj;
extern void func_0204B3DC(struct Obj *,unsigned int);
static inline void brightness(u8 *value)
{
    func_02041EE4(6,0,128-*value);
    func_02041EE4(5,0,*value-128);
}
int func_021B63BC(Context *p)
{
    void *desc;
    switch(W(0x0c)) {
    case 7:
        func_020061E4(1358); W(0x0c)=8;
    case 8:
        if(WIPE_SYS_EndCheck()==1) {
            if(W(0x1840)==1) func_021B9818((u8 *)p);
            else W(0x0c)=1;
        }
        if(W(0x98)==1) func_021B8A30((u8 *)p);
        break;
    case 9:
        if(WIPE_SYS_EndCheck()==1 && GFL_USE_IsBgmFading()==0) return 2;
        break;
    case 0: func_021B98A0((u8 *)p); break;
    case 1: func_021B75E0((u8 *)p); break;
    case 2:
        W(0x10)+=6;
        if((int)W(0x10)>=192) {
            func_021B9C08((u8 *)p,1,0); W(0x10)=192; W(0x0c)=3;
            H(0x1838)=0; H(0x183a)=0; H(0x18c4)=0;
        }
        func_021B918C((u8 *)p); break;
    case 6:
        W(0x10)-=6;
        if((int)W(0x10)<0) { W(0x10)=0; W(0x0c)=1; }
        func_021B918C((u8 *)p); break;
    case 3:
        if(func_021B940C((u8 *)p)==2) { W(0x0c)=10; B(0x18c0)=0; func_0204B3DC((struct Obj *)P(0x18b0),1); }
        break;
    case 10:
        B(0x18c0)++; func_021B9784((u8 *)p);
        if(B(0x18c0)>60) {
            if(*(u32 *)P(4)==0) {
                WIPE_SYS_Start(0,0,0,0x7fff,18,1,H(0)); GFL_USE_FadeOutBgm(60); W(0x0c)=9; p->mode=1;
            } else {
                func_021B9C08((u8 *)p,2,0); func_021FCDEC(*(int *)P(4),69); W(0x0c)=4;
            }
        }
        break;
    case 4:
        if(func_021FCE00(*(void **)P(4),69)==1) W(0x0c)=5;
        break;
    case 5:
        if(func_021FD6A4(*(void **)P(4))==1) {
            WIPE_SYS_Start(0,0,0,0x7fff,18,1,H(0)); GFL_USE_FadeOutBgm(60); W(0x0c)=9; p->mode=1;
        }
        break;
    }
    func_021B9F5C((u8 *)p); func_021B8C6C((struct O *)p); func_021F51E8(P(0x187c));
    func_021F4990(P(0x1884)); CLACT_DrawSystem(); func_02047964(); G3D_SYSTEM_ApplyLookAt();
    func_021F51F4((void **)P(0x187c)); BILLBOARD_Draw((struct Board *)P(0x188c),(struct Camera *)P(0x1888),0); G3D_SYSTEM_DrawEnd();
    p->counter++;
    if(p->counter>1) {
        p->counter=0;
        func_02041EE4(3,1,1); func_02041EE4(3,5,1);
    }
    if(p->mode==0) {
        if(p->brightness<128) { p->brightness+=8; brightness(&p->brightness); }
        else if(p->flag==0) {
            p->flag=1; func_0204152C(7,0);
            p->window=BMP_WIN_Create(7,1,19,30,4,14,1);
            if(W(0x1840)==0) func_021B9C90((u8 *)p); else func_021B9C08((u8 *)p,6,0);
            func_0201F73C((u8 *)p->window,1,128,12);
        }
    } else {
        if(p->flag==1) {
            func_021BA0C8((u8 *)p,2); p->flag=0;
            func_0204047C(7,3); func_0204047C(4,0); func_0204047C(5,1); func_0204047C(6,2);
            func_021BA0C8((u8 *)p,4); func_0204989C(46,13,7,0,0,0,H(0)); func_02041B6C(7);
            p->busy=0; func_0201C6EC((struct PrintSys *)P(0x18e8)); func_020452E8((struct Descriptor *)p->window); p->window=0; func_021BA0C8((u8 *)p,6);
        } else if(p->brightness!=0) {
            func_021BA0C8((u8 *)p,p->brightness+96); p->brightness-=8; brightness(&p->brightness);
        }
    }
    func_021BA0C8((u8 *)p,8);
    if(p->busy==0 && W(0x0c)==1) {
        if(P(0x38)!=0 && p->sentinel!=*(u16 *)func_021BA20C(P(0x38))) {
            func_021B9CBC((u8 *)p,P(0x38)); p->sentinel=*(u16 *)func_021BA20C(P(0x38));
        } else if(p->sentinel!=255 && P(0x38)==0) { func_021B9C90((u8 *)p); p->sentinel=255; }
    }
    func_021BA0C8((u8 *)p,10);
    if(p->busy==1 && func_0201C6B4((const struct PrintSys *)P(0x18e8))==1) {
        p->busy=0; desc=(u8 *)p->window;
        BMP_WIN_TransferChars(desc); BMP_WIN_MakeScreen(desc); func_02041B6C(func_02045730(desc));
        func_0204047C(4,1); func_0204047C(5,2); func_0204047C(6,3); func_0204047C(7,0);
    }
    func_021BA0C8((u8 *)p,12);
    if(P(0x18e8)!=0) PRINTSYS_QUE_Main((struct PrintSys *)P(0x18e8));
    func_021BA0C8((u8 *)p,14);
    if(H(0x18c2)!=0) H(0x18c2)--;
    if(*(u32 *)P(4)!=0 && W(0x0c)!=7 && W(0x0c)!=8 && W(0x0c)!=9) {
        func_021BA0C8((u8 *)p,32);
        if(func_0200FB24()!=0) {
            func_021BA0C8((u8 *)p,34); WIPE_SYS_Start(0,0,0,0x7fff,18,1,H(0)); GFL_USE_FadeOutBgm(60);
            func_021BA0C8((u8 *)p,36); W(0x0c)=9; func_021BA0C8((u8 *)p,38);
        } else func_021BA0C8((u8 *)p,64);
    }
    func_021BA0C8((u8 *)p,16);
    return 0;
}
