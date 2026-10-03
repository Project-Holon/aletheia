/*
 * function: func_021BB61C
 * address: 0x021BB61C
 * packet: pkt_ov110_021BB61C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BAC64 0x021BAC64 thumb ov110
 *   func_021BAC78 0x021BAC78 thumb ov110
 *   func_0204B878 0x0204B878 arm
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct { int a,b,c; } Triple;
extern void func_021BAC64(void *,Triple *,int,int);
extern void *func_021BAC78(void *,Triple *,int,int,int,int);
extern void func_0204B878(void *,u16);
extern void func_0204B3DC(void *,unsigned);
void func_021BB61C(u8 *p) { Triple t; func_021BAC64(*(void **)p,&t,0,0); *(void **)(p+84)=func_021BAC78(*(void **)p,&t,48,64,3,1); func_0204B878(*(void **)(p+84),4); func_0204B3DC(*(void **)(p+84),0); }
