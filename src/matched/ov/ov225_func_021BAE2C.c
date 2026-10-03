/*
 * function: func_021BAE2C
 * address: 0x021BAE2C
 * packet: pkt_ov225_021BAE2C
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Lever: initialise offset after cursor clear, letting zero schedule at
 * that call's argument setup rather than before the touch-mode setter.
 * symbols:
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_02035CB8 0x02035CB8 arm
 *   func_020355D8 0x020355D8 arm
 *   func_021BB034 0x021BB034 thumb ov225
 *   func_02028218 0x02028218 thumb
 *   func_0204B404 0x0204B404 arm
 *   func_021BB074 0x021BB074 thumb ov225
 *   func_021BB1F4 0x021BB1F4 thumb ov225
 *   func_021BB044 0x021BB044 thumb ov225
 *   func_021BB088 0x021BB088 thumb ov225
 *   func_020061E4 0x020061E4 thumb
 *   func_02035D20 0x02035D20 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
struct Obj;struct Vec2 {short x,y;};
extern u32 func_0204B3F4(struct Obj *);
extern u32 func_02035CB8(u32 *,u32 *),func_02035D20(u32 *,u32 *);
extern void func_020355D8(u8);
extern u16 func_021BB034(u16 **),func_021BB074(u16 **),func_021BB044(u16 **);
extern void func_02028218(void *,u32);
extern void func_0204B404(struct Obj *,const struct Vec2 *,u32);
extern u16 func_021BB1F4(void *,u16,u16);
extern void func_021BB088(char *);
extern void func_020061E4(u32);
int func_021BAE2C(char *p)
{
    u32 dragx,dragy;
    struct Vec2 drag;
    u32 clickx,clicky;
    struct Vec2 click;
    if(func_0204B3F4(*(struct Obj **)(p+0x5c))==0) return 0;
    if(*(u32 *)(p+0x88)) {
        if(func_02035CB8(&dragx,&dragy)) {
            int offset;
            u16 selection,end;
            func_020355D8(1);
            func_02028218(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),0);
            offset=0;
            drag.x=240;
            if(dragy>=8) offset=dragy-8;
            drag.y=offset;
            if(drag.y<17) drag.y=17;
            else if(drag.y>135) drag.y=135;
            func_0204B404(*(struct Obj **)(p+0x5c),&drag,1);
            selection=func_021BB1F4(p,(u16)(func_021BB074((u16 **)p)+1),(u16)dragy);
            if(selection!=*(u16 *)(*(char **)p+0xc)) {
                *(u16 *)(*(char **)p+0xc)=selection;
                end=func_021BB044((u16 **)p);
                if(*(u32 *)(p+0x8c) || *(u16 *)(*(char **)p+0xe)<*(u16 *)(*(char **)p+0xc) || end<*(u16 *)(*(char **)p+0xe)) {
                    *(u16 *)(*(char **)p+0xe)=*(u16 *)(*(char **)p+0xc);
                    *(u32 *)(p+0x8c)=1;
                }
                func_021BB088(p);
                func_020061E4(0x548);
            }
        } else *(u32 *)(p+0x88)=0;
        return 1;
    } else {
        if(func_02035D20(&clickx,&clicky) && clickx>=240 && clickx<=247 && clicky>=17 && clicky<=150) {
            int offset;
            u16 selection,end;
            func_020355D8(1);
            func_02028218(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),0);
            offset=0;
            func_020061E4(0x548);
            *(u32 *)(p+0x88)=1;
            click.x=240;
            if(clicky>=8) offset=clicky-8;
            click.y=offset;
            if(click.y<17) click.y=17;
            else if(click.y>135) click.y=135;
            func_0204B404(*(struct Obj **)(p+0x5c),&click,1);
            selection=func_021BB1F4(p,(u16)(func_021BB074((u16 **)p)+1),(u16)clicky);
            if(selection!=*(u16 *)(*(char **)p+0xc)) {
                *(u16 *)(*(char **)p+0xc)=selection;
                end=func_021BB044((u16 **)p);
                if(*(u32 *)(p+0x8c) || *(u16 *)(*(char **)p+0xe)<*(u16 *)(*(char **)p+0xc) || end<*(u16 *)(*(char **)p+0xe)) {
                    *(u16 *)(*(char **)p+0xe)=*(u16 *)(*(char **)p+0xc);
                    *(u32 *)(p+0x8c)=1;
                }
                func_021BB088(p);
            }
        }
        if(*(u32 *)(p+0x88)) return 1;
        return 0;
    }
}
