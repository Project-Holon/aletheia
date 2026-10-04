/*
 * function: func_021FF334
 * address: 0x021FF334
 * packet: pkt_ov186_021FF334
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: 0x0204B5E4 ARM9 ARM, sole unresolved relocation in own MATCH 212; unit_0204B5D4.c defines sub_0204B5E4 but omits it from function: header. Owner unit and shard require Ilias maintenance.
 * Verified blocker C: one --arm without region, fixed compiler/flags/lang, EXACT 16 (scratch b5e4.c and b5e4-verify.log).
 * typedef unsigned long u32;
 * typedef struct { char pad[0x14]; u32 a; u32 b; } Actor;
 * u32 func_0204B5E4(const Actor *p,u32 which)
 * { if(which==0)return p->a; else return p->b; }
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B4EC 0x0204B4EC arm
 *   func_0204B5E4 0x0204B5E4 arm
 *   func_0204B49C 0x0204B49C arm
 *   func_0204B5D4 0x0204B5D4 arm
 *   func_021FF038 0x021FF038 thumb ov186
 * Width: space argument truncated by original caller to u16 despite callee u32.
 */
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned long u32;
struct Actor;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern s16 func_0204B4EC(void *,u16,u32);
extern u32 func_0204B5E4(const struct Actor *actor, u32 which);
extern void func_0204B49C(void *,s16,u16,u32);
extern void func_0204B5D4(struct Actor *actor, u32 value, u32 which);
extern void func_021FF038(char *,u32);
void func_021FF334(char *p)
{
    s16 x;
    u32 y;
    *(int *)(p+0x28)=(*(int *)(p+0x28)+1)%2;
    if(*(int *)(p+0x28)!=0)return;
    switch(*(int *)(p+0x1C)){
    case 0:
        func_0204B3DC(*(void **)(p+4),1);
        *(int *)(p+0x24)=0;
        *(int *)(p+0x1C)=1;
        break;
    case 1:
        x=func_0204B4EC(*(void **)(p+4),*(u32 *)(p+0x44),0);
        y=func_0204B5E4(*(void **)(p+4),0);
        if(*(int *)(p+0x24)==0){
            *(int *)(p+0x2C)=*(s16 *)(p+0x34)-x;
            *(int *)(p+0x2C)/=*(s16 *)(p+0x3A);
            (*(int *)(p+0x24))++;
            *(int *)(p+0x30)=*(s16 *)(p+0x38)-y;
            *(int *)(p+0x30)/=*(s16 *)(p+0x3A);
        }else if(*(int *)(p+0x24)==*(s16 *)(p+0x3A)+1){
            x=*(s16 *)(p+0x34);
            y=*(s16 *)(p+0x38);
            *(int *)(p+0x1C)=2;
        }else{
            x+=(s16)*(int *)(p+0x2C);
            y+=*(int *)(p+0x30);
            (*(int *)(p+0x24))++;
        }
        func_0204B49C(*(void **)(p+4),x,*(u32 *)(p+0x44),0);
        func_0204B5D4(*(void **)(p+4),y,0);
        break;
    case 2:func_021FF038(p,0);break;
    }
}
