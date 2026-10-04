/*
 * function: func_021B96BC
 * address: 0x021B96BC
 * packet: pkt_ov225_021B96BC
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * lever: repeat shared constructor/store tails in their arms and keep done as int; enum done adds truncation pairs (584B/404 concrete).
 * trailing: separately matched callback021B98FC (2B) and two alignment bytes at021B98FE; lead576B.
 * attempts: four one calls in final retry; direct-goto enum baseline DIFF66/576, repeated tails enum DIFF404/584, wide store casts unchanged, repeated tails int EXACT*576.
 * symbols:
 *   func_0204E804 0x0204E804 arm
 *   func_0204E720 0x0204E720 arm
 *   func_021BB31C 0x021BB31C thumb ov225
 *   func_021BB308 0x021BB308 thumb ov225
 *   func_021BB6E0 0x021BB6E0 thumb ov225
 *   func_021BB844 0x021BB844 thumb ov225
 *   func_021BB7F4 0x021BB7F4 thumb ov225
 *   func_021BB2B4 0x021BB2B4 thumb ov225
 *   func_021BBA64 0x021BBA64 thumb ov225
 *   func_021BBA14 0x021BBA14 thumb ov225
 *   func_021B9BEC 0x021B9BEC thumb ov225
 *   func_021B9BE0 0x021B9BE0 thumb ov225
 *   func_021B9C98 0x021B9C98 thumb ov225
 *   func_021B9CB0 0x021B9CB0 thumb ov225
 *   func_021B9BC8 0x021B9BC8 thumb ov225
 *   func_021B9C0C 0x021B9C0C thumb ov225
 *   func_021B9CC8 0x021B9CC8 thumb ov225
 *   func_021B9BF8 0x021B9BF8 thumb ov225
 *   func_021BBA74 0x021BBA74 thumb ov225
 *   func_021BBB0C 0x021BBB0C thumb ov225
 *   func_021BBAE8 0x021BBAE8 thumb ov225
 *   func_021BB854 0x021BB854 thumb ov225
 *   func_021B9E60 0x021B9E60 thumb ov225
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum {ZERO=0,ONE=1} Flag;
extern int func_0204E804(void);
extern void func_0204E720(u32,int,int,int);
extern int func_021BB31C(char *);
extern void func_021BB308(char *);
extern char *func_021BB6E0(char *,char *);
extern int func_021BB844(char *);
extern void func_021BB7F4(char *);
extern char *func_021BB2B4(char *,char *);
extern int func_021BBA64(char *);
extern void func_021BBA14(char *);
extern u16 func_021B9BEC(char *,int);
extern u16 func_021B9BE0(char *,int);
extern int func_021B9C98(void *,int,int);
struct Big;
extern void func_021B9CB0(void *unused, int code, struct Big *save);
extern u16 func_021B9BC8(char *,int);
extern u16 func_021B9C0C(char *,int,int);
extern int func_021B9CC8(unsigned unused, unsigned key);
extern u16 func_021B9BF8(char *,int,int);
extern char *func_021BBA74(char *,char *);
extern int func_021BBB0C(char *);
extern void func_021BBAE8(char *p);
extern char *func_021BB854(char *,char *);
extern void func_021B9E60(char *);
int func_021B96BC(void *a,u32 *state,void *unused,char *p)
{
 int done;
 u32 count;
 u16 id,i,item,selected;
 switch(*state) {
 case 0: *state=1; break;
 case 1: if(!func_0204E804()) *state=2; break;
 case 2:
  done=0;
  switch(*(u32 *)(p+0x10)) {
  case 0:
   if(!func_021BB31C(*(char **)(p+0x1c))) goto innerDone;
   {
    if(*(u32 *)(p+0x18)<=1) {
     if(*(u32 *)(p+0x18)==0) *(u32 *)(*(char **)(p+4)+4)=0;
     else if(*(u32 *)(p+0x18)==1) *(u32 *)(*(char **)(p+4)+4)=1;
     done=1;
    } else {
     func_021BB308(*(char **)(p+0x1c));
     if(*(u32 *)(p+0x18)==2) {
      *(u32 *)(p+0x10)=1;
      *(u16 *)(p+0x20)=0; *(u16 *)(p+0x22)=0;
      *(char **)(p+0x2c)=func_021BB6E0(p+0x20,*(char **)(p+8));
     } else if(*(u32 *)(p+0x18)==3) {
      *(u32 *)(p+0x10)=2; *(u32 *)(p+0x30)=1;
      *(u16 *)(p+0x34)=done;
      *(u16 *)(p+0x36)=done; *(u16 *)(p+0x38)=done;
      *(char **)(p+0x44)=func_021BB854(p+0x30,*(char **)(p+8));
     }
    }
   }
   break;
  case 1:
   if(!func_021BB844(*(char **)(p+0x2c))) {
   default:
innerDone:
    break;
   } else {
    func_021BB7F4(*(char **)(p+0x2c));
    if(*(u32 *)(p+0x24)==0) {
     *(u32 *)(p+0x10)=done;
     *(char **)(p+0x1c)=func_021BB2B4(p+0x14,*(char **)(p+8));
    } else {
     *(u32 *)(p+0x10)=2; *(u32 *)(p+0x30)=0;
     *(u16 *)(p+0x34)=*(u16 *)(p+0x28);
     *(u16 *)(p+0x36)=done; *(u16 *)(p+0x38)=done;
     *(char **)(p+0x44)=func_021BB854(p+0x30,*(char **)(p+8));
    }
   }
   break;
  case 2:
   if(func_021BBA64(*(char **)(p+0x44))) {
    func_021BBA14(*(char **)(p+0x44));
    if(*(u32 *)(p+0x3c)==0) {
     if(*(u32 *)(p+0x30)==0) { *(u32 *)(p+0x10)=1; *(char **)(p+0x2c)=func_021BB6E0(p+0x20,*(char **)(p+8)); }
     else if(*(u32 *)(p+0x30)==1) { *(u32 *)(p+0x10)=done; *(char **)(p+0x1c)=func_021BB2B4(p+0x14,*(char **)(p+8)); }
    } else {
     *(u32 *)(p+0x10)=3;
     id=*(u16 *)(p+0x40);
     count=func_021B9BEC(*(char **)(*(char **)(p+8)+0x2c),id);
     selected=func_021B9BE0(*(char **)(*(char **)(p+8)+0x2c),id);
     if(!func_021B9C98(*(char **)(*(char **)(p+8)+0x2c),selected,**(int **)(p+8)))
      func_021B9CB0(*(char **)(*(char **)(p+8)+0x2c),selected,(struct Big *)(**(int **)(p+8)));
     *(u16 *)(p+0x4a)=func_021B9BC8(*(char **)(*(char **)(p+8)+0x2c),id);
     *(unsigned char *)(p+0x48)=func_021B9BEC(*(char **)(*(char **)(p+8)+0x2c),id);
     for(i=0;i<count;i++) {
      item=func_021B9C0C(*(char **)(*(char **)(p+8)+0x2c),id,i);
      if(!func_021B9CC8((unsigned int)(*(char **)(*(char **)(p+8)+0x2c)),item)) item=65535;
      *(u16 *)(p+i*4+0x4c)=item;
      *(u16 *)(p+i*4+0x4e)=func_021B9BF8(*(char **)(*(char **)(p+8)+0x2c),id,i);
     }
     *(char **)(p+0x74)=func_021BBA74(p+0x48,*(char **)(p+8));
    }
   }
   break;
  case 3:
   if(func_021BBB0C(*(char **)(p+0x74))) {
    func_021BBAE8(*(void **)(p+0x74));
    if(*(u32 *)(p+0x70)==0) {
     *(u32 *)(p+0x10)=2;
     *(char **)(p+0x44)=func_021BB854(p+0x30,*(char **)(p+8));
    }
   }
   break;
  }
  if(done) { *state=3; func_0204E720(3,0,16,0); }
  break;
 case 3: if(!func_0204E804()) *state=4; break;
 case 4: return 1;
 }
 func_021B9E60(*(char **)(p+8));
 return 0;
}
