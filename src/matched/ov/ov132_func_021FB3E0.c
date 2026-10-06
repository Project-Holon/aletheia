/*
 * function: func_021FB3E0
 * address: 0x021FB3E0
 * packet: pkt_ov132_021FB3E0
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * pass 2 2026-10-06 P2L34: EXACT in --lang c99 and --lang c. The last 23 bytes were spill slots:
 *   with loop invariant motion on, x,y,z (each used two or three times inside the loop) got new
 *   loop webs and fell below the other spills.  for this function
 *   keeps them as declared locals, and the slots then follow declaration order
 *   (mask, x, y, z, wait / i, ctx).
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
struct Cursor;
extern u32 func_0201134C(struct Cursor *p);
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
#pragma opt_loop_invariants off
int func_021FB3E0(int unused,char *p)
{
    int mask;
    Coord x,y,z;
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
    u8 i;
    void *ctx;
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
#pragma opt_loop_invariants reset
