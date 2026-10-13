/*
 * function: func_021B95A0
 * address: 0x021B95A0
 * packet: pkt_ov222_021B95A0
 * region: ov222
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * checks: 1 own callee bodies/forwarders and SDK-mode read rederived arities; 2 fresh own9748 and R1 ov221 constructor twin read; 3 BGMode counter with named enum-zero and uncast mode call; 4 enum-zero and enum-counter idioms cover lever; 5 fresh full idiom listing/neighbours. One MATCH424 and required TU MATCH424; sole unresolved ARM9 witness remains.
 * residual: concrete-correct MATCH424, 35/36 relocations resolved; +00AA ARM9 func_02043588 has no witness; required TU --suggest-split leaves whole caller OUT.
 * blocker: ARM902043588 omitted from src/matched/arm9/unit_02043570.c's function header; integrator-owned.
 *   Verified EXACT16 ARM C preserved from prior parked ov214021BAD14 / ov133021B69AC; R1 reverified this wave:
 *   extern void func_02043558(void),func_02043570(void);
 *   void func_02043588(void) {func_02043558();func_02043570();}
 * volatile: 021B9638..021B9648 BLDCNT store and two DISPCNT reads/writes.
 * prototype: 3159C leaves allocation result in r0; original consumes it despite legacy void declaration.
 * lever: BGMode i=BG_MODE0, uncast func_0207D518(i), enum do-while one-trip resource loop restores +00AE register copy.
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021B9F10 0x021B9F10 thumb ov222
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_0204047C 0x0204047C arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021B98FC 0x021B98FC thumb ov222
 *   func_021B9900 0x021B9900 thumb ov222
 *   func_021B9964 0x021B9964 thumb ov222
 *   func_021B9C1C 0x021B9C1C thumb ov222
 *   func_021B9CE4 0x021B9CE4 thumb ov222
 *   func_02012944 0x02012944 thumb
 *   func_02043588 0x02043588 arm
 *   func_0207D518 0x0207D518 arm
 *   func_02043558 0x02043558 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   func_02043598 0x02043598 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_021B9D84 0x021B9D84 thumb ov222
 *   func_0204E720 0x0204E720 arm
 *   func_0203D34C 0x0203D34C arm
 *   tbl_021BA1F4 0x021BA1F4 data a4
 *   tbl_021BA360 0x021BA360 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 id;u8 cfg[32];u32 type,enable;} Row;
extern const Row tbl_021BA1F4[];
typedef struct {u32 a,b,c;} Assets;
extern Assets tbl_021BA360[];
struct BgTemplate;
struct Obj;
extern void func_0203064C(u32 a, u32 b, u32 c);
struct Obj0203159C;
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void*,int,u32);
extern void *func_021B9F10(u32,u32);
struct GfFont;
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void*);
extern void func_0204047C(int,u16);
extern void *func_020056A0(u32,void*,u32);
extern void func_021B98FC(void);
extern void func_021B9900(char*);
extern void func_021B9964(struct Obj *p);
extern void func_021B9C1C(char*);
extern void func_021B9CE4(char*);
extern char *func_02012944(void*);
typedef enum { BG_MODE0=0, BG_MODE1=1 } BGMode;
extern void func_02043588(void),func_02043558(void),func_0207D518(BGMode);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
extern void func_02043598(u32,u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void*,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void*,u32,u32,u32,u32,u32,u16);
extern void func_02049238(void*);
extern void func_021B9D84(char *p);
extern void func_0204E720(u32,int,int,int),func_020409B4(u32),func_0203D34C(u32,u32),func_02005E30(u32);
int func_021B95A0(void *owner,void *unused,void *input)
{
 char *p,*settings;
 BGMode i;
 int selected,zero;
 const Row *row;
 u32 id;
 u16 heap;
 void *h;
 func_0203064C((u32)((void*)1),131,0x30000);
 p=func_0203159C(owner,88,131);
 i=BG_MODE0;
 func_02082BCC(p,i,88);
 *(u16*)p=131;
 *(void**)(p+4)=input;
 *(void**)(p+8)=func_021B9F10(1,*(u16*)p);
 *(void**)(p+12)=func_0201D7EC(23,0,0,0,*(u16*)p);
 *(u32*)(p+16)=func_0201C440((void*)*(u16*)p);
 func_0204047C(1,1);func_0204047C(2,0);
 *(void**)(p+20)=func_020056A0((u32)func_021B98FC,p,1);
 func_021B9900(p);func_021B9964((struct Obj *)p);func_021B9C1C(p);func_021B9CE4(p);
 settings=func_02012944(*(void**)(*(char**)(p+4)));
 *(volatile u16*)0x04001050=i;
 *(volatile u32*)0x04001000 &= ~0xe000u;
 *(volatile u32*)0x04001000 |= 0x10000;
 func_02043588();func_0207D518(i);func_02043558();
 do {
  row=&tbl_021BA1F4[i];id=row->id;
  func_0203FCA0((u8)id,(const struct BgTemplate *)row->cfg,(u8)row->type);func_020414AC(id);func_02040588(id,row->enable);
  i++;
 } while((u32)i<1u);
 func_02043598(16,1);
 heap=*(u16*)p;
 selected=1;if(*(u8*)(settings+29)!=1) selected=0;
 h=func_020490F4(30,heap);
 zero=0;
 func_02049B68(h,tbl_021BA360[selected].a,4,zero,zero,heap);
 func_02049658(h,tbl_021BA360[selected].b,4,zero,zero,zero,heap);
 func_020498F4(h,tbl_021BA360[selected].c,4,zero,zero,zero,heap);
 func_02049238(h);func_020409B4(4);func_021B9D84((char *)p);
 func_0204E720(3,16,16,0);func_0203D34C(0,*(u16*)p);
 if(*(int*)(*(char**)(p+4)+4)==0) func_02005E30(6);
 return 1;
}
