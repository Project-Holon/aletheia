/*
 * function: func_021B77EC
 * address: 0x021B77EC
 * packet: pkt_ov104_021B77EC
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 021B7DD4 tail-forwards live r0 from u32 0201C4E4; caller reads it.
 * symbols:
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   func_021B8EB0 0x021B8EB0 thumb ov104
 *   func_021B7DD4 0x021B7DD4 thumb ov104
 *   func_021B7EE4 0x021B7EE4 thumb ov104
 *   func_021B795C 0x021B795C thumb ov104
 *   func_021B8AEC 0x021B8AEC thumb ov104
 *   func_021B71E4 0x021B71E4 thumb ov101
 *   func_021B63D0 0x021B63D0 thumb ov101
 */
#include "../include/Obj07987.h"
#include "../include/Obj22214.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void FADE_Start(u32,int,int,int);
extern int FADE_IsActive(void);
extern void func_021B8EB0(u8 *);
extern int func_021B7DD4(u8 *);
extern int func_021B7EE4(u8 *p, u8 *q);
extern void func_021B795C(u8 *p);
extern void func_021B8AEC(u8 *);
extern void func_021B71E4(int);
typedef struct { u8 pad[0x78]; int busy; u8 pad7c[6]; unsigned short counter; } Obj;
struct Obj;
extern int func_021B63D0(struct Obj *p);
int func_021B77EC(void *a,u32 *state,void *b,u8 *p) {
 switch(*state) {
 case 0: *state=1; break;
 case 1: FADE_Start(3,16,0,0); *state=2; break;
 case 2: if(!FADE_IsActive()) *state=3; break;
 case 3: (*(void (**)(u8 *,unsigned short *))(p+0x804))(p,(unsigned short *)(p+0x808)); if(((struct Obj07987 *)p)->f80C) *state=4; func_021B8EB0(p+0x7cc); break;
 case 4: FADE_Start(3,0,16,0); *state=5; break;
 case 5: if(!FADE_IsActive()) *state=6; break;
 case 6: return 1;
 }
 if(func_021B7DD4(p+0xbc)) { func_021B7EE4(p+0xcc,p+0xbc); func_021B7EE4(p+0x7dc,p+0xbc); func_021B7EE4(p+0x7f0,p+0xbc); }
 func_021B795C(p);
 func_021B8AEC(p+0x278);
 if(!((struct Obj07987 *)p)->f8AC) func_021B71E4(((struct Obj07987 *)p)->f7AC);
 func_021B63D0((struct Obj *)(*(Obj * *)&((struct Obj22214 *)(*(u8 * *)&((struct Obj07987 *)p)->f8B0))->f4));
 return 0;
}
