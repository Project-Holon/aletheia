/*
 * function: func_021B7984
 * address: 0x021B7984
 * packet: pkt_ov106_021B7984
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: Unsigned conversion and ROUND use runtime-proven add C95C/sub CB8C. 8FA8 stores word +28 then tail-calls 3630C; 8E90 reads five inputs, writes Pair/Vec/word outputs.
 * symbols:
 *   func_021B727C 0x021B727C thumb ov101
 *   func_021B8FA8 0x021B8FA8 thumb ov106
 *   func_021B900C 0x021B900C thumb ov106
 *   func_021B8E50 0x021B8E50 thumb ov106
 *   func_021B8408 0x021B8408 thumb ov106
 *   func_021B9134 0x021B9134 thumb ov106
 *   func_021B8E90 0x021B8E90 thumb ov106
 *   func_0207CA68 0x0207CA68 arm
 *   d_021B949C 0x021B949C data a4
 *   func_021B9198 0x021B9198 thumb ov106
 *   func_021B913C 0x021B913C thumb ov106
 *   func_021B7250 0x021B7250 thumb ov101
 *   func_021B78D0 0x021B78D0 thumb ov106
 *   func_021B7948 0x021B7948 thumb ov106
 *   func_021B838C 0x021B838C thumb ov106
 *   func_021B8DA8 0x021B8DA8 thumb ov106
 *   func_021B8FD0 0x021B8FD0 thumb ov106
 *   func_021B71E4 0x021B71E4 thumb ov101
 *   _ffltu 0x0209BE04 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   _ll_mul 0x0209C054 arm
 *   func_0207C768 0x0207C768 arm
 */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { int x,y; } Pair;
typedef struct { int x,y,z; } Vec;
extern const Vec d_021B949C;
extern int func_021B727C(int),func_021B7250(int *);
extern u32 func_021B8FA8(u8 *,u32 *);
extern int func_021B8E50(u8 *,Pair *,Pair *,Pair *),func_021B8E90(u8 *,Pair *,Pair *,Vec *,int *);
extern int func_0207CA68(const Vec *,const Vec *),func_0207C768(int,int);
extern void func_021B900C(u8 *,int,int),func_021B8408(u8 *,s16),func_021B9134(u8 *);
extern int func_021B9198(u8 *);
extern s16 func_021B913C(u8 *);
extern void func_021B78D0(u8 *,u32),func_021B7948(u8 *,u32,u8 *),func_021B838C(u8 *),func_021B8DA8(int *),func_021B8FD0(u8 *),func_021B71E4(u32);
#define ROUND(a) ((int)((a)!=0 ? (float)((a)<<12)+0.5f : (float)((a)<<12)-0.5f))
#define SCALE(a) ((int)(((long long)func_0207C768(ROUND(a)-81920,163840)*245760+2048)>>12))
void func_021B7984(u8 *a,u32 unused,u8 *p) {
    u32 value;
    Pair pair;
    Vec vec;
    int duration;
    if(!func_021B727C(*(int *)(p+0x614))) {
        if(func_021B8FA8(p+0x5d4,&value)&128) {
            if(ROUND(value)>81920)func_021B900C(p+0x600,SCALE(value),12);
            else func_021B900C(p+0x600,8192,12);
        } else if(func_021B8FA8(p+0x5d4,&value)&64) {
            if(ROUND(value)>81920)func_021B900C(p+0x600,-SCALE(value),12);
            else func_021B900C(p+0x600,-8192,12);
        } else if(func_021B8E50(p+0x5d4,0,0,&pair)) {
            func_021B8408(p+0x38,-pair.y);
            func_021B9134(p+0x600);
        } else if(func_021B8E90(p+0x5d4,0,0,&vec,&duration))
            func_021B900C(p+0x600,func_0207CA68(&d_021B949C,&vec),duration);
    }
    if(func_021B9198(p+0x600))func_021B8408(p+0x38,func_021B913C(p+0x600));
    if(func_021B7250(*(int **)(p+0x614))==1)func_021B78D0(a,(u32)func_021B7948);
    func_021B838C(p+0x38);
    func_021B8DA8((int *)(p+0x5d4));
    func_021B8FD0(p+0x600);
    func_021B71E4(*(u32 *)(p+0x614));
}
