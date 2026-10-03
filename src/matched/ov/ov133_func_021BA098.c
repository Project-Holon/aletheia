/*
 * function: func_021BA098
 * address: 0x021BA098
 * packet: pkt_ov133_021BA098
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Actor;
typedef struct {short x,y;} Pos;
extern void func_0204B9A0(struct Actor*);
extern void func_0204B3DC(void*,u32);
extern void func_0204B404(void*,const Pos*,unsigned);
void func_021BA098(u8*p){Pos pos;pos.x=*(int*)(p+28);pos.y=*(int*)(p+32);func_0204B9A0(*(struct Actor**)(p+0x18b4));func_0204B3DC(*(void**)(p+0x18b4),1);func_0204B404(*(void**)(p+0x18b4),&pos,0);}
