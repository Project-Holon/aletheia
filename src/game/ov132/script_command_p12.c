/*
 * file:     script_command_p12.c
 * unit:     yes
 * function: func_021FD350, func_021FD3D8, func_021FD3F0, func_021FD400, func_021FD470
 * address:  0x021FD350
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02030734 0x02030734 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3F8 0x0203D3F8 arm
 *   d_021FDE5C 0x021FDE5C data a4
 *   func_020173EC 0x020173EC thumb
 *   func_0203996C 0x0203996C arm
 *   func_020084BC 0x020084BC thumb
 */
#include "../../matched/include/Obj06494.h"
#include "../../matched/include/Obj23284.h"
#include "../../matched/include/Obj23285.h"

struct Entry;
typedef unsigned int u32;

typedef unsigned short u16;

struct Record { int f0; int flag; char pad8[0x14]; char *data; char pad20[0x10]; };

struct Context { char pad0[0x60]; struct Record rec[4]; };

typedef unsigned char u8;

typedef signed int     s32;

/* The callback owner is the 0x1ac-byte allocation in 021FC644. */
typedef struct {u8 pad[0x128];char *buffer;u8 tail[0x80];} Owner;

extern u32 func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020173EC(void);
extern void func_02082D44(void *,void *,u32);
extern struct Entry *func_020399A8(void);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern struct Entry *func_0203996C(s32 idx);
extern int func_020084BC(const u16 *);
int func_021FD350(char *p, char *src);
void func_021FD3D8(long i,int b,int c,struct Context *p);
void *func_021FD3F0(long i,struct Context *p);
int func_021FD400(const char *p);
void func_021FD470(int a,int b,int c,const Owner *p);
extern const char d_021FDE5C[];

/*
 * followers: larger leaves 021FD3D8 and 021FD3F0 filed separately.
 */
int func_021FD350(char *p, char *src)
{
    char *q;
    void *h;
    u32 n;
    int zero;
    if(((struct Obj06494 *)p)->f124) func_020307B0(((struct Obj06494 *)p)->f124);
    n=func_020173EC();
    q=func_02030734(((struct Obj06494 *)p)->f0,n+0x7c,0,d_021FDE5C,0x5be);
    zero=0;
    ((struct Obj06494 *)p)->f124=q;
    func_02082D44(src,q,0x7c);
    n=func_020173EC();
    q+=0x7c;
    func_02082D44(((struct Obj23284 *)src)->f4,q,n);
    h=func_020399A8();
    n=func_020173EC();
    return func_0203D3F8((u32)h,0xff,0x1103,n+0x7c,(u32)(((struct Obj06494 *)p)->f124),1,zero,1);
}

/*
 * layout: 021FC862..021FC93E initializes four 48-byte records at +0x60.
 * padding: two zero bytes at 021FD3EE before 021FD3F0.
 */
void func_021FD3D8(long i,int b,int c,struct Context *p)
{
    char *s;
    p->rec[i].flag=1;
    s=p->rec[i].data;
    ((struct Obj23285 *)s)->f4=s+0x7c;
}

/*
 * layout: 021FC862..021FC93E initializes four 48-byte records at +0x60.
 */
void *func_021FD3F0(long i,struct Context *p)
{
    p->rec[i].flag=0;
    return p->rec[i].data;
}

/*
 * note: 2026-10-05 recoup: the copy length is a plain call result plus 0x7c, written the same way as the
 *   first call's n (n=f()+0x7c) and passed as n. The older draft passed n+0x7c inline and left adds r2/r1 swapped.
 */
int func_021FD400(const char *p)
{
    u8 i;
    u32 n;
    u32 k;
    u32 q;
    void *h;
    for(i=0;i<4;i++) {
        n=func_020173EC()+0x7c;
        q=*(u32 *)(p+0x128);
        k=i*n;
        n=func_020173EC()+0x7c;
        func_02082D44(*(void **)(p+i*0x30+0x7c),(void *)(q+k),n);
    }
    h=func_0203996C(0xff);
    n=func_020173EC();
    return func_0203D3F8((u32)h,0xff,0x1104,(n+0x7c)*4,*(u32 *)(p+0x128),1,0,1);
}

/*
 * note: 2026-10-05 length kept in a local before the call (n = f()+0x7c; call(q+k, src, n)); the inline n+0x7c form swapped two adds (4 B). Older DIFF notes superseded.
 */
void func_021FD470(int a,int b,int c,const Owner *p)
{
    u8 i;
    char *s;
    u32 k;
    char *q;
    u32 n;
    for(i=0;i<4;i++) {
        s=(char *)p+i*0x30;
        if(func_020084BC(*(u16 **)(s+0x84))==0) {
            n=func_020173EC()+0x7c;
            q=p->buffer;
            k=i*n;
            n=func_020173EC()+0x7c;
            func_02082D44(q+k,*(void **)(s+0x7c),n);
            q=*(char **)(s+0x7c);
            *(char **)(q+4)=q+0x7c;
            *(int *)(s+0x64)=1;
        } else *(int *)(s+0x64)=0;
    }
    *(int *)((char *)p+0x15c)=1;
}
