/*
 * function: func_021B77DC
 * address: 0x021B77DC
 * packet: pkt_ov180_021B77DC
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Add the far offset before the index; see the far-offset-before-the-index idiom.
 * symbols:
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BMP_OAM_UploadChars 0x020257D0 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Obj;
extern void PRINTSYS_PrintColor(void *,s16,s16,void *,void *,u16);
extern void BMP_OAM_UploadChars(struct Obj *);
void func_021B77DC(u8 *p,int n,void *w,void *s,int x,int y) { PRINTSYS_PrintColor(*(void **)((u32)p+0x9124+(u32)n*8),x,y,s,w,0x3c40); BMP_OAM_UploadChars(*(struct Obj **)((u32)p+0x9120+(u32)n*8)); }
