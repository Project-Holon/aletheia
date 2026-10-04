/*
 * function: func_021B9D9C
 * address: 0x021B9D9C
 * packet: pkt_ov223_021B9D9C
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: bind the file table record before the sprite record to reproduce their address scheduling.
 * symbols:
 *   ids 0x021BC710 data a2
 *   banks 0x021BC6FC data a1
 *   motion 0x021BC7F0 data a1
 *   files 0x021BC73C data a1
 *   func_0202D7C8 0x0202D7C8 thumb
 *   func_0202D81C 0x0202D81C thumb
 *   func_0202D7D8 0x0202D7D8 thumb
 *   func_0202D898 0x0202D898 thumb
 *   func_02049238 0x02049238 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021BC520 0x021BC520 thumb
 *   func_0204B294 0x0204B294 arm
 *   func_0204B324 0x0204B324 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   _fgr 0x0209BBB0 arm
 *   _ffltu 0x0209BE04 arm
 *   _ffix 0x0209C494 arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _fdiv 0x0209CE10 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Request {u16 x,y,z;u8 a,b;};
struct Desc {u16 x,y,z;u8 a,b;u16 c,d;u32 sx,sy;u16 e,f;};
typedef struct {u8 b[14];} Motion;
typedef struct {u8 b[5];} Files;
extern const u16 ids[];
extern const u8 banks[];
extern const Motion motion[];
extern const Files files[];
extern u32 func_0202D7C8(u32);
extern u32 func_0202D81C(u32,u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern u32 func_0202D7D8(u32,u32,u32,u32,u32,u32,u32,u32,u16,u16);
extern u32 func_0202D898(u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern void func_02049238(u32);
extern void func_02082BCC(void *,int,u32);
extern unsigned func_021BC520(unsigned char *p);
struct Obj;
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern u32 func_0204B324(u32,u32,u32,u32,void *,u16,u16);
extern void func_0204B3DC(struct Obj *,unsigned int);
typedef signed int     s32;
extern void *func_020490F4(u32 id, u16 heap);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
#define FIX(x) ((int)(((x)>0)?((x)*4096.0f+.5f):((x)*4096.0f-.5f)))
void func_021B9D9C(char *p)
{
    struct Desc desc;
    struct Request request;
    u32 arc,other,id;
    char *r;
    const Files *f;
    u8 i,j;
    arc=func_0202D7C8(*(u16 *)p);
    for(i=0;i<3;i++) {
        id=ids[i];r=p+i*148;
        *(u32 *)(r+84)=func_0202D81C(arc,id,0,0,0,0,0,0,1,*(u16 *)p);
        *(u32 *)(r+88)=func_0202D7D8(arc,id,0,0,0,0,0,1,(u16)(banks[i]<<5),*(u16 *)p);
        *(u32 *)(r+92)=func_0202D898(id,0,0,0,0,0,0,1,*(u16 *)p);
    }
    func_02049238(arc);
    for(j=0;j<3;j++) {
        func_02082BCC(&request,0,8);
        request.x=motion[j].b[0];request.y=motion[j].b[1];request.z=0;request.a=2;request.b=3;
        r=p+j*148;
        *(u32 *)(r+108)=(u32)func_0204B294((void *)func_021BC520(*(void **)(p+20)),*(u32 *)(r+84),*(u32 *)(r+88),*(u32 *)(r+92),&request,1,*(u16 *)p);
        func_0204B3DC((struct Obj *)*(u32 *)(r+108),0);
    }
    other=(u32)func_020490F4(205,*(u16 *)p);
    for(i=0;i<3;i++) {
        f=files+i;
        r=p+i*148;
        *(u32 *)(r+96)=func_0204A6C8((void *)other,f->b[0],0,1,*(u16 *)p);
        *(u32 *)(r+104)=func_0204AF28((void *)other,f->b[2],f->b[3],*(u16 *)p);
    }
    func_02049238(other);
    for(j=0;j<3;j++) {
        func_02082BCC(&desc,0,24);
        desc.x=motion[j].b[0];desc.y=motion[j].b[1];desc.z=0;desc.a=2;desc.b=3;desc.c=0;desc.d=0;
        desc.sx=FIX((float)motion[j].b[6]/16.0f);desc.sy=FIX((float)motion[j].b[6]/16.0f);
        desc.e=0;desc.f=1;
        r=p+j*148;
        *(u32 *)(r+112)=func_0204B324(func_021BC520(*(void **)(p+20)),*(u32 *)(r+96),*(u32 *)(r+88),*(u32 *)(r+104),&desc,1,*(u16 *)p);
        func_0204B3DC((struct Obj *)*(u32 *)(r+112),0);
    }
    for(i=0;i<3;i++) {
        *(u16 *)(p+i*148+216)=0;
        *(u32 *)(p+i*148+220)=0;
        *(u32 *)(p+i*148+224)=0;
        *(u32 *)(p+i*148+228)=0;
    }
    *(u32 *)(p+528)=0;*(u32 *)(p+532)=0;
}
