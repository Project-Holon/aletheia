/*
 * function: func_021B82DC
 * address: 0x021B82DC
 * packet: pkt_ov103_021B82DC
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: Verified against the ov103 Thumb image.
 * symbols:
 *   func_021B824C 0x021B824C thumb ov103
 *   func_021B8138 0x021B8138 thumb ov103
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern void func_021B824C(u8 *,void *,int,u8 *,s16,s16,int); extern void func_021B8138(u8 *,void *,int,int,s16);
void func_021B82DC(u8 *a,u8 *b,int c) { int *p=*(int **)(b+0xb0c); if(p[0])func_021B824C(a,b+0x174,c,(u8 *)p[2],0,0,0x37); else func_021B8138(a,b+0x174,c,0,0); }
