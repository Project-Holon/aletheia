/*
 * function: func_02207868
 * address: 0x02207868
 * packet: pkt_ov195_02207868
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * checks: 1 own matrix/vec/invsqrt bodies and matched callers confirm signatures; original explicitly forwards heap in r1 to 08410; 2 06274/063E0/06604/0685C no complete motion twin; 3 Boolean first/second, Boolean done and _Bool smallH/smallV each DIFF597; after stop s16 first/second DIFF599; writable p retained; 4 case2 cursor cache DIFF600 and case3 shared done-zero DIFF597, scheduling cap used, branch/stack idioms read; 5 refreshed unfiltered idioms and matched neighbours, declared-stack-struct idiom read.
 * recoup 2026-10-05 (P17L3): extent is 2340 B (not 114 B); compiled 2364 (24 B over). First divergence at +0x94 in case 1: original stores one movs r1 to the flag slots [sp+0x84],[sp+0x80] with done in r5 and loop counters i,j in the LOWEST slots [sp+0x20],[sp+0x18] (q at 0x58); ours puts i,j just under the flags (0x78,0x74) and done in r4. Tried (4 compiles): flags declared before the s16 counters (597->596), counters declared last (594), counters as case-block locals (594, same), first=second=1 chain (597, worse). Slot order does not follow declaration order here; not closed. Best form kept (594 differ).
 * recoup 2026-10-05 P30R8 (18 compiles, best 562 differ, was 594): instruction-aligned diff shows the code shape is the original's except 4 things. (1) Spill slots: original keeps the s16 counters in the LOWEST slots (j 0x18, j 0x1c, i 0x20, i 0x24, i 0x28, below all compiler temps); ours puts named locals above temps, so ~540 of the differing bytes are slot numbers. Declaring `s16 i,i,i,j,j,j` reproduces the original relative order of the counters (not their absolute position). Block-local `char *q` per loop (594->567) and separate `first3,second3,done3` for case 3 (567->562; flags3 now at 0x78/0x74 like the original) are kept. (2) Original shares one `movs r,#1` for the two flag stores (str [0x84]; str [0x80]); ours emits two movs. Tried first=second=1, second=first=1, first=1;second=first, `int first=1,second=1`, u8 flags: all keep two movs. (3) smallV=0 in the original is `movs r2,#0; str r2,[sp,#0x7c]` before the pool load, a zero separate from smallH; ours shares r0. Tried smallH=smallV=0 and u8 smallV: no change. (4) add order at +04F8 (adds r4,r3,r4 / lsls r3,r2,#7 swapped). Per-function pragmas on the final form (opt_lifetimes, opt_propagation, opt_common_subs, opt_dead_assignments off: 1451 to 2225 differ; scheduling, peephole off: no change). Counters first-declared put them at the top (570); counters and flags as case-block locals 571.
 * final push 2026-10-05 G10L2 (30 compiles, 562 -> 23 bytes off): (1) ONE shared s16 i,j for all four loops (drops the counters to the original low slots, clears the case 2 q/j register swap); (2) case 3 locals (vx..inv, dx..inv) declared in their branch blocks; (3) `done=1;first=1;second=1;` with done FIRST makes first/second share one movs (literal CSE), also for case 3; (4) `smallH=0;smallV=0;` order gives the separate smallV zero; (5) case 2 first clear as `c=p+i*0x900;c+=j*0x80;c[0x88]=0` matches the original schedule. Remaining 23 B: case 3 second clear (j shift scheduled before the add; original sequential), dy1 spill slot 0x68 vs 0x60 with the case 3 vert slots shifted by one, and the five hoisted 2048 constants of case 3 branch 1 stored in order m4,m5,m1,m2,m3 (original m1..m5; slots equal). Tried without effect: plain/pointer/struct-view/(j<<7)/inline cell forms for the clear, dy declared last/block-local/as vy/unsigned, case 1 locals block-scoped, q at function scope (worse), split horiz sum (worse).
 * residual: 2364 compiled/full extent; 597 concrete differences, 35/35 relocations resolved. Final retry exhausted: 7 one runs. Prior macro-free baseline-agreeing 300-candidate permuter not repeated; volatile winner rejected previously. Cached case2 cursor loads before guards and shared case3 done=0 improve prior705 to597.
 * extent: handed2340 ends at 0220818C before pop02208190; pools through022081A0; next genuine022081A4. Full extent2364 proved by explicit show.
 * symbols:
 *   func_0207B640 0x0207B640 thumb
 *   func_0207BC08 0x0207BC08 arm
 *   func_0207C7E8 0x0207C7E8 arm
 *   func_02208410 0x02208410 thumb ov195
 *   _ll_mul 0x0209C054 arm
 *   FX_SinCosTable_ 0x020A1B38 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef long fx32;
typedef struct {fx32 x,y,z;} Vec;
typedef struct {fx32 a[12];} Matrix;
extern void func_0207B640(Matrix *,fx32,fx32);
extern void func_0207BC08(const Vec *,const Matrix *,Vec *);
extern fx32 func_0207C7E8(fx32);
extern int func_02208410(char *,u16);
extern const s16 FX_SinCosTable_[];
#define G(n) (*(u32 *)(p+(n)))
#define Q(n) (*(int *)(q+(n)))
#define H(n) (*(s16 *)(p+(n)))
#define V(n) (*(Vec *)(q+(n)))
static inline int mul(int a,int b){return (int)(((long long)a*b+2048)>>12);}
static inline int sub(int a,int b){return (int)((u32)a-(u32)b);}
static inline int add(int a,int b){return (int)((u32)a+(u32)b);}
void func_02207868(char *p,u16 heap)
{
    int first,second,done;
    int angle,dx,dy,dz,horiz,vert,inv,vx,vy,vz,smallH,smallV;
    Vec goal;
    Matrix m1;
    Vec source1;
    Matrix m2;
    Vec source2;
    Matrix m3;
    Vec source3;
    Matrix m4;
    Vec source4;
    int first3,second3,done3;
    s16 i,j;
    G(0x68)+=G(0x6c);
    if((int)G(0x68)>=65536)G(0x68)-=65536;
    for(i=0;i<18;i++)for(j=0;j<18;j++){
        char *q=p+0x74+i*0x900+j*0x80;
        V(0x74)=V(0x68);
    }
    switch(G(0x64)){
    case 0:
        G(0x64)=1;G(0x70)=0;G(0x6c)=0x600;return;
    case 1:
        done=1;first=1;second=1;
        for(i=0;i<18;i++)for(j=0;j<18;j++){
            char *q=p+0x74+i*0x900+j*0x80;
            angle=add(Q(0x4c),G(0x68));if(angle>=65536)angle-=65536;
            func_0207B640(&m1,FX_SinCosTable_[(angle>>4)*2],FX_SinCosTable_[(angle>>4)*2+1]);
            source1.x=Q(0x50);source1.y=0;source1.z=0;
            func_0207BC08(&source1,&m1,&goal);goal.y=Q(0x54);
            if(Q(0x64)==0){
                if(first||second){Q(0x30)=0;Q(0x64)=1;if(first)first=0;else second=0;}
                done=0;
            }else if(Q(0x64)==1){
                if(Q(0x30)==0){
                    Q(0x68)=add(Q(0x68),Q(0x40));Q(0x6c)=add(Q(0x6c),Q(0x44));Q(0x70)=add(Q(0x70),Q(0x48));
                    Q(0x30)++;*(u8 *)(p+0xa274)=(u8)(i+1);
                }else{
                    dy=sub(Q(0x5c),Q(0x6c));dz=sub(Q(0x60),Q(0x70));dx=sub(Q(0x58),Q(0x68));
                    horiz=mul(dx,dx)+mul(dz,dz);vert=mul(dy,dy);
                    if(horiz<0x11ac&&vert<0x11ac){
                        Q(0x68)=Q(0x58);Q(0x70)=Q(0x60);Q(0x6c)=Q(0x5c);
                        Q(0x68)=goal.x;Q(0x70)=goal.z;Q(0x6c)=goal.y;Q(0x30)=0;Q(0x64)=2;
                    }else{
                        smallH=0;smallV=0;if(horiz<0x11ac)smallH=1;else if(vert<0x11ac)smallV=1;
                        if(smallH){Q(0x68)=Q(0x58);Q(0x70)=Q(0x60);}
                        else{
                            inv=func_0207C7E8(horiz);
                            Q(0x68)=add(add(Q(0x68),mul(sub(Q(0x68),Q(0x74)),409)),mul(mul(dx,inv),3584));
                            Q(0x70)=add(add(Q(0x70),mul(sub(Q(0x70),Q(0x7c)),409)),mul(mul(dz,inv),3584));
                        }
                        if(smallV)Q(0x6c)=Q(0x5c);
                        else{vy=dy>=0?4096:-4096;Q(0x6c)=add(add(Q(0x6c),mul(sub(Q(0x6c),Q(0x78)),409)),mul(vy,3584));}
                        Q(0x30)++;
                    }
                }
                done=0;
            }else if(Q(0x64)==2){Q(0x68)=goal.x;Q(0x70)=goal.z;Q(0x6c)=goal.y;}
        }
        if(done){G(0x64)=2;if(G(0x28)!=1&&G(0x28)!=2)G(0x28)=1;}return;
    case 2:
        if(G(0x70)<100)G(0x6c)+=32;
        if(G(0x70)>=200&&G(0x70)<240)G(0x6c)-=32;
        for(i=0;i<18;i++)for(j=0;j<18;j++){
            char *q=p+0x74+i*0x900+j*0x80;
            angle=add(Q(0x4c),G(0x68));if(angle>=65536)angle-=65536;
            func_0207B640(&m2,FX_SinCosTable_[(angle>>4)*2],FX_SinCosTable_[(angle>>4)*2+1]);
            source2.x=Q(0x50);source2.y=0;source2.z=0;
            func_0207BC08(&source2,&m2,&V(0x68));Q(0x6c)=Q(0x54);
        }
        if(func_02208410(p,heap)&&G(0x70)>=30){
            j=H(0x5a);i=H(0x5c);
            if(i>=0&&j>=0){
                {char *c=p+i*0x900;c+=j*0x80;*(u8 *)(c+0x88)=0;}
                if(j-1<0){H(0x5a)=18;H(0x5c)--;}else H(0x5a)--;
            }
            j=H(0x5e);i=H(0x60);
            if(i<18&&j<18){
                *(u8 *)(p+i*0x900+j*0x80+0x88)=0;
                if(j+1>=18){H(0x5e)=0;H(0x60)++;}else H(0x5e)++;
            }
        }
        if(H(0x5c)<0&&H(0x60)>=18&&G(0x70)>=240){G(0x64)=3;G(0x70)=0;return;}
        G(0x70)++;return;
    case 3:
        done3=1;first3=1;second3=1;
        for(i=17;i>=0;i--)for(j=17;j>=0;j--){
            char *q=p+0x74+i*0x900+j*0x80;
            angle=add(Q(0x4c),G(0x68));if(angle>=65536)angle-=65536;
            if(Q(0x64)==2){
                if(first3||second3){Q(0x30)=0;Q(0x64)=3;if(first3)first3=0;else second3=0;}
                else{
                    func_0207B640(&m3,FX_SinCosTable_[(angle>>4)*2],FX_SinCosTable_[(angle>>4)*2+1]);
                    source3.x=Q(0x50);source3.y=0;source3.z=0;
                    func_0207BC08(&source3,&m3,&V(0x68));Q(0x6c)=Q(0x54);
                }
                done3=0;
            }else if(Q(0x64)==3){
                if(Q(0x30)==0){
                    int vx,vy,vz,horiz,vert,inv;
                    func_0207B640(&m4,FX_SinCosTable_[(angle>>4)*2],FX_SinCosTable_[(angle>>4)*2+1]);
                    source4.x=Q(0x50);source4.y=0;source4.z=0;
                    func_0207BC08(&source4,&m4,&V(0x68));Q(0x6c)=Q(0x54);
                    vx=sub(Q(0x68),Q(0x74));vy=sub(Q(0x6c),Q(0x78));vz=sub(Q(0x70),Q(0x7c));
                    horiz=mul(vx,vx)+mul(vz,vz);vert=mul(vy,vy);
                    if(horiz>4096){inv=func_0207C7E8(horiz);vx=mul(vx,inv);vz=mul(vz,inv);}
                    if(vert>4096)vy=vy>=0?4096:-4096;
                    Q(0x68)=add(Q(0x68),vx);Q(0x6c)=add(Q(0x6c),vy);Q(0x70)=add(Q(0x70),vz);Q(0x30)++;
                }else{
                    int dx,dy,dz,horiz,vert,inv;
                    dx=sub(Q(0x34),Q(0x68));dy=sub(Q(0x38),Q(0x6c));dz=sub(Q(0x3c),Q(0x70));
                    horiz=mul(dx,dx)+mul(dz,dz);vert=mul(dy,dy);
                    if(horiz<0x11ac&&vert<0x11ac){Q(0x68)=Q(0x34);Q(0x70)=Q(0x3c);Q(0x6c)=Q(0x38);Q(0x30)=0;Q(0x64)=4;}
                    else{
                        if(horiz>4096){inv=func_0207C7E8(horiz);dx=mul(dx,inv);dz=mul(dz,inv);}
                        if(vert>4096)dy=dy>=0?4096:-4096;
                        Q(0x68)=add(Q(0x68),dx);Q(0x6c)=add(Q(0x6c),dy);Q(0x70)=add(Q(0x70),dz);
                    }
                }
                done3=0;
            }
        }
        if(done3){G(0x64)=4;G(0x28)=4;}return;
    case 4: return;
    }
}
