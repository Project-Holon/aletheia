/*
 * function: func_021B9B80
 * address: 0x021B9B80
 * packet: pkt_ov223_021B9B80
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: reuse the selector for the loaded target; final clamp stays in the outer if.
 * symbols:
 *   table 0x021BC78C data
 *   func_02011590 0x02011590 thumb
 *   func_02011B8C 0x02011B8C thumb
 *   func_021BC52C 0x021BC52C thumb
 *   func_021B95A0 0x021B95A0 thumb
 */
typedef unsigned short u16;
extern const struct Row {u16 h[5];} table[];
typedef signed int     s32;
typedef unsigned int   u32;
struct IcaAnime;
extern u32 func_02011590(struct IcaAnime *p, s32 v);
extern void func_02011B8C(void *,void *);
extern void *func_021BC52C(void *);
extern int func_021B95A0(void *,int);
void func_021B9B80(char *p)
{
    unsigned i=0;
    if(*(unsigned *)(p+72)==0) i=1;
    i=table[*(unsigned *)(p+68)].h[i];
    if(*(unsigned *)(p+76)!=i) {
        int step;
        if(*(unsigned *)(p+72)!=0) step=-2048; else step=2048;
        func_02011590(*(void **)(p+64),step);
        func_02011B8C(func_021BC52C(*(void **)(p+20)),*(void **)(p+64));
        if(*(unsigned *)(p+72)!=0) --*(unsigned *)(p+76); else ++*(unsigned *)(p+76);
    if(*(unsigned *)(p+76)==i && *(unsigned *)(p+72)!=0) {
        func_021B95A0(*(void **)(p+64),0x4E000);
        func_02011B8C(func_021BC52C(*(void **)(p+20)),*(void **)(p+64));
    }
    }
}
