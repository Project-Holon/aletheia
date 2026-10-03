/*
 * function: func_021BAA84
 * address: 0x021BAA84
 * packet: pkt_ov223_021BAA84
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the pooled addresses are the two bytes of one pair; indexed members preserve separate base/base+1 pool words.
 * symbols:
 *   d_021BC716 0x021BC716 data a2
 *   func_0204B404 0x0204B404 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;typedef struct Vec2 {s16 x,y;} Vec2;typedef struct BytePair {u8 x,y;} BytePair;struct Obj;extern const BytePair d_021BC716[];extern void func_0204B404(struct Obj *,const Vec2 *,u32);
void func_021BAA84(char *p,int unused) {Vec2 pos;u32 idx,off;off=0x228;idx=*(u32 *)(p+off);off-=4;pos.x=d_021BC716[idx].x;pos.y=d_021BC716[idx].y;func_0204B404(*(struct Obj **)(p+off),&pos,0);}
