/*
 * function: func_021DF620
 * address: 0x021DF620
 * packet: pkt_ov183_021DF620
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: short step spills first; i remains live after the first loop and
 * supplies the second loop's row; forward/back/loaded declaration order
 * gives the three 36-byte buffers at sp+7c, sp+58, sp+34.
 * symbols:
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   CLACT_GetActorImageProxy 0x0204B7C8 arm
 *   CLACT_GetActorPaletteOffset 0x0204B714 arm
 *   CLACT_SetActorImageProxy 0x0204B784 arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   func_020490F4 0x020490F4 arm
 *   func_021DF838 0x021DF838 thumb ov183
 *   POKE_TOOL_CalcGraphicIndex 0x0201BABC thumb
 *   ARC_UTIL_LoadScreenDataFromHandle 0x02049E74 arm
 *   CLACT_TransferCharacter 0x0204A9D0 arm
 *   CLACT_GetCharacterProxy 0x0204AB84 arm
 *   POKE_TOOL_CalcIconPalette 0x0201BB5C thumb
 *   func_020307B0 0x020307B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct State { u8 pad[0x14]; u16 shared0,shared1; u16 indices[5][6]; int cursor; char *sprites[5][6]; void *source; };
struct Rec { u32 w[9]; };
struct Entries { u32 species[6],form[6],gender[6]; };
struct Sub { u8 pad[16]; u32 size,data; };
struct Obj;
struct Struct36;
struct Sub0204A9D0;
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
extern u32 CLACT_GetActorPaletteOffset(struct Obj *o);
extern void CLACT_GetActorImageProxy(const char *src, struct Struct36 *dst);
extern void CLACT_SetActorImageProxy(char *dst, const struct Struct36 *src);
struct Obj;
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned int);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_021DF838(int,char *);
extern u32 POKE_TOOL_CalcGraphicIndex(u32,u32,u32,u32),POKE_TOOL_CalcIconPalette(u32,u32,u32,u32);
extern void *ARC_UTIL_LoadScreenDataFromHandle(void *,u32,u32,u32,u16);
extern void CLACT_TransferCharacter(int a, struct Sub0204A9D0 *b);
extern void CLACT_GetCharacterProxy(u32,struct Rec *);
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *);
void func_021DF620(struct State *p,int first,short step,u16 heap)
{
    int i,j;
    char *src,*dst;
    u32 value;
    void *archive,*handle;
    struct Sub *data;
    struct Rec forward,back,loaded;
    struct Entries entries;
    u32 mode;
    for(i=0;i<5;i++) {
        for(j=0;j<6;j++) {
            if(step==1 && i!=4) {
                src=p->sprites[i+1][j]; dst=p->sprites[i][j];
                if(CLACT_GetActorDrawEnable((struct Obj *)src)) {
                    CLACT_GetActorImageProxy(src,(struct Struct36 *)(&forward));
                    value=CLACT_GetActorPaletteOffset((struct Obj *)src);
                    CLACT_SetActorImageProxy(dst,(const struct Struct36 *)(&forward));
                    CLACT_SetActorPaletteOffset((struct Obj *)dst,value,0);
                    CLACT_SetActorDrawEnable((struct Obj *)dst,1);
                } else CLACT_SetActorDrawEnable((struct Obj *)dst,0);
            } else if(step==-1 && i!=4) {
                src=p->sprites[3-i][j]; dst=p->sprites[4-i][j];
                if(CLACT_GetActorDrawEnable((struct Obj *)src)) {
                    CLACT_GetActorImageProxy(src,(struct Struct36 *)(&back));
                    value=CLACT_GetActorPaletteOffset((struct Obj *)src);
                    CLACT_SetActorImageProxy(dst,(const struct Struct36 *)(&back));
                    CLACT_SetActorPaletteOffset((struct Obj *)dst,value,0);
                    CLACT_SetActorDrawEnable((struct Obj *)dst,1);
                } else CLACT_SetActorDrawEnable((struct Obj *)dst,0);
            }
        }
    }
    mode=(heap&0x7fff)|0x8000;
    archive=func_020490F4(7,(u16)mode);
    if(step==-1) { --p->cursor; if(p->cursor<0) p->cursor=4; }
    for(j=0;j<6;j++) {
        if(step==1) i=4; else if(step==-1) i=0;
        func_021DF838((int)((u32)p->source+(i+first)*0xc4),(char *)&entries);
        if(entries.species[j]) {
            handle=ARC_UTIL_LoadScreenDataFromHandle(archive,POKE_TOOL_CalcGraphicIndex(entries.species[j],entries.form[j],entries.gender[j],0),0,(u32)&data,mode);
            CLACT_TransferCharacter(p->indices[p->cursor][j],(struct Sub0204A9D0 *)data);
            CLACT_GetCharacterProxy(p->indices[p->cursor][j],&loaded);
            CLACT_SetActorImageProxy(p->sprites[i][j],(const struct Struct36 *)(&loaded));
            CLACT_SetActorPaletteOffset((struct Obj *)p->sprites[i][j],POKE_TOOL_CalcIconPalette(entries.species[j],entries.form[j],entries.gender[j],0),0);
            func_020307B0(handle);
            CLACT_SetActorDrawEnable((struct Obj *)p->sprites[i][j],1);
        } else CLACT_SetActorDrawEnable((struct Obj *)p->sprites[i][j],0);
    }
    if(step==1) { ++p->cursor; if(p->cursor>4) p->cursor=0; }
    ARC_TOOL_DeleteHandle(archive);
}
