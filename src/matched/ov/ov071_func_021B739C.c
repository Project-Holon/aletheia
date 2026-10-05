/*
 * function: func_021B739C
 * address: 0x021B739C
 * packet: pkt_ov071_021B739C
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note final push 2026-10-05 G7L1: EXACT once the witness leaf 021B7A08 was matched; was MATCH, not
 *   EXACT, only because func_021B7A08 and three data symbols have no witness outside the extent.
 *   Two changes from 32 B off:
 *   1 case 4 calls func_020355D8x, a second extern name for 0x020355D8 (listed in symbols). With
 *     one name, mwcc tail-merged case 4's `movs r0,#0; blx 20355d8; ...` into case 3's copy and
 *     the res compare reloaded from the case 3 stack slot (spill); the original keeps its own
 *     blx and branches to the shared `ldr 0x551` tail. Case 4 also uses block-local keys4/res4
 *     (res in r0, no spill). 32 -> 10 B.
 *   2 case 5: f78 byte store before `dst = d->text;` and a braced copy body `{*dst=*src;dst++;src++;}`
 *     (10 -> 0 B). Earlier notes tried f78-before-dst alone (38 B) under the old case 4.
 *   The alias is the integrator's call: if a single-name form exists it must keep the separate blx.
 * note 2026-10-05 (wave P18 lane 1): 1160 of 1160 bytes, 32 bytes differ (from 1156/706).
 *   Real extent is 1160 B (jump-table state machine), not the 104 B label gap.
 *   Forms that closed most of the gap, in order:
 *   1 navigation: the loop counter and the selected index are ONE variable (`i = *c->f8;`
 *     after the search loop); gives the original register order in all four d-pad arms.
 *   2 `#pragma opt_lifetimes off` and `#pragma opt_common_subs off` (both needed: each alone
 *     leaves 381 / 549 bytes off). Gives the unmerged c->f8 reload before the store.
 *   3 cases 7 and 8: `*state = 11;` written in each arm (7: after d->f81 = 1; 8: else arm).
 *     This restores the lone `b` stub of the state-8 path and fixes the state/d colours
 *     (r5 state, r6 d) with no other change. 440 -> 32 bytes off.
 *   4 case 5: `dst = d->text;` before the d->f78 store gives the early `adds r2,r6,#0` copy.
 *   Plain d_021BA862[sel][k], struct rows, u32 base casts: no effect or worse (pool refs
 *   fold k into the addend); `row = d_021BA862[sel]; next = row[k]` per arm is the form kept.
 *   Residue (32 B): case 5 text copy loop colours only: original dst r2, tmp r0, f0 pointer r0,
 *   f78 byte r1, f78 address r0; build has dst r0, tmp r2, f0 pointer r1, byte r2, address r1.
 *   Tried: dst after/before f78, before the struct copy (1188 B), src first (40 B), src before f78
 *   (37 B), swapped declaration order of dst/src, indexed copy d->text[i] = src[i] (107 B, no
 *   strength reduction), no pragmas (644 B).
 *   Callees: matched definitions checked, return types and arity agree with the listing.
 *   func_021B7A08 (no witness) is the 12 B Thumb tail thunk at 0x021B7A08 inside the extent of
 *   func_021B79A0 (ldr r1,[r1,#8]; ldr r3,[pc,#4]; adds r0,#0x38; bx r3, target 0x02028485);
 *   not filed. Its call is a wildcard in the diff.
 * note recoup 2026-10-05 P30R1: still 32 B (case 5 text copy colours). 23 compiles, no change:
 *   callees re-checked (no void/arity issue); per-function pragmas opt_propagation off (401 B),
 *   opt_dead_assignments off (44), scheduling off (32), peephole off (32); byte read into a u8 local
 *   first (32); for-init src (32); do-while (32); while(i--) (389); indexed loop (862 / 388);
 *   u16 temp local in loop (32); const src (32); separate counter t (389); f78 store via raw
 *   *(u8 *)(d+0x78) (32); src before f78 (37); f78 before dst (38); declaration order of
 *   dst/src/r/i in four positions (32 each, no effect). The colour order dst r0 / f0 r1 / byte r2
 *   is stable under all source forms tried.
 * symbols:
 *   func_02012138 0x02012138 thumb
 *   func_02158344 0x02158344 thumb ov010
 *   func_020120F4 0x020120F4 thumb
 *   func_02158590 0x02158590 thumb ov010
 *   func_021B7AC4 0x021B7AC4 thumb ov071
 *   func_021B7AE8 0x021B7AE8 thumb ov071
 *   func_021B7BB4 0x021B7BB4 thumb ov071
 *   func_021B7BF0 0x021B7BF0 thumb ov071
 *   func_021B7BFC 0x021B7BFC thumb ov071
 *   func_021B79A0 0x021B79A0 thumb ov071
 *   func_021B7A08 0x021B7A08 thumb ov071
 *   func_021B7A14 0x021B7A14 thumb ov071
 *   func_02035C60 0x02035C60 arm
 *   func_020362DC 0x020362DC arm
 *   func_02035C08 0x02035C08 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020355D8x 0x020355D8 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_02175B14 0x02175B14 thumb ov011
 *   func_02175B4C 0x02175B4C thumb ov011
 *   func_021761EC 0x021761EC thumb ov011
 *   func_02173E2C 0x02173E2C thumb ov011
 *   func_021B6B98 0x021B6B98 thumb ov071
 *   func_021B6BEC 0x021B6BEC thumb ov071
 *   func_021B6C74 0x021B6C74 thumb ov071
 *   func_021B7108 0x021B7108 thumb ov071
 *   func_021B7114 0x021B7114 thumb ov071
 *   d_021BA87C 0x021BA87C data a4
 *   d_021BA85C 0x021BA85C data a1
 *   d_021BA862 0x021BA862 data a1
 *   d_021BAA4C 0x021BAA4C data a4
  */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 a[6];} Record;
typedef struct {void **f0;u8 *f4;u8 *f8;u8 padc[0x20];u8 f2c,f2d,f2e;} C;
typedef struct {u8 pad0[0x4c];Record rec;u16 text[10];u8 f78;u8 pad79[7];u8 f80,f81,f82,f83;} D;
extern u32 func_02012138(void *);
extern u8 *func_02158344(u32);
extern void *func_020120F4(void *);
extern int func_02158590(void *);
extern void func_021B7AC4(void *,void *);
extern void func_021B7AE8(void *,int);
extern void func_021B7BB4(void *,void *);
extern void func_021B7BF0(void *);
extern void func_021B7BFC(C *,D *,u8);
extern void func_021B79A0(void *,void *,int);
extern int func_021B7A08(void *,void *);
extern void func_021B7A14(void *);
extern int func_02035C60(void);
extern u32 func_020362DC(void);
extern int func_02035C08(const void *);
extern void func_020355D8(int);
extern void func_020355D8x(int);
extern void func_020061E4(u32);
extern int func_02175B14(u8 *);
extern void func_02175B4C(u8 *,u8 *);
extern u8 func_021761EC(u8 *);
extern int func_02173E2C(u8 *,Record *);
extern void func_021B6B98(void *,void *,int,int,int);
extern void func_021B6BEC(void *,void *,int,int,int);
extern u8 func_021B6C74(void *,int);
extern void func_021B7108(void *);
extern int func_021B7114(void *);
extern const u32 d_021BA87C[];
extern const u8 d_021BA85C[],d_021BA862[][4];
extern const u32 d_021BAA4C[];
#pragma opt_lifetimes off
#pragma opt_common_subs off
int func_021B739C(int a,int *state,C *c,D *d)
{
 u16 *dst;
 u16 *src;
 u8 *r;
 int keys,res,t;
 u32 i;
 u8 next;
 const u8 *row;
 r=func_02158344(func_02012138(*c->f0));
 func_021B7AC4(d,c); func_021B7AE8(d,*c->f8);func_021B7BB4(c,d);func_021B7BF0(d);
 if(c->f2e==1 && *state==3) return 1;
 switch(*state) {
 case 0:
  if(r!=0 && func_02175B14(r+0x1ac)==1) func_021B7BFC(c,d,1);
  *state=1;break;
 case 1:
  if(func_02158590(func_020120F4(*c->f0))==0) func_021B79A0(d,c->f4,0x16);
  else func_021B79A0(d,c->f4,0x12);
  ++*state;break;
 case 2:
  if(func_021B7A08(c->f4,d)!=1) break;
  if(func_02035C60()==0 && (func_020362DC()&3)==0) break;
  func_021B7A14(d);func_020061E4(0x547);
  if(func_02035C60()!=0) {d->f83=1;func_021B6B98(c,(u8 *)d+0x2c,1,0xff,3);}
  else {d->f83=0;func_021B6B98(c,(u8 *)d+0x2c,1,0,3);}
  if(d->f82==0) *state=3;else *state=4;
  break;
 case 3:
  keys=func_020362DC();res=func_02035C08(d_021BA87C);
  if(r!=0 && func_02175B14(r+0x1ac)==1) {func_021B7BFC(c,d,1);d->f80=1;*state=4;break;}
  if(keys>0 && d->f83==1) {d->f83=0;func_021B6B98(c,(u8 *)d+0x2c,1,0,3);func_020061E4(0x548);break;}
  if(keys&0xf0) {
   next=0xff;
   for(i=0;(i<6)?1:0;i++) if(d_021BA85C[i]==*c->f8) break;
   i=*c->f8;
   if(keys&0x40) {row=d_021BA862[i];next=row[0];}
   else if(keys&0x80) {row=d_021BA862[i];next=row[1];}
   else if(keys&0x20) {row=d_021BA862[i];next=row[2];}
   else if(keys&0x10) {row=d_021BA862[i];next=row[3];}
   if(next!=0xff) i=next;
   *c->f8=i;func_020061E4(0x548);
  }
  if(res>=0 && res<6) {*c->f8=res;d->f83=1;func_021B6B98(c,(u8 *)d+0x2c,1,0xff,3);func_020061E4(0x548);break;}
  if(res==6 || (keys&1)) {
   func_020355D8(res==6);
   if(func_02158590(func_020120F4(*c->f0))==0) {
    t=d_021BAA4C[*c->f8];
    if(t!=2 && t!=1) {*state=9;break;}
   }
   func_021B6BEC(c,(u8 *)d+0x2c,1,0,3);func_020061E4(0x736);*state=5;
  } else if(res==7 || (keys&2)) {
   func_021B7108((u8 *)d+0x24);func_020355D8(res==7);func_020061E4(0x551);*state=11;
  }
  break;
 case 4: {
  int keys4,res4;
  keys4=func_020362DC();res4=func_02035C08(d_021BA87C);
  if(res4==7 || (keys4&2)) {func_020355D8x(res4==7);func_020061E4(0x551);*state=11;}
  break;}

 case 5:
  d->rec=*(Record *)(c->f4+0x60+d_021BAA4C[*c->f8]*24);
  d->f78=((u8 *)c->f0)[0x15];
  dst=d->text;
  src=(u16 *)((u8 *)c->f0+0x18);
  for(i=10;i!=0;i--) {*dst=*src;dst++;src++;}
  if(r!=0 && func_02173E2C(r,&d->rec)!=1) break;
  *state=6;break;
 case 6:
  if(r==0) {*state=3;break;}
  t=func_021761EC(r+0x1ac);
  if(t==1) {func_021B79A0(d,c->f4,0x10);*state=7;}
  else if(t==2) {func_021B79A0(d,c->f4,0x11);*state=8;}
  else if(t==3) {func_021B79A0(d,c->f4,0x15);*state=8;}
  else if(t==4) {func_021B79A0(d,c->f4,0x14);*state=8;}
  break;
 case 7:case 8:
  if(func_021B7A08(c->f4,d)!=1) break;
  if(*state==7) {
  } else if(*state==8) {
   if(func_02035C60()==0 && !(func_020362DC()&3)) break;
  } else break;
  if(*state==7 && r!=0 && func_02175B14(r+0x1ac)==0) break;
  func_021B7A14(d);func_020061E4(0x547);
  if(*state==7) {if(r!=0) func_02175B4C(r,r+0x1ac);d->f81=1;*state=11;}
  else *state=11;
  break;
 case 9:func_021B79A0(d,c->f4,0x17);++*state;break;
 case 10:
  if(func_021B7A08(c->f4,d)==1 && (func_02035C60()!=0 || (func_020362DC()&3)!=0)) {func_021B7A14(d);*state=3;}
  break;
 case 11:
  if(func_021B6C74(c,3)==2) break;
  if(func_021B7114((u8 *)d+0x24)!=0) break;
  if(d->f81==1) c->f2c=4;else c->f2c=0;
  return 1;
 }
 return 0;
}
#pragma opt_lifetimes reset
#pragma opt_common_subs reset
