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
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B7C8 0x0204B7C8 arm
 *   func_0204B714 0x0204B714 arm
 *   func_0204B784 0x0204B784 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020490F4 0x020490F4 arm
 *   func_021DF838 0x021DF838 thumb ov183
 *   func_0201BABC 0x0201BABC thumb
 *   func_02049E74 0x02049E74 arm
 *   func_0204A9D0 0x0204A9D0 arm
 *   func_0204AB84 0x0204AB84 arm
 *   func_0201BB5C 0x0201BB5C thumb
 *   func_020307B0 0x020307B0 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct State { u8 pad[0x14]; u16 shared0,shared1; u16 indices[5][6]; int cursor; char *sprites[5][6]; void *source; };
struct Rec { u32 w[9]; };
struct Entries { u32 species[6],form[6],gender[6]; };
struct Sub { u8 pad[16]; u32 size,data; };
extern u32 func_0204B3F4(void *),func_0204B714(void *);
extern void func_0204B7C8(const char *,struct Rec *),func_0204B784(char *,const struct Rec *);
extern void func_0204B6F4(void *,u32,u32),func_0204B3DC(void *,u32);
extern void *func_020490F4(u32,u16);
extern void func_021DF838(int,char *);
extern u32 func_0201BABC(u32,u32,u32,u32),func_0201BB5C(u32,u32,u32,u32);
extern void *func_02049E74(void *,u32,u32,u32,u16);
extern void func_0204A9D0(int,struct Sub *),func_0204AB84(u32,struct Rec *);
extern void func_020307B0(void *),func_02049238(void *);
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
                if(func_0204B3F4(src)) {
                    func_0204B7C8(src,&forward);
                    value=func_0204B714(src);
                    func_0204B784(dst,&forward);
                    func_0204B6F4(dst,value,0);
                    func_0204B3DC(dst,1);
                } else func_0204B3DC(dst,0);
            } else if(step==-1 && i!=4) {
                src=p->sprites[3-i][j]; dst=p->sprites[4-i][j];
                if(func_0204B3F4(src)) {
                    func_0204B7C8(src,&back);
                    value=func_0204B714(src);
                    func_0204B784(dst,&back);
                    func_0204B6F4(dst,value,0);
                    func_0204B3DC(dst,1);
                } else func_0204B3DC(dst,0);
            }
        }
    }
    mode=(heap&0x7fff)|0x8000;
    archive=func_020490F4(7,mode);
    if(step==-1) { --p->cursor; if(p->cursor<0) p->cursor=4; }
    for(j=0;j<6;j++) {
        if(step==1) i=4; else if(step==-1) i=0;
        func_021DF838((int)((u32)p->source+(i+first)*0xc4),(char *)&entries);
        if(entries.species[j]) {
            handle=func_02049E74(archive,func_0201BABC(entries.species[j],entries.form[j],entries.gender[j],0),0,(u32)&data,mode);
            func_0204A9D0(p->indices[p->cursor][j],data);
            func_0204AB84(p->indices[p->cursor][j],&loaded);
            func_0204B784(p->sprites[i][j],&loaded);
            func_0204B6F4(p->sprites[i][j],func_0201BB5C(entries.species[j],entries.form[j],entries.gender[j],0),0);
            func_020307B0(handle);
            func_0204B3DC(p->sprites[i][j],1);
        } else func_0204B3DC(p->sprites[i][j],0);
    }
    if(step==1) { ++p->cursor; if(p->cursor>4) p->cursor=0; }
    func_02049238(archive);
}
