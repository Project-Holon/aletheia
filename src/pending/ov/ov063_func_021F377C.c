/*
 * function: func_021F377C
 * address: 0x021F377C
 * packet: pkt_ov063_021F377C
 * region: ov063
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * checks: 1 own B7A84/B7D50 and narrowed ov010/ov021 callers confirm arities; 2 matched 36C0/3758/376C and neighbours refreshed; 3 unsigned table Cell and signed local Cell reduce DIFF1166 to 730, raw halfword buffer worse 1466/+24, const vector inputs retained; 4 grouped vector stores and reversed stack-local declarations tried (two scheduling variants), stack-object/fixed-float idioms read; 5 fresh idioms and neighbours, no new twin. Next: original height spill and frame layout; leave ov021 blockers to Ilias.
 * runs: W75 five fixed one runs plus baseline explain and first permuter300; prior four fixed runs retained as history, not repeated.
 * residual: 730 concrete bytes; compiled 1528, original code/pool ends 021F3D74 (1528, delta 0); handed 1572 includes trailing rodata. Relocations 77/79: ov021 B3D0/B388 unresolved and Ilias-owned, not filed.
 * search: macro-free emitted baseline agrees DIFF730/1528. Permuter300 best DIFF663 rejected: tmp2 = s->scene lies after case0 break and is bypassed by case1; tmp = s->delta.y lies after case4 break and is bypassed by case5. Both cases read uninitialized temporaries. Search consumed; do not repeat.
 * note: recoup 2026-10-05 (P26L1): lane size 30 B was a label gap; real extent 1528 B (021F377C..021F3D74). Residue read from listing: the original keeps height (func_021B7D50 result) in a stack slot [sp,#0xc] and holds &cell (add r6,sp,#0x1c, computed inside the cell copy, used as adds r1,r6,#0 for the first func_021BB3C4 call) in r6 across that call; compiled keeps height in r6 and builds the address at the call. That one spill gives the 4-byte larger frame (sub sp,#0x74 with push r3 dropped) and shifts every later sp offset, so most of the 730 bytes are offset shift, not new logic. Tried: Cell *cp local for both the first call and the loop (identical output, mwcc propagates the address), pragmas opt_lifetimes/opt_propagation/opt_common_subs/scheduling off (1136/1338/1272/730, worse or equal). The two ov021 relocations: func_021BB3D0 has a matched file src/matched/ov/ov072_func_021BB3D0.c, the ov072 token resolves it but raises the diff to 734 B (the ov072 copy is a different function body at that address), so ov021 stays; func_021BB388 also unwitnessed. Next: find a source form that keeps an address live across the height call without a stand-in.
 * note: recoup 2026-10-05 P30R9 (11 compiles, all DIFF 730 or worse): real callee types from matched callers (func_021AB0F8 returns u16 takes u32, func_021BB3C4 returns u32): 730, no change. const on BB3C4 / B7D50 record pointer: 730. Inline helper blocked(scene,cell) for both attribute tests: 730. Inline fetch(&cell,s) for the cell copy-in: 730. Cell *cp local set before the height call and used in the first BB3C4 call, set once or set again in the loop: 730 (mwcc propagates every single-use or repeated &cell, so the early add r6,sp,#0x1c is not a pointer variable in the source; it must come from a CSE of an address expression in the copy block, no source form found). Pragmas opt_dead_assignments off 1337, peephole off 730. s->end.y store moved after the scale line: 763. Frame facts: original spill slots are bound [sp,#4], case-5 temp [sp,#8], height [sp,#0xc], terrain [sp,#0x10], scale hi word [sp,#0x14]; compiled has no height slot (r6) and bound/temp swapped, so the 4-byte frame difference is exactly the missing height spill, caused by r6 being held by the cell address across func_021B7D50.
 * symbols:
 *   func_0219E764 0x0219E764 thumb ov021
 *   func_0207CDB8 0x0207CDB8 arm
 *   func_021B8028 0x021B8028 thumb ov021
 *   func_021BB480 0x021BB480 thumb ov021
 *   func_021B7A84 0x021B7A84 thumb ov021
 *   func_021B7D50 0x021B7D50 thumb ov021
 *   func_021BB3C4 0x021BB3C4 thumb ov021
 *   func_021AB0F8 0x021AB0F8 thumb ov021
 *   func_021B7D38 0x021B7D38 thumb ov021
 *   func_0207CA00 0x0207CA00 arm
 *   func_0207CBD0 0x0207CBD0 arm
 *   func_0207CCA4 0x0207CCA4 arm
 *   func_0207C768 0x0207C768 arm
 *   func_0207D14C 0x0207D14C arm
 *   func_0218F0A8 0x0218F0A8 thumb ov021
 *   func_0218F0E8 0x0218F0E8 thumb ov021
 *   func_0218EC54 0x0218EC54 thumb ov021
 *   func_0218E13C 0x0218E13C thumb ov021
 *   func_0218E124 0x0218E124 thumb ov021
 *   func_0218ECE4 0x0218ECE4 thumb ov021
 *   func_0218ECB4 0x0218ECB4 thumb ov021
 *   func_021BB3D0 0x021BB3D0 thumb ov021
 *   func_0218EC5C 0x0218EC5C thumb ov021
 *   func_0218EC90 0x0218EC90 thumb ov021
 *   func_0218ECF4 0x0218ECF4 thumb ov021
 *   func_020061E4 0x020061E4 thumb
 *   func_0216D568 0x0216D568 thumb ov010
 *   func_021AC528 0x021AC528 thumb ov021
 *   func_021A3044 0x021A3044 thumb ov021
 *   func_0216D89C 0x0216D89C thumb ov010
 *   func_02006148 0x02006148 thumb
 *   func_020061F8 0x020061F8 thumb
 *   func_021A36B0 0x021A36B0 thumb ov021
 *   func_021A36D4 0x021A36D4 thumb ov021
 *   func_021BB260 0x021BB260 thumb ov021
 *   func_021BB388 0x021BB388 thumb ov021
 *   func_0219E2C0 0x0219E2C0 thumb ov021
 *   func_0216D570 0x0216D570 thumb ov010
 *   func_0216DB4C 0x0216DB4C thumb ov010
 *   func_0216DC98 0x0216DC98 thumb ov010
 *   func_0216DAE0 0x0216DAE0 thumb ov010
 *   func_0216DB04 0x0216DB04 thumb ov010
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef long long s64;
typedef struct {int x,y,z;} Vec;
typedef struct {s16 x,y,z;} SmallVec;
typedef struct {u16 a,b,c,d;} Cell;
typedef struct {u16 a,b; s16 c; u16 d;} LocalCell;
typedef struct {u32 state;int scene,entity;void *obj;int model,map,player;u32 pad1c;Vec start,end;SmallVec dir;u16 pad3e;int step,count;Vec oldpos,oldlook,delta,lookdelta;Cell cell;int f80;} S;
extern void func_0219E764(int,SmallVec *);
extern void func_0207CDB8(SmallVec *,SmallVec *);
extern void func_021B8028(int,Vec *);
extern int func_021BB480(int);
extern int func_021B7A84(int,Vec *,Vec *,Cell *,Vec *);
extern int func_021B7D50(int,Cell *);
extern int func_021BB3C4(int,Cell *);
extern u32 func_021AB0F8(int);
extern void func_021B7D38(int,Cell *,Vec *);
extern void func_0207CA00(const Vec *,const Vec *,Vec *);
extern int func_0207CBD0(const Vec *);
extern void func_0207CCA4(Vec *,Vec *);
extern int func_0207C768(int,int);
extern int func_0207D14C(int,int *);
extern void func_0218F0A8(int);
extern int func_0218F0E8(int);
extern void func_0218EC54(int);
extern void func_0218E13C(int,u32);
extern void func_0218E124(int,u32);
extern void func_0218ECE4(int,Vec *);
extern void func_0218ECB4(int,Vec *);
extern void func_021BB3D0(int,Cell *);
extern int func_0218EC5C(int);
extern void func_0218EC90(int,Vec *);
extern void func_0218ECF4(int,Vec *);
extern void func_020061E4(u32);
extern void func_0216D568(int,int);
extern void func_021AC528(int,int);
extern void func_021A3044(void *,Vec *);
extern void func_0216D89C(int,Vec *);
extern int func_02006148(u32);
extern void func_020061F8(int);
extern void func_021A36B0(void *,Cell *);
extern void func_021A36D4(void *,Vec *);
extern void func_021BB260(int,int);
extern void func_021BB388(int);
extern void func_0219E2C0(int,Cell *);
extern void func_0216D570(int,int);
extern void func_0216DB4C(int,int);
extern void func_0216DC98(int,int);
extern void func_0216DAE0(int,int);
extern void func_0216DB04(int);
static inline int fxmul(int a,int b) {return (int)(((s64)a*b+2048)>>12);}
void func_021F377C(int unused,S *s)
{
 int n,terrain,height,valid,i,bound,scale,y,z;
 Vec origin,delta,point,pos,look,finalpos;
 SmallVec dir;
 LocalCell cell;
 int length;
 switch(s->state) {
 case 0:
  func_0219E764(s->model,&dir);dir.y=0;func_0207CDB8(&dir,&dir);
  func_021B8028(s->entity,&origin);
  s->start.x=origin.x+fxmul(dir.x,0x10000);
  s->start.y=origin.y+fxmul(dir.y,0x10000);
  s->start.z=origin.z+fxmul(dir.z,0x10000);
  s->end.y=-0xa000;
  scale=fxmul(s->start.y+0xa000,0x127b);
  s->end.x=s->start.x+fxmul(dir.x,scale);s->end.z=s->start.z+fxmul(dir.z,scale);
  terrain=func_021BB480(s->scene);
  if(func_021B7A84(terrain,&s->start,&s->end,&s->cell,&s->end)==0) {s->state=9;return;}
  cell.a=s->cell.a;cell.b=s->cell.b;cell.c=s->cell.c;cell.d=s->cell.d;
  height=func_021B7D50(terrain,&s->cell);
  valid=0;
  if(!(func_021AB0F8(func_021BB3C4(s->scene,(Cell *)&cell))&1)) valid=1;
  cell.c+=2;if(cell.c>height) cell.c=height;
  bound=(u16)(height+cell.c);
  for(i=0;i<bound;i++) {cell.c--;if(func_021AB0F8(func_021BB3C4(s->scene,(Cell *)&cell))&1)break;s->cell.a=cell.a;s->cell.b=cell.b;s->cell.c=cell.c;s->cell.d=cell.d;valid=1;}
  if(!valid) {s->state=9;return;}
  func_021B7D38(terrain,&s->cell,&s->end);
  func_0207CA00(&s->end,&s->start,&delta);length=func_0207CBD0(&delta);func_0207CCA4(&delta,&delta);
  s->dir.x=delta.x;s->dir.y=delta.y;s->dir.z=delta.z;
  length=func_0207C768(length,0x8000);
  if(func_0207D14C(length,&length)==0)s->count=length>>12;else s->count=(length>>12)+1;
  s->step=0;
  if(s->obj!=0) {func_0218F0A8(s->player);s->state=1;}else s->state=4;
  break;
 case 1:
  if(func_0218F0E8(s->player)!=0)break;
  func_0218EC54(s->player);func_0218E13C(s->player,2);
  func_0218ECE4(s->player,&s->oldpos);func_0218ECB4(s->player,&s->oldlook);func_021BB3D0(s->scene,&s->cell);
  if(func_0218EC5C(s->player)!=0) {func_0218EC90(s->player,&s->end);func_0218EC54(s->player);}
  func_0218E13C(s->player,2);func_0218ECE4(s->player,&s->delta);func_0218ECB4(s->player,&s->lookdelta);
  func_0207CA00(&s->delta,&s->oldpos,&s->delta);func_0207CA00(&s->lookdelta,&s->oldlook,&s->lookdelta);
  func_021BB260(s->scene,0);func_0218E124(s->player,2);func_0218EC54(s->player);
  func_0218EC90(s->player,&s->oldlook);func_0218ECF4(s->player,&s->oldpos);
  s->state=4;break;
 case 4:
  func_020061E4(0x6ed);s->state=5;func_0216D568(s->model,0x8000);
 case 5:
  s->step++;
  if((u32)s->step>=(u32)s->count) {point=s->end;s->state=8;}
  else {
   if(s->step>0) n=(int)(0.5f+(float)(s->step<<12));else n=(int)((float)(s->step<<12)-0.5f);
   scale=fxmul(n,0x8000);
   z=s->start.z+fxmul(s->dir.z,scale);y=s->start.y+fxmul(s->dir.y,scale);point.x=s->start.x+fxmul(s->dir.x,scale);point.y=y;point.z=z;
   if(s->step%2==0)func_021AC528(s->model,s->map);
  }
  if(s->obj!=0)func_021A3044(s->obj,&point);else func_0216D89C(s->model,&point);
  if(s->obj==0)break;
  z=s->oldpos.z+func_0207C768(fxmul(s->delta.z,s->step<<12),s->count<<12);
  y=s->oldpos.y+func_0207C768(fxmul(s->delta.y,s->step<<12),s->count<<12);
  pos.x=s->oldpos.x+func_0207C768(fxmul(s->delta.x,s->step<<12),s->count<<12);
  pos.y=y;pos.z=z;
  z=s->oldlook.z+func_0207C768(fxmul(s->lookdelta.z,s->step<<12),s->count<<12);
  y=s->oldlook.y+func_0207C768(fxmul(s->lookdelta.y,s->step<<12),s->count<<12);
  look.x=s->oldlook.x+func_0207C768(fxmul(s->lookdelta.x,s->step<<12),s->count<<12);
  look.y=y;look.z=z;
  func_0218EC90(s->player,&look);func_0218ECF4(s->player,&pos);
  break;
 case 8:
  func_020061F8(func_02006148(0x6ed));
  if(s->obj!=0) {func_021A36B0(s->obj,&s->cell);func_021A36D4(s->obj,&finalpos);func_021A3044(s->obj,&finalpos);func_021BB260(s->scene,1);func_021BB388(s->scene);}
  else func_0219E2C0(s->model,&s->cell);
  func_0216D570(s->model,0x8000);func_0216DB4C(s->model,0);func_0216DC98(s->model,0);func_0216DAE0(s->model,1);func_0216DB04(s->model);s->state=9;
  break;
 case 2:case 3:case 6:case 7:case 9:break;
 }
}

