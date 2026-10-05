/*
 * function: func_021FB3E0
 * address: 0x021FB3E0
 * packet: pkt_ov132_021FB3E0
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * checks: 1 own cursor/mask/context/position/allocator/task definitions reread; 2 B2B0 reread, no closer twin; 3 u32 rate unchanged23, u16 i with explicit byte steps unchanged23; 4 flat u32 coordinate locals25, stacked coordinate record23; 5 unfiltered directory/neighbours refreshed, declared stack object/scope idioms read.
 * wave78: FINAL retry exhausted; 5 one runs, best DIFF328/32823 retained,19/19 relocations resolved. Both scheduling variants consumed. Earlier P300 consumed/rejected for changed cursor reads, not repeated.
 * renewed-pass: six compiles, same-size328 DIFF23 with19/19 resolved; x/y/z/wait/context/index spills remain; two manual scheduling variants exhausted.
 * permuter: earlier once300/types best22 rejected because its mutation swapped z/wait cursor reads; consumed search was not repeated.
 * 2026-10-05 (wave P7 lane V3): DIFF 23 B, 328 B, 19/19 resolved. Only residue: spill slot order of x,y,z,wait,ctx,i (original descending mask,x,y,z,wait,i,ctx; ours mask,wait,ctx,i,x,y,z). Tried: six per-function pragmas (opt_lifetimes, opt_propagation, opt_common_subs, opt_dead_assignments, scheduling, peephole): 23 B except opt_propagation 238 B; declaration order mask,x,y,z,wait / ctx,i first / all in one block: 23 to 25 B, x,y,z stay lowest whatever the order; int instead of Coord: 23 B; one outer block holding x,y,z,wait,ctx,i: 133 B; direct stores instead of vset: 41 B. No twin found in matched overlays. Slot order looks like spill-cost order, not declaration order.
 * recoup 2026-10-05 (R5): still DIFF 23 B. Tried (one compile each): x,y,z as a Vec local; x,y,z,wait in one 4-field struct; wait as u8/u16/int/u32 (u8/u16 add 4 B); x,y,z in an inner block; x,y,z declared last; wait called first; `u8 i; void *ctx;` order (inner order becomes wait,i,ctx like the original, but 23 B, x,y,z still lowest); opt_lifetimes off and opt_common_subs off on that order; extra uses of wait in the loop (slot order unchanged, so not use-cost driven). x,y,z always take the three lowest slots, even as promoted struct fields. Unresolved: what makes the original keep them above wait.
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021FB1F4 0x021FB1F4 thumb ov132
 *   func_021F9DA0 0x021F9DA0 thumb ov132
 *   func_021F9DA4 0x021F9DA4 thumb ov132
 *   func_021F8044 0x021F8044 thumb ov112
 *   func_021F8054 0x021F8054 thumb ov112
 *   func_02030734 0x02030734 arm
 *   func_0207CA00 0x0207CA00 arm
 *   func_021FADA0 0x021FADA0 thumb ov132
 *   func_021FB528 0x021FB528 thumb ov132
 *   d_021FDD00 0x021FDD00 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { COORD_ZERO } Coord;
typedef struct {int x,y,z;} Vec;
extern u32 func_0201134C(void *);
extern int func_021FB1F4(char *,int);
extern void *func_021F9DA0(char *);
extern void *func_021F9DA4(char *,u32);
extern void func_021F8044(void *,u32 *,u32 *);
extern void func_021F8054(void *,u32 *,const u32 *);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_0207CA00(const void *,const void *,void *);
extern void *func_021FADA0(char *,u32,u32,u32);
extern void func_021FB528(int,char *);
extern const char d_021FDD00[];
static inline void vset(Vec *v,Coord x,Coord y,Coord z)
{
    v->x=x;v->y=y;v->z=z;
}
int func_021FB3E0(int unused,char *p)
{
    Coord x,y,z;
    int mask;
    char *owner;
    int rate;
    Coord wait;
    owner=*(char **)p;
    mask=func_021FB1F4(p,func_0201134C(*(void **)(p+4)));
    rate=func_0201134C(*(void **)(p+4));
    x=func_0201134C(*(void **)(p+4));
    y=func_0201134C(*(void **)(p+4));
    z=func_0201134C(*(void **)(p+4));
    wait=func_0201134C(*(void **)(p+4));
    {
    void *ctx;
    u8 i;
    char *q,*target;
    u32 pos[3];
    ctx=func_021F9DA0(*(void **)(owner+52));
    for(i=0;i<4;i++) {
        if(mask&(1<<i)) {
            target=func_021F9DA4(*(void **)(owner+52),i);
            if (rate==0) {
                func_021F8044(ctx,(u32 *)target,pos);
                pos[0]+=x;pos[1]+=y;pos[2]+=z;
                func_021F8054(ctx,(u32 *)target,pos);
            } else {
                q=func_02030734(*(u16 *)owner,56,0,d_021FDD00,0x31B);
                *(char **)(q+48)=owner;
                *(char **)q=target;
                *(void **)(q+4)=*(void **)(owner+52);
                *(u16 *)(q+46)=0;
                func_021F8044(ctx,(u32 *)target,(u32 *)(q+8));
                vset((Vec *)(q+20),*(int *)(q+8)+x,*(int *)(q+12)+y,*(int *)(q+16)+z);
                *(u16 *)(q+44)=rate;
                *(int *)(q+32)=(int)x/(int)rate;
                *(int *)(q+36)=(int)y/(int)rate;
                *(int *)(q+40)=(int)z/(int)rate;
                *(void **)(q+52)=func_021FADA0(owner,(u32)func_021FB528,(u32)q,10);
            }
        }
    }
    }
    if(wait==1) {*(u16 *)(p+20)=rate;return 1;}
    return 0;
}
